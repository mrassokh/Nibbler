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

Nibbler::Nibbler()
{
	srand(time(NULL));
}

Nibbler::~Nibbler()
{

}

Nibbler::Nibbler(int width, int height) : m_loopCondition(1),
											m_velocity(10),
											m_time(0),
											m_deltaTime(0)


{
	srand(time(NULL));

	m_gameField = &GameField::Instance(width, height);
	m_foodProcessor = &FoodProcessor::Instance();
	m_snakeProcessor = &SnakeProcessor::Instance();
	m_render = &Render::Instance();
	m_eventFunctions[0] = &Nibbler::handleLeftFirstEvent;
	m_eventFunctions[1] = &Nibbler::handleRightFirstEvent;
	m_eventFunctions[2] = &Nibbler::handleLeftSecondEvent;
	m_eventFunctions[3] = &Nibbler::handleRightSecondEvent;
	m_eventFunctions[4] = &Nibbler::handleExitEvent;
	m_eventFunctions[5] = &Nibbler::handleChangeToSdlEvent;
	m_eventFunctions[6] = &Nibbler::handleChangeToSfmlEvent;
	m_eventFunctions[7] = &Nibbler::handleChangeToGlutEvent;
	m_eventFunctions[8] = &Nibbler::handleChangeMultiplayerEvent;
	m_eventFunctions[9] = &Nibbler::handleDefaultEvent;

	m_foodList = std::shared_ptr<std::vector<std::shared_ptr<FoodSegment>>>(new std::vector<std::shared_ptr<FoodSegment>>);
//	m_foodList = std::shared_ptr<std::vector<std::shared_ptr<Obstacle>>>(new std::vector<std::shared_ptr<Obstacle>>);
	m_snakeProcessor->initSnake(m_snake, m_gameField);
	m_foodProcessor->initFoodList(m_foodList,m_gameField);
	m_sharedWindowLib = "lib1_sdl.so";
}

Nibbler			&Nibbler::Instance(int width, int height)
{
	static Nibbler instance(width, height);
	return instance;
}

void 			Nibbler::dlerror_wrapper(void) {
	std::cerr << "Error:" << dlerror() << std::endl;
	exit(EXIT_FAILURE);
}


void  			Nibbler::processing()
{
	while (strcmp(m_sharedWindowLib, "exit") != 0){
		dl_handle = dlopen(m_sharedWindowLib, RTLD_LAZY | RTLD_LOCAL);
		if (!dl_handle) {
			dlerror_wrapper();
			std::cout << "first" << std::endl;
		}
		printf("m_sharedWindowLib %s!!!\n\n\n", m_sharedWindowLib);
		m_windowCreator = reinterpret_cast<IWindow *(*)(int width, int height)>(dlsym(dl_handle, "createWindow"));
		if (!m_windowCreator) {
			std::cout << "second" << std::endl;
			dlerror_wrapper();
		}
		m_newWindow = m_windowCreator(m_gameField->getWidth(), m_gameField->getHeight());
		std::cout << "width - " << m_gameField->getWidth() << " height - " << m_gameField->getHeight() << std::endl;
		m_newWindow->init();
		m_loopCondition = 1;
		gameLoop();
		m_windowDestructor = reinterpret_cast<void (*)(IWindow*)>(dlsym(dl_handle, "deleteWindow"));
		if (!m_windowDestructor)
			dlerror_wrapper();
		m_windowDestructor(m_newWindow);
		dlclose(dl_handle);
	}
}


void 			Nibbler::gameLoop()
{
	double velocity_incr = 0;
	m_snakeProcessor->configure(m_foodList, m_gameField, m_newWindow, &m_loopCondition);
	while (m_loopCondition) {
		clock_t start = clock();
		eventHandling();
		try {
			m_snakeProcessor->updateSnake(m_snake, m_velocity, m_deltaTime);
			m_foodProcessor->timeUpdateFoodList(m_foodList, m_gameField);
		}
		catch (std::exception& e)	{
			std::cerr << e.what() << std::endl;
			m_sharedWindowLib = "exit";
		}
		draw();
//		printf("score is %d\n", m_snake.getScore());
		m_deltaTime = static_cast<double>((clock() - start ))/ CLOCKS_PER_SEC;
		m_time += m_deltaTime;
		if (velocity_incr > 1) {
			m_velocity += 5;
			velocity_incr = 0;
		}
		velocity_incr += m_deltaTime;
	}
}

void 			Nibbler::draw()
{
	m_newWindow->startCycl();
	m_render->drawSnake(m_snake, m_newWindow);
	m_render->drawFood(m_foodList, m_newWindow);
	m_newWindow->endCycl();
}

void 			Nibbler::eventHandling()
{
	EVENTS ev = m_newWindow->getEvent();
	(this->*m_eventFunctions[ev])();
	if (ev == 4)
		m_loopCondition = 0;
}


void 										Nibbler::handleLeftFirstEvent()
{
		auto headSquare = std::dynamic_pointer_cast<SnakeHead>(*(m_snake.getSnake()->begin()));
	//	printf("LEFT EVENT with RotationCondition %d", headSquare->getRotationCondition());
		if (!headSquare->getRotationCondition())
			return ;
		int newDirX = headSquare->getDirY() ;
		int newDirY = (-1) * headSquare->getDirX();
		headSquare->setDirX(newDirX);
		headSquare->setDirY(newDirY);
		headSquare->setRotationCondition(0);
}

void 										Nibbler::handleRightFirstEvent()
{
		auto headSquare = std::dynamic_pointer_cast<SnakeHead>(*(m_snake.getSnake()->begin()));
	//	printf("Right EVENT with RotationCondition %d", headSquare->getRotationCondition());
		if (!headSquare->getRotationCondition())
			return ;
		int newDirX = (-1) * headSquare->getDirY();
		int newDirY =  headSquare->getDirX();
		headSquare->setDirX(newDirX);
		headSquare->setDirY(newDirY);
		headSquare->setRotationCondition(0);
}

void 										Nibbler::handleLeftSecondEvent()
{
		printf("handleLeftSecondEvent!!!\n\n\n");
}

void 										Nibbler::handleRightSecondEvent()
{
		printf("handleRightSecondEvent!!!\n\n\n");
}

void 										Nibbler::handleExitEvent()
{
	m_newWindow->quit() ;
	m_sharedWindowLib = "exit";
}
void 										Nibbler::handleChangeToSdlEvent()
{
	m_loopCondition = 0;
	m_newWindow->quit();
	printf("handleChangeToSdlEvent!!!\n\n\n");
	m_sharedWindowLib = "lib1_sdl.so";
}
void 										Nibbler::handleChangeToSfmlEvent()
{
	m_loopCondition = 0;
	m_newWindow->quit();
	printf("handleChangeToSfmlEvent!!!\n\n\n");
	m_sharedWindowLib = "lib2_sfml.so";
}
void 										Nibbler::handleChangeToGlutEvent()
{
	m_loopCondition = 0;
	m_newWindow->quit();
	printf("handleChangeToGlutEvent!!!\n\n\n");
	m_sharedWindowLib = "glutlib.so";
}

void 										Nibbler::handleChangeMultiplayerEvent()
{
	m_multMode = m_multMode == 0 ? 1 : 0;
	printf("m_multMode is %d!!!\n\n\n", m_multMode);
}

void 										Nibbler::handleDefaultEvent()
{

}
