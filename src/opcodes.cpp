#include "gcpu.h"
#include <iostream>
using namespace std;

void Gcpu::OP00(u_int8_t dest, u_int8_t val){
    registers[dest] = val;
    currentInstruction += 3;
}

void Gcpu::OP01(u_int8_t dest){
    currentInstruction = dest;
}

void Gcpu::OP02(u_int8_t reg, u_int8_t memAddr){
    memory[memAddr] = registers[reg];
    currentInstruction += 3;
}

void Gcpu::OP03(u_int8_t reg, u_int8_t memAddr){
    registers[reg] = memory[memAddr];
    currentInstruction += 3;
}

void Gcpu::OP04(u_int8_t reg){
    registers[reg]++;
    currentInstruction += 2;
}

void Gcpu::OP05(u_int8_t reg){
    registers[reg]--;
    currentInstruction += 2;
}