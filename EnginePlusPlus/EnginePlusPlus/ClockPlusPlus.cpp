#include "stdafx.h"
#include "ClockPlusPlus.h"


LARGE_INTEGER	Clock::counter;
LARGE_INTEGER	Clock::ticksPerSecond;
bool			Clock::highResolutionSupported = false;

void Clock::init()
{
	highResolutionSupported = QueryPerformanceFrequency(&ticksPerSecond);
	counter = getHardwareCounterValue();
}

//converts ticks to hours with decimal
double Clock::getCTimeInHours()
	{
		LARGE_INTEGER result;
		result.QuadPart = getHardwareCounterValue().QuadPart; //get ticks
		double temp = ((double)result.QuadPart) / ((double)ticksPerSecond.QuadPart); //convert to seconds (and double)
		temp = temp / 60.0; //divide by 60 seconds to get minutes
		temp = temp / 60.0; //divide by 60 minutes to get hours;
		return temp; //return the hours
	}

//returns the number of seconds since the game started
double Clock::getGameRuntime()
{
	LARGE_INTEGER result;
	result.QuadPart = getHardwareCounterValue().QuadPart - counter.QuadPart;
	double temp = ((double)result.QuadPart) / ((double)ticksPerSecond.QuadPart);
	return temp; //return the seconds since the game started
}