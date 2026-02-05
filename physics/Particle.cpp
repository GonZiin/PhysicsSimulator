#include "Particle.hpp"

Particle::Particle(float x, float y, float mass, float radius, SDL_Color color)
    : position (x, y), mass (mass), radius(radius), color (color) {
    velocity = Vector2(0, 0);
    acceleration = Vector2(0, 0);
}

void Particle::ApplyForce(const Vector2& force) {
    acceleration += force * (1.0f / mass);
}

void Particle::Update(float dt) {
    velocity += acceleration * dt;
    position += velocity * dt;
    acceleration = Vector2(0, 0);
}
