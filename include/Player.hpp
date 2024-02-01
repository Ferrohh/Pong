#pragma once
#include "Entity.hpp"
#include "Constants.h"

class Player : public Entity {
    public:
        using Entity::Entity;
        void moveUp();
        void moveDown();
};