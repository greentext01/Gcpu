#include <iostream>
#include "assembler.h"

using namespace std;

int main(){
    Assembler oasm("testAsm.oasm", "out.bin");
    oasm.readFile();
    oasm.build();
    return EXIT_SUCCESS;
}