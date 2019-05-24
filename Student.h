#include <iostream>

using namespace std;
#ifndef Student_h
#define Student_h
class Student{
	public:
		int arvTime; // arrival time
		int reqTime; // required time
		int waitTime;

		Student(int a, int t);
		~Student();

};


#endif
