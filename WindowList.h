#ifndef WINDOWLIST_H
#define WINDOWLIST_H

#include "DoublyLinkedList.h"
#include "Window.h"
class WindowList {
public:
  ListNode<Window>* cursor;
  static WindowList* getInstance();
  void addWindow(Window w);
  Window removeWindow();
  WindowList();
  int returnSize();
  bool findOpenWindow();
private:
  bool isFull = false;
  DoublyLinkedList<Window> winL;
  static WindowList* windowInstance;

};


#endif
