#pragma once

#include <optional>
#include <ostream>
#include <string>

#include "action.hpp"

namespace sm_ns {

// represents one state in a state machine that has an action associated with it
class state {
  public:
	// constructors
	state() = delete;

	explicit state(std::string);

	// call the action
	auto operator()() const -> bool;

	// overload for std::unordered_map
	auto operator==(state) const -> bool;

	friend std::ostream& operator<<(std::ostream& os, const state& state);

	std::string name;
};

} // namespace sm_ns
