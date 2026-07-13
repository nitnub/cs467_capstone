#include "romCombine.h"


int romCombine(char *filepath1, char *completeRomPath) {
    FILE* rom_ptr1 = fopen(filepath1, "rb");

    if (rom_ptr1 == NULL) {
        printf("error: file failed to open!\n");
        return -1;
    }

    FILE* dest_ptr = fopen(completeRomPath, "ab");

    if (dest_ptr == NULL) {
        printf("error: output file failed to open\n");
        return -1;
    }

    unsigned char buffer[64];
    int readCount =1;
    int writeCount;

    // read in bytes to the buffer until there are no more bytes to be read
    while ((readCount = fread(buffer, sizeof(unsigned char), sizeof(buffer), rom_ptr1)) > 0) {

        writeCount = fwrite(buffer, sizeof(unsigned char), readCount, dest_ptr);

        if (readCount != writeCount) {
            printf("error appending binary data to new file");
        }

    }
    
    // close files that were opened
    fclose(dest_ptr);
    fclose(rom_ptr1);
    return 0;
}

int main(void) {

    char* fp1="../../space_invaders/invaders.e";
    char* fp2="../../space_invaders/invaders.f";
    char* fp3="../../space_invaders/invaders.g";
    char* fp4="../../space_invaders/invaders.h";
    char* outfile="combinedRom.e";

    // clear the output file
    FILE *ptr = fopen(outfile, "w");
    fclose(ptr);

    romCombine(fp4, outfile);
    romCombine(fp3, outfile);
    romCombine(fp2, outfile);
    romCombine(fp1, outfile);

}