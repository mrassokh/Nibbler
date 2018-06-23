/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomExeptions.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:35:07 by mrassokh          #+#    #+#             */
/*   Updated: 2018/05/31 17:35:09 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CustomExeptions.hpp"

CustomExeption::CustomExeption()
{
	m_Error = "Some strange error. God bless you!";
}

CustomExeption::CustomExeption(std::string Error)
{
	m_Error = Error;
}

CustomExeption::CustomExeption(const CustomExeption& rhs)
{
	m_Error = rhs.getError();
}

CustomExeption & CustomExeption::operator = (CustomExeption const & rhs)
{
	if (this != &rhs)
		m_Error = rhs.getError();
	return *this;
}

CustomExeption::~CustomExeption()
{

}

std::string 		CustomExeption::getError() const
{
	return m_Error;
}

const char* 		CustomExeption::what() const throw()
{
	return this->m_Error.c_str();
}
