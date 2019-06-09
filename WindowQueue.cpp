#ifndef WINDOWQUEUE_CPP
#define WINDOWQUEUE_CPP

#include "WindowQueue.h"

using namespace std;

WindowQueue * WindowQueue::windowInstance = 0;

WindowQueue::WindowQueue() {
}

WindowQueue* WindowQueue::getInstance() {
  if(windowInstance == 0){
    windowInstance = new WindowQueue();
  }
  return windowInstance;
}

void WindowQueue::addWindow(Window w) {
  winQ.insert(w);
}

Window WindowQueue::removeWindow(){
  return winQ.remove();
}

#endif
