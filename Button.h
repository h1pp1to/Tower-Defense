#pragma once
#include <SDL2\SDL.h>


class Button
{
private:
	SDL_Rect ButtonRect;
public:
	Button(int x, int y, int w, int h);
	Button(SDL_Rect rectangle);
	Button();
	~Button();

	void CreateButton(SDL_Rect newButton);
	void CreateButton(int x, int y, int w, int h);
	bool IsClicked(int xMouse, int yMouse);

	SDL_Rect GetRect();

};

