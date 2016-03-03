#include "Button.h"


Button::Button(int x, int y , int w , int h)
{
	CreateButton(x, y, w, h);
}

Button::Button(SDL_Rect rectangle)
{
	CreateButton(rectangle);
}

Button::Button ()
{
}

Button::~Button()
{
}

void Button::CreateButton(SDL_Rect newButton)
{
	ButtonRect = newButton;
}

void Button::CreateButton(int x, int y, int w, int h)
{
	ButtonRect.x = x;
	ButtonRect.y = y;
	ButtonRect.w = w;
	ButtonRect.h = h;
}

bool Button::IsClicked(int xMouse, int yMouse)
{
	return (xMouse > ButtonRect.x && xMouse < (ButtonRect.x + ButtonRect.w)) &&
		(yMouse >ButtonRect.y && yMouse < (ButtonRect.y + ButtonRect.h));
}

SDL_Rect Button::GetRect()
{
	return ButtonRect;
}