#ifndef WINDOWLIST_H
#define WINDOWLIST_H

#include "Queue.h"
#include "Window.h"
#include "Statistics.h"

class WindowList {
public:
  ListNode<Window>* cursor;
  // Window* cursor;

  static WindowList* getInstance();
  void addWindow(Window w);
  Window removeWindow();
  WindowList();
  int returnSize();
  bool findOpenWindow();
  void reopenWindow();
  void winStatistics();
  void printList();
  Queue<Window> winQ;
  int totalNumWindows;
  void reopenWindow();

private:
  Window w;
  Statistics* stats;

  static WindowList* windowInstance;

};


#endif
