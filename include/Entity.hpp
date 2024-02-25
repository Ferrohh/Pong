#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Math.hpp"

class Entity
{
public:
	Entity(Vector2f p_pos, SDL_Texture* p_tex, int p_w, int p_h);
	Entity(Vector2f p_pos, int p_w, int p_h);
	Vector2f& getPos();
	SDL_Texture* getTex();
	SDL_Rect getCurrentFrame();

	void setPos(float x, float y);
protected:
	Vector2f pos;
	SDL_Rect currentFrame;
	SDL_Texture* tex;
};