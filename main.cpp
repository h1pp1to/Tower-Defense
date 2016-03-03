#include <iostream>
#include "Button.h"
#include "Visualise.h"
#include <SDL2\SDL.h>
#undef main

int main()
{
	Visualize::Init();
	SDL_Event e;
	Mouse mousePos;
	Button button;
	Button button2;

	button.CreateButton(100, 100, 100, 100);
	button2.CreateButton(300, 300, 100, 100);

	Visualize::CreateColor(131, 211, 22);
	Visualize::DrawButton(button.GetRect());
	Visualize::DrawButton(button2.GetRect());

	bool isRunning = true;
	
	while (isRunning)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				isRunning = false;
			}
			if (e.type == SDL_MOUSEBUTTONDOWN)
			{
				SDL_GetMouseState(&mousePos.xMouse, &mousePos.yMouse);
				if (button.IsClicked(mousePos.xMouse, mousePos.yMouse) || button2.IsClicked(mousePos.xMouse, mousePos.yMouse))
				{
					std::cout << "You clicked me !" << std::endl;
				}
			}
		}
		Visualize::UpdateSurface();
		Visualize::UpdateWindow();
	}

	
	SDL_DestroyWindow(Visualize::m_Window);
	SDL_Quit();

	return 0;
}

