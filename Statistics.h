#ifndef STATISTICS_H
#define STATISTICS_H

using namespace std;

class Statistics{
public:

  //STUDENT STATISTICS
  float meanStuWaitTime;
  float medianStuWaitTime;
  int longestStuWaitTime;
  int numStuWaitOverTen;

  //WINDOW STATISTICS
  float meanWinIdleTime;
  int longestWinWaitTime;
  int numWinWaitOverFive;

  static Statistics* getInstance();

  Statistics();
  ~Statistics();
private:
  static Statistics* statsInstance;

};

#endif
