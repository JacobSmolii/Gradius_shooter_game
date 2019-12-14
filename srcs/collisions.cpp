/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:30:18 by viclucas          #+#    #+#             */
/*   Updated: 2019/11/05 12:28:11 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Window.hpp"
#include "Infos.hpp"
#include "curses.h"

void	player_dead(Player *player, Infos *a, WINDOW *win, t_list **enemy, t_list **bullets)
{
	a->setLives(a->getLives() - 1);
	if (!a->getLives())
	{
		curs_set(1);
		getch();
		endwin();
		std::cout << "YOU LOST WITH " << a->getScore() << " SCORE" << std::endl;
		exit(1);
	}
	static_cast<void>(enemy);
	static_cast<void>(bullets);
	player->cleanLastPos(1, win);
	player->setY(START_PLAYER_Y);
	player->setX(START_PLAYER_X);
	player->print_player(player->get_y(), player->get_x(), win, player->get_type());
}

void	collisions(t_list **bullets, t_list **enemy, 
				Player *player, WINDOW *win, 
				Infos *a)
{
	t_list *tmp_bullet;
	t_list *tmp_enemy;

	tmp_bullet = *bullets;
	tmp_enemy = *enemy;
	while (tmp_bullet)
	{
		while (tmp_enemy)
		{
			if ((tmp_bullet->a->get_y() == tmp_enemy->a->get_y() ||
					tmp_bullet->a->get_y() == tmp_enemy->a->get_y() + 2 ||
					tmp_bullet->a->get_y() == tmp_enemy->a->get_y() + 1 ||
					tmp_bullet->a->get_y() == tmp_enemy->a->get_y() - 1 || 
					tmp_bullet->a->get_y() == tmp_enemy->a->get_y() - 2) &&
					(tmp_bullet->a->get_x() == tmp_enemy->a->get_x()) &&
					tmp_bullet->a->get_type() == 1)
				{
				a->delElem(bullets, tmp_bullet->id);	
				a->delElem(enemy, tmp_enemy->id);	
				a->setScore(a->getScore() + 100);
				tmp_enemy->a->cleanLastPos(2, win);
				tmp_bullet->a->cleanLastPos(3, win);
				break ;	
			}
			else if ((tmp_bullet->a->get_y() == player->get_y() ||
				tmp_bullet->a->get_y() == player->get_y() + 1 ||
				tmp_bullet->a->get_y() == player->get_y() + 2 ||
				tmp_bullet->a->get_y() == player->get_y() - 2 ||
				tmp_bullet->a->get_y() == player->get_y() - 1) &&
				(tmp_bullet->a->get_x() == player->get_x()) &&
				tmp_bullet->a->get_type() == 2)
				player_dead(player, a, win, enemy, bullets);
//			else if (player->get_y() 
			tmp_enemy = tmp_enemy->next;

		}
		tmp_enemy = *enemy;	
		tmp_bullet = tmp_bullet->next;
	
	}
	tmp_enemy = *enemy;
	while (tmp_enemy)
	{
		if (abs((tmp_enemy->a->get_y() - player->get_y())) < 3 &&
			(abs(tmp_enemy->a->get_x() - player->get_x())) < 3 )
				player_dead(player, a, win, &tmp_enemy, bullets);	
		tmp_enemy = tmp_enemy->next;
	}
	//between ships
}
