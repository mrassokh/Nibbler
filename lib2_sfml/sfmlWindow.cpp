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
#include "SFML2.2/SFML-2.2-osx-clang-universal/Frameworks/SFML.framework/Versions/Current/Headers/System/Vector2.hpp"
//https://github.com/noxsnono/Nibbler/blob/master/lib_sfml/lib_sfml.class.cpp

SfmlWindow::SfmlWindow()
{}

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
	m_event = new sf::Event();

	sf::Vector2i pos(0, 0);
	try {
		sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
		m_window = new sf::RenderWindow(
				sf::VideoMode(m_width, m_height, desktop.bitsPerPixel),
				"Genius");
		m_window->setPosition(pos);
		m_window->setFramerateLimit(60);
	}
	catch (std::exception & e) {
		std::cerr << "SFML EXCEPTION --] " << e.what() << std::endl;
	}
}

void 					SfmlWindow::startCycl()
{
	m_window->clear(sf::Color(42, 242, 242, 255));
}

void 					SfmlWindow::endCycl()
{
	m_window->display();
}

void 					SfmlWindow::quit(void)
{
	m_window->close();
}

EVENTS 			SfmlWindow::getEvent(void)
{
	while (m_window->pollEvent(*m_event)){
		if (m_event->type == sf::Event::Closed)
			return EXIT;
		else if (m_event->type == sf::Event::KeyPressed)
		{
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
	sf::ConvexShape rect;

	rect.setOutlineThickness(0.5);
	rect.setPointCount(4);
	rect.setPoint(0, sf::Vector2f(0, 0));
	rect.setPoint(1, sf::Vector2f(SQUARE_SIZE, 0));
	rect.setPoint(2, sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));
	rect.setPoint(3, sf::Vector2f(0, SQUARE_SIZE));
	rect.setPosition(sf::Vector2f(x *  SQUARE_SIZE, y *  SQUARE_SIZE));
	rect.setOutlineColor(sf::Color(150, 150, 150));
	if (type == FOOD){
		rect.setFillColor(sf::Color(242, 0, 242, 255));
	} else if (type == SNAKE_HEAD) {
		rect.setFillColor(sf::Color(242, 0, 42, 255));
	} else if (type == OBSTACLE) {
		rect.setFillColor(sf::Color(0, 0, 142, 255));
	}  else  {
		rect.setFillColor(sf::Color(242, 242, 242, 255));
	}
	m_window->draw(rect);
}

SfmlWindow		*createWindow(int width, int height)
{
	return new SfmlWindow(width, height);
}

void			deleteWindow(SfmlWindow *sfmlWindow)
{
	delete sfmlWindow;
}