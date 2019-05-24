#include "fileReader.h"

fileReader::fileReader(){
  line = "";
  time = 0;
}

fileReader::~fileReader(){}

QueueHolder fileReader::fillQueue(const *char fileName) {
  qH = new QueueHolder();
  myFile = (fileName);

  if(!myFile.isOpen()) {
    cout << "file could not open" << endl;
  } else {
    getline(myFile, line);

    for(int i = 0 ; i < line; ++i) {
      w = new Window();
      qH.winQ.insert(w);
    }
    
    while(getline(myFile, line)) {
      time = stoi(line);
      for(int i = 0; i < line; ++i) {
        getline(myFile, line);
        s = new Student(time, stoi(line));
        qH.stuQ.insert(s);
      }
    }
  }
  return qH;
}
