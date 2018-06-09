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
#include "GameField.hpp"
#include <vector>

class ObstacleProcessor
{
public:
	static ObstacleProcessor	&Instance();

	void 					initObstacleList(std::shared_ptr<std::vector<std::shared_ptr<Obstacle>>> obstacleList,
										GameField *gameField);
	// void 					timeUpdateFoodList(std::shared_ptr<std::vector<std::shared_ptr<FoodSegment>>> foodList,
	// 									GameField *gameField);
	void 					createObstacle(std::shared_ptr<std::vector<std::shared_ptr<Obstacle>>> obstacleList,
										GameField *gameField);

private:
	ObstacleProcessor();
	ObstacleProcessor(ObstacleProcessor const & rhs) = delete;
	ObstacleProcessor & operator = (ObstacleProcessor const & rhs) = delete;
	virtual ~ObstacleProcessor();

	ObstacleDirector						*m_obstacleDirector;
	std::shared_ptr<DotObstacleBuilder>	 	m_dotObstacleBuilder;
};

#endif
