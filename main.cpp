#include <iostream>
#include "gcpu.h"

using namespace std;

int main(){
    Gcpu gcpu("testProg.bin");
    gcpu.read();
    gcpu.exec();
    for(int i = 0; i < 8; i++){
        cout << "(" << hex << i << ")" << gcpu.getRegVal(i) << endl;
    }
    return EXIT_SUCCESS;
}