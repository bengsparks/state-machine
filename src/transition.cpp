#include "../include/transition.hpp"

using namespace sm_ns;

// transition implementation
transition::transition(state from, state to, event trigger)
	: from{std::move(from)}
	, to{std::move(to)}
	, trigger{std::move(trigger)}
	, action_opt{std::nullopt}
{
}

transition::transition(state from,
					   state to,
					   event trigger,
					   class action callback)
	: from{std::move(from)}
	, to{std::move(to)}
	, trigger{std::move(trigger)}
	, action_opt{callback}
{
}

auto transition::operator==(transition other) const -> bool
{
	return from == other.from && to == other.to && trigger == other.trigger;
}

auto transition::operator()() const -> void
{
	if (action_opt == std::nullopt) {
		return;
	}
	std::invoke(*action_opt);
}

auto sm_ns::make_transition(std::string from,
							std::string to,
							std::string trigger) -> transition
{
	return transition{state{std::move(from)}, state{std::move(to)},
					  event{std::move(trigger)}};
}

auto sm_ns::make_transition(std::string from,
							std::string to,
							std::string trigger,
							std::function<auto(void)->void> callback)
	-> transition
{
	return transition{state{std::move(from)}, state{std::move(to)},
					  event{std::move(trigger)}, action{std::move(callback)}};
}
