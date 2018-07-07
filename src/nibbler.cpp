/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nibbler.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 12:52:00 by mrassokh          #+#    #+#             */
/*   Updated: 2018/05/19 12:52:03 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//#include "nibbler.hpp"
#include "../includes/nibbler.hpp"

Nibbler::Nibbler() : m_loopCondition(1),
						m_velocity(1),
						m_time(0),
						m_deltaTime(0),
						m_multMode(0)
{
	srand(time(NULL));
}

Nibbler::~Nibbler()
{

}

Nibbler::Nibbler(int width, int height, int mult) : m_loopCondition(1),
													m_startCondition(1),
													m_gameOverCondition(1),
													m_velocity(1),
													m_time(0),
													m_deltaTime(0),
													m_multMode(mult),
													m_windowState(START),
													m_finishMessage(""),
													m_changeLib(0)


{
	srand(time(NULL));

	m_gameField = &GameField::Instance(width, height);
	m_foodProcessor = &FoodProcessor::Instance();
	m_snakeProcessor = &SnakeProcessor::Instance();
	m_obstacleProcessor = &ObstacleProcessor::Instance();
	m_render = &Render::Instance();

	m_eventFunctions[0] = &Nibbler::handleLeftFirstEvent;
	m_eventFunctions[1] = &Nibbler::handleRightFirstEvent;
	m_eventFunctions[2] = &Nibbler::handleLeftSecondEvent;
	m_eventFunctions[3] = &Nibbler::handleRightSecondEvent;
	m_eventFunctions[4] = &Nibbler::handleExitEvent;
	m_eventFunctions[5] = &Nibbler::handleChangeToSdlEvent;
	m_eventFunctions[6] = &Nibbler::handleChangeToSfmlEvent;
	m_eventFunctions[7] = &Nibbler::handleChangeToGLFWEvent;
	m_eventFunctions[8] = &Nibbler::handleNewGameEvent;
	m_eventFunctions[9] = &Nibbler::handleDefaultEvent;

	m_windowStateFunctions[0] = &Nibbler::startScreen;
	m_windowStateFunctions[1] = &Nibbler::gameLoop;
	m_windowStateFunctions[2] = &Nibbler::gameOverScreen;

	m_foodList = std::shared_ptr<std::vector<std::shared_ptr<FoodSegment>>>(new std::vector<std::shared_ptr<FoodSegment>>);
	m_obstacleList = std::shared_ptr<std::vector<std::shared_ptr<Obstacle>>>(new std::vector<std::shared_ptr<Obstacle>>);
	m_sharedWindowLib = "lib1_sdl.so";
}

Nibbler			&Nibbler::Instance(int width, int height, int mult)
{
	static Nibbler instance(width, height, mult);
	return instance;
}

void 			Nibbler::dlerror_wrapper(void) {
	std::cerr << "Error:" << dlerror() << std::endl;
	exit(EXIT_FAILURE);
}

void 			Nibbler::initGame(void)
{
	m_snakeProcessor->initSnake(m_snake, m_gameField, 0, m_multMode);
	if (m_multMode)
		m_snakeProcessor->initSnake(m_secondSnake, m_gameField, 1, m_multMode);
	m_obstacleProcessor->initObstacleList(m_obstacleList, m_gameField);
	m_foodProcessor->initFoodList(m_foodList,m_gameField);
}

void 								Nibbler::clearGame()
{
	printf("%s\n","ClearGame" );
	m_velocity = 1;
	m_time = 0;
	m_deltaTime = 0;
	m_loopCondition = 0;
	m_gameField->clear();
	m_foodList->clear();
	m_obstacleList->clear();
	m_snake.getSnake()->clear();
	m_snake.setScore(0);
	if (m_multMode) {
		m_secondSnake.getSnake()->clear();
		m_secondSnake.setScore(0);
	}
}

void  			Nibbler::processing()
{
	while (strcmp(m_sharedWindowLib, "exit") != 0){
		m_changeLib = 0;
		dl_handle = dlopen(m_sharedWindowLib, RTLD_LAZY | RTLD_LOCAL);
		if (!dl_handle) {
			dlerror_wrapper();
		}
		m_windowCreator = reinterpret_cast<IWindow *(*)(int width, int height)>(dlsym(dl_handle, "createWindow"));
		if (!m_windowCreator) {
			dlerror_wrapper();
		}
	    m_newWindow = m_windowCreator(m_gameField->getWidth(), m_gameField->getHeight());
		m_newWindow->init();
		while (!m_changeLib)
			(this->*m_windowStateFunctions[m_windowState])();
		m_windowDestructor = reinterpret_cast<void (*)(IWindow*)>(dlsym(dl_handle, "deleteWindow"));
		if (!m_windowDestructor){
			dlerror_wrapper();
		}
		m_windowDestructor(m_newWindow);
		dlclose(dl_handle);
	}
}

void 	Nibbler::startScreen()
{
	m_startCondition = 1;
	while (m_startCondition){
		m_newWindow->drawStart();
		eventHandling();
	}
}

void 	Nibbler::gameOverScreen()
{
	m_gameOverCondition = 1;
	while (m_gameOverCondition){
		m_newWindow->drawGameOver(m_finishMessage);
		eventHandling();
	}
}

void 			Nibbler::gameLoop()
{
	double velocity_incr = 0;
	m_loopCondition = 1;
	m_snakeProcessor->configure(m_foodList, m_gameField, m_newWindow, &m_loopCondition, m_multMode);
	while (m_loopCondition) {
		clock_t start = clock();
		if (!update())
			break;
		draw();
		eventHandling();
		m_deltaTime = static_cast<double>((clock() - start ))/ CLOCKS_PER_SEC;
		m_time += m_deltaTime;
		if (velocity_incr > 5 && m_velocity < 50) {
			m_velocity += 1;
			velocity_incr = 0;
		}
		velocity_incr += m_deltaTime;
	}
}

int 			Nibbler::update()
{
	try {
		m_snakeProcessor->updateSnake(m_snake, m_velocity, m_deltaTime);
		if (m_multMode) {
			m_snakeProcessor->updateSnake(m_secondSnake, m_velocity, m_deltaTime);
		}
		m_snakeProcessor->checkFinish(m_snake, m_secondSnake);
		m_foodProcessor->timeUpdateFoodList(m_foodList, m_gameField);
	}
	catch (std::exception& e)	{
		m_finishMessage = static_cast<std::string>(e.what());
		m_finishMessage.insert(0, "GAME OVER!!!\n");
		m_loopCondition = 0;
		clearGame();
		m_windowState = GAME_OVER;
		return (0);
	}
	return (1);
}

void 			Nibbler::draw()
{
	m_newWindow->startCycl();
	m_render->drawFood(m_foodList, m_newWindow);
	m_render->drawObstacles(m_obstacleList, m_newWindow);
	m_render->drawSnake(m_snake, m_newWindow);
	m_render->drawFood(m_foodList, m_newWindow);
	m_render->drawObstacles(m_obstacleList, m_newWindow);
	if (m_multMode){
		m_render->drawSnake(m_secondSnake, m_newWindow);
		m_newWindow->drawScore(m_snake.getScore(), m_velocity, SNAKE_HEAD, 1);
		m_newWindow->drawScore(m_secondSnake.getScore(), m_velocity, SNAKE_SECOND_HEAD, 1);
	} else {
		m_newWindow->drawScore(m_snake.getScore(), m_velocity, SNAKE_HEAD, 0);
	}
	m_newWindow->endCycl();
}

void 			Nibbler::eventHandling()
{
	EVENTS ev = m_newWindow->getEvent();
	(this->*m_eventFunctions[ev])();
	if (ev == 4)
		m_loopCondition = 0;
}


void 			Nibbler::handleLeftFirstEvent()
{
	if (m_windowState != GAME)
		return ;

	auto headSquare = std::dynamic_pointer_cast<SnakeHead>(*(m_snake.getSnake()->begin()));
   	printf("headSquare->getLeftRotationCondition()  = %d\n",headSquare->getLeftRotationCondition());
	if (headSquare->getLeftRotationCondition() < 0)
		return ;
	rotateToLeft(headSquare);
}

void 			Nibbler::handleRightFirstEvent()
{
	if (m_windowState != GAME)
		return ;

	auto headSquare = std::dynamic_pointer_cast<SnakeHead>(*(m_snake.getSnake()->begin()));
	if (headSquare->getRightRotationCondition() < 0)
		return ;
	rotateToRight(headSquare);
}

void 			Nibbler::handleLeftSecondEvent()
{
	if (m_windowState != GAME)
		return ;

	auto headSquare = std::dynamic_pointer_cast<SnakeHead>(*(m_secondSnake.getSnake()->begin()));
	if (headSquare->getLeftRotationCondition() < 0)
		return ;
	rotateToLeft(headSquare);
}

void 			Nibbler::handleRightSecondEvent()
{
	if (m_windowState != GAME)
		return ;

	auto headSquare = std::dynamic_pointer_cast<SnakeHead>(*(m_secondSnake.getSnake()->begin()));
	if (headSquare->getRightRotationCondition() < 0)
		return ;
	rotateToRight(headSquare);
}

void 			Nibbler::handleExitEvent()
{
	m_newWindow->quit("");
	m_loopCondition = 0;
	m_startCondition = 0;
	m_gameOverCondition = 0;
	m_sharedWindowLib = "exit";
	m_changeLib = 1;
}

void 			Nibbler::handleChangeToSdlEvent()
{
	m_loopCondition = 0;
	m_startCondition = 0;
	m_gameOverCondition = 0;
	m_newWindow->quit("");
	printf("handleChangeToSdlEvent!!!\n");
	m_sharedWindowLib = "lib1_sdl.so";
	m_changeLib = 1;
}
void 				Nibbler::handleChangeToSfmlEvent()
{
	m_loopCondition = 0;
	m_startCondition = 0;
	m_gameOverCondition = 0;
	m_newWindow->quit("");
	printf("handleChangeToSfmlEvent!!!\n");
	m_sharedWindowLib = "lib2_sfml.so";
	m_changeLib = 1;
}

void 		Nibbler::handleChangeToGLFWEvent()
{
	m_loopCondition = 0;
	m_startCondition = 0;
	m_gameOverCondition = 0;
	m_newWindow->quit("");
	printf("handleChangeToGLFWEvent!!!\n\n\n");
	m_sharedWindowLib = "lib3_glfw.so";
	m_changeLib = 1;
}


void 		Nibbler::handleNewGameEvent()
{
	m_loopCondition = 0;
	m_startCondition = 0;
	m_gameOverCondition = 0;
	clearGame();
	initGame();
	m_windowState = GAME;
}

void 		Nibbler::handleDefaultEvent()
{

}

void 		Nibbler::rotateToLeft(std::shared_ptr<SnakeHead> headSquare)
{
	int newDirX = headSquare->getDirY() ;
	int newDirY = (-1) * headSquare->getDirX();
	headSquare->setDirX(newDirX);
	headSquare->setDirY(newDirY);
	headSquare->setLeftRotationCondition(headSquare->getLeftRotationCondition() - 1);
	headSquare->setRightRotationCondition(headSquare->getRightRotationCondition() + 1);
}

void 		Nibbler::rotateToRight(std::shared_ptr<SnakeHead> headSquare)
{
	int newDirX = (-1) * headSquare->getDirY();
	int newDirY =  headSquare->getDirX();
	headSquare->setDirX(newDirX);
	headSquare->setDirY(newDirY);
	headSquare->setLeftRotationCondition(headSquare->getLeftRotationCondition() + 1);
	headSquare->setRightRotationCondition(headSquare->getRightRotationCondition() - 1);
}
