#include "shape.h"
//constructor
Shape :: Shape(int x_, int y_) : Point(x_, y_ ){}
//default contructor 
Shape :: Shape( ) : Point() {}
//setters 
void Shape :: setterShape(int x_, int y_)
{
    x = x_;
    y = y_;
}
//getters
int Shape :: getX()
{
    return x;
}
int Shape :: getY()
{
    return y;
}
//print function
void Shape :: print()
{
    std :: cout << "The coordinate of a shape is  x = " << x << " y = " << y << std :: endl;
}