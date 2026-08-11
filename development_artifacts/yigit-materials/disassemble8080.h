#ifndef DISASSEMBLE8080_H
#define DISASSEMBLE8080_H

/**
 * Decode and print one Intel 8080 instruction from a ROM buffer.
 *
 * Reads the opcode byte at codebuffer[pc], writes its address and
 * mnemonic to stdout
 *
 * @param codebuffer  pointer to raw ROM bytes
 * @param pc                    byte offset of the instruction to decode
 * @return           instruction length in bytes
 */

int Disassemble8080(unsigned char *codebuffer, int pc);

#endif // DISASSEMBLE8080_H
