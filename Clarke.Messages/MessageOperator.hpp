#pragma once
#include <ostream>

template<typename T>
struct type_name_trait;

template<typename T>
concept is_tuple = requires(T a) { std::get<0>(a); }

template<typename T>
concept named_type = requires() { type_name_trait<T>::name } -> char const* const

template<typename T>
concept basic_type = requires(std::ostream & s, T & o) { s << o; }

template<size_t I, typename... T>
std::ostream& print(std::ostream& s, std::tuple<T...> const& tuple)
{
	if constexpr (I < sizeof...(T))
	{
		print<I+1>(print(s << " ", std::get<I>(tuple)), tuple);
	}
	return s;
}

template<typename T>
std::ostream& print(std::ostream& s, T const& object) requires named_type<T>&& is_tuple<T>
{
	return print<0>(s << "(" << type_name_trait<T>::name << " ", object) << ")";
}

template<basic_type T>
std::ostream& print(std::ostream& s, T const& object)
{
	return s << object;
}
