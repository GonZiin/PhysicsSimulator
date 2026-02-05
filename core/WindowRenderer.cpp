#include "WindowRenderer.hpp"
#include "../graphics/Circle.hpp"

WindowRenderer::WindowRenderer(const char* title, int width, int height)
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
    int w, h;
    SDL_GetRendererOutputSize(renderer, &w, &h);

    for (auto& p : particles) {
        p.ApplyForce(gravity * p.mass);
        p.Update(dt);

        if (p.position.y + p.radius >= h) {
            p.position.y = h - p.radius;
            p.velocity.y *= -0.8f;
        }

        if (p.position.x - p.radius <= 0) {
            p.position.x = p.radius;
            p.velocity.x *= -0.8f;
        }
        else if (p.position.x + p.radius >= w) {
            p.position.x = w - p.radius;
            p.velocity.x *= -0.8f;
        }
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

        Render();
        
        SDL_RenderPresent(renderer);
    }
}

void WindowRenderer::HandleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
        else if (event.type == SDL_MOUSEBUTTONDOWN) {
            if (event.button.button == SDL_BUTTON_LEFT) {
                int x, y;
                SDL_GetMouseState(&x, &y);

                particles.push_back(Particle(
                    (float)x, (float)y,
                    1.0f,
                    15.0f + (rand() %15),
                    {0, 255, 255, 255}
                ));
            }
        }
    }
}

void WindowRenderer::Render() {
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_RenderClear(renderer);

    for (const auto& p : particles) {
        Circle::DrawFillCircle (
            renderer,
            (int)p.position.x,
            (int)p.position.y,
            (int)p.radius,
            p.color
        );
    }
}