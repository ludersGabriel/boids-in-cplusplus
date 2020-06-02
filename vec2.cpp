#include "vec2.h"

vec2::vec2(int xcoord, int ycoord){
    x = xcoord;
    y = ycoord;
}

vec2 vec2::operator + (vec2 const &coord){
    return vec2(x + coord.x, y + coord.y);
}

vec2 vec2::operator - (vec2 const &coord){
    return vec2(x - coord.x, y - coord.y); 
}

vec2 vec2::operator / (float const &num){
    return vec2(x/num , y/num);
}

vec2 vec2::operator * (float const &num){
    return vec2(x*num, y*num);
}

bool vec2::operator == (vec2 const &coord){
    return x == coord.x and y == coord.y;
}

vec2 vec2::operator = (vec2 const &coord){
    x = coord.x;
    y = coord.y;
}

float vec2::magnitude(){
    return sqrt(pow(x,2) + pow(y,2));
}

float vec2::distance(vec2 coord){
    return sqrt(pow(x - coord.x, 2) + pow(y - coord.y, 2));
}

void vec2::print_coord(void){
    std::cout << "coord x,y: " << x << "," << y << "\n";
}