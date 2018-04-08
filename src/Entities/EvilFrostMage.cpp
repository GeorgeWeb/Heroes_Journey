#include "EvilFrostMage.hpp"

namespace HJ { namespace Entities {

	EvilFrostMage::EvilFrostMage() : EvilAI()
	{
		m_health = 150;
		m_maxHealth = 150;
		m_mana = 75;
		m_maxMana = 75;
		m_armour = 20;
		m_damage = 50;
		m_dodgeChance = 2;
		m_critChance = 3;
	}

	EvilFrostMage* EvilFrostMage::GetType()
	{
		return this;
	}

	void EvilFrostMage::Init()
	{
		EvilAI::Init();
	}

	void EvilFrostMage::Update(float t_deltaTime)
	{
		EvilAI::Update(t_deltaTime);
	}

	void EvilFrostMage::Render()
	{
		EvilAI::Render();
	}

} }