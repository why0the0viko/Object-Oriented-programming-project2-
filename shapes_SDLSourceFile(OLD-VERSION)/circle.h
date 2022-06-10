#ifndef _CIRCLE_
#define _CIRCLE_

#include "shape.h"
class circle : public Shape
{
    private:

    int radius;
    public:
    //constructor
    circle(int radius, int x, int y);
    //setter
    void setRadius(int r);
    //getter
    int getRadius();
    //area
    double areaCircle();
    //perimeter
    double perimeterCircle();
    //print
    void printCircle();
    void drawCircle(SDL_Renderer *R, SDL_Window *W);
};
#endif