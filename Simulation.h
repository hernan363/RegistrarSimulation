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
  void run();
private:
  int count;
  Statistics* stats;
  StudentQueue* sQ;
  WindowList* wL;
  Student s;
  Window w;
};

#endif
