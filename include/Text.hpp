#pragma once
#include "Entity.hpp"
#include "Constants.h"
#include <SDL2/SDL_ttf.h>

class Text : public Entity {
    private:
        std::string message;
        TTF_Font* font;
        SDL_Color color;
        SDL_Surface* surf_msg;
        int p_points, e_points;
        // bool freesurf;
    public:
        Text(Vector2f p_pos, TTF_Font* t_font, int p_w, int p_h, std::string msg);
        void edit_texture(SDL_Texture* new_texture);
        SDL_Surface* get_message() { return surf_msg; };

        void addPoint_p();
        void addPoint_e();

        // bool canFreeSurf() {return freesurf;}
        // void editFreeSurf(bool new_surf) { freesurf = new_surf;}

        // void freeSurf();
};