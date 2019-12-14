/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 20:49:44 by vsmolii           #+#    #+#             */
/*   Updated: 2019/11/05 12:23:53 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unistd.h>
#include "Window.hpp"
#include "Infos.hpp"
#include "list_management.hpp"
#include "Bullet.hpp"
#include "Frame_per_sec.hpp"
#include "Background.hpp"

int main()
{
	srand(time(0));
	t_window win;
	int value = 0;
	int mv = 10;
	int shot = 0;

	Infos a;
	t_list *stars = NULL;
	t_list *enemy = a.getEnemyList();
	t_list *bullets = a.getBulletList();
	Player player;
	Frame_psec fps;

	init_interactive_mode(&win);
	entryOutput(&win, a);
	createFirstLayer(&win, &stars); 
	userInput(&win, 1, &shot);
	shot = 0;
	while (1)
	{
		if (fps.frame_per_second())
		{
			a.timer_count(&a, win);
			value = userInput(&win, 2, &shot);
			if (shot)
			{
				Parent *bullet = new Bullet(player.get_y(), player.get_x() + 15, player.get_type());
				a.addElem(&bullets, bullet);
			}
			if (value != -1)
				player.move(value, win.big, player.get_type());
			shot = 0;
			a.setFramesUntilWave(a.getFramesUntilWave() -1);
			if (!a.getFramesUntilWave())
			{
				new_wave(&enemy, win.big);
				a.setFramesUntilWave(100);
			}
			if (!mv)
			{
				move_enemy(&enemy, win.big);
				wattron(win.big, COLOR_PAIR(1));
				moveStars(&stars, &win);
				wattroff(win.big, COLOR_PAIR(1));
				NewStarLine(&stars);
				mv = 5;
			}
			mv--;
			enemy_shoot(&bullets, enemy);
			move_bullets(&bullets, win.big);
			collisions(&bullets, &enemy, &player, win.big, &a);
			usleep(10000);
			a.setScore(a.getScore() + 1);
			initDown(&win, a);
			wrefresh(win.big);
			wrefresh(win.down);
		}
	}
	close_win();
}
