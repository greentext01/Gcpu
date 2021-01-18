#include "runner.hpp"
using namespace std;

void Runner::OP0C() {
  switch (registers[0]) {
    case 0x00:  // print char
      BIOS00();
      currentInstruction += 1;
      break;
    case 0x01:  // print int (hex)
      BIOS01();
      currentInstruction += 1;
      break;
    case 0x02:  // scan char
      BIOS02();
      currentInstruction += 1;
      break;
    case 0x03:  // scan int (hex)
      BIOS03();
      currentInstruction += 1;
      break;
  }
}
// print char
void Runner::BIOS00() { printf("%c", registers[1]); }

// print int (hex)
void Runner::BIOS01() { printf("%x", registers[1]); }

// scan char
void Runner::BIOS02() { cin >> registers[1]; }

// scan int (hex)
void Runner::BIOS03() {
  u_int8_t buffer;
  cin >> buffer;
  registers[1] = stoi(string(1, buffer), nullptr, 16);
}