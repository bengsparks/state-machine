#include "../include/event.hpp"

using namespace sm_ns;

// event implementation
event::event(std::string name) : name{std::move(name)}
{
}

auto event::operator==(event other) const -> bool
{
	return name == other.name;
}

auto sm_ns::operator<<(std::ostream& os, const event& event) -> std::ostream&
{
	return os << event.name;
}
