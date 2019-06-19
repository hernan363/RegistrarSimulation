#include "fileReader.h"
#include "Simulation.h"

using namespace std;

int main(int argc, char const *argv[]) {
  fileReader r;
  Simulation s;

  r.fillQueue(argv[1]);
  // r.wL->printList();
  cout << "singleton address wL " << r.wL << endl;
  s.simulate();

  return 0;
}
