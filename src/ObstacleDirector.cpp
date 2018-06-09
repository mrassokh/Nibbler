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

int			ObstacleDirector::constructObstacle(GameField *gamefield)
{
	if (!m_obstacleBuilder->checkObstacleToGameField(gamefield))
		return (0);
	m_obstacleBuilder->createNewObstacle();
	m_obstacleBuilder->setFirstX();
	m_obstacleBuilder->setFirstY();
	m_obstacleBuilder->setSize();
	m_obstacleBuilder->setObstacleSegments();
	return (1);
}

Obstacle 	ObstacleDirector::getObstacle()
{
	return m_obstacleBuilder->getReadyObstacle();
}
