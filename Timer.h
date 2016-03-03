#pragma once

#include <thread>
#include <chrono>

using namespace std;

class Timer
{
	thread m_Thread;
	bool bRunning ;

	typedef std::chrono::milliseconds Interval;
	typedef std::function<void(void)> FunctionCall;
public:
	Timer();
	Timer(const FunctionCall &function, const Interval &interval);
	~Timer();

	void Start(const FunctionCall &function, const Interval &interval);

	void Stop();
};