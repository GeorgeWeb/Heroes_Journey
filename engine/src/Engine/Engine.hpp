#ifndef ENGINE_H
#define ENGINE_H

// SFML Dependencies
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

// Engine features
#include "Maths/Vector2ul.hpp"
#include "SM/StateMachine.hpp"
#include "Asset/AssetManager.hpp"
#include "Input/InputManager.hpp"
#include "ECM/EntityManager.hpp"
#include "System/Renderer.hpp"
#include "System/Settings.hpp"
#include "System/Animation.hpp"
#include "Utils/Random.hpp"
#include "Utils/FileIO.hpp"

namespace Engine {

	class Engine2D
	{
		public:
			static sf::RenderWindow* window;
			static std::string title;

			static sf::Sprite cursor;

		public:
			Engine2D() = delete;
			
			static void Render();
			static void Update();

			static void DisplayFPS();

			static sf::RenderWindow& GetWin();
			static sf::Vector2u GetWinSize();

			static void SetVsync(bool t_vsync);
	};

	namespace Timing
	{
		// Return time since Epoc
		long long Now();
		// Return time since last() was last called.
		long long Last();
	}

}

#endif !ENGINE_H