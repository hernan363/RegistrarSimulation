#ifndef FILEREADER_CPP
#define FILEREADER_CPP

#include "fileReader.h"
#include <string>


fileReader::fileReader(){
  line = "";
  time = 0;
  numStudents = 0;
  sQ = StudentQueue::getInstance();
  wQ = WindowLists::getInstance();
}

fileReader::~fileReader(){}

bool fileReader::fillQueue(const char* fileName) {
  myFile.open(fileName);

  if(!myFile.is_open()) {
    cout << "file could not open" << endl;
    return false;
  } else {
    getline(myFile, line);

    add_Windows_To_Queue(); //adding Windows

    while(getline(myFile, line)) {
      time = stoi(line);
      getline(myFile,line);
      numStudents = stoi(line);

      for(int i = 0; i < numStudents; ++i) {
        getline(myFile, line);
        s = Student(time, stoi(line));
        sQ->addStudent(s);
      }
    }
    return true;
  }
}

void fileReader::add_Windows_To_Queue() {
  for(int i = 0 ; i < stoi(line); ++i) {
    wQ->totalNumWindows++;
    w = Window(wQ->totalNumWindows);
    wQ->addWindow(w);
  }
}
#endif
