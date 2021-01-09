#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <string>
#include <stdint.h>
#include <filesystem>
using namespace std;

class Assembler{
    map<string, u_int8_t> keyStringMap;
    vector<string> readFile;
    int size;
    ifstream file;
    Assembler(string asmPath);
    void readFile();
};

Assembler::Assembler(string asmPath){
    file = ifstream(asmPath);
    
}

void Assembler::readFile(){
    for()
}