#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

#define N_FRUIT 9

int main(int argc, char* argv[])
{
    // Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

    // initialize SDL image
	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

    // make a window
	RenderWindow window("Melon Maker", 800, 800);

    // make the game loop
	bool gameRunning = true; // manage game loop
	SDL_Event event; // manage events
	while (gameRunning)
	{
		// get our controls and events
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}
		window.clear();
		window.display();
	}

	// close window
	window.cleanUp();
	SDL_Quit();

	return 0;
}