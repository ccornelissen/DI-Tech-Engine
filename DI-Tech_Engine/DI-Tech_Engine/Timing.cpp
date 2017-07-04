#include "Timing.h"

using namespace std;

static double g_Freq;
static bool g_TimerInitialized;

double Timing::GetTime()
{
	g_TimerInitialized = false;
	if(!g_TimerInitialized)
	{
		LARGE_INTEGER li;
		//Attempt to get the frequency of windows performance counter
		if (!QueryPerformanceFrequency(&li))
		{
			cerr << "QueryPerformanceFrequency failed in timer initialization"  << endl;
		}

		//Set frequency to the double version of 64 bit integer
		g_Freq = double(li.QuadPart);
		g_TimerInitialized = true;
	}

	LARGE_INTEGER li;
	//Attempt to retrieve the current version of the performance counter
	if (!QueryPerformanceCounter(&li))
		cerr << "QueryPerformanceCounter failed in get time!" << endl;

	return double(li.QuadPart) / g_Freq;
}
