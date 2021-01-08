#ifndef GCPU_H
#define GCPU_H

#include <iostream>
#include <fstream>
#include <vector>
#include <stdint.h>

using namespace std;

class Gcpu{
public:
    Gcpu(string file);
    void exec();
    void read();
    uint8_t getRegVal(int index); //Encapsualtion for registers

private:
    int currentInstruction;
    vector<u_int8_t> memory;
    vector<u_int8_t> registers;
    //opcodes
    void OP00(char dest, char val); //mov
    void OP01(int dest); //jmp
    void OP02(int reg, int memAddr); //memp
    void OP03(int reg, int memAddr); //memg
    ifstream fileStream;
    vector<u_int8_t> opcodes;
    size_t length;
};

#endif