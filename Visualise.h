#pragma once
#include <SDL2\SDL.h>
namespace Visualize
{
	SDL_Window* m_Window = nullptr;
	SDL_Surface* m_Surface = nullptr;

	SDL_Color Color;

	void Init()
	{
		SDL_Init(SDL_INIT_VIDEO);
		m_Window = SDL_CreateWindow("TOWER DEFENSE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 680, 420, SDL_WINDOW_SHOWN);
		m_Surface = SDL_GetWindowSurface(m_Window);
	}

	void UpdateSurface()
	{
		SDL_BlitSurface(m_Surface, NULL, m_Surface, NULL);
	}

	void UpdateWindow()
	{
		SDL_UpdateWindowSurface(m_Window);
	}

	void DrawButton(SDL_Rect Rect)
	{
		SDL_FillRect(m_Surface, &Rect, SDL_MapRGB(m_Surface->format, Color.a, Color.b, Color.g));
	}

	void CreateColor(int a, int b , int g)
	{
		Color.a = a;
		Color.b = b;
		Color.g = g;
	}
}