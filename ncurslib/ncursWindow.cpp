/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncursWindow.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 13:29:22 by mrassokh          #+#    #+#             */
/*   Updated: 2018/06/02 13:29:24 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ncursWindow.hpp"

NcursWindow::NcursWindow()
{

}

NcursWindow::NcursWindow(int width, int height)
{
	m_width = width * SQUARE_SIZE;
	m_height = height * SQUARE_SIZE;
	m_quit = false;

}

NcursWindow::~NcursWindow()
{

}

void 					NcursWindow::init(void)
{
	// initscr();
    // curs_set(0);
    // nodelay(stdscr, true);
    // noecho();
    // keypad(stdscr, true);
    // int loop = 1;
    // while (loop)
    //     loop = 1;
    // endwin();

}

void 					NcursWindow::startCycl()
{

	// SDL_SetRenderDrawColor(m_renderer, 42, 242, 242, 255);
	// SDL_RenderClear(m_renderer);
}

void 					NcursWindow::endCycl()
{
	//SDL_RenderPresent(m_renderer);
}

// void 					NcursWindow::draw(int const & grid_x, int const & grid_y)
//  {
// // 	SDL_Delay(10);
// // 	SDL_PollEvent(&m_event);
// // 	SDL_SetRenderDrawColor(m_renderer, 42, 242, 242, 255);
// // 	SDL_RenderClear(m_renderer);
//
// 	drawSquare(grid_x, grid_y, SNAKE_HEAD);
// 	//SDL_RenderPresent(m_renderer);
// }

void 					NcursWindow::quit(std::string const & finishMessage)
{
	if (finishMessage == "")
		return;
	// SDL_Delay(1000);
	// SDL_DestroyRenderer(m_renderer);
	// SDL_DestroyWindow(m_window);
	// SDL_Quit();
}

EVENTS 			NcursWindow::getEvent()
{

	// while (SDL_PollEvent(&m_event)){
	// if (m_event.type == SDL_QUIT ||  m_event.key.keysym.sym == SDLK_ESCAPE)
	// 	return EXIT;
	// else if (m_event.type == SDL_KEYDOWN)
	// {
	// 	//printf("SDL_KEYDOWN %d\n", ret);
    //
	// 	return handleKeyDown(m_event.key.keysym.sym);
	// }
	// }
	return DEFAULT;
}

EVENTS 			NcursWindow::handleKeyDown(int key) const
{
	// if (key == SDLK_LEFT)
	// 	return LEFT_FIRST;
	// else if (key == SDLK_RIGHT)
	// 	return RIGHT_FIRST;
	// else if (key == SDLK_q)
	// 	return LEFT_SECOND;
	// else if (key == SDLK_w)
	// 	return RIGHT_SECOND;
	// else if (key == SDLK_a)
	// 	return CHANGE_TO_SDL_WIN;
	// else if (key == SDLK_s)
	// 	return CHANGE_TO_NCURS_WIN;
	// else if (key == SDLK_d)
	// 	return CHANGE_TO_GLUT_WIN;
	// else if (key == SDLK_m)
	// 	return CHANGE_MULTIPLAYER_MODE;
	// else
	// 	return DEFAULT;
	if (key)
		return DEFAULT;
	return DEFAULT;
}
void 					NcursWindow::drawScore(int score, int velocity, eType type, int mult)
{
	if (score != velocity)
	mult  = type * 10;
}
void 			NcursWindow::drawSquare(int x, int y, eType type)
{
	if (type)
	x = y /10;
	// SDL_Rect rectangle;
    //
	// rectangle.x = x *  SQUARE_SIZE;
	// rectangle.y = y * SQUARE_SIZE;
	// rectangle.w = SQUARE_SIZE;
	// rectangle.h = SQUARE_SIZE;
	// if (type == FOOD){
	// 	SDL_SetRenderDrawColor(m_renderer,242, 0, 242, 255);
	// } else if (type == SNAKE_HEAD) {
	// 	SDL_SetRenderDrawColor(m_renderer,242, 0, 42, 255);
	// } else  {
	// 	SDL_SetRenderDrawColor(m_renderer,242, 242, 242, 255);
	// }
	// SDL_RenderFillRect(m_renderer, &rectangle);
}

void 					NcursWindow::drawStart()
{

}

void 					NcursWindow::drawGameOver(std::string const & finishMessage)
{
	if (finishMessage == "")
		return;
}

NcursWindow		*createWindow(int width, int height)
{
	return new NcursWindow(width, height);
}

void 		deleteWindow(NcursWindow *NcursWindow)
{
	delete NcursWindow;
}
