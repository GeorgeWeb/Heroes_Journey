#ifndef SKILL_SET_H
#define SKILL_SET_H

#include "Components/StatusComponent.hpp"

namespace HJ
{
	using namespace Components;

	enum class SKILL_TARGET : int
	{
		SELF =  0,
		ALLY =  1,
		ENEMY = 2,
		ENEMY_TEAM = 3
	};

	enum class DAMAGE_BASE : int
	{
		MELEE = 0,
		RANGED = 1,
		DEFENCE = 2
	};

	enum class DAMAGE_TYPE : int
	{
		BASIC = 0,
		FROST = 1,
		FIRE = 2,
		MAGIC = 3
	};

	class Skill
	{
		public:
			Skill() = default;
			
			
			DAMAGE_BASE dmgBase;
			DAMAGE_TYPE dmgType;
			SKILL_TARGET target;

			unsigned int damageMod;

			unsigned int manaNeed = 0;

			std::string textureRefName = "";
			std::string effectDesc = "";

			std::vector<EFFECT_TYPE> applicableEffects = {};
	};

	// [BASIC/GENERAL SKILL SET]
	class BasicAttack final : public Skill
	{
		public:
			BasicAttack() : Skill()
			{
				textureRefName = "Tex_BasicAttackBtn";
				dmgBase = DAMAGE_BASE::MELEE;
				dmgType = DAMAGE_TYPE::BASIC;
				target = SKILL_TARGET::ENEMY;
				damageMod = 100;
			}
	};

	class BasicMagicAttack final : public Skill
	{
	public:
		BasicMagicAttack() : Skill()
		{
			textureRefName = "Tex_BasicAttackBtn";
			dmgBase = DAMAGE_BASE::RANGED;
			dmgType = DAMAGE_TYPE::MAGIC;
			target = SKILL_TARGET::ENEMY;
			damageMod = 100;
		}
	};

	class BasicDefence final : public Skill
	{
		public:
			BasicDefence() : Skill()
			{
				textureRefName = "Tex_DefendBtn";
				dmgBase = DAMAGE_BASE::DEFENCE;
				dmgType = DAMAGE_TYPE::BASIC;
				target = SKILL_TARGET::SELF;
				damageMod = 0;
				applicableEffects = { EFFECT_TYPE::DEFEND };
			}
	};

	/*** SPECIALIZED SKILL SETS ***/

	// [KNIGHT SKILL SET]
	class HeroicStrike final : public Skill
	{
		public:
			HeroicStrike() : Skill()
			{
				textureRefName = "Tex_TestSkillBtn";
				dmgBase = DAMAGE_BASE::MELEE;
				dmgType = DAMAGE_TYPE::BASIC;
				target = SKILL_TARGET::ENEMY;
				manaNeed = 50;
				damageMod = 200;
			}
	};

	class ShieldThrow final : public Skill
	{
		public:
			ShieldThrow() : Skill()
			{
				textureRefName = "Tex_TestSkillBtn";
				effectDesc = "Stun";
				dmgBase = DAMAGE_BASE::RANGED;
				dmgType = DAMAGE_TYPE::BASIC;
				target = SKILL_TARGET::ENEMY;
				manaNeed = 50;
				damageMod = 50;
				applicableEffects = { EFFECT_TYPE::STUN };
			}
	};

	// [BARD SKILL SET]
	class OffenseAura final : public Skill
	{
		public:
			OffenseAura() : Skill()
			{
				textureRefName = "Tex_TestSkillBtn";
				effectDesc = "Party DMG boost";
				dmgBase = DAMAGE_BASE::DEFENCE;
				dmgType = DAMAGE_TYPE::BASIC;
				target = SKILL_TARGET::ALLY;
				manaNeed = 25;
				damageMod = 0;
				applicableEffects = { EFFECT_TYPE::DAMAGE_AURA };
			}
	};

	class DeffenseAura final : public Skill
	{
		public:
			DeffenseAura() : Skill()
			{
				textureRefName = "Tex_TestSkillBtn";
				effectDesc = "Party ARM boost";
				dmgBase = DAMAGE_BASE::DEFENCE;
				dmgType = DAMAGE_TYPE::BASIC;
				target = SKILL_TARGET::ALLY;
				manaNeed = 25;
				damageMod = 0;
				applicableEffects = { EFFECT_TYPE::ARMOUR_AURA };
			}
	};
	
	// [ROGUE SKILL SET]
	class RavenBow final : public Skill
	{
		public:
			RavenBow() : Skill()
			{
				textureRefName = "Tex_TestSkillBtn";
				effectDesc = "";
				dmgBase = DAMAGE_BASE::RANGED;
				dmgType = DAMAGE_TYPE::BASIC;
				target = SKILL_TARGET::ENEMY;
				damageMod = 75;
			}
	};

