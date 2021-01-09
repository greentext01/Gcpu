#include "gcpu.h"
using namespace std;

Gcpu::Gcpu(string file){
    fileStream = ifstream(file, ios::binary); 
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
        case 0x00:
            OP00(opcodes[currentInstruction + 1], opcodes[currentInstruction + 2]);
            break;
        case 0x01:
            OP01(opcodes[currentInstruction + 1]);
            break;
        case 0x02:
            OP02(opcodes[currentInstruction + 1], opcodes[currentInstruction + 2]);
            break;
        case 0x03:
            OP03(opcodes[currentInstruction + 1], opcodes[currentInstruction + 2]);
            break;
        case 0x04:
            OP04(opcodes[currentInstruction + 1], opcodes[currentInstruction + 2]);
            break;
        case 0x05:
            OP05(opcodes[currentInstruction + 1], opcodes[currentInstruction + 2]);
            break;
        case 0x06:
            OP06(opcodes[currentInstruction + 1], opcodes[currentInstruction + 2], 
            opcodes[currentInstruction + 3]);
            break;
        case 0x07:
            OP07(opcodes[currentInstruction + 1], opcodes[currentInstruction + 2]);
            break;
        case 0x08:
            OP08(opcodes[currentInstruction + 1], opcodes[currentInstruction + 2]);
            break;
        case 0x09:
            OP09(opcodes[currentInstruction + 1], opcodes[currentInstruction + 2]);
            break;
        case 0x0A:
            OP0A(opcodes[currentInstruction + 1], opcodes[currentInstruction + 2]);
            break;

    }
}

void Gcpu::printReg(){
    for(int i = 0; i < registers.size(); i++){
        cout << "(" << i << ") " << hex << (int)registers[i] << endl;
    }
}