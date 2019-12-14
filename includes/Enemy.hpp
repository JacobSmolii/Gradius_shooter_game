/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 19:00:46 by viclucas          #+#    #+#             */
/*   Updated: 2019/11/04 11:47:00 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include "curses.h"
#include "Parent.hpp"

class Enemy : public Parent
{
	public:
	Enemy(void);
	~Enemy(void);
	Enemy(Enemy const &name);
	Enemy &operator=(Enemy const &name);
	void spawn();
	private:
	void	spawn(WINDOW *win);
};

#endif

