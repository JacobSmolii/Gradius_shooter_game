/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printingInfos.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 11:59:58 by viclucas          #+#    #+#             */
/*   Updated: 2019/11/04 12:08:06 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Infos.hpp"
#include "Window.hpp"

void	initDown(t_window *win, Infos a)
{
	if (!win)
		return ;
	wattron(win->down, COLOR_PAIR(1));
	mvwprintw(win->down, 6, 20, "PRESS Q TO EXIT");
	wattroff(win->down, COLOR_PAIR(1));
	wattron(win->down, COLOR_PAIR(3));
	mvwprintw(win->down, 8, 20, "PRESS SPACE TO USE PAUSE:\t");
	wattroff(win->down, COLOR_PAIR(3));
	wattron(win->down, COLOR_PAIR(2));
	mvwprintw(win->down, 5, 95, "W");
	mvwprintw(win->down, 6, 95, "|");
	mvwprintw(win->down, 7, 76, "Use command   <- A - D -> to move");
	mvwprintw(win->down, 8, 95, "|");
	mvwprintw(win->down, 9, 95, "S");
	wattroff(win->down, COLOR_PAIR(2));
	wattron(win->down, COLOR_PAIR(1));
	mvwprintw(win->down, 6, 150, "LIVE REMAINING:\t%d", a.getLives());
	wattroff(win->down, COLOR_PAIR(1));
	wattron(win->down, COLOR_PAIR(3));
	mvwprintw(win->down, 8, 150, "SCORE         :\t%ld", a.getScore());
	wattroff(win->down, COLOR_PAIR(3));

}

void	entryOutput(t_window *win, Infos a)
{
	Player sample;

	sample.print_player(START_PLAYER_Y, START_PLAYER_X, win->big, sample.get_type());
	initDown(win, a);
}
