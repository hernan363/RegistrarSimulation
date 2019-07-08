#ifndef STATISTICS_H
#define STATISTICS_H

#include <bits/stdc++.h> // sort() function for median student

using namespace std;

class Statistics{
public:

  //STUDENT STATISTICS
  int totalStuWaitTime; //totalStudent wait time
  int longestStuWaitTime; // longest student wait time
  int numStuWaitOverTen; // number of students who waited over ten minutes
  int numStudents; //number of students

    //Median
  int* stuMedian; //student median array to hold all the statistics
  float medianValue; // final median value

  //WINDOW STATISTICS
  int avgWinIdleTime; //average window idle time
  int longestWinWaitTime; // longest window idle time
  int numWinWaitOverFive; // number of windows that waited over give minutes

  static Statistics* getInstance();

  void setMedianArraySize();
  void setMedianArrayValue();

  Statistics();
  ~Statistics();
private:
  static Statistics* statsInstance;

};

#endif
