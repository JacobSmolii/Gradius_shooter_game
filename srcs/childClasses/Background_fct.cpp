/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Background_fct.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:09:57 by vsmolii           #+#    #+#             */
/*   Updated: 2019/11/05 10:08:20 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Infos.hpp"
#include "Window.hpp"
#include "Background.hpp"

void	starGeneration(Parent *star, int i)
{
	star->setY(rand()%COLS);
	star->setX(i);
}

void	print_layer(t_window *win, t_list **stars)
{
	t_list *tmp;

	if (!*stars)
		return;
	tmp = *stars;
	wattron(win->big, COLOR_PAIR(1));
	while (tmp)
	{
		mvwprintw(win->big, tmp->a->get_y(), tmp->a->get_x(), "*");
		tmp = tmp->next;
	}
	wattroff(win->big, COLOR_PAIR(1));
}

void	createFirstLayer(t_window *win, t_list **stars)
{
	Infos a;

	for (int i = 0; i < COLS; i++)
	{
		for (int j = 0; j < STAR_PER_COLS; j++)
		{
			Parent *star = new Background;
			starGeneration(star, i);
			a.addElem(stars, star);
		}	
	}
	print_layer(win, stars);
}

void	moveStars(t_list **stars, t_window *win)
{
	Infos a;
	t_list *tmp;

	if (!*stars)
		return ;
	tmp = *stars;
	while (tmp)
	{
		if (tmp->a->get_x() <= 1)
		{
			tmp->a->cleanLastPos(4, win->big);
			a.delElem(stars, tmp->id);
		}
		tmp->a->move(2, win->big, 4);
		tmp = tmp->next;	
	}
}

void	NewStarLine(t_list **stars)
{
	Infos a;
	for (int j = 0; j < STAR_PER_COLS; j++)
	{
		Parent *star = new Background;
		starGeneration(star, COLS - 2);
		a.addElem(stars, star);
	}	
}

