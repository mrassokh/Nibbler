/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FoodSegment.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 10:59:49 by mrassokh          #+#    #+#             */
/*   Updated: 2018/05/31 10:59:51 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FoodSegment.hpp"
#include <ctime>
FoodSegment::FoodSegment()
{
	this->setType(FOOD);
}

FoodSegment::FoodSegment(const int & x, const int & y)
									: SquareSegment(x, y, FOOD),
										m_bornTime(static_cast<double>(clock() / CLOCKS_PER_SEC))
{
	//srand(time(NULL));
	m_liveTime = 0.5 + (rand() % 10) * 0.10;
}

FoodSegment::FoodSegment(FoodSegment const & rhs)
{
	m_bornTime = rhs.getBornTime();
}

FoodSegment & FoodSegment::operator = (FoodSegment const & rhs)
{
	if (this != &rhs)
		m_bornTime = rhs.getBornTime();
	return *this;
}

FoodSegment::~FoodSegment()
{

}
double 			FoodSegment::getBornTime() const
{
	return m_bornTime;
}

double 			FoodSegment::getLiveTime() const
{
	return m_liveTime;
}
