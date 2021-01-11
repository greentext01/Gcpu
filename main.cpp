#include <unistd.h>

#include <iostream>

#include "include/assembler.hpp"
#include "include/runner.hpp"
#define HELPTEXT "<SAMPLE HELP TEXT>"

using namespace std;

int main(int argc, char *argv[]) {
  // Usage 1: build -i<input file> -o<output file>
  // Usage 2: run <file>

  // Check first command (is it run or build?)
  if (strcmp(argv[1], "run") == 0) {
    // Run:
    Runner runner(argv[2]);  // argv[2] is the file to build
    runner.read();
    while (true) {  // Run the program
      runner.exec();
      runner.printReg();
      cout << "\n\n\n";
    }
  } else if (strcmp(argv[1], "build") == 0) {
    // Build:
    int opt;
    string output;
    string input;
    while ((opt = getopt(argc, argv, "o:i:")) != -1) {
      switch (opt) {
        case 'o':
          output = optarg;
          break;
        case 'i':
          input = optarg;
          cout << optarg;
          break;
        default:
          cout << HELPTEXT << endl;
          break;
      }
    }
    // Is the input option not set?
    if (input.empty()) {
      cout << "Error: You must set an input using the -i option (-h for help)"
           << endl;
      return EXIT_FAILURE;
    }
    // Is the output option not set?
    if (output.empty()) {
      // Set the output variable to "a.out"
      output = "a.out";
    }
    Assembler oasm(input, output);
    oasm.readFile();
    oasm.build();
    return EXIT_SUCCESS;
  } else {
    cout << HELPTEXT << endl;
    return EXIT_FAILURE;
  }
}