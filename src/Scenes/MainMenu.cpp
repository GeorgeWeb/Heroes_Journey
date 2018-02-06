#include "MainMenu.hpp"
#include "MainGameMap.hpp"

#include <sstream>
#include <iostream>

namespace HJ {

	using namespace Engine;

	MainMenuScene::MainMenuScene(GameDataRef t_data)
		: m_data(t_data)
	{
		// Won't use for more initialization, hence I will use the Init() func
	}

	void MainMenuScene::Init()
	{
		// load & set background texture
		m_data->assets.LoadTexture("Main Menu Background", MAINMENU_SCENE_BACKGROUND);
		m_background.setTexture(m_data->assets.GetTexture("Main Menu Background"));

		// load & set start game button texture
		m_startBtn = std::make_shared<GUI::GUIElement>(sf::Vector2f({ 500.0f, 100.0f }));
		m_data->assets.LoadTexture("Main Menu Start Button", MAINMENU_STARTGAME_BUTTON);
		m_startBtn->SetTexture(m_data->assets.GetTexture("Main Menu Start Button"));
		m_startBtn->SetPosition({
			(SCREEN_WIDTH * .5f) - (m_startBtn->GetShape().getGlobalBounds().width * .5f),
			(SCREEN_HEIGHT * .5f) - (m_startBtn->GetShape().getGlobalBounds().height * .5f)
		});

		// load & set quit game button texture
		m_quitBtn = std::make_shared<GUI::GUIElement>(sf::Vector2f({ 300.0f, 300.0f }));
		m_data->assets.LoadTexture("Main Menu Quit Button", MAINMENU_QUITGAME_BUTTON);
		m_quitBtn->SetTexture(m_data->assets.GetTexture("Main Menu Quit Button"));
		m_quitBtn->SetPosition({ 
			(SCREEN_WIDTH * .5f) - (m_quitBtn->GetShape().getGlobalBounds().width * .5f),
			(m_startBtn->GetPosition().y) + (m_startBtn->GetShape().getGlobalBounds().height * 1.25f)
		});

		// load & set title font type
		m_data->assets.LoadFont("Main Menu Title Font", MAINMENU_TITLE_FONT);
		m_titleText.setFont(m_data->assets.GetFont("Main Menu Title Font"));
		m_titleText.setCharacterSize(72);
		m_titleText.setString("Heroes Journey");
		m_titleText.setPosition((SCREEN_WIDTH * .5f) - (m_titleText.getGlobalBounds().width * .5f), 100.0f);
	}

	void MainMenuScene::HandleInput()
	{
		sf::Event event;
		while (m_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
				m_data->window.close();

			// Quit the game screen on quitBtn left mouse click
			if (m_data->input.isClicked(m_quitBtn, sf::Mouse::Left, m_data->window))
			{
				m_data->window.close();
			}

			// Switch scenes (to Main Menu) on startBtn left mouse click
			if (m_data->input.isClicked(m_startBtn, sf::Mouse::Left, m_data->window))
			{
				// Switch scenes (to Main Game (Map))
				auto mainGameMapState = std::make_unique<MainGameMapScene>(MainGameMapScene(m_data));
				m_data->machine.AddState(std::move(mainGameMapState));
			}
		}
	}

	void MainMenuScene::Update(float t_delatTime)
	{
		// Do sth (e.g. animations)
		m_startBtn->Update(t_delatTime);
		m_quitBtn->Update(t_delatTime);
	}

	void MainMenuScene::Draw(float t_deltaTime)
	{
		m_data->window.clear();

		m_data->window.draw(m_background);
		m_data->window.draw(m_titleText);
		m_data->window.draw(m_startBtn->GetShape());
		m_data->window.draw(m_quitBtn->GetShape());

		m_data->window.display();
	}

}