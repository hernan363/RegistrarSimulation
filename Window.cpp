#ifndef WINDOW_CPP
#define WINDOW_CPP
#include "Window.h"

using namespace std;
Window::Window(){
	id = 0;
	idle = 0;
	totalIdle = 0;
	timeTilOpen = 0;
	idleForFive = false;
}

Window::Window(int id){
	this->id = id;
	idle = 0;
	totalIdle = 0;
	timeTilOpen = 0;
	idleForFive = false;
}

bool operator==(const Window& window, const Window& window2) {
	if(window.id != window2.id) {
		return false;
	}
	return true;
}

Window::~Window(){}
#endif
