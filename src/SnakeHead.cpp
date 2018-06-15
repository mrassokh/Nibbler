/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SnakeHead.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:03:30 by mrassokh          #+#    #+#             */
/*   Updated: 2018/05/29 16:03:31 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/SnakeHead.hpp"

SnakeHead::SnakeHead()
{
	this->setType(SNAKE_HEAD);
}

SnakeHead::SnakeHead(const int & x, const int & y, const int & prev_x,
	 					const int & prev_y, const int & dirX, const int & dirY)
						: SnakeSegment(x, y, prev_x, prev_y),
						m_dirX(dirX),
						m_dirY(dirY),
						m_delta(0),
						m_rotateCondition(1)

{
	this->setType(SNAKE_HEAD);
}

SnakeHead::SnakeHead(SnakeHead const & rhs) : SnakeSegment(rhs)
{
	setDirX(rhs.getDirX());
	setDirY(rhs.getDirY());
}

SnakeHead & SnakeHead::operator = (SnakeHead const & rhs)
{
	if (this == &rhs)
		return *this;

	(SnakeHead&)(*this) = rhs;
	setDirX(rhs.getDirX());
	setDirY(rhs.getDirY());

	return *this;
}

SnakeHead::~SnakeHead()
{

}

int 		SnakeHead::getDirX() const
{
	return m_dirX;
}
int 		SnakeHead::getDirY() const
{
	return m_dirY;
}
void 		SnakeHead::setDirX(const int & x)
{
	m_dirX = x;
}
void 		SnakeHead::setDirY(const int & y)
{
	m_dirY = y;
}

int 		SnakeHead::getRotationCondition() const
{
	return m_rotateCondition;
}

void 		SnakeHead::setDelta(const float & delta)
{
	m_delta = delta;
}

void 		SnakeHead::setRotationCondition(const int & condition)
{
	m_rotateCondition = condition;
}


float 		SnakeHead::getDelta() const
{
	return m_delta;
}
