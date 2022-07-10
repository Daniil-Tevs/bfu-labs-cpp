#include <scene.hpp>

namespace dt
{
	Scene::Scene(int width, int height)
	{
		m_width = width;
		m_height = height;
		m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(m_width, m_height), "Lab13");
		m_texture = std::make_unique<sf::Texture>();
		m_texture->create(m_width, m_height);
		m_sprite = std::make_unique<sf::Sprite>(*m_texture);

		Intrinsic intrinsic = { 960.0, 540.0, 960.0, 540.0 };
		Point position = { 0.0, 0.0, 0.0 };
		Angles angles = { 0.0,0.0,0.0 };
		m_camera = std::make_unique<Camera>(m_width, m_height, intrinsic, position, angles);
	}
	Scene::~Scene() = default;
	void Scene::LifeCycle()
	{
        dt::Sphere pol_sphere(2,2*acos(-1),acos(-1)/2);
        pol_sphere.offset({0,5,0});
        pol_sphere.setColor({0,0,255,255});
//        dt::Sphere pol_sphere2("(x+10)^2+(y-5)^2+z^2=4", 2*acos(-1), acos(-1)/2);
//        pol_sphere2.setColor({0,255,0,255});
//        dt::Sphere pol_sphere3("../examples/input_sphere_equation.txt");
//        pol_sphere3.setColor({255,255,0,255});
//        ObjectText figure("../examples/points.txt");
        dt::Parallelepiped parallelepiped(1.5,1,1);
        parallelepiped.offset({0, 5, 0});
        parallelepiped.setColor({100,255,100,255});

		while (m_window->isOpen()) {
			sf::Event event;
			while (m_window->pollEvent(event))
				if (event.type == sf::Event::Closed)
					m_window->close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				m_camera->dZ(m_speed);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				m_camera->dZ(-m_speed);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				m_camera->dX(-m_speed);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				m_camera->dX(m_speed);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				m_camera->dPitch(-0.02);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				m_camera->dPitch(0.02);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				m_camera->dRoll(-0.02);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				m_camera->dRoll(0.02);

			// Проецирование точек
			pol_sphere.ProjectPointsObject(m_camera);
//            pol_sphere2.ProjectPointsObject(m_camera);
//            pol_sphere3.ProjectPointsObject(m_camera);
//            figure.ProjectPointsObject(m_camera);
            parallelepiped.ProjectPointsObject(m_camera);

			m_texture->update((uint8_t*)m_camera->Picture(), display_width, display_height, 0, 0);
			m_camera->Clear();


			m_window->clear();
			m_window->draw(*m_sprite);

			m_window->display();
		}
	}
}