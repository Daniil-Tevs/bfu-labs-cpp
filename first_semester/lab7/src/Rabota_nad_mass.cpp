#include<iostream>
#include "function.h"
void Proverka(int &fl,int n,int* mass)
{
    int i, j,k=0;
    int** massvs = new int* [n];
    //копирование элементов одномерного в двумерный массив
    for (i = 0; i < n; i++)
    {
        massvs[i] = &mass[i*n];
    }
    for (i = 0; i < n-1; i++)
    {
        for (k = i+1; k < n; k++)
        {
            fl = 0;
            for (j = 0; j < n; j++)
            {
                if (massvs[i][j] != massvs[k][j])
                {
                    fl = 1;
                    break;
                }
            }
            if (fl == 0)
                break;
        }
        if (fl == 0)
            break;
    }
    delete[] massvs;
}
int Prostoe_digit(int n, int* mass)
{
    int max = INT_MIN;
    int i,j,t=0,s=0;
    for (i = 0; i < n*n; i++)
    {
        t = 0;
        if (mass[i] >0)
        {
            for (j = 2; j <= sqrt(abs(mass[i])); j++)
            {
                if (mass[i] % j == 0)
                {
                    t = 1;
                    break;
                }
            }
            if (t == 0)
            {
                if (max < mass[i])
                    max = mass[i];
            }
        }
    }
    return max;
}
void end(int max, int n, int* mass)
{
    int i, j, k = 0;
    int** massvs = new int* [n];
    //копирование элементов одномерного в двумерный массив
    for (i = 0; i < n; i++)
    {
        massvs[i] = &mass[i * n];
    }
    int min;
    for (i = 0; i < n; i++)
    {
        min = INT_MAX;
        for (j = 0; j < n; j++)
        {
            if (min > massvs[j][i])
                min = massvs[j][i];
        }
        for (j = 0; j < n; j++)
        {
            if (min == massvs[j][i])
                massvs[j][i] = max;
        }
    }
    k = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            mass[k] = massvs[i][j];
            k++;
        }
    }
    delete[] massvs;
}