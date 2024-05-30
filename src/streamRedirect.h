#pragma once
#pragma

#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class StreamRedirect {
public:
  StreamRedirect(std::ostream &os, const std::string &filename)
      : oldStream(os.rdbuf()), outputStream(&os) {
    fileStream.open(filename, std::ios::out);
    if (!fileStream.is_open()) {
      throw std::runtime_error("Failed to open the file: " + filename);
    }
    os.rdbuf(fileStream.rdbuf());
  }

  ~StreamRedirect() {
    outputStream->rdbuf(oldStream);
    if (fileStream.is_open()) {
      fileStream.close();
    }
  }

private:
  std::ofstream fileStream;
  std::streambuf *oldStream;
  std::ostream *outputStream;
};

inline bool compareFiles(const std::string &filename1,
                         const std::string &filename2) {
  std::ifstream file1(filename1), file2(filename2);
  std::string line1, line2;

  while (!file1.eof() && !file2.eof()) {
    getline(file1, line1);
    getline(file2, line2);
    if (line1 != line2) {
      return false;
    }
  }
  return file1.eof() && file2.eof();
}