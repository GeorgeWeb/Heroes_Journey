#include "CastleInterior.hpp"
#include "PauseMenu.hpp"

namespace HJ {

	using namespace Engine;
	using namespace System;
	using namespace Engine::ECM;
	using namespace Engine::Components;
	using namespace HJ::Entities;

	CastleScene::CastleScene(GameDataRef t_data) : 
		m_data(t_data)
	{ }

	void CastleScene::Init()
	{
		m_data->assets.LoadTexture("Tex_CastleBG", CASTLE_SCENE_BACKGROUD);
		m_data->assets.LoadTexture("Tex_Infirmary", CASTLE_SCENE_INFIRMARY);
		m_data->assets.LoadTexture("Tex_Blacksmith", CASTLE_SCENE_BLACKSMITH);
		m_data->assets.LoadTexture("Tex_Library", CASTLE_SCENE_LIBRARY);
		m_data->assets.LoadTexture("Tex_Inn", CASTLE_SCENE_INN);
		m_data->assets.LoadTexture("Tex_GeneralStore", CASTLE_SCENE_GENERAL_STORE);
		m_data->assets.LoadTexture("Tex_BackArrow", CASTLE_SCENE_BACK_ARROW);
		m_data->assets.LoadTexture("Tex_UiFrame", CASTLE_SCENE_UI_FRAME);
		m_data->assets.LoadTexture("Tex_UpgradeBtn", CASTLE_SCENE_UPGRADE_BUTTON);
		m_data->assets.LoadTexture("Tex_Health", HP_POT_ICON);
		m_data->assets.LoadTexture("Tex_Mana", MANA_POT_ICON);
		m_data->assets.LoadTexture("Tex_Coin", COIN_ICON);
		m_data->assets.LoadTexture("Tex_ManaBtn", CASTLE_SCENE_MANABTN);
		m_data->assets.LoadTexture("Tex_HealthBtn", CASTLE_SCENE_HEALTHBTN);

		// background
		auto bg = std::make_shared<Entity>();
		auto bgSprite = bg->AddComponent<SpriteComponent>("C_CastleBGSprite");
		// define
		bgSprite->GetSprite().setTexture(m_data->assets.GetTexture("Tex_CastleBG"));
		bgSprite->GetSprite().setColor(sf::Color(255, 255, 255, 255));
		// properties
		//bgSprite->GetSprite().scale(1, 0.96f);
		bg->SetPosition(sf::Vector2f(0.0f, 0.0f));
		bg->SetVisible(true);
		bg->SetAlive(true);

		//UI frame for buildings
		auto fr = std::make_shared<Entity>();
		auto frSprite = fr->AddComponent<SpriteComponent>("C_FrameSprite");
		//init data
		frSprite->GetSprite().setTexture(m_data->assets.GetTexture("Tex_UiFrame"));
		frSprite->GetSprite().setColor(sf::Color(255, 255, 255, 255));
		//properties
		fr->SetPosition(sf::Vector2f(0.0f, SCREEN_HEIGHT - frSprite->GetSprite().getGlobalBounds().height));
		fr->SetVisible(true);
		fr->SetAlive(true);
		fr->Init();

		// infirmary
		m_infirmary = std::make_shared<Infirmary>("C_InfirmarySprite");
		// initialize data
		m_infirmary->SetSprite(m_data->assets.GetTexture("Tex_Infirmary"));
		// more properties
		m_infirmary->SetPosition(sf::Vector2f((SCREEN_WIDTH - m_infirmary->GetComponent<SpriteComponent>("C_InfirmarySprite")->GetSprite().getGlobalBounds().width) * 0.1f,
			(SCREEN_HEIGHT - m_infirmary->GetComponent<SpriteComponent>("C_InfirmarySprite")->GetSprite().getGlobalBounds().height) * 0.7));
		m_infirmary->Init();

		// blacksmith
		m_blacksmith = std::make_shared<Blacksmith>("C_BlacksmithSprite");
		// initialize data
		m_blacksmith->SetSprite(m_data->assets.GetTexture("Tex_Blacksmith"));
		// more properties
		m_blacksmith->SetPosition(sf::Vector2f((SCREEN_WIDTH - m_blacksmith->GetComponent<SpriteComponent>("C_BlacksmithSprite")->GetSprite().getGlobalBounds().width) * 0.15f,
			(SCREEN_HEIGHT - m_blacksmith->GetComponent<SpriteComponent>("C_BlacksmithSprite")->GetSprite().getGlobalBounds().height) * 0.35));
		m_blacksmith->Init();

		// Library
		m_library = std::make_shared<Library>("C_LibrarySprite");
		// initialize data
		m_library->SetSprite(m_data->assets.GetTexture("Tex_Library"));
		// more properties
		m_library->SetPosition(sf::Vector2f((SCREEN_WIDTH - m_library->GetComponent<SpriteComponent>("C_LibrarySprite")->GetSprite().getGlobalBounds().width) * 0.5f,
			(SCREEN_HEIGHT - m_library->GetComponent<SpriteComponent>("C_LibrarySprite")->GetSprite().getGlobalBounds().height) * 0.2));
		m_library->Init();

		// Inn
		m_inn = std::make_shared<Inn>("C_InnSprite");
		// initialize data
		m_inn->SetSprite(m_data->assets.GetTexture("Tex_Inn"));
		// more properties
		m_inn->SetPosition(sf::Vector2f((SCREEN_WIDTH - m_inn->GetComponent<SpriteComponent>("C_InnSprite")->GetSprite().getGlobalBounds().width) * 0.8f,
			(SCREEN_HEIGHT - m_inn->GetComponent<SpriteComponent>("C_InnSprite")->GetSprite().getGlobalBounds().height) * 0.3));
		m_inn->Init();

		// General Store
		m_generalStore = std::make_shared<GeneralStore>("C_GeneralStore");
		// initialize data
		m_generalStore->SetSprite(m_data->assets.GetTexture("Tex_GeneralStore"));
		// more properties
		m_generalStore->SetPosition(sf::Vector2f((SCREEN_WIDTH - m_generalStore->GetComponent<SpriteComponent>("C_GeneralStore")->GetSprite().getGlobalBounds().width) * 0.85f,
			(SCREEN_HEIGHT - m_generalStore->GetComponent<SpriteComponent>("C_GeneralStore")->GetSprite().getGlobalBounds().height) * 0.6));
		m_generalStore->Init();

		// backArrow
		auto backArrow = std::make_shared<Entity>();
		auto backArrowSprite = backArrow->AddComponent<SpriteComponent>("C_BackArrow");		
		// define backArrow sprite
		backArrowSprite->GetSprite().setTexture(m_data->assets.GetTexture("Tex_BackArrow"));
		backArrowSprite->GetSprite().setColor(sf::Color(255, 255, 255, 255));
		// backArrow properties
		backArrow->SetPosition(sf::Vector2f((SCREEN_WIDTH - backArrowSprite->GetSprite().getGlobalBounds().width) * 0.05, 
			(SCREEN_HEIGHT - backArrowSprite->GetSprite().getGlobalBounds().height) * 0.01));
		backArrow->SetVisible(true);
		backArrow->SetAlive(true);

		//upgrade button
		auto upgradeBtn = std::make_shared<Entity>();
		auto upgradeBtnSprite = upgradeBtn->AddComponent<SpriteComponent>("C_UpgradeBtn");
		//define sprite
		upgradeBtnSprite->GetSprite().setTexture(m_data->assets.GetTexture("Tex_UpgradeBtn"));
		upgradeBtnSprite->GetSprite().setColor(sf::Color(255, 255, 255, 255));
		upgradeBtn->SetPosition(sf::Vector2f(upgradeBtnSprite->GetSprite().getGlobalBounds().width + 40.0f, SCREEN_HEIGHT - upgradeBtnSprite->GetSprite().getGlobalBounds().height - 80.0f));
		//properties
		upgradeBtn->SetVisible(false);
		upgradeBtn->SetAlive(false);

		//Health potion sprite
		auto health = std::make_shared<Entity>();
		auto healthSprite = health->AddComponent<SpriteComponent>("C_Health");
		//sprite define
		healthSprite->GetSprite().setTexture(m_data->assets.GetTexture("Tex_Health"));
		healthSprite->GetSprite().setColor(sf::Color(255, 255, 255, 255));
		health->SetPosition(sf::Vector2f(SCREEN_WIDTH - SCREEN_WIDTH * 0.3, SCREEN_HEIGHT - SCREEN_HEIGHT * 0.3));
		//properties
		health->SetVisible(true);
		health->SetAlive(true);

		// Text for health
		auto textHp = std::make_shared<Entity>();
		auto hpTextFont = textHp->AddComponent<TextComponent>("C_HpText");
		// define
		hpTextFont->SetFont(m_data->assets.GetFont("Font_Pixel"));
		hpTextFont->GetText().setCharacterSize(14);
		textHp->SetPosition(sf::Vector2f(sf::Vector2f(SCREEN_WIDTH - SCREEN_WIDTH * 0.3 + 30, SCREEN_HEIGHT - SCREEN_HEIGHT * 0.3+15)));
		// properties
		textHp->showOnCreate = true;
		textHp->SetVisible(true);
		textHp->SetAlive(true);
		textHp->Init();
		hpTextFont->GetText().setCharacterSize(10);
		
		//Mana potion sprite
		auto mana = std::make_shared<Entity>();
		auto manaSprite = mana->AddComponent<SpriteComponent>("C_Mana");
		//sprite define
		manaSprite->GetSprite().setTexture(m_data->assets.GetTexture("Tex_Mana"));
		manaSprite->GetSprite().setColor(sf::Color(255, 255, 255, 255));
		mana->SetPosition(sf::Vector2f(SCREEN_WIDTH - SCREEN_WIDTH * 0.23, SCREEN_HEIGHT - SCREEN_HEIGHT * 0.3));
		//properties
		mana->SetVisible(true);
		mana->SetAlive(true);

		// Text for mana
		auto textMn = std::make_shared<Entity>();
		auto mnTextFont = textMn->AddComponent<TextComponent>("C_MnText");
		// define
		mnTextFont->SetFont(m_data->assets.GetFont("Font_Pixel"));
		mnTextFont->GetText().setCharacterSize(14);
		textMn->SetPosition(sf::Vector2f(sf::Vector2f(SCREEN_WIDTH - SCREEN_WIDTH * 0.23+30, SCREEN_HEIGHT - SCREEN_HEIGHT * 0.3 + 15)));
		// properties
		textMn->showOnCreate = true;
		textMn->SetVisible(true);
		textMn->SetAlive(true);
		textMn->Init();
		mnTextFont->GetText().setCharacterSize(10);
		
		//Coin sprite
		auto coin = std::make_shared<Entity>();
		auto coinSprite = coin->AddComponent<SpriteComponent>("C_Coin");
		//sprite define
		coinSprite->GetSprite().setTexture(m_data->assets.GetTexture("Tex_Coin"));
		coinSprite->GetSprite().setColor(sf::Color(255, 255, 255, 255));
		coin->SetPosition(sf::Vector2f(SCREEN_WIDTH - SCREEN_WIDTH * 0.16, SCREEN_HEIGHT - SCREEN_HEIGHT * 0.3));
		//properties
		coin->SetVisible(true);
		coin->SetAlive(true);

		// Text for coin
		auto textCoin = std::make_shared<Entity>();
		auto coinTextFont = textCoin->AddComponent<TextComponent>("C_CoinText");
		// define
		coinTextFont->SetFont(m_data->assets.GetFont("Font_Pixel"));
		coinTextFont->GetText().setCharacterSize(14);
		textCoin->SetPosition(sf::Vector2f(sf::Vector2f(SCREEN_WIDTH - SCREEN_WIDTH * 0.16 +30, SCREEN_HEIGHT - SCREEN_HEIGHT * 0.3 + 15)));
		// properties
		textCoin->showOnCreate = true;
		textCoin->SetVisible(true);
		textCoin->SetAlive(true);
		textCoin->Init();
		coinTextFont->GetText().setCharacterSize(10);

		//mana button texture
		auto manaBtn = std::make_shared<Entity>();
		auto manaBtnSprite = manaBtn->AddComponent<SpriteComponent>("C_ManaBtnSprite");
		//sprite define
		manaBtnSprite->GetSprite().setTexture(m_data->assets.GetTexture("Tex_ManaBtn"));
		manaBtnSprite->GetSprite().setColor(sf::Color(255, 255, 255, 255));
		manaBtn->SetPosition(sf::Vector2f(SCREEN_WIDTH - manaBtnSprite->GetSprite().getGlobalBounds().width * 2.5, SCREEN_HEIGHT - manaBtnSprite->GetSprite().getGlobalBounds().height*1.3));
		//properties
		manaBtn->SetVisible(false);
		manaBtn->SetAlive(true);

		//health button texture
		auto healthBtn = std::make_shared<Entity>();
		auto healthBtnSprite = healthBtn->AddComponent<SpriteComponent>("C_HealthBtnSprite");
		//sprite define
		healthBtnSprite->GetSprite().setTexture(m_data->assets.GetTexture("Tex_HealthBtn"));
		healthBtnSprite->GetSprite().setColor(sf::Color(255, 255, 255, 255));
		healthBtn->SetPosition(sf::Vector2f(SCREEN_WIDTH - healthBtnSprite->GetSprite().getGlobalBounds().width *3.7f , SCREEN_HEIGHT - healthBtnSprite->GetSprite().getGlobalBounds().height*1.3));
		//properties
		healthBtn->SetVisible(false);
		healthBtn->SetAlive(true);
		

		// Text
		auto text = std::make_shared<Entity>();
		auto infTextFont = text->AddComponent<TextComponent>("C_Text");
		// define
		infTextFont->SetFont(m_data->assets.GetFont("Font_Pixel"));
		infTextFont->GetText().setCharacterSize(14);		
		text->SetPosition(sf::Vector2f(infTextFont->GetText().getGlobalBounds().width + 10.0f, SCREEN_HEIGHT - infTextFont->GetText().getGlobalBounds().height - 180.0f));
		// properties
		text->showOnCreate = false;
		text->SetVisible(false);
		text->SetAlive(true);
		text->Init();

		// Text 2
		auto text2 = std::make_shared<Entity>();
		auto infTextFont2 = text2->AddComponent<TextComponent>("C_Text2");
		// define
		infTextFont2->SetFont(m_data->assets.GetFont("Font_Pixel"));
		infTextFont2->GetText().setCharacterSize(14);
		text2->SetPosition(sf::Vector2f(infTextFont2->GetText().getGlobalBounds().width + 20.0f, SCREEN_HEIGHT - infTextFont2->GetText().getGlobalBounds().height - 120.0f));
		// properties
		text2->showOnCreate = false;
		text2->SetVisible(false);
		text2->SetAlive(true);
		text2->Init();

		// Text 3
		auto text3 = std::make_shared<Entity>();
		auto infTextFont3 = text3->AddComponent<TextComponent>("C_Text3");
		// define
		infTextFont3->SetFont(m_data->assets.GetFont("Font_Pixel"));
		infTextFont3->GetText().setCharacterSize(14);
		text3->SetPosition(sf::Vector2f(infTextFont3->GetText().getGlobalBounds().width + 20.0f, SCREEN_HEIGHT - infTextFont3->GetText().getGlobalBounds().height -50.0f));
		// properties
		text3->showOnCreate = false;
		text3->SetVisible(false);
		text3->SetAlive(true);
		text3->Init();

		// Text 4
		auto text4 = std::make_shared<Entity>();
		auto infTextFont4 = text4->AddComponent<TextComponent>("C_Text4");
		// define
		infTextFont4->SetFont(m_data->assets.GetFont("Font_Pixel"));
		infTextFont4->GetText().setCharacterSize(14);
		text4->SetPosition(sf::Vector2f(infTextFont4->GetText().getGlobalBounds().width+ 240.0f, SCREEN_HEIGHT - infTextFont4->GetText().getGlobalBounds().height - 50.0f));
		// properties
		text4->showOnCreate = false;
		text4->SetVisible(false);
		text4->SetAlive(true);
		text4->Init();

		// Text 5
		auto text5 = std::make_shared<Entity>();
		auto infTextFont5 = text5->AddComponent<TextComponent>("C_Text5");
		// define
		infTextFont5->SetFont(m_data->assets.GetFont("Font_Pixel"));
		infTextFont5->GetText().setCharacterSize(14);
		text5->SetPosition(sf::Vector2f(upgradeBtnSprite->GetSprite().getGlobalBounds().width + 100.0f, SCREEN_HEIGHT - upgradeBtnSprite->GetSprite().getGlobalBounds().height ));
		// properties
		text5->showOnCreate = false;
		text5->SetVisible(false);
		text5->SetAlive(true);
		text5->Init();
		
		

		AddEntity("E_zCastleBG", bg);
		AddEntity("E_Blacksmith", m_blacksmith);
		AddEntity("E_Infirmary", m_infirmary);
		AddEntity("E_Library", m_library);
		AddEntity("E_Inn", m_inn);
		AddEntity("E_GeneralStore", m_generalStore);
		AddEntity("E_BackArrow", backArrow);
		AddEntity("E_00Text", text);
		AddEntity("E_00Text2", text2);
		AddEntity("E_00Text3", text3);
		AddEntity("E_00Text4", text4);
		AddEntity("E_00Text5", text5);
		AddEntity("E_00UpBtn", upgradeBtn);
		AddEntity("E_0Frame", fr);
		AddEntity("E_Health", health);
		AddEntity("E_Mana", mana);
		AddEntity("E_Coin", coin);
		AddEntity("E_HpText", textHp);
		AddEntity("E_MnText", textMn);
		AddEntity("E_CoinText", textCoin);
		AddEntity("E_00HealthBtn", healthBtn);
		AddEntity("E_00ManaBtn", manaBtn);
		
	}

