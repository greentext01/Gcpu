#include <iostream>
#include <list>
#include <fstream>
#include <stdint.h>
using namespace std;

class Parser{

protected:
    ifstream fileStream;
    list<uint8_t> opcodes;
    Parser(string file);
    void parse();
};

Parser::Parser(string file){
    fileStream = ifstream(file);
}


void Parser::parse(){
    char buffer[2];
    for(int i = 0; i < 3; i++){
        if()
    }
}