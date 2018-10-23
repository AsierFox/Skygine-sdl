#include "window.h"

namespace stormengine
{
	namespace graphics
	{

		Window::Window(const char* title, int width, int height)
		{
			m_pTitle = title;
			m_Width = width;
			m_Height = height;

			if (!init()) {
				std::cout << "Error initializating Window." << std::endl;
			}

			// Set keys to false
			for (int i = 0; i < MAX_KEYS; i++)
			{
				m_sKeys[i] = false;
			}
			// Set mouse buttons to false
			for (int i = 0; i < MAX_MOUSE_BUTTONS; i++)
			{
				m_sMouseButtons[i] = false;
			}
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update()
		{
			// Detect OpenGL render errors
			GLenum glError = glGetError();
			if (GL_NO_ERROR != glError)
			{
				std::cout << "OpenGL ERROR: " << glError << std::endl;
			}

			// Active events
			glfwPollEvents();
			glfwSwapBuffers(m_pWindow);
		}

		int Window::getWidth() const
		{
			return m_Width;
		}

		void Window::setWidth(int width)
		{
			m_Width = width;
		}

		int Window::getHeight() const
		{
			return m_Height;
		}

		void Window::setHeight(int height)
		{
			m_Height = height;
		}

		bool Window::isClosed() const
		{
			return glfwWindowShouldClose(m_pWindow) == 1;
		}

		bool Window::isKeyPressed(unsigned int keycode) const
		{
			// TODO: Log this
			if (keycode >= MAX_KEYS) {
				return false;
			}
			return m_sKeys[keycode];
		}

		bool Window::isMouseButtonPressed(unsigned int button) const
		{
			// TODO: Log this
			if (button >= MAX_MOUSE_BUTTONS)
			{
				return false;
			}
			return m_sMouseButtons[button];
		}

		void Window::getMousePosition(double& x, double& y) const
		{
			x = m_sMouseX;
			y = m_sMouseY;
		}

		bool Window::init()
		{
			m_pWindow = glfwCreateWindow(m_Width, m_Height, m_pTitle, NULL, NULL);

			if (!m_pWindow)
			{
				std::cout << "Error creating Window." << std::endl;
				glfwTerminate();
				return false;
			}

			glfwMakeContextCurrent(m_pWindow);

			// Attach Window object to GLFW Window, so we can access custom data from callbacks
			glfwSetWindowUserPointer(m_pWindow, this);

			// Set resize callback
			glfwSetWindowSizeCallback(m_pWindow, window_resize_callback);
			// Set input callbacks
			glfwSetKeyCallback(m_pWindow, key_callback);
			glfwSetMouseButtonCallback(m_pWindow, mouse_button_callback);
			glfwSetCursorPosCallback(m_pWindow, cursor_position_callback);

			// Set clear color
			//glClearColor(.2f, .3f, .8f, 1.0f);

			// Initialize GLEW after Window context creation
			if (glewInit() != GLEW_OK)
			{
				std::cout << "Failed to initialize GLEW." << std::endl;
			}

			return true;
		}

		void Window::window_resize_callback(GLFWwindow* window, int width, int height)
		{
			Window* myWindow = (Window*) glfwGetWindowUserPointer(window);
			// Update window dimensions when resizing
			myWindow->setWidth(width);
			myWindow->setHeight(height);
			// Resize also graphics inside Window
			glViewport(0, 0, width, height);
		}

		void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window* myWindow = (Window*) glfwGetWindowUserPointer(window);
			myWindow->m_sKeys[key] = action != GLFW_RELEASE;
		}

		void Window::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
		{
			Window* myWindow = (Window*) glfwGetWindowUserPointer(window);
			myWindow->m_sMouseButtons[button] = action != GLFW_RELEASE;
		}

		void Window::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
		{
			Window* myWindow = (Window*) glfwGetWindowUserPointer(window);
			myWindow->m_sMouseX = xpos;
			myWindow->m_sMouseY = ypos;
		}

	}
}
