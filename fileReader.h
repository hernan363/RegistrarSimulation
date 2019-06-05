#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include <string>

#include "WindowQueue.h"
#include "StudentQueue.h"


using namespace std;

class fileReader {
private:
  WindowQueue wQ;
  StudentQueue sQ;
  Window w;
  Student s;

  int time;

  ifstream myFile;
  string line;
  Student createStudent(int arrivalTime, int requiredTime);
  Window createWindow();
public:
  void fillQueue(const char* fileName);

  fileReader();
  ~fileReader();
};
#endif
