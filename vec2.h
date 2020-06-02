#ifndef VEC2_H
#define VEC2_H

#include <math.h>
#include <iostream>

class vec2{
    public:
        float x, y;
    public:
        vec2(int xcoord = 0, int ycoord = 0);
        vec2 operator + (vec2 const &coord);
        vec2 operator - (vec2 const &coord);
        vec2 operator / (float const &num);
        vec2 operator * (float const &num);
        vec2 operator = (vec2 const &coord);
        bool operator == (vec2 const &coord);
        float magnitude();
        float distance(vec2 coord);
        void print_coord(void);
};


#endif