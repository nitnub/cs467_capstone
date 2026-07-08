#ifndef DISASSEMBLER_H
#define DISASSEMBLER_H
#include <stddef.h>



/**
 * Print the opcodes formatted Intel 8080 ROM file to the terminal.
 * @param fileName name of the file to be read
 * @return 0 on success
 */
int printAssembly(char fileName[]);

/**
 * Print the opCode at a specified location in the buffer (intended as an indirect
 * call, but can be called directly for troubleshooting).
 * @param codeBuffer buffer from valid ROM file
 * @param pc program counter location to print from
 * @return total count of bytes in the operation
 */
int disassemble(const unsigned char *codeBuffer, int pc);

#endif //DISASSEMBLER_H
