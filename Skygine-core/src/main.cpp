#include <iostream>

//#define TEST 1

#ifdef TEST
#include "../test/test.h"
#endif // TEST

#include "graphics/window.h"
#include "graphics/shader.h"
#include "graphics/buffer.h"
#include "graphics/indexbuffer.h"
#include "graphics/vertexarray.h"
#include "graphics/renderers/renderer2d.h"
#include "graphics/renderers/simplerenderer2d.h"
#include "graphics/renderers/renderable2d.h"

int main()
{
	using namespace stormengine;
	using namespace graphics;
	using namespace maths;

#ifdef TEST
	test::Test::test();
#else // TEST

	if (!glfwInit())
	{
		std::cout << "Failed to initialize GLFW." << std::endl;
	}

	Window window("Stormengine", 800, 600);

	Matr4 ortho = Matr4::get_orthograhic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader shader("src/graphics/shaders/basic.vert", "src/graphics/shaders/basic.frag");
	shader.enable();

	// Set vertex matrices
	shader.setUniformMatr4f("projection_matrix", ortho);
	shader.setUniformMatr4f("model_matrix", Matr4::get_translation(Vect3(4, 3, 0)));
	// Send vectors for fragment
	shader.setUniform2f("light_position", Vect2(4.0f, 1.5f));
	shader.setUniform4f("colour", Vect4(1.0f, 1.0f, 1.0f, 1.0f));

	Renderable2D sprite1(Vect3(5, 5, 0), Vect2(4, 4), Vect4(1, 0, 1, 1), shader);
	Renderable2D sprite2(Vect3(0, 0, 0), Vect2(4, 4), Vect4(1, 0, 1, 1), shader);

	SimpleRenderer2D renderer2D;

	while (!window.isClosed())
	{
		window.clear();

		// Update light position
		double mouseX, mouseY;
		window.getMousePosition(mouseX, mouseY);
		shader.setUniform2f("light_position", Vect2(
			(float) (mouseX * 16.0f / 800.0f),
			(float) (9.0f - mouseY * 9.0f / 600.0f)));

		renderer2D.submit(&sprite1);
		renderer2D.submit(&sprite2);
		renderer2D.flush();

		window.update();
	}

#endif // TEST
	return 0;
}
