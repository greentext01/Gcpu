#ifndef GCPU_H
#define GCPU_H

#include <stdint.h>
#include <unistd.h>

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Runner {
 public:
  Runner(string file);
  void exec();
  void read();
  void printReg();

 private:
  int currentInstruction;
  vector<u_int8_t> memory;
  vector<u_int8_t> registers;
  // opcodes
  void OP00(u_int8_t dest, u_int8_t val);  // mov (put value in register)
  void OP01(u_int8_t dest);                // jmp (jump to an opcode)
  void OP02(u_int8_t reg,
            u_int8_t memAddr);  // memp (put value from register to memory)
  void OP03(u_int8_t reg,
            u_int8_t memAddr);  // memg (get value from memory to register)
  void OP04(u_int8_t reg,
            u_int8_t amount);  // add (add value to number from register)
  void OP05(u_int8_t reg,
            u_int8_t amount);  // sub (substract value to number from register)
  void OP06(u_int8_t reg1, u_int8_t reg2,
            u_int8_t dest);  // comp (compare two numbers from regiters; 0
                             // = equal; 1 = bigger than; 2 = smaller than)
  void OP07(u_int8_t reg, u_int8_t dest);  // je (jump if equal)
  void OP08(u_int8_t reg, u_int8_t dest);  // jne (jump if not equal)
  void OP09(u_int8_t reg, u_int8_t dest);  // jb (jump if bigger than)
  void OP0A(u_int8_t reg, u_int8_t dest);  // js (jump if smaller than)
  void OP0B();                             // exit
  void OP0C();                             // exec (Very complicated, See wiki)
                                           // TODO set wiki page url

  void BIOS00();  // print char
  void BIOS01();  // print int (hex)
  void BIOS02();  // scan char
  void BIOS03();  // scan int (hex)

  ifstream fileStream;
  vector<u_int8_t> opcodes;
  size_t length;
};

#endif