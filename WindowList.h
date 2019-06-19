#ifndef WINDOWLIST_H
#define WINDOWLIST_H

#include "DoublyLinkedList.h"
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
  int windowsOpen;
  int totalNumWindows;
  void printList();
  DoublyLinkedList<Window> winL;



private:
  Window w;
  Statistics* stats;

  static WindowList* windowInstance;

};


#endif
