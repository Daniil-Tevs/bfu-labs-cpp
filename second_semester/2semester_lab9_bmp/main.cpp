#include <iostream>
#include "bmp.h"
int main()
{
    bmp image("../example.bmp");
    image.filter('b','d',50);
//    image.filter('r','u',200);
    image.write("../output.bmp");
    return 0;
}
