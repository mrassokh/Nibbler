/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CustomExeptions.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 17:26:01 by mrassokh          #+#    #+#             */
/*   Updated: 2018/05/31 17:26:03 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_EXCEPTIONS
# define CUSTOM_EXCEPTIONS

#include <iostream>
#include <exception>

class CustomExeption : public std::exception
{
public:

    CustomExeption();
    CustomExeption(std::string Error);
    CustomExeption(const CustomExeption& rhs);
	CustomExeption & operator = (CustomExeption const & rhs);
    virtual ~CustomExeption();

    virtual const char* what() const throw();
	std::string 		getError() const;
private:
    std::string 		m_Error;
};
#endif
