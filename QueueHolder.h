#include "Queue.h"
#include "Student.h"
#include "Window.h"

using namespace std;

class QueueHolder {
public:
  Queue<Student> stuQ;
  Queue<Window> winQ;
  QueueHolder();
private:
  ~QueueHolder();

};
