/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObstacleDirector.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 11:44:48 by mrassokh          #+#    #+#             */
/*   Updated: 2018/06/03 11:44:50 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSTACLE_DIRECTOR_HPP
# define OBSTACLE_DIRECTOR_HPP

#include "ObstacleBuilder.hpp"

class ObstacleDirector {

public:
	static ObstacleDirector &Instance();

	void 					setObstacleBuilder(ObstacleBuilder *obstacleBuilder);
    int 					constructObstacle(GameField *gamefield, int const & x, int const & y);
    Obstacle 				*getObstacle();
private:
	ObstacleDirector();
	ObstacleDirector(ObstacleDirector const & rhs) = delete;
	ObstacleDirector& operator = (ObstacleDirector const & rhs) = delete;
	virtual ~ObstacleDirector();

	ObstacleBuilder  	*m_obstacleBuilder;
};

#endif
