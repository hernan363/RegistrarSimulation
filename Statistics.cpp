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
  medianValue = 0;

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
  stuMedian = new int[numStudents];
}

void Statistics::setMedianArrayValue() {
  //sort the Array
  sort(stuMedian,stuMedian+numStudents);

  //find the median value and check that it is in the middle
  medianValue = ((float)numStudents-1)/2;
  if(floor(medianValue) == medianValue) {
    //whole Number
    medianValue = stuMedian[(int)medianValue];
  } else {
    medianValue = (
      stuMedian[(int)floor(medianValue)] + stuMedian[(int)ceil(medianValue)]
    )/2;
  }
}

#endif
