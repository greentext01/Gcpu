#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <map>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdint.h>
#include <sstream>
using namespace std;

class Assembler{
public:
    void readFile();
    void build();
    Assembler(string inputName, string outputName);

private:
    map<string, u_int8_t> textToHexMap;
    vector<string> fileLines;
    int size;
    ifstream file;
    ofstream output;
};

#endif