#pragma once
#include <tuple>
#include <ostream>
#include <istream>

namespace clarke::messages
{

	//These are handy bits that go in a header somewhere
	template<class e, class t, int N>
	constexpr std::basic_istream<e, t>& operator>>(std::basic_istream<e, t>& in, const e(&sliteral)[N]) {
		e buffer[N - 1] = {}; //get buffer
		in >> buffer[0]; //skips whitespace
		if (N > 2)
			in.read(buffer + 1, N - 2); //read the rest
		if (strncmp(buffer, sliteral, N - 1)) //if it failed
			in.setstate(std::ios::failbit); //set the state
		return in;
	}
	template<class e, class t>
	constexpr std::basic_istream<e, t>& operator>>(std::basic_istream<e, t>& in, const e& cliteral) {
		e buffer(0);  //get buffer
		in >> buffer; //read data
		if (buffer != cliteral) //if it failed
			in.setstate(std::ios::failbit); //set the state
		return in;
	}
	//redirect mutable char arrays to their normal function
	template<class e, class t, int N>
	constexpr std::basic_istream<e, t>& operator>>(std::basic_istream<e, t>& in, e(&carray)[N]) {
		return std::operator>>(in, carray);
	}

	template<typename T>
	struct type_name_trait;

	template<typename T>
	concept is_tuple = requires(T a) { std::get<0>(a); };

	template<typename T>
	concept named_type = (requires() { type_name_trait<T>::name; });

	template<typename T>
	concept basic_type = requires(std::ostream & s, T & o) { s << o; }&& requires(std::istream& s, T& o) { s >> o; };

	template<basic_type T>
	constexpr std::ostream& print(std::ostream& s, T const& object)
	{
		return s << object;
	}

	template<size_t I, typename... T>
	constexpr std::ostream& print(std::ostream& s, std::tuple<T...> const& tuple)
	{
		if constexpr (I < sizeof...(T))
		{
			print<I + 1>(print(s << " ", std::get<I>(tuple)), tuple);
		}
		return s;
	}

	template<typename T>
	constexpr std::ostream& print(std::ostream& s, T const& object) requires named_type<T>&& is_tuple<T>
	{
		return print<0>(s << "(" << type_name_trait<T>::name, object) << ")";
	}
	
	template<basic_type T>
	constexpr std::istream& read(std::istream& s, T& object)
	{
		return s >> object;
	}

	template<size_t I, typename... T>
	constexpr std::istream& read(std::istream& s, std::tuple<T...>& tuple)
	{
		if constexpr (I < sizeof...(T))
		{
			read<I + 1>(read(s, std::get<I>(tuple)), tuple);
		}
		return s;
	}

	template<typename T>
	constexpr std::istream& read(std::istream& s, T& object) requires named_type<T>&& is_tuple<T>
	{
		return read<0>(s >> (const char[])"(" >> type_name_trait<T>::name, object) >> (const char[])")";
	}

}