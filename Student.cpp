#ifndef STUDENT_CPP
#define STUDENT_CPP

#include "Student.h"
#include <iostream>

using namespace std;
Student::Student(){}
Student::Student(int a, int t){
	//variables needed
	arvTime = a; // arrival time
	reqTime = t; // time needed at the window
	waitTime = 0; // time spent waiting for an open window
}

//overloading operator
ostream& operator<<(ostream& os, const Student& stu) {
	os << stu.arvTime << " - " << stu.reqTime << " - " << stu.waitTime;
	return os;
}

Student::~Student(){}
#endif
