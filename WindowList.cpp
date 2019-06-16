#ifndef WINDOWLIST_CPP
#define WINDOWLIST_CPP

#include "WindowList.h"

using namespace std;

WindowList * WindowList::windowInstance = 0;

WindowList::WindowList() {
}

WindowList* WindowList::getInstance() {
  if(windowInstance == 0){
    windowInstance = new WindowList();
  }
  return windowInstance;
}

bool WindowList::findOpenWindow() {
  cursor = winL.front;
  while(!isFull) {
    if(cursor->data.open == true) {
      cursor->data.open = false;
      return true;
    } else if (cursor->data.open == false) {
      cursor = cursor->prev;
    } else {
      isFull = true;
    }
  }
  return false;
}

void WindowList::addWindow(Window w) {
  winL.insertBack(w);
}

Window WindowList::removeWindow(){
  return winL.removeFront();
}

int WindowList::returnSize() {
  return winL.size;
}

#endif
