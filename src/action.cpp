#include "../include/action.hpp"

using namespace sm_ns;

// action implementation
action::action(std::function<auto(void)->void> callback)
	: __m_action{std::move(callback)}
{
}

auto action::operator()() const -> void
{
    std::invoke(__m_action);
}
