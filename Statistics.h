#ifndef STATISTICS_H
#define STATISTICS_H

#include <iostream>

using namespace std;

class Statistics{
public:

  //STUDENT STATISTICS
  int totalStuWaitTime;
  int longestStuWaitTime;
  int numStuWaitOverTen;
  int* stuMedian;

  //WINDOW STATISTICS
  int avgWinIdleTime;
  int longestWinWaitTime;
  int numWinWaitOverFive;

  int numStudents;

  static Statistics* getInstance();

  void printStats();
  void setMedianArraySize();
  void sort();

  Statistics();
  ~Statistics();
private:
  static Statistics* statsInstance;

};

#endif
