#include "Text.hpp"

Text::Text(Vector2f p_pos, TTF_Font* t_font, int p_w, int p_h, std::string msg)
: Entity(p_pos, p_w, p_h), message(msg), font(t_font)
{
    this->color = {255, 255, 255};
    this->surf_msg = TTF_RenderText_Solid(this->font, this->message.c_str(), this->color);
    p_points = 0;
    e_points = 0;
    // freesurf = true;
}

void Text::addPoint_p() {
    p_points++;
    message = std::to_string(p_points) + " - " + std::to_string(e_points);
    std::cout << message << std::endl;
    surf_msg = TTF_RenderText_Solid(this->font, this->message.c_str(), this->color);
    // freesurf = true;
}
void Text::addPoint_e() {
    e_points++;
    message = std::to_string(p_points) + " - " + std::to_string(e_points);
    std::cout << message << std::endl;
    surf_msg = TTF_RenderText_Solid(this->font, this->message.c_str(), this->color);
    // freesurf = true;
}

void Text::edit_texture(SDL_Texture* new_texture) {
    this->tex = new_texture;
}

// void Text::freeSurf() {
//     SDL_FreeSurface(surf_msg);
// }