	void CastleScene::HandleInput()
	{
		sf::Event event;

		while (Renderer::GetWin().pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				Renderer::GetWin().close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
			{
				// Switch scenes (to Pause Menu)
				auto pauseMenuState = std::make_unique<PauseMenuScene>(PauseMenuScene(m_data));
				m_data->machine.AddState(std::move(pauseMenuState), false);
			}

			//Check if infirmary is clicked
			auto infComp = m_infirmary->GetComponent<SpriteComponent>("C_InfirmarySprite");
			if (m_data->input.isClicked(infComp->GetSprite(), sf::Mouse::Left, Renderer::GetWin()))
			{
				m_infirmary->isClicked = true;
			

				//set last clicked building as infirmary
				lastClicked = "infirmary";
			}

			//Check if Blacksmith is clicked
			auto blacksmithComp = m_blacksmith->GetComponent<SpriteComponent>("C_BlacksmithSprite");
			if (m_data->input.isClicked(blacksmithComp->GetSprite(), sf::Mouse::Left, Renderer::GetWin()))
			{
				m_blacksmith->isClicked = true;
				lastClicked = "blacksmith";
			}

			//Check if Library is clicked
			auto libraryComp = m_library->GetComponent<SpriteComponent>("C_LibrarySprite");
			if (m_data->input.isClicked(libraryComp->GetSprite(), sf::Mouse::Left, Renderer::GetWin()))
			{
				m_library->isClicked = true;
				lastClicked = "library";
			}

			//Check if Inn is clicked
			auto innComp = m_inn->GetComponent<SpriteComponent>("C_InnSprite");
			if (m_data->input.isClicked(innComp->GetSprite(), sf::Mouse::Left, Renderer::GetWin()))
			{
				m_inn->isClicked = true;
				lastClicked = "inn";
			}

			//Check if GeneralStore is clicked
			auto genStoreComp = m_generalStore->GetComponent<SpriteComponent>("C_GeneralStore");
			if (m_data->input.isClicked(genStoreComp->GetSprite(), sf::Mouse::Left, Renderer::GetWin()))
			{
				m_generalStore->isClicked = true;
				lastClicked = "generalStore";
			}

			//check if back arrow is clicked
			auto arrowComp = m_data->ents.Find<Entity>("E_BackArrow")->GetComponent<SpriteComponent>("C_BackArrow");
			if (m_data->input.isClicked(arrowComp->GetSprite(), sf::Mouse::Left, Renderer::GetWin()))
			{
				m_arrowClick = true;
			}

			//check if upgrade button is clicked
			auto upBtnComp = m_data->ents.Find<Entity>("E_00UpBtn")->GetComponent<SpriteComponent>("C_UpgradeBtn");
			if (m_data->input.isClicked(upBtnComp->GetSprite(), sf::Mouse::Left, Renderer::GetWin()))
			{
				m_buttonClick = true;
				if (lastClicked == "infirmary")
				{
					m_data->gm.gold -= 10 * m_infirmary->GetLevel();
					m_infirmary->Upgrade();
					std::cout << "Infirmary found!" << std::endl;
				}

				else if (lastClicked == "blacksmith")
				{
					m_data->gm.gold -= 10 * m_blacksmith->GetLevel();
					m_blacksmith->Upgrade();
					std::cout << "Blacksmith found!" << std::endl;
				}

				else if (lastClicked == "library")
				{
					m_data->gm.gold -= 10 * m_library->GetLevel();
					m_library->Upgrade();
					std::cout << "Library found!" << std::endl;
				}

				else if (lastClicked == "inn")
				{
					m_data->gm.gold -= 10 * m_inn->GetLevel();
					m_inn->Upgrade();
					std::cout << "Inn found!" << std::endl;
				}
			}

			// check if mana button has been clicked
			auto manaComp = m_data->ents.Find<Entity>("E_00ManaBtn")->GetComponent < SpriteComponent>("C_ManaBtnSprite");
			if (m_data->input.isClicked(manaComp->GetSprite(), sf::Mouse::Left, Renderer::GetWin()))
			{
				m_buyMana = true;
				m_data->gm.gold -= 10 ;
				m_data->gm.manaPot += 1;
			}

			//check if health button has been clicked
			auto healthComp = m_data->ents.Find<Entity>("E_00HealthBtn")->GetComponent < SpriteComponent>("C_HealthBtnSprite");
			if (m_data->input.isClicked(healthComp->GetSprite(), sf::Mouse::Left, Renderer::GetWin()))
			{
				m_buyHealth = true;
				m_data->gm.gold -= 10;
				m_data->gm.healthPot += 1;
			}

		}
	}

