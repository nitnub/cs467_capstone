#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "disassemble8080.h"


int main(int argc, char **argv)
{
    // command line arg validation
    if (argc < 2)
    {
        printf("Usage: %s <romfile>\n", argv[0]);
        exit(1);
    }

    // open the file, "rb"- read binary
    FILE *f = fopen(argv[1], "rb");
    if (f == NULL)
    {
        printf("Couldn't open %s\n", argv[1]);
        exit(1);
    }

    // calculate file size for allocation
    // TODO: Look into more details into ftell() - any alternatives?
    fseek(f, 0L, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0L, SEEK_SET);

    // allocate buffer memory
    unsigned char *buffer = malloc(fsize);
    if (buffer == NULL)
    {
        printf("Could not allocate memory\n");
        fclose(f);
        exit(1);
    }

    // load and close the file
    // TODO: let user know about this many bytes were read from this many
    fread(buffer, 1, fsize, f);
    fclose(f);
    
    // start the disassembly loop
    int pc = 0;

    while (pc < fsize)
    {
        pc += Disassemble8080(buffer, pc);
    }
    
    // cleanup
    free(buffer);
    exit(0);
}
