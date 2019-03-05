#include "../include/state.hpp"

using namespace sm_ns;

// state implementation
state::state(std::string name) : name{std::move(name)}, __m_action{std::nullopt}
{
}

state::state(std::string name, class action callback)
	: name{std::move(name)}, __m_action{std::move(callback)}
{
}

auto state::operator()() const -> bool
{
	if (__m_action == std::nullopt) {
		return false;
	}

	std::invoke(*__m_action);
	return true;
}

auto state::operator==(state other) const -> bool
{
	// Do not differentiate on action, because std::function cannot be compared
	return name == other.name;
}

template <typename Callback>
auto make_state(std::string name, Callback callback) -> state {
  return state{name, action{callback}};
}

namespace sm_ns {
auto operator<<(std::ostream& os, const state& state) -> std::ostream&
{
	os << "state: " << state.name;
	return os;
}
} // namespace sm_ns
