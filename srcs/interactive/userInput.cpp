/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   userInput.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 13:36:58 by viclucas          #+#    #+#             */
/*   Updated: 2019/11/04 12:06:46 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.hpp"

void		bottom_informations(t_window *win)
{
	wattron(win->down, COLOR_PAIR(3));
	mvwprintw(win->down, 8, 20, "PRESS P TO USE PAUSE:\t");
	mvwprintw(win->down, 8, 47, "PAUSED  ");
	wattroff(win->down, COLOR_PAIR(3));
	return ;
	}

int		userInput(t_window *win, int flag, int *shot)
{
	int c;
	char input[NUM_MOVES + 1] = "wdas";

	c = getch();
	if (c == ' ')
		*shot = 1;
	if (c == 'p' || flag == 1 || c == 'P')
	{
		bottom_informations(win);
		wrefresh(win->big);
		wrefresh(win->down);
		c = 0;
		while (c != 'p' && c != 'P')
		{
			c = getch();
			if (c == 'q' || c == 'Q')
				close_win();
		}
		wattron(win->down, COLOR_PAIR(3));
		mvwprintw(win->down, 8, 47, "RUNNING");
		wattroff(win->down, COLOR_PAIR(3));
	}
	if (c == 'q' || c == 'Q')
		close_win();
	for (int i = 0; i < NUM_MOVES; i++)
		if (input[i] == c)
			return i;
	return -1;
}
