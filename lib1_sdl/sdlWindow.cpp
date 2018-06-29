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

#include "../includes/sdlWindow.hpp"
#include <unistd.h>

void get_text_and_rect(SDL_Renderer *renderer, int x, int y, const char *text,
					   SDL_Texture **texture, SDL_Rect *rect)
{
	char path[1024];
	getcwd(path, sizeof(path));
	std::string fontPath = path;
	fontPath += "/fonts/arial.ttf";
	std::cout << fontPath << std::endl;
	TTF_Font* font = TTF_OpenFont("arial.ttf", 24);
	if (font == NULL) {
		printf("error: font not found\n");
		exit(EXIT_FAILURE);
	}
	SDL_Color textColor = { 255, 255, 255, 0 };
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, textColor);
	*texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	int text_width = textSurface->w;
	int text_height = textSurface->h;
	SDL_FreeSurface(textSurface);
	rect->x = x;
	rect->y = y;
	rect->w = text_width;
	rect->h = text_height;
}


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
	TTF_Init();
	m_window = SDL_CreateWindow("SDL2 line drawing",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_width, m_height, 0);
	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
}

void 					SdlWindow::startCycl()
{

	SDL_SetRenderDrawColor(m_renderer, 244, 164, 96, 255);
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
	printf("%s\n", finishMessage.c_str());
	SDL_Delay(1000);
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	TTF_Quit();
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
		SDL_SetRenderDrawColor(m_renderer, 165, 42, 42, 255);
	} else if (type == SNAKE_HEAD) {
		SDL_SetRenderDrawColor(m_renderer, 242, 0, 42, 255);
	} else if (type == SNAKE_SECOND_HEAD) {
		SDL_SetRenderDrawColor(m_renderer, 42, 0, 242, 255);
	} else if (type == OBSTACLE) {
		SDL_SetRenderDrawColor(m_renderer, 105, 105, 105, 255);
	}  else  {
		SDL_SetRenderDrawColor(m_renderer, 255,222,173, 255);
	}
	SDL_RenderFillRect(m_renderer, &rectangle);
}

void 				SdlWindow::drawStart()
{
	SDL_Texture *texture;
	SDL_Rect rect;
	std::string text("FOR START NEW GAME PRESS N\n FOR EXIT PRESS ECS\n");
	std::cout << "Draw start: 1) Line" << std::endl;
	get_text_and_rect(m_renderer, 0, 0, text.c_str(), &texture, &rect);
	std::cout << "Draw start: 2) Line" << std::endl;
	SDL_SetRenderDrawColor(m_renderer, 32,178,170, 255);
	std::cout << "Draw start: 3) Line" << std::endl;
	SDL_RenderClear(m_renderer);
	std::cout << "Draw start: 4) Line" << std::endl;
	printf("FOR START NEW GAME PRESS N\n FOR EXIT PRESS ECS\n");

	SDL_RenderPresent(m_renderer);
	std::cout << "Draw start: 5) Line" << std::endl;
	SDL_DestroyTexture(texture);
	std::cout << "Draw start: 6) Line" << std::endl;
}

void 				SdlWindow::drawGameOver(std::string const & finishMessage)
{
	SDL_SetRenderDrawColor(m_renderer, 32,178,170, 255);

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
