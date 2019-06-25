#ifndef FILEREADER_CPP
#define FILEREADER_CPP

#include "fileReader.h"
#include <string>


fileReader::fileReader(){
  line = "";
  time = 0;
  sQ = StudentQueue::getInstance();
  wQ = WindowList::getInstance();
}

fileReader::~fileReader(){}

void fileReader::fillQueue(const char* fileName) {
  // myFile = (fileName);
  myFile.open(fileName);

  if(!myFile.is_open()) {
    cout << "file could not open" << endl;
  } else {
    getline(myFile, line);

    for(int i = 0 ; i < stoi(line); ++i) {
      w = Window();
      wQ->addWindow(w);
    }

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
  }
  // wQ->printList();
}
#endif
