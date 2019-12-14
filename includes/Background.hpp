/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Background.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsmolii <vsmolii@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:42:47 by vsmolii           #+#    #+#             */
/*   Updated: 2019/11/05 09:45:04 by viclucas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Infos.hpp"
#include "Window.hpp"
#include <vector>
#include <iostream>

void	NewStarLine(t_list **stars);
void	createFirstLayer(t_window *win, t_list **stars);		
void	moveStars(t_list **stars, t_window *win);
class Background : public Parent
{
	public:
		Background();
		Background(int height, int width);
		~Background(void);
		Background(Background const &name);
		Background &operator=(Background const &name);

		std::vector<char>	create_new_line(void);

		void	update_star_map(void);
		void	display_map(t_window win);

	private:
		int		_height;
		int		_width;
		// char	**_star_map;
		std::vector<std::vector<char> > _star_map;
};

#endif
