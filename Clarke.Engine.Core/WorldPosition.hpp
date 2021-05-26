#pragma once
#include <tuple>
#include "../Clarke.Messages/TypeNameTrait.hpp"
#include "../Clarke.Messages/TypeProperties.hpp"

namespace clarke::engine::core
{
	struct WorldPosition : public std::tuple<int, int>
	{
		VALUE_CONSTRUCTORS();

		PROPERTY(x, 0);
		PROPERTY(y, 1);
		constexpr WorldPosition operator+(WorldPosition const& other) const noexcept;
	};
}

REGISTER_NAME(clarke::engine::core, WorldPosition);
