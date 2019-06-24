#ifndef SIMULATION_CPP
#define SIMULATION_CPP

#include "Simulation.h"

//constructor
Simulation::Simulation() {
  sQ = StudentQueue::getInstance();
  wL = WindowList::getInstance();
  stats = Statistics::getInstance();
  count = 1;
}

//destructor
Simulation::~Simulation(){}

void Simulation::simulate() {
  stats->numStudents = sQ->returnSize();
  while(true) {
    if((sQ->returnSize() != 0)) {
      run();
    } else {
      if(wL->windowsOpen == wL->totalNumWindows) {
        break;
      }
    }
    wL->reopenWindow();
    sQ->incrementStuWait();
    ++count;
  }
  runWindowStatistics();
  // stats->printStats();
}

void Simulation::run() {
  while(sQ->returnSize() != 0 && sQ->peekFront().arvTime <= count) {
    if(wL->findOpenWindow() == true) {
      s = sQ->removeStudent();
      w = wL->cursor;
      ///////////////Window Statistics /////////////
      w->data.totalIdle += count - w->data.timeTilOpen;

      if((count-w->data.timeTilOpen) > 5) {
        w->data.idleForFive = true;
      }

      w->data.timeTilOpen = count + s.reqTime;

      ///////Student Statistics////////////
      stats->totalStuWaitTime += s.waitTime-s.arvTime;

      if(s.waitTime > stats->longestStuWaitTime) {
        stats->longestStuWaitTime = s.waitTime;
      }

      if(s.waitTime > 10) {
        ++stats->numStuWaitOverTen;
      }
    } else {
      break;
    }
  }
}

void Simulation::runWindowStatistics() {
  wL->winStatistics();
}
#endif
