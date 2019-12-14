/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viclucas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 13:06:05 by viclucas          #+#    #+#             */
/*   Updated: 2019/11/04 11:47:24 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP

#include "Parent.hpp"

class Bullet : public Parent
{
	public:
		Bullet(int y, int x, int type);
		Bullet();
		~Bullet(void);
        Bullet(Bullet const &name);
        Bullet &operator=(Bullet const &name);
    	void	spawn();    

	private:
         void    spawn(int y, int x);
		
};

#endif
