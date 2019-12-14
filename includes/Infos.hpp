/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Infos.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:59:58 by viclucas          #+#    #+#             */
/*   Updated: 2019/11/04 19:56:28 by vsmolii          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFOS_HPP
# define INFOS_HPP
#include "Window.hpp"
#include <iostream>

typedef struct s_list
{
	struct s_list *next;
	Parent *a;
	size_t id;
}				t_list;

class Infos
{
	public:
	Infos(void);
	~Infos(void);
	Infos(Infos const &name);
	Infos &operator=(Infos const &name);

	int		getLives() const;
	size_t	getScore() const;
	t_list *getEnemyList() const;
	Player getPlayer() const;
	t_list *getBulletList() const;
	int		getFramesUntilWave() const;

	void	addElem(t_list **head, Parent *elem);
	void	delElem(t_list **head, size_t id);
	void	printList(t_list *head);
	void	delete_whole(t_list **list, WINDOW *win);
	void	timer_count(Infos *a, t_window win);
	void	setFramesUntilWave(int nb);
	void	setLives(int nb);
	void	setScore(size_t nb);

	private:
		t_list 		*_EnemyList;
		int			_framesUntilWave;
		int			_lives;
		size_t		_score;
		Player 		_P;
		t_list 		*_BulletList;
		int			hours;
		int			minutes;
		int			seconds;
};
#endif
