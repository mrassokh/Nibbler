/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Render.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 13:50:46 by mrassokh          #+#    #+#             */
/*   Updated: 2018/06/01 13:50:48 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_HPP
# define RENDER_HPP
#include "FoodSegment.hpp"
#include "Snake.hpp"
#include "Obstacle.hpp"
#include "IWindow.hpp"
#include <vector>

class Render
{
public:
	static Render	&Instance();

	void 			drawSnake(Snake &snake, IWindow *window) const;
	void 			drawFood(std::shared_ptr<std::vector<std::shared_ptr<FoodSegment>>> foodList,
							IWindow *window) const;
	void 			drawObstacles(std::shared_ptr<std::vector<std::shared_ptr<Obstacle>>> obstacleList,
							IWindow *window) const;
private:
	Render();
	Render(Render const & rhs) = delete;
	Render & operator = (Render const & rhs) = delete;
	virtual ~Render();
};

#endif
