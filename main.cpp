#include <array>
#include <iostream>
#include <unordered_set>

#include "state_machine.hpp"

auto main(int argc, char* argv[]) -> int {
    auto transitions = std::unordered_set{
        sm_ns::make_transition("stopped", "running", "run"),
        sm_ns::make_transition("paused", "running", "run"),

        sm_ns::make_transition("running", "stopped", "stop"),
        sm_ns::make_transition("paused", "stopped", "stop"),

        sm_ns::make_transition("running", "paused", "pause")
    };
    sm_ns::state_machine state_machine{transitions, "stopped"};

    state_machine.trigger(sm_ns::event{"run"});
    std::cout << state_machine << "\n";

    state_machine.trigger(sm_ns::event{"stop"});
    std::cout << state_machine << "\n";

    state_machine.trigger(sm_ns::event{"run"});
    std::cout << state_machine << "\n";

    state_machine.trigger(sm_ns::event{"pause"});
    std::cout << state_machine << "\n";

    return EXIT_SUCCESS;
}