#ifndef SIMULATION_CPP
#define SIMULATION_CPP

#include "Simulation.h"

//constructor
Simulation::Simulation() {
  sQ = StudentQueue::getInstance();
  wL = WindowList::getInstance();
  count = 0;
}

//destructor
Simulation::~Simulation(){}

void Simulation::run() {
  while(sQ->peekFront().arvTime <= count) {
    if(wL->findOpenWindow() == true) {
      s = sQ->removeStudent();
      w = wL->cursor->data;
      w.totalIdle += count - w.timeTilOpen;

      if((count-w.timeTilOpen) >= 5) {
        w.idleForFive = true;
      }

      w.timeTilOpen = count + s.reqTime;

      //TODO:
      //student wait time to statistics;
      //
    }
  }
}

#endif
