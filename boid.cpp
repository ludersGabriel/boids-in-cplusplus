#include "boid.h"

boid::boid(int bid, boid* boids, int size, int colorR, int colorG, int colorB, vec2 bpos, vec2 bvel, game_manager *bgame){
            id = bid;
            flock = boids;
            flockSize = size;
            r = colorR;
            g = colorG;
            b = colorB;
            pos = bpos; 
            vel = bvel;
            game = bgame;
        }

void boid::draw_boid(){
    //put stuff here
    filledCircleRGBA(game->renderer, pos.x, pos.y, radius, r, g, b, 255);
}

vec2 boid::rule1(){
    vec2 center = vec2(0, 0);
    vec2 v1 = vec2(0, 0);
    int numNeighbors = 0;

    for(int i = 0; i < flockSize; i++){
        if(flock[i].id != id){
            if(pos.distance(flock[i].pos) <= fov){
                center = center + flock[i].pos;
                numNeighbors += 1;
            }
        }
    }

    if(numNeighbors){
        center = center/numNeighbors;
        v1 = center - pos;
        return v1 * centergingFactor;
    }
    else return vec2(0, 0);

}

vec2 boid::rule2(){
    vec2 v2 = vec2(0, 0);
    
    for(int i = 0; i < flockSize; i++){
        if(flock[i].id != id and pos.distance(flock[i].pos) <= minDistance){
            v2 = v2 - (flock[i].pos - pos);
        }
    }
    return v2 * avoidCollisionFactor;
}

vec2 boid::rule3(){
    vec2 v3 = vec2(0, 0);
    int numNeighbors = 0;

    for(int i = 0; i < flockSize; i++){
        if(flock[i].id != id and pos.distance(flock[i].pos) <= fov){
            v3 = v3 + flock[i].vel;
            numNeighbors += 1;
        }
    }

    if(numNeighbors){
        v3 = v3/numNeighbors;
        v3 = v3 - vel;
        return v3 * mathcingSpeedFacotr;
    }
    else return vec2(0, 0);

}


void boid::speed_limit(){
    float speed = vel.magnitude();
    if(speed > speedLimit){
        vel = (vel/speed);
        vel = vel * speedLimit;
    }
}

void boid::control_boundaries(){
    if(pos.x < margin) vel.x += turnFactor;
    else if(pos.x > game->width - margin) vel.x -= turnFactor;

    if(pos.y < margin) vel.y += turnFactor;
    else if(pos.y > game->height - margin) vel.y -= turnFactor;
}

void boid::move_boid(){
    vec2 v1 = rule1();
    vec2 v2 = rule2();
    vec2 v3 = rule3();

    vel = vel + v1 + v2 + v3;

    speed_limit();
    control_boundaries();

    pos = pos + vel;
}

void boid::clean(){
    SDL_DestroyWindow(game->window);
    SDL_DestroyRenderer(game->renderer);
    SDL_Quit();
    std::cout << "game cleaned" << std::endl;
    exit(0);
}

void boid::handle_events(){
    SDL_Event event;
    
    SDL_PollEvent(&event);
    // SDL_WaitEvent(&event);
    if(event.type == SDL_QUIT) 
        clean();
    if(event.type == SDL_KEYDOWN){
        if(event.key.keysym.sym == SDLK_q){
            if(centergingFactor == 0) return;
            centergingFactor -= 0.001;        
        }
        else if(event.key.keysym.sym == SDLK_w){
            if(centergingFactor == 1) return;
            centergingFactor += 0.001;
        }
        else if(event.key.keysym.sym == SDLK_a){
            if(avoidCollisionFactor == 1) return;
            avoidCollisionFactor += 0.001;
        }
        else if(event.key.keysym.sym == SDLK_s){
            if(avoidCollisionFactor == 0) return;
            avoidCollisionFactor -= 0.001;
        }
        else if(event.key.keysym.sym == SDLK_z){
            if(mathcingSpeedFacotr == 1) return;
            mathcingSpeedFacotr += 0.001;
        }
        else if(event.key.keysym.sym == SDLK_x){
            if(mathcingSpeedFacotr == 0) return;
            mathcingSpeedFacotr -= 0.001;
        }

    }
}

flock::flock(game_manager *bgame){
    boids = (boid*)malloc(boidAmount * sizeof(boid));
    if(not boids){ 
        std::cout << "failed making boids" << std::endl;
        exit(1);
    }

    srand(time(NULL));
    game = bgame;
    for(int i = 0; i < boidAmount; i++){
        vec2 bpos = vec2(rand() % game->width + 1, rand() % game->height + 1);
        vec2 bvel = vec2(rand() % 13 + (-5) + 1, rand() % 13 + (-5) + 1);
        int r = 102;
        int g = 51;
        int b = 0;
        boids[i] = boid(i, boids, boidAmount, r, g, b, bpos, bvel, game);
    }
}

void flock::draw_flock(){
    SDL_RenderClear(game->renderer);
    for(int i = 0; i < boidAmount; i++){
        boids[i].draw_boid();
    }
    SDL_SetRenderDrawColor(game->renderer, game->rendR, game->rendG, game->rendB, game->rendA); 
    SDL_RenderPresent(game->renderer);
}

void flock::move_flock(){
    for(int i = 0; i < boidAmount; i++){
        boids[i].move_boid();

    }
}

void flock::handle_factors(){
    for(int i = 0; i < boidAmount; i++){
        boids[i].handle_events();
    }
}