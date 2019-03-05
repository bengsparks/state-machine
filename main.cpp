#include <array>
#include <iostream>
#include <unordered_set>

#include "state_machine.hpp"

auto main(int argc, char* argv[]) -> int
{
	auto transitions = sm_ns::transitions{
		sm_ns::make_transition(
			"stopped", "running", "run",
			[]() -> void { std::cout << "stopped -> running : run\n"; }),
		sm_ns::make_transition(
			"paused", "running", "run",
			[]() -> void { std::cout << "paused -> running : run\n"; }),

		sm_ns::make_transition(
			"running", "stopped", "stop",
			[]() -> void { std::cout << "running -> stopped : stop\n"; }),
		sm_ns::make_transition(
			"paused", "stopped", "stop",
			[]() -> void { std::cout << "paused -> stopped : stop\n"; }),
		sm_ns::make_transition("running", "paused", "pause", []() -> void {
			std::cout << "running -> paused : pause\n";
		})};
	sm_ns::state_machine state_machine{transitions, "stopped"};

	state_machine.trigger(sm_ns::event{"run"});
	state_machine.trigger(sm_ns::event{"stop"});
	state_machine.trigger(sm_ns::event{"run"});
	state_machine.trigger(sm_ns::event{"pause"});

	return EXIT_SUCCESS;
}
