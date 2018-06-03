/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SnakeSegment.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:49:32 by mrassokh          #+#    #+#             */
/*   Updated: 2018/05/29 14:49:35 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SnakeSegment.hpp"

SnakeSegment::SnakeSegment() : SquareSegment()
{
	this->setType(SNAKE_SEGMENT);
	this->setPrevGridX(-1);
	this->setPrevGridY(-1);
}
SnakeSegment::SnakeSegment(const int & x, const int & y, const int & prev_x,
	 					const int & prev_y) : SquareSegment(x,y,SNAKE_SEGMENT),
												m_prevGridX(prev_x),
												m_prevGridY(prev_y)
{

}

SnakeSegment::SnakeSegment(SnakeSegment const & rhs) : SquareSegment(rhs)
{
	setPrevGridX(rhs.getPrevGridX());
	setPrevGridY(rhs.getPrevGridY());
}

SnakeSegment & SnakeSegment::operator = (SnakeSegment const & rhs)
{
	if (this == &rhs)
		return *this;
	(SquareSegment&)(*this) = rhs;
	setPrevGridX(rhs.getPrevGridX());
	setPrevGridY(rhs.getPrevGridY());

	return *this;
}

SnakeSegment::~SnakeSegment()
{

}

int 		SnakeSegment::getPrevGridX() const
{
	return m_prevGridX;
}
int 		SnakeSegment::getPrevGridY() const
{
	return m_prevGridY;
}
void 		SnakeSegment::setPrevGridX(const int & x)
{
	m_prevGridX = x;
}
void 		SnakeSegment::setPrevGridY(const int & y)
{
	m_prevGridY = y;
}
