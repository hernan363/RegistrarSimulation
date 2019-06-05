#include "Queue.h"
#include "Window.h"

using namespace std;

class WindowQueue {
public:
  // static WindowQueue firstInstance;
  static WindowQueue* getInstance();
  void addWindow(Window w);
  Window removeWindow();

  WindowQueue();
  ~WindowQueue();
private:
  static WindowQueue* firstInstance;
  Queue<Window> winQ;

};
