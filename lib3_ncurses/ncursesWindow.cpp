/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncursesWindow.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 14:21:37 by rmalkevy          #+#    #+#             */
/*   Updated: 2018/06/30 14:21:39 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ncursesWindow.hpp"

ncursesWindow::ncursesWindow()
{}

ncursesWindow::ncursesWindow(int width, int height)
{
	m_width = width;
	m_height = height;
}

ncursesWindow::~ncursesWindow()
{}

void 					ncursesWindow::init(void)
{
	initscr();
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);		// wall
	init_pair(2, COLOR_GREEN, COLOR_BLACK);		// snake
	init_pair(3, COLOR_CYAN, COLOR_BLACK);		// fruit
	init_pair(4, COLOR_RED, COLOR_BLACK);		// special
	m_window = newwin(m_height, m_width, 0, 0);
	if (m_window == NULL)
		throw std::exception();
	wbkgd(m_window, COLOR_PAIR(0));
	cbreak();
	noecho();
	nodelay(stdscr, true);
	curs_set(0);
	keypad(m_window, true);
	wrefresh(m_window);
}

void 					ncursesWindow::startCycl()
{
	werase(m_window);
	wattron(m_window, COLOR_PAIR(1));
}

void 					ncursesWindow::endCycl()
{
	wrefresh(m_window);
}

void 					ncursesWindow::quit(std::string const & finishMessage)
{
//	printf("%s\n", finishMessage.c_str());
	(void)finishMessage;
	refresh();
	wrefresh(m_window);
	delwin(m_window);
	endwin();
}

EVENTS 			ncursesWindow::getEvent()
{
	int pollEvent = 1;

	wtimeout(m_window, 1);
	while (pollEvent){
		m_event = wgetch(m_window);
		if (m_event == 27)
			return EXIT;
		else {
			return handleKeyDown();
		}
	}
	return DEFAULT;
}

EVENTS 			ncursesWindow::handleKeyDown() const
{
	switch (m_event) {
		case KEY_LEFT:	return LEFT_FIRST;
		case 'q':		return LEFT_SECOND;
		case KEY_RIGHT:	return RIGHT_FIRST;
		case 'w':		return RIGHT_SECOND;
		case 'a':		return CHANGE_TO_SDL_WIN;
		case 's':		return CHANGE_TO_SFML_WIN;
		case 'd':		return CHANGE_TO_NCURS_WIN;
		case 'n':		return NEW_GAME;
		case 27:		return EXIT;
		default: return DEFAULT;
	}
}

void 			ncursesWindow::drawSquare(int x, int y, eType type)
{
//	int	state = 1;
//
//	for (y = 0; y < this->_y; y++) {
//		for (x = 0; x < this->_x; x++) {
//			if (state != 1 && this->_map[y][x] == WALL) {
//				wattroff(this->_window, COLOR_PAIR(state));
//				wattron(this->_window, COLOR_PAIR(1));
//				state = 1;
//			}
//			else if (state != 3 && this->_map[y][x] == FRUIT) {
//				wattroff(this->_window, COLOR_PAIR(state));
//				wattron(this->_window, COLOR_PAIR(3));
//				state = 3;
//			}
//			else if (state != 2 && (this->_map[y][x] == QUEUE || this->_map[y][x] == HEAD)) {
//				wattroff(this->_window, COLOR_PAIR(state));
//				wattron(this->_window, COLOR_PAIR(2));
//				state = 2;
//			}
//			else if (state != 4 && this->_map[y][x] == SPECIAL){
//				wattroff(this->_window, COLOR_PAIR(state));
//				wattron(this->_window, COLOR_PAIR(4));
//				state = 4;
//			}
//			mvwprintw(this->_window, y, x, "%c", this->_map[y][x]);
//		}
//	}



	if (type == FOOD){
		wattron(m_window, COLOR_PAIR(3));
	} else if (type == SNAKE_HEAD) {
		wattron(m_window, COLOR_PAIR(2));
	} else if (type == SNAKE_SECOND_HEAD) {
		wattron(m_window, COLOR_PAIR(3));
	} else if (type == OBSTACLE) {
		wattron(m_window, COLOR_PAIR(1));
	}  else  {
		wattron(m_window, COLOR_PAIR(4));
	}
	mvwprintw(m_window, y, x, "%c", '*');
}


void 			ncursesWindow::drawScore(int score, int velocity, eType type, int mult)
{
	score = 0;
	velocity = 0;
	type = SNAKE_HEAD;
	mult = 0;
//	std::string results("score is " +std::to_string(score)+ "\nvelocity is " +std::to_string(velocity)+ "\n");
//	if (!mult){
//		std::cout << results << std::endl;
//	} else {
//		if (type == SNAKE_HEAD) {
//			results.insert(0, "FIRST PLAYER:\n");
//		} else if (type == SNAKE_SECOND_HEAD){
//			results.insert(0, "SECOND PLAYER:\n");
//		}
//		std::cout << results << std::endl;
//	}
}

void 			ncursesWindow::drawStart()
{
//	m_window->clear(sf::Color(32,178,170, 255));
//	sf::Font font;
//	font.loadFromFile("./fonts/arial.ttf");
//
//	sf::Text text;
//	text.setFont(font);
//	text.setCharacterSize(40);
//	text.setStyle(sf::Text::Bold);
//	text.setColor(sf::Color::Black);
//	text.setString(        "FOR START NEW GAME PRESS << N >>\n"
//								   "--------------------------------\n"
//								   "FOR EXIT PRESS << ESC >>\n");
//
//	sf::FloatRect textRect = text.getLocalBounds();
//	text.setOrigin(textRect.left + textRect.width/2.0f,
//				   textRect.top  + textRect.height/2.0f);
//	text.setPosition(sf::Vector2f(m_width/2.0f,m_height/2.0f));
//
//	m_window->draw(text);
//	m_window->display();
}

void 			ncursesWindow::drawGameOver(std::string const & finishMessage)
{
//	m_window->clear(sf::Color(0, 0, 250, 255));
//	sf::Font font;
//	font.loadFromFile("./fonts/arial.ttf");
//
//	sf::Text text;
//	text.setFont(font);
//	text.setCharacterSize(40);
//	text.setStyle(sf::Text::Bold);
//	text.setColor(sf::Color::White);
//	text.setString(finishMessage.c_str());
//
//	sf::FloatRect textRect = text.getLocalBounds();
//	text.setOrigin(textRect.left + textRect.width/2.0f,
//				   textRect.top  + textRect.height/2.0f);
//	text.setPosition(sf::Vector2f(m_width/2.0f,m_height/2.0f));
//
//	m_window->draw(text);
//	m_window->display();
//	std::cout << finishMessage << std::endl;
	(void)finishMessage;
}



ncursesWindow		*createWindow(int width, int height)
{
	return new ncursesWindow(width, height);
}

void			deleteWindow(ncursesWindow *ncursesWindow)
{
	delete ncursesWindow;
}
