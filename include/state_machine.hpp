#pragma once

#include <ostream>
#include <unordered_map>
#include <unordered_set>

#include "hashing.hpp"
#include "state.hpp"
#include "transition.hpp"

namespace sm_ns {

// represents one state machine
class state_machine {
  public:
	state_machine() = delete;
	state_machine(std::unordered_set<transition>, std::string);

	auto trigger(event) -> int;

	friend auto operator<<(std::ostream& os, const state_machine& machine)
		-> std::ostream&;

	state current_state;

  private:
	std::unordered_map<
		state,
		std::unordered_map<event, std::pair<state, std::optional<action>>>>
		__m_transitions;
};
} // namespace sm_ns
