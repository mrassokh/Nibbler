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

enum STATE
{
	START,
	GAME,
	GAME_OVER
};

enum EVENTS
{
	LEFT_FIRST,
	RIGHT_FIRST,
	LEFT_SECOND,
	RIGHT_SECOND,
	EXIT,
	CHANGE_TO_SDL_WIN,
	CHANGE_TO_SFML_WIN,
	CHANGE_TO_GLFW_WIN,
	NEW_GAME,
	DEFAULT
};

class IWindow
{
public:
	virtual EVENTS 			getEvent(void)  = 0;
	virtual void 			drawSquare(int x, int y, eType type) = 0;
	virtual void 			drawScore(int score, int velocity, eType type, int mult) = 0;
	virtual void 			drawStart() = 0;
	virtual void 			drawGameOver(std::string const & finishMessage) = 0;
	virtual void 			startCycl() = 0;
	virtual void 			init(void) = 0;
	virtual void 			endCycl(void) = 0;
//	virtual void 			quit(std::string const & finishMessage) = 0;
};


# endif
