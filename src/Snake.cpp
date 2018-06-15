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

Snake::Snake() : m_eating(0), m_score(0)
{
	m_snake = std::shared_ptr<std::list<std::shared_ptr<SquareSegment>>>(new std::list<std::shared_ptr<SquareSegment>>);
}

Snake::Snake(Snake const & rhs)
{
	(void)rhs;
}

Snake & Snake::operator = (Snake const & rhs)
{
	(void)rhs;
	return *this;
}

Snake::~Snake()
{

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
