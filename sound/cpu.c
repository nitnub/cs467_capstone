/*
 * cpu.c // a cpu skeleton with a simple I/O hook to test the sound
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct ConditionCodes {
    uint8_t    z:1;
    uint8_t    s:1;
    uint8_t    p:1;
    uint8_t    cy:1;
    uint8_t    ac:1;
    uint8_t    pad:3;
} ConditionCodes;

typedef struct State8080 {
    uint8_t    a;
    uint8_t    b;
    uint8_t    c;
    uint8_t    d;
    uint8_t    e;
    uint8_t    h;
    uint8_t    l;
    uint16_t   sp;
    uint16_t   pc;
    uint8_t    *memory;
    ConditionCodes cc;
    uint8_t    int_enable;

    // Simple I/O hooks
    void (*out_port)(uint8_t port, uint8_t value);
    uint8_t (*in_port)(uint8_t port);
} State8080;

void UnimplementedInstruction(State8080 *state)
{
    printf("Error: unimplemented instruction (opcode 0x%02x at pc=0x%04x)\n",
           state->memory[state->pc], state->pc);
    exit(1);
}

void UndocumentedInstruction(State8080* state)
{
    printf("Error: Undocumented instruction at 0x%04x\n", state->pc);
    exit(1);
}

// Parity: returns 1 if the number of set bits in the low 'size' bits of x is even
int Parity(int x, int size)
{
    int i;
    int p = 0;
    x = (x & ((1 << size) - 1));
    for (i = 0; i < size; i++)
    {
        if (x & 0x1) p++;
        x = x >> 1;
    }
    return (0 == (p & 0x1));
}

int Emulate8080(State8080* state)
{
    unsigned char *opcode = &(state->memory[state->pc]);

    switch (*opcode)
    {
        // NOP
        case 0x00: break;
    
        // LXI B,word -- load BC with 16-bit immediate
        case 0x01:
            state->c = opcode[1];
            state->b = opcode[2];
            state->pc += 2;
            break;
        
        // STAX B -- store A at address in BC
        case 0x02:
        {
            uint16_t addr = (state->b << 8) | state->c; // combine B (hi) and C (lo)
            state->memory[addr] = state->a;
            break;
        }
            
        // INX B -- increment BC (no flags)
        case 0x03:
        {
            uint16_t bc = (state->b << 8) | state->c;
            bc += 1;
            state->b = (bc >> 8) & 0xff;             // separate the bytes after addition
            state->c = bc & 0xff;
            break;
        }

        // INR B -- increment B, Z/S/P (no CY)
        case 0x04:
            state->b += 1;
            state->cc.z = (state->b == 0);
            state->cc.s = (0x80 == (state->b & 0x80));
            state->cc.p = Parity(state->b, 8);
            break;
            
        // DCR B -- decrement B, Z/S/P (no CY)
        case 0x05:
            state->b -= 1;
            state->cc.z = (state->b == 0);
            state->cc.s = (0x80 == (state->b & 0x80));
            state->cc.p = Parity(state->b, 8);
            break;

        // MVI B,d8 -- load immediate byte into B
        case 0x06:
            state->b = opcode[1];
            state->pc += 1;
            break;

        // RLC -- rotate A left, bit7 -> CY and bit0
        case 0x07:
        {
            uint8_t x = state->a;
            state->a = ((x << 1) | (x >> 7));
            state->cc.cy = (0x80 == (x & 0x80));
            break;
        }
        
        // NOP
        case 0x08: break;

        // DAD B -- HL += BC, sets CY only
        case 0x09:
        {
            uint32_t hl = (state->h << 8) | state->l;
            uint32_t bc = (state->b << 8) | state->c;
            uint32_t res = hl + bc;
            state->h = (res >> 8) & 0xff;
            state->l = res & 0xff;
            state->cc.cy = (res > 0xffff);
            break;
        }

        // LDAX B -- load A from address in BC
        case 0x0a:
        {
            uint16_t addr = (state->b << 8) | state->c;
            state->a = state->memory[addr];
            break;
        }
    
        // DCX B -- decrement BC (no flags)
        case 0x0b:
        {
            uint16_t bc = (state->b << 8) | state->c;
            bc -= 1;
            state->b = (bc >> 8) & 0xff;
            state->c = bc & 0xff;
            break;
        }
        
        // INR C
        case 0x0c:
            state->c += 1;
            state->cc.z = (state->c == 0);
            state->cc.s = (0x80 == (state->c & 0x80));
            state->cc.p = Parity(state->c, 8);
            break;

        // DCR C
        case 0x0d:
            state->c -= 1;
            state->cc.z = (state->c == 0);
            state->cc.s = (0x80 == (state->c & 0x80));
            state->cc.p = Parity(state->c, 8);
            break;

        // MVI C,d8
        case 0x0e:
            state->c = opcode[1];
            state->pc += 1;
            break;

        // RRC -- rotate A right, bit0 -> CY and bit7
        case 0x0f:
        {
            uint8_t x = state->a;
            state->a = ((x >> 1) | (x << 7));
            state->cc.cy = (0x01 == (x & 0x01));
            break;
        }

        // NOP
        case 0x10: break;

        // LXI D,word
        case 0x11:
            state->e = opcode[1];
            state->d = opcode[2];
            state->pc += 2;
            break;

        // STAX D -- store A at address in DE
        case 0x12:
        {
            uint16_t addr = (state->d << 8) | state->e;
            state->memory[addr] = state->a;
            break;
        }

        // INX D
        case 0x13:
        {
            uint16_t de = (state->d << 8) | state->e;
            de += 1;
            state->d = (de >> 8) & 0xff;
            state->e = de & 0xff;
            break;
        }

        // INR D
        case 0x14:
            state->d += 1;
            state->cc.z = (state->d == 0);
            state->cc.s = (0x80 == (state->d & 0x80));
            state->cc.p = Parity(state->d, 8);
            break;

        // DCR D
        case 0x15:
            state->d -= 1;
            state->cc.z = (state->d == 0);
            state->cc.s = (0x80 == (state->d & 0x80));
            state->cc.p = Parity(state->d, 8);
            break;

        // MVI D,d8
        case 0x16:
            state->d = opcode[1];
            state->pc += 1;
            break;

        // RAL -- rotate A left through CY
        case 0x17:
        {
            uint8_t x = state->a;
            state->a = (x << 1) | state->cc.cy;
            state->cc.cy = (0x80 == (x & 0x80));
            break;
        }

        // NOP
        case 0x18: break;

        // DAD D -- HL += DE
        case 0x19:
        {
            uint32_t hl = (state->h << 8) | state->l;
            uint32_t de = (state->d << 8) | state->e;
            uint32_t res = hl + de;
            state->h = (res >> 8) & 0xff;
            state->l = res & 0xff;
            state->cc.cy = (res > 0xffff);
            break;
        }

        // LDAX D -- load A from address in DE
        case 0x1a:
        {
            uint16_t addr = (state->d << 8) | state->e;
            state->a = state->memory[addr];
            break;
        }

        // DCX D
        case 0x1b:
        {
            uint16_t de = (state->d << 8) | state->e;
            de -= 1;
            state->d = (de >> 8) & 0xff;
            state->e = de & 0xff;
            break;
        }

        // INR E
        case 0x1c:
            state->e += 1;
            state->cc.z = (state->e == 0);
            state->cc.s = (0x80 == (state->e & 0x80));
            state->cc.p = Parity(state->e, 8);
            break;

        // DCR E
        case 0x1d:
            state->e -= 1;
            state->cc.z = (state->e == 0);
            state->cc.s = (0x80 == (state->e & 0x80));
            state->cc.p = Parity(state->e, 8);
            break;

        // MVI E,d8
        case 0x1e:
            state->e = opcode[1];
            state->pc += 1;
            break;
    
        // RAR -- rotate A right through CY
        case 0x1f:
        {
            uint8_t x = state->a;
            state->a = (x >> 1) | (state->cc.cy << 7);
            state->cc.cy = (0x01 == (x & 0x01));
            break;
        }

        // NOP
        case 0x20: break;

        // LXI H,word
        case 0x21:
            state->l = opcode[1];
            state->h = opcode[2];
            state->pc += 2;
            break;

        // SHLD a16 -- store L,H to address, address+1
        case 0x22:
        {
            uint16_t addr = (opcode[2] << 8) | opcode[1];
            state->memory[addr] = state->l;
            state->memory[addr + 1] = state->h;
            state->pc += 2;
            break;
        }
    
        // INX H
        case 0x23:
        {
            uint16_t hl = (state->h << 8) | state->l;
            hl += 1;
            state->h = (hl >> 8) & 0xff;
            state->l = hl & 0xff;
            break;
        }

        // INR H
        case 0x24:
            state->h += 1;
            state->cc.z = (state->h == 0);
            state->cc.s = (0x80 == (state->h & 0x80));
            state->cc.p = Parity(state->h, 8);
            break;

        // DCR H
        case 0x25:
            state->h -= 1;
            state->cc.z = (state->h == 0);
            state->cc.s = (0x80 == (state->h & 0x80));
            state->cc.p = Parity(state->h, 8);
            break;

        // MVI H,d8
        case 0x26:
            state->h = opcode[1];
            state->pc += 1;
            break;

        // DAA -- decimal adjust A (BCD correction).
        case 0x27:
        {
            uint8_t a = state->a;
            uint8_t carry = state->cc.cy;
            uint8_t correction = 0;

            if ((a & 0x0f) > 9 || state->cc.ac)
            {
                correction |= 0x06;
            }
            if ((a >> 4) > 9 || carry || (((a >> 4) == 9) && ((a & 0x0f) > 9)))
            {
                correction |= 0x60;
                carry = 1;
            }

            uint16_t r = (uint16_t)a + correction;
            state->cc.ac = (((a & 0x0f) + (correction & 0x0f)) > 0x0f);
            state->a = r & 0xff;
            state->cc.cy = carry;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;
        }

        // NOP
        case 0x28: break;

        // DAD H -- HL += HL
        case 0x29:
        {
            uint32_t hl = (state->h << 8) | state->l;
            uint32_t res = hl + hl;
            state->h = (res >> 8) & 0xff;
            state->l = res & 0xff;
            state->cc.cy = (res > 0xffff);
            break;
        }

        // LHLD a16 -- load L,H from address, address+1
        case 0x2a:
        {
            uint16_t addr = (opcode[2] << 8) | opcode[1];
            state->l = state->memory[addr];
            state->h = state->memory[addr + 1];
            state->pc += 2;
            break;
        }

        // DCX H
        case 0x2b:
        {
            uint16_t hl = (state->h << 8) | state->l;
            hl -= 1;
            state->h = (hl >> 8) & 0xff;
            state->l = hl & 0xff;
            break;
        }

        // INR L
        case 0x2c:
            state->l += 1;
            state->cc.z = (state->l == 0);
            state->cc.s = (0x80 == (state->l & 0x80));
            state->cc.p = Parity(state->l, 8);
            break;

        // DCR L
        case 0x2d:
            state->l -= 1;
            state->cc.z = (state->l == 0);
            state->cc.s = (0x80 == (state->l & 0x80));
            state->cc.p = Parity(state->l, 8);
            break;

        // MVI L,d8
        case 0x2e:
            state->l = opcode[1];
            state->pc += 1;
            break;

        // CMA -- complement A (no flags affected)
        case 0x2f:
            state->a = ~state->a;
            break;

        // NOP
        case 0x30: break;

        // LXI SP,word
        case 0x31:
            state->sp = (opcode[2] << 8) | opcode[1];
            state->pc += 2;
            break;

        // STA a16 -- store A directly to address
        case 0x32:
        {
            uint16_t addr = (opcode[2] << 8) | opcode[1];
            state->memory[addr] = state->a;
            state->pc += 2;
            break;
        }

        // INX SP
        case 0x33:
            state->sp += 1;
            break;

        // INR M -- increment byte at address HL
        case 0x34:
        {
            uint16_t addr = (state->h << 8) | state->l;
            uint8_t res = state->memory[addr] + 1;
            state->memory[addr] = res;
            state->cc.z = (res == 0);
            state->cc.s = (0x80 == (res & 0x80));
            state->cc.p = Parity(res, 8);
            break;
        }

        // DCR M -- decrement byte at address HL
        case 0x35:
        {
            uint16_t addr = (state->h << 8) | state->l;
            uint8_t res = state->memory[addr] - 1;
            state->memory[addr] = res;
            state->cc.z = (res == 0);
            state->cc.s = (0x80 == (res & 0x80));
            state->cc.p = Parity(res, 8);
            break;
        }

        // MVI M,d8 -- store immediate byte at address HL
        case 0x36:
        {
            uint16_t addr = (state->h << 8) | state->l;
            state->memory[addr] = opcode[1];
            state->pc += 1;
            break;
        }

        // STC -- set carry flag
        case 0x37:
            state->cc.cy = 1;
            break;

        // NOP
        case 0x38: break;

        // DAD SP -- HL += SP
        case 0x39:
        {
            uint32_t hl = (state->h << 8) | state->l;
            uint32_t res = hl + state->sp;
            state->h = (res >> 8) & 0xff;
            state->l = res & 0xff;
            state->cc.cy = (res > 0xffff);
            break;
        }

        // LDA a16 -- load A directly from address
        case 0x3a:
        {
            uint16_t addr = (opcode[2] << 8) | opcode[1];
            state->a = state->memory[addr];
            state->pc += 2;
            break;
        }

        // DCX SP
        case 0x3b:
            state->sp -= 1;
            break;

        // INR A
        case 0x3c:
            state->a += 1;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;

        // DCR A
        case 0x3d:
            state->a -= 1;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;

        // MVI A,d8
        case 0x3e:
            state->a = opcode[1];
            state->pc += 1;
            break;

        // CMC -- complement carry flag
        case 0x3f:
            state->cc.cy = !state->cc.cy;
            break;


        // MOV B,B
        case 0x40: state->b = state->b; break;
        // MOV B,C
        case 0x41: state->b = state->c; break;
        // MOV B,D
        case 0x42: state->b = state->d; break;
        // MOV B,E
        case 0x43: state->b = state->e; break;
        // MOV B,H
        case 0x44: state->b = state->h; break;
        // MOV B,L
        case 0x45: state->b = state->l; break;
        // MOV B,M
        case 0x46: state->b = state->memory[(state->h << 8) | state->l]; break;
        // MOV B,A
        case 0x47: state->b = state->a; break;

        // MOV C,B
        case 0x48: state->c = state->b; break;
        // MOV C,C
        case 0x49: state->c = state->c; break;
        // MOV C,D
        case 0x4a: state->c = state->d; break;
        // MOV C,E
        case 0x4b: state->c = state->e; break;
        // MOV C,H
        case 0x4c: state->c = state->h; break;
        // MOV C,L
        case 0x4d: state->c = state->l; break;
        // MOV C,M
        case 0x4e: state->c = state->memory[(state->h << 8) | state->l]; break;
        // MOV C,A
        case 0x4f: state->c = state->a; break;

        // MOV D,B
        case 0x50: state->d = state->b; break;
        // MOV D,C
        case 0x51: state->d = state->c; break;
        // MOV D,D
        case 0x52: state->d = state->d; break;
        // MOV D,E
        case 0x53: state->d = state->e; break;
        // MOV D,H
        case 0x54: state->d = state->h; break;
        // MOV D,L
        case 0x55: state->d = state->l; break;
        // MOV D,M
        case 0x56: state->d = state->memory[(state->h << 8) | state->l]; break;
        // MOV D,A
        case 0x57: state->d = state->a; break;

        // MOV E,B
        case 0x58: state->e = state->b; break;
        // MOV E,C
        case 0x59: state->e = state->c; break;
        // MOV E,D
        case 0x5a: state->e = state->d; break;
        // MOV E,E
        case 0x5b: state->e = state->e; break;
        // MOV E,H
        case 0x5c: state->e = state->h; break;
        // MOV E,L
        case 0x5d: state->e = state->l; break;
        // MOV E,M
        case 0x5e: state->e = state->memory[(state->h << 8) | state->l]; break;
        // MOV E,A
        case 0x5f: state->e = state->a; break;

        // MOV H,B
        case 0x60: state->h = state->b; break;
        // MOV H,C
        case 0x61: state->h = state->c; break;
        // MOV H,D
        case 0x62: state->h = state->d; break;
        // MOV H,E
        case 0x63: state->h = state->e; break;
        // MOV H,H
        case 0x64: state->h = state->h; break;
        // MOV H,L
        case 0x65: state->h = state->l; break;
        // MOV H,M
        case 0x66: state->h = state->memory[(state->h << 8) | state->l]; break;
        // MOV H,A
        case 0x67: state->h = state->a; break;

        // MOV L,B
        case 0x68: state->l = state->b; break;
        // MOV L,C
        case 0x69: state->l = state->c; break;
        // MOV L,D
        case 0x6a: state->l = state->d; break;
        // MOV L,E
        case 0x6b: state->l = state->e; break;
        // MOV L,H
        case 0x6c: state->l = state->h; break;
        // MOV L,L
        case 0x6d: state->l = state->l; break;
        // MOV L,M
        case 0x6e: state->l = state->memory[(state->h << 8) | state->l]; break;
        // MOV L,A
        case 0x6f: state->l = state->a; break;

        // MOV M,B
        case 0x70: state->memory[(state->h << 8) | state->l] = state->b; break;
        // MOV M,C
        case 0x71: state->memory[(state->h << 8) | state->l] = state->c; break;
        // MOV M,D
        case 0x72: state->memory[(state->h << 8) | state->l] = state->d; break;
        // MOV M,E
        case 0x73: state->memory[(state->h << 8) | state->l] = state->e; break;
        // MOV M,H
        case 0x74: state->memory[(state->h << 8) | state->l] = state->h; break;
        // MOV M,L
        case 0x75: state->memory[(state->h << 8) | state->l] = state->l; break;

        // HLT -- halt the CPU
        case 0x76:
            exit(0);
            break;

        // MOV M,A
        case 0x77: state->memory[(state->h << 8) | state->l] = state->a; break;
        // MOV A,B
        case 0x78: state->a = state->b; break;
        // MOV A,C
        case 0x79: state->a = state->c; break;
        // MOV A,D
        case 0x7a: state->a = state->d; break;
        // MOV A,E
        case 0x7b: state->a = state->e; break;
        // MOV A,H
        case 0x7c: state->a = state->h; break;
        // MOV A,L
        case 0x7d: state->a = state->l; break;
        // MOV A,M
        case 0x7e: state->a = state->memory[(state->h << 8) | state->l]; break;
        // MOV A,A
        case 0x7f: state->a = state->a; break;


        // ADD B
        case 0x80:
        {
            uint16_t r = (uint16_t)state->a + state->b;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // ADD C
        case 0x81:
        {
            uint16_t r = (uint16_t)state->a + state->c;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // ADD D
        case 0x82:
        {
            uint16_t r = (uint16_t)state->a + state->d;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // ADD E
        case 0x83:
        {
            uint16_t r = (uint16_t)state->a + state->e;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // ADD H
        case 0x84:
        {
            uint16_t r = (uint16_t)state->a + state->h;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // ADD L
        case 0x85:
        {
            uint16_t r = (uint16_t)state->a + state->l;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // ADD M
        case 0x86:
        {
            uint8_t m = state->memory[(state->h << 8) | state->l];
            uint16_t r = (uint16_t)state->a + m;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // ADD A
        case 0x87:
        {
            uint16_t r = (uint16_t)state->a + state->a;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }

        // ADC B
        case 0x88:
        {
            uint16_t r = (uint16_t)state->a + state->b + state->cc.cy;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // ADC C
        case 0x89:
        {
            uint16_t r = (uint16_t)state->a + state->c + state->cc.cy;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // ADC D
        case 0x8a:
        {
            uint16_t r = (uint16_t)state->a + state->d + state->cc.cy;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // ADC E
        case 0x8b:
        {
            uint16_t r = (uint16_t)state->a + state->e + state->cc.cy;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // ADC H
        case 0x8c:
        {
            uint16_t r = (uint16_t)state->a + state->h + state->cc.cy;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // ADC L
        case 0x8d:
        {
            uint16_t r = (uint16_t)state->a + state->l + state->cc.cy;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // ADC M
        case 0x8e:
        {
            uint8_t m = state->memory[(state->h << 8) | state->l];
            uint16_t r = (uint16_t)state->a + m + state->cc.cy;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // ADC A
        case 0x8f:
        {
            uint16_t r = (uint16_t)state->a + state->a + state->cc.cy;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }

        // SUB B
        case 0x90:
        {
            uint16_t r = (uint16_t)state->a - state->b;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // SUB C
        case 0x91:
        {
            uint16_t r = (uint16_t)state->a - state->c;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // SUB D
        case 0x92:
        {
            uint16_t r = (uint16_t)state->a - state->d;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // SUB E
        case 0x93:
        {
            uint16_t r = (uint16_t)state->a - state->e;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // SUB H
        case 0x94:
        {
            uint16_t r = (uint16_t)state->a - state->h;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // SUB L
        case 0x95:
        {
            uint16_t r = (uint16_t)state->a - state->l;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // SUB M
        case 0x96:
        {
            uint8_t m = state->memory[(state->h << 8) | state->l];
            uint16_t r = (uint16_t)state->a - m;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // SUB A
        case 0x97:
        {
            uint16_t r = (uint16_t)state->a - state->a;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }

        // SBB B
        case 0x98:
        {
            uint16_t r = (uint16_t)state->a - state->b - state->cc.cy;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // SBB C
        case 0x99:
        {
            uint16_t r = (uint16_t)state->a - state->c - state->cc.cy;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // SBB D
        case 0x9a:
        {
            uint16_t r = (uint16_t)state->a - state->d - state->cc.cy;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // SBB E
        case 0x9b:
        {
            uint16_t r = (uint16_t)state->a - state->e - state->cc.cy;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // SBB H
        case 0x9c:
        {
            uint16_t r = (uint16_t)state->a - state->h - state->cc.cy;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // SBB L
        case 0x9d:
        {
            uint16_t r = (uint16_t)state->a - state->l - state->cc.cy;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // SBB M
        case 0x9e:
        {
            uint8_t m = state->memory[(state->h << 8) | state->l];
            uint16_t r = (uint16_t)state->a - m - state->cc.cy;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }
        // SBB A
        case 0x9f:
        {
            uint16_t r = (uint16_t)state->a - state->a - state->cc.cy;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            break;
        }

        // ANA/XRA/ORA all clear CY and AC on real hardware, then set Z/S/P from A.
        // ANA B
        case 0xa0:
            state->a &= state->b;
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;
        // ANA C
        case 0xa1:
            state->a &= state->c;
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;
        // ANA D
        case 0xa2:
            state->a &= state->d;
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;
        // ANA E
        case 0xa3:
            state->a &= state->e;
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;
        // ANA H
        case 0xa4:
            state->a &= state->h;
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;
        // ANA L
        case 0xa5:
            state->a &= state->l;
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;
        // ANA M
        case 0xa6:
            state->a &= state->memory[(state->h << 8) | state->l];
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;
        // ANA A
        case 0xa7:
            state->a &= state->a;
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;

        // XRA B
        case 0xa8:
            state->a ^= state->b;
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;
        // XRA C
        case 0xa9:
            state->a ^= state->c;
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;
        // XRA D
        case 0xaa:
            state->a ^= state->d;
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;
        // XRA E
        case 0xab:
            state->a ^= state->e;
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;
        // XRA H
        case 0xac:
            state->a ^= state->h;
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;
        // XRA L
        case 0xad:
            state->a ^= state->l;
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;
        // XRA M
        case 0xae:
            state->a ^= state->memory[(state->h << 8) | state->l];
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;
        // XRA A
        case 0xaf:
            state->a ^= state->a;
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;

        // ORA B
        case 0xb0:
            state->a |= state->b;
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;
        // ORA C
        case 0xb1:
            state->a |= state->c;
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;
        // ORA D
        case 0xb2:
            state->a |= state->d;
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;
        // ORA E
        case 0xb3:
            state->a |= state->e;
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;
        // ORA H
        case 0xb4:
            state->a |= state->h;
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;
        // ORA L
        case 0xb5:
            state->a |= state->l;
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;
        // ORA M
        case 0xb6:
            state->a |= state->memory[(state->h << 8) | state->l];
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;
        // ORA A
        case 0xb7:
            state->a |= state->a;
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            break;

        // NOTE: CMP does the same subtraction as SUB, but discards the result
        // A itself is never written, only the flags are affected.
        // CMP B
        case 0xb8:
        {
            uint16_t r = (uint16_t)state->a - state->b;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            break;
        }
        // CMP C
        case 0xb9:
        {
            uint16_t r = (uint16_t)state->a - state->c;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            break;
        }
        // CMP D
        case 0xba:
        {
            uint16_t r = (uint16_t)state->a - state->d;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            break;
        }
        // CMP E
        case 0xbb:
        {
            uint16_t r = (uint16_t)state->a - state->e;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            break;
        }
        // CMP H
        case 0xbc:
        {
            uint16_t r = (uint16_t)state->a - state->h;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            break;
        }
        // CMP L
        case 0xbd:
        {
            uint16_t r = (uint16_t)state->a - state->l;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            break;
        }
        // CMP M
        case 0xbe:
        {
            uint8_t m = state->memory[(state->h << 8) | state->l];
            uint16_t r = (uint16_t)state->a - m;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            break;
        }
        // CMP A
        case 0xbf:
        {
            uint16_t r = (uint16_t)state->a - state->a;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            break;
        }

    
        // RNZ -- return if not zero. 
        case 0xc0:
            if (!state->cc.z)
            {
                state->pc = state->memory[state->sp] | (state->memory[state->sp + 1] << 8);
                state->sp += 2;
                return 0;
            }
            break;

        // POP B -- mirror of PUSH B
        case 0xc1:
            state->c = state->memory[state->sp];
            state->b = state->memory[state->sp + 1];
            state->sp += 2;
            break;

        // JNZ a16 - jump if not zero
        case 0xc2:
            if (!state->cc.z) { state->pc = (opcode[2] << 8) | opcode[1]; return 0; }
            else state->pc += 2;
            break;

        // JMP a16 - unconditional jump
        case 0xc3:
            state->pc = (opcode[2] << 8) | opcode[1];
            return 0;

        // CNZ a16 -- call if not zero. 
        case 0xc4:
            if (!state->cc.z)
            {
                uint16_t ret_addr = state->pc + 3;
                state->memory[state->sp - 1] = (ret_addr >> 8) & 0xff;
                state->memory[state->sp - 2] = ret_addr & 0xff;
                state->sp -= 2;
                state->pc = (opcode[2] << 8) | opcode[1];
                return 0;
            }
            state->pc += 2;
            break;

        // PUSH B
        case 0xc5:
            state->memory[state->sp - 1] = state->b;
            state->memory[state->sp - 2] = state->c;
            state->sp -= 2;
            break;

        // ADI d8 -- add immediate to A
        case 0xc6:
        {
            uint16_t r = (uint16_t)state->a + opcode[1];
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            state->pc += 1;
            break;
        }
    
        // RST 0 -- push return address, jump to $0000. 
        case 0xc7:
        {
            uint16_t ret_addr = state->pc + 1;
            state->memory[state->sp - 1] = (ret_addr >> 8) & 0xff;
            state->memory[state->sp - 2] = ret_addr & 0xff;
            state->sp -= 2;
            state->pc = 0x0000;
            return 0;
        }

        // RZ -- return if zero
        case 0xc8:
            if (state->cc.z)
            {
                state->pc = state->memory[state->sp] | (state->memory[state->sp + 1] << 8);
                state->sp += 2;
                return 0;
            }
            break;

        // RET -- return from subroutine
        case 0xc9:
            state->pc = state->memory[state->sp] | (state->memory[state->sp + 1] << 8);
            state->sp += 2;
            return 0;

        // JZ a16 -- jump if zero
        case 0xca:
            if (state->cc.z) { state->pc = (opcode[2] << 8) | opcode[1]; return 0; }
            else state->pc += 2;
            break;

        // (undocumented) JMP dup
        case 0xcb:
            UndocumentedInstruction(state);
            break;

        // CZ a16 -- call if zero
        case 0xcc:
            if (state->cc.z)
            {
                uint16_t ret_addr = state->pc + 3;
                state->memory[state->sp - 1] = (ret_addr >> 8) & 0xff;
                state->memory[state->sp - 2] = ret_addr & 0xff;
                state->sp -= 2;
                state->pc = (opcode[2] << 8) | opcode[1];
                return 0;
            }
            state->pc += 2;
            break;

        // CALL a16 -- push return addr, jump.
        case 0xcd:
        {
            uint16_t ret_addr = state->pc + 3;
            state->memory[state->sp - 1] = (ret_addr >> 8) & 0xff;
            state->memory[state->sp - 2] = ret_addr & 0xff;
            state->sp = state->sp - 2;
            state->pc = (opcode[2] << 8) | opcode[1];
            return 0; // skip the trailing pc += 1 -- pc was just set directly
        }

        // ACI d8 -- add immediate + carry to A
        case 0xce:
        {
            uint16_t r = (uint16_t)state->a + opcode[1] + state->cc.cy;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            state->pc += 1;
            break;
        }

        // RST 1
        case 0xcf:
        {
            uint16_t ret_addr = state->pc + 1;
            state->memory[state->sp - 1] = (ret_addr >> 8) & 0xff;
            state->memory[state->sp - 2] = ret_addr & 0xff;
            state->sp -= 2;
            state->pc = 0x0008;
            return 0;
        }

        // RNC -- return if no carry
        case 0xd0:
            if (!state->cc.cy)
            {
                state->pc = state->memory[state->sp] | (state->memory[state->sp + 1] << 8);
                state->sp += 2;
                return 0;
            }
            break;

        // POP D
        case 0xd1:
            state->e = state->memory[state->sp];
            state->d = state->memory[state->sp + 1];
            state->sp += 2;
            break;

        // JNC a16 -- jump if no carry
        case 0xd2:
            if (!state->cc.cy) { state->pc = (opcode[2] << 8) | opcode[1]; return 0; }
            else state->pc += 2;
            break;

        // OUT d8 -- write A to output port. opcode[1] is the port number.
        case 0xd3:
            if (state->out_port)
            {
                state->out_port(opcode[1], state->a);
            }
            state->pc += 1;
            break;
            
        // CNC a16 -- call if no carry
        case 0xd4:
            if (!state->cc.cy)
            {
                uint16_t ret_addr = state->pc + 3;
                state->memory[state->sp - 1] = (ret_addr >> 8) & 0xff;
                state->memory[state->sp - 2] = ret_addr & 0xff;
                state->sp -= 2;
                state->pc = (opcode[2] << 8) | opcode[1];
                return 0;
            }
            state->pc += 2;
            break;

        // PUSH D
        case 0xd5:
            state->memory[state->sp - 1] = state->d;
            state->memory[state->sp - 2] = state->e;
            state->sp -= 2;
            break;

        // SUI d8 -- subtract immediate from A
        case 0xd6:
        {
            uint16_t r = (uint16_t)state->a - opcode[1];
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            state->pc += 1;
            break;
        }

        // RST 2
        case 0xd7:
        {
            uint16_t ret_addr = state->pc + 1;
            state->memory[state->sp - 1] = (ret_addr >> 8) & 0xff;
            state->memory[state->sp - 2] = ret_addr & 0xff;
            state->sp -= 2;
            state->pc = 0x0010;
            return 0;
        }

        // RC -- return if carry
        case 0xd8:
            if (state->cc.cy)
            {
                state->pc = state->memory[state->sp] | (state->memory[state->sp + 1] << 8);
                state->sp += 2;
                return 0;
            }
            break;

        // (undocumented) RET dup
        case 0xd9:
            UndocumentedInstruction(state);
            break;
    
        // JC a16 -- jump if carry
        case 0xda:
            if (state->cc.cy) { state->pc = (opcode[2] << 8) | opcode[1]; return 0; }
            else state->pc += 2;
            break;

        // IN d8 -- read input port into A.
        case 0xdb:
            if (state->in_port)
            {
                state->a = state->in_port(opcode[1]);
            }
            state->pc += 1;
            break;

        // CC a16 -- call if carry
        case 0xdc:
            if (state->cc.cy)
            {
                uint16_t ret_addr = state->pc + 3;
                state->memory[state->sp - 1] = (ret_addr >> 8) & 0xff;
                state->memory[state->sp - 2] = ret_addr & 0xff;
                state->sp -= 2;
                state->pc = (opcode[2] << 8) | opcode[1];
                return 0;
            }
            state->pc += 2;
            break;

        // (undocumented) CALL dup
        case 0xdd:
            UndocumentedInstruction(state);
            break;

        // SBI d8 -- subtract immediate + carry from A
        case 0xde:
        {
            uint16_t r = (uint16_t)state->a - opcode[1] - state->cc.cy;
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->a = r & 0xff;
            state->pc += 1;
            break;
        }

        // RST 3
        case 0xdf:
        {
            uint16_t ret_addr = state->pc + 1;
            state->memory[state->sp - 1] = (ret_addr >> 8) & 0xff;
            state->memory[state->sp - 2] = ret_addr & 0xff;
            state->sp -= 2;
            state->pc = 0x0018;
            return 0;
        }

        // RPO -- return if parity odd
        case 0xe0:
            if (!state->cc.p)
            {
                state->pc = state->memory[state->sp] | (state->memory[state->sp + 1] << 8);
                state->sp += 2;
                return 0;
            }
            break;

        // POP H
        case 0xe1:
            state->l = state->memory[state->sp];
            state->h = state->memory[state->sp + 1];
            state->sp += 2;
            break;

        // JPO a16 -- jump if parity odd
        case 0xe2:
            if (!state->cc.p) { state->pc = (opcode[2] << 8) | opcode[1]; return 0; }
            else state->pc += 2;
            break;

        // XTHL -- exchange HL with top of stack
        case 0xe3:
        {
            uint8_t lo = state->memory[state->sp];
            uint8_t hi = state->memory[state->sp + 1];
            state->memory[state->sp] = state->l;
            state->memory[state->sp + 1] = state->h;
            state->l = lo;
            state->h = hi;
            break;
        }

        // CPO a16 -- call if parity odd
        case 0xe4:
            if (!state->cc.p)
            {
                uint16_t ret_addr = state->pc + 3;
                state->memory[state->sp - 1] = (ret_addr >> 8) & 0xff;
                state->memory[state->sp - 2] = ret_addr & 0xff;
                state->sp -= 2;
                state->pc = (opcode[2] << 8) | opcode[1];
                return 0;
            }
            state->pc += 2;
            break;

        // PUSH H
        case 0xe5:
            state->memory[state->sp - 1] = state->h;
            state->memory[state->sp - 2] = state->l;
            state->sp -= 2;
            break;

        // ANI d8 -- AND immediate with A
        case 0xe6:
            state->a &= opcode[1];
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            state->pc += 1;
            break;

        // RST 4
        case 0xe7:
        {
            uint16_t ret_addr = state->pc + 1;
            state->memory[state->sp - 1] = (ret_addr >> 8) & 0xff;
            state->memory[state->sp - 2] = ret_addr & 0xff;
            state->sp -= 2;
            state->pc = 0x0020;
            return 0;
        }

        // RPE -- return if parity even
        case 0xe8:
            if (state->cc.p)
            {
                state->pc = state->memory[state->sp] | (state->memory[state->sp + 1] << 8);
                state->sp += 2;
                return 0;
            }
            break;

        // PCHL -- jump to address in HL
        case 0xe9:
            state->pc = (state->h << 8) | state->l;
            return 0;

        // JPE a16 -- jump if parity even
        case 0xea:
            if (state->cc.p) { state->pc = (opcode[2] << 8) | opcode[1]; return 0; }
            else state->pc += 2;
            break;

        // XCHG -- swap HL and DE
        case 0xeb:
        {
            uint8_t tmp_h = state->h, tmp_l = state->l;
            state->h = state->d;
            state->l = state->e;
            state->d = tmp_h;
            state->e = tmp_l;
            break;
        }

        // CPE a16 -- call if parity even
        case 0xec:
            if (state->cc.p)
            {
                uint16_t ret_addr = state->pc + 3;
                state->memory[state->sp - 1] = (ret_addr >> 8) & 0xff;
                state->memory[state->sp - 2] = ret_addr & 0xff;
                state->sp -= 2;
                state->pc = (opcode[2] << 8) | opcode[1];
                return 0;
            }
            state->pc += 2;
            break;

        // (undocumented) CALL dup
        case 0xed:
            UndocumentedInstruction(state);
            break;


        // XRI d8 -- XOR immediate with A
        case 0xee:
            state->a ^= opcode[1];
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            state->pc += 1;
            break;
    
        // RST 5
        case 0xef:
        {
            uint16_t ret_addr = state->pc + 1;
            state->memory[state->sp - 1] = (ret_addr >> 8) & 0xff;
            state->memory[state->sp - 2] = ret_addr & 0xff;
            state->sp -= 2;
            state->pc = 0x0028;
            return 0;
        }

        // RP -- return if plus (not minus, i.e. sign flag clear)
        case 0xf0:
            if (!state->cc.s)
            {
                state->pc = state->memory[state->sp] | (state->memory[state->sp + 1] << 8);
                state->sp += 2;
                return 0;
            }
            break;

        // POP PSW -- pop A and flags.
        case 0xf1:
        {
            uint8_t psw = state->memory[state->sp];
            state->a = state->memory[state->sp + 1];
            state->cc.cy = (psw & 0x01) != 0;
            state->cc.p  = (psw & 0x04) != 0;
            state->cc.ac = (psw & 0x10) != 0;
            state->cc.z  = (psw & 0x40) != 0;
            state->cc.s  = (psw & 0x80) != 0;
            state->sp += 2;
            break;
        }

        // JP a16 -- jump if positive (sign flag clear)
        case 0xf2:
            if (!state->cc.s) { state->pc = (opcode[2] << 8) | opcode[1]; return 0; }
            else state->pc += 2;
            break;

        // DI -- disable interrupts
        case 0xf3:
            state->int_enable = 0;
            break;

        // CP a16 -- call if positive
        case 0xf4:
            if (!state->cc.s)
            {
                uint16_t ret_addr = state->pc + 3;
                state->memory[state->sp - 1] = (ret_addr >> 8) & 0xff;
                state->memory[state->sp - 2] = ret_addr & 0xff;
                state->sp -= 2;
                state->pc = (opcode[2] << 8) | opcode[1];
                return 0;
            }
            state->pc += 2;
            break;

        // PUSH PSW -- push A and flags
        case 0xf5:
        {
            uint8_t psw = (state->cc.s  << 7) |
                          (state->cc.z  << 6) |
                          (0           << 5) |
                          (state->cc.ac << 4) |
                          (0           << 3) |
                          (state->cc.p  << 2) |
                          (1           << 1) |
                          (state->cc.cy << 0);
            state->memory[state->sp - 1] = state->a;
            state->memory[state->sp - 2] = psw;
            state->sp -= 2;
            break;
        }

        // ORI d8 -- OR immediate with A
        case 0xf6:
            state->a |= opcode[1];
            state->cc.cy = 0; state->cc.ac = 0;
            state->cc.z = (state->a == 0);
            state->cc.s = (0x80 == (state->a & 0x80));
            state->cc.p = Parity(state->a, 8);
            state->pc += 1;
            break;

        // RST 6
        case 0xf7:
        {
            uint16_t ret_addr = state->pc + 1;
            state->memory[state->sp - 1] = (ret_addr >> 8) & 0xff;
            state->memory[state->sp - 2] = ret_addr & 0xff;
            state->sp -= 2;
            state->pc = 0x0030;
            return 0;
        }

        // RM -- return if minus (sign flag set)
        case 0xf8:
            if (state->cc.s)
            {
                state->pc = state->memory[state->sp] | (state->memory[state->sp + 1] << 8);
                state->sp += 2;
                return 0;
            }
            break;

        // SPHL -- SP = HL
        case 0xf9:
            state->sp = (state->h << 8) | state->l;
            break;

        // JM a16 -- jump if minus
        case 0xfa:
            if (state->cc.s) { state->pc = (opcode[2] << 8) | opcode[1]; return 0; }
            else state->pc += 2;
            break;

        // EI -- enable interrupts
        case 0xfb:
            state->int_enable = 1;
            break;

        // CM a16 -- call if minus
        case 0xfc:
            if (state->cc.s)
            {
                uint16_t ret_addr = state->pc + 3;
                state->memory[state->sp - 1] = (ret_addr >> 8) & 0xff;
                state->memory[state->sp - 2] = ret_addr & 0xff;
                state->sp -= 2;
                state->pc = (opcode[2] << 8) | opcode[1];
                return 0;
            }
            state->pc += 2;
            break;

        // (undocumented) CALL dup
        case 0xfd:
            UndocumentedInstruction(state);
            break;

        // CPI d8 -- compare immediate with A
        case 0xfe:
        {
            uint16_t r = (uint16_t)state->a - opcode[1];
            state->cc.cy = (r > 0xff);
            state->cc.z  = ((r & 0xff) == 0);
            state->cc.s  = (0x80 == (r & 0x80));
            state->cc.p  = Parity(r & 0xff, 8);
            state->pc += 1;
            break;
        }

        // RST 7
        case 0xff:
        {
            uint16_t ret_addr = state->pc + 1;
            state->memory[state->sp - 1] = (ret_addr >> 8) & 0xff;
            state->memory[state->sp - 2] = ret_addr & 0xff;
            state->sp -= 2;
            state->pc = 0x0038;
            return 0;
        }
    }

    state->pc += 1;  // for the opcode itself
    return 0;
}
