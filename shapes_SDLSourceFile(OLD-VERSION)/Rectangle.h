#ifndef _RECTANGLE_
#define _RECTANGLE_

#include "shape.h"
class Rectangle : public Shape
{
    private: 

    int R_x, R_y;

    public:
    //constructors
    //Rectangle(int xr, int yr, int xl, int yl);
    Rectangle(int xl, int yl, int h, int w);
    //setters
    void setterRec(int x_r_, int y_r_);
    //getters
    int getRx();
    int getRy();
    //area
    int area();
    //perimeter
    int perimeter();
    //print
    void printR();
    void draw(SDL_Renderer *R, SDL_Window *W);
};
#endif