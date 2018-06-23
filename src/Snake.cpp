/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 17:51:56 by mrassokh          #+#    #+#             */
/*   Updated: 2018/05/19 17:51:58 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Snake.hpp"

Snake::Snake() : m_eating(0), m_score(0), m_nextIsNotObstacle(1)
{
	m_snake = std::shared_ptr<std::list<std::shared_ptr<SquareSegment>>>(new std::list<std::shared_ptr<SquareSegment>>);
}

Snake::Snake(Snake const & rhs)
{
	setEating(rhs.getEating());
	setScore(rhs.getScore());
	setNextIsNotObstacle(rhs.getNextIsNotObstacle());
	getSnake()->clear();

	auto snake = getSnake();
	auto it = (const_cast<Snake &>(rhs)).getSnake()->begin();
	while (it != (const_cast<Snake &>(rhs)).getSnake()->end())
	{
		std::shared_ptr<SquareSegment> newSegment = std::shared_ptr<SquareSegment>(new SquareSegment(*(std::dynamic_pointer_cast<SquareSegment>(*it))));
		snake->push_back(newSegment);
		it++;
	}
}

Snake & Snake::operator = (Snake const & rhs)
{
	if (this == &rhs){
		return *this;
	}

	setEating(rhs.getEating());
	setScore(rhs.getScore());
	setNextIsNotObstacle(rhs.getNextIsNotObstacle());
	return *this;
}

Snake::~Snake()
{
	getSnake()->clear();
}

std::shared_ptr<std::list<std::shared_ptr<SquareSegment>>>	Snake::getSnake()
{
	return m_snake;
}

int 														Snake::getEating() const
{
	return m_eating;
}

void 														Snake::setEating(int const & eating)
{
	if (eating > 0)
		m_eating = eating;
	else
		m_eating = 0;
}

int 														Snake::getScore() const
{
	return m_score;
}

void 														Snake::setScore(int const & score)
{
	m_score = score;
}


int 														Snake::getNextIsNotObstacle() const
{
	return 	m_nextIsNotObstacle;
}

void 														Snake::setNextIsNotObstacle(int const & nextIsNotObstacle)
{
	m_nextIsNotObstacle = nextIsNotObstacle;
}
