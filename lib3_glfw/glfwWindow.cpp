/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glfwWindow.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 14:21:37 by rmalkevy          #+#    #+#             */
/*   Updated: 2018/06/30 14:21:39 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/glfwWindow.hpp"

glfwWindow::glfwWindow() : m_width(0), m_height(0)
{}

glfwWindow::glfwWindow(int width, int height) :
		m_width((const GLuint)width * SQUARE_SIZE),
		m_height((const GLuint)height * SQUARE_SIZE)
{
}

glfwWindow::~glfwWindow()
{}


int g_keycode = 0;

static void     key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
		g_keycode = key;
	}

	if (action == GLFW_PRESS)
		g_keycode = key;
	scancode = 0;
	mods = 0;
}

static void glfwError(int id, const char* description)
{
	std::cout << description << "id " << id << std::endl;
}

void 					glfwWindow::init()
{
	glfwSetErrorCallback(&glfwError);

	if (!glfwInit()) {
		return ;
	}

	// Set all the required options for GLFW
//	glfwWindowHint(GLFW_SAMPLES, 4);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow* window = glfwCreateWindow(m_width, m_height, "Nibler GLFW", nullptr, nullptr);
	if (window == nullptr) {
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);

	// Setup our viewport to be the entire size of the window
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);

	// Change to the projection matrix, reset the matrix and set up orthagonal projection (i.e. 2D)
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, height, 0, 0, 1); // Paramters: left, right, bottom, top, near, far

	// ----- OpenGL settings -----

//	glfwSwapInterval(1); 		// Lock to vertical sync of monitor (normally 60Hz, so 60fps)

	glEnable(GL_SMOOTH);		// Enable (gouraud) shading

	glDisable(GL_DEPTH_TEST); 	// Disable depth testing
	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_BLEND);		// Enable blending (used for alpha) and blending function to use
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glLineWidth(5.0f);		// Set a 'chunky' line width

	glEnable(GL_LINE_SMOOTH);	// Enable anti-aliasing on lines

	glPointSize(5.0f);		// Set a 'chunky' point size

	glEnable(GL_POINT_SMOOTH);	// Enable anti-aliasing on points

	m_window = window;
}

void            reset_viewport(float r, float g, float b)
{
	glClearColor(r, g, b, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Reset the matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void 					glfwWindow::startCycl()
{
	reset_viewport(0.9f, 0.6f, 0.3f);
}

void 					glfwWindow::endCycl()
{
	glFlush();
	// Swap the screen buffers
	glfwSwapBuffers(m_window);
}

void 					glfwWindow::quit(std::string const & finishMessage)
{
	if (m_window)
		glfwDestroyWindow(m_window);
	if (glfwWindowShouldClose(m_window))
		glfwTerminate();
	(void)finishMessage;
}

EVENTS 			glfwWindow::getEvent()
{
	g_keycode = 0;
//	int pollEvent = 1;
//
//	while (pollEvent){
		glfwPollEvents();
		//if (g_keycode > 0) std::cout << g_keycode << std::endl;
		if (g_keycode == GLFW_KEY_ESCAPE)
			return EXIT;
		else {
			return handleKeyDown();
		}
//	}
//	return DEFAULT;
}

EVENTS 			glfwWindow::handleKeyDown() const
{
	switch (g_keycode) {
		case GLFW_KEY_LEFT:		return LEFT_FIRST;
		case GLFW_KEY_Q:		return LEFT_SECOND;
		case GLFW_KEY_RIGHT:	return RIGHT_FIRST;
		case GLFW_KEY_W:		return RIGHT_SECOND;
		case GLFW_KEY_A:		return CHANGE_TO_SDL_WIN;
		case GLFW_KEY_S:		return CHANGE_TO_SFML_WIN;
		case GLFW_KEY_D:		return CHANGE_TO_GLFW_WIN;
		case GLFW_KEY_N:		return NEW_GAME;
		default:				return DEFAULT;
	}
}

//void		glfwWindow::drawCell(int x, int y, int width, int height)
//{
//	glBegin(GL_QUADS);
//	glVertex2f((GLfloat)x, (GLfloat)y);
//	glVertex2f((GLfloat)x + width, (GLfloat)y);
//	glVertex2f((GLfloat)x + width, (GLfloat)y + height);
//	glVertex2f((GLfloat)x, (GLfloat)y + height);
//	glEnd();
//}

void 			glfwWindow::drawSquare(int x, int y, eType type)
{
	if (type == FOOD){
		glColor3ub(165, 42, 42);
	} else if (type == SNAKE_HEAD) {
		glColor3ub(242, 0, 42);
	} else if (type == SNAKE_SECOND_HEAD) {
		glColor3ub(42, 0, 242);
	} else if (type == OBSTACLE) {
		glColor3ub(105, 105, 105);
	}  else  {
		glColor3ub(255,222,173);
	}
//	drawCell(x * SQUARE_SIZE, y * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE);
	x = x * SQUARE_SIZE * 2;
	y = y * SQUARE_SIZE * 2;
	glRecti(x, y, x + SQUARE_SIZE * 2, y + SQUARE_SIZE * 2);
}


void            draw_text(float x, float y, std::string str, void *font)
{

	int     len;
	int     i;

	glRasterPos2f(x, y);
	len = str.length();
	i = 0;
	while (i < len)
	{
		glutBitmapCharacter(font, str[i]);
		i++;
	}
}

void 			glfwWindow::drawScore(int score, int velocity, eType type, int mult)
{
	std::string scoreStr("Score " +std::to_string(score));
	std::string velocityStr("Velocity " +std::to_string(velocity));

	if (!mult){
		draw_text(15, 20, scoreStr, TEXT_FONT);
		draw_text(15, 50, velocityStr, TEXT_FONT);
	} else {
		if (type == SNAKE_HEAD) {
			draw_text(15, 20, "FIRST PLAYER:", TEXT_FONT);
			draw_text(15, 40, scoreStr, TEXT_FONT);
			draw_text(15, 60, velocityStr, TEXT_FONT);
		} else if (type == SNAKE_SECOND_HEAD){
			draw_text(15, 100, "SECOND PLAYER:\n", TEXT_FONT);
			draw_text(15, 120, scoreStr, TEXT_FONT);
			draw_text(15, 140, velocityStr, TEXT_FONT);
		}
	}

}

void 			glfwWindow::drawStart()
{
	reset_viewport(0.125f, 0.698f, 0.666f);

	draw_text(m_width - 200, m_height, "To start game press <<N>>", TEXT_FONT);

	glfwSwapBuffers(m_window);
}

void 			glfwWindow::drawGameOver(std::string const & finishMessage)
{
	reset_viewport(0.125f, 0.698f, 0.666f);

	draw_text(m_width - 200, m_height - 20, "GAME OVER !!!", TEXT_FONT);
	draw_text(m_width - 200, m_height + 20, "To start new game press <<N>>", TEXT_FONT);

	(void)finishMessage;
	glfwSwapBuffers(m_window);
}



glfwWindow		*createWindow(int width, int height)
{
	return new glfwWindow(width, height);
}

void			deleteWindow(glfwWindow *glfwWindow)
{
	delete glfwWindow;
}
