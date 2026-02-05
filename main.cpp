#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {
    // 1. Inicializar o SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Erro fatal no SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    // 2. Criar a janela
    SDL_Window* window = SDL_CreateWindow(
        "Physics Simulator (C++)",  // Título
        SDL_WINDOWPOS_CENTERED,     // Posição X
        SDL_WINDOWPOS_CENTERED,     // Posição Y
        800, 600,                   // Largura, Altura
        SDL_WINDOW_SHOWN
    );

    if (window == nullptr) {
        std::cerr << "Erro ao criar janela: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // 3. Obter a superfície da janela para desenhar
    SDL_Surface* screenSurface = SDL_GetWindowSurface(window);

    // Pintar de AZUL para testar (R=0, G=0, B=255)
    SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0, 0, 255));
    
    // Atualizar o ecrã
    SDL_UpdateWindowSurface(window);

    // 4. Esperar 3 segundos para veres a janela
    SDL_Delay(3000);

    // 5. Limpar memória
    SDL_DestroyWindow(window);
    SDL_Quit();

    std::cout << "Teste concluído com sucesso!" << std::endl;
    return 0;
}