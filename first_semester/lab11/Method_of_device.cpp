#include "device.h"
#include <ctime>
double Device::Pol()
{
    srand(time(0));
    static unsigned seed = 1+rand()%100;
    seed = (seed * 73129 + 95121) % 1000;
    return (double) seed/10;
}
void Device::Print(double result)
{
    std::cout<<"Result of "<<m_name<<std::endl;
    std::cout<<result<<std::endl;
}