#include "Player.hpp"

void Player::moveUp() {
    if(pos.y >= 10)
    pos.y -= 10;
}

void Player::moveDown() {
    if(pos.y <= HEIGHT-10-Entity::currentFrame.h)
    pos.y += 10;
}