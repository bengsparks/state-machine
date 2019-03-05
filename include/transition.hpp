#pragma once

#include "event.hpp"
#include "state.hpp"

namespace sm_ns {

class transition {
  public:
	// constructors
	transition() = delete;

	transition(state, state, event);

	auto operator==(transition other) const -> bool;

	state from, to;
	event trigger;
};

auto make_transition(std::string, std::string, std::string) -> transition;

} // namespace sm_ns