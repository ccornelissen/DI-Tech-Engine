#pragma once
#include "DI_Base.h"

using namespace std;

class MainComponent
{
public:
	static void Start();
	static void Stop();
	static void Run();
	static void Render();
	static void CleanUp();
};
