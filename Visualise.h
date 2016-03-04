#pragma once
#include <SDL2\SDL.h>
#include "Singleton.h"

class Visualize
{
private:
	Visualize() = default;
	Visualize(const Visualize&) = delete;
	Visualize& operator=(const Visualize&) = delete;
	SDL_Window* m_Window = nullptr;
public:
	static const int WINDOW_WIDTH = 680;
	static const int WINDOW_HEIGHT = 420;
	SDL_Surface* m_Surface;

	void Init()
	{
		SDL_Init(SDL_INIT_VIDEO);
		m_Window = SDL_CreateWindow("TOWER DEFENSE",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
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

	static Visualize& Instance()
	{
		static Visualize *Instance = new Visualize;
		return *Instance;
	}
};
