#include "runner.hpp"
using namespace std;

Runner::Runner(string file) {
  registers.resize(8);
  memory.resize(255);
  fileStream = ifstream(file);
  currentInstruction = 0;
}

void Runner::read() {
  opcodes = vector<u_int8_t>(std::istreambuf_iterator<char>(fileStream), {});
}

void Runner::exec() {  // Execute the current instruction
  switch (opcodes[currentInstruction]) {
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
    case 0x0B:
      OP0B();
      break;
  }
}

void Runner::printReg() {
  for (int i = 0; i < registers.size(); i++) {
    cout << "(" << i << ") " << hex << (int)registers[i] << endl;
  }
}