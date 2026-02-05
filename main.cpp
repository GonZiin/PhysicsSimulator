#include <SDL2/SDL.h>
#include "core/WindowRenderer.hpp"

int main(int argc, char* argv[]) {
    WindowRenderer mainWindow("Particle Simulator", 1920, 1080);
    mainWindow.Run();

    return 0;
}