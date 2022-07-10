#include "class.h"
//Вариант 3.
//Создайте N (0<N<100) квадратов. Перемещайте их из исходного положения влево
//до конца экрана с разной скоростью. При достижении конца экрана остановите фигуры.
int main()
{
    sf::RenderWindow window(sf::VideoMode(width, height), "Laba_9");
    int n=100,t=0,j=0,x,y,dlina=35;
    std::vector<Square *> vec;
    if(n>100)
    {
        std::cout<<"Error: a lot of shape, make number less "<<n<<std::endl;
        std::cout<<"Number of shapes will be 100";
        n=100;
    }
    for(int i=0;i<n;i++)
    {
        if(i%20==0)
        {
            t+=100;
            j=0;
        }
        x=width-dlina/2-bok-t;
        y=dlina*j+j*10+bok-bok/dlina;
        vec.push_back(new Square(dlina, sf::Color(1+rand()%255,1+rand()%255,1+rand()%255,200+rand()%500),x,y,3+rand()%10));
        j++;
    }
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Blue);
        for(auto & i : vec)
        {
            window.draw(*i->getShape());
            i->Moving();
        }
        window.display();
        std::this_thread::sleep_for(40ms);
    }

    return 0;
}
