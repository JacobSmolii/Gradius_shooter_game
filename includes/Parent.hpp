/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 12:14:26 by vsmolii           #+#    #+#             */
/*   Updated: 2019/11/04 12:07:23 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARENT_H
#define PARENT_H

#include <curses.h>
#include <string>


class	Parent
{
	public:
		Parent(void);
		virtual ~Parent(void);
		Parent(Parent const &name);
		Parent &operator=(Parent const &name);
		void	move(int flag, WINDOW *win, int type);
		int		get_x(void);
		int		get_y(void);
		int		get_type(void);
		void	cleanLastPos(int type, WINDOW *win);
		void	setX(int c);
		void	setY(int c);
		void	delete_player(int y, int x);
//		void	print_player(int y, int x, WINDOW *win);
		void	printBlanks(int y, int x, WINDOW *win, size_t length);
 		void	spawn();
		void	print_player(int y, int x, WINDOW *win, int type);

	protected:
		int _y;
		int _x;
		int _type;

};


#endif
