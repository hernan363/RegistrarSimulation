#ifndef SIMULATION_CPP
#define SIMULATION_CPP

#include "Simulation.h"

//constructor
Simulation::Simulation() {
  sQ = StudentQueue::getInstance();
  wQ = WindowLists::getInstance();
  stats = Statistics::getInstance();
  count = 1;
}

//destructor
Simulation::~Simulation(){}

void Simulation::simulate() {
  setTotalSizes();
  while(sQ->returnSize() != 0 || wQ->returnSize() != wQ->totalNumWindows) {
    serviceStudents();
    wQ->increaseIdleTimer();
    wQ->reopenWindow();
    ++count;
  }
  stats->setMedianArrayValue();
  wQ->insertWindowStatistics();
}

void Simulation::serviceStudents() {
  //Check if there are students in the queue
  //and if there are windows working
  while(sQ->returnSize() != 0 && sQ->peekFront().arvTime <= count) {
    if(wQ->returnSize() != 0) {
      serviceOneStudent();
    } else {
      break;
    }
  }
}

void Simulation::serviceOneStudent() {
  //removes the student and window from their respective queues
  s = sQ->removeStudent();
  wQ->removeWindow(s.reqTime);

  ///////Updating Student Statistics////////////
  s.waitTime = count - s.arvTime;
  stats->totalStuWaitTime += s.waitTime;

  stats->stuMedian[sQ->returnSize()] = s.waitTime;//adding to the median array

  if(s.waitTime > stats->longestStuWaitTime) {
    stats->longestStuWaitTime = s.waitTime;
  }

  if(s.waitTime > 10) {
    ++stats->numStuWaitOverTen;
  }
}

void Simulation::setTotalSizes() {
  stats->numStudents = sQ->returnSize(); // setting number of students
  wQ->totalNumWindows = wQ->winQ.getSize(); //setting number of windows
  stats->setMedianArraySize(); // setting size of the array
}

#endif
