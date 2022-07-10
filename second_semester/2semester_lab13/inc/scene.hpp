#pragma once
#include <SFML/Graphics.hpp>
#define display_width 1920
#define display_height 1080
#include <camera.hpp>
#include "object.h"

namespace dt
{
	class Scene
	{
	public:
		Scene(int width, int height);
		~Scene();
		void LifeCycle();

	private:
		std::shared_ptr<Camera> m_camera;

		int m_width;
		int m_height;

        double m_speed = 0.1;

		std::unique_ptr<sf::RenderWindow> m_window;
		std::unique_ptr<sf::Texture> m_texture;
		std::unique_ptr<sf::Sprite> m_sprite;
	};
}