#ifndef SIMULATION_CPP
#define SIMULATION_CPP

#include "Simulation.h"

//constructor
Simulation::Simulation() {
  sQ = StudentQueue::getInstance();
  wQ = WindowQueue::getInstance();
  count = 0;
}

//destructor
Simulation::~Simulation(){}

void Simulation::run() {
  while(sQ->peekFront().arvTime <= count) {
    s = sQ.removeStudent();
    w = wQ.removeWindow();
    
  }
}

#endif
