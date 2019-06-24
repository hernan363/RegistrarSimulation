#ifndef WINDOWLIST_CPP
#define WINDOWLIST_CPP

#include "WindowList.h"

using namespace std;

WindowList * WindowList::windowInstance = 0;

void WindowList::printList() {
  winL.printAll();
}

WindowList::WindowList() {
  stats = Statistics::getInstance();
  totalNumWindows = 0;
  windowsOpen = 0;
}

WindowList* WindowList::getInstance() {
  if(windowInstance == 0){
    windowInstance = new WindowList();
  }
  return windowInstance;
}

bool WindowList::findOpenWindow() {
  cursor = winL.front;

  while(windowsOpen != 0) {
    if(cursor->data.open == true) {
      cursor->data.open = false;
      --windowsOpen;
      return true;
    } else if (cursor->next == NULL) {
      break;
    } else {
      cursor = cursor->next;
    }
  }
  return false;
}

//reopens and decrements the timeTilOpen;
void WindowList::reopenWindow(){
  cursor = winL.front;
  while(true) {
    //reopen window if not decrement the timeTileOpen
    if(cursor->data.timeTilOpen == 0) {
      cursor->data.open = true;
      ++windowsOpen;
    } else {
      --cursor->data.timeTilOpen;
    }

    //exit loop
    if(cursor == winL.back) {
      break;
    }
    //next node
    if(cursor->next != NULL) {
      cursor = cursor->next;
    } else {
      break;
    }
  }
}

void WindowList::winStatistics() {
  cursor = winL.front;
  while(true) {
    if(cursor->data.idleForFive == true) {
      ++stats->numWinWaitOverFive;
    }
    if(cursor->data.totalIdle > stats->longestWinWaitTime) {
      stats->longestWinWaitTime = cursor->data.totalIdle;
    }
    //adding to the wait time (we will divide in the next line)
    stats->avgWinIdleTime += cursor->data.totalIdle;
    if(cursor->next != NULL) {
      cursor = cursor->next;
    } else {
      break;
    }

  }
  //dividing the average wait time
  stats->avgWinIdleTime /= totalNumWindows;
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
