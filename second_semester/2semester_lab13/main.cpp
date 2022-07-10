#include <SFML/Graphics.hpp>
#include <scene.hpp>

int main()
{
    dt::Scene scene(display_width, display_height);
    scene.LifeCycle();

    return 0;
}