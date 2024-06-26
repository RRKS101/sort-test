#include "scopetimer.h"

ScopeTimer::ScopeTimer(const char* label)
{
	this->timer_label = label;
	this->timer_start = std::chrono::steady_clock::now().time_since_epoch();
}

ScopeTimer::~ScopeTimer()
{
	std::chrono::nanoseconds t = this->get_elapsed();
	if (this->timer_label != nullptr)
		printf("%s: %f us\n", this->timer_label, t.count() / 1000.0);
}

std::chrono::nanoseconds ScopeTimer::get_elapsed()
{
	return  std::chrono::steady_clock::now().time_since_epoch() - this->timer_start;
}
