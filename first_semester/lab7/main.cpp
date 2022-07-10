#include <iostream>
#include <windows.h>
#include "function.h"

int main()
{

    int n,fl = 0,max;
    Read(n);
    int* mass = new int[n * n];
    Read_m(mass);
    Proverka(fl, n, mass);
    if (fl == 0)
    {
        max=Prostoe_digit(n, mass);
        if (max != INT_MIN)
            end(max, n, mass);
        else
            fl = 1;

    }
    Write(n, mass,fl);
    delete[] mass;
    std::cout<<1;
}
