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
  int totalWinIdleTime;
  int longestWinWaitTime;
  int numWinWaitOverFive;

  static Statistics* getInstance();

  Statistics();
  ~Statistics();
private:
  static Statistics* statsInstance;

};

#endif
