#ifndef __VEC2_HPP__
#define __VEC2_HPP__

#include "../Shape/Circle.hpp"
#include "../Shape/Polygon.hpp"

typedef struct vec2 {
        float x; 
        float y; 
        vec2(float _x, float _y) : x(_x), y(_y) {   }
    } vec2_t; 

    enum color {
        Black, 
        White,
        Grey, 
        Blue,
        Orange,
        Red, 
        Yellow,
        Purple,
        Pink, 
        Green
    }; 
    //union or similar to init a class from type polygon or circle 

#endif 