#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>
#include <vector>

#include "RenderWindow.hpp"
#include "Constants.h"


int main(int argc, char* argv[])
{
    // Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;

    // initialize SDL image
	if (!(IMG_Init(IMG_INIT_PNG)))
		std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;

    // make a window
	RenderWindow window("Melon Maker", WIDTH, HEIGHT);
	
    // make the game loop
	bool gameRunning = true; // manage game loop
	SDL_Event event; // manage events

	SDL_Texture* ball_texture = window.loadTexture("../res/gfx/Ball.png");
	SDL_Texture* player_texture = window.loadTexture("../res/gfx/Player.png");
	
	// 0 --> ball
	// 1 --> player
	// 2 --> enemy
	Ball ball = Ball(Vector2f(WIDTH/2 - 32, HEIGHT/2 - 32), ball_texture, 16, 16);

	std::vector<Player> players = {
		Player(Vector2f(WIDTH/50 - 8, HEIGHT/2 - 96), player_texture, 8, 96),
		Player(Vector2f(WIDTH - WIDTH/50 - 8, HEIGHT/2 - 96), player_texture, 8, 96)
	};

	Player* player = &players[0];
	Player* enemy = &players[1];

	while (gameRunning)
	{
		// get our controls and events
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				gameRunning = false;
				break;

			case SDL_KEYDOWN:
				switch(event.key.keysym.sym) {
					case SDLK_s:
						player->moveDown();
						break;
					case SDLK_DOWN:
						enemy->moveDown();
						break;
					case SDLK_w:
						player->moveUp();
						break;
					case SDLK_UP:
						enemy->moveUp();
						break;
				}
				
				break;
			}
		}
		ball.move(players);
		window.clear();
		window.render(ball);
		for(Player a : players) {
			window.render(a);
		}
		window.display();
	}

	// close window
	window.cleanUp();
	SDL_Quit();

	return 0;
}