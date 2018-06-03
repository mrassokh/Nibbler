/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObstacleBuilder.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 17:31:17 by mrassokh          #+#    #+#             */
/*   Updated: 2018/06/02 17:31:19 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ObstacleBuilder.hpp"

ObstacleBuilder::ObstacleBuilder()
{

}

ObstacleBuilder::ObstacleBuilder(int const & x, int const & y) : m_X(x), m_Y(y)
{

}

ObstacleBuilder::ObstacleBuilder(ObstacleBuilder const & rhs)
{
	m_X = rhs.getX();
	m_Y = rhs.getY();
	if (rhs.getObstacle())
	{
		m_obstacle = new Obstacle(*(rhs.getObstacle()));
	}
}

ObstacleBuilder& ObstacleBuilder::operator = (ObstacleBuilder const & rhs)
{
	if (this == &rhs)
		return *this;

	m_X = rhs.getX();
	m_Y = rhs.getY();
	if (rhs.getObstacle())
	{
		m_obstacle = new Obstacle(*(rhs.getObstacle()));
	}
	return *this;
}

ObstacleBuilder::~ObstacleBuilder()
{
	if (m_obstacle)
		delete m_obstacle;
}

void 		ObstacleBuilder::createNewObstacle()
{
	m_obstacle = new Obstacle();
}

Obstacle	ObstacleBuilder::getReadyObstacle()
{
	return 	*m_obstacle;
}

int			ObstacleBuilder::getX() const
{
	return m_X;
}

int			ObstacleBuilder::getY() const
{
	return m_Y;
}

Obstacle 	*ObstacleBuilder::getObstacle() const
{
	return m_obstacle;
}
