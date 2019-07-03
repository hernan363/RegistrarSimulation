#ifndef STATISTICS_CPP
#define STATISTICS_CPP

#include "Statistics.h"

Statistics* Statistics::statsInstance = 0;

Statistics::Statistics() {
  //STUDENT STATISTICS
  totalStuWaitTime = 0;
  longestStuWaitTime = 0;
  numStuWaitOverTen = 0;
  numStudents = 0;

  //WINDOW STATISTICS
  avgWinIdleTime = 0;
  longestWinWaitTime = 0;
  numWinWaitOverFive = 0;
}

Statistics::~Statistics(){}

Statistics* Statistics::getInstance() {
  if(statsInstance == 0) {
    statsInstance = new Statistics();
  }
  return statsInstance;
}

void Statistics::setMedianArraySize() {
  cout << "numStudents" << numStudents << endl;
  stuMedian = new int[numStudents];
}

void Statistics::printStats() {
  for(int i = 0; i < numStudents; ++i) {
    cout << "student median Number: " <<  stuMedian[i] << endl;
  }
}

#endif
