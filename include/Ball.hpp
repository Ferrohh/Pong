#pragma once
#include "Entity.hpp"
#include "Player.hpp"
// #include "Text.hpp"
#include <vector>

class Ball : public Entity {
    public:
        using Entity::Entity;
        void move(std::vector<Player> players);
    private:
        bool checkCollision();
        bool checkCollision(Player e);
        void calcAngle(float q);
        float step = 0.05;
        float angle = 270;
};