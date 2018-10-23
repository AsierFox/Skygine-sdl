#pragma once

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace stormengine
{
	namespace graphics
	{

#define MAX_KEYS			1024
#define MAX_MOUSE_BUTTONS	32

		class Window
		{
			const char* m_pTitle;
			int m_Width;
			int m_Height;
			bool m_Closed;
			GLFWwindow* m_pWindow;

			// TODO: Refactor to input
			// Input static variables
			bool m_sKeys[MAX_KEYS];
			bool m_sMouseButtons[MAX_MOUSE_BUTTONS];
			double m_sMouseX;
			double m_sMouseY;
		public:
			Window(const char* title, int width, int height);
			~Window();
			void clear() const;
			void update();

			int getWidth() const;
			void setWidth(int width);
			int getHeight() const;
			void setHeight(int height);
			bool isClosed() const;

			bool isKeyPressed(unsigned int keycode) const;
			bool isMouseButtonPressed(unsigned int button) const;
			void getMousePosition(double& x, double& y) const;
		private:
			bool init();
			static void window_resize_callback(GLFWwindow* window, int width, int height);
			static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		};

	}
}
