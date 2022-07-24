#pragma once
#include <string_view>

template <typename T>
constexpr auto type_name();

#define get_type(x) type_name<decltype(x)>()