#include "BaseUI.h"

BaseUI::BaseUI()
{
	m_pos = Vector2D(0, 0);
}

BaseUI::BaseUI(int x, int y)
{
	m_pos = Vector2D(x, y);
}
