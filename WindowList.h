#ifndef WINDOWLIST_H
#define WINDOWLIST_H

#include "DoublyLinkedList.h"
#include "Window.h"
class WindowList {
public:
  static WindowList* getInstance();
  void addWindow(Window w);
  Window removeWindow();
  WindowList();
  int returnSize();
private:
  DoublyLinkedList<Window> winL;
  static WindowList* windowInstance;

};


#endif
