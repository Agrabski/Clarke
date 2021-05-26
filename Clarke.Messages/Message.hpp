#pragma once
#include <tuple>
#include <type_traits>

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
		constexpr Message(Ts const&... args) noexcept : std::tuple<Ts...>(args...) {}
		constexpr Message() noexcept = default;
	};

	template<typename T>
	concept message = std::is_base_of<IMessage, T>::value;
}
