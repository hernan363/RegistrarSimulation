#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student{
	public:
		int arvTime; // arrival time
		int reqTime; // required time
		int waitTime; // wait time

		Student();
		Student(int a, int t);
		~Student();
};


#endif
