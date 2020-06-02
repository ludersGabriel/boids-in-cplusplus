#include <iostream>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "vec2.h"


class boid{
    public:
        vec2 pos, vel;

    public:
        boid(vec2 bpos, vec2 bvel){
            pos = bpos; 
            vel = bvel;
        }
};

int main(void){
    vec2 pos(1,2), vel(2,2);
    boid birb(pos, vel);

    birb.pos.print_coord();
    birb.vel.print_coord();    

    return 0;
}