#include "circle.h"
#include <math.h>
//constructor
circle :: circle(int radius, int x, int y) : Shape(x, y), radius(radius) {}
//setter
void circle :: setRadius(int r)
{
    radius = r;
}
//getter
int circle :: getRadius()
{
    return radius;
}
//area
double circle :: areaCircle()
{
    double area = 0.0;
    area = 3.14 * radius * radius;
    return area;
}
//perimeter
double circle :: perimeterCircle()
{
    double perimeter = 0.0;
    perimeter = 3.14 * radius * 2;
    return perimeter;
}
//print
void circle :: printCircle()
{
    print();
    std :: cout << "The radius is : " << radius << std :: endl;
}
void circle :: drawCircle(SDL_Renderer *R, SDL_Window *W)
{
    const float angle = 180 / 3.1415926;
    //SDL_RenderClear(R);
    SDL_SetRenderDrawColor(R, 255, 255, 255, 255);

    // SDL_RenderDrawLine(R, getX(), getY(), getX() + radius, getY());
    // SDL_RenderDrawLine(R, getX(), getY(), getX(), getY() + radius);
    float xcorprev = getX();
    float ycorprev = getY() + radius;
    for(int i = 1; i < 360; i += 1)
    {
        float currentx = getX() + radius * cos(i * angle);
        float currenty =  getY() + radius * sin(i * angle);
        SDL_RenderDrawLine(R,xcorprev, ycorprev, currentx, currenty);
        xcorprev = currentx;
        ycorprev = currenty;
    }

    SDL_SetRenderDrawColor(R, 0, 0, 0, 255);

    //SDL_RenderPresent(R);

}