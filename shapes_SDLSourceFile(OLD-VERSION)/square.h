#ifndef _SQUARE_
#define _SQUARE_

#include "Rectangle.h"
class square : public Rectangle
{
    private:

    public:
    //constructors
    square(int x_l, int y_l, int x_r, int y_r);
    square(int x_l, int y_l, int z);

};
#endif