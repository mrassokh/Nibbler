/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 15:40:21 by mrassokh          #+#    #+#             */
/*   Updated: 2018/06/16 15:40:22 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/nibbler.hpp"
#include "../includes/CustomExeptions.hpp"
#include "../includes/InputChecker.hpp"


int main(int ac, char **av)
{
	InputChecker *checker = InputChecker::getInstance();

	try{
		checker->checkAndStoreInput(ac, av);
	} catch (std::exception& e)	{
		std::cerr << e.what() << std::endl;
		return 0;
	}

	Nibbler::Instance(checker->getWidth(), checker->getHeight(),
						checker->getMultMode()).processing();
	return 0;
}
