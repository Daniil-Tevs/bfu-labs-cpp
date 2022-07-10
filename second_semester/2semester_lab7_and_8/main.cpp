#include <iostream>
#include <cassert>
#include "matrix.h"

int main() {
    std::cout << "=== Test 1 ===" << std::endl;

    {
        double m1[2][2]={{1,2},{3,4}},m2[2][1]={{1},{2}};
        mat22d A=m1;
        vec2d x=m2;
        auto B = A*x;
        assert(B.get(0, 0) == 3);
        assert(B.get(1, 0) == 14);
    }

    std::cout << "Done!" << std::endl;

    std::cout << "=== Test 2 ===" << std::endl;

    {
        double m1[2][2]={{1,1},{1,1}},m2[2][1]={{1},{1}};
        mat22d A=m1;
        vec2d x=m2;
        vec2d B;
        B = A*x;

        assert(B.get(0, 0) == 2);
        assert(B.get(1, 0) == 2);
    }

    std::cout << "Done!" << std::endl;


    return 0;
}
