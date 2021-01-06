#include <iostream>
#include <fstream>
#include "gcpu.h"

using namespace std;

Gcpu::Gcpu(string file){
    fileStream = ifstream(file, ios::binary); 
    fileStream.seekg(0, std::ios::end);
    length = fileStream.tellg();
    fileStream.seekg(0, std::ios::beg);
    opcodes = new char[length];
}

void Gcpu::read(){
    fileStream.read(opcodes, length);
}

void Gcpu::OP00(char src, char dest){
    currentInstruction += 3;
    registers[(int)dest] = registers[(int)src];
}

void Gcpu::exec(){
    switch((int) *(opcodes + currentInstruction)){
        case 00:
            OP00(*(opcodes + currentInstruction + 1), *(opcodes + currentInstruction + 2));
            break;
    }
}