#pragma once

namespace clarke::messages
{
	template<typename T>
	struct type_name_trait;
}
/// registers a message. MUST BE USED IN GLOBAL NAMESPACE
#define REGISTER_NAME(NAMESPACE, X) namespace clarke::messages{template<> struct type_name_trait<NAMESPACE::X> {static inline const char name[] = #X;};}
