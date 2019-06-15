#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student{
	public:
		int arvTime; // arrival time
		int reqTime; // required time
		int waitTime;

		Student();
		Student(int a, int t);
		~Student();

		friend ostream& operator<<(ostream& os, const Student& stu);
};


#endif
