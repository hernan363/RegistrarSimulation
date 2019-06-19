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
  while((sQ->returnSize() != 0) || (wL->windowsOpen != wL->totalNumWindows)) {
    run();
    cout <<sQ->returnSize() << endl;
  }
  runWindowStatistics();
}

void Simulation::run() {
  cout << sQ->peekFront().arvTime<< endl;

  while(sQ->peekFront().arvTime <= count) {
    cout << "Hello" << endl;

    if(wL->findOpenWindow() == true) {
      cout << "Hello" << endl;
      s = sQ->removeStudent();
      w = wL->cursor->data;
      ///////////////Window Statistics /////////////
      w.totalIdle += count - w.timeTilOpen;

      if((count-w.timeTilOpen) > 5) {
        w.idleForFive = true;
      }

      w.timeTilOpen = count + s.reqTime;

      ///////Student Statistics////////////
      stats->totalStuWaitTime += s.waitTime;

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
  ++count;
  wL->reopenWindow();
}

void Simulation::runWindowStatistics() {
  wL->winStatistics();
}
#endif
