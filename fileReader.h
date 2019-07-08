#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include <string>

#include "WindowLists.h"
#include "StudentQueue.h"

using namespace std;

class fileReader {
private:
  StudentQueue* sQ;
  Window w;
  Student s;

  int time;
  int numStudents;

  ifstream myFile;
  string line;
  Student createStudent(int arrivalTime, int requiredTime);
  Window createWindow();
public:
  WindowLists* wQ;

  bool fillQueue(const char* fileName);

  fileReader();
  ~fileReader();
};
#endif
