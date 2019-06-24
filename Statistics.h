#ifndef STATISTICS_H
#define STATISTICS_H

using namespace std;

class Statistics{
public:

  //STUDENT STATISTICS
  int totalStuWaitTime;
  int longestStuWaitTime;
  int numStuWaitOverTen;

  //WINDOW STATISTICS
  int avgWinIdleTime;
  int longestWinWaitTime;
  int numWinWaitOverFive;

  static Statistics* getInstance();

  void printStats();

  Statistics();
  ~Statistics();
private:
  static Statistics* statsInstance;

};

#endif
