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
    registers.resize(8);
    memory.resize(255);
    opcodes.resize(8);
}

void Gcpu::read(){
    for(int i = 0; i < length; i++){
        uint8_t opcode;
        fileStream >> hex >> opcode;
        opcodes[i] = opcode;
    }
}

void Gcpu::exec(){ //Execute the current instruction
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
        case 04:
            OP04(opcodes[currentInstruction + 1], opcodes[currentInstruction + 2]);
            break;
        case 05:
            OP05(opcodes[currentInstruction + 1], opcodes[currentInstruction + 2]);
            break;
        
    }
}

void Gcpu::printReg(){
    for(int i = 0; i < registers.size(); i++){
        cout << "(" << i << ") " << hex << (int)registers[i] << endl;
    }
}