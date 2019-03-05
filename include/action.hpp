#pragma once

#include <functional>

namespace sm_ns {

// represents one action that will be triggered upon reaching a state
class action {
  public:
	// constructors
	action() = delete;

	explicit action(std::function<auto(void)->void>);

	auto operator()() const -> void;

  private:
	std::function<auto(void)->void> __m_action;
};

} // namespace sm_ns