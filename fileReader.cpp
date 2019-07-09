#ifndef FILEREADER_CPP
#define FILEREADER_CPP

#include "fileReader.h"
#include <string>


fileReader::fileReader(){
  line = "";
  timeArrived = 0;
  numStudents = 0;
  sQ = StudentQueue::getInstance();
  wQ = WindowLists::getInstance();
}

fileReader::~fileReader(){}

//comments describe each getline
bool fileReader::fillQueue(const char* fileName) {
  myFile.open(fileName);

  if(!myFile.is_open()) {
    cout << "file could not open" << endl;
    return false;
  } else {
    getline(myFile, line); // number of windows

    addWindowsToQueue();

    while(getline(myFile, line)) { // time a student arrived
      timeArrived = stoi(line);
      getline(myFile,line);  // number of students at a given time
      numStudents = stoi(line);

      for(int i = 0; i < numStudents; ++i) {
        getline(myFile, line); // amount of time a student needs at a window
        s = Student(timeArrived, stoi(line));
        sQ->addStudent(s);
      }
    }
    return true;
  }
}

void fileReader::addWindowsToQueue() {
  for(int i = 0 ; i < stoi(line); ++i) {
    wQ->totalNumWindows++;
    w = Window(wQ->totalNumWindows);
    wQ->addWindow(w);
  }
}
#endif
