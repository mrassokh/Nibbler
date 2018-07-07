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

	m_window = new sf::RenderWindow(sf::VideoMode(m_width, m_height), "Nibbler SFML");
	try
	{
		if (m_window == NULL)
			throw "Could not create sfml window";
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void 					SfmlWindow::startCycl()
{
	m_window->clear(sf::Color(244,164,96, 255)); //32,178,170
}

void 					SfmlWindow::endCycl()
{
	m_window->display();
}

void 					SfmlWindow::quit(std::string const & finishMessage)
{
	m_window->close();
	if (finishMessage == "")
		return;
}

EVENTS 			SfmlWindow::getEvent()
{
	while (m_window->pollEvent(*m_event)){
		if (m_event->type == sf::Event::Closed){
			return EXIT;
		}
		else if (m_event->type == sf::Event::KeyPressed){
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
			return CHANGE_TO_SFML_WIN;
		case sf::Keyboard::D:
			return CHANGE_TO_GLFW_WIN;
		case sf::Keyboard::N:
			return NEW_GAME;
		case sf::Keyboard::Escape:
			return EXIT;
		default: return DEFAULT;
	}
}

void 			SfmlWindow::drawSquare(int x, int y, eType type)
{
	sf::ConvexShape rect;

	rect.setOutlineThickness(1);
	rect.setOutlineColor(sf::Color(150, 150, 150));
	rect.setPointCount(4);
	rect.setPoint(0, sf::Vector2f(0, 0));
	rect.setPoint(1, sf::Vector2f(SQUARE_SIZE, 0));
	rect.setPoint(2, sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));
	rect.setPoint(3, sf::Vector2f(0, SQUARE_SIZE));
	rect.setPosition(sf::Vector2f(x *  SQUARE_SIZE, y *  SQUARE_SIZE));
	if (type == FOOD){
		rect.setFillColor(sf::Color(165, 42, 42, 255));
	} else if (type == SNAKE_HEAD) {
		rect.setFillColor(sf::Color(242, 0, 42, 255));
	} else if (type == SNAKE_SECOND_HEAD) {
		rect.setFillColor(sf::Color(42, 0, 242, 255));
	} else if (type == OBSTACLE) {
		rect.setFillColor(sf::Color(105, 105, 105, 255));
	}  else  {
		rect.setFillColor(sf::Color(255,222,173, 255));
	}
//	242, 242, 242
	m_window->draw(rect);
}


void 			SfmlWindow::drawScore(int score, int velocity, eType type, int mult)
{
	sf::Font font;
	font.loadFromFile("./fonts/arial.ttf");

	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(25);
	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color::Black);
	std::string results("score is " +std::to_string(score)+ "\nvelocity is " +std::to_string(velocity)+ "\n");
	text.setPosition(sf::Vector2f(m_width - 300, 50));
	if (!mult){
		text.setString(results.c_str());
	} else {
		if (type == SNAKE_HEAD) {
			results.insert(0, "FIRST PLAYER:\n");
		} else if (type == SNAKE_SECOND_HEAD){
			text.setPosition(sf::Vector2f(m_width - 300, 150));
			results.insert(0, "SECOND PLAYER:\n");
		}
		text.setString(results);
	}
	m_window->draw(text);

}
void 			SfmlWindow::drawStart()
{
	m_window->clear(sf::Color(32,178,170, 255));
	sf::Font font;
	font.loadFromFile("./fonts/arial.ttf");

	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(40);
	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color::Black);
	text.setString(        "FOR START NEW GAME PRESS << N >>\n"
						   "--------------------------------\n"
						   "FOR EXIT PRESS << ESC >>\n");

	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width/2.0f,
				   textRect.top  + textRect.height/2.0f);
	text.setPosition(sf::Vector2f(m_width/2.0f,m_height/2.0f));

	m_window->draw(text);
	m_window->display();
}

void 			SfmlWindow::drawGameOver(std::string const & finishMessage)
{
	m_window->clear(sf::Color(0, 0, 250, 255));
	sf::Font font;
	font.loadFromFile("./fonts/arial.ttf");

	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(40);
	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color::White);
	text.setString(finishMessage.c_str());

	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width/2.0f,
				   textRect.top  + textRect.height/2.0f);
	text.setPosition(sf::Vector2f(m_width/2.0f,m_height/2.0f));

	m_window->draw(text);
	m_window->display();
}



SfmlWindow		*createWindow(int width, int height)
{
	return new SfmlWindow(width, height);
}

void			deleteWindow(SfmlWindow *sfmlWindow)
{
	delete sfmlWindow;
}
