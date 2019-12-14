/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Infos.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:09:23 by viclucas          #+#    #+#             */
/*   Updated: 2019/11/05 10:13:01 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Infos.hpp"

Infos::Infos()
{
	this->_framesUntilWave = 10;
	this->_lives = 3;
	this->_score = 0;
	this->_EnemyList = NULL;
	this->_BulletList = NULL;
	this->hours = 0;
	this->minutes = 0;
	this->seconds = 0;
}

Infos::Infos(Infos const &name)
{
	*this = name;
}

Infos::~Infos(void) { return; }

Infos &Infos::operator=(Infos const &name)
{
	this->_framesUntilWave = name.getFramesUntilWave();
	this->_lives = name._lives;
	this->_score = name._score;
	this->_EnemyList = name._EnemyList;
	this->_P = name._P;
	this->_BulletList = name._BulletList;
	return *this;
}

int Infos::getFramesUntilWave() const { return this->_framesUntilWave;}
int Infos::getLives() const { return this->_lives;}
size_t Infos::getScore() const { return this->_score;}
t_list *Infos::getEnemyList() const { return this->_EnemyList;}
Player Infos::getPlayer() const { return this->_P;}
t_list *Infos::getBulletList() const { return this->_BulletList;}

void 	Infos::setFramesUntilWave(int a) { this->_framesUntilWave = a ;}
void	Infos::setLives(int a) { this->_lives =  a;}
void	Infos::setScore(size_t a) { this->_score = a;}

void	Infos::addElem(t_list **head, Parent *elem)
{
	t_list *tmp;
	t_list *ret = new t_list;
	ret->a = elem;
	ret->next = NULL;
	ret->id = 0;
	if (!*head)
	{
		*head = ret;
		return;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	ret->id = tmp->id + 1;
	tmp->next = ret;
}

void	Infos::delElem(t_list **head, size_t id)
{
	t_list *tmp;
	t_list *prev;

	if (!*head)
		return;
	if ((*head)->id == id)
	{
		tmp = *head;
		*head = (*head)->next;
		delete tmp;
		return;
	}
	tmp = *head;
	while (tmp && tmp->id != id)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (!tmp)
		return;
	prev->next = tmp->next;
}

void	Infos::printList(t_list *n)
{
	if (!n)
		return;
	t_list *tmp = n;
	int i = 0;
	while (tmp)
	{
		//std::cout << "type = " << tmp->a->get_type() << std::endl;
		std::cout << "i = " << i << std::endl;
		std::cout << "X = " << tmp->a->get_x() << std::endl;
		std::cout << "Y = " << tmp->a->get_y() << std::endl << std::endl;
		tmp = tmp->next;
		i++;
	}
	std::cout << "NB = " << i << std::endl;
}

void	Infos::delete_whole(t_list **enemy, WINDOW *win)
{
	t_list *tmp;
	t_list *prev;

	if (!*enemy)
		return;
	tmp = *enemy;
	while (tmp)
	{
		prev = tmp;
		tmp->a->print_player(tmp->a->get_y(), tmp->a->get_x(), win, tmp->a->get_type());
		tmp = tmp->next;
				delete tmp->a;
		delete prev;
	}
}

void	Infos::timer_count(Infos *a, t_window win)
{
	a->seconds++;
	if (a->seconds == 60)
	{
		a->minutes++;
		if (a->minutes == 60)
		{
			a->hours++;
			a->minutes = 0;
		}
		a->seconds = 0;
	}

	wattron(win.down, COLOR_PAIR(2));
	mvwprintw(win.down, 10, 150, "Timer         :\t%02d | %02d | %02d\n", a->hours, a->minutes, a->seconds);
	wattroff(win.down, COLOR_PAIR(2));
}
