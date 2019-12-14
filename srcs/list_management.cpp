/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:52:40 by viclucas          #+#    #+#             */
/*   Updated: 2019/11/05 12:30:36 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.hpp"
#include "Infos.hpp"
#include "curses.h"

void	move_enemy(t_list **enemy, WINDOW *win)
{
	Infos a;
	t_list *tmp;
	int idx[] = {0, 2, 3};

	if (!*enemy)
		return;
	tmp = *enemy;
	while (tmp)
	{
		if (tmp->a->get_x() <= 4)
		{
			tmp->a->cleanLastPos(2, win);
			a.delElem(enemy, tmp->id);
		}
		else
			tmp->a->move(idx[rand()%3], win, tmp->a->get_type());
		tmp = tmp->next;
	}
}

void	enemy_shoot(t_list **bullets, t_list *enemy)
{
	t_list *tmp;
	int 	value = 0;

	Infos a;
	tmp = enemy; 
	if (!enemy)
		return;
	while (tmp)
	{
		value = rand()%200;
		if (value == 2) // 1/200 chance to shoot each loop
		{
			Parent *item = new Bullet(tmp->a->get_y(), tmp->a->get_x() - 2, tmp->a->get_type());
			a.addElem(bullets, item);
		}
		tmp = tmp->next;
	}
}

void	new_wave(t_list **enemy, WINDOW *win)
{
	Infos a;

	for (int i = 0; i < MONSTER_BY_WAVE; i++)
	{
		Parent *Elem = new Enemy();
		Elem->print_player(Elem->get_y(), Elem->get_x(), win, Elem->get_type());
		a.addElem(enemy, Elem);
	}
}

void	move_bullets(t_list **head, WINDOW *win)
{
	t_list *tmp;

	if (!*head)
		return;
	tmp = *head;
	while (tmp)
	{
		if (tmp->a->get_type() == 1)
		{
			wattron(win, COLOR_PAIR(3));
			mvwprintw(win, tmp->a->get_y(), tmp->a->get_x() -1, "  ");
			mvwprintw(win, tmp->a->get_y(), tmp->a->get_x(), "==");
			tmp->a->setX(tmp->a->get_x() + 1);
			wattroff(win, COLOR_PAIR(3));
		}
		else
		{
			wattron(win, COLOR_PAIR(2));
			mvwprintw(win, tmp->a->get_y(), tmp->a->get_x() + 1, " ");
			mvwprintw(win, tmp->a->get_y(), tmp->a->get_x(), "=");
			tmp->a->setX(tmp->a->get_x() - 1);
			wattroff(win, COLOR_PAIR(2));
		}
		tmp = tmp->next;
	}
}
