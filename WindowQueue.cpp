#include "WindowQueue.h"

WindowQueue::WindowQueue() {
  firstInstance = 0;
}

WindowQueue::~WindowQueue(){}

WindowQueue* WindowQueue::getInstance() {
  if(firstInstance == 0){
    firstInstance = new WindowQueue();
  }
  return firstInstance;
}

void WindowQueue::addWindow(Window w) {
  winQ.insert(w);
}

Window WindowQueue::removeWindow(){
  return winQ.remove();
}
