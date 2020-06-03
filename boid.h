#ifndef BOID_H
#define BOID_H

#include "vec2.h"
#include "game_manager.h"
#include <time.h>

class boid{
    public:
        int id;
        float turnFactor = 0.5;
        int margin = 200;
        float fov = 75;
        float centergingFactor = 0.005;
        float avoidCollisionFactor = 0.05;
        float mathcingSpeedFacotr = 0.05;
        float speedLimit = 10;
        float minDistance = 20;
        float safeDistance = 50;
        float radius = 5;
        vec2 pos, vel;
        int r, g, b;
        game_manager *game;
        boid *flock;
        int flockSize;

    public:
        boid(int bid = -1, boid* boids = nullptr, int flockSize = -1, int colorR = 0, int colorG = 0, int colorB = 0, vec2 bpos = vec2(0,0), vec2 bvel = vec2(0,0), game_manager *bgame = nullptr);
        void draw_boid();
        void move_boid();
        void control_boundaries();
        void speed_limit();
        vec2 rule1();
        vec2 rule2();
        vec2 rule3();
        void clean();
        void handle_events();
};

class flock{
    public:
        int boidAmount = 500;
        boid *boids;
        game_manager *game;
    public:
        flock(game_manager *bgame = nullptr);
        void draw_flock();
        void move_flock();
        void handle_factors();
};

#endif