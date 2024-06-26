#pragma once
#include <chrono>
class ScopeTimer
{
public:
	ScopeTimer(const char* timer_label);
	~ScopeTimer();

	inline std::chrono::nanoseconds get_elapsed();

	const char* timer_label = nullptr;
	std::chrono::nanoseconds timer_start;
};