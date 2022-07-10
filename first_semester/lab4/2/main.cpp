#include <iostream>
#include <fstream>
#include "function.h"
using namespace std;


int main()
{
    int i=0,j=0,n;
    int fl=0,s=0,a=0,b=0,t=0,sum=0;
    ifstream in("input.txt");
    ofstream out("output.txt");
    in>>n;
    int* mass = new int[n];
    for(i=0;i<n;i++)
        in>>mass[i];
    for(j=0;j<t;j++)
    {
        if(mass[j]<=0)
            fl=1;
    }
    t=i-1;
    int a_max=INT_MIN,b_max=INT_MIN,u=0,v=0;;
    if(fl==0)
    {
        for(i=0;i<t;i++)
        {
            for(j=i;j<t;j++)
            {
                a = last_digit(mass[i]);
                b = last_digit(mass[j]);
                a_max=max_digit(mass[i]);
                b_max=max_digit(mass[j]);

                if(a==b)
                {
                    if(a_max==b_max)
                    {
                        if(mass[i]>=mass[j])
                            swap(mass[i],mass[j]);
                    }
                    else if(a_max>=b_max)
                        swap(mass[i],mass[j]);
                }
                else if(a>=b)
                    swap(mass[i],mass[j]);
            }
        }
        for(j=0;j<t;j++)
            out<<mass[j]<<" ";
    }
    else
        cout<<"Error: nekorektnie dannie";
    delete[] mass;
    return 0;
}