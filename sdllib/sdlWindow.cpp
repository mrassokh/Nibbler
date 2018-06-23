/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdlWindow.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 14:21:37 by mrassokh          #+#    #+#             */
/*   Updated: 2018/05/19 14:21:39 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdlWindow.hpp"

SdlWindow::SdlWindow()
{

}

SdlWindow::SdlWindow(int width, int height)
{
	m_width = width * SQUARE_SIZE;
	m_height = height * SQUARE_SIZE;
	m_quit = false;

}

SdlWindow::~SdlWindow()
{

}

void 					SdlWindow::init(void)
{
	SDL_Init(SDL_INIT_VIDEO);
	m_window = SDL_CreateWindow("SDL2 line drawing",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_width, m_height, 0);
	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
}

void 					SdlWindow::startCycl()
{

	SDL_SetRenderDrawColor(m_renderer, 42, 242, 242, 255);
	SDL_RenderClear(m_renderer);
}

void 					SdlWindow::endCycl()
{
	SDL_RenderPresent(m_renderer);
}

void 					SdlWindow::drawScore(int score, int velocity, eType type, int mult)
{
	if (!mult){
		printf("score is %d;\n velocity is %d\n", score, velocity);
	} else {
		if (type == SNAKE_HEAD) {
			printf("FIRST PLAYER:\n score is %d;\n velocity is %d\n", score, velocity);
		} else if (type == SNAKE_SECOND_HEAD){
			printf("SECOND PLAYER:\n score is %d;\n velocity is %d\n", score, velocity);
		}
	}
}

void 					SdlWindow::quit(std::string const & finishMessage)
{
	SDL_Delay(1000);
	printf("%s\n", finishMessage.c_str());
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

EVENTS 			SdlWindow::getEvent(void)
{
	while (SDL_PollEvent(&m_event)){
	if (m_event.type == SDL_QUIT ||  m_event.key.keysym.sym == SDLK_ESCAPE)
		return EXIT;
	else if (m_event.type == SDL_KEYDOWN)
	{
		//printf("SDL_KEYDOWN %d\n", ret);

		return handleKeyDown(m_event.key.keysym.sym);
	}
	}
	return DEFAULT;
}

EVENTS 			SdlWindow::handleKeyDown(int key) const
{
	if (key == SDLK_LEFT)
		return LEFT_FIRST;
	else if (key == SDLK_RIGHT)
		return RIGHT_FIRST;
	else if (key == SDLK_q)
		return LEFT_SECOND;
	else if (key == SDLK_w)
		return RIGHT_SECOND;
	else if (key == SDLK_a)
		return CHANGE_TO_SDL_WIN;
	else if (key == SDLK_s)
		return CHANGE_TO_NCURS_WIN;
	else if (key == SDLK_d)
		return CHANGE_TO_GLUT_WIN;
	else if (key == SDLK_n)
		return NEW_GAME;
	else
		return DEFAULT;
}

void 			SdlWindow::drawSquare(int x, int y, eType type)
{
	SDL_Rect rectangle;

	rectangle.x = x *  SQUARE_SIZE;
	rectangle.y = y * SQUARE_SIZE;
	rectangle.w = SQUARE_SIZE;
	rectangle.h = SQUARE_SIZE;
	if (type == FOOD){
		SDL_SetRenderDrawColor(m_renderer,242, 0, 242, 255);
	} else if (type == SNAKE_HEAD) {
		SDL_SetRenderDrawColor(m_renderer,242, 0, 42, 255);
	} else if (type == SNAKE_SECOND_HEAD) {
		SDL_SetRenderDrawColor(m_renderer,42, 0, 242, 255);
	} else if (type == OBSTACLE) {
		SDL_SetRenderDrawColor(m_renderer, 0, 0, 142, 255);
	}  else  {
		SDL_SetRenderDrawColor(m_renderer,242, 242, 242, 255);
	}
	SDL_RenderFillRect(m_renderer, &rectangle);
}

void 				SdlWindow::drawStart()
{
	SDL_SetRenderDrawColor(m_renderer, 250, 0, 0, 255);
	printf("FOR START NEW GAME PRESS N\n FOR EXIT PRESS ECS\n");
	SDL_RenderClear(m_renderer);
	SDL_RenderPresent(m_renderer);
}

void 				SdlWindow::drawGameOver(std::string const & finishMessage)
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 250, 255);

	//printf("%s\n", finishMessage.c_str());
	//printf("FOR START NEW GAME PRESS N\n FOR EXIT PRESS ECS\n");
	SDL_RenderClear(m_renderer);
	SDL_RenderPresent(m_renderer);
	if (finishMessage == "")
		return ;
}

SdlWindow		*createWindow(int width, int height)
{
	return new SdlWindow(width, height);
}

void 		deleteWindow(SdlWindow *sdlWindow)
{
	delete sdlWindow;
}
