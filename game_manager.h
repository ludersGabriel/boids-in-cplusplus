#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "vec2.h"

class game_manager{
    public: 
        int width; 
        int height;
        bool isRunning;
        SDL_Window* window;
        SDL_Renderer* renderer;
        int rendR = 102;
        int rendG = 178;
        int rendB = 255;
        int rendA = 0;
    public:
        game_manager(int w, int h, char const * tittle, bool fullscreen);
        void render();
        void update();
        void clean();
        void handle_events();

};

#endif