	class RainOfArrows final : public Skill
	{
		public:
			RainOfArrows() : Skill()
			{
				textureRefName = "Tex_TestSkillBtn";
				effectDesc = "";
				dmgBase = DAMAGE_BASE::RANGED;
				dmgType = DAMAGE_TYPE::BASIC;
				target = SKILL_TARGET::ENEMY;
				manaNeed = 50;
				damageMod = 3 * 75;
			}
	};

	// [SORCERESS SKILL SET]
	class FireBolt final : public Skill
	{
		public:
			FireBolt() : Skill()
			{
				textureRefName = "Tex_TestSkillBtn";
				effectDesc = "";
				dmgBase = DAMAGE_BASE::RANGED;
				dmgType = DAMAGE_TYPE::FIRE;
				target = SKILL_TARGET::ENEMY;
				manaNeed = 50;
				damageMod = 200;
			}
	};

	class FrostAura final : public Skill
	{
		public:
			FrostAura() : Skill()
			{
				textureRefName = "Tex_TestSkillBtn";
				effectDesc = "Party frost resistance";
				dmgBase = DAMAGE_BASE::DEFENCE;
				dmgType = DAMAGE_TYPE::FROST;
				target = SKILL_TARGET::ALLY;
				manaNeed = 50;
				damageMod = 0;
				applicableEffects = { EFFECT_TYPE::FROST_AURA };
			}
	};
	
	// [TROLL SKILL SET]
	class Stomp final : public Skill
	{
		public:
			Stomp() : Skill()
			{
				dmgBase = DAMAGE_BASE::MELEE;
				dmgType = DAMAGE_TYPE::BASIC;
				target = SKILL_TARGET::ENEMY;
				damageMod = 50;
				applicableEffects = { EFFECT_TYPE::STUN };
			}
	};

	class Smack final : public Skill
	{
		public:
			Smack() : Skill()
			{
				dmgBase = DAMAGE_BASE::MELEE;
				dmgType = DAMAGE_TYPE::BASIC;
				target = SKILL_TARGET::ENEMY;
				damageMod = 133;
			}
	};

	class RageRawr final : public Skill
	{
		public:
			RageRawr() : Skill()
			{
				dmgBase = DAMAGE_BASE::MELEE;
				dmgType = DAMAGE_TYPE::BASIC;
				target = SKILL_TARGET::ENEMY_TEAM;
				damageMod = 100;
				applicableEffects = { EFFECT_TYPE::STUN, EFFECT_TYPE::ENRAGE };
			}
	};

	// [CYCLOP SKILL SET]
	class HeavyBoulder final : public Skill
	{
		public:
			HeavyBoulder() : Skill()
			{
				dmgBase = DAMAGE_BASE::RANGED;
				dmgType = DAMAGE_TYPE::BASIC;
				target = SKILL_TARGET::ENEMY;
				damageMod = 100;
			}
	};

	class VeryHeavyBoulder final : public Skill
	{
		public:
			VeryHeavyBoulder() : Skill()
			{
				dmgBase = DAMAGE_BASE::RANGED;
				dmgType = DAMAGE_TYPE::BASIC;
				target = SKILL_TARGET::ENEMY;
				damageMod = 90;
				applicableEffects = { EFFECT_TYPE::STUN };
			}
	};

	class Devour final : public Skill
	{
		public:
			Devour() : Skill()
			{
				dmgBase = DAMAGE_BASE::MELEE;
				dmgType = DAMAGE_TYPE::BASIC;
				target = SKILL_TARGET::ENEMY;
				damageMod = 200;
			}
	};

	// [HARPY SKILL SET]
	class IcyClaw : public Skill
	{
		public:
			IcyClaw() : Skill()
			{
				dmgBase = DAMAGE_BASE::MELEE;
				dmgType = DAMAGE_TYPE::FROST;
				target = SKILL_TARGET::ENEMY;
				damageMod = 100;
			}
	};
	
	// For rage state, the harpy will use Devour, the on that the Cyclop uses.

	// [EVIL FROST MAGE (LAST BOSS) SKILL SET]
	class FrostBolt : public Skill
	{
		public:
			FrostBolt() : Skill()
			{
				dmgBase = DAMAGE_BASE::RANGED;
				dmgType = DAMAGE_TYPE::FROST;
				target = SKILL_TARGET::ENEMY;
				damageMod = 300;
			}
	};

	class FrostRing : public Skill
	{
		public:
			FrostRing() : Skill()
			{
				dmgBase = DAMAGE_BASE::RANGED;
				dmgType = DAMAGE_TYPE::FROST;
				target = SKILL_TARGET::ENEMY;
				damageMod = 50;
				applicableEffects = { EFFECT_TYPE::STUN };
			}
	};

	class FrostArmor : public Skill
	{
		public:
			FrostArmor() : Skill()
			{
				dmgBase = DAMAGE_BASE::DEFENCE;
				dmgType = DAMAGE_TYPE::FROST;
				target = SKILL_TARGET::SELF;
				damageMod = 0;
				applicableEffects = { EFFECT_TYPE::FROST_ARMOR };
			}
	};
}

#endif // !SKILL_SET_H