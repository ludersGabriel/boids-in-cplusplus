#include <iostream>
#include "game_manager.h"
#include "boid.h"

int main(int argc, char* argv[]){
    const  int FPS = 60;
    const int frameDelay = 1000/FPS;
    Uint32 frameStart;
    int frameTime;

    game_manager game = game_manager(1800, 1000, "boid sim", false);
    flock boids = flock(&game);

    while(game.isRunning){
        frameStart = SDL_GetTicks();

        //main body here
        boids.handle_factors();
        boids.draw_flock();
        boids.move_flock();
    
        frameTime = SDL_GetTicks() - frameStart;
        //ends here

        if (frameDelay > frameTime)
            SDL_Delay(frameDelay - frameTime);
    }
    
    return 0;
}