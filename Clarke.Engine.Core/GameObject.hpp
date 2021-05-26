#pragma once
#include "WorldPosition.hpp"
#include "AdvanceStateContext.hpp"
#include "GameObjectId.hpp"

namespace clarke::engine::core
{


	class GameObject
	{
		GameObject* parent_;
		WorldPosition position_;
	public:
		constexpr WorldPosition globalPosition() const noexcept;

		void advanceState(AdvanceStateContext&) const;

	};
}