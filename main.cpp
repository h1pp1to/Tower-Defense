
#include "TowerUpdateMenu.h"
#include "Visualise.h"
#include "Timer.h"
#undef main

int main()
{
	Visualize::Instance().Init();

	TowerUpdateMenu m_TowerMenu;
	m_TowerMenu.Init();

	bool IsRunning = true;

	SDL_Event m_Event;
	while (IsRunning)
	{

		while (SDL_PollEvent(&m_Event))
		{
			switch (m_Event.type)
			{
				case SDL_QUIT:
				{
					IsRunning = false;
					break;
				}
				case SDL_KEYDOWN:
				{
					if (m_Event.key.keysym.sym && SDLK_ESCAPE)
						IsRunning = false;
					break;
				}
				case SDL_MOUSEBUTTONDOWN:
				{
					m_TowerMenu.HandleButtons(m_Event.button.x, m_Event.button.y);
					Tower::Instance().DEBUG();
					break;
				}
				default: break;
			}
		}

		m_TowerMenu.DrawTowerMenu();

		Visualize::Instance().UpdateSurface();
		Visualize::Instance().UpdateWindow();

	}

	return 0;
}

