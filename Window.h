#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>

using namespace std;

class Window{
public:
	int id;
	int idle; // keeps track of how long the windows are idle
	int totalIdle; // total time spent idle
	int timeTilOpen; // what time will it be open at
	bool idleForFive; // if the window has been idle for more than 5 minutes

	// friend ostream& operator<<(ostream& os, const Window& win);
	friend bool operator==(const Window& window, const Window& window2);

	Window(int id);
	Window();
	~Window();
};
#endif
