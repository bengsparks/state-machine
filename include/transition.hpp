#pragma once

#include "action.hpp"
#include "event.hpp"
#include "state.hpp"

namespace sm_ns {

class transition {
  public:
	// constructors
	transition() = delete;

	transition(state, state, event);
	transition(state, state, event, action);

	auto operator==(transition other) const -> bool;
	auto operator()() const -> void;

	state from, to;
	event trigger;

	std::optional<action> action_opt;
};

auto make_transition(std::string, std::string, std::string) -> transition;

auto make_transition(std::string from,
					 std::string to,
					 std::string trigger,
					 std::function<auto(void)->void> callback) -> transition;

} // namespace sm_ns
