#include "Windows.h"
#include <iostream>

using namespace std;

Windows::Windows(){
	idle = -1;
	totalIdle = 0;
	timeTilOpen = 0;
	open = true;
	idleForFive = false; 
}

Windows::~Windows(){}
