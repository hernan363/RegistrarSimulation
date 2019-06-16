#ifndef WINDOWQUEUE_H
#define WINDOWQUEUE_H

#include "Queue.h"
#include "Window.h"
class WindowQueue {
public:
  static WindowQueue* getInstance();
  void addWindow(Window w);
  Window removeWindow();
  WindowQueue();
  int returnSize();
private:
  Queue<Window> winQ;
  static WindowQueue* windowInstance;

};


#endif
