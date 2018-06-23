/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputChecker.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 17:00:45 by mrassokh          #+#    #+#             */
/*   Updated: 2018/06/10 17:00:46 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InputChecker.hpp"

InputChecker*		InputChecker::m_instance = 0;

InputChecker::InputChecker()
{
	m_multMode = 0;
}

InputChecker::~InputChecker()
{

}

InputChecker*		InputChecker::getInstance()
{
	if (m_instance == nullptr)
		m_instance = new InputChecker();
	return m_instance;
}

void 				InputChecker::checkAndStoreInput(int ac,char **av)
{
	if (ac != 3 && ac != 4) {
		throw CustomExeption("Wrong number of input arguments!!!\n Usage: ./nibbler (int)width (int)height (int)mult(optional)");
	} else {
		try {
			m_width = std::stoi(av[1]);
		} catch (std::exception& e) {
			throw CustomExeption("input width argument cannot be converted to int");
		}

		try {
			m_height = std::stoi(av[2]);
		} catch (std::exception& e) {
			throw CustomExeption("input height argument cannot be converted to int");
		}
	}
		if (m_width < 10 || m_height < 10)
			throw CustomExeption("Minimal size for width and height is 10!!!\n");
	if (ac == 4) {
		if (!strcmp(av[3], "mult"))
			m_multMode = 1;
		else
			throw CustomExeption("MultMode optional parameter should be is: mult");
	}
}

int 				InputChecker::getWidth()
{
	return m_width;
}

int					InputChecker::getHeight()
{
	return m_height;
}

int					InputChecker::getMultMode()
{
	return m_multMode;
}
