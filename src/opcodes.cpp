#include "runner.hpp"
using namespace std;

void Runner::OP00(u_int8_t dest, u_int8_t val) {
  // mov (put value in register)
  registers[dest] = val;
  currentInstruction += 3;
}

void Runner::OP01(u_int8_t dest) {
  // jmp (jump to an opcode)
  currentInstruction = dest;
}

void Runner::OP02(u_int8_t reg, u_int8_t memAddr) {
  // memp (put value from register to memory)
  memory[memAddr] = registers[reg];
  currentInstruction += 3;
}

void Runner::OP03(u_int8_t reg, u_int8_t memAddr) {
  // memg (get value from memory to register)
  registers[reg] = memory[memAddr];
  currentInstruction += 3;
}

void Runner::OP04(u_int8_t reg, uint8_t amount) {
  // add (add value to number from register)
  registers[reg] += amount;
  currentInstruction += 3;
}

void Runner::OP05(u_int8_t reg, uint8_t amount) {
  // sub (substract value to number from register)
  registers[reg] -= amount;
  currentInstruction += 3;
}

void Runner::OP06(u_int8_t reg1, u_int8_t reg2, u_int8_t destinationReg) {
  // comp (compare two numbers from regiters; 0 = equal; 1 = bigger than; 2 =
  // smaller than)
  if (registers[reg1] == registers[reg2]) {
    registers[destinationReg] = 0;
  } else if (registers[reg1] > registers[reg2]) {
    registers[destinationReg] = 1;
  } else if (registers[reg1] < registers[reg2]) {
    registers[destinationReg] = 2;
  }
  currentInstruction += 4;
}

void Runner::OP07(u_int8_t reg, u_int8_t dest) {
  // je (jump if equal)
  if (registers[reg] == 0) {
    currentInstruction = dest;
  } else {
    currentInstruction += 3;
  }
}

void Runner::OP08(u_int8_t reg, u_int8_t dest) {
  // jne (jump if not equal)
  if (registers[reg] == 1 | registers[reg] == 2) {
    currentInstruction = dest;
  } else {
    currentInstruction += 3;
  }
}

void Runner::OP09(u_int8_t reg, u_int8_t dest) {
  // jb (jump if bigger than)
  if (registers[reg] == 1) {
    currentInstruction = dest;
  } else {
    currentInstruction += 3;
  }
}

void Runner::OP0A(u_int8_t reg, u_int8_t dest) {
  if (registers[reg] == 2) {
    currentInstruction = dest;
  } else {
    currentInstruction += 3;
  }
  // js (jump if smaller than)
}

void Runner::OP0B() { exit(0); }