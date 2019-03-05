#pragma once

#include <string>
#include <ostream>

namespace sm_ns {

// represents one event that can trigger a transition
class event {
  public:
	// constructors
	event() = delete;

	explicit event(std::string);

	// overload for std::unordered_map
	auto operator==(event) const -> bool;

	friend std::ostream &operator<<(std::ostream &os, const event &event);

	std::string name;
};

} // namespace sm_ns