#include "fileReader.h"
#include "Simulation.h"

using namespace std;

int main(int argc, char const *argv[]) {
  fileReader r;
  Simulation s;
  Statistics* stats = Statistics::getInstance();

  //simulate if the file exists
  if(r.fillQueue(argv[1]) == true) {
    s.simulate();

    cout << "Mean student wait time: " << stats->totalStuWaitTime/stats->numStudents << endl;
    cout << "Median student wait time:" << stats->medianValue << endl;
    cout << "Longest student wait time:" << stats->longestStuWaitTime << endl;
    cout << "Number of students who waited over ten minutes: " << stats->numStuWaitOverTen << endl;
    cout << "Average window idle time: " << stats->avgWinIdleTime << endl;
    cout << "Longest window wait time: " << stats->longestWinWaitTime << endl;
    cout << "Number of Windows that waited for over five minutes: " << stats->numWinWaitOverFive << endl;
  }

  return 0;
}
