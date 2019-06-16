#ifndef SIMULATION_H
#define SIMULATION_H

#include "StudentQueue.h"
#include "WindowQueue.h"
using namespace std;

class Simulation {
public:
  Simulation();
  ~Simulation();
  void run();
private:
  int count;
  StudentQueue* sQ;
  WindowQueue* wQ;
  Student s;
  Window w;
  
};

#endif
