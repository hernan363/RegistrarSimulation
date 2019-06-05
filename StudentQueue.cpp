#ifndef STUDENTQUEUE_CPP
#define STUDENTQUEUE_CPP

#include "StudentQueue.h"

StudentQueue::StudentQueue(){
  // firstInstance = NULL;
  firstInstance = 0;
}

StudentQueue::~StudentQueue(){}

StudentQueue* StudentQueue::getInstance() {
  if(firstInstance == 0) {
    firstInstance = new StudentQueue();
  }
  return firstInstance;
}

void StudentQueue::addStudent(Student* s) {
  stuQ.insert(*s);
}

Student StudentQueue::removeStudent(){
  return stuQ.remove();
}
#endif
