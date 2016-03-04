#include "Timer.h"

//TODO(Fer) - doesnt work yet
Timer::Timer() : bRunning(false){}
Timer::Timer(const FunctionCall &function, const Interval &interval)
{
	Start(function, interval);
}
Timer::~Timer(){}

void Timer::Start(const FunctionCall &function, 
	const Interval &interval)
{
	bRunning = true;

	m_Thread = thread([=]()
	{
		this_thread::sleep_for(interval);
		function();
	});

	m_Thread.join();
}

void Timer::Stop()
{
	bRunning = false;
	m_Thread.join();
}