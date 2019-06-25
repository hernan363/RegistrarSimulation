#ifndef SIMULATION_H
#define SIMULATION_H

#include "StudentQueue.h"
#include "WindowList.h"
#include "Statistics.h"

using namespace std;

class Simulation {
public:
  Simulation();
  ~Simulation();
  void simulate();
private:
  int count;
  Statistics* stats;
  StudentQueue* sQ;
  WindowList* wQ;
  Student s;
  // Window* w;
  ListNode<Window>* w;

  void run();
  void runWindowStatistics();
};

#endif
