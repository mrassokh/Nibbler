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
#include "IEntity.hpp"
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
#include <cstring>
class Nibbler
{
public:
	static	Nibbler								&Instance(int width, int height);
	void  										processing();
	//void  										processing(char **av);

private:
	Nibbler();
	Nibbler(int width, int height);
	Nibbler(Nibbler const & rhs) = delete;
	Nibbler & operator = (Nibbler const & rhs) = delete;
	virtual ~Nibbler();

	void 										dlerror_wrapper(void);
	void 										gameLoop();
	void 										draw();
	void 										update();


	void 										eventHandling();

	void 										handleLeftFirstEvent();
	void 										handleRightFirstEvent();
	void 										handleLeftSecondEvent();
	void 										handleRightSecondEvent();
	void 										handleExitEvent();
	void 										handleChangeToSdlEvent();
	void 										handleChangeToNcursEvent();
	void 										handleChangeToGlutEvent();
	void 										handleChangeMultiplayerEvent();
	void 										handleDefaultEvent();


	std::array<void (Nibbler::*)(), 10>			m_eventFunctions;

	std::shared_ptr<std::vector
			<std::shared_ptr<FoodSegment>>> 	m_foodList;

	std::shared_ptr<std::vector
			<std::shared_ptr<Obstacle>>> 		m_obstacleList;

	GameField									*m_gameField;
	FoodProcessor								*m_foodProcessor;
	SnakeProcessor								*m_snakeProcessor;
	Render 										*m_render;
	Snake										m_snake;
	IWindow 									*m_newWindow;
	int 										m_loopCondition;
	int 										m_velocity;
	double										m_time;
	double										m_deltaTime;

	IWindow 									*(*m_windowCreator)(int width, int height);
	void										(*m_windowDestructor)(IWindow	*);
	void 										*dl_handle;
	int 										m_multMode;
	const char* 								m_sharedWindowLib;
};


#endif
