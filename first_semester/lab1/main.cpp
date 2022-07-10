#include <iostream>
#include <cmath>
int main()
{
    int N;
    double X;
    std::cin>>X>>N;
    X=std::pow(X,1/N);
    std::cout<<X;
    return 0;
}
