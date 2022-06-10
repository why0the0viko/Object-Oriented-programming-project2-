#ifndef _SHAPE_
#define _SHAPE_

#include "Point.h"
#include <SDL2/SDL.h>

class Shape : private Point<int>
{
    public:
    //constructor
    Shape(int x_, int y_);
    //default contructor 
    Shape( );
    //setters 
    void setterShape(int x, int y);
    //getters
    int getX();
    int getY();
    //print function
    void print();
};
#endif