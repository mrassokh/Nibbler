/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FoodSegment.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 10:59:29 by mrassokh          #+#    #+#             */
/*   Updated: 2018/05/31 10:59:31 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOOD_SEGMENT_HPP
# define FOOD_SEGMENT_HPP

# include "SquareSegment.hpp"
# include <ctime>
# include <cstdlib>

class FoodSegment : public SquareSegment
{
public:
	FoodSegment();
	FoodSegment(const int & x, const int & y);
	FoodSegment(FoodSegment const & rhs);
	FoodSegment & operator = (FoodSegment const & rhs);
	virtual ~FoodSegment();

	double 			getBornTime() const;
	double 			getLiveTime() const;

private:
	double			m_bornTime;
	double			m_liveTime;
};



#endif
