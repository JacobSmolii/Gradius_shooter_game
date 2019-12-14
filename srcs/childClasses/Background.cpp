/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Background.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:47:38 by vsmolii           #+#    #+#             */
/*   Updated: 2019/11/05 09:48:56 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Background.hpp"
#include "Window.hpp"
Background::Background() : Parent()
{
	this->_x = 0;
	this->_y = 0;
	this->_type = 4;	
}

Background::Background(int height, int width) : _height(height), _width(width)
{
	/*
	for (int y = 0; y < this->_height; y++)
		for (int x = 0; x < this->_width; x++)
			this->_star_map[y] = create_new_line();
	*/
}

Background::~Background(void)
{
	for (int y = 0; y < this->_height; y++)
		_star_map[y].clear();
	_star_map.clear();
}


Background &
Background::operator=(Background const &name)
{
	this->_y = name._y;
	this->_x = name._x;
	return *this;
}

Background::Background(Background const &name) : Parent()
{
	*this = name;
}

/*
std::vector<char>		Background::create_new_line(void)
{
	std::vector<char> new_line_stars(this->_width);

	for (int x = 0; x < this->_width; x++)
		new_line_stars[x] = rand() % 92 == 0 ? '*' : ' ';
	return (new_line_stars);
}

void	Background::update_star_map(void)
{
	_star_map[this->_height].clear();
	for (int i = this->_height; i > 0; i--)
		this->_star_map[i] = this->_star_map[i - 1];
	this->_star_map[0] = create_new_line();
}

void	Background::display_map(t_window win)
{
	for (int y = 0; y < this->_height; y++)
		for (int x = 0; x < this->_width; x++)
			mvaddch(y, x, this->_star_map[y + 1][x]);
			// wechochar(win.big, this->_star_map[y + 1][x]);

}
*/
