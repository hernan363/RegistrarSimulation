#ifndef FILEREADER_H
#define FILEREADER_H

#include <fstream>
#include <string>

#include "WindowLists.h"
#include "StudentQueue.h"

using namespace std;

class fileReader {
private:
  // WindowList* wL;
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

  void fillQueue(const char* fileName);

  fileReader();
  ~fileReader();
};
#endif
