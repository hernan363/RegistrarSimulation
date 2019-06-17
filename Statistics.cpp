#ifndef STATISTICS_CPP
#define STATISTICS_CPP

#include "Statistics.h"

Statistics* Statistics::statsInstance = 0;

Statistics::Statistics() {
  //STUDENT STATISTICS
  totalStuWaitTime = 0;
  longestStuWaitTime = 0;
  numStuWaitOverTen = 0;

  //WINDOW STATISTICS
  totalWinIdleTime = 0;
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

#endif
