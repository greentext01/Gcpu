#include <iostream>
#include "gcpu.h"

using namespace std;

int main(){
    Gcpu gcpu("testProg.bin");
    gcpu.read();
    gcpu.exec();
    gcpu.exec();
    gcpu.exec();
    return EXIT_SUCCESS;
}