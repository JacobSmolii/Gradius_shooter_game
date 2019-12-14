/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 15:29:45 by viclucas          #+#    #+#             */
/*   Updated: 2019/11/04 12:30:28 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
#define PLAYER_HPP
#define START_PLAYER_Y 35
#define START_PLAYER_X 5
#include "Parent.hpp"

class Player : public Parent
{
	public: 
	Player(void);
	~Player(void);
	Player(Player const &name);
	Player &operator=(Player const &name);
	void	shooting(void);	
	void	spawn();
	void	spawn(WINDOW *win, int y, int x);

typedef struct s_list
{
	Player *item;
	struct s_list *next;
}			t_list;

t_list	*add_elem(t_list *head, WINDOW *win);

};

#endif
