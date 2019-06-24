#include "fileReader.h"
#include "Simulation.h"

using namespace std;

int main(int argc, char const *argv[]) {
  fileReader r;
  Simulation s;
  Statistics* stats = Statistics::getInstance();

  r.fillQueue(argv[1]);
  // r.wL->printList();
  cout << "singleton address wL " << r.wL << endl;
  s.simulate();

  cout << "Mean student wait time: " << stats->totalStuWaitTime/stats->numStudents << endl;
  cout << "Median student wait time:" << stats->totalStuWaitTime << endl;
  cout << "Longest student wait time:" << stats->longestStuWaitTime << endl;
  cout << "Number of students who waited over ten minutes: " << stats->numStuWaitOverTen << endl;
  cout << "Average window idle time: " << stats->avgWinIdleTime << endl;
  cout << "Longest window wait time: " << stats->longestWinWaitTime << endl;
  cout << "Number of Windows that waited for over five minutes: " << stats->numWinWaitOverFive << endl;

  return 0;
}
