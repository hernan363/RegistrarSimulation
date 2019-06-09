#include "fileReader.h"

using namespace std;

int main(int argc, char const *argv[]) {
  fileReader r;

  r.fillQueue(argv[1]);

  return 0;
}
