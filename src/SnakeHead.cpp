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
	 					const int & prev_y, const int & dirX, const int & dirY, eType type)
						: SnakeSegment(x, y, prev_x, prev_y),
						m_dirX(dirX),
						m_dirY(dirY),
						m_delta(0),
						m_leftRotateCondition(1),
						m_rightRotateCondition(1),
						m_finish(0)
{
	this->setType(type);
}

SnakeHead::SnakeHead(SnakeHead const & rhs) : SnakeSegment(rhs)
{
	setDirX(rhs.getDirX());
	setDirY(rhs.getDirY());
	setDelta(rhs.getDelta());
	setLeftRotationCondition(rhs.getLeftRotationCondition());
	setRightRotationCondition(rhs.getRightRotationCondition());
	setFinish(rhs.getFinish());
	setFinishMessage(rhs.getFinishMessage());
}

SnakeHead & SnakeHead::operator = (SnakeHead const & rhs)
{
	if (this == &rhs)
		return *this;

	setDirX(rhs.getDirX());
	setDirY(rhs.getDirY());
	setDelta(rhs.getDelta());
	setLeftRotationCondition(rhs.getLeftRotationCondition());
	setRightRotationCondition(rhs.getRightRotationCondition());
	setFinish(rhs.getFinish());
	setFinishMessage(rhs.getFinishMessage());

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

int 		SnakeHead::getLeftRotationCondition() const
{
	return m_leftRotateCondition;
}

int 		SnakeHead::getRightRotationCondition() const
{
	return m_rightRotateCondition;
}

int			SnakeHead::getFinish() const
{
	return m_finish;
}

std::string SnakeHead::getFinishMessage() const
{
	return m_finishMessage;
}

float 		SnakeHead::getDelta() const
{
	return m_delta;
}

void 		SnakeHead::setDirY(const int & y)
{
	m_dirY = y;
}
void 		SnakeHead::setDirX(const int & x)
{
	m_dirX = x;
}
void 		SnakeHead::setDelta(const float & delta)
{
	m_delta = delta;
}

void 		SnakeHead::setLeftRotationCondition(const int & condition)
{
	m_leftRotateCondition = condition;
}

void 		SnakeHead::setRightRotationCondition(const int & condition)
{
	m_rightRotateCondition = condition;
}

void 		SnakeHead::setFinish(const int & finish)
{
	m_finish = finish;
}

void 		SnakeHead::setFinishMessage(const std::string & finishMessage)
{
	m_finishMessage =  finishMessage;
}
