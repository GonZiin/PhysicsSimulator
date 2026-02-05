#pragma once
#include "Vector2.hpp"
#include <SDL2/SDL.h>

class Particle {
    public:
        Vector2 position;
        Vector2 velocity;
        Vector2 acceleration;

        float radius;
        float mass;
        SDL_Color color;

        Particle(float x, float y, float mass, float radius, SDL_Color color);
        ~Particle() = default;

        void Update(float dt);
        void ApplyForce(const Vector2& force);
};