#ifndef GCPU_H
#define GCPU_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Gcpu{
public:
    Gcpu(string file);
    void exec();
    void read();
    int getRegVal(int index); //Encapsualtion for registers

private:
    int currentInstruction;
    char registers[8];
    //opcodes
    void OP00(char dest, char val); //mov
    void OP01(int dest); //jmp
    ifstream fileStream;
    char* opcodes;
    size_t length;
};

#endif