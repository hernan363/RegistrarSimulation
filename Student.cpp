#ifndef STUDENT_CPP
#define STUDENT_CPP

#include "Student.h"

using namespace std;
Student::Student(){}
Student::Student(int a, int t){
	arvTime = a; // arrival time
	reqTime = t; // time needed at the window
	waitTime = 0; // time spent waiting for an open window
}

Student::~Student(){}

#endif