	void CastleScene::Update(float t_delatTime)
	{

		UpdateText();

		UpdateResourceText();
		//Handle the back arrow click
		auto arrowComp = m_data->ents.Find<Entity>("E_BackArrow")->GetComponent<SpriteComponent>("C_BackArrow");

		if (m_arrowClick && !m_arrowUnClick)
		{
			arrowComp->GetSprite().setColor(sf::Color(arrowComp->GetSprite().getColor().r - 100,
				arrowComp->GetSprite().getColor().g - 100,
				arrowComp->GetSprite().getColor().b - 100,
				arrowComp->GetSprite().getColor().a));
			m_arrowUnClick = true;
		}

		if (m_arrowUnClick)
		{
			m_time -= t_delatTime;
		}
		
		if (m_time < 0.0f && m_arrowUnClick)
		{
			arrowComp->GetSprite().setColor(sf::Color(arrowComp->GetSprite().getColor().r + 100,
				arrowComp->GetSprite().getColor().g + 100,
				arrowComp->GetSprite().getColor().b + 100,
				arrowComp->GetSprite().getColor().a));

			m_time = 0.1f;
			m_arrowUnClick = false;
			m_arrowClick = false;

			// go back to map scene
			m_data->machine.RemoveState();
		}

		//Handle the Upgrade button click
		auto upBtnComp = m_data->ents.Find<Entity>("E_00UpBtn")->GetComponent<SpriteComponent>("C_UpgradeBtn");
		if (m_buttonClick && !m_buttonUnClick)
		{
			upBtnComp->GetSprite().setColor(sf::Color(upBtnComp->GetSprite().getColor().r - 100,
				upBtnComp->GetSprite().getColor().g - 100,
				upBtnComp->GetSprite().getColor().b - 100,
				upBtnComp->GetSprite().getColor().a));
			m_buttonUnClick  = true;
		}

		if (m_buttonUnClick)
		{
			m_time -= t_delatTime;
		}

		if (m_time < 0.0f && m_buttonUnClick)
		{
			upBtnComp->GetSprite().setColor(sf::Color(upBtnComp->GetSprite().getColor().r + 100,
				upBtnComp->GetSprite().getColor().g + 100,
				upBtnComp->GetSprite().getColor().b + 100,
				upBtnComp->GetSprite().getColor().a));

			m_time = 0.1f;
			m_buttonUnClick = false;
			m_buttonClick = false;

		
		}

		//Handle the ManaPotion button click
		auto manaComp = m_data->ents.Find<Entity>("E_00ManaBtn")->GetComponent < SpriteComponent>("C_ManaBtnSprite");
		if (m_buyMana && !m_buyManaUn)
		{
			manaComp->GetSprite().setColor(sf::Color(manaComp->GetSprite().getColor().r - 100,
				manaComp->GetSprite().getColor().g - 100,
				manaComp->GetSprite().getColor().b - 100,
				manaComp->GetSprite().getColor().a));
			m_buyManaUn = true;
		}

		if (m_buyManaUn)
		{
			m_time -= t_delatTime;
		}

		if (m_time < 0.0f && m_buyManaUn)
		{
			manaComp->GetSprite().setColor(sf::Color(manaComp->GetSprite().getColor().r + 100,
				manaComp->GetSprite().getColor().g + 100,
				manaComp->GetSprite().getColor().b + 100,
				manaComp->GetSprite().getColor().a));

			m_time = 0.1f;
			m_buyManaUn = false;
			m_buyMana = false;


		}

		//Handle the Health Potion button click
		auto healthComp = m_data->ents.Find<Entity>("E_00HealthBtn")->GetComponent < SpriteComponent>("C_HealthBtnSprite");
		if (m_buyHealth && !m_buyHealthUn)
		{
			healthComp->GetSprite().setColor(sf::Color(healthComp->GetSprite().getColor().r - 100,
				healthComp->GetSprite().getColor().g - 100,
				healthComp->GetSprite().getColor().b - 100,
				upBtnComp->GetSprite().getColor().a));
			m_buyHealthUn = true;
		}

		if (m_buyHealthUn)
		{
			m_time -= t_delatTime;
		}

		if (m_time < 0.0f && m_buyHealthUn)
		{
			healthComp->GetSprite().setColor(sf::Color(healthComp->GetSprite().getColor().r + 100,
				healthComp->GetSprite().getColor().g + 100,
				healthComp->GetSprite().getColor().b + 100,
				healthComp->GetSprite().getColor().a));

			m_time = 0.1f;
			m_buyHealthUn = false;
			m_buyHealth = false;


		}

		m_data->ents.Update(m_entities, t_delatTime);
	}

