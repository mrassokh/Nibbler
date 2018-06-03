/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IWindow.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 13:48:51 by mrassokh          #+#    #+#             */
/*   Updated: 2018/05/19 13:48:54 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_HPP
# define WINDOW_HPP
# include <iostream>
# include "Snake.hpp"
enum EVENTS
{
	LEFT_FIRST,
	RIGHT_FIRST,
	LEFT_SECOND,
	RIGHT_SECOND,
	EXIT,
	CHANGE_TO_SDL_WIN,
	CHANGE_TO_NCURS_WIN,
	CHANGE_TO_GLUT_WIN,
	CHANGE_MULTIPLAYER_MODE,
	DEFAULT
};

class IWindow
{
public:
	virtual EVENTS 			getEvent(void)  = 0;
	virtual void 			drawSquare(int x, int y, eType type) = 0;
	virtual void 			startCycl() = 0;
	virtual void 			draw(int const & grid_x, int const & grid_y) = 0;
	virtual void 			init(void) = 0;
	virtual void 			endCycl(void) = 0;
	virtual void 			cycle(void) = 0;
	virtual void 			quit(void) = 0;
};

# endif
