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
  stats->setMedianArraySize();
  //window size = 5
  while(sQ->returnSize() != 0 || wQ->returnSize() != wQ->totalNumWindows) {
    run();
    wQ->increaseIdleTimer();
    wQ->reopenWindow();
    ++count;
  }
  // stats->stuMedian.sort();
  runWindowStatistics();
  stats->printStats();
}

void Simulation::run() {
  while(sQ->returnSize() != 0 && sQ->peekFront().arvTime <= count) {
    if(wQ->returnSize() != 0) {
      //removes the student and window their respective queues
      s = sQ->removeStudent();
      wQ->removeWindow(s.reqTime);
      cout << "ID: " << w.id << " || HAS A TOTAL IDLE TIME OF: " << w.totalIdle << endl;
      cout << "Student: " << s.arvTime << " count "<< count << endl;
      ///////Student Statistics////////////
      //adding to the median array//
      cout <<"returning size " << sQ->returnSize() <<  endl;
      cout << "wait time: " << s.waitTime << endl;

      s.waitTime = count - s.arvTime;
      stats->totalStuWaitTime += s.waitTime;
      stats->stuMedian[sQ->returnSize()] = s.waitTime;


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
