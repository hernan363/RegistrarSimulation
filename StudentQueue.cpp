#ifndef STUDENTQUEUE_CPP
#define STUDENTQUEUE_CPP

#include "StudentQueue.h"
StudentQueue* StudentQueue::firstInstance = 0;


StudentQueue::StudentQueue(){
  // firstInstance = NULL;
}
int StudentQueue::returnSize(){
  return stuQ.getSize();
}

StudentQueue* StudentQueue::getInstance() {
  if(firstInstance == 0) {
    firstInstance = new StudentQueue();
  }
  return firstInstance;
}

void StudentQueue::addStudent(Student s) {
  stuQ.insert(s);
}

Student StudentQueue::removeStudent(){
  return stuQ.remove();
}

void StudentQueue::printQueue(){
  stuQ.printAll();
}

Student StudentQueue::peekFront() {
  return stuQ.peek();
}
#endif
