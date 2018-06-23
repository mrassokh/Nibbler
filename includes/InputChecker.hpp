/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InputChecker.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrassokh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 17:00:29 by mrassokh          #+#    #+#             */
/*   Updated: 2018/06/10 17:00:32 by mrassokh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_CHECKER_HPP
# define INPUT_CHECKER_HPP
# include "CustomExeptions.hpp"

class InputChecker {
public:
	static InputChecker*		getInstance();
	void 						checkAndStoreInput(int ac,char **av);

	int 						getWidth();
	int							getHeight();
	int							getMultMode();

private:
	InputChecker();
	InputChecker(InputChecker const & rhs) = delete;
	InputChecker& operator = (InputChecker const & rhs) = delete;
	virtual ~InputChecker();

	static InputChecker*		m_instance;
	int							m_width;
	int							m_height;
	int							m_multMode;
};

#endif
