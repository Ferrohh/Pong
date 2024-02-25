#include "Entity.hpp"

Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex, int p_w, int p_h)
:pos(p_pos), tex(p_tex)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = p_w;
	currentFrame.h = p_h;
}

Entity::Entity(Vector2f p_pos, int p_w, int p_h)
: pos(p_pos)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = p_w;
	currentFrame.h = p_h;
}

Vector2f& Entity::getPos() {
	return pos;
}

SDL_Texture* Entity::getTex()
{
	return tex;
}

SDL_Rect Entity::getCurrentFrame()
{
	return currentFrame;
}

void Entity::setPos(float x, float y) {
	pos.x = x;
	pos.y = y;
}