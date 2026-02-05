#include "WindowRenderer.hpp"
#include "../graphics/Circle.hpp"

WindowRenderer::WindowRenderer(const char* title, int width, int height)
    : particle(400, 100, 1.0f, 20.0f, {0,255,255,255})
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_ALLOW_HIGHDPI);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    isRunning = true;

    lastFrameTime = SDL_GetTicks64();
}

void WindowRenderer::Update(float dt) {
    Vector2 gravity(0.0, 980.0f);
    particle.ApplyForce(gravity * particle.mass);
    particle.Update(dt);
    int w, h;
    SDL_GetRendererOutputSize(renderer, &w, &h);

    if (particle.position.y + particle.radius >= h) {
        particle.position.y = h - particle.radius;
        particle.velocity.y *= -0.8f;
    }
}

WindowRenderer::~WindowRenderer() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void WindowRenderer::Run() {
    while (isRunning) {
        HandleEvents();

        Uint64 currentFrameTime = SDL_GetTicks64();
        float dt = (currentFrameTime - lastFrameTime) / 1000.0f;
        lastFrameTime = currentFrameTime;

        Update(dt);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        Circle::DrawFillCircle(
            renderer,
            (int)particle.position.x,
            (int)particle.position.y,
            (int)particle.radius,
            particle.color
        );
        
        SDL_RenderPresent(renderer);
    }
}

void WindowRenderer::HandleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            isRunning = false;
    }
}