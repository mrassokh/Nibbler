/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfmlWindow.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 14:21:37 by rmalkevy          #+#    #+#             */
/*   Updated: 2018/05/19 14:21:39 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/sfmlWindow.hpp"
//#include "SFML-2.5.0-macOS-clang/include/SFML/Graphics/Rect.hpp"
//#include "SFML-2.5.0-macOS-clang/Frameworks/SFML.framework/Headers/Window/Keyboard.hpp"
//https://github.com/noxsnono/Nibbler/blob/master/lib_sfml/lib_sfml.class.cpp

SfmlWindow::SfmlWindow()
{

}

SfmlWindow::SfmlWindow(int width, int height)
{
	m_width = width * SQUARE_SIZE;
	m_height = height * SQUARE_SIZE;
	m_quit = false;

}

SfmlWindow::~SfmlWindow()
{
	delete m_event;
	delete m_window;
}

void 					SfmlWindow::init(void)
{
	sf::ContextSettings settings;

	_x = 5;
	_y = 5;
	settings.antialiasingLevel = 8;
	m_event = new sf::Event();
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::Vector2i pos((desktop.width / 2) - ((_x * 10) / 2), (desktop.height / 2) - ((_y * 10) / 2));
	try {
		m_window = new sf::RenderWindow(
				sf::VideoMode(_y * 10, _x * 10, 32),
				"Genius",
				sf::Style::Default,
				settings);
		m_window->setPosition(pos);
	}
	catch (std::exception & e) {
		std::cerr << "SFML EXCEPTION --] " << e.what() << std::endl;
	}
}

void 					SfmlWindow::startCycl()
{
//	SDL_SetRenderDrawColor(m_renderer, 42, 242, 242, 255);
//	SDL_RenderClear(m_renderer);
}

void 					SfmlWindow::endCycl()
{
//	SDL_RenderPresent(m_renderer);
}

void 					SfmlWindow::quit(void)
{
//	SDL_Delay(1000);
//	SDL_DestroyRenderer(m_renderer);
//	SDL_DestroyWindow(m_window);
//	SDL_Quit();
}

EVENTS 			SfmlWindow::getEvent(void)
{
	while (m_window->pollEvent(*m_event)){
		if (m_event->type == sf::Event::Closed)
			return EXIT;
		else if (m_event->type == sf::Event::KeyPressed)
		{
			//printf("SDL_KEYDOWN %d\n", ret);
			return handleKeyDown();
		}
	}
	return DEFAULT;
}

EVENTS 			SfmlWindow::handleKeyDown() const
{
	switch (m_event->key.code) {
		case sf::Keyboard::Left:
			return LEFT_FIRST;
		case sf::Keyboard::Q:
			return LEFT_SECOND;
		case sf::Keyboard::Right:
			return RIGHT_FIRST;
		case sf::Keyboard::W:
			return RIGHT_SECOND;
		case sf::Keyboard::A:
			return CHANGE_TO_SDL_WIN;
		case sf::Keyboard::S:
			return CHANGE_TO_NCURS_WIN;
		case sf::Keyboard::D:
			return CHANGE_TO_GLUT_WIN;
		case sf::Keyboard::M:
			return CHANGE_MULTIPLAYER_MODE;
		case sf::Keyboard::Escape:
			return EXIT;
		default: return DEFAULT;
	}
}

void 			SfmlWindow::drawSquare(int x, int y, eType type)
{
	sf::Sprite rectangle;
	rectangle.setTextureRect(sf::IntRect(x *  SQUARE_SIZE, y * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE));
	if (type == FOOD){
		rectangle.setColor(sf::Color(242, 0, 242, 255));
	} else if (type == SNAKE_HEAD) {
		rectangle.setColor(sf::Color(242, 0, 42, 255));
	} else if (type == OBSTACLE) {
		rectangle.setColor(sf::Color(0, 0, 142, 255));
	}  else  {
		rectangle.setColor(sf::Color(242, 242, 242, 255));
	}
	m_window->draw(rectangle);
}

