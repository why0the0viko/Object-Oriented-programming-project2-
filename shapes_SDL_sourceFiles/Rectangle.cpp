#include "Rectangle.h"

Rectangle :: Rectangle(int xr, int yr, int xl, int yl) : Shape(xl, yl), R_x(xr), R_y(yr) {}
Rectangle :: Rectangle(int xl, int yl, int h) : Shape(xl, yl), R_x(xl + h), R_y(yl + h) {}

//setters
void Rectangle :: setterRec(int x_r_, int y_r_)
{
    R_x = x_r_;
    R_y = y_r_;
}
//getters
int Rectangle :: getRx()
{
    return R_x;
}
int Rectangle :: getRy()
{
    return R_y;
}
//area
double Rectangle :: area()
{
    int area = 0;
    area = (R_x - getX()) * (R_y - getY());
    return area;
}
//perimeter
double Rectangle :: perimeter()
{
    int perimetre = 0;
    perimetre = (R_x - getX()) * 2 + (R_y - getY()) * 2;
    return perimetre;
}
//print
void Rectangle :: print()
{
    print();
    std :: cout << "The right coordinates : x = " << R_x << " y = " << R_y << std :: endl; 
}
void Rectangle :: draw(SDL_Renderer *R, SDL_Window *W)
{

    SDL_SetRenderDrawColor(R, 255, 255, 255, 255);

    SDL_RenderDrawLine(R, getX(), getY(), getX(), R_y);
    SDL_RenderDrawLine(R, getX(), getY(), R_x, getY());
    SDL_RenderDrawLine(R, R_x, R_y, R_x, getY());
    SDL_RenderDrawLine(R, R_x, R_y, getX(), R_y);

    SDL_SetRenderDrawColor(R, 0, 0, 0, 255);

}