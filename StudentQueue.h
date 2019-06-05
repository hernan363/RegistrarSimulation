#ifndef STUDENTQUEUE_H
#define STUDENTQUEUE_H

#include "Queue.h"
#include "Student.h"

using namespace std;

class StudentQueue {
public:
  StudentQueue();
  ~StudentQueue();
  static StudentQueue* getInstance();
  Student removeStudent();
  void addStudent(Student* s);

private:
  static StudentQueue* firstInstance;
  Queue<Student> stuQ;
};

#endif
