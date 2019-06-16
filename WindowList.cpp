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
