/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FoodProcessor.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 13:17:34 by mrassokh          #+#    #+#             */
/*   Updated: 2018/06/01 13:17:35 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOOD_PROCESSOR_HPP
# define FOOD_PROCESSOR_HPP
#include "FoodSegment.hpp"
#include "GameField.hpp"
#include <vector>

class FoodProcessor
{
public:
	static FoodProcessor	&Instance();

	void 					initFoodList(std::shared_ptr<std::vector<std::shared_ptr<FoodSegment>>> foodList,
										GameField *gameField);
	void 					timeUpdateFoodList(std::shared_ptr<std::vector<std::shared_ptr<FoodSegment>>> foodList,
										GameField *gameField);
	void 					createFoodSegment(std::shared_ptr<std::vector<std::shared_ptr<FoodSegment>>> foodList,
										GameField *gameField);

private:
	FoodProcessor();
	FoodProcessor(FoodProcessor const & rhs) = delete;
	FoodProcessor & operator = (FoodProcessor const & rhs) = delete;
	virtual ~FoodProcessor();
};

#endif
