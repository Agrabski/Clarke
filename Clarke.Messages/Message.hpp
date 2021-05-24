#pragma once
#include <tuple>

namespace clarke::messages
{
	class IMessage
	{
	public:
		virtual ~IMessage() noexcept = default;
	};

	template<typename... Ts>
	class Message : public IMessage, public std::tuple<Ts...> {
	protected:
		virtual ~Message() noexcept = default;
	public:
		Message(Ts const&... args) noexcept : std::tuple<Ts...>(args...) {}
		Message() noexcept = default;
	};
}
