#ifndef WINDOWLIST_CPP
#define WINDOWLIST_CPP

#include "WindowLists.h"

using namespace std;

WindowLists * WindowLists::windowInstance = 0;

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

//reopens and decrements the timeTilOpen;
void WindowLists::reopenWindow(){
  cursor = winL.front;
  while(cursor != NULL) {
    //reopen window if not decrement the timeTileOpen
    cout << cursor->data.timeTilOpen << endl;
    if(cursor->data.timeTilOpen == 0) {

      w = cursor->data;
      cursor = cursor->next;
      cout << "ID: " << w.id << endl;
      winL.deletePos(w);
      winQ.insert(w);
      cout << "one time" << endl;
    } else {
      --cursor->data.timeTilOpen;
      cursor = cursor->next;

    }

  }
}

void WindowLists::winStatistics() {
  cursor = winQ.D.front;
  while(cursor != NULL) {
    if(cursor->data.idleForFive == true) {
      ++stats->numWinWaitOverFive;
    }
    if(cursor->data.totalIdle > stats->longestWinWaitTime) {
      stats->longestWinWaitTime = cursor->data.totalIdle;
    }
    //adding to the wait time (we will divide in the next line)
    stats->avgWinIdleTime += cursor->data.totalIdle;
    cursor = cursor->next;

  }
  //dividing the average wait time
  stats->avgWinIdleTime /= totalNumWindows;
}

void WindowLists::addWindow(Window w) {
  winQ.insert(w);
}

Window WindowLists::removeWindow(int stuTimeNeeded){

  w = winQ.remove();
  w.timeTilOpen = stuTimeNeeded;
  winL.insertBack(w);
  return w;
}

int WindowLists::returnSize() {
  return winQ.getSize();
}

int WindowLists::returnListSize() {
  return winL.size;
}

void WindowLists::increaseIdleTimer() {
  cursor = winQ.D.front;
  while(cursor != NULL) {
    ++cursor->data.idle;
    cursor = cursor->next;
  }
}

#endif
