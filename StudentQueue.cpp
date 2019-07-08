#ifndef STUDENTQUEUE_CPP
#define STUDENTQUEUE_CPP

#include "StudentQueue.h"

StudentQueue* StudentQueue::firstInstance = 0;

StudentQueue::StudentQueue(){
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

void StudentQueue::incrementStuWait(){
  cursor = stuQ.D.front;
  while(cursor != NULL) {
    ++cursor->data.waitTime;
    cursor = cursor->next;
  }
}

void StudentQueue::addStudent(Student s) {
  stuQ.insert(s);
}

Student StudentQueue::removeStudent(){
  return stuQ.remove();
}

Student StudentQueue::peekFront() {
  return stuQ.peek();
}
#endif
