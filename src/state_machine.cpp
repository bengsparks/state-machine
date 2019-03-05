#include <iostream>
#include "../include/state_machine.hpp"

using namespace sm_ns;

// state machine implementation
state_machine::state_machine(std::unordered_set<transition> transitions,
							 std::string first_state)
	: current_state{state{std::move(first_state)}}, __m_transitions{}
{
	for (auto transition : transitions) {
		if (const auto position = __m_transitions.find(transition.from);
			position == std::end(__m_transitions)) {
			auto [new_position, _] = __m_transitions.emplace(
				transition.from, std::unordered_map<event, state>{});
			new_position->second.emplace(transition.trigger, transition.to);
		}

		else {
			position->second.emplace(transition.trigger, transition.to);
		}
	}
}

auto state_machine::trigger(event happening) -> int
{
	// sanity check
	if (const auto event_lookup = __m_transitions.find(current_state); event_lookup != std::end(__m_transitions)) {
		const auto event_state_map = event_lookup->second;

		if (const auto state_lookup = event_state_map.find(happening); state_lookup != std::end(event_state_map)) {
			current_state = state_lookup->second;
			return EXIT_SUCCESS;
		}

		else {
			std::cerr << "unable to find event " << happening << " in state lookup map\n";
			return EXIT_FAILURE;
		}
	}

	else {
		std::cerr << "unable to find state " << current_state << " in transition map\n";
		return EXIT_FAILURE;
	}
}

auto sm_ns::operator<<(std::ostream& os, const state_machine& machine) -> std::ostream&
{
	return os << machine.current_state;
}
