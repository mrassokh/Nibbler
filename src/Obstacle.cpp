/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 16:07:30 by mrassokh          #+#    #+#             */
/*   Updated: 2018/06/02 16:07:32 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Obstacle.hpp"

Obstacle::Obstacle()
{
	m_obstacleSegments = std::shared_ptr<std::vector<std::shared_ptr<SquareSegment>>>(new std::vector<std::shared_ptr<SquareSegment>>);
}

Obstacle::Obstacle(Obstacle const & rhs)
{
	setFirstX(rhs.getFirstX());
	setFirstY(rhs.getFirstY());
	setSize(rhs.getSize());

	auto obs = getObstacleSegments();
	auto it = (const_cast<Obstacle &>(rhs)).getObstacleSegments()->begin();
	while (it != (const_cast<Obstacle &>(rhs)).getObstacleSegments()->end())
	{
		std::shared_ptr<SquareSegment> newSegment = std::shared_ptr<SquareSegment>(new SquareSegment(*(std::dynamic_pointer_cast<SquareSegment>(*it))));
		obs->push_back(newSegment);
		it++;
	}
}

Obstacle Obstacle::operator = (Obstacle const & rhs)
{
	if (this == &rhs)
		return *this;
	clearObstacleSegments();

	setFirstX(rhs.getFirstX());
	setFirstY(rhs.getFirstY());
	setSize(rhs.getSize());

	auto obs = getObstacleSegments();
	auto it = (const_cast<Obstacle &>(rhs)).getObstacleSegments()->begin();
	while (it != (const_cast<Obstacle &>(rhs)).getObstacleSegments()->end())
	{
		std::shared_ptr<SquareSegment> newSegment = std::shared_ptr<SquareSegment>(new SquareSegment(*(std::dynamic_pointer_cast<SquareSegment>(*it))));
		obs->push_back(newSegment);
		it++;
	}
	return *this;
}

Obstacle::~Obstacle()
{
	clearObstacleSegments();
}

void 											Obstacle::clearObstacleSegments()
{
	// auto it = getObstacleSegments()->begin();
	// while (it != getObstacleSegments()->end())
	// {
	// //	delete std::dynamic_pointer_cast<SquareSegment>(*it);
	// 	it++;
	// }
	getObstacleSegments()->clear();
}

void 											Obstacle::setFirstX(int const & firstX)
{
	if (firstX < 0){
		m_firstX = 0;
		return ;
	}
	m_firstX = firstX;
}
void 											Obstacle::setFirstY(int const & firstY)
{
	if (firstY < 0){
		m_firstY = 0;
		return ;
	}
	m_firstY = firstY;
}
void 											Obstacle::setSize(int const &size)
{
	if (size < 0){
		m_size = 0;
		return ;
	}
	m_size = size;
}

int												Obstacle::getFirstX() const
{
	return m_firstX;
}
int												Obstacle::getFirstY() const
{
	return m_firstY;
}
int												Obstacle::getSize() const
{
	return m_size;
}

std::shared_ptr<std::vector
		<std::shared_ptr<SquareSegment>>>		Obstacle::getObstacleSegments()
{
	return m_obstacleSegments;
}
