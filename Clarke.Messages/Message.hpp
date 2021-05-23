#pragma once

namespace clarke::messages
{
	class IMessage
	{
	public:
		virtual ~IMessage() noexcept = 0;
	};
}
