#include <iostream>
#include "gcpu.h"

using namespace std;

int main(){
    Gcpu gcpu("testProg.bin");
    gcpu.registers[5] = 'E';
    gcpu.exec();
    cout << gcpu.registers[3];
    return EXIT_SUCCESS;
}