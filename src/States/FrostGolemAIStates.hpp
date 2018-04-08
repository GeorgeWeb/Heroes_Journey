#ifndef FROST_GOLEM_AI_STATES
#define FROST_GOLEM_AI_STATES

#include "../Components/StateMachineComponent.hpp"
#include "../Entities/Hero.hpp"

#include <vector>

namespace HJ { namespace States {

	using namespace Engine;
	
	class FrostGolemWaitState final : public State
	{
		public:
			FrostGolemWaitState() = default;
			void EnterState(ECM::Entity* t_owner) override;
			void Execute(ECM::Entity* t_owner, float t_deltaTime) override {};
	};

	class FrostGolemStepInState final : public State
	{
		public:
			FrostGolemStepInState(sf::Vector2f t_position, float t_speed)
				: m_position(t_position), m_speed(t_speed), m_canStepIn(false) {}
			void EnterState(ECM::Entity* t_owner) override;
			void Execute(ECM::Entity* t_owner, float t_deltaTime) override;

		private:
			sf::Vector2f m_position;
			float m_speed;
			bool m_canStepIn;
	};

	class FrostGolemReturnState final : public State
	{
		public:
			FrostGolemReturnState(sf::Vector2f t_position, float t_speed)
				: m_position(t_position), m_speed(t_speed), m_canReturn(false) {}
			void EnterState(ECM::Entity* t_owner) override;
			void Execute(ECM::Entity* t_owner, float t_deltaTime) override;

		private:
			sf::Vector2f m_position;
			float m_speed;
			bool m_canReturn;
	};

	class FrostGolemAttackState final : public State
	{
		public:
			FrostGolemAttackState(std::vector<std::shared_ptr<Entities::Hero>> t_heroes, unsigned int t_damage)
				: m_heroes(t_heroes), m_damage(t_damage), m_isAttacking(false) {}

			void EnterState(ECM::Entity* t_owner) override;
			void Execute(ECM::Entity* t_owner, float t_deltaTime) override;

		private:
			std::vector<std::shared_ptr<Entities::Hero>> m_heroes;
			unsigned int m_damage;
			bool m_isAttacking;
	};

} }

#endif // !FROST_GOLEM_AI_STATES