#include <iostream>

using namespace std;

class Window{
public:
	int idle; // keeps track of how long the windows are idle
	int totalIdle; // total time spent idle
	int timeTilOpen; // what time will it be open at
	bool open;  // if the window is open
	bool idleForFive; // if the window has been idle for more than 5 minutes

	Window();
	~Window();
};
