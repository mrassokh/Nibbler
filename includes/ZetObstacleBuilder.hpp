/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZetObstacleBuilder.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 11:15:26 by mrassokh          #+#    #+#             */
/*   Updated: 2018/06/10 11:15:27 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZET_OBSTACLE_BUILDER_HPP
# define ZET_OBSTACLE_BUILDER_HPP
# include "ObstacleBuilder.hpp"

class ZetObstacleBuilder : public ObstacleBuilder {
public:
	ZetObstacleBuilder();
	virtual ~ZetObstacleBuilder();

	virtual int 		checkObstacleToGameField(GameField *gamefield, int const & x, int const & y);
	virtual void 		setFirstX(int const & x);
	virtual void 		setFirstY(int const & y);
	virtual void 		setSize();
	virtual void 		setObstacleSegments(GameField *gamefield, int const & x, int const & y);
};

#endif
