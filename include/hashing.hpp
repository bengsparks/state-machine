#pragma once

#include <string>

namespace sm_ns {

class state;
class event;
class transition;

} // namespace sm_ns
namespace std {

template <>
struct hash<sm_ns::event> {
	auto operator()(const sm_ns::event& e) const noexcept -> std::size_t;
};

template <>
struct hash<sm_ns::state> {
	auto operator()(const sm_ns::state& s) const noexcept -> std::size_t;
};

template <>
struct hash<sm_ns::transition> {
	auto operator()(const sm_ns::transition& s) const noexcept -> std::size_t;
};

} // namespace std