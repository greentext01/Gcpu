#ifndef GCPU_H
#define GCPU_H

#include <iostream>
#include <fstream>

using namespace std;

class Gcpu{
public:
    Gcpu(string file);
    void exec();
    char registers[8];

private:
    int currentInstruction;
    //opcodes
    void OP00(char src, char dest); //mov
    void OP01(int dest); //jmp
    ifstream fileStream;
    char* opcodes;
    void read();
    size_t length;
};

#endif