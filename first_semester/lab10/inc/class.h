#pragma once
//Подключение библиотек
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include<vector>

//Определение констант
#define width 1600
#define height 920
#define bok 27
using namespace std::chrono_literals;

class Square
{
private:
    sf::RectangleShape *m_shape;
    int v;
public:
    Square(float dlina, const sf::Color color,int x,int y,int v_f)
    {
        m_shape = new sf::RectangleShape(sf::Vector2f(dlina,dlina));;
        m_shape->setFillColor(color);
        m_shape->setOrigin(dlina/2,dlina/2);
        m_shape->setPosition(x,y);
        v=v_f;
    }
    void Moving();
    sf::RectangleShape *getShape()
    {
        return m_shape;
    }
    ~Square()
    {
        delete m_shape;
    }
};
