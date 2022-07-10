#include <iostream>
#include <vector>
#include "device.h"
//Вариант 3
//Датчики давления ПД-100 и температуры ПТ-100.
//Поля данных: давление и температура (float).

int main()
{
    std::string name,adress;
    int n;
    std::cout<<"Input number of devices"<<std::endl;
    std::cin>>n;
    std::vector<std::string> mass_a_n;
    for(int i=0;i<n;i++)
    {
        std::cout<<"Input adress of "<<i+1<<" device"<<std::endl;
        std::cin>>name;
        mass_a_n.push_back(name);
        std::cout<<"Input name of "<<i+1<<" device"<<std::endl;
        std::cin>>adress;
        mass_a_n.push_back(adress);
    }
    std::vector<Device*> devices;
    for(int i=0;i<n;i++)
    {
        devices.push_back(new Device(mass_a_n[i*2],mass_a_n[i*2+1]));
        devices[i]->Print(devices[i]->Pol());
    }
    return 0;
}
