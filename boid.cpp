#include "boid.h"

boid::boid(int colorR, int colorG, int colorB, vec2 bpos, vec2 bvel, game_manager *bgame){
            r = colorR;
            g = colorG;
            b = colorB;
            pos = bpos; 
            vel = bvel;
            game = bgame;
        }

void boid::draw_boid(){
    SDL_RenderClear(game->renderer);

    //put stuff here
    filledCircleRGBA(game->renderer, pos.x, pos.y, radius, r, g, b, 255);


    SDL_SetRenderDrawColor(game->renderer, game->rendR, game->rendG, game->rendB, game->rendA); 
    SDL_RenderPresent(game->renderer);
}

void boid::speed_limit(){
    float speed = vel.magnitude();
    if(speed > speedLimit) vel = (vel/speed) * speedLimit;
}

void boid::control_boundaries(){
    if(pos.x < margin) vel.x += turnFactor;
    else if(pos.x > game->width - margin) vel.x -= turnFactor;

    if(pos.y < margin) vel.y += turnFactor;
    else if(pos.y > game->height - margin) vel.y -= turnFactor;
}



void boid::move(){

    control_boundaries();
    pos = pos + vel;
}