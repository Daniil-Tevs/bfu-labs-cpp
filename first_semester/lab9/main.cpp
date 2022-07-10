#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
//Вариант 3.
//Создайте 3 прямоугольника разных цветов и размеров. Перемещайте их из исходного положения влево
//до конца экрана с разной скорость. При достижении конца экрана остановите фигуры.
using namespace std::chrono_literals;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Laba_9");
    //Первый прямоугольник
    sf::RectangleShape shape1(sf::Vector2f(50.f, 50.f));
    shape1.setFillColor(sf::Color::Red);
    float shape1_x0=60,shape1_y0=25;
    shape1.setOrigin(shape1_x0,shape1_y0);
    float shape1_x=1000, shape1_y=60,s1=5;
    //Второй прямоугольник
    sf::RectangleShape shape2(sf::Vector2f(240.f, 100.f));
    shape2.setFillColor(sf::Color::Yellow);
    float shape2_x0=120,shape2_y0=50;
    shape2.setOrigin(shape2_x0,shape2_y0);
    float shape2_x=650, shape2_y=180,s2=3;

    //Третий прямоугольник
    sf::RectangleShape shape3(sf::Vector2f(70.f, 400.f));
    shape3.setFillColor(sf::Color::Green);
    float shape3_x0=35,shape3_y0=200;
    shape3.setOrigin(shape3_x0,shape3_y0);
    float shape3_x=1000, shape3_y=500,s3=7;
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(shape1_x-s1 >= shape1_x0)
            shape1_x -= s1;
        else if(shape1_x != shape1_x0)
            shape1_x--;
        if(shape2_x-s2 >= shape2_x0)
            shape2_x -= s2;
        else if(shape2_x != shape2_x0)
            shape2_x--;
        if(shape3_x-s3 >= shape3_x0)
            shape3_x -= s3;
        else if(shape3_x != shape3_x0)
            shape3_x--;
        shape1.setPosition(shape1_x,shape1_y);
        shape2.setPosition(shape2_x,shape2_y);
        shape3.setPosition(shape3_x,shape3_y);
        window.clear(sf::Color::Blue);
        window.draw(shape1);
        window.draw(shape2);
        window.draw(shape3);
        window.display();
        std::this_thread::sleep_for(40ms);
    }

    return 0;
}