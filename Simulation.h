#ifndef SIMULATION_H
#define SIMULATION_H

#include "StudentQueue.h"
#include "WindowLists.h"
#include "Statistics.h"

using namespace std;

class Simulation {
public:
  Simulation();
  void simulate();
  ~Simulation();

private:
  int count;
  Statistics* stats; // statistics
  StudentQueue* sQ; //Student Queue
  WindowLists* wQ; // Window Queue
  Student s; // student
  Window w; // window

  void serviceStudents();
  void setTotalSizes();
  void serviceOneStudent();

};

#endif
