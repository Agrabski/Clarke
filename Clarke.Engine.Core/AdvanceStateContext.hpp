#include "../Clarke.Messages/Message.hpp"
#include "GameObject.hpp"
#include "GameObjectId.hpp"

namespace clarke::engine::core
{
	class GameObject;
	
	class AdvanceStateContext
	{
		GameObject const* getObject(GameObjectId id) const;
		
		template<messages::message T>
		void enqueue(T&& message);

	};

}

