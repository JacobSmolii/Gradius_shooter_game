/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 13:05:41 by viclucas          #+#    #+#             */
/*   Updated: 2019/11/04 16:14:50 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"
#include "Window.hpp"


Bullet::Bullet(int y, int x, int type) : Parent()
{
	this->_type = type;
	this->_y = y;
	this->_x = x;
}

Bullet::
Bullet() : Parent()
{
	return;
}

Bullet::Bullet(Bullet const &name) : Parent()
{
	*this = name;
}

Bullet::~Bullet(void) { return; }

Bullet &Bullet::operator=(Bullet const &name)
{
	this->_type = name._type;
	this->_y = name._y;
	this->_x = name._x;
	return *this;
}

void	Bullet::
spawn(void)
{
	return;
}
