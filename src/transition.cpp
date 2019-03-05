#include "../include/transition.hpp"

using namespace sm_ns;

// transition implementation
transition::transition(state from, state to, event trigger)
	: from{std::move(from)}, to{std::move(to)}, trigger{std::move(trigger)}
{
}

auto transition::operator==(transition other) const -> bool
{
	return from == other.from && to == other.to && trigger == other.trigger;
}

auto sm_ns::make_transition(std::string from, std::string to, std::string trigger)
	-> transition
{
	return transition{state{std::move(from)}, state{std::move(to)},
					  event{std::move(trigger)}};
}
