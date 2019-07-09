#ifndef WINDOWLIST_H
#define WINDOWLIST_H

#include "Queue.h"
#include "Window.h"
#include "Statistics.h"

class WindowLists {
public:
  static WindowLists* getInstance();
  WindowLists();
  ~WindowLists();
  void addWindow(Window w);
  void removeWindow(int stuTimeNeeded);
  void reopenWindow();
  void insertWindowStatistics();
  void increaseIdleTimer();

  int returnSize();
  int returnListSize();

  bool findOpenWindow();

  Queue<Window> winQ;
  DoublyLinkedList<Window> winL;
  int totalNumWindows;

private:
  Window w;
  Statistics* stats;
  ListNode<Window>* cursor;
  static WindowLists* windowInstance;

};


#endif
