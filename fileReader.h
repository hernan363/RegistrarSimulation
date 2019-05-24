#include <fstream>
#include <string>

#include "QueueHolder.h"

using namespace std;

class fileReader {
private:
  QueueHolder qH;

  Window w;
  Student s;

  int time;

  ifstream myFile;
  string line;
  Student createStudent(int arrivalTime, int requiredTime);
  Window createWindow();
public:
  void fillQueue();

  fileReader();
  ~fileReader();
};
