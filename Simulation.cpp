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
  cout << "ROUND: " << count << endl;
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
    // sQ->incrementStuWait();
    wQ->increaseIdleTimer();
    wQ->reopenWindow();

    // cout <<"Window Queue Size: " << wQ->returnSize() << endl;
    // cout <<"Window List Size: " << wQ->returnListSize() << endl;
    //
    // cout <<"Student Size: " <<  sQ->returnSize() << endl;
    ++count;
  }
  runWindowStatistics();
  // stats->printStats();
}

void Simulation::run() {
  while(sQ->returnSize() != 0 && sQ->peekFront().arvTime <= count) {
    if(wQ->returnSize() != 0) {
      s = sQ->removeStudent();
      wQ->removeWindow(s.reqTime);
      ///////////////Window Statistics /////////////

      cout << "ID: " << w.id << " || HAS A TOTAL IDLE TIME OF: " << w.totalIdle << endl;
      cout << "Student: " << s.arvTime << " count "<< count << endl;
      ///////Student Statistics////////////
      s.waitTime = count - s.arvTime;
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
}

void Simulation::runWindowStatistics() {
  wQ->winStatistics();
}
#endif
