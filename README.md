# Gcpu
## Building:
```bash
$ cmake .
$ make
```
Output program is called Gcpu
## Editing:
Edit testProg.bin with a hex editor (I reccommend [Bless](https://github.com/bwrsandman/Bless))

## Documentation:
```
00: put value in register
01: jump to an opcode
02: put value from register to memory
03: get value from memory to register
04: add value to number from register
05: substract value to number from register
```
