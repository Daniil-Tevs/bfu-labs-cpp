#include "function.h"

int last_digit(int a1)
{
    int a;
    while(a1>0)
    {
        a=a1%10;
        a1/=10;

    }
    return a;
}
int max_digit(int a1)
{
    int a=0,a_max=0;
    while(a1>0)
    {
        a=a1%10;
        if(a_max<a)
            a_max=a;
        a1/=10;

    }
    return a_max;
}