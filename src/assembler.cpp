#include "assembler.h"
using namespace std;


Assembler::Assembler(string asmPath, string outputName){
    file = ifstream(asmPath);
    output = ofstream(outputName);
    textToHexMap["mov"] = 0x00;
    textToHexMap["jmp"] = 0x01;
    textToHexMap["memp"] = 0x02;
    textToHexMap["memg"] = 0x03;
    textToHexMap["add"] = 0x04;
    textToHexMap["sub"] = 0x05;
    textToHexMap["comp"] = 0x06;
    textToHexMap["je"] = 0x07;
    textToHexMap["jne"] = 0x08;
    textToHexMap["jb"] = 0x09;
    textToHexMap["js"] = 0x0A;
}

void Assembler::readFile(){
    string currentLine;
    while(getline(file, currentLine)){
        fileLines.push_back(currentLine);
    }
}

void Assembler::build(){
    for(string line : fileLines){
        vector<string> args;
        char* token = strtok((char*)line.c_str(), " ");
        while (token != NULL) {
            args.push_back(token);
            token = strtok(NULL, " "); 
        }
        output << textToHexMap[args[0]];
        for(int i = 1; i < args.size(); i++){
            char outByte = stoi(args[i], nullptr, 16);
            output.write((char*) &outByte, 1);
        }
    }
}