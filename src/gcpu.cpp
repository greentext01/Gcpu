#include <iostream>
#include <fstream>
#include "gcpu.h"
#include <sstream>

using namespace std;

Gcpu::Gcpu(string file){
    fileStream = ifstream(file, fstream::in); 
    fileStream.seekg(0, std::ios::end);
    length = fileStream.tellg();
    fileStream.seekg(0, std::ios::beg);
    fill(registers.begin(), registers.end(), 0);
    fill(memory.begin(), memory.end(), 0);
}

void Gcpu::read(){
    for(int i = 0; i < length; i++){
        uint8_t opcode;
        fileStream >> hex >> opcode;
        opcodes.push_back(opcode);
        printf("%X\n", opcodes[i]);
        fill(registers.begin(), registers.end(), 0);
        fill(memory.begin(), memory.end(), 0);
    }
}

void Gcpu::exec(){
    switch(opcodes[currentInstruction]){
        case 00:
            OP00(opcodes[currentInstruction + 1], opcodes[currentInstruction + 2]);
            break;
        case 01:
            OP01(opcodes[currentInstruction + 1]);
            break;
        case 02:
            OP02(opcodes[currentInstruction + 1], opcodes[currentInstruction + 2]);
            break;
        case 03:
            OP03(opcodes[currentInstruction + 1], opcodes[currentInstruction + 2]);
            break;
    }
}

uint8_t Gcpu::getRegVal(int index){
    return registers[index];
}