#include "simplerenderer2d.h"

namespace stormengine
{
	namespace graphics
	{

		void SimpleRenderer2D::submit(const Renderable2D* const renderable)
		{
			m_renderQueue.push_back(renderable);
		}

		void SimpleRenderer2D::flush()
		{
			while (!m_renderQueue.empty())
			{
				const Renderable2D* renderable = m_renderQueue.front();
				renderable->getVertexArray()->bind();
				renderable->getIndexBuffer()->bind();

				renderable->getShader().setUniformMatr4f("model_matrix", Matr4::get_translation(renderable->getPosition()));
				glDrawElements(GL_TRIANGLES, renderable->getIndexBuffer()->getIndexCount(), GL_UNSIGNED_SHORT, 0);

				renderable->getIndexBuffer()->unbind();
				renderable->getVertexArray()->unbind();

				m_renderQueue.pop_front();
			}
		}

	}
}
