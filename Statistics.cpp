#ifndef STATISTICS_CPP
#define STATISTICS_CPP

#include "Statistics.h"

Statistics* Statistics::statsInstance = 0;

Statistics::Statistics() {}

Statistics::~Statistics(){}

Statistics* Statistics::getInstance() {
  if(statsInstance == 0) {
    statsInstance = new Statistics();
  }
  return statsInstance;
}

#endif
