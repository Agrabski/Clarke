#include "WorldPosition.hpp"

constexpr clarke::engine::core::WorldPosition clarke::engine::core::WorldPosition::operator+(WorldPosition const& other) const noexcept
{
	return WorldPosition(x() + other.x(), y() + other.y());
}
