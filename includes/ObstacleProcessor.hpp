/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObstacleProcessor.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:10:27 by mrassokh          #+#    #+#             */
/*   Updated: 2018/06/09 11:10:29 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSTACLE_PROCESSOR_HPP
# define OBSTACLE_PROCESSOR_HPP
#include "ObstacleDirector.hpp"
#include "DotObstacleBuilder.hpp"
#include  "ZetObstacleBuilder.hpp"
#include "LObstacleBuilder.hpp"
#include "GameField.hpp"
#include <vector>
#include <array>

class ObstacleProcessor
{
public:
	static ObstacleProcessor			&Instance();

	void 								initObstacleList(std::shared_ptr<std::vector<std::shared_ptr<Obstacle>>> obstacleList,
											GameField *gameField);
	void 								createObstacle(std::shared_ptr<std::vector<std::shared_ptr<Obstacle>>> obstacleList,
											GameField *gameField);

private:
	ObstacleProcessor();
	ObstacleProcessor(ObstacleProcessor const & rhs) = delete;
	ObstacleProcessor & operator = (ObstacleProcessor const & rhs) = delete;
	virtual ~ObstacleProcessor();

	ObstacleDirector						*m_obstacleDirector;
	DotObstacleBuilder	 					*m_dotObstacleBuilder;
	ZetObstacleBuilder						*m_zetObstacleBuilder;
	LObstacleBuilder						*m_lObstacleBuilder;

	std::array<ObstacleBuilder *, 3>		m_builders;
};
#endif
