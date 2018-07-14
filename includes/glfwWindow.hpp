/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxWindow.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 14:21:37 by rmalkevy          #+#    #+#             */
/*   Updated: 2018/06/30 14:21:39 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NIBLER_NCURSESWINDOW_HPP
#define NIBLER_NCURSESWINDOW_HPP

# include "IWindow.hpp"
# define SQUARE_SIZE 40

# include "../lib3_glfw/glfw-3.2.1/include/GLFW/glfw3.h"
# include <GLUT/glut.h>

//# define TEXT_FONT      GLUT_STROKE_ROMAN
# define TEXT_FONT      GLUT_BITMAP_TIMES_ROMAN_24

class glfwWindow : public IWindow
{
public:
	glfwWindow(int width, int height);
	virtual ~glfwWindow();

	virtual EVENTS			getEvent();
	virtual void 			drawSquare(int x, int y, eType type);
	virtual void 			drawScore(int score, int velocity, eType type, int mult);
	virtual void 			drawStart();
	virtual void 			drawGameOver(std::string const & finishMessage);
	virtual void 			startCycl();
	virtual void 			endCycl();
	virtual void 			init();

	EVENTS 					handleKeyDown() const;
private:
	glfwWindow();
	GLFWwindow				*m_window;
	const GLuint 			m_width;
	const GLuint			m_height;
};

extern "C" {
	glfwWindow		*createWindow(int width, int height);
	void 			deleteWindow(glfwWindow *glfwWindow);
}

#endif //NIBLER_NCURSESWINDOW_HPP