	void CastleScene::Draw(float t_deltaTime)
	{
		m_data->ents.Render(m_entities);
	}

	

	void CastleScene::AddEntity(const std::string& t_name, std::shared_ptr<Entity> t_entity)
	{
		State::AddEntity(t_name, t_entity);
		// Add to global entities container
		m_data->ents.Save(t_name, t_entity);
	}

	void CastleScene::UpdateText()
	{
		if (lastClicked == "infirmary")
		{
			m_data->ents.Find<Entity>("E_00Text")->GetComponent<TextComponent>("C_Text")->GetText().setString("INFIRMARY ");
			m_data->ents.Find<Entity>("E_00Text")->SetVisible(true);


			m_data->ents.Find<Entity>("E_00Text2")->GetComponent<TextComponent>("C_Text2")->GetText().setString(" Level: " + std::to_string(m_infirmary->GetLevel()));
			m_data->ents.Find<Entity>("E_00Text2")->SetVisible(true);

			m_data->ents.Find<Entity>("E_00Text3")->GetComponent<TextComponent>("C_Text3")->GetText().setString(" Bonus HP: " + std::to_string(m_infirmary->GetLevel() *10));
			m_data->ents.Find<Entity>("E_00Text3")->SetVisible(true);

			m_data->ents.Find<Entity>("E_00Text4")->GetComponent<TextComponent>("C_Text4")->GetText().setString(" Next Level Bonus : " + std::to_string((m_infirmary->GetLevel() + 1) * 10));
			m_data->ents.Find<Entity>("E_00Text4")->SetVisible(true);

			m_data->ents.Find<Entity>("E_00Text5")->GetComponent<TextComponent>("C_Text5")->GetText().setString("(cost: " + std::to_string(m_infirmary->GetLevel()*10)+ " )");
			m_data->ents.Find<Entity>("E_00Text5")->SetVisible(true);

			m_data->ents.Find<Entity>("E_00UpBtn")->SetVisible(true);
			m_data->ents.Find<Entity>("E_00UpBtn")->SetAlive(true);

			m_data->ents.Find<Entity>("E_00HealthBtn")->SetVisible(false);
			m_data->ents.Find<Entity>("E_00ManaBtn")->SetVisible(false);
		}

		if (lastClicked == "blacksmith")
		{
			m_data->ents.Find<Entity>("E_00Text")->GetComponent<TextComponent>("C_Text")->GetText().setString("BLACKSMITH ");
			m_data->ents.Find<Entity>("E_00Text")->SetVisible(true);


			m_data->ents.Find<Entity>("E_00Text2")->GetComponent<TextComponent>("C_Text2")->GetText().setString(" Level: " + std::to_string(m_blacksmith->GetLevel()));
			m_data->ents.Find<Entity>("E_00Text2")->SetVisible(true);

			m_data->ents.Find<Entity>("E_00Text3")->GetComponent<TextComponent>("C_Text3")->GetText().setString(" Bonus ATK: " + std::to_string(m_blacksmith->GetBonus()));
			m_data->ents.Find<Entity>("E_00Text3")->SetVisible(true);

			m_data->ents.Find<Entity>("E_00Text4")->GetComponent<TextComponent>("C_Text4")->GetText().setString(" Next Level Bonus : " + std::to_string((m_blacksmith->GetLevel() + 1) * 10));
			m_data->ents.Find<Entity>("E_00Text4")->SetVisible(true);

			m_data->ents.Find<Entity>("E_00Text5")->GetComponent<TextComponent>("C_Text5")->GetText().setString("(cost: " + std::to_string(m_blacksmith->GetLevel() * 10) + " )");
			m_data->ents.Find<Entity>("E_00Text5")->SetVisible(true);

			m_data->ents.Find<Entity>("E_00UpBtn")->SetVisible(true);
			m_data->ents.Find<Entity>("E_00UpBtn")->SetAlive(true);

			m_data->ents.Find<Entity>("E_00HealthBtn")->SetVisible(false);
			m_data->ents.Find<Entity>("E_00ManaBtn")->SetVisible(false);
		}

		if (lastClicked == "library")
		{
			m_data->ents.Find<Entity>("E_00Text")->GetComponent<TextComponent>("C_Text")->GetText().setString("LIBRARY ");
			m_data->ents.Find<Entity>("E_00Text")->SetVisible(true);


			m_data->ents.Find<Entity>("E_00Text2")->GetComponent<TextComponent>("C_Text2")->GetText().setString(" Level: " + std::to_string(m_library ->GetLevel()));
			m_data->ents.Find<Entity>("E_00Text2")->SetVisible(true);

			m_data->ents.Find<Entity>("E_00Text3")->GetComponent<TextComponent>("C_Text3")->GetText().setString(" Bonus MN: " + std::to_string(m_library->GetBonus()));
			m_data->ents.Find<Entity>("E_00Text3")->SetVisible(true);

			m_data->ents.Find<Entity>("E_00Text4")->GetComponent<TextComponent>("C_Text4")->GetText().setString(" Next Level Bonus : " + std::to_string((m_library->GetLevel() + 1) * 10));
			m_data->ents.Find<Entity>("E_00Text4")->SetVisible(true);

			m_data->ents.Find<Entity>("E_00Text5")->GetComponent<TextComponent>("C_Text5")->GetText().setString("(cost: " + std::to_string(m_library->GetLevel() * 10) + " )");
			m_data->ents.Find<Entity>("E_00Text5")->SetVisible(true);

			m_data->ents.Find<Entity>("E_00UpBtn")->SetVisible(true);
			m_data->ents.Find<Entity>("E_00UpBtn")->SetAlive(true);

			m_data->ents.Find<Entity>("E_00HealthBtn")->SetVisible(false);
			m_data->ents.Find<Entity>("E_00ManaBtn")->SetVisible(false);
		}

		if (lastClicked == "inn")
		{
			m_data->ents.Find<Entity>("E_00Text")->GetComponent<TextComponent>("C_Text")->GetText().setString("Inn ");
			m_data->ents.Find<Entity>("E_00Text")->SetVisible(true);


			m_data->ents.Find<Entity>("E_00Text2")->GetComponent<TextComponent>("C_Text2")->GetText().setString(" Level: " + std::to_string(m_inn->GetLevel()));
			m_data->ents.Find<Entity>("E_00Text2")->SetVisible(true);

			m_data->ents.Find<Entity>("E_00Text3")->GetComponent<TextComponent>("C_Text3")->GetText().setString(" Bonus Recovery : " + std::to_string(m_inn->GetBonus()));
			m_data->ents.Find<Entity>("E_00Text3")->SetVisible(true);

			m_data->ents.Find<Entity>("E_00Text4")->GetComponent<TextComponent>("C_Text4")->GetText().setString(" Next Level Bonus : " + std::to_string((m_inn->GetLevel() + 1) * 10));
			m_data->ents.Find<Entity>("E_00Text4")->SetVisible(true);

			m_data->ents.Find<Entity>("E_00Text5")->GetComponent<TextComponent>("C_Text5")->GetText().setString("(cost: " + std::to_string(m_inn->GetLevel() * 10) + " )");
			m_data->ents.Find<Entity>("E_00Text5")->SetVisible(true);

			m_data->ents.Find<Entity>("E_00UpBtn")->SetVisible(true);
			m_data->ents.Find<Entity>("E_00UpBtn")->SetAlive(true);

			m_data->ents.Find<Entity>("E_00HealthBtn")->SetVisible(false);
			m_data->ents.Find<Entity>("E_00ManaBtn")->SetVisible(false);
		}

		if (lastClicked == "generalStore")
		{
			m_data->ents.Find<Entity>("E_00Text")->GetComponent<TextComponent>("C_Text")->GetText().setString("General Store ");
			m_data->ents.Find<Entity>("E_00Text")->SetVisible(true);
			m_data->ents.Find<Entity>("E_00Text2")->SetVisible(false);
			m_data->ents.Find<Entity>("E_00Text3")->SetVisible(false);
			m_data->ents.Find<Entity>("E_00Text4")->SetVisible(false);
			m_data->ents.Find<Entity>("E_00Text5")->SetVisible(false);
			m_data->ents.Find<Entity>("E_00UpBtn")->SetVisible(false);

			m_data->ents.Find<Entity>("E_00HealthBtn")->SetVisible(true);
			m_data->ents.Find<Entity>("E_00ManaBtn")->SetVisible(true);
		}
	}

	void CastleScene::UpdateResourceText()
	{ 
		m_data->ents.Find<Entity>("E_HpText")->GetComponent<TextComponent>("C_HpText")->GetText().setString("X " + std::to_string(m_data->gm.healthPot));
		m_data->ents.Find<Entity>("E_MnText")->GetComponent<TextComponent>("C_MnText")->GetText().setString("X " + std::to_string(m_data->gm.manaPot));
		m_data->ents.Find<Entity>("E_CoinText")->GetComponent<TextComponent>("C_CoinText")->GetText().setString("X " + std::to_string(m_data->gm.gold));
		
	}

}