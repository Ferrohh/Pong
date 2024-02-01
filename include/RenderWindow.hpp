#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "Entity.hpp"
#include "Ball.hpp"
#include "Player.hpp"

#define WIDTH 800
#define HEIGHT 500

class RenderWindow 
{
public:
	RenderWindow(const char* p_title, int p_w, int p_h);
	SDL_Texture* loadTexture(const char* p_filePath);
	void cleanUp();
	void clear();
	void render(Entity& p_entity);
	void render(SDL_Texture* bg);
	void display();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};