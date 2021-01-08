#include "gcpu.h"
#include <iostream>
using namespace std;

void Gcpu::OP00(char dest, char val){
    currentInstruction += 3;
    registers[(int)dest] = val;
}

void Gcpu::OP01(int dest){
    currentInstruction = dest;
}

void Gcpu::OP02(int reg, int memAddr){
    currentInstruction += 3;
    memory[memAddr] = registers[reg];
}

void Gcpu::OP03(int reg, int memAddr){
    currentInstruction += 3;
    registers[reg] = memory[memAddr];
}