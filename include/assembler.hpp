#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <stdint.h>
#include <string.h>

#include <fstream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

class Assembler {
 public:
  void readFile();
  void build();
  Assembler(string inputName, string outputName);

 private:
  map<string, u_int8_t> textToHexMap;
  vector<string> fileLines;
  ifstream file;
  ofstream output;
};

#endif