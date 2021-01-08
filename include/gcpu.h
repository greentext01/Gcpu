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
    void printReg();

private:
    int currentInstruction;
    vector<u_int8_t> memory;
    vector<u_int8_t> registers;
    //opcodes
    void OP00(u_int8_t dest, u_int8_t val); //mov (put value in register)
    void OP01(u_int8_t dest); //jmp (jump to an opcode)
    void OP02(u_int8_t reg, u_int8_t memAddr); //memp (put value from register to memory)
    void OP03(u_int8_t reg, u_int8_t memAddr); //memg (get value from memory to register)
    void OP04(u_int8_t reg); //inc (increment a register)
    void OP05(u_int8_t reg); //dec (decrement a register)
    ifstream fileStream;
    vector<u_int8_t> opcodes;
    size_t length;
};

#endif