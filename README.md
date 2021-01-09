# Gcpu
## Building:
```bash
$ cmake .
$ make
```
Output program is called Gcpu
## Editing:
Edit testProg.bin with a hex editor (I reccommend [Bless](https://github.com/bwrsandman/Bless))
Edit main.cpp and add a ```exec()``` function for each opcode you want to execute.

## Documentation:
```
00: put value in register
01: jump to an opcode
02: put value from register to memory
03: get value from memory to register
04: add value to number from register
05: substract value to number from register
06: compare two numbers from regiters; 0 = equal; 1 = bigger than; 2 = smaller than
07: jump if equal
08: jump if not equal
09: jump if bigger than
0A: jump if smaller than
```
