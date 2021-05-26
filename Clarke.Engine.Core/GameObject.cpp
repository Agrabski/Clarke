#include "GameObject.hpp"

constexpr clarke::engine::core::WorldPosition clarke::engine::core::GameObject::globalPosition() const noexcept
{
	if (parent_ != nullptr)
		return parent_->globalPosition() + position_;
	return position_;
}
