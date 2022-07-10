#include<iostream>
#include<fstream>
#include "function.h"
void Write(int n, int* mass,int fl)
{
    std::ofstream out("output.txt");
    int i;
    if(fl==1)
        out << "Simple digit no found" << std::endl;
    for (i = 0; i < n * n; i++)
    {
       if ((i != 0) && (i % n) == 0)
            out << std::endl;
        out << mass[i] << " ";
    }
}
