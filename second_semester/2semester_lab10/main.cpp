#include <iostream>
#include "bmp.h"
int main()
{
    bmp image("../examples/example1.bmp");
//    image.filter('r','u',200);
    image.rotate(acos(-1)/4);
    image.write("../output.bmp");
    return 0;
}
