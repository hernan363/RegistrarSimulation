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
  stats->numStudents = sQ->returnSize();
  wQ->totalNumWindows = wQ->winQ.getSize();
//window size = 5
  while(sQ->returnSize() != 0 || wQ->returnSize() != wQ->totalNumWindows) {
    // if((sQ->returnSize() != 0)) {
    //   run();
    // } else {
    //   if(wQ->returnSize() == wQ->totalNumWindows) {
    //     break;
    //   }
    // }
    run();
    wQ->reopenWindow();
    sQ->incrementStuWait();
    wQ->increaseIdleTimer();
    cout <<"Window Queue Size: " << wQ->returnSize() << endl;
    cout <<"Window List Size: " << wQ->returnListSize() << endl;

    cout <<"Student Size: " <<  sQ->returnSize() << endl;
    ++count;
    cout << "ROUND: " << count << endl;
  }
  runWindowStatistics();
  // stats->printStats();
}

void Simulation::run() {
  while(sQ->returnSize() != 0 && sQ->peekFront().arvTime <= count) {
    if(wQ->returnSize() != 0) {
      s = sQ->removeStudent();
      w = wQ->removeWindow(s.reqTime);
      ///////////////Window Statistics /////////////
      w.totalIdle += count - w.timeTilOpen;

      if((count-w.timeTilOpen) > 5) {
        w.idleForFive = true;
      }

      w.timeTilOpen = count + s.reqTime;

      ///////Student Statistics////////////
      stats->totalStuWaitTime += count-s.arvTime;

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
  wQ->winStatistics();
}
#endif
