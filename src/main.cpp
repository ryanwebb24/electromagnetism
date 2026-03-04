#include <SDL3/SDL.h>

#include <iostream>

#include "Particle.h"
#include "PartilceEngine.h"

int WINDOW_HEIGHT = 600;
int WINDOW_WIDTH = 800;

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL failed to initialize: " << SDL_GetError() << "\n";
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Electromagnetism Simulation",
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_RESIZABLE);

    if (!window) {
        std::cerr << "Window creation failed: " << SDL_GetError() << "\n";
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (!renderer) {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << "\n";
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    bool running = true;
    SDL_Event event;

    const double physics_dt = 0.01;
    const PhysicsVector gravity(0, 9.8);
    const int numberOfParticles = 100;// downward acceleration
    
    PartilceEngine particles();

    while (running) {
        // Handle events
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
              case SDL_EVENT_QUIT:
                running = false;
                break
              case SDL_EVENT_MOUSE_BUTTON_DOWN:

              default:
                
                break;
            }
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
            if (event.type == SDL_MOUSE)
        }
        if (!running) break;

        // Physics update
        particle1.applyForce(gravity * particle1.getMass()); // Gravity stuff
        particle1.update(physics_dt, WINDOW_WIDTH, WINDOW_HEIGHT);

        // Render
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_FRect rect;
        rect.x = static_cast<int>(particle1.getPosition().getX());
        rect.y = static_cast<int>(particle1.getPosition().getY());
        rect.w = 5;
        rect.h = 5;
        SDL_RenderFillRect(renderer, &rect);

        SDL_RenderPresent(renderer);

        SDL_Delay(10);  // ~100 FPS cap
    }

    std::cout << "Simulation ended.\n";
    std::cout << "Particle: y=" << particle1.getPosition().getY()
              << " x=" << particle1.getPosition().getX() << std::endl;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
