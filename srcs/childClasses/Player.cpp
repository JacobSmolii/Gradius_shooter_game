/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:32:54 by viclucas          #+#    #+#             */
/*   Updated: 2019/11/05 09:34:29 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

Player::Player() : Parent()
{
	this->_type = 1;
	this->_y = START_PLAYER_Y;
	this->_x = START_PLAYER_X;
}

Player::Player(Player const &name) : Parent()
{
	*this = name;
}

Player::~Player(void) { return; }

Player &Player::operator=(Player const &name)
{
	static_cast<void>(name);
	return *this;
}

void	Player::shooting(void)
{
	return ;
}

void	Player::spawn()
{
	return ;
}

void	Player::spawn(WINDOW *win, int y, int x)
{
	mvwprintw(win, y - 2, x, "   __");
	mvwprintw(win, y - 1, x, "   \\  \\_____");
	mvwprintw(win, y, x, "###[==______|>");
	mvwprintw(win, y + 1, x, "   /_/");
}
