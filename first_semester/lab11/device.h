#pragma once
#include <iostream>
class Device
{
private:
    std::string m_adress;
    std::string m_name;
public:
    double Pol();
    void Print(double result);
    Device(std::string adress,std::string name)
    {
        m_adress=adress;
        m_name=name;
    }
    ~Device()
    {

    }
};