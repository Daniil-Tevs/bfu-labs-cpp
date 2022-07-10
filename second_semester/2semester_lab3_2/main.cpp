#include <iostream>
double function(double x)
{
    return x-10;
}
double BISECTION(double a,double b,double eps)
{
    while(true)
    {
        double x=(a+b)*0.5;
        if(abs(x-a)<eps && abs(x-b)<eps)
            return x;
        else if(function(x)* function(a)>0)
            a=x;
        else
            b=x;
    }
}
int main() {
    std::cout<<BISECTION(0,INT32_MAX,0.00001);
    return 0;
}
