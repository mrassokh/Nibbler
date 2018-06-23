/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ObstacleBuilder.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 17:31:06 by mrassokh          #+#    #+#             */
/*   Updated: 2018/06/02 17:31:07 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSTACLE_BUILDER_HPP
# define OBSTACLE_BUILDER_HPP
# include "Obstacle.hpp"
# include "GameField.hpp"
# include "SquareSegment.hpp"

class ObstacleBuilder {
public:
	ObstacleBuilder();
	ObstacleBuilder(int const & x, int const & y);
	ObstacleBuilder(ObstacleBuilder const & rhs);
	ObstacleBuilder& operator = (ObstacleBuilder const & rhs);
	virtual ~ObstacleBuilder();

	void 				createNewObstacle();
	Obstacle			*getReadyObstacle();
	int					getX() const;
	int					getY() const;
	Obstacle 			*getObstacle() const;
	void 				setOneSegment(GameField *gamefield, int const & x, int const & y);

	virtual int 		checkObstacleToGameField(GameField *gamefield, int const & x, int const & y) = 0;
	virtual void 		setFirstX(int const & x) = 0;
	virtual void 		setFirstY(int const & y) = 0;
	virtual void 		setSize() = 0;
	virtual void 		setObstacleSegments(GameField *gamefield, int const & x, int const & y) = 0;

protected:
	Obstacle 			*m_obstacle;
	int 				m_X;
	int 				m_Y;
};

#endif
