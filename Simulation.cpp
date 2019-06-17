#ifndef SIMULATION_CPP
#define SIMULATION_CPP

#include "Simulation.h"

//constructor
Simulation::Simulation() {
  sQ = StudentQueue::getInstance();
  wL = WindowList::getInstance();
  stats = Statistics::getInstance();
  count = 0;
}

//destructor
Simulation::~Simulation(){}

void Simulation::run() {
  while(sQ->peekFront().arvTime <= count) {
    if(wL->findOpenWindow() == true) {
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
#endif
