/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LObstacleBuilder.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 12:11:44 by mrassokh          #+#    #+#             */
/*   Updated: 2018/06/10 12:11:45 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef L_OBSTACLE_BUILDER_HPP
# define L_OBSTACLE_BUILDER_HPP
# include "ObstacleBuilder.hpp"

class LObstacleBuilder : public ObstacleBuilder {
public:
	LObstacleBuilder();
	virtual ~LObstacleBuilder();

	virtual int 		checkObstacleToGameField(GameField *gamefield, int const & x, int const & y);
	virtual void 		setFirstX(int const & x);
	virtual void 		setFirstY(int const & y);
	virtual void 		setSize();
	virtual void 		setObstacleSegments(GameField *gamefield, int const & x, int const & y);
};

#endif
