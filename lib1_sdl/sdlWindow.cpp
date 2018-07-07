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

void SdlWindow::showText(int x, int y, const char *text) {
	int texW = 0;
	int texH = 0;
	int posX = x;
	int posY = y;
	SDL_Color color = { 255, 255, 255, 0 };
	m_textSurface = TTF_RenderText_Blended_Wrapped(m_font, text, color, m_width / 2);
	m_textTexture = SDL_CreateTextureFromSurface(m_renderer, m_textSurface);
	SDL_QueryTexture(m_textTexture, NULL, NULL, &texW, &texH);
	if (x == 0 && y == 0) {
		posX = (m_width - texW) / 2;
		posY = (m_height - texH) / 2;
	}
	SDL_Rect dstrect = { posX, posY, texW, texH  };
	SDL_RenderCopy(m_renderer, m_textTexture, NULL, &dstrect);
	SDL_FreeSurface(m_textSurface);
	SDL_DestroyTexture(m_textTexture);
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

void 					SdlWindow::init()
{
	std::cout<< "Init" <<std::endl;
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	m_window = SDL_CreateWindow("SDL2 line drawing",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_width, m_height, 0);
	m_renderer = SDL_CreateRenderer(m_window, -1, 0);

	char path[1024];
	getcwd(path, sizeof(path));
	std::string fontPath = path;
	fontPath += "/fonts/arial.ttf";
	std::cout << fontPath << std::endl;
	m_font = TTF_OpenFont(fontPath.c_str(), 24);
	if (m_font == NULL) {
		printf("error: font not found\n");
		exit(EXIT_FAILURE);
	}
	std::cout << "End init" << std::endl;
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
	std::string results("score - " +std::to_string(score)+ "\nvelocity - " +std::to_string(velocity)+ "\n");
	if (!mult){
		showText(m_width - 200, 50, results.c_str());
	} else {
		if (type == SNAKE_HEAD) {
			results.insert(0, "FIRST PLAYER:\n");
			showText(m_width - 200, 50, results.c_str());
		} else if (type == SNAKE_SECOND_HEAD){
			results.insert(0, "SECOND PLAYER:\n");
			showText(m_width - 200, 150, results.c_str());
		}
	}
}

void 					SdlWindow::quit(std::string const & finishMessage)
{
	TTF_CloseFont(m_font);

	TTF_Quit();
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
	printf("%s\n", finishMessage.c_str());
}

EVENTS 			SdlWindow::getEvent(void)
{
	while (SDL_PollEvent(&m_event)){
		if (m_event.type == SDL_QUIT ||  m_event.key.keysym.sym == SDLK_ESCAPE)
			return EXIT;
		else if (m_event.type == SDL_KEYDOWN)
		{
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
		return CHANGE_TO_SFML_WIN;
	else if (key == SDLK_d)
		return CHANGE_TO_GLFW_WIN;
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
	std::string text("For start new game press <<N>>\nFor Exit press <<ECS>>");

	SDL_SetRenderDrawColor(m_renderer, 32,178,170, 255);
	SDL_RenderClear(m_renderer);
	showText(0, 0, text.c_str());
	SDL_RenderPresent(m_renderer);
}

void 				SdlWindow::drawGameOver(std::string const & finishMessage)
{
	SDL_SetRenderDrawColor(m_renderer, 32, 178, 170, 255);
	SDL_RenderClear(m_renderer);

	std::string message = finishMessage;
	message += "\nFor start new game press <<N>>\nFor Exit press <<ECS>>";
	showText(0, 0, message.c_str());
	SDL_RenderPresent(m_renderer);
}

SdlWindow		*createWindow(int width, int height)
{
	return new SdlWindow(width, height);
}

void 		deleteWindow(SdlWindow *sdlWindow)
{
	delete sdlWindow;
}
