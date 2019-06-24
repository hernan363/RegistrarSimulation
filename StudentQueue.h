#ifndef STUDENTQUEUE_H
#define STUDENTQUEUE_H

#include "Queue.h"
#include "Student.h"

#include <iostream>

using namespace std;

class StudentQueue {
public:
  static StudentQueue* getInstance();
  Student removeStudent();
  void addStudent(Student s);
  int returnSize();
  void printQueue();
  Student peekFront();
  void incrementStuWait();
private:
  ListNode<Student>* cursor;
  StudentQueue();
  static StudentQueue* firstInstance;
  Queue<Student> stuQ;
};






#endif
