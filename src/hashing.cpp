#include "../include/hashing.hpp"

#include "../include/event.hpp"
#include "../include/state.hpp"
#include "../include/transition.hpp"

using namespace sm_ns;

auto std::hash<event>::operator()(const event& e) const noexcept -> std::size_t
{
	return std::hash<std::string>()(e.name);
}

auto std::hash<state>::operator()(const state& s) const noexcept -> std::size_t
{
	return std::hash<std::string>()(s.name);
}

auto std::hash<transition>::operator()(const transition& t) const noexcept -> std::size_t
{
	return 	std::hash<state>()(t.from) +
	        std::hash<state>()(t.to) +
			std::hash<event>()(t.trigger);
}
