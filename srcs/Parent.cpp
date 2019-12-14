/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:26:17 by viclucas          #+#    #+#             */
/*   Updated: 2019/11/05 12:29:21 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parent.hpp"

Parent::Parent(void) : _y(0), _x(0), _type(0)
{
	return ;
}

Parent::Parent(Parent const &name)
{
	*this = name;
}

Parent &Parent::operator=(Parent const &name)
{
	static_cast<void>(name);
	return *this;
}

Parent::~Parent(void) { return; }

int		Parent::get_x(void) { return this->_x;}
int		Parent::get_y(void) { return this->_y;}
int		Parent::get_type(void) { return this->_type;}


void	Parent::setX(int c) { this->_x = c;}
void	Parent::setY(int c) { this->_y = c;}

typedef struct s_moves
{
	void (Parent::*f)(int _y, int _x); 
	int id;
}				t_moves;

void	Parent::printBlanks(int y, int x, WINDOW *win, size_t length)
{
	mvwprintw(win, y, x, "%*s", length, "");
}

void	Parent::cleanLastPos(int type, WINDOW *win)
{
	if (type == 1)
	{
		printBlanks(this->get_y() -2, this->get_x(), win, 5);
		printBlanks(this->get_y() -1, this->get_x(), win, 14);
		printBlanks(this->get_y(), this->get_x(), win, 14);
		printBlanks(this->get_y() + 1, this->get_x(), win, 6);
	}
	else if (type == 2)
	{
		printBlanks(this->get_y() -1, this->get_x() - 1, win, 4);
		printBlanks(this->get_y(), this->get_x() -1, win, 4);
		printBlanks(this->get_y() + 1, this->get_x() - 1, win, 4);
	}
	else if (type == 3)
		printBlanks(this->get_y(), this->get_x() -1, win, 2);
	else if (type ==4)
		printBlanks(this->get_y(), this->get_x(), win, 1);

}

void	Parent::move(int ind, WINDOW *win, int type)
{
	if (ind == 0 && this->get_y() > 3)
	{
		cleanLastPos(this->_type, win);
		print_player(this->get_y() - 1, this->get_x(), win, type); // move up: y - 1;
		this->setY(this->get_y() - 1);
	}
	else if (ind == 1 && COLS - get_x() > 17)
	{
		cleanLastPos(this->_type, win);
		print_player(this->get_y(), this->get_x() + 2, win, type); // move right: x + 1;
		this->setX(this->get_x() + 2);
	}
	else if (ind == 2 && get_x() > 1)
	{
		cleanLastPos(this->_type, win);
		print_player(this->get_y(), this->get_x() - 2, win, type); // move left: x - 1;
		this->setX(this->get_x() - 2);
	}
	else if (ind == 3 && LINES -get_y() > 17)
	{
		cleanLastPos(this->_type, win);
		print_player(this->get_y() + 1, this->get_x(), win, type); // move down: y + 1;
		this->setY(this->get_y() + 1);
	}
}

void	Parent::print_player(int y, int x, WINDOW *win, int type)
{
	if (type == 1)
	{
		mvwprintw(win, y - 2, x, "   __");
		mvwprintw(win, y - 1, x, "   \\  \\_____");
		mvwprintw(win, y, x, "###[==______|>");
		mvwprintw(win, y + 1, x, "   /_/");
	}
	else if (type == 2)
	{
		mvwprintw(win, y - 1, x, "/-\\");
		mvwprintw(win, y, x, " - ");
		mvwprintw(win, y + 1, x, "\\-/");
	}
	else if (type == 4)
	{
		mvwprintw(win, y, x, "*");
	}
}
