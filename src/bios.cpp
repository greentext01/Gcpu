#include "runner.hpp"
using namespace std;

void Runner::OP0C() {
  switch (registers[0]) {
    case 0x00:  // printf
      BIOS00();
      currentInstruction += 1;
      break;
    case 0x01:
      BIOS01();
      currentInstruction += 1;
      break;
  }
}

void Runner::BIOS00() { printf("%c", registers[1]); }

void Runner::BIOS01() { cin >> registers[1]; }