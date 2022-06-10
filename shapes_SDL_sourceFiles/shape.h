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
    virtual void print() = 0;
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual void draw(SDL_Renderer *R, SDL_Window *W) = 0; 
};
#endif