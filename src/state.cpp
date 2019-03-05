#include "../include/state.hpp"

using namespace sm_ns;

// state implementation
state::state(std::string name) : name{std::move(name)}
{
}

auto state::operator==(state other) const -> bool
{
	// Do not differentiate on action, because std::function cannot be compared
	return name == other.name;
}

namespace sm_ns {
auto operator<<(std::ostream& os, const state& state) -> std::ostream&
{
	os << "state: " << state.name;
	return os;
}
} // namespace sm_ns
