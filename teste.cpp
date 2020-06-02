#include <iostream>
#include "game_manager.h"
#include "boid.h"

int main(int argc, char* argv[]){
    const  int FPS = 60;
    const int frameDelay = 1000/FPS;
    Uint32 frameStart;
    int frameTime;

    game_manager game = game_manager(1600, 900, "boid sim", false);
    boid birb(250, 23, 200, vec2(10, 10), vec2(5, 5), &game);

    while(game.isRunning){
        frameStart = SDL_GetTicks();

        //main body here
        game.handle_events();
        birb.draw_boid();
        birb.move();
    
        frameTime = SDL_GetTicks() - frameStart;
        //ends here

        if (frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);

    }
    
    return 0;
}