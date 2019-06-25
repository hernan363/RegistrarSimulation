#ifndef WINDOWLIST_CPP
#define WINDOWLIST_CPP

#include "WindowLists.h"

using namespace std;

WindowLists * WindowLists::windowInstance = 0;

// void WindowLists::printList() {
//   winQ.printAll();
// }

WindowLists::WindowLists() {
  stats = Statistics::getInstance();
  totalNumWindows = 0;
}

WindowLists* WindowLists::getInstance() {
  if(windowInstance == 0){
    windowInstance = new WindowLists();
  }
  return windowInstance;
}

// bool WindowLists::findOpenWindow() {
//   cursor = winL.front;
//
//   while(windowsOpen != 0) {
//     if(cursor->data.open == true) {
//       cursor->data.open = false;
//       --windowsOpen;
//       return true;
//     } else if (cursor->next == NULL) {
//       break;
//     } else {
//       cursor = cursor->next;
//     }
//   }
//   return false;
// }

//reopens and decrements the timeTilOpen;
void WindowLists::reopenWindow(){
  cursor = winL.front;
  while(true) {
    //reopen window if not decrement the timeTileOpen
    if(cursor->data.timeTilOpen == 0) {
      winQ.insert(cursor->data);
    } else {
      --cursor->data.timeTilOpen;
    }

    //next node
    if(cursor->next != NULL) {
      cursor = cursor->next;
    } else {
      break;
    }
  }
}

void WindowLists::winStatistics() {
  cursor = winQ.D.front;
  while(true) {
    cout << winQ.getSize() << endl;
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

void WindowLists::addWindow(Window w) {
  winQ.insert(w);
}

Window WindowLists::removeWindow(){

  w = winQ.remove();
  winL.insertBack(w);
  return w;
}

int WindowLists::returnSize() {
  return winQ.getSize();
}

#endif
