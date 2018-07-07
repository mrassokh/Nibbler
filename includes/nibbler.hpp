/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nibbler.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 12:52:39 by mrassokh          #+#    #+#             */
/*   Updated: 2018/05/19 12:52:40 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBBLER_HPP
# define NIBBLER_HPP
#include <dlfcn.h>
#include <iostream>
#include "IWindow.hpp"
#include "GameField.hpp"
#include "Snake.hpp"
#include "SnakeHead.hpp"
#include "FoodSegment.hpp"
#include "CustomExeptions.hpp"
#include "FoodProcessor.hpp"
#include "SnakeProcessor.hpp"
#include "Render.hpp"
#include <array>
#include <vector>
#include "Obstacle.hpp"
#include "ObstacleProcessor.hpp"
#include <cstring>

class Nibbler
{
public:
	static	Nibbler								&Instance(int width, int height, int mult);
	void  										processing();

private:
	Nibbler();
	Nibbler(int width, int height, int mult);
	Nibbler(Nibbler const & rhs) = delete;
	Nibbler & operator = (Nibbler const & rhs) = delete;
	virtual ~Nibbler();


	void 										dlerror_wrapper(void);
	void 										initGame();
	void 										startScreen();
	void 										gameLoop();
	void 										gameOverScreen();
	void 										clearGame();

	void 										draw();
	int 										update();


	void 										eventHandling();

	void 										handleLeftFirstEvent();
	void 										handleRightFirstEvent();
	void 										handleLeftSecondEvent();
	void 										handleRightSecondEvent();
	void 										handleExitEvent();
	void 										handleChangeToSdlEvent();
	void 										handleChangeToSfmlEvent();
	void 										handleChangeToGLFWEvent();
	void 										handleNewGameEvent();
	void 										handleDefaultEvent();

	void 										rotateToLeft(std::shared_ptr<SnakeHead> headSquare);
	void 										rotateToRight(std::shared_ptr<SnakeHead> headSquare);


	std::array<void (Nibbler::*)(), 10>			m_eventFunctions;
	std::array<void (Nibbler::*)(), 3>			m_windowStateFunctions;

	std::shared_ptr<std::vector
			<std::shared_ptr<FoodSegment>>> 	m_foodList;

	std::shared_ptr<std::vector
			<std::shared_ptr<Obstacle>>> 		m_obstacleList;

	Snake										m_snake;
	Snake										m_secondSnake;


	GameField									*m_gameField;
	FoodProcessor								*m_foodProcessor;
	SnakeProcessor								*m_snakeProcessor;
	ObstacleProcessor							*m_obstacleProcessor;
	Render 										*m_render;



	IWindow 									*m_newWindow;
	int 										m_loopCondition;
	int 										m_startCondition;
	int 										m_gameOverCondition;
	int 										m_velocity;
	double										m_time;
	double										m_deltaTime;

	IWindow 									*(*m_windowCreator)(int width, int height);
	void										(*m_windowDestructor)(IWindow	*);
	void 										*dl_handle;
	int 										m_multMode;
	const char* 								m_sharedWindowLib;
	enum STATE									m_windowState;
	std::string 								m_finishMessage;
	int 										m_changeLib;
};

#endif
