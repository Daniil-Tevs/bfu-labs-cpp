#include<iostream>
#include<fstream>
#include "function.h"
void Read(int& a)
{

    std::ifstream in("input.txt");
    in >> a;
    in.close();
}
void Read_m(int* mass)
{
    std::ifstream in("input.txt");
    int n, i;
    in >> n;
    for (i = 0; i < n * n; i++)
        in >> mass[i];
    in.close();
}