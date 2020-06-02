#include "game_manager.h"

game_manager::game_manager(int w, int h, char const * tittle, bool fullscreen){
    if(not SDL_Init(SDL_INIT_EVERYTHING)){
        int flags = 0;
        if(fullscreen){
            flags = SDL_WINDOW_FULLSCREEN;
        }
        
        width = w;
        height = h;
        window = SDL_CreateWindow(tittle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        if(window) std::cout << "window created" << std::endl;
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if(renderer){
             std::cout << "renderer created" << std::endl;
        }
        std::cout << "subsystems initialized!.." << std::endl; 
        isRunning = true;
    }
    else isRunning = false;
}


void game_manager::render(){
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, rendR, rendG, rendB, rendA); 
    SDL_RenderPresent(renderer);
}

void game_manager::update(){
    return;
}

void game_manager::clean(){
    isRunning = false;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "game cleaned" << std::endl;
}

void game_manager::handle_events(){
    SDL_Event event;
    
    SDL_PollEvent(&event);
    switch (event.type){
        case SDL_QUIT:
            clean();
            break;
        default:
            break;
    }
}

