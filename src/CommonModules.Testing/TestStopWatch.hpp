#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include "StopWatch.hpp"

class TestStopWatch
{
public:
	TestStopWatch()
	{}

	~TestStopWatch()
	{}

	void TestCallStopWatchOnce()
	{
		std::cout << "Test call StopWatch once" << std::endl;
		StopWatch sw;
		sw.Start();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		sw.Stop();

		double elapsed = sw.GetElapsed();
		std::cout << elapsed << std::endl;
	}

	void TestCallStopWatchMultiple()
	{
		std::cout << "\nTest call StopWatch once" << std::endl;
		StopWatch sw;
		std::cout << "first call" << std::endl;
		sw.Start();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		sw.Stop();

		double elapsed = sw.GetElapsed();
		std::cout << elapsed << std::endl;

		std::cout << "second call" << std::endl;
		sw.Start();
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
		sw.Stop();

		elapsed = sw.GetElapsed();
		std::cout << elapsed << std::endl;
	}
};