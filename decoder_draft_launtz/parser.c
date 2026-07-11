#include <stdlib.h>
#include <stdio.h>

#include "handler.h"


/*
* load three bytes into instructionData struct from buffer
*/
void getInstruction(unsigned char *buffer, struct instructionData *currentIns) {

    memmove(&currentIns->instruction, &buffer[0], sizeof(unsigned char));
    memmove(&currentIns->operand1, &buffer[1], sizeof(unsigned char));
    memmove(&currentIns->operand2, &buffer[2], sizeof(unsigned char));

    return;
}

int parseBinary(char *filepath, struct instructionData *currentIns) {

    size_t byteCounter = 1;
    unsigned char buffer[3];
    int offset = 0;
    int instructionBytes = 0;
    int cursorStatus;

    // open file
    FILE* rom_ptr = fopen(filepath, "rb");

    while (byteCounter != 0) {

        cursorStatus = fseek(rom_ptr, offset, SEEK_SET);

        printf("0x%02lx: ", ftell(rom_ptr));

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

        if (instructionBytes > 0) {
            printf("  |  instructionBytes: %d\n", instructionBytes);
        }
        else {
            printf("\n");
        }


        // increment offset
        offset += (1 + instructionBytes);
    }



    // print second byte in hex (operand1)


    // print third byte in hex (operand 2)
    

    // increment byte location


    // close file
    fclose(rom_ptr);
}

int main(void) {

    char* rom_filepath = "../space_invaders/invaders.e";
    struct instructionData *code = malloc(sizeof(struct instructionData));

    parseBinary(rom_filepath, code);

    free(code);
}




