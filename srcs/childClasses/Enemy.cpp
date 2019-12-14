/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:57:31 by viclucas          #+#    #+#             */
/*   Updated: 2019/11/05 12:27:12 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "Window.hpp"

Enemy::Enemy() : Parent()
{
	int min_x = COLS - 20;
	int	min_y = 3;	
	int range_x[] = {min_x, min_x + 4, min_x + 8};
	int range_y[] = {min_y, min_y + 4, min_y + 8, min_y + 12, min_y + 16, min_y + 20, min_y + 30, min_y + 34, min_y + 40, min_y +44, min_y + 48, min_y + 52};
	
	int value = rand()%3;
	this->_x = range_x[value];
	value = rand()%12;
	this->_y = range_y[value];
	this->_type = 2;
}

Enemy::Enemy(Enemy const &name) : Parent()
{
	*this = name;
}

Enemy::~Enemy(void) { return; }

Enemy &Enemy::operator=(Enemy const &name)
{
	this->_type = name._type;
	this->_y = name._y;
	this->_x = name._x;
	return *this;
}

void	Enemy::spawn(void)
{
	return;
}

void	Enemy::spawn(WINDOW *win)
{
	mvwprintw(win, this->get_y() - 1, this->get_x(), "/-\\");
	mvwprintw(win, this->get_y(), this->get_x(), " - ");
	mvwprintw(win, this->get_y() + 1, this->get_x(), "\\-/");
}
