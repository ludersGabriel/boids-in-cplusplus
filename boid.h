#ifndef BOID_H
#define BOID_H

#include "vec2.h"
#include "game_manager.h"


class boid{
    public:
        float turnFactor = 1;
        int margin = 100;
        float fov = 100;
        float centergingFactor = 0.005;
        float avoidCollisionFactor = 0.05;
        float mathcingSpeedFacotr = 0.005;
        float speedLimit = 10;
        float minDistance = 20;
        float safeDistance = 50;
        float radius = 5;
        vec2 pos, vel;
        int r, g, b;
        game_manager *game;

    public:
        boid(int colorR, int colorG, int colorB, vec2 bpos, vec2 bvel, game_manager *bgame);
        void draw_boid();
        void move();
        void control_boundaries();
        void speed_limit();
};

#endif