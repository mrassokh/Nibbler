/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObstacleDirector.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 11:46:38 by mrassokh          #+#    #+#             */
/*   Updated: 2018/06/03 11:46:39 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ObstacleDirector.hpp"

ObstacleDirector & ObstacleDirector::Instance()
{
	static ObstacleDirector instance;
	return instance;
}

ObstacleDirector::ObstacleDirector()
{

}

ObstacleDirector::~ObstacleDirector()
{

}


void 		ObstacleDirector::setObstacleBuilder(ObstacleBuilder *obstacleBuilder)
{
	m_obstacleBuilder = obstacleBuilder;
}

int			ObstacleDirector::constructObstacle(GameField *gamefield, int const & x, int const & y)
{
	if (!m_obstacleBuilder->checkObstacleToGameField(gamefield, x, y))
		return (0);
	m_obstacleBuilder->createNewObstacle();
	m_obstacleBuilder->setFirstX(x);
	m_obstacleBuilder->setFirstY(y);
	m_obstacleBuilder->setSize();
	m_obstacleBuilder->setObstacleSegments(gamefield, x, y);
	return (1);
}

Obstacle 	*ObstacleDirector::getObstacle()
{
	return m_obstacleBuilder->getReadyObstacle();
}
