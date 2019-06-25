#ifndef WINDOWLIST_H
#define WINDOWLIST_H

#include "Queue.h"
#include "Window.h"
#include "Statistics.h"

#include <iostream>

class WindowLists {
public:
  ListNode<Window>* cursor;
  // Window* cursor;

  static WindowLists* getInstance();
  void addWindow(Window w);
  Window removeWindow();
  WindowLists();
  ~WindowLists();

  int returnSize();
  bool findOpenWindow();
  void reopenWindow();
  void winStatistics();
  // void printList();
  Queue<Window> winQ;
  DoublyLinkedList<Window> winL;
  int totalNumWindows;

private:
  Window w;
  Statistics* stats;

  static WindowLists* windowInstance;

};


#endif
