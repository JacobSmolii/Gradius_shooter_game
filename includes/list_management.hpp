/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:15:50 by viclucas          #+#    #+#             */
/*   Updated: 2019/11/04 17:01:01 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_MANAGEMENT_HPP
#define LIST_MANAGEMENT_HPP
#include "Infos.hpp"
#include "curses.h"

void	collisions(t_list **bullets, t_list **enemy, Player *player, 
		WINDOW *win, Infos *a);
void	enemy_shoot(t_list **bullets, t_list *enemy);
void	move_enemy(t_list **enemy, WINDOW *win);
void	move_bullets(t_list **head, WINDOW *win);
void	new_wave(t_list **enemy, WINDOW *win);
#endif
