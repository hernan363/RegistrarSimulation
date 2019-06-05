#ifndef FILEREADER_CPP
#define FILEREADER_CPP

#include "fileReader.h"

fileReader::fileReader(){
  line = "";
  time = 0;
  sQ.getInstance();
  wQ.getInstance();

}

fileReader::~fileReader(){}

void fileReader::fillQueue(const char* fileName) {
  // myFile = (fileName);

  if(!myFile.isOpen()) {
    cout << "file could not open" << endl;
  } else {
    getline(myFile, line);

    for(int i = 0 ; i < line.length(); ++i) {
      w = new Window();
      wQ.addWindow(w);
    }

    while(getline(myFile, line)) {
      time = stoi(line);
      for(int i = 0; i < line.length(); ++i) {
        getline(myFile, line);
        s = new Student(time, stoi(line));
        sQ.addStudent(s);
      }
    }
  }
}
#endif
