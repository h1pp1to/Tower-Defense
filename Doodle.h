#pragma once

#include <SDL2\SDL.h>
#include "Visualise.h"
class Doodle
{
private:
	SDL_Color Color;

public:
	Doodle::Doodle(){}
	Doodle::~Doodle(){}

	void SetColor(int red, int blue, int green)
	{
		Color.a = red;
		Color.b = blue;
		Color.g = green;
	}

	void DrawRect(int x, int y, int w, int h)
	{
		SDL_Rect Rect = { x, y, w, h };
		SDL_FillRect(Visualize::Instance().m_Surface, &Rect,
			SDL_MapRGB(Visualize::Instance().m_Surface->format, Color.a, Color.b, Color.g));
	}

	void DrawRect(SDL_Rect Rect)
	{
		SDL_FillRect(Visualize::Instance().m_Surface, &Rect, 
			SDL_MapRGB(Visualize::Instance().m_Surface->format, Color.a, Color.b, Color.g));
	}

	void DrawRect(SDL_Rect Rect, SDL_Color Color)
	{
		SDL_FillRect(Visualize::Instance().m_Surface, &Rect, 
			SDL_MapRGB(Visualize::Instance().m_Surface->format, Color.a, Color.b, Color.g));
	}
};