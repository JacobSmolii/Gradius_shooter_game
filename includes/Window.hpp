/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 09:18:06 by viclucas          #+#    #+#             */
/*   Updated: 2019/11/05 12:23:37 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_HPP
# define WINDOW_HPP
#include <curses.h>
# include <stdio.h>
# include <stdlib.h>
# include <iostream>
# include <unistd.h>
# include <list>

# include "Player.hpp"
# include "Enemy.hpp"
# include "Bullet.hpp"

# define STAR_PER_COLS 1
# define NUM_MOVES 4
# define WINDOW_TOO_SMALL 1
# define NO_COLORS 2
# define MAX_Y 64
# define MAX_X 192
# define NUM_LIFES_AT_START 3
# define MONSTER_BY_WAVE 1

class Infos;

typedef struct s_window
{
	WINDOW	*big;
	WINDOW	*side;
	WINDOW	*down;
}			t_window;

void	initDown(t_window *win, Infos a);
int				userInput(t_window *win, int flag, int *shot);
void			entryOutput(t_window *win, Infos a);
void            close_win(void);
void			init_interactive_mode(t_window *win);


#endif
