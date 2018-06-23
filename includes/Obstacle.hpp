/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 16:06:50 by mrassokh          #+#    #+#             */
/*   Updated: 2018/06/02 16:06:51 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP
#include "SquareSegment.hpp"
#include "IWindow.hpp"
#include <vector>

class Obstacle {
public:
	Obstacle();
	Obstacle(Obstacle const & rhs);
	Obstacle operator = (Obstacle const & rhs);
	virtual ~Obstacle();

	void 											setFirstX(int const & firstX);
	void 											setFirstY(int const & firstY);
	void 											setSize(int const &size);

	int												getFirstX() const;
	int												getFirstY() const;
	int												getSize() const;

	std::shared_ptr<std::vector
			<std::shared_ptr<SquareSegment>>>		getObstacleSegments();
	void 											clearObstacleSegments();
	void 											drawObstacle(IWindow *window);


private:
	int												m_firstX;
	int												m_firstY;
	int												m_size;

	std::shared_ptr<std::vector
			<std::shared_ptr<SquareSegment>>> 		m_obstacleSegments;
};

#endif
