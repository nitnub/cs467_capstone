#include <stdlib.h>
#include <stdio.h>

#include "handler.h"

void getInstruction(unsigned char *buffer, struct instructionData *currentIns);
int parseBinary(char *filepath, char *outfile, struct instructionData *currentIns, int romOffset);

/*
* load three bytes into instructionData struct from buffer
*/
void getInstruction(unsigned char *buffer, struct instructionData *currentIns) {

    memmove(&currentIns->instruction, &buffer[0], sizeof(unsigned char));
    memmove(&currentIns->operand1, &buffer[1], sizeof(unsigned char));
    memmove(&currentIns->operand2, &buffer[2], sizeof(unsigned char));

    return;
}

/*
* write assembly to file
*/
int parseBinary(char *filepath, char *outfile, struct instructionData *currentIns, int romOffset) {

    size_t byteCounter = 1;
    unsigned char buffer[3];
    int offset = 0;
    int instructionBytes = 0;
    int cursorStatus;

    // open file
    FILE* rom_ptr = fopen(filepath, "rb");
    FILE* asm_ptr = fopen(outfile, "a");

    while (byteCounter != 0) {

        cursorStatus = fseek(rom_ptr, offset, SEEK_SET);

        printf("0x%04lx: ", ftell(rom_ptr)+romOffset);

        fprintf(asm_ptr, "     0x%04lx: ", ftell(rom_ptr)+romOffset);

        // zero buffer
        memset(buffer, 0, 3*sizeof(unsigned char));

        // read 3 bytes into the buffer starting at location byteCounter
        byteCounter = fread(buffer, sizeof(unsigned char), 3, rom_ptr);
        // printf("0x %02X ", (unsigned char) buffer[0]);
        // printf("%02x ", (unsigned char) buffer[1]);
        // printf("%02x\n", (unsigned char) buffer[2]);
        getInstruction(buffer, currentIns);
        printf("%02X ", currentIns->instruction);
        printf("%02X ", currentIns->operand1);
        printf("%02X  |  ", currentIns->operand2);

        instructionBytes = dispatchLevel2(currentIns);
        printf("%s", currentIns->assembly);

        // print location and assembly to file
        fprintf(asm_ptr, "%02X [%02X %02X]  |   %s\n", currentIns->instruction, currentIns->operand1, currentIns->operand2, currentIns->assembly);

        if (instructionBytes > 0) {
            printf("  |  instructionBytes: %d\n", instructionBytes);
        }
        else {
            printf("\n");
        }

        // increment offset
        offset += 1; // (1 + instructionBytes);
    }

    // close file
    fclose(asm_ptr);
    fclose(rom_ptr);
}

int main(void) {

    char* outfilepath = "invaders.asm";

    //char* rom_filepath = "../space_invaders/invaders.e";
    //char* rom_filepath2 = "../space_invaders/invaders.f";
    //char* rom_filepath3 = "../space_invaders/invaders.g";
    //char* rom_filepath4 = "../space_invaders/invaders.h";

    char *combined_filepath = "./combineRom/combinedRom.e";
    struct instructionData *code = malloc(sizeof(struct instructionData));

    // parseBinary(rom_filepath, code);

    parseBinary(combined_filepath, outfilepath, code, 0);
    //parseBinary(rom_filepath, outfilepath, code, 0);
    //parseBinary(rom_filepath2, outfilepath, code, 0x800);
    //parseBinary(rom_filepath3, outfilepath, code, 0x1000);
    //parseBinary(rom_filepath4, outfilepath, code, 0x1800);

    free(code);
}




