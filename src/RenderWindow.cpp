#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
	:window(NULL), renderer(NULL)
{
    // make a window
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_ALLOW_HIGHDPI);

    // return error in case of failing
	if (window == NULL)
	{
		std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
	}

    // make renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}


SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
	// load image from file path
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if (texture == NULL)
		std::cout << "Failed to load texture. Error: " << SDL_GetError() << std::endl;

	return texture;
}


void RenderWindow::cleanUp()
{
	// destroy window
	SDL_DestroyWindow(window);
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& p_entity)
{
	SDL_Rect src; 
	src.x = p_entity.getCurrentFrame().x;
	src.y = p_entity.getCurrentFrame().y;
	src.w = p_entity.getCurrentFrame().w;
	src.h = p_entity.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = p_entity.getPos().x;
	dst.y = p_entity.getPos().y;
	dst.w = p_entity.getCurrentFrame().w;
	dst.h = p_entity.getCurrentFrame().h;

	SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
}

// void RenderWindow::render(Text& p_text)
// {
// 	SDL_Rect dst;
// 	dst.x = p_text.getPos().x;
// 	dst.y = p_text.getPos().y;
// 	dst.w = p_text.getCurrentFrame().w;
// 	dst.h = p_text.getCurrentFrame().h;

// 	SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, p_text.get_message());

// 	// if(p_text.canFreeSurf()) {
// 	// 	p_text.freeSurf();
// 	// 	p_text.editFreeSurf(false);
// 	// }

// 	SDL_RenderCopy(renderer, message, NULL, &dst);
// }

void RenderWindow::render(SDL_Texture* bg) {
	SDL_RenderCopy(renderer, bg, NULL, NULL);
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}