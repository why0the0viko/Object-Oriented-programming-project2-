#include "square.h"
square :: square(int x_l, int y_l, int x_r, int y_r) : Rectangle(x_r, y_r, x_l, y_l)
{
    if((x_r - x_l) != (y_r - y_l))
    {
        throw std :: runtime_error("Its not a square");
    }
}
square :: square(int x_l, int y_l, int z) : Rectangle(x_l, y_l, z, z) {}
