#include "Windows.h"
#include <iostream>

using namespace std;

Window::Window(){
	idle = -1;
	totalIdle = 0;
	timeTilOpen = 0;
	open = true;
	idleForFive = false;
}

Window::~Window(){}
