     0x0000: 00 [00 00]  |   NOP
     0x0001: 00 [00 C3]  |   NOP
     0x0002: 00 [C3 D4]  |   NOP
     0x0003: C3 [D4 18]  |   JMP 0x18D4
     0x0004: D4 [18 00]  |   CNC 0x0018
     0x0005: 18 [00 00]  |   Undefined instruction
     0x0006: 00 [00 F5]  |   NOP
     0x0007: 00 [F5 C5]  |   NOP
     0x0008: F5 [C5 D5]  |   PUSH PSW
     0x0009: C5 [D5 E5]  |   PUSH B
     0x000a: D5 [E5 C3]  |   PUSH D
     0x000b: E5 [C3 8C]  |   PUSH H
     0x000c: C3 [8C 00]  |   JMP 0x008C
     0x000d: 8C [00 00]  |   ADC H
     0x000e: 00 [00 F5]  |   NOP
     0x000f: 00 [F5 C5]  |   NOP
     0x0010: F5 [C5 D5]  |   PUSH PSW
     0x0011: C5 [D5 E5]  |   PUSH B
     0x0012: D5 [E5 3E]  |   PUSH D
     0x0013: E5 [3E 80]  |   PUSH H
     0x0014: 3E [80 32]  |   MVI A, 0x80
     0x0015: 80 [32 72]  |   ADD B
     0x0016: 32 [72 20]  |   STA 0x2072
     0x0017: 72 [20 21]  |   MOV M, D
     0x0018: 20 [21 C0]  |   Undefined instruction
     0x0019: 21 [C0 20]  |   LXI H, 0x20C0 
     0x001a: C0 [20 35]  |   RNZ
     0x001b: 20 [35 CD]  |   Undefined instruction
     0x001c: 35 [CD CD]  |   DCR M
     0x001d: CD [CD 17]  |   CAL 0x17CD
     0x001e: CD [17 DB]  |   CAL 0xDB17
     0x001f: 17 [DB 01]  |   RAL
     0x0020: DB [01 0F]  |   IN 0x01
     0x0021: 01 [0F DA]  |   LXI B, 0xDA0F 
     0x0022: 0F [DA 67]  |   RRC
     0x0023: DA [67 00]  |   JC 0x0067
     0x0024: 67 [00 3A]  |   MOV H, A
     0x0025: 00 [3A EA]  |   NOP
     0x0026: 3A [EA 20]  |   LDA 0x20EA
     0x0027: EA [20 A7]  |   JPE 0xA720
     0x0028: 20 [A7 CA]  |   Undefined instruction
     0x0029: A7 [CA 42]  |   ANA A
     0x002a: CA [42 00]  |   JZ 0x0042
     0x002b: 42 [00 3A]  |   MOV B, D
     0x002c: 00 [3A EB]  |   NOP
     0x002d: 3A [EB 20]  |   LDA 0x20EB
     0x002e: EB [20 FE]  |   XCHG
     0x002f: 20 [FE 99]  |   Undefined instruction
     0x0030: FE [99 CA]  |   CPI 0x99
     0x0031: 99 [CA 3E]  |   SBB C
     0x0032: CA [3E 00]  |   JZ 0x003E
     0x0033: 3E [00 C6]  |   MVI A, 0x00
     0x0034: 00 [C6 01]  |   NOP
     0x0035: C6 [01 27]  |   ADI 0x01
     0x0036: 01 [27 32]  |   LXI B, 0x3227 
     0x0037: 27 [32 EB]  |   DAA
     0x0038: 32 [EB 20]  |   STA 0x20EB
     0x0039: EB [20 CD]  |   XCHG
     0x003a: 20 [CD 47]  |   Undefined instruction
     0x003b: CD [47 19]  |   CAL 0x1947
     0x003c: 47 [19 AF]  |   MOV B, A
     0x003d: 19 [AF 32]  |   DAD D
     0x003e: AF [32 EA]  |   XRA A
     0x003f: 32 [EA 20]  |   STA 0x20EA
     0x0040: EA [20 3A]  |   JPE 0x3A20
     0x0041: 20 [3A E9]  |   Undefined instruction
     0x0042: 3A [E9 20]  |   LDA 0x20E9
     0x0043: E9 [20 A7]  |   PCHL
     0x0044: 20 [A7 CA]  |   Undefined instruction
     0x0045: A7 [CA 82]  |   ANA A
     0x0046: CA [82 00]  |   JZ 0x0082
     0x0047: 82 [00 3A]  |   ADD D
     0x0048: 00 [3A EF]  |   NOP
     0x0049: 3A [EF 20]  |   LDA 0x20EF
     0x004a: EF [20 A7]  |   RST 5
     0x004b: 20 [A7 C2]  |   Undefined instruction
     0x004c: A7 [C2 6F]  |   ANA A
     0x004d: C2 [6F 00]  |   JNZ 0x006F
     0x004e: 6F [00 3A]  |   MOV L, A
     0x004f: 00 [3A EB]  |   NOP
     0x0050: 3A [EB 20]  |   LDA 0x20EB
     0x0051: EB [20 A7]  |   XCHG
     0x0052: 20 [A7 C2]  |   Undefined instruction
     0x0053: A7 [C2 5D]  |   ANA A
     0x0054: C2 [5D 00]  |   JNZ 0x005D
     0x0055: 5D [00 CD]  |   MOV E, L
     0x0056: 00 [CD BF]  |   NOP
     0x0057: CD [BF 0A]  |   CAL 0x0ABF
     0x0058: BF [0A C3]  |   CMP A
     0x0059: 0A [C3 82]  |   LDAX B
     0x005a: C3 [82 00]  |   JMP 0x0082
     0x005b: 82 [00 3A]  |   ADD D
     0x005c: 00 [3A 93]  |   NOP
     0x005d: 3A [93 20]  |   LDA 0x2093
     0x005e: 93 [20 A7]  |   SUB E
     0x005f: 20 [A7 C2]  |   Undefined instruction
     0x0060: A7 [C2 82]  |   ANA A
     0x0061: C2 [82 00]  |   JNZ 0x0082
     0x0062: 82 [00 C3]  |   ADD D
     0x0063: 00 [C3 65]  |   NOP
     0x0064: C3 [65 07]  |   JMP 0x0765
     0x0065: 65 [07 3E]  |   MOV H, L
     0x0066: 07 [3E 01]  |   RLC
     0x0067: 3E [01 32]  |   MVI A, 0x01
     0x0068: 01 [32 EA]  |   LXI B, 0xEA32 
     0x0069: 32 [EA 20]  |   STA 0x20EA
     0x006a: EA [20 C3]  |   JPE 0xC320
     0x006b: 20 [C3 3F]  |   Undefined instruction
     0x006c: C3 [3F 00]  |   JMP 0x003F
     0x006d: 3F [00 CD]  |   CMC
     0x006e: 00 [CD 40]  |   NOP
     0x006f: CD [40 17]  |   CAL 0x1740
     0x0070: 40 [17 3A]  |   MOV B, B
     0x0071: 17 [3A 32]  |   RAL
     0x0072: 3A [32 20]  |   LDA 0x2032
     0x0073: 32 [20 32]  |   STA 0x3220
     0x0074: 20 [32 80]  |   Undefined instruction
     0x0075: 32 [80 20]  |   STA 0x2080
     0x0076: 80 [20 CD]  |   ADD B
     0x0077: 20 [CD 00]  |   Undefined instruction
     0x0078: CD [00 01]  |   CAL 0x0100
     0x0079: 00 [01 CD]  |   NOP
     0x007a: 01 [CD 48]  |   LXI B, 0x48CD 
     0x007b: CD [48 02]  |   CAL 0x0248
     0x007c: 48 [02 CD]  |   MOV C, B
     0x007d: 02 [CD 13]  |   STAX B
     0x007e: CD [13 09]  |   CAL 0x0913
     0x007f: 13 [09 00]  |   INX D
     0x0080: 09 [00 E1]  |   DAD B
     0x0081: 00 [E1 D1]  |   NOP
     0x0082: E1 [D1 C1]  |   POP H
     0x0083: D1 [C1 F1]  |   POP D
     0x0084: C1 [F1 FB]  |   POP B
     0x0085: F1 [FB C9]  |   POP PSW
     0x0086: FB [C9 00]  |   EI
     0x0087: C9 [00 00]  |   RET
     0x0088: 00 [00 00]  |   NOP
     0x0089: 00 [00 00]  |   NOP
     0x008a: 00 [00 AF]  |   NOP
     0x008b: 00 [AF 32]  |   NOP
     0x008c: AF [32 72]  |   XRA A
     0x008d: 32 [72 20]  |   STA 0x2072
     0x008e: 72 [20 3A]  |   MOV M, D
     0x008f: 20 [3A E9]  |   Undefined instruction
     0x0090: 3A [E9 20]  |   LDA 0x20E9
     0x0091: E9 [20 A7]  |   PCHL
     0x0092: 20 [A7 CA]  |   Undefined instruction
     0x0093: A7 [CA 82]  |   ANA A
     0x0094: CA [82 00]  |   JZ 0x0082
     0x0095: 82 [00 3A]  |   ADD D
     0x0096: 00 [3A EF]  |   NOP
     0x0097: 3A [EF 20]  |   LDA 0x20EF
     0x0098: EF [20 A7]  |   RST 5
     0x0099: 20 [A7 C2]  |   Undefined instruction
     0x009a: A7 [C2 A5]  |   ANA A
     0x009b: C2 [A5 00]  |   JNZ 0x00A5
     0x009c: A5 [00 3A]  |   ANA L
     0x009d: 00 [3A C1]  |   NOP
     0x009e: 3A [C1 20]  |   LDA 0x20C1
     0x009f: C1 [20 0F]  |   POP B
     0x00a0: 20 [0F D2]  |   Undefined instruction
     0x00a1: 0F [D2 82]  |   RRC
     0x00a2: D2 [82 00]  |   JNC 0x0082
     0x00a3: 82 [00 21]  |   ADD D
     0x00a4: 00 [21 20]  |   NOP
     0x00a5: 21 [20 20]  |   LXI H, 0x2020 
     0x00a6: 20 [20 CD]  |   Undefined instruction
     0x00a7: 20 [CD 4B]  |   Undefined instruction
     0x00a8: CD [4B 02]  |   CAL 0x024B
     0x00a9: 4B [02 CD]  |   MOV C, E
     0x00aa: 02 [CD 41]  |   STAX B
     0x00ab: CD [41 01]  |   CAL 0x0141
     0x00ac: 41 [01 C3]  |   MOV B, C
     0x00ad: 01 [C3 82]  |   LXI B, 0x82C3 
     0x00ae: C3 [82 00]  |   JMP 0x0082
     0x00af: 82 [00 CD]  |   ADD D
     0x00b0: 00 [CD 86]  |   NOP
     0x00b1: CD [86 08]  |   CAL 0x0886
     0x00b2: 86 [08 E5]  |   ADD M
     0x00b3: 08 [E5 7E]  |   Undefined instruction
     0x00b4: E5 [7E 23]  |   PUSH H
     0x00b5: 7E [23 66]  |   MOV A, M
     0x00b6: 23 [66 6F]  |   INX H
     0x00b7: 66 [6F 22]  |   MOV H, M
     0x00b8: 6F [22 09]  |   MOV L, A
     0x00b9: 22 [09 20]  |   SHLD 0x2009
     0x00ba: 09 [20 22]  |   DAD B
     0x00bb: 20 [22 0B]  |   Undefined instruction
     0x00bc: 22 [0B 20]  |   SHLD 0x200B
     0x00bd: 0B [20 E1]  |   DCX B
     0x00be: 20 [E1 2B]  |   Undefined instruction
     0x00bf: E1 [2B 7E]  |   POP H
     0x00c0: 2B [7E FE]  |   DCX H
     0x00c1: 7E [FE 03]  |   MOV A, M
     0x00c2: FE [03 C2]  |   CPI 0x03
     0x00c3: 03 [C2 C8]  |   INX B
     0x00c4: C2 [C8 00]  |   JNZ 0x00C8
     0x00c5: C8 [00 3D]  |   RZ
     0x00c6: 00 [3D 32]  |   NOP
     0x00c7: 3D [32 08]  |   DCR A
     0x00c8: 32 [08 20]  |   STA 0x2008
     0x00c9: 08 [20 FE]  |   Undefined instruction
     0x00ca: 20 [FE FE]  |   Undefined instruction
     0x00cb: FE [FE 3E]  |   CPI 0xFE
     0x00cc: FE [3E 00]  |   CPI 0x3E
     0x00cd: 3E [00 C2]  |   MVI A, 0x00
     0x00ce: 00 [C2 D3]  |   NOP
     0x00cf: C2 [D3 00]  |   JNZ 0x00D3
     0x00d0: D3 [00 3C]  |   OUT 0x00
     0x00d1: 00 [3C 32]  |   NOP
     0x00d2: 3C [32 0D]  |   INR A
     0x00d3: 32 [0D 20]  |   STA 0x200D
     0x00d4: 0D [20 C9]  |   DCR C
     0x00d5: 20 [C9 3E]  |   Undefined instruction
     0x00d6: C9 [3E 02]  |   RET
     0x00d7: 3E [02 32]  |   MVI A, 0x02
     0x00d8: 02 [32 FB]  |   STAX B
     0x00d9: 32 [FB 21]  |   STA 0x21FB
     0x00da: FB [21 32]  |   EI
     0x00db: 21 [32 FB]  |   LXI H, 0xFB32 
     0x00dc: 32 [FB 22]  |   STA 0x22FB
     0x00dd: FB [22 C3]  |   EI
     0x00de: 22 [C3 E4]  |   SHLD 0xE4C3
     0x00df: C3 [E4 08]  |   JMP 0x08E4
     0x00e0: E4 [08 00]  |   CPO 0x0008
     0x00e1: 08 [00 00]  |   Undefined instruction
     0x00e2: 00 [00 00]  |   NOP
     0x00e3: 00 [00 00]  |   NOP
     0x00e4: 00 [00 00]  |   NOP
     0x00e5: 00 [00 00]  |   NOP
     0x00e6: 00 [00 00]  |   NOP
     0x00e7: 00 [00 00]  |   NOP
     0x00e8: 00 [00 00]  |   NOP
     0x00e9: 00 [00 00]  |   NOP
     0x00ea: 00 [00 00]  |   NOP
     0x00eb: 00 [00 00]  |   NOP
     0x00ec: 00 [00 00]  |   NOP
     0x00ed: 00 [00 00]  |   NOP
     0x00ee: 00 [00 00]  |   NOP
     0x00ef: 00 [00 00]  |   NOP
     0x00f0: 00 [00 00]  |   NOP
     0x00f1: 00 [00 00]  |   NOP
     0x00f2: 00 [00 00]  |   NOP
     0x00f3: 00 [00 00]  |   NOP
     0x00f4: 00 [00 00]  |   NOP
     0x00f5: 00 [00 00]  |   NOP
     0x00f6: 00 [00 00]  |   NOP
     0x00f7: 00 [00 00]  |   NOP
     0x00f8: 00 [00 00]  |   NOP
     0x00f9: 00 [00 00]  |   NOP
     0x00fa: 00 [00 00]  |   NOP
     0x00fb: 00 [00 00]  |   NOP
     0x00fc: 00 [00 00]  |   NOP
     0x00fd: 00 [00 00]  |   NOP
     0x00fe: 00 [00 21]  |   NOP
     0x00ff: 00 [21 02]  |   NOP
     0x0100: 21 [02 20]  |   LXI H, 0x2002 
     0x0101: 02 [20 7E]  |   STAX B
     0x0102: 20 [7E A7]  |   Undefined instruction
     0x0103: 7E [A7 C2]  |   MOV A, M
     0x0104: A7 [C2 38]  |   ANA A
     0x0105: C2 [38 15]  |   JNZ 0x1538
     0x0106: 38 [15 E5]  |   Undefined instruction
     0x0107: 15 [E5 3A]  |   DCR D
     0x0108: E5 [3A 06]  |   PUSH H
     0x0109: 3A [06 20]  |   LDA 0x2006
     0x010a: 06 [20 6F]  |   MVI B, 0x20
     0x010b: 20 [6F 3A]  |   Undefined instruction
     0x010c: 6F [3A 67]  |   MOV L, A
     0x010d: 3A [67 20]  |   LDA 0x2067
     0x010e: 67 [20 67]  |   MOV H, A
     0x010f: 20 [67 7E]  |   Undefined instruction
     0x0110: 67 [7E A7]  |   MOV H, A
     0x0111: 7E [A7 E1]  |   MOV A, M
     0x0112: A7 [E1 CA]  |   ANA A
     0x0113: E1 [CA 36]  |   POP H
     0x0114: CA [36 01]  |   JZ 0x0136
     0x0115: 36 [01 23]  |   MVI M, 0x01
     0x0116: 01 [23 23]  |   LXI B, 0x2323 
     0x0117: 23 [23 7E]  |   INX H
     0x0118: 23 [7E 23]  |   INX H
     0x0119: 7E [23 46]  |   MOV A, M
     0x011a: 23 [46 E6]  |   INX H
     0x011b: 46 [E6 FE]  |   MOV B, M
     0x011c: E6 [FE 07]  |   ANI 0xFE
     0x011d: FE [07 07]  |   CPI 0x07
     0x011e: 07 [07 07]  |   RLC
     0x011f: 07 [07 5F]  |   RLC
     0x0120: 07 [5F 16]  |   RLC
     0x0121: 5F [16 00]  |   MOV E, A
     0x0122: 16 [00 21]  |   MVI D, 0x00
     0x0123: 00 [21 00]  |   NOP
     0x0124: 21 [00 1C]  |   LXI H, 0x1C00 
     0x0125: 00 [1C 19]  |   NOP
     0x0126: 1C [19 EB]  |   INR E
     0x0127: 19 [EB 78]  |   DAD D
     0x0128: EB [78 A7]  |   XCHG
     0x0129: 78 [A7 C4]  |   MOV A, B
     0x012a: A7 [C4 3B]  |   ANA A
     0x012b: C4 [3B 01]  |   CNZ 0x013B
     0x012c: 3B [01 2A]  |   DCX SP
     0x012d: 01 [2A 0B]  |   LXI B, 0x0B2A 
     0x012e: 2A [0B 20]  |   LHLD 0x200B
     0x012f: 0B [20 06]  |   DCX B
     0x0130: 20 [06 10]  |   Undefined instruction
     0x0131: 06 [10 CD]  |   MVI B, 0x10
     0x0132: 10 [CD D3]  |   Undefined instruction
     0x0133: CD [D3 15]  |   CAL 0x15D3
     0x0134: D3 [15 AF]  |   OUT 0x15
     0x0135: 15 [AF 32]  |   DCR D
     0x0136: AF [32 00]  |   XRA A
     0x0137: 32 [00 20]  |   STA 0x2000
     0x0138: 00 [20 C9]  |   NOP
     0x0139: 20 [C9 21]  |   Undefined instruction
     0x013a: C9 [21 30]  |   RET
     0x013b: 21 [30 00]  |   LXI H, 0x0030 
     0x013c: 30 [00 19]  |   Undefined instruction
     0x013d: 00 [19 EB]  |   NOP
     0x013e: 19 [EB C9]  |   DAD D
     0x013f: EB [C9 3A]  |   XCHG
     0x0140: C9 [3A 68]  |   RET
     0x0141: 3A [68 20]  |   LDA 0x2068
     0x0142: 68 [20 A7]  |   MOV L, B
     0x0143: 20 [A7 C8]  |   Undefined instruction
     0x0144: A7 [C8 3A]  |   ANA A
     0x0145: C8 [3A 00]  |   RZ
     0x0146: 3A [00 20]  |   LDA 0x2000
     0x0147: 00 [20 A7]  |   NOP
     0x0148: 20 [A7 C0]  |   Undefined instruction
     0x0149: A7 [C0 3A]  |   ANA A
     0x014a: C0 [3A 67]  |   RNZ
     0x014b: 3A [67 20]  |   LDA 0x2067
     0x014c: 67 [20 67]  |   MOV H, A
     0x014d: 20 [67 3A]  |   Undefined instruction
     0x014e: 67 [3A 06]  |   MOV H, A
     0x014f: 3A [06 20]  |   LDA 0x2006
     0x0150: 06 [20 16]  |   MVI B, 0x20
     0x0151: 20 [16 02]  |   Undefined instruction
     0x0152: 16 [02 3C]  |   MVI D, 0x02
     0x0153: 02 [3C FE]  |   STAX B
     0x0154: 3C [FE 37]  |   INR A
     0x0155: FE [37 CC]  |   CPI 0x37
     0x0156: 37 [CC A1]  |   STC
     0x0157: CC [A1 01]  |   CZ 0x01A1
     0x0158: A1 [01 6F]  |   ANA C
     0x0159: 01 [6F 46]  |   LXI B, 0x466F 
     0x015a: 6F [46 05]  |   MOV L, A
     0x015b: 46 [05 C2]  |   MOV B, M
     0x015c: 05 [C2 54]  |   DCR B
     0x015d: C2 [54 01]  |   JNZ 0x0154
     0x015e: 54 [01 32]  |   MOV D, H
     0x015f: 01 [32 06]  |   LXI B, 0x0632 
     0x0160: 32 [06 20]  |   STA 0x2006
     0x0161: 06 [20 CD]  |   MVI B, 0x20
     0x0162: 20 [CD 7A]  |   Undefined instruction
     0x0163: CD [7A 01]  |   CAL 0x017A
     0x0164: 7A [01 61]  |   MOV A, D
     0x0165: 01 [61 22]  |   LXI B, 0x2261 
     0x0166: 61 [22 0B]  |   MOV H, C
     0x0167: 22 [0B 20]  |   SHLD 0x200B
     0x0168: 0B [20 7D]  |   DCX B
     0x0169: 20 [7D FE]  |   Undefined instruction
     0x016a: 7D [FE 28]  |   MOV A, L
     0x016b: FE [28 DA]  |   CPI 0x28
     0x016c: 28 [DA 71]  |   Undefined instruction
     0x016d: DA [71 19]  |   JC 0x1971
     0x016e: 71 [19 7A]  |   MOV M, C
     0x016f: 19 [7A 32]  |   DAD D
     0x0170: 7A [32 04]  |   MOV A, D
     0x0171: 32 [04 20]  |   STA 0x2004
     0x0172: 04 [20 3E]  |   INR B
     0x0173: 20 [3E 01]  |   Undefined instruction
     0x0174: 3E [01 32]  |   MVI A, 0x01
     0x0175: 01 [32 00]  |   LXI B, 0x0032 
     0x0176: 32 [00 20]  |   STA 0x2000
     0x0177: 00 [20 C9]  |   NOP
     0x0178: 20 [C9 16]  |   Undefined instruction
     0x0179: C9 [16 00]  |   RET
     0x017a: 16 [00 7D]  |   MVI D, 0x00
     0x017b: 00 [7D 21]  |   NOP
     0x017c: 7D [21 09]  |   MOV A, L
     0x017d: 21 [09 20]  |   LXI H, 0x2009 
     0x017e: 09 [20 46]  |   DAD B
     0x017f: 20 [46 23]  |   Undefined instruction
     0x0180: 46 [23 4E]  |   MOV B, M
     0x0181: 23 [4E FE]  |   INX H
     0x0182: 4E [FE 0B]  |   MOV C, M
     0x0183: FE [0B FA]  |   CPI 0x0B
     0x0184: 0B [FA 94]  |   DCX B
     0x0185: FA [94 01]  |   JM 0x0194
     0x0186: 94 [01 DE]  |   SUB H
     0x0187: 01 [DE 0B]  |   LXI B, 0x0BDE 
     0x0188: DE [0B 5F]  |   SBI 0x0B
     0x0189: 0B [5F 78]  |   DCX B
     0x018a: 5F [78 C6]  |   MOV E, A
     0x018b: 78 [C6 10]  |   MOV A, B
     0x018c: C6 [10 47]  |   ADI 0x10
     0x018d: 10 [47 7B]  |   Undefined instruction
     0x018e: 47 [7B 14]  |   MOV B, A
     0x018f: 7B [14 C3]  |   MOV A, E
     0x0190: 14 [C3 83]  |   INR D
     0x0191: C3 [83 01]  |   JMP 0x0183
     0x0192: 83 [01 68]  |   ADD E
     0x0193: 01 [68 A7]  |   LXI B, 0xA768 
     0x0194: 68 [A7 C8]  |   MOV L, B
     0x0195: A7 [C8 5F]  |   ANA A
     0x0196: C8 [5F 79]  |   RZ
     0x0197: 5F [79 C6]  |   MOV E, A
     0x0198: 79 [C6 10]  |   MOV A, C
     0x0199: C6 [10 4F]  |   ADI 0x10
     0x019a: 10 [4F 7B]  |   Undefined instruction
     0x019b: 4F [7B 3D]  |   MOV C, A
     0x019c: 7B [3D C3]  |   MOV A, E
     0x019d: 3D [C3 95]  |   DCR A
     0x019e: C3 [95 01]  |   JMP 0x0195
     0x019f: 95 [01 15]  |   SUB L
     0x01a0: 01 [15 CA]  |   LXI B, 0xCA15 
     0x01a1: 15 [CA CD]  |   DCR D
     0x01a2: CA [CD 01]  |   JZ 0x01CD
     0x01a3: CD [01 21]  |   CAL 0x2101
     0x01a4: 01 [21 06]  |   LXI B, 0x0621 
     0x01a5: 21 [06 20]  |   LXI H, 0x2006 
     0x01a6: 06 [20 36]  |   MVI B, 0x20
     0x01a7: 20 [36 00]  |   Undefined instruction
     0x01a8: 36 [00 23]  |   MVI M, 0x00
     0x01a9: 00 [23 4E]  |   NOP
     0x01aa: 23 [4E 36]  |   INX H
     0x01ab: 4E [36 00]  |   MOV C, M
     0x01ac: 36 [00 CD]  |   MVI M, 0x00
     0x01ad: 00 [CD D9]  |   NOP
     0x01ae: CD [D9 01]  |   CAL 0x01D9
     0x01af: D9 [01 21]  |   Undefined instruction
     0x01b0: 01 [21 05]  |   LXI B, 0x0521 
     0x01b1: 21 [05 20]  |   LXI H, 0x2005 
     0x01b2: 05 [20 7E]  |   DCR B
     0x01b3: 20 [7E 3C]  |   Undefined instruction
     0x01b4: 7E [3C E6]  |   MOV A, M
     0x01b5: 3C [E6 01]  |   INR A
     0x01b6: E6 [01 77]  |   ANI 0x01
     0x01b7: 01 [77 AF]  |   LXI B, 0xAF77 
     0x01b8: 77 [AF 21]  |   MOV M, A
     0x01b9: AF [21 67]  |   XRA A
     0x01ba: 21 [67 20]  |   LXI H, 0x2067 
     0x01bb: 67 [20 66]  |   MOV H, A
     0x01bc: 20 [66 C9]  |   Undefined instruction
     0x01bd: 66 [C9 00]  |   MOV H, M
     0x01be: C9 [00 21]  |   RET
     0x01bf: 00 [21 00]  |   NOP
     0x01c0: 21 [00 21]  |   LXI H, 0x2100 
     0x01c1: 00 [21 06]  |   NOP
     0x01c2: 21 [06 37]  |   LXI H, 0x3706 
     0x01c3: 06 [37 36]  |   MVI B, 0x37
     0x01c4: 37 [36 01]  |   STC
     0x01c5: 36 [01 23]  |   MVI M, 0x01
     0x01c6: 01 [23 05]  |   LXI B, 0x0523 
     0x01c7: 23 [05 C2]  |   INX H
     0x01c8: 05 [C2 C5]  |   DCR B
     0x01c9: C2 [C5 01]  |   JNZ 0x01C5
     0x01ca: C5 [01 C9]  |   PUSH B
     0x01cb: 01 [C9 E1]  |   LXI B, 0xE1C9 
     0x01cc: C9 [E1 C9]  |   RET
     0x01cd: E1 [C9 3E]  |   POP H
     0x01ce: C9 [3E 01]  |   RET
     0x01cf: 3E [01 06]  |   MVI A, 0x01
     0x01d0: 01 [06 E0]  |   LXI B, 0xE006 
     0x01d1: 06 [E0 21]  |   MVI B, 0xE0
     0x01d2: E0 [21 02]  |   RPO
     0x01d3: 21 [02 24]  |   LXI H, 0x2402 
     0x01d4: 02 [24 C3]  |   STAX B
     0x01d5: 24 [C3 CC]  |   INR H
     0x01d6: C3 [CC 14]  |   JMP 0x14CC
     0x01d7: CC [14 23]  |   CZ 0x2314
     0x01d8: 14 [23 46]  |   INR D
     0x01d9: 23 [46 23]  |   INX H
     0x01da: 46 [23 79]  |   MOV B, M
     0x01db: 23 [79 86]  |   INX H
     0x01dc: 79 [86 77]  |   MOV A, C
     0x01dd: 86 [77 23]  |   ADD M
     0x01de: 77 [23 78]  |   MOV M, A
     0x01df: 23 [78 86]  |   INX H
     0x01e0: 78 [86 77]  |   MOV A, B
     0x01e1: 86 [77 C9]  |   ADD M
     0x01e2: 77 [C9 06]  |   MOV M, A
     0x01e3: C9 [06 C0]  |   RET
     0x01e4: 06 [C0 11]  |   MVI B, 0xC0
     0x01e5: C0 [11 00]  |   RNZ
     0x01e6: 11 [00 1B]  |   LXI D, 0x1B00 
     0x01e7: 00 [1B 21]  |   NOP
     0x01e8: 1B [21 00]  |   DCX D
     0x01e9: 21 [00 20]  |   LXI H, 0x2000 
     0x01ea: 00 [20 C3]  |   NOP
     0x01eb: 20 [C3 32]  |   Undefined instruction
     0x01ec: C3 [32 1A]  |   JMP 0x1A32
     0x01ed: 32 [1A 21]  |   STA 0x211A
     0x01ee: 1A [21 42]  |   LDAX D
     0x01ef: 21 [42 21]  |   LXI H, 0x2142 
     0x01f0: 42 [21 C3]  |   MOV B, D
     0x01f1: 21 [C3 F8]  |   LXI H, 0xF8C3 
     0x01f2: C3 [F8 01]  |   JMP 0x01F8
     0x01f3: F8 [01 21]  |   RM
     0x01f4: 01 [21 42]  |   LXI B, 0x4221 
     0x01f5: 21 [42 22]  |   LXI H, 0x2242 
     0x01f6: 42 [22 0E]  |   MOV B, D
     0x01f7: 22 [0E 04]  |   SHLD 0x040E
     0x01f8: 0E [04 11]  |   MVI C, 0x04
     0x01f9: 04 [11 20]  |   INR B
     0x01fa: 11 [20 1D]  |   LXI D, 0x1D20 
     0x01fb: 20 [1D D5]  |   Undefined instruction
     0x01fc: 1D [D5 06]  |   DCR E
     0x01fd: D5 [06 2C]  |   PUSH D
     0x01fe: 06 [2C CD]  |   MVI B, 0x2C
     0x01ff: 2C [CD 32]  |   INR L
     0x0200: CD [32 1A]  |   CAL 0x1A32
     0x0201: 32 [1A D1]  |   STA 0xD11A
     0x0202: 1A [D1 0D]  |   LDAX D
     0x0203: D1 [0D C2]  |   POP D
     0x0204: 0D [C2 FD]  |   DCR C
     0x0205: C2 [FD 01]  |   JNZ 0x01FD
     0x0206: FD [01 C9]  |   Undefined instruction
     0x0207: 01 [C9 3E]  |   LXI B, 0x3EC9 
     0x0208: C9 [3E 01]  |   RET
     0x0209: 3E [01 C3]  |   MVI A, 0x01
     0x020a: 01 [C3 1B]  |   LXI B, 0x1BC3 
     0x020b: C3 [1B 02]  |   JMP 0x021B
     0x020c: 1B [02 3E]  |   DCX D
     0x020d: 02 [3E 01]  |   STAX B
     0x020e: 3E [01 C3]  |   MVI A, 0x01
     0x020f: 01 [C3 14]  |   LXI B, 0x14C3 
     0x0210: C3 [14 02]  |   JMP 0x0214
     0x0211: 14 [02 AF]  |   INR D
     0x0212: 02 [AF 11]  |   STAX B
     0x0213: AF [11 42]  |   XRA A
     0x0214: 11 [42 22]  |   LXI D, 0x2242 
     0x0215: 42 [22 C3]  |   MOV B, D
     0x0216: 22 [C3 1E]  |   SHLD 0x1EC3
     0x0217: C3 [1E 02]  |   JMP 0x021E
     0x0218: 1E [02 AF]  |   MVI E, 0x02
     0x0219: 02 [AF 11]  |   STAX B
     0x021a: AF [11 42]  |   XRA A
     0x021b: 11 [42 21]  |   LXI D, 0x2142 
     0x021c: 42 [21 32]  |   MOV B, D
     0x021d: 21 [32 81]  |   LXI H, 0x8132 
     0x021e: 32 [81 20]  |   STA 0x2081
     0x021f: 81 [20 01]  |   ADD C
     0x0220: 20 [01 02]  |   Undefined instruction
     0x0221: 01 [02 16]  |   LXI B, 0x1602 
     0x0222: 02 [16 21]  |   STAX B
     0x0223: 16 [21 06]  |   MVI D, 0x21
     0x0224: 21 [06 28]  |   LXI H, 0x2806 
     0x0225: 06 [28 3E]  |   MVI B, 0x28
     0x0226: 28 [3E 04]  |   Undefined instruction
     0x0227: 3E [04 F5]  |   MVI A, 0x04
     0x0228: 04 [F5 C5]  |   INR B
     0x0229: F5 [C5 3A]  |   PUSH PSW
     0x022a: C5 [3A 81]  |   PUSH B
     0x022b: 3A [81 20]  |   LDA 0x2081
     0x022c: 81 [20 A7]  |   ADD C
     0x022d: 20 [A7 C2]  |   Undefined instruction
     0x022e: A7 [C2 42]  |   ANA A
     0x022f: C2 [42 02]  |   JNZ 0x0242
     0x0230: 42 [02 CD]  |   MOV B, D
     0x0231: 02 [CD 69]  |   STAX B
     0x0232: CD [69 1A]  |   CAL 0x1A69
     0x0233: 69 [1A C1]  |   MOV L, C
     0x0234: 1A [C1 F1]  |   LDAX D
     0x0235: C1 [F1 3D]  |   POP B
     0x0236: F1 [3D C8]  |   POP PSW
     0x0237: 3D [C8 D5]  |   DCR A
     0x0238: C8 [D5 11]  |   RZ
     0x0239: D5 [11 E0]  |   PUSH D
     0x023a: 11 [E0 02]  |   LXI D, 0x02E0 
     0x023b: E0 [02 19]  |   RPO
     0x023c: 02 [19 D1]  |   STAX B
     0x023d: 19 [D1 C3]  |   DAD D
     0x023e: D1 [C3 29]  |   POP D
     0x023f: C3 [29 02]  |   JMP 0x0229
     0x0240: 29 [02 CD]  |   DAD H
     0x0241: 02 [CD 7C]  |   STAX B
     0x0242: CD [7C 14]  |   CAL 0x147C
     0x0243: 7C [14 C3]  |   MOV A, H
     0x0244: 14 [C3 35]  |   INR D
     0x0245: C3 [35 02]  |   JMP 0x0235
     0x0246: 35 [02 21]  |   DCR M
     0x0247: 02 [21 10]  |   STAX B
     0x0248: 21 [10 20]  |   LXI H, 0x2010 
     0x0249: 10 [20 7E]  |   Undefined instruction
     0x024a: 20 [7E FE]  |   Undefined instruction
     0x024b: 7E [FE FF]  |   MOV A, M
     0x024c: FE [FF C8]  |   CPI 0xFF
     0x024d: FF [C8 FE]  |   RST 7
     0x024e: C8 [FE FE]  |   RZ
     0x024f: FE [FE CA]  |   CPI 0xFE
     0x0250: FE [CA 81]  |   CPI 0xCA
     0x0251: CA [81 02]  |   JZ 0x0281
     0x0252: 81 [02 23]  |   ADD C
     0x0253: 02 [23 46]  |   STAX B
     0x0254: 23 [46 4F]  |   INX H
     0x0255: 46 [4F B0]  |   MOV B, M
     0x0256: 4F [B0 79]  |   MOV C, A
     0x0257: B0 [79 C2]  |   ORA B
     0x0258: 79 [C2 77]  |   MOV A, C
     0x0259: C2 [77 02]  |   JNZ 0x0277
     0x025a: 77 [02 23]  |   MOV M, A
     0x025b: 02 [23 7E]  |   STAX B
     0x025c: 23 [7E A7]  |   INX H
     0x025d: 7E [A7 C2]  |   MOV A, M
     0x025e: A7 [C2 88]  |   ANA A
     0x025f: C2 [88 02]  |   JNZ 0x0288
     0x0260: 88 [02 23]  |   ADC B
     0x0261: 02 [23 5E]  |   STAX B
     0x0262: 23 [5E 23]  |   INX H
     0x0263: 5E [23 56]  |   MOV E, M
     0x0264: 23 [56 E5]  |   INX H
     0x0265: 56 [E5 EB]  |   MOV D, M
     0x0266: E5 [EB E5]  |   PUSH H
     0x0267: EB [E5 21]  |   XCHG
     0x0268: E5 [21 6F]  |   PUSH H
     0x0269: 21 [6F 02]  |   LXI H, 0x026F 
     0x026a: 6F [02 E3]  |   MOV L, A
     0x026b: 02 [E3 D5]  |   STAX B
     0x026c: E3 [D5 E9]  |   XTHL
     0x026d: D5 [E9 E1]  |   PUSH D
     0x026e: E9 [E1 11]  |   PCHL
     0x026f: E1 [11 0C]  |   POP H
     0x0270: 11 [0C 00]  |   LXI D, 0x000C 
     0x0271: 0C [00 19]  |   INR C
     0x0272: 00 [19 C3]  |   NOP
     0x0273: 19 [C3 4B]  |   DAD D
     0x0274: C3 [4B 02]  |   JMP 0x024B
     0x0275: 4B [02 05]  |   MOV C, E
     0x0276: 02 [05 04]  |   STAX B
     0x0277: 05 [04 C2]  |   DCR B
     0x0278: 04 [C2 7D]  |   INR B
     0x0279: C2 [7D 02]  |   JNZ 0x027D
     0x027a: 7D [02 3D]  |   MOV A, L
     0x027b: 02 [3D 05]  |   STAX B
     0x027c: 3D [05 70]  |   DCR A
     0x027d: 05 [70 2B]  |   DCR B
     0x027e: 70 [2B 77]  |   MOV M, B
     0x027f: 2B [77 11]  |   DCX H
     0x0280: 77 [11 10]  |   MOV M, A
     0x0281: 11 [10 00]  |   LXI D, 0x0010 
     0x0282: 10 [00 19]  |   Undefined instruction
     0x0283: 00 [19 C3]  |   NOP
     0x0284: 19 [C3 4B]  |   DAD D
     0x0285: C3 [4B 02]  |   JMP 0x024B
     0x0286: 4B [02 35]  |   MOV C, E
     0x0287: 02 [35 2B]  |   STAX B
     0x0288: 35 [2B 2B]  |   DCR M
     0x0289: 2B [2B C3]  |   DCX H
     0x028a: 2B [C3 81]  |   DCX H
     0x028b: C3 [81 02]  |   JMP 0x0281
     0x028c: 81 [02 E1]  |   ADD C
     0x028d: 02 [E1 23]  |   STAX B
     0x028e: E1 [23 7E]  |   POP H
     0x028f: 23 [7E FE]  |   INX H
     0x0290: 7E [FE FF]  |   MOV A, M
     0x0291: FE [FF CA]  |   CPI 0xFF
     0x0292: FF [CA 3B]  |   RST 7
     0x0293: CA [3B 03]  |   JZ 0x033B
     0x0294: 3B [03 23]  |   DCX SP
     0x0295: 03 [23 35]  |   INX B
     0x0296: 23 [35 C0]  |   INX H
     0x0297: 35 [C0 47]  |   DCR M
     0x0298: C0 [47 AF]  |   RNZ
     0x0299: 47 [AF 32]  |   MOV B, A
     0x029a: AF [32 68]  |   XRA A
     0x029b: 32 [68 20]  |   STA 0x2068
     0x029c: 68 [20 32]  |   MOV L, B
     0x029d: 20 [32 69]  |   Undefined instruction
     0x029e: 32 [69 20]  |   STA 0x2069
     0x029f: 69 [20 3E]  |   MOV L, C
     0x02a0: 20 [3E 30]  |   Undefined instruction
     0x02a1: 3E [30 32]  |   MVI A, 0x30
     0x02a2: 30 [32 6A]  |   Undefined instruction
     0x02a3: 32 [6A 20]  |   STA 0x206A
     0x02a4: 6A [20 78]  |   MOV L, D
     0x02a5: 20 [78 36]  |   Undefined instruction
     0x02a6: 78 [36 05]  |   MOV A, B
     0x02a7: 36 [05 23]  |   MVI M, 0x05
     0x02a8: 05 [23 35]  |   DCR B
     0x02a9: 23 [35 C2]  |   INX H
     0x02aa: 35 [C2 9B]  |   DCR M
     0x02ab: C2 [9B 03]  |   JNZ 0x039B
     0x02ac: 9B [03 2A]  |   SBB E
     0x02ad: 03 [2A 1A]  |   INX B
     0x02ae: 2A [1A 20]  |   LHLD 0x201A
     0x02af: 1A [20 06]  |   LDAX D
     0x02b0: 20 [06 10]  |   Undefined instruction
     0x02b1: 06 [10 CD]  |   MVI B, 0x10
     0x02b2: 10 [CD 24]  |   Undefined instruction
     0x02b3: CD [24 14]  |   CAL 0x1424
     0x02b4: 24 [14 21]  |   INR H
     0x02b5: 14 [21 10]  |   INR D
     0x02b6: 21 [10 20]  |   LXI H, 0x2010 
     0x02b7: 10 [20 11]  |   Undefined instruction
     0x02b8: 20 [11 10]  |   Undefined instruction
     0x02b9: 11 [10 1B]  |   LXI D, 0x1B10 
     0x02ba: 10 [1B 06]  |   Undefined instruction
     0x02bb: 1B [06 10]  |   DCX D
     0x02bc: 06 [10 CD]  |   MVI B, 0x10
     0x02bd: 10 [CD 32]  |   Undefined instruction
     0x02be: CD [32 1A]  |   CAL 0x1A32
     0x02bf: 32 [1A 06]  |   STA 0x061A
     0x02c0: 1A [06 00]  |   LDAX D
     0x02c1: 06 [00 CD]  |   MVI B, 0x00
     0x02c2: 00 [CD DC]  |   NOP
     0x02c3: CD [DC 19]  |   CAL 0x19DC
     0x02c4: DC [19 3A]  |   CC 0x3A19
     0x02c5: 19 [3A 6D]  |   DAD D
     0x02c6: 3A [6D 20]  |   LDA 0x206D
     0x02c7: 6D [20 A7]  |   MOV L, L
     0x02c8: 20 [A7 C0]  |   Undefined instruction
     0x02c9: A7 [C0 3A]  |   ANA A
     0x02ca: C0 [3A EF]  |   RNZ
     0x02cb: 3A [EF 20]  |   LDA 0x20EF
     0x02cc: EF [20 A7]  |   RST 5
     0x02cd: 20 [A7 C8]  |   Undefined instruction
     0x02ce: A7 [C8 31]  |   ANA A
     0x02cf: C8 [31 00]  |   RZ
     0x02d0: 31 [00 24]  |   LXI SP, 0x2400 
     0x02d1: 00 [24 FB]  |   NOP
     0x02d2: 24 [FB CD]  |   INR H
     0x02d3: FB [CD D7]  |   EI
     0x02d4: CD [D7 19]  |   CAL 0x19D7
     0x02d5: D7 [19 CD]  |   RST 2
     0x02d6: 19 [CD 2E]  |   DAD D
     0x02d7: CD [2E 09]  |   CAL 0x092E
     0x02d8: 2E [09 A7]  |   MVI L, 0x09
     0x02d9: 09 [A7 CA]  |   DAD B
     0x02da: A7 [CA 6D]  |   ANA A
     0x02db: CA [6D 16]  |   JZ 0x166D
     0x02dc: 6D [16 CD]  |   MOV L, L
     0x02dd: 16 [CD E7]  |   MVI D, 0xCD
     0x02de: CD [E7 18]  |   CAL 0x18E7
     0x02df: E7 [18 7E]  |   RST 4
     0x02e0: 18 [7E A7]  |   Undefined instruction
     0x02e1: 7E [A7 CA]  |   MOV A, M
     0x02e2: A7 [CA 2C]  |   ANA A
     0x02e3: CA [2C 03]  |   JZ 0x032C
     0x02e4: 2C [03 3A]  |   INR L
     0x02e5: 03 [3A CE]  |   INX B
     0x02e6: 3A [CE 20]  |   LDA 0x20CE
     0x02e7: CE [20 A7]  |   ACI 0x20
     0x02e8: 20 [A7 CA]  |   Undefined instruction
     0x02e9: A7 [CA 2C]  |   ANA A
     0x02ea: CA [2C 03]  |   JZ 0x032C
     0x02eb: 2C [03 3A]  |   INR L
     0x02ec: 03 [3A 67]  |   INX B
     0x02ed: 3A [67 20]  |   LDA 0x2067
     0x02ee: 67 [20 F5]  |   MOV H, A
     0x02ef: 20 [F5 0F]  |   Undefined instruction
     0x02f0: F5 [0F DA]  |   PUSH PSW
     0x02f1: 0F [DA 32]  |   RRC
     0x02f2: DA [32 03]  |   JC 0x0332
     0x02f3: 32 [03 CD]  |   STA 0xCD03
     0x02f4: 03 [CD 0E]  |   INX B
     0x02f5: CD [0E 02]  |   CAL 0x020E
     0x02f6: 0E [02 CD]  |   MVI C, 0x02
     0x02f7: 02 [CD 78]  |   STAX B
     0x02f8: CD [78 08]  |   CAL 0x0878
     0x02f9: 78 [08 73]  |   MOV A, B
     0x02fa: 08 [73 23]  |   Undefined instruction
     0x02fb: 73 [23 72]  |   MOV M, E
     0x02fc: 23 [72 2B]  |   INX H
     0x02fd: 72 [2B 2B]  |   MOV M, D
     0x02fe: 2B [2B 70]  |   DCX H
     0x02ff: 2B [70 00]  |   DCX H
     0x0300: 70 [00 CD]  |   MOV M, B
     0x0301: 00 [CD E4]  |   NOP
     0x0302: CD [E4 01]  |   CAL 0x01E4
     0x0303: E4 [01 F1]  |   CPO 0xF101
     0x0304: 01 [F1 0F]  |   LXI B, 0x0FF1 
     0x0305: F1 [0F 3E]  |   POP PSW
     0x0306: 0F [3E 21]  |   RRC
     0x0307: 3E [21 06]  |   MVI A, 0x21
     0x0308: 21 [06 00]  |   LXI H, 0x0006 
     0x0309: 06 [00 D2]  |   MVI B, 0x00
     0x030a: 00 [D2 12]  |   NOP
     0x030b: D2 [12 03]  |   JNC 0x0312
     0x030c: 12 [03 06]  |   STAX D
     0x030d: 03 [06 20]  |   INX B
     0x030e: 06 [20 3E]  |   MVI B, 0x20
     0x030f: 20 [3E 22]  |   Undefined instruction
     0x0310: 3E [22 32]  |   MVI A, 0x22
     0x0311: 22 [32 67]  |   SHLD 0x6732
     0x0312: 32 [67 20]  |   STA 0x2067
     0x0313: 67 [20 CD]  |   MOV H, A
     0x0314: 20 [CD B6]  |   Undefined instruction
     0x0315: CD [B6 0A]  |   CAL 0x0AB6
     0x0316: B6 [0A AF]  |   ORA M
     0x0317: 0A [AF 32]  |   LDAX B
     0x0318: AF [32 11]  |   XRA A
     0x0319: 32 [11 20]  |   STA 0x2011
     0x031a: 11 [20 78]  |   LXI D, 0x7820 
     0x031b: 20 [78 D3]  |   Undefined instruction
     0x031c: 78 [D3 05]  |   MOV A, B
     0x031d: D3 [05 3C]  |   OUT 0x05
     0x031e: 05 [3C 32]  |   DCR B
     0x031f: 3C [32 98]  |   INR A
     0x0320: 32 [98 20]  |   STA 0x2098
     0x0321: 98 [20 CD]  |   SBB B
     0x0322: 20 [CD D6]  |   Undefined instruction
     0x0323: CD [D6 09]  |   CAL 0x09D6
     0x0324: D6 [09 CD]  |   SUI 0x09
     0x0325: 09 [CD 7F]  |   DAD B
     0x0326: CD [7F 1A]  |   CAL 0x1A7F
     0x0327: 7F [1A C3]  |   MOV A, A
     0x0328: 1A [C3 F9]  |   LDAX D
     0x0329: C3 [F9 07]  |   JMP 0x07F9
     0x032a: F9 [07 CD]  |   SPHL
     0x032b: 07 [CD 7F]  |   RLC
     0x032c: CD [7F 1A]  |   CAL 0x1A7F
     0x032d: 7F [1A C3]  |   MOV A, A
     0x032e: 1A [C3 17]  |   LDAX D
     0x032f: C3 [17 08]  |   JMP 0x0817
     0x0330: 17 [08 CD]  |   RAL
     0x0331: 08 [CD 09]  |   Undefined instruction
     0x0332: CD [09 02]  |   CAL 0x0209
     0x0333: 09 [02 C3]  |   DAD B
     0x0334: 02 [C3 F8]  |   STAX B
     0x0335: C3 [F8 02]  |   JMP 0x02F8
     0x0336: F8 [02 00]  |   RM
     0x0337: 02 [00 00]  |   STAX B
     0x0338: 00 [00 00]  |   NOP
     0x0339: 00 [00 21]  |   NOP
     0x033a: 00 [21 68]  |   NOP
     0x033b: 21 [68 20]  |   LXI H, 0x2068 
     0x033c: 68 [20 36]  |   MOV L, B
     0x033d: 20 [36 01]  |   Undefined instruction
     0x033e: 36 [01 23]  |   MVI M, 0x01
     0x033f: 01 [23 7E]  |   LXI B, 0x7E23 
     0x0340: 23 [7E A7]  |   INX H
     0x0341: 7E [A7 C3]  |   MOV A, M
     0x0342: A7 [C3 B0]  |   ANA A
     0x0343: C3 [B0 03]  |   JMP 0x03B0
     0x0344: B0 [03 00]  |   ORA B
     0x0345: 03 [00 2B]  |   INX B
     0x0346: 00 [2B 36]  |   NOP
     0x0347: 2B [36 01]  |   DCX H
     0x0348: 36 [01 3A]  |   MVI M, 0x01
     0x0349: 01 [3A 1B]  |   LXI B, 0x1B3A 
     0x034a: 3A [1B 20]  |   LDA 0x201B
     0x034b: 1B [20 47]  |   DCX D
     0x034c: 20 [47 3A]  |   Undefined instruction
     0x034d: 47 [3A EF]  |   MOV B, A
     0x034e: 3A [EF 20]  |   LDA 0x20EF
     0x034f: EF [20 A7]  |   RST 5
     0x0350: 20 [A7 C2]  |   Undefined instruction
     0x0351: A7 [C2 63]  |   ANA A
     0x0352: C2 [63 03]  |   JNZ 0x0363
     0x0353: 63 [03 3A]  |   MOV H, E
     0x0354: 03 [3A 1D]  |   INX B
     0x0355: 3A [1D 20]  |   LDA 0x201D
     0x0356: 1D [20 0F]  |   DCR E
     0x0357: 20 [0F DA]  |   Undefined instruction
     0x0358: 0F [DA 81]  |   RRC
     0x0359: DA [81 03]  |   JC 0x0381
     0x035a: 81 [03 0F]  |   ADD C
     0x035b: 03 [0F DA]  |   INX B
     0x035c: 0F [DA 8E]  |   RRC
     0x035d: DA [8E 03]  |   JC 0x038E
     0x035e: 8E [03 C3]  |   ADC M
     0x035f: 03 [C3 6F]  |   INX B
     0x0360: C3 [6F 03]  |   JMP 0x036F
     0x0361: 6F [03 CD]  |   MOV L, A
     0x0362: 03 [CD C0]  |   INX B
     0x0363: CD [C0 17]  |   CAL 0x17C0
     0x0364: C0 [17 07]  |   RNZ
     0x0365: 17 [07 07]  |   RAL
     0x0366: 07 [07 DA]  |   RLC
     0x0367: 07 [DA 81]  |   RLC
     0x0368: DA [81 03]  |   JC 0x0381
     0x0369: 81 [03 07]  |   ADD C
     0x036a: 03 [07 DA]  |   INX B
     0x036b: 07 [DA 8E]  |   RLC
     0x036c: DA [8E 03]  |   JC 0x038E
     0x036d: 8E [03 21]  |   ADC M
     0x036e: 03 [21 18]  |   INX B
     0x036f: 21 [18 20]  |   LXI H, 0x2018 
     0x0370: 18 [20 CD]  |   Undefined instruction
     0x0371: 20 [CD 3B]  |   Undefined instruction
     0x0372: CD [3B 1A]  |   CAL 0x1A3B
     0x0373: 3B [1A CD]  |   DCX SP
     0x0374: 1A [CD 47]  |   LDAX D
     0x0375: CD [47 1A]  |   CAL 0x1A47
     0x0376: 47 [1A CD]  |   MOV B, A
     0x0377: 1A [CD 39]  |   LDAX D
     0x0378: CD [39 14]  |   CAL 0x1439
     0x0379: 39 [14 3E]  |   DAD SP
     0x037a: 14 [3E 00]  |   INR D
     0x037b: 3E [00 32]  |   MVI A, 0x00
     0x037c: 00 [32 12]  |   NOP
     0x037d: 32 [12 20]  |   STA 0x2012
     0x037e: 12 [20 C9]  |   STAX D
     0x037f: 20 [C9 78]  |   Undefined instruction
     0x0380: C9 [78 FE]  |   RET
     0x0381: 78 [FE D9]  |   MOV A, B
     0x0382: FE [D9 CA]  |   CPI 0xD9
     0x0383: D9 [CA 6F]  |   Undefined instruction
     0x0384: CA [6F 03]  |   JZ 0x036F
     0x0385: 6F [03 3C]  |   MOV L, A
     0x0386: 03 [3C 32]  |   INX B
     0x0387: 3C [32 1B]  |   INR A
     0x0388: 32 [1B 20]  |   STA 0x201B
     0x0389: 1B [20 C3]  |   DCX D
     0x038a: 20 [C3 6F]  |   Undefined instruction
     0x038b: C3 [6F 03]  |   JMP 0x036F
     0x038c: 6F [03 78]  |   MOV L, A
     0x038d: 03 [78 FE]  |   INX B
     0x038e: 78 [FE 30]  |   MOV A, B
     0x038f: FE [30 CA]  |   CPI 0x30
     0x0390: 30 [CA 6F]  |   Undefined instruction
     0x0391: CA [6F 03]  |   JZ 0x036F
     0x0392: 6F [03 3D]  |   MOV L, A
     0x0393: 03 [3D 32]  |   INX B
     0x0394: 3D [32 1B]  |   DCR A
     0x0395: 32 [1B 20]  |   STA 0x201B
     0x0396: 1B [20 C3]  |   DCX D
     0x0397: 20 [C3 6F]  |   Undefined instruction
     0x0398: C3 [6F 03]  |   JMP 0x036F
     0x0399: 6F [03 3C]  |   MOV L, A
     0x039a: 03 [3C E6]  |   INX B
     0x039b: 3C [E6 01]  |   INR A
     0x039c: E6 [01 32]  |   ANI 0x01
     0x039d: 01 [32 15]  |   LXI B, 0x1532 
     0x039e: 32 [15 20]  |   STA 0x2015
     0x039f: 15 [20 07]  |   DCR D
     0x03a0: 20 [07 07]  |   Undefined instruction
     0x03a1: 07 [07 07]  |   RLC
     0x03a2: 07 [07 07]  |   RLC
     0x03a3: 07 [07 21]  |   RLC
     0x03a4: 07 [21 70]  |   RLC
     0x03a5: 21 [70 1C]  |   LXI H, 0x1C70 
     0x03a6: 70 [1C 85]  |   MOV M, B
     0x03a7: 1C [85 6F]  |   INR E
     0x03a8: 85 [6F 22]  |   ADD L
     0x03a9: 6F [22 18]  |   MOV L, A
     0x03aa: 22 [18 20]  |   SHLD 0x2018
     0x03ab: 18 [20 C3]  |   Undefined instruction
     0x03ac: 20 [C3 6F]  |   Undefined instruction
     0x03ad: C3 [6F 03]  |   JMP 0x036F
     0x03ae: 6F [03 C2]  |   MOV L, A
     0x03af: 03 [C2 4A]  |   INX B
     0x03b0: C2 [4A 03]  |   JNZ 0x034A
     0x03b1: 4A [03 23]  |   MOV C, D
     0x03b2: 03 [23 35]  |   INX B
     0x03b3: 23 [35 C2]  |   INX H
     0x03b4: 35 [C2 4A]  |   DCR M
     0x03b5: C2 [4A 03]  |   JNZ 0x034A
     0x03b6: 4A [03 C3]  |   MOV C, D
     0x03b7: 03 [C3 46]  |   INX B
     0x03b8: C3 [46 03]  |   JMP 0x0346
     0x03b9: 46 [03 11]  |   MOV B, M
     0x03ba: 03 [11 2A]  |   INX B
     0x03bb: 11 [2A 20]  |   LXI D, 0x202A 
     0x03bc: 2A [20 CD]  |   LHLD 0xCD20
     0x03bd: 20 [CD 06]  |   Undefined instruction
     0x03be: CD [06 1A]  |   CAL 0x1A06
     0x03bf: 06 [1A E1]  |   MVI B, 0x1A
     0x03c0: 1A [E1 D0]  |   LDAX D
     0x03c1: E1 [D0 23]  |   POP H
     0x03c2: D0 [23 7E]  |   RNC
     0x03c3: 23 [7E A7]  |   INX H
     0x03c4: 7E [A7 C8]  |   MOV A, M
     0x03c5: A7 [C8 FE]  |   ANA A
     0x03c6: C8 [FE 01]  |   RZ
     0x03c7: FE [01 CA]  |   CPI 0x01
     0x03c8: 01 [CA FA]  |   LXI B, 0xFACA 
     0x03c9: CA [FA 03]  |   JZ 0x03FA
     0x03ca: FA [03 FE]  |   JM 0xFE03
     0x03cb: 03 [FE 02]  |   INX B
     0x03cc: FE [02 CA]  |   CPI 0x02
     0x03cd: 02 [CA 0A]  |   STAX B
     0x03ce: CA [0A 04]  |   JZ 0x040A
     0x03cf: 0A [04 23]  |   LDAX B
     0x03d0: 04 [23 FE]  |   INR B
     0x03d1: 23 [FE 03]  |   INX H
     0x03d2: FE [03 C2]  |   CPI 0x03
     0x03d3: 03 [C2 2A]  |   INX B
     0x03d4: C2 [2A 04]  |   JNZ 0x042A
     0x03d5: 2A [04 35]  |   LHLD 0x3504
     0x03d6: 04 [35 CA]  |   INR B
     0x03d7: 35 [CA 36]  |   DCR M
     0x03d8: CA [36 04]  |   JZ 0x0436
     0x03d9: 36 [04 7E]  |   MVI M, 0x04
     0x03da: 04 [7E FE]  |   INR B
     0x03db: 7E [FE 0F]  |   MOV A, M
     0x03dc: FE [0F C0]  |   CPI 0x0F
     0x03dd: 0F [C0 E5]  |   RRC
     0x03de: C0 [E5 CD]  |   RNZ
     0x03df: E5 [CD 30]  |   PUSH H
     0x03e0: CD [30 04]  |   CAL 0x0430
     0x03e1: 30 [04 CD]  |   Undefined instruction
     0x03e2: 04 [CD 52]  |   INR B
     0x03e3: CD [52 14]  |   CAL 0x1452
     0x03e4: 52 [14 E1]  |   MOV D, D
     0x03e5: 14 [E1 23]  |   INR D
     0x03e6: E1 [23 34]  |   POP H
     0x03e7: 23 [34 23]  |   INX H
     0x03e8: 34 [23 23]  |   INR M
     0x03e9: 23 [23 35]  |   INX H
     0x03ea: 23 [35 35]  |   INX H
     0x03eb: 35 [35 23]  |   DCR M
     0x03ec: 35 [23 35]  |   DCR M
     0x03ed: 23 [35 35]  |   INX H
     0x03ee: 35 [35 35]  |   DCR M
     0x03ef: 35 [35 23]  |   DCR M
     0x03f0: 35 [23 36]  |   DCR M
     0x03f1: 23 [36 08]  |   INX H
     0x03f2: 36 [08 CD]  |   MVI M, 0x08
     0x03f3: 08 [CD 30]  |   Undefined instruction
     0x03f4: CD [30 04]  |   CAL 0x0430
     0x03f5: 30 [04 C3]  |   Undefined instruction
     0x03f6: 04 [C3 00]  |   INR B
     0x03f7: C3 [00 14]  |   JMP 0x1400
     0x03f8: 00 [14 3C]  |   NOP
     0x03f9: 14 [3C 77]  |   INR D
     0x03fa: 3C [77 3A]  |   INR A
     0x03fb: 77 [3A 1B]  |   MOV M, A
     0x03fc: 3A [1B 20]  |   LDA 0x201B
     0x03fd: 1B [20 C6]  |   DCX D
     0x03fe: 20 [C6 08]  |   Undefined instruction
     0x03ff: C6 [08 32]  |   ADI 0x08
     0x0400: 08 [32 2A]  |   Undefined instruction
     0x0401: 32 [2A 20]  |   STA 0x202A
     0x0402: 2A [20 CD]  |   LHLD 0xCD20
     0x0403: 20 [CD 30]  |   Undefined instruction
     0x0404: CD [30 04]  |   CAL 0x0430
     0x0405: 30 [04 C3]  |   Undefined instruction
     0x0406: 04 [C3 00]  |   INR B
     0x0407: C3 [00 14]  |   JMP 0x1400
     0x0408: 00 [14 CD]  |   NOP
     0x0409: 14 [CD 30]  |   INR D
     0x040a: CD [30 04]  |   CAL 0x0430
     0x040b: 30 [04 D5]  |   Undefined instruction
     0x040c: 04 [D5 E5]  |   INR B
     0x040d: D5 [E5 C5]  |   PUSH D
     0x040e: E5 [C5 CD]  |   PUSH H
     0x040f: C5 [CD 52]  |   PUSH B
     0x0410: CD [52 14]  |   CAL 0x1452
     0x0411: 52 [14 C1]  |   MOV D, D
     0x0412: 14 [C1 E1]  |   INR D
     0x0413: C1 [E1 D1]  |   POP B
     0x0414: E1 [D1 3A]  |   POP H
     0x0415: D1 [3A 2C]  |   POP D
     0x0416: 3A [2C 20]  |   LDA 0x202C
     0x0417: 2C [20 85]  |   INR L
     0x0418: 20 [85 6F]  |   Undefined instruction
     0x0419: 85 [6F 32]  |   ADD L
     0x041a: 6F [32 29]  |   MOV L, A
     0x041b: 32 [29 20]  |   STA 0x2029
     0x041c: 29 [20 CD]  |   DAD H
     0x041d: 20 [CD 91]  |   Undefined instruction
     0x041e: CD [91 14]  |   CAL 0x1491
     0x041f: 91 [14 3A]  |   SUB C
     0x0420: 14 [3A 61]  |   INR D
     0x0421: 3A [61 20]  |   LDA 0x2061
     0x0422: 61 [20 A7]  |   MOV H, C
     0x0423: 20 [A7 C8]  |   Undefined instruction
     0x0424: A7 [C8 32]  |   ANA A
     0x0425: C8 [32 02]  |   RZ
     0x0426: 32 [02 20]  |   STA 0x2002
     0x0427: 02 [20 C9]  |   STAX B
     0x0428: 20 [C9 FE]  |   Undefined instruction
     0x0429: C9 [FE 05]  |   RET
     0x042a: FE [05 C8]  |   CPI 0x05
     0x042b: 05 [C8 C3]  |   DCR B
     0x042c: C8 [C3 36]  |   RZ
     0x042d: C3 [36 04]  |   JMP 0x0436
     0x042e: 36 [04 21]  |   MVI M, 0x04
     0x042f: 04 [21 27]  |   INR B
     0x0430: 21 [27 20]  |   LXI H, 0x2027 
     0x0431: 27 [20 C3]  |   DAA
     0x0432: 20 [C3 3B]  |   Undefined instruction
     0x0433: C3 [3B 1A]  |   JMP 0x1A3B
     0x0434: 3B [1A CD]  |   DCX SP
     0x0435: 1A [CD 30]  |   LDAX D
     0x0436: CD [30 04]  |   CAL 0x0430
     0x0437: 30 [04 CD]  |   Undefined instruction
     0x0438: 04 [CD 52]  |   INR B
     0x0439: CD [52 14]  |   CAL 0x1452
     0x043a: 52 [14 21]  |   MOV D, D
     0x043b: 14 [21 25]  |   INR D
     0x043c: 21 [25 20]  |   LXI H, 0x2025 
     0x043d: 25 [20 11]  |   DCR H
     0x043e: 20 [11 25]  |   Undefined instruction
     0x043f: 11 [25 1B]  |   LXI D, 0x1B25 
     0x0440: 25 [1B 06]  |   DCR H
     0x0441: 1B [06 07]  |   DCX D
     0x0442: 06 [07 CD]  |   MVI B, 0x07
     0x0443: 07 [CD 32]  |   RLC
     0x0444: CD [32 1A]  |   CAL 0x1A32
     0x0445: 32 [1A 2A]  |   STA 0x2A1A
     0x0446: 1A [2A 8D]  |   LDAX D
     0x0447: 2A [8D 20]  |   LHLD 0x208D
     0x0448: 8D [20 2C]  |   ADC L
     0x0449: 20 [2C 7D]  |   Undefined instruction
     0x044a: 2C [7D FE]  |   INR L
     0x044b: 7D [FE 63]  |   MOV A, L
     0x044c: FE [63 DA]  |   CPI 0x63
     0x044d: 63 [DA 53]  |   MOV H, E
     0x044e: DA [53 04]  |   JC 0x0453
     0x044f: 53 [04 2E]  |   MOV D, E
     0x0450: 04 [2E 54]  |   INR B
     0x0451: 2E [54 22]  |   MVI L, 0x54
     0x0452: 54 [22 8D]  |   MOV D, H
     0x0453: 22 [8D 20]  |   SHLD 0x208D
     0x0454: 8D [20 2A]  |   ADC L
     0x0455: 20 [2A 8F]  |   Undefined instruction
     0x0456: 2A [8F 20]  |   LHLD 0x208F
     0x0457: 8F [20 2C]  |   ADC A
     0x0458: 20 [2C 22]  |   Undefined instruction
     0x0459: 2C [22 8F]  |   INR L
     0x045a: 22 [8F 20]  |   SHLD 0x208F
     0x045b: 8F [20 3A]  |   ADC A
     0x045c: 20 [3A 84]  |   Undefined instruction
     0x045d: 3A [84 20]  |   LDA 0x2084
     0x045e: 84 [20 A7]  |   ADD H
     0x045f: 20 [A7 C0]  |   Undefined instruction
     0x0460: A7 [C0 7E]  |   ANA A
     0x0461: C0 [7E E6]  |   RNZ
     0x0462: 7E [E6 01]  |   MOV A, M
     0x0463: E6 [01 01]  |   ANI 0x01
     0x0464: 01 [01 29]  |   LXI B, 0x2901 
     0x0465: 01 [29 02]  |   LXI B, 0x0229 
     0x0466: 29 [02 C2]  |   DAD H
     0x0467: 02 [C2 6E]  |   STAX B
     0x0468: C2 [6E 04]  |   JNZ 0x046E
     0x0469: 6E [04 01]  |   MOV L, M
     0x046a: 04 [01 E0]  |   INR B
     0x046b: 01 [E0 FE]  |   LXI B, 0xFEE0 
     0x046c: E0 [FE 21]  |   RPO
     0x046d: FE [21 8A]  |   CPI 0x21
     0x046e: 21 [8A 20]  |   LXI H, 0x208A 
     0x046f: 8A [20 71]  |   ADC D
     0x0470: 20 [71 23]  |   Undefined instruction
     0x0471: 71 [23 23]  |   MOV M, C
     0x0472: 23 [23 70]  |   INX H
     0x0473: 23 [70 C9]  |   INX H
     0x0474: 70 [C9 E1]  |   MOV M, B
     0x0475: C9 [E1 3A]  |   RET
     0x0476: E1 [3A 32]  |   POP H
     0x0477: 3A [32 1B]  |   LDA 0x1B32
     0x0478: 32 [1B 32]  |   STA 0x321B
     0x0479: 1B [32 32]  |   DCX D
     0x047a: 32 [32 20]  |   STA 0x2032
     0x047b: 32 [20 2A]  |   STA 0x2A20
     0x047c: 20 [2A 38]  |   Undefined instruction
     0x047d: 2A [38 20]  |   LHLD 0x2038
     0x047e: 38 [20 7D]  |   Undefined instruction
     0x047f: 20 [7D B4]  |   Undefined instruction
     0x0480: 7D [B4 C2]  |   MOV A, L
     0x0481: B4 [C2 8A]  |   ORA H
     0x0482: C2 [8A 04]  |   JNZ 0x048A
     0x0483: 8A [04 2B]  |   ADC D
     0x0484: 04 [2B 22]  |   INR B
     0x0485: 2B [22 38]  |   DCX H
     0x0486: 22 [38 20]  |   SHLD 0x2038
     0x0487: 38 [20 C9]  |   Undefined instruction
     0x0488: 20 [C9 11]  |   Undefined instruction
     0x0489: C9 [11 35]  |   RET
     0x048a: 11 [35 20]  |   LXI D, 0x2035 
     0x048b: 35 [20 3E]  |   DCR M
     0x048c: 20 [3E F9]  |   Undefined instruction
     0x048d: 3E [F9 CD]  |   MVI A, 0xF9
     0x048e: F9 [CD 50]  |   SPHL
     0x048f: CD [50 05]  |   CAL 0x0550
     0x0490: 50 [05 3A]  |   MOV D, B
     0x0491: 05 [3A 46]  |   DCR B
     0x0492: 3A [46 20]  |   LDA 0x2046
     0x0493: 46 [20 32]  |   MOV B, M
     0x0494: 20 [32 70]  |   Undefined instruction
     0x0495: 32 [70 20]  |   STA 0x2070
     0x0496: 70 [20 3A]  |   MOV M, B
     0x0497: 20 [3A 56]  |   Undefined instruction
     0x0498: 3A [56 20]  |   LDA 0x2056
     0x0499: 56 [20 32]  |   MOV D, M
     0x049a: 20 [32 71]  |   Undefined instruction
     0x049b: 32 [71 20]  |   STA 0x2071
     0x049c: 71 [20 CD]  |   MOV M, C
     0x049d: 20 [CD 63]  |   Undefined instruction
     0x049e: CD [63 05]  |   CAL 0x0563
     0x049f: 63 [05 3A]  |   MOV H, E
     0x04a0: 05 [3A 78]  |   DCR B
     0x04a1: 3A [78 20]  |   LDA 0x2078
     0x04a2: 78 [20 A7]  |   MOV A, B
     0x04a3: 20 [A7 21]  |   Undefined instruction
     0x04a4: A7 [21 35]  |   ANA A
     0x04a5: 21 [35 20]  |   LXI H, 0x2035 
     0x04a6: 35 [20 C2]  |   DCR M
     0x04a7: 20 [C2 5B]  |   Undefined instruction
     0x04a8: C2 [5B 05]  |   JNZ 0x055B
     0x04a9: 5B [05 11]  |   MOV E, E
     0x04aa: 05 [11 30]  |   DCR B
     0x04ab: 11 [30 1B]  |   LXI D, 0x1B30 
     0x04ac: 30 [1B 21]  |   Undefined instruction
     0x04ad: 1B [21 30]  |   DCX D
     0x04ae: 21 [30 20]  |   LXI H, 0x2030 
     0x04af: 30 [20 06]  |   Undefined instruction
     0x04b0: 20 [06 10]  |   Undefined instruction
     0x04b1: 06 [10 C3]  |   MVI B, 0x10
     0x04b2: 10 [C3 32]  |   Undefined instruction
     0x04b3: C3 [32 1A]  |   JMP 0x1A32
     0x04b4: 32 [1A E1]  |   STA 0xE11A
     0x04b5: 1A [E1 3A]  |   LDAX D
     0x04b6: E1 [3A 6E]  |   POP H
     0x04b7: 3A [6E 20]  |   LDA 0x206E
     0x04b8: 6E [20 A7]  |   MOV L, M
     0x04b9: 20 [A7 C0]  |   Undefined instruction
     0x04ba: A7 [C0 3A]  |   ANA A
     0x04bb: C0 [3A 80]  |   RNZ
     0x04bc: 3A [80 20]  |   LDA 0x2080
     0x04bd: 80 [20 FE]  |   ADD B
     0x04be: 20 [FE 01]  |   Undefined instruction
     0x04bf: FE [01 C0]  |   CPI 0x01
     0x04c0: 01 [C0 11]  |   LXI B, 0x11C0 
     0x04c1: C0 [11 45]  |   RNZ
     0x04c2: 11 [45 20]  |   LXI D, 0x2045 
     0x04c3: 45 [20 3E]  |   MOV B, L
     0x04c4: 20 [3E ED]  |   Undefined instruction
     0x04c5: 3E [ED CD]  |   MVI A, 0xED
     0x04c6: ED [CD 50]  |   Undefined instruction
     0x04c7: CD [50 05]  |   CAL 0x0550
     0x04c8: 50 [05 3A]  |   MOV D, B
     0x04c9: 05 [3A 36]  |   DCR B
     0x04ca: 3A [36 20]  |   LDA 0x2036
     0x04cb: 36 [20 32]  |   MVI M, 0x20
     0x04cc: 20 [32 70]  |   Undefined instruction
     0x04cd: 32 [70 20]  |   STA 0x2070
     0x04ce: 70 [20 3A]  |   MOV M, B
     0x04cf: 20 [3A 56]  |   Undefined instruction
     0x04d0: 3A [56 20]  |   LDA 0x2056
     0x04d1: 56 [20 32]  |   MOV D, M
     0x04d2: 20 [32 71]  |   Undefined instruction
     0x04d3: 32 [71 20]  |   STA 0x2071
     0x04d4: 71 [20 CD]  |   MOV M, C
     0x04d5: 20 [CD 63]  |   Undefined instruction
     0x04d6: CD [63 05]  |   CAL 0x0563
     0x04d7: 63 [05 3A]  |   MOV H, E
     0x04d8: 05 [3A 76]  |   DCR B
     0x04d9: 3A [76 20]  |   LDA 0x2076
     0x04da: 76 [20 FE]  |   HLT
     0x04db: 20 [FE 10]  |   Undefined instruction
     0x04dc: FE [10 DA]  |   CPI 0x10
     0x04dd: 10 [DA E7]  |   Undefined instruction
     0x04de: DA [E7 04]  |   JC 0x04E7
     0x04df: E7 [04 3A]  |   RST 4
     0x04e0: 04 [3A 48]  |   INR B
     0x04e1: 3A [48 1B]  |   LDA 0x1B48
     0x04e2: 48 [1B 32]  |   MOV C, B
     0x04e3: 1B [32 76]  |   DCX D
     0x04e4: 32 [76 20]  |   STA 0x2076
     0x04e5: 76 [20 3A]  |   HLT
     0x04e6: 20 [3A 78]  |   Undefined instruction
     0x04e7: 3A [78 20]  |   LDA 0x2078
     0x04e8: 78 [20 A7]  |   MOV A, B
     0x04e9: 20 [A7 21]  |   Undefined instruction
     0x04ea: A7 [21 45]  |   ANA A
     0x04eb: 21 [45 20]  |   LXI H, 0x2045 
     0x04ec: 45 [20 C2]  |   MOV B, L
     0x04ed: 20 [C2 5B]  |   Undefined instruction
     0x04ee: C2 [5B 05]  |   JNZ 0x055B
     0x04ef: 5B [05 11]  |   MOV E, E
     0x04f0: 05 [11 40]  |   DCR B
     0x04f1: 11 [40 1B]  |   LXI D, 0x1B40 
     0x04f2: 40 [1B 21]  |   MOV B, B
     0x04f3: 1B [21 40]  |   DCX D
     0x04f4: 21 [40 20]  |   LXI H, 0x2040 
     0x04f5: 40 [20 06]  |   MOV B, B
     0x04f6: 20 [06 10]  |   Undefined instruction
     0x04f7: 06 [10 CD]  |   MVI B, 0x10
     0x04f8: 10 [CD 32]  |   Undefined instruction
     0x04f9: CD [32 1A]  |   CAL 0x1A32
     0x04fa: 32 [1A 3A]  |   STA 0x3A1A
     0x04fb: 1A [3A 82]  |   LDAX D
     0x04fc: 3A [82 20]  |   LDA 0x2082
     0x04fd: 82 [20 3D]  |   ADD D
     0x04fe: 20 [3D C2]  |   Undefined instruction
     0x04ff: 3D [C2 08]  |   DCR A
     0x0500: C2 [08 05]  |   JNZ 0x0508
     0x0501: 08 [05 3E]  |   Undefined instruction
     0x0502: 05 [3E 01]  |   DCR B
     0x0503: 3E [01 32]  |   MVI A, 0x01
     0x0504: 01 [32 6E]  |   LXI B, 0x6E32 
     0x0505: 32 [6E 20]  |   STA 0x206E
     0x0506: 6E [20 2A]  |   MOV L, M
     0x0507: 20 [2A 76]  |   Undefined instruction
     0x0508: 2A [76 20]  |   LHLD 0x2076
     0x0509: 76 [20 C3]  |   HLT
     0x050a: 20 [C3 7E]  |   Undefined instruction
     0x050b: C3 [7E 06]  |   JMP 0x067E
     0x050c: 7E [06 E1]  |   MOV A, M
     0x050d: 06 [E1 11]  |   MVI B, 0xE1
     0x050e: E1 [11 55]  |   POP H
     0x050f: 11 [55 20]  |   LXI D, 0x2055 
     0x0510: 55 [20 3E]  |   MOV D, L
     0x0511: 20 [3E DB]  |   Undefined instruction
     0x0512: 3E [DB CD]  |   MVI A, 0xDB
     0x0513: DB [CD 50]  |   IN 0xCD
     0x0514: CD [50 05]  |   CAL 0x0550
     0x0515: 50 [05 3A]  |   MOV D, B
     0x0516: 05 [3A 46]  |   DCR B
     0x0517: 3A [46 20]  |   LDA 0x2046
     0x0518: 46 [20 32]  |   MOV B, M
     0x0519: 20 [32 70]  |   Undefined instruction
     0x051a: 32 [70 20]  |   STA 0x2070
     0x051b: 70 [20 3A]  |   MOV M, B
     0x051c: 20 [3A 36]  |   Undefined instruction
     0x051d: 3A [36 20]  |   LDA 0x2036
     0x051e: 36 [20 32]  |   MVI M, 0x20
     0x051f: 20 [32 71]  |   Undefined instruction
     0x0520: 32 [71 20]  |   STA 0x2071
     0x0521: 71 [20 CD]  |   MOV M, C
     0x0522: 20 [CD 63]  |   Undefined instruction
     0x0523: CD [63 05]  |   CAL 0x0563
     0x0524: 63 [05 3A]  |   MOV H, E
     0x0525: 05 [3A 76]  |   DCR B
     0x0526: 3A [76 20]  |   LDA 0x2076
     0x0527: 76 [20 FE]  |   HLT
     0x0528: 20 [FE 15]  |   Undefined instruction
     0x0529: FE [15 DA]  |   CPI 0x15
     0x052a: 15 [DA 34]  |   DCR D
     0x052b: DA [34 05]  |   JC 0x0534
     0x052c: 34 [05 3A]  |   INR M
     0x052d: 05 [3A 58]  |   DCR B
     0x052e: 3A [58 1B]  |   LDA 0x1B58
     0x052f: 58 [1B 32]  |   MOV E, B
     0x0530: 1B [32 76]  |   DCX D
     0x0531: 32 [76 20]  |   STA 0x2076
     0x0532: 76 [20 3A]  |   HLT
     0x0533: 20 [3A 78]  |   Undefined instruction
     0x0534: 3A [78 20]  |   LDA 0x2078
     0x0535: 78 [20 A7]  |   MOV A, B
     0x0536: 20 [A7 21]  |   Undefined instruction
     0x0537: A7 [21 55]  |   ANA A
     0x0538: 21 [55 20]  |   LXI H, 0x2055 
     0x0539: 55 [20 C2]  |   MOV D, L
     0x053a: 20 [C2 5B]  |   Undefined instruction
     0x053b: C2 [5B 05]  |   JNZ 0x055B
     0x053c: 5B [05 11]  |   MOV E, E
     0x053d: 05 [11 50]  |   DCR B
     0x053e: 11 [50 1B]  |   LXI D, 0x1B50 
     0x053f: 50 [1B 21]  |   MOV D, B
     0x0540: 1B [21 50]  |   DCX D
     0x0541: 21 [50 20]  |   LXI H, 0x2050 
     0x0542: 50 [20 06]  |   MOV D, B
     0x0543: 20 [06 10]  |   Undefined instruction
     0x0544: 06 [10 CD]  |   MVI B, 0x10
     0x0545: 10 [CD 32]  |   Undefined instruction
     0x0546: CD [32 1A]  |   CAL 0x1A32
     0x0547: 32 [1A 2A]  |   STA 0x2A1A
     0x0548: 1A [2A 76]  |   LDAX D
     0x0549: 2A [76 20]  |   LHLD 0x2076
     0x054a: 76 [20 22]  |   HLT
     0x054b: 20 [22 58]  |   Undefined instruction
     0x054c: 22 [58 20]  |   SHLD 0x2058
     0x054d: 58 [20 C9]  |   MOV E, B
     0x054e: 20 [C9 32]  |   Undefined instruction
     0x054f: C9 [32 7F]  |   RET
     0x0550: 32 [7F 20]  |   STA 0x207F
     0x0551: 7F [20 21]  |   MOV A, A
     0x0552: 20 [21 73]  |   Undefined instruction
     0x0553: 21 [73 20]  |   LXI H, 0x2073 
     0x0554: 73 [20 06]  |   MOV M, E
     0x0555: 20 [06 0B]  |   Undefined instruction
     0x0556: 06 [0B C3]  |   MVI B, 0x0B
     0x0557: 0B [C3 32]  |   DCX B
     0x0558: C3 [32 1A]  |   JMP 0x1A32
     0x0559: 32 [1A 11]  |   STA 0x111A
     0x055a: 1A [11 73]  |   LDAX D
     0x055b: 11 [73 20]  |   LXI D, 0x2073 
     0x055c: 73 [20 06]  |   MOV M, E
     0x055d: 20 [06 0B]  |   Undefined instruction
     0x055e: 06 [0B C3]  |   MVI B, 0x0B
     0x055f: 0B [C3 32]  |   DCX B
     0x0560: C3 [32 1A]  |   JMP 0x1A32
     0x0561: 32 [1A 21]  |   STA 0x211A
     0x0562: 1A [21 73]  |   LDAX D
     0x0563: 21 [73 20]  |   LXI H, 0x2073 
     0x0564: 73 [20 7E]  |   MOV M, E
     0x0565: 20 [7E E6]  |   Undefined instruction
     0x0566: 7E [E6 80]  |   MOV A, M
     0x0567: E6 [80 C2]  |   ANI 0x80
     0x0568: 80 [C2 C1]  |   ADD B
     0x0569: C2 [C1 05]  |   JNZ 0x05C1
     0x056a: C1 [05 3A]  |   POP B
     0x056b: 05 [3A C1]  |   DCR B
     0x056c: 3A [C1 20]  |   LDA 0x20C1
     0x056d: C1 [20 FE]  |   POP B
     0x056e: 20 [FE 04]  |   Undefined instruction
     0x056f: FE [04 3A]  |   CPI 0x04
     0x0570: 04 [3A 69]  |   INR B
     0x0571: 3A [69 20]  |   LDA 0x2069
     0x0572: 69 [20 CA]  |   MOV L, C
     0x0573: 20 [CA B7]  |   Undefined instruction
     0x0574: CA [B7 05]  |   JZ 0x05B7
     0x0575: B7 [05 A7]  |   ORA A
     0x0576: 05 [A7 C8]  |   DCR B
     0x0577: A7 [C8 23]  |   ANA A
     0x0578: C8 [23 36]  |   RZ
     0x0579: 23 [36 00]  |   INX H
     0x057a: 36 [00 3A]  |   MVI M, 0x00
     0x057b: 00 [3A 70]  |   NOP
     0x057c: 3A [70 20]  |   LDA 0x2070
     0x057d: 70 [20 A7]  |   MOV M, B
     0x057e: 20 [A7 CA]  |   Undefined instruction
     0x057f: A7 [CA 89]  |   ANA A
     0x0580: CA [89 05]  |   JZ 0x0589
     0x0581: 89 [05 47]  |   ADC C
     0x0582: 05 [47 3A]  |   DCR B
     0x0583: 47 [3A CF]  |   MOV B, A
     0x0584: 3A [CF 20]  |   LDA 0x20CF
     0x0585: CF [20 B8]  |   RST 1
     0x0586: 20 [B8 D0]  |   Undefined instruction
     0x0587: B8 [D0 3A]  |   CMP B
     0x0588: D0 [3A 71]  |   RNC
     0x0589: 3A [71 20]  |   LDA 0x2071
     0x058a: 71 [20 A7]  |   MOV M, C
     0x058b: 20 [A7 CA]  |   Undefined instruction
     0x058c: A7 [CA 96]  |   ANA A
     0x058d: CA [96 05]  |   JZ 0x0596
     0x058e: 96 [05 47]  |   SUB M
     0x058f: 05 [47 3A]  |   DCR B
     0x0590: 47 [3A CF]  |   MOV B, A
     0x0591: 3A [CF 20]  |   LDA 0x20CF
     0x0592: CF [20 B8]  |   RST 1
     0x0593: 20 [B8 D0]  |   Undefined instruction
     0x0594: B8 [D0 23]  |   CMP B
     0x0595: D0 [23 7E]  |   RNC
     0x0596: 23 [7E A7]  |   INX H
     0x0597: 7E [A7 CA]  |   MOV A, M
     0x0598: A7 [CA 1B]  |   ANA A
     0x0599: CA [1B 06]  |   JZ 0x061B
     0x059a: 1B [06 2A]  |   DCX D
     0x059b: 06 [2A 76]  |   MVI B, 0x2A
     0x059c: 2A [76 20]  |   LHLD 0x2076
     0x059d: 76 [20 4E]  |   HLT
     0x059e: 20 [4E 23]  |   Undefined instruction
     0x059f: 4E [23 00]  |   MOV C, M
     0x05a0: 23 [00 22]  |   INX H
     0x05a1: 00 [22 76]  |   NOP
     0x05a2: 22 [76 20]  |   SHLD 0x2076
     0x05a3: 76 [20 CD]  |   HLT
     0x05a4: 20 [CD 2F]  |   Undefined instruction
     0x05a5: CD [2F 06]  |   CAL 0x062F
     0x05a6: 2F [06 D0]  |   CMA
     0x05a7: 06 [D0 CD]  |   MVI B, 0xD0
     0x05a8: D0 [CD 7A]  |   RNC
     0x05a9: CD [7A 01]  |   CAL 0x017A
     0x05aa: 7A [01 79]  |   MOV A, D
     0x05ab: 01 [79 C6]  |   LXI B, 0xC679 
     0x05ac: 79 [C6 07]  |   MOV A, C
     0x05ad: C6 [07 67]  |   ADI 0x07
     0x05ae: 07 [67 7D]  |   RLC
     0x05af: 67 [7D D6]  |   MOV H, A
     0x05b0: 7D [D6 0A]  |   MOV A, L
     0x05b1: D6 [0A 6F]  |   SUI 0x0A
     0x05b2: 0A [6F 22]  |   LDAX B
     0x05b3: 6F [22 7B]  |   MOV L, A
     0x05b4: 22 [7B 20]  |   SHLD 0x207B
     0x05b5: 7B [20 21]  |   MOV A, E
     0x05b6: 20 [21 73]  |   Undefined instruction
     0x05b7: 21 [73 20]  |   LXI H, 0x2073 
     0x05b8: 73 [20 7E]  |   MOV M, E
     0x05b9: 20 [7E F6]  |   Undefined instruction
     0x05ba: 7E [F6 80]  |   MOV A, M
     0x05bb: F6 [80 77]  |   ORI 0x80
     0x05bc: 80 [77 23]  |   ADD B
     0x05bd: 77 [23 34]  |   MOV M, A
     0x05be: 23 [34 C9]  |   INX H
     0x05bf: 34 [C9 11]  |   INR M
     0x05c0: C9 [11 7C]  |   RET
     0x05c1: 11 [7C 20]  |   LXI D, 0x207C 
     0x05c2: 7C [20 CD]  |   MOV A, H
     0x05c3: 20 [CD 06]  |   Undefined instruction
     0x05c4: CD [06 1A]  |   CAL 0x1A06
     0x05c5: 06 [1A D0]  |   MVI B, 0x1A
     0x05c6: 1A [D0 23]  |   LDAX D
     0x05c7: D0 [23 7E]  |   RNC
     0x05c8: 23 [7E E6]  |   INX H
     0x05c9: 7E [E6 01]  |   MOV A, M
     0x05ca: E6 [01 C2]  |   ANI 0x01
     0x05cb: 01 [C2 44]  |   LXI B, 0x44C2 
     0x05cc: C2 [44 06]  |   JNZ 0x0644
     0x05cd: 44 [06 23]  |   MOV B, H
     0x05ce: 06 [23 34]  |   MVI B, 0x23
     0x05cf: 23 [34 CD]  |   INX H
     0x05d0: 34 [CD 75]  |   INR M
     0x05d1: CD [75 06]  |   CAL 0x0675
     0x05d2: 75 [06 3A]  |   MOV M, L
     0x05d3: 06 [3A 79]  |   MVI B, 0x3A
     0x05d4: 3A [79 20]  |   LDA 0x2079
     0x05d5: 79 [20 C6]  |   MOV A, C
     0x05d6: 20 [C6 03]  |   Undefined instruction
     0x05d7: C6 [03 21]  |   ADI 0x03
     0x05d8: 03 [21 7F]  |   INX B
     0x05d9: 21 [7F 20]  |   LXI H, 0x207F 
     0x05da: 7F [20 BE]  |   MOV A, A
     0x05db: 20 [BE DA]  |   Undefined instruction
     0x05dc: BE [DA E2]  |   CMP M
     0x05dd: DA [E2 05]  |   JC 0x05E2
     0x05de: E2 [05 D6]  |   JPO 0xD605
     0x05df: 05 [D6 0C]  |   DCR B
     0x05e0: D6 [0C 32]  |   SUI 0x0C
     0x05e1: 0C [32 79]  |   INR C
     0x05e2: 32 [79 20]  |   STA 0x2079
     0x05e3: 79 [20 3A]  |   MOV A, C
     0x05e4: 20 [3A 7B]  |   Undefined instruction
     0x05e5: 3A [7B 20]  |   LDA 0x207B
     0x05e6: 7B [20 47]  |   MOV A, E
     0x05e7: 20 [47 3A]  |   Undefined instruction
     0x05e8: 47 [3A 7E]  |   MOV B, A
     0x05e9: 3A [7E 20]  |   LDA 0x207E
     0x05ea: 7E [20 80]  |   MOV A, M
     0x05eb: 20 [80 32]  |   Undefined instruction
     0x05ec: 80 [32 7B]  |   ADD B
     0x05ed: 32 [7B 20]  |   STA 0x207B
     0x05ee: 7B [20 CD]  |   MOV A, E
     0x05ef: 20 [CD 6C]  |   Undefined instruction
     0x05f0: CD [6C 06]  |   CAL 0x066C
     0x05f1: 6C [06 3A]  |   MOV L, H
     0x05f2: 06 [3A 7B]  |   MVI B, 0x3A
     0x05f3: 3A [7B 20]  |   LDA 0x207B
     0x05f4: 7B [20 FE]  |   MOV A, E
     0x05f5: 20 [FE 15]  |   Undefined instruction
     0x05f6: FE [15 DA]  |   CPI 0x15
     0x05f7: 15 [DA 12]  |   DCR D
     0x05f8: DA [12 06]  |   JC 0x0612
     0x05f9: 12 [06 3A]  |   STAX D
     0x05fa: 06 [3A 61]  |   MVI B, 0x3A
     0x05fb: 3A [61 20]  |   LDA 0x2061
     0x05fc: 61 [20 A7]  |   MOV H, C
     0x05fd: 20 [A7 C8]  |   Undefined instruction
     0x05fe: A7 [C8 3A]  |   ANA A
     0x05ff: C8 [3A 7B]  |   RZ
     0x0600: 3A [7B 20]  |   LDA 0x207B
     0x0601: 7B [20 FE]  |   MOV A, E
     0x0602: 20 [FE 1E]  |   Undefined instruction
     0x0603: FE [1E DA]  |   CPI 0x1E
     0x0604: 1E [DA 12]  |   MVI E, 0xDA
     0x0605: DA [12 06]  |   JC 0x0612
     0x0606: 12 [06 FE]  |   STAX D
     0x0607: 06 [FE 27]  |   MVI B, 0xFE
     0x0608: FE [27 00]  |   CPI 0x27
     0x0609: 27 [00 D2]  |   DAA
     0x060a: 00 [D2 12]  |   NOP
     0x060b: D2 [12 06]  |   JNC 0x0612
     0x060c: 12 [06 97]  |   STAX D
     0x060d: 06 [97 32]  |   MVI B, 0x97
     0x060e: 97 [32 15]  |   SUB A
     0x060f: 32 [15 20]  |   STA 0x2015
     0x0610: 15 [20 3A]  |   DCR D
     0x0611: 20 [3A 73]  |   Undefined instruction
     0x0612: 3A [73 20]  |   LDA 0x2073
     0x0613: 73 [20 F6]  |   MOV M, E
     0x0614: 20 [F6 01]  |   Undefined instruction
     0x0615: F6 [01 32]  |   ORI 0x01
     0x0616: 01 [32 73]  |   LXI B, 0x7332 
     0x0617: 32 [73 20]  |   STA 0x2073
     0x0618: 73 [20 C9]  |   MOV M, E
     0x0619: 20 [C9 3A]  |   Undefined instruction
     0x061a: C9 [3A 1B]  |   RET
     0x061b: 3A [1B 20]  |   LDA 0x201B
     0x061c: 1B [20 C6]  |   DCX D
     0x061d: 20 [C6 08]  |   Undefined instruction
     0x061e: C6 [08 67]  |   ADI 0x08
     0x061f: 08 [67 CD]  |   Undefined instruction
     0x0620: 67 [CD 6F]  |   MOV H, A
     0x0621: CD [6F 15]  |   CAL 0x156F
     0x0622: 6F [15 79]  |   MOV L, A
     0x0623: 15 [79 FE]  |   DCR D
     0x0624: 79 [FE 0C]  |   MOV A, C
     0x0625: FE [0C DA]  |   CPI 0x0C
     0x0626: 0C [DA A5]  |   INR C
     0x0627: DA [A5 05]  |   JC 0x05A5
     0x0628: A5 [05 0E]  |   ANA L
     0x0629: 05 [0E 0B]  |   DCR B
     0x062a: 0E [0B C3]  |   MVI C, 0x0B
     0x062b: 0B [C3 A5]  |   DCX B
     0x062c: C3 [A5 05]  |   JMP 0x05A5
     0x062d: A5 [05 0D]  |   ANA L
     0x062e: 05 [0D 3A]  |   DCR B
     0x062f: 0D [3A 67]  |   DCR C
     0x0630: 3A [67 20]  |   LDA 0x2067
     0x0631: 67 [20 67]  |   MOV H, A
     0x0632: 20 [67 69]  |   Undefined instruction
     0x0633: 67 [69 16]  |   MOV H, A
     0x0634: 69 [16 05]  |   MOV L, C
     0x0635: 16 [05 7E]  |   MVI D, 0x05
     0x0636: 05 [7E A7]  |   DCR B
     0x0637: 7E [A7 37]  |   MOV A, M
     0x0638: A7 [37 C0]  |   ANA A
     0x0639: 37 [C0 7D]  |   STC
     0x063a: C0 [7D C6]  |   RNZ
     0x063b: 7D [C6 0B]  |   MOV A, L
     0x063c: C6 [0B 6F]  |   ADI 0x0B
     0x063d: 0B [6F 15]  |   DCX B
     0x063e: 6F [15 C2]  |   MOV L, A
     0x063f: 15 [C2 37]  |   DCR D
     0x0640: C2 [37 06]  |   JNZ 0x0637
     0x0641: 37 [06 C9]  |   STC
     0x0642: 06 [C9 21]  |   MVI B, 0xC9
     0x0643: C9 [21 78]  |   RET
     0x0644: 21 [78 20]  |   LXI H, 0x2078 
     0x0645: 78 [20 35]  |   MOV A, B
     0x0646: 20 [35 7E]  |   Undefined instruction
     0x0647: 35 [7E FE]  |   DCR M
     0x0648: 7E [FE 03]  |   MOV A, M
     0x0649: FE [03 C2]  |   CPI 0x03
     0x064a: 03 [C2 67]  |   INX B
     0x064b: C2 [67 06]  |   JNZ 0x0667
     0x064c: 67 [06 CD]  |   MOV H, A
     0x064d: 06 [CD 75]  |   MVI B, 0xCD
     0x064e: CD [75 06]  |   CAL 0x0675
     0x064f: 75 [06 21]  |   MOV M, L
     0x0650: 06 [21 DC]  |   MVI B, 0x21
     0x0651: 21 [DC 1C]  |   LXI H, 0x1CDC 
     0x0652: DC [1C 22]  |   CC 0x221C
     0x0653: 1C [22 79]  |   INR E
     0x0654: 22 [79 20]  |   SHLD 0x2079
     0x0655: 79 [20 21]  |   MOV A, C
     0x0656: 20 [21 7C]  |   Undefined instruction
     0x0657: 21 [7C 20]  |   LXI H, 0x207C 
     0x0658: 7C [20 35]  |   MOV A, H
     0x0659: 20 [35 35]  |   Undefined instruction
     0x065a: 35 [35 2B]  |   DCR M
     0x065b: 35 [2B 35]  |   DCR M
     0x065c: 2B [35 35]  |   DCX H
     0x065d: 35 [35 3E]  |   DCR M
     0x065e: 35 [3E 06]  |   DCR M
     0x065f: 3E [06 32]  |   MVI A, 0x06
     0x0660: 06 [32 7D]  |   MVI B, 0x32
     0x0661: 32 [7D 20]  |   STA 0x207D
     0x0662: 7D [20 C3]  |   MOV A, L
     0x0663: 20 [C3 6C]  |   Undefined instruction
     0x0664: C3 [6C 06]  |   JMP 0x066C
     0x0665: 6C [06 A7]  |   MOV L, H
     0x0666: 06 [A7 C0]  |   MVI B, 0xA7
     0x0667: A7 [C0 C3]  |   ANA A
     0x0668: C0 [C3 75]  |   RNZ
     0x0669: C3 [75 06]  |   JMP 0x0675
     0x066a: 75 [06 21]  |   MOV M, L
     0x066b: 06 [21 79]  |   MVI B, 0x21
     0x066c: 21 [79 20]  |   LXI H, 0x2079 
     0x066d: 79 [20 CD]  |   MOV A, C
     0x066e: 20 [CD 3B]  |   Undefined instruction
     0x066f: CD [3B 1A]  |   CAL 0x1A3B
     0x0670: 3B [1A C3]  |   DCX SP
     0x0671: 1A [C3 91]  |   LDAX D
     0x0672: C3 [91 14]  |   JMP 0x1491
     0x0673: 91 [14 21]  |   SUB C
     0x0674: 14 [21 79]  |   INR D
     0x0675: 21 [79 20]  |   LXI H, 0x2079 
     0x0676: 79 [20 CD]  |   MOV A, C
     0x0677: 20 [CD 3B]  |   Undefined instruction
     0x0678: CD [3B 1A]  |   CAL 0x1A3B
     0x0679: 3B [1A C3]  |   DCX SP
     0x067a: 1A [C3 52]  |   LDAX D
     0x067b: C3 [52 14]  |   JMP 0x1452
     0x067c: 52 [14 22]  |   MOV D, D
     0x067d: 14 [22 48]  |   INR D
     0x067e: 22 [48 20]  |   SHLD 0x2048
     0x067f: 48 [20 C9]  |   MOV C, B
     0x0680: 20 [C9 E1]  |   Undefined instruction
     0x0681: C9 [E1 3A]  |   RET
     0x0682: E1 [3A 80]  |   POP H
     0x0683: 3A [80 20]  |   LDA 0x2080
     0x0684: 80 [20 FE]  |   ADD B
     0x0685: 20 [FE 02]  |   Undefined instruction
     0x0686: FE [02 C0]  |   CPI 0x02
     0x0687: 02 [C0 21]  |   STAX B
     0x0688: C0 [21 83]  |   RNZ
     0x0689: 21 [83 20]  |   LXI H, 0x2083 
     0x068a: 83 [20 7E]  |   ADD E
     0x068b: 20 [7E A7]  |   Undefined instruction
     0x068c: 7E [A7 CA]  |   MOV A, M
     0x068d: A7 [CA 0F]  |   ANA A
     0x068e: CA [0F 05]  |   JZ 0x050F
     0x068f: 0F [05 3A]  |   RRC
     0x0690: 05 [3A 56]  |   DCR B
     0x0691: 3A [56 20]  |   LDA 0x2056
     0x0692: 56 [20 A7]  |   MOV D, M
     0x0693: 20 [A7 C2]  |   Undefined instruction
     0x0694: A7 [C2 0F]  |   ANA A
     0x0695: C2 [0F 05]  |   JNZ 0x050F
     0x0696: 0F [05 23]  |   RRC
     0x0697: 05 [23 7E]  |   DCR B
     0x0698: 23 [7E A7]  |   INX H
     0x0699: 7E [A7 C2]  |   MOV A, M
     0x069a: A7 [C2 AB]  |   ANA A
     0x069b: C2 [AB 06]  |   JNZ 0x06AB
     0x069c: AB [06 3A]  |   XRA E
     0x069d: 06 [3A 82]  |   MVI B, 0x3A
     0x069e: 3A [82 20]  |   LDA 0x2082
     0x069f: 82 [20 FE]  |   ADD D
     0x06a0: 20 [FE 08]  |   Undefined instruction
     0x06a1: FE [08 DA]  |   CPI 0x08
     0x06a2: 08 [DA 0F]  |   Undefined instruction
     0x06a3: DA [0F 05]  |   JC 0x050F
     0x06a4: 0F [05 36]  |   RRC
     0x06a5: 05 [36 01]  |   DCR B
     0x06a6: 36 [01 CD]  |   MVI M, 0x01
     0x06a7: 01 [CD 3C]  |   LXI B, 0x3CCD 
     0x06a8: CD [3C 07]  |   CAL 0x073C
     0x06a9: 3C [07 11]  |   INR A
     0x06aa: 07 [11 8A]  |   RLC
     0x06ab: 11 [8A 20]  |   LXI D, 0x208A 
     0x06ac: 8A [20 CD]  |   ADC D
     0x06ad: 20 [CD 06]  |   Undefined instruction
     0x06ae: CD [06 1A]  |   CAL 0x1A06
     0x06af: 06 [1A D0]  |   MVI B, 0x1A
     0x06b0: 1A [D0 21]  |   LDAX D
     0x06b1: D0 [21 85]  |   RNC
     0x06b2: 21 [85 20]  |   LXI H, 0x2085 
     0x06b3: 85 [20 7E]  |   ADD L
     0x06b4: 20 [7E A7]  |   Undefined instruction
     0x06b5: 7E [A7 C2]  |   MOV A, M
     0x06b6: A7 [C2 D6]  |   ANA A
     0x06b7: C2 [D6 06]  |   JNZ 0x06D6
     0x06b8: D6 [06 21]  |   SUI 0x06
     0x06b9: 06 [21 8A]  |   MVI B, 0x21
     0x06ba: 21 [8A 20]  |   LXI H, 0x208A 
     0x06bb: 8A [20 7E]  |   ADC D
     0x06bc: 20 [7E 23]  |   Undefined instruction
     0x06bd: 7E [23 23]  |   MOV A, M
     0x06be: 23 [23 86]  |   INX H
     0x06bf: 23 [86 32]  |   INX H
     0x06c0: 86 [32 8A]  |   ADD M
     0x06c1: 32 [8A 20]  |   STA 0x208A
     0x06c2: 8A [20 CD]  |   ADC D
     0x06c3: 20 [CD 3C]  |   Undefined instruction
     0x06c4: CD [3C 07]  |   CAL 0x073C
     0x06c5: 3C [07 21]  |   INR A
     0x06c6: 07 [21 8A]  |   RLC
     0x06c7: 21 [8A 20]  |   LXI H, 0x208A 
     0x06c8: 8A [20 7E]  |   ADC D
     0x06c9: 20 [7E FE]  |   Undefined instruction
     0x06ca: 7E [FE 28]  |   MOV A, M
     0x06cb: FE [28 DA]  |   CPI 0x28
     0x06cc: 28 [DA F9]  |   Undefined instruction
     0x06cd: DA [F9 06]  |   JC 0x06F9
     0x06ce: F9 [06 FE]  |   SPHL
     0x06cf: 06 [FE E1]  |   MVI B, 0xFE
     0x06d0: FE [E1 D2]  |   CPI 0xE1
     0x06d1: E1 [D2 F9]  |   POP H
     0x06d2: D2 [F9 06]  |   JNC 0x06F9
     0x06d3: F9 [06 C9]  |   SPHL
     0x06d4: 06 [C9 06]  |   MVI B, 0xC9
     0x06d5: C9 [06 FE]  |   RET
     0x06d6: 06 [FE CD]  |   MVI B, 0xFE
     0x06d7: FE [CD DC]  |   CPI 0xCD
     0x06d8: CD [DC 19]  |   CAL 0x19DC
     0x06d9: DC [19 23]  |   CC 0x2319
     0x06da: 19 [23 35]  |   DAD D
     0x06db: 23 [35 7E]  |   INX H
     0x06dc: 35 [7E FE]  |   DCR M
     0x06dd: 7E [FE 1F]  |   MOV A, M
     0x06de: FE [1F CA]  |   CPI 0x1F
     0x06df: 1F [CA 4B]  |   RAR
     0x06e0: CA [4B 07]  |   JZ 0x074B
     0x06e1: 4B [07 FE]  |   MOV C, E
     0x06e2: 07 [FE 18]  |   RLC
     0x06e3: FE [18 CA]  |   CPI 0x18
     0x06e4: 18 [CA 0C]  |   Undefined instruction
     0x06e5: CA [0C 07]  |   JZ 0x070C
     0x06e6: 0C [07 A7]  |   INR C
     0x06e7: 07 [A7 C0]  |   RLC
     0x06e8: A7 [C0 06]  |   ANA A
     0x06e9: C0 [06 EF]  |   RNZ
     0x06ea: 06 [EF 21]  |   MVI B, 0xEF
     0x06eb: EF [21 98]  |   RST 5
     0x06ec: 21 [98 20]  |   LXI H, 0x2098 
     0x06ed: 98 [20 7E]  |   SBB B
     0x06ee: 20 [7E A0]  |   Undefined instruction
     0x06ef: 7E [A0 77]  |   MOV A, M
     0x06f0: A0 [77 E6]  |   ANA B
     0x06f1: 77 [E6 20]  |   MOV M, A
     0x06f2: E6 [20 D3]  |   ANI 0x20
     0x06f3: 20 [D3 05]  |   Undefined instruction
     0x06f4: D3 [05 00]  |   OUT 0x05
     0x06f5: 05 [00 00]  |   DCR B
     0x06f6: 00 [00 00]  |   NOP
     0x06f7: 00 [00 CD]  |   NOP
     0x06f8: 00 [CD 42]  |   NOP
     0x06f9: CD [42 07]  |   CAL 0x0742
     0x06fa: 42 [07 CD]  |   MOV B, D
     0x06fb: 07 [CD CB]  |   RLC
     0x06fc: CD [CB 14]  |   CAL 0x14CB
     0x06fd: CB [14 21]  |   Undefined instruction
     0x06fe: 14 [21 83]  |   INR D
     0x06ff: 21 [83 20]  |   LXI H, 0x2083 
     0x0700: 83 [20 06]  |   ADD E
     0x0701: 20 [06 0A]  |   Undefined instruction
     0x0702: 06 [0A CD]  |   MVI B, 0x0A
     0x0703: 0A [CD 5F]  |   LDAX B
     0x0704: CD [5F 07]  |   CAL 0x075F
     0x0705: 5F [07 06]  |   MOV E, A
     0x0706: 07 [06 FE]  |   RLC
     0x0707: 06 [FE C3]  |   MVI B, 0xFE
     0x0708: FE [C3 DC]  |   CPI 0xC3
     0x0709: C3 [DC 19]  |   JMP 0x19DC
     0x070a: DC [19 3E]  |   CC 0x3E19
     0x070b: 19 [3E 01]  |   DAD D
     0x070c: 3E [01 32]  |   MVI A, 0x01
     0x070d: 01 [32 F1]  |   LXI B, 0xF132 
     0x070e: 32 [F1 20]  |   STA 0x20F1
     0x070f: F1 [20 2A]  |   POP PSW
     0x0710: 20 [2A 8D]  |   Undefined instruction
     0x0711: 2A [8D 20]  |   LHLD 0x208D
     0x0712: 8D [20 46]  |   ADC L
     0x0713: 20 [46 0E]  |   Undefined instruction
     0x0714: 46 [0E 04]  |   MOV B, M
     0x0715: 0E [04 21]  |   MVI C, 0x04
     0x0716: 04 [21 50]  |   INR B
     0x0717: 21 [50 1D]  |   LXI H, 0x1D50 
     0x0718: 50 [1D 11]  |   MOV D, B
     0x0719: 1D [11 4C]  |   DCR E
     0x071a: 11 [4C 1D]  |   LXI D, 0x1D4C 
     0x071b: 4C [1D 1A]  |   MOV C, H
     0x071c: 1D [1A B8]  |   DCR E
     0x071d: 1A [B8 CA]  |   LDAX D
     0x071e: B8 [CA 28]  |   CMP B
     0x071f: CA [28 07]  |   JZ 0x0728
     0x0720: 28 [07 23]  |   Undefined instruction
     0x0721: 07 [23 13]  |   RLC
     0x0722: 23 [13 0D]  |   INX H
     0x0723: 13 [0D C2]  |   INX D
     0x0724: 0D [C2 1D]  |   DCR C
     0x0725: C2 [1D 07]  |   JNZ 0x071D
     0x0726: 1D [07 7E]  |   DCR E
     0x0727: 07 [7E 32]  |   RLC
     0x0728: 7E [32 87]  |   MOV A, M
     0x0729: 32 [87 20]  |   STA 0x2087
     0x072a: 87 [20 26]  |   ADD A
     0x072b: 20 [26 00]  |   Undefined instruction
     0x072c: 26 [00 68]  |   MVI H, 0x00
     0x072d: 00 [68 29]  |   NOP
     0x072e: 68 [29 29]  |   MOV L, B
     0x072f: 29 [29 29]  |   DAD H
     0x0730: 29 [29 29]  |   DAD H
     0x0731: 29 [29 22]  |   DAD H
     0x0732: 29 [22 F2]  |   DAD H
     0x0733: 22 [F2 20]  |   SHLD 0x20F2
     0x0734: F2 [20 CD]  |   JP 0xCD20
     0x0735: 20 [CD 42]  |   Undefined instruction
     0x0736: CD [42 07]  |   CAL 0x0742
     0x0737: 42 [07 C3]  |   MOV B, D
     0x0738: 07 [C3 F1]  |   RLC
     0x0739: C3 [F1 08]  |   JMP 0x08F1
     0x073a: F1 [08 CD]  |   POP PSW
     0x073b: 08 [CD 42]  |   Undefined instruction
     0x073c: CD [42 07]  |   CAL 0x0742
     0x073d: 42 [07 C3]  |   MOV B, D
     0x073e: 07 [C3 39]  |   RLC
     0x073f: C3 [39 14]  |   JMP 0x1439
     0x0740: 39 [14 21]  |   DAD SP
     0x0741: 14 [21 87]  |   INR D
     0x0742: 21 [87 20]  |   LXI H, 0x2087 
     0x0743: 87 [20 CD]  |   ADD A
     0x0744: 20 [CD 3B]  |   Undefined instruction
     0x0745: CD [3B 1A]  |   CAL 0x1A3B
     0x0746: 3B [1A C3]  |   DCX SP
     0x0747: 1A [C3 47]  |   LDAX D
     0x0748: C3 [47 1A]  |   JMP 0x1A47
     0x0749: 47 [1A 06]  |   MOV B, A
     0x074a: 1A [06 10]  |   LDAX D
     0x074b: 06 [10 21]  |   MVI B, 0x10
     0x074c: 10 [21 98]  |   Undefined instruction
     0x074d: 21 [98 20]  |   LXI H, 0x2098 
     0x074e: 98 [20 7E]  |   SBB B
     0x074f: 20 [7E B0]  |   Undefined instruction
     0x0750: 7E [B0 77]  |   MOV A, M
     0x0751: B0 [77 CD]  |   ORA B
     0x0752: 77 [CD 70]  |   MOV M, A
     0x0753: CD [70 17]  |   CAL 0x1770
     0x0754: 70 [17 21]  |   MOV M, B
     0x0755: 17 [21 7C]  |   RAL
     0x0756: 21 [7C 1D]  |   LXI H, 0x1D7C 
     0x0757: 7C [1D 22]  |   MOV A, H
     0x0758: 1D [22 87]  |   DCR E
     0x0759: 22 [87 20]  |   SHLD 0x2087
     0x075a: 87 [20 C3]  |   ADD A
     0x075b: 20 [C3 3C]  |   Undefined instruction
     0x075c: C3 [3C 07]  |   JMP 0x073C
     0x075d: 3C [07 11]  |   INR A
     0x075e: 07 [11 83]  |   RLC
     0x075f: 11 [83 1B]  |   LXI D, 0x1B83 
     0x0760: 83 [1B C3]  |   ADD E
     0x0761: 1B [C3 32]  |   DCX D
     0x0762: C3 [32 1A]  |   JMP 0x1A32
     0x0763: 32 [1A 3E]  |   STA 0x3E1A
     0x0764: 1A [3E 01]  |   LDAX D
     0x0765: 3E [01 32]  |   MVI A, 0x01
     0x0766: 01 [32 93]  |   LXI B, 0x9332 
     0x0767: 32 [93 20]  |   STA 0x2093
     0x0768: 93 [20 31]  |   SUB E
     0x0769: 20 [31 00]  |   Undefined instruction
     0x076a: 31 [00 24]  |   LXI SP, 0x2400 
     0x076b: 00 [24 FB]  |   NOP
     0x076c: 24 [FB CD]  |   INR H
     0x076d: FB [CD 79]  |   EI
     0x076e: CD [79 19]  |   CAL 0x1979
     0x076f: 79 [19 CD]  |   MOV A, C
     0x0770: 19 [CD D6]  |   DAD D
     0x0771: CD [D6 09]  |   CAL 0x09D6
     0x0772: D6 [09 21]  |   SUI 0x09
     0x0773: 09 [21 13]  |   DAD B
     0x0774: 21 [13 30]  |   LXI H, 0x3013 
     0x0775: 13 [30 11]  |   INX D
     0x0776: 30 [11 F3]  |   Undefined instruction
     0x0777: 11 [F3 1F]  |   LXI D, 0x1FF3 
     0x0778: F3 [1F 0E]  |   DI
     0x0779: 1F [0E 04]  |   RAR
     0x077a: 0E [04 CD]  |   MVI C, 0x04
     0x077b: 04 [CD F3]  |   INR B
     0x077c: CD [F3 08]  |   CAL 0x08F3
     0x077d: F3 [08 3A]  |   DI
     0x077e: 08 [3A EB]  |   Undefined instruction
     0x077f: 3A [EB 20]  |   LDA 0x20EB
     0x0780: EB [20 3D]  |   XCHG
     0x0781: 20 [3D 21]  |   Undefined instruction
     0x0782: 3D [21 10]  |   DCR A
     0x0783: 21 [10 28]  |   LXI H, 0x2810 
     0x0784: 10 [28 0E]  |   Undefined instruction
     0x0785: 28 [0E 14]  |   Undefined instruction
     0x0786: 0E [14 C2]  |   MVI C, 0x14
     0x0787: 14 [C2 57]  |   INR D
     0x0788: C2 [57 08]  |   JNZ 0x0857
     0x0789: 57 [08 11]  |   MOV D, A
     0x078a: 08 [11 CF]  |   Undefined instruction
     0x078b: 11 [CF 1A]  |   LXI D, 0x1ACF 
     0x078c: CF [1A CD]  |   RST 1
     0x078d: 1A [CD F3]  |   LDAX D
     0x078e: CD [F3 08]  |   CAL 0x08F3
     0x078f: F3 [08 DB]  |   DI
     0x0790: 08 [DB 01]  |   Undefined instruction
     0x0791: DB [01 E6]  |   IN 0x01
     0x0792: 01 [E6 04]  |   LXI B, 0x04E6 
     0x0793: E6 [04 CA]  |   ANI 0x04
     0x0794: 04 [CA 7F]  |   INR B
     0x0795: CA [7F 07]  |   JZ 0x077F
     0x0796: 7F [07 06]  |   MOV A, A
     0x0797: 07 [06 99]  |   RLC
     0x0798: 06 [99 AF]  |   MVI B, 0x99
     0x0799: 99 [AF 32]  |   SBB C
     0x079a: AF [32 CE]  |   XRA A
     0x079b: 32 [CE 20]  |   STA 0x20CE
     0x079c: CE [20 3A]  |   ACI 0x20
     0x079d: 20 [3A EB]  |   Undefined instruction
     0x079e: 3A [EB 20]  |   LDA 0x20EB
     0x079f: EB [20 80]  |   XCHG
     0x07a0: 20 [80 27]  |   Undefined instruction
     0x07a1: 80 [27 32]  |   ADD B
     0x07a2: 27 [32 EB]  |   DAA
     0x07a3: 32 [EB 20]  |   STA 0x20EB
     0x07a4: EB [20 CD]  |   XCHG
     0x07a5: 20 [CD 47]  |   Undefined instruction
     0x07a6: CD [47 19]  |   CAL 0x1947
     0x07a7: 47 [19 21]  |   MOV B, A
     0x07a8: 19 [21 00]  |   DAD D
     0x07a9: 21 [00 00]  |   LXI H, 0x0000 
     0x07aa: 00 [00 22]  |   NOP
     0x07ab: 00 [22 F8]  |   NOP
     0x07ac: 22 [F8 20]  |   SHLD 0x20F8
     0x07ad: F8 [20 22]  |   RM
     0x07ae: 20 [22 FC]  |   Undefined instruction
     0x07af: 22 [FC 20]  |   SHLD 0x20FC
     0x07b0: FC [20 CD]  |   CM 0xCD20
     0x07b1: 20 [CD 25]  |   Undefined instruction
     0x07b2: CD [25 19]  |   CAL 0x1925
     0x07b3: 25 [19 CD]  |   DCR H
     0x07b4: 19 [CD 2B]  |   DAD D
     0x07b5: CD [2B 19]  |   CAL 0x192B
     0x07b6: 2B [19 CD]  |   DCX H
     0x07b7: 19 [CD D7]  |   DAD D
     0x07b8: CD [D7 19]  |   CAL 0x19D7
     0x07b9: D7 [19 21]  |   RST 2
     0x07ba: 19 [21 01]  |   DAD D
     0x07bb: 21 [01 01]  |   LXI H, 0x0101 
     0x07bc: 01 [01 7C]  |   LXI B, 0x7C01 
     0x07bd: 01 [7C 32]  |   LXI B, 0x327C 
     0x07be: 7C [32 EF]  |   MOV A, H
     0x07bf: 32 [EF 20]  |   STA 0x20EF
     0x07c0: EF [20 22]  |   RST 5
     0x07c1: 20 [22 E7]  |   Undefined instruction
     0x07c2: 22 [E7 20]  |   SHLD 0x20E7
     0x07c3: E7 [20 22]  |   RST 4
     0x07c4: 20 [22 E5]  |   Undefined instruction
     0x07c5: 22 [E5 20]  |   SHLD 0x20E5
     0x07c6: E5 [20 CD]  |   PUSH H
     0x07c7: 20 [CD 56]  |   Undefined instruction
     0x07c8: CD [56 19]  |   CAL 0x1956
     0x07c9: 56 [19 CD]  |   MOV D, M
     0x07ca: 19 [CD EF]  |   DAD D
     0x07cb: CD [EF 01]  |   CAL 0x01EF
     0x07cc: EF [01 CD]  |   RST 5
     0x07cd: 01 [CD F5]  |   LXI B, 0xF5CD 
     0x07ce: CD [F5 01]  |   CAL 0x01F5
     0x07cf: F5 [01 CD]  |   PUSH PSW
     0x07d0: 01 [CD D1]  |   LXI B, 0xD1CD 
     0x07d1: CD [D1 08]  |   CAL 0x08D1
     0x07d2: D1 [08 32]  |   POP D
     0x07d3: 08 [32 FF]  |   Undefined instruction
     0x07d4: 32 [FF 21]  |   STA 0x21FF
     0x07d5: FF [21 32]  |   RST 7
     0x07d6: 21 [32 FF]  |   LXI H, 0xFF32 
     0x07d7: 32 [FF 22]  |   STA 0x22FF
     0x07d8: FF [22 CD]  |   RST 7
     0x07d9: 22 [CD D7]  |   SHLD 0xD7CD
     0x07da: CD [D7 00]  |   CAL 0x00D7
     0x07db: D7 [00 AF]  |   RST 2
     0x07dc: 00 [AF 32]  |   NOP
     0x07dd: AF [32 FE]  |   XRA A
     0x07de: 32 [FE 21]  |   STA 0x21FE
     0x07df: FE [21 32]  |   CPI 0x21
     0x07e0: 21 [32 FE]  |   LXI H, 0xFE32 
     0x07e1: 32 [FE 22]  |   STA 0x22FE
     0x07e2: FE [22 CD]  |   CPI 0x22
     0x07e3: 22 [CD C0]  |   SHLD 0xC0CD
     0x07e4: CD [C0 01]  |   CAL 0x01C0
     0x07e5: C0 [01 CD]  |   RNZ
     0x07e6: 01 [CD 04]  |   LXI B, 0x04CD 
     0x07e7: CD [04 19]  |   CAL 0x1904
     0x07e8: 04 [19 21]  |   INR B
     0x07e9: 19 [21 78]  |   DAD D
     0x07ea: 21 [78 38]  |   LXI H, 0x3878 
     0x07eb: 78 [38 22]  |   MOV A, B
     0x07ec: 38 [22 FC]  |   Undefined instruction
     0x07ed: 22 [FC 21]  |   SHLD 0x21FC
     0x07ee: FC [21 22]  |   CM 0x2221
     0x07ef: 21 [22 FC]  |   LXI H, 0xFC22 
     0x07f0: 22 [FC 22]  |   SHLD 0x22FC
     0x07f1: FC [22 CD]  |   CM 0xCD22
     0x07f2: 22 [CD E4]  |   SHLD 0xE4CD
     0x07f3: CD [E4 01]  |   CAL 0x01E4
     0x07f4: E4 [01 CD]  |   CPO 0xCD01
     0x07f5: 01 [CD 7F]  |   LXI B, 0x7FCD 
     0x07f6: CD [7F 1A]  |   CAL 0x1A7F
     0x07f7: 7F [1A CD]  |   MOV A, A
     0x07f8: 1A [CD 8D]  |   LDAX D
     0x07f9: CD [8D 08]  |   CAL 0x088D
     0x07fa: 8D [08 CD]  |   ADC L
     0x07fb: 08 [CD D6]  |   Undefined instruction
     0x07fc: CD [D6 09]  |   CAL 0x09D6
     0x07fd: D6 [09 00]  |   SUI 0x09
     0x07fe: 09 [00 AF]  |   DAD B
     0x07ff: 00 [AF 32]  |   NOP
     0x0800: AF [32 C1]  |   XRA A
     0x0801: 32 [C1 20]  |   STA 0x20C1
     0x0802: C1 [20 CD]  |   POP B
     0x0803: 20 [CD CF]  |   Undefined instruction
     0x0804: CD [CF 01]  |   CAL 0x01CF
     0x0805: CF [01 3A]  |   RST 1
     0x0806: 01 [3A 67]  |   LXI B, 0x673A 
     0x0807: 3A [67 20]  |   LDA 0x2067
     0x0808: 67 [20 0F]  |   MOV H, A
     0x0809: 20 [0F DA]  |   Undefined instruction
     0x080a: 0F [DA 72]  |   RRC
     0x080b: DA [72 08]  |   JC 0x0872
     0x080c: 72 [08 CD]  |   MOV M, D
     0x080d: 08 [CD 13]  |   Undefined instruction
     0x080e: CD [13 02]  |   CAL 0x0213
     0x080f: 13 [02 CD]  |   INX D
     0x0810: 02 [CD CF]  |   STAX B
     0x0811: CD [CF 01]  |   CAL 0x01CF
     0x0812: CF [01 CD]  |   RST 1
     0x0813: 01 [CD B1]  |   LXI B, 0xB1CD 
     0x0814: CD [B1 00]  |   CAL 0x00B1
     0x0815: B1 [00 CD]  |   ORA C
     0x0816: 00 [CD D1]  |   NOP
     0x0817: CD [D1 19]  |   CAL 0x19D1
     0x0818: D1 [19 06]  |   POP D
     0x0819: 19 [06 20]  |   DAD D
     0x081a: 06 [20 CD]  |   MVI B, 0x20
     0x081b: 20 [CD FA]  |   Undefined instruction
     0x081c: CD [FA 18]  |   CAL 0x18FA
     0x081d: FA [18 CD]  |   JM 0xCD18
     0x081e: 18 [CD 18]  |   Undefined instruction
     0x081f: CD [18 16]  |   CAL 0x1618
     0x0820: 18 [16 CD]  |   Undefined instruction
     0x0821: 16 [CD 0A]  |   MVI D, 0xCD
     0x0822: CD [0A 19]  |   CAL 0x190A
     0x0823: 0A [19 CD]  |   LDAX B
     0x0824: 19 [CD F3]  |   DAD D
     0x0825: CD [F3 15]  |   CAL 0x15F3
     0x0826: F3 [15 CD]  |   DI
     0x0827: 15 [CD 88]  |   DCR D
     0x0828: CD [88 09]  |   CAL 0x0988
     0x0829: 88 [09 3A]  |   ADC B
     0x082a: 09 [3A 82]  |   DAD B
     0x082b: 3A [82 20]  |   LDA 0x2082
     0x082c: 82 [20 A7]  |   ADD D
     0x082d: 20 [A7 CA]  |   Undefined instruction
     0x082e: A7 [CA EF]  |   ANA A
     0x082f: CA [EF 09]  |   JZ 0x09EF
     0x0830: EF [09 CD]  |   RST 5
     0x0831: 09 [CD 0E]  |   DAD B
     0x0832: CD [0E 17]  |   CAL 0x170E
     0x0833: 0E [17 CD]  |   MVI C, 0x17
     0x0834: 17 [CD 35]  |   RAL
     0x0835: CD [35 09]  |   CAL 0x0935
     0x0836: 35 [09 CD]  |   DCR M
     0x0837: 09 [CD D8]  |   DAD B
     0x0838: CD [D8 08]  |   CAL 0x08D8
     0x0839: D8 [08 CD]  |   RC
     0x083a: 08 [CD 2C]  |   Undefined instruction
     0x083b: CD [2C 17]  |   CAL 0x172C
     0x083c: 2C [17 CD]  |   INR L
     0x083d: 17 [CD 59]  |   RAL
     0x083e: CD [59 0A]  |   CAL 0x0A59
     0x083f: 59 [0A CA]  |   MOV E, C
     0x0840: 0A [CA 49]  |   LDAX B
     0x0841: CA [49 08]  |   JZ 0x0849
     0x0842: 49 [08 06]  |   MOV C, C
     0x0843: 08 [06 04]  |   Undefined instruction
     0x0844: 06 [04 CD]  |   MVI B, 0x04
     0x0845: 04 [CD FA]  |   INR B
     0x0846: CD [FA 18]  |   CAL 0x18FA
     0x0847: FA [18 CD]  |   JM 0xCD18
     0x0848: 18 [CD 75]  |   Undefined instruction
     0x0849: CD [75 17]  |   CAL 0x1775
     0x084a: 75 [17 D3]  |   MOV M, L
     0x084b: 17 [D3 06]  |   RAL
     0x084c: D3 [06 CD]  |   OUT 0x06
     0x084d: 06 [CD 04]  |   MVI B, 0xCD
     0x084e: CD [04 18]  |   CAL 0x1804
     0x084f: 04 [18 C3]  |   INR B
     0x0850: 18 [C3 1F]  |   Undefined instruction
     0x0851: C3 [1F 08]  |   JMP 0x081F
     0x0852: 1F [08 00]  |   RAR
     0x0853: 08 [00 00]  |   Undefined instruction
     0x0854: 00 [00 00]  |   NOP
     0x0855: 00 [00 11]  |   NOP
     0x0856: 00 [11 BA]  |   NOP
     0x0857: 11 [BA 1A]  |   LXI D, 0x1ABA 
     0x0858: BA [1A CD]  |   CMP D
     0x0859: 1A [CD F3]  |   LDAX D
     0x085a: CD [F3 08]  |   CAL 0x08F3
     0x085b: F3 [08 06]  |   DI
     0x085c: 08 [06 98]  |   Undefined instruction
     0x085d: 06 [98 DB]  |   MVI B, 0x98
     0x085e: 98 [DB 01]  |   SBB B
     0x085f: DB [01 0F]  |   IN 0x01
     0x0860: 01 [0F 0F]  |   LXI B, 0x0F0F 
     0x0861: 0F [0F DA]  |   RRC
     0x0862: 0F [DA 6D]  |   RRC
     0x0863: DA [6D 08]  |   JC 0x086D
     0x0864: 6D [08 0F]  |   MOV L, L
     0x0865: 08 [0F DA]  |   Undefined instruction
     0x0866: 0F [DA 98]  |   RRC
     0x0867: DA [98 07]  |   JC 0x0798
     0x0868: 98 [07 C3]  |   SBB B
     0x0869: 07 [C3 7F]  |   RLC
     0x086a: C3 [7F 07]  |   JMP 0x077F
     0x086b: 7F [07 3E]  |   MOV A, A
     0x086c: 07 [3E 01]  |   RLC
     0x086d: 3E [01 C3]  |   MVI A, 0x01
     0x086e: 01 [C3 9B]  |   LXI B, 0x9BC3 
     0x086f: C3 [9B 07]  |   JMP 0x079B
     0x0870: 9B [07 CD]  |   SBB E
     0x0871: 07 [CD 1A]  |   RLC
     0x0872: CD [1A 02]  |   CAL 0x021A
     0x0873: 1A [02 C3]  |   LDAX D
     0x0874: 02 [C3 14]  |   STAX B
     0x0875: C3 [14 08]  |   JMP 0x0814
     0x0876: 14 [08 3A]  |   INR D
     0x0877: 08 [3A 08]  |   Undefined instruction
     0x0878: 3A [08 20]  |   LDA 0x2008
     0x0879: 08 [20 47]  |   Undefined instruction
     0x087a: 20 [47 2A]  |   Undefined instruction
     0x087b: 47 [2A 09]  |   MOV B, A
     0x087c: 2A [09 20]  |   LHLD 0x2009
     0x087d: 09 [20 EB]  |   DAD B
     0x087e: 20 [EB C3]  |   Undefined instruction
     0x087f: EB [C3 86]  |   XCHG
     0x0880: C3 [86 08]  |   JMP 0x0886
     0x0881: 86 [08 00]  |   ADD M
     0x0882: 08 [00 00]  |   Undefined instruction
     0x0883: 00 [00 00]  |   NOP
     0x0884: 00 [00 3A]  |   NOP
     0x0885: 00 [3A 67]  |   NOP
     0x0886: 3A [67 20]  |   LDA 0x2067
     0x0887: 67 [20 67]  |   MOV H, A
     0x0888: 20 [67 2E]  |   Undefined instruction
     0x0889: 67 [2E FC]  |   MOV H, A
     0x088a: 2E [FC C9]  |   MVI L, 0xFC
     0x088b: FC [C9 21]  |   CM 0x21C9
     0x088c: C9 [21 11]  |   RET
     0x088d: 21 [11 2B]  |   LXI H, 0x2B11 
     0x088e: 11 [2B 11]  |   LXI D, 0x112B 
     0x088f: 2B [11 70]  |   DCX H
     0x0890: 11 [70 1B]  |   LXI D, 0x1B70 
     0x0891: 70 [1B 0E]  |   MOV M, B
     0x0892: 1B [0E 0E]  |   DCX D
     0x0893: 0E [0E CD]  |   MVI C, 0x0E
     0x0894: 0E [CD F3]  |   MVI C, 0xCD
     0x0895: CD [F3 08]  |   CAL 0x08F3
     0x0896: F3 [08 3A]  |   DI
     0x0897: 08 [3A 67]  |   Undefined instruction
     0x0898: 3A [67 20]  |   LDA 0x2067
     0x0899: 67 [20 0F]  |   MOV H, A
     0x089a: 20 [0F 3E]  |   Undefined instruction
     0x089b: 0F [3E 1C]  |   RRC
     0x089c: 3E [1C 21]  |   MVI A, 0x1C
     0x089d: 1C [21 11]  |   INR E
     0x089e: 21 [11 37]  |   LXI H, 0x3711 
     0x089f: 11 [37 D4]  |   LXI D, 0xD437 
     0x08a0: 37 [D4 FF]  |   STC
     0x08a1: D4 [FF 08]  |   CNC 0x08FF
     0x08a2: FF [08 3E]  |   RST 7
     0x08a3: 08 [3E B0]  |   Undefined instruction
     0x08a4: 3E [B0 32]  |   MVI A, 0xB0
     0x08a5: B0 [32 C0]  |   ORA B
     0x08a6: 32 [C0 20]  |   STA 0x20C0
     0x08a7: C0 [20 3A]  |   RNZ
     0x08a8: 20 [3A C0]  |   Undefined instruction
     0x08a9: 3A [C0 20]  |   LDA 0x20C0
     0x08aa: C0 [20 A7]  |   RNZ
     0x08ab: 20 [A7 C8]  |   Undefined instruction
     0x08ac: A7 [C8 E6]  |   ANA A
     0x08ad: C8 [E6 04]  |   RZ
     0x08ae: E6 [04 C2]  |   ANI 0x04
     0x08af: 04 [C2 BC]  |   INR B
     0x08b0: C2 [BC 08]  |   JNZ 0x08BC
     0x08b1: BC [08 CD]  |   CMP H
     0x08b2: 08 [CD CA]  |   Undefined instruction
     0x08b3: CD [CA 09]  |   CAL 0x09CA
     0x08b4: CA [09 CD]  |   JZ 0xCD09
     0x08b5: 09 [CD 31]  |   DAD B
     0x08b6: CD [31 19]  |   CAL 0x1931
     0x08b7: 31 [19 C3]  |   LXI SP, 0xC319 
     0x08b8: 19 [C3 A9]  |   DAD D
     0x08b9: C3 [A9 08]  |   JMP 0x08A9
     0x08ba: A9 [08 06]  |   XRA C
     0x08bb: 08 [06 20]  |   Undefined instruction
     0x08bc: 06 [20 21]  |   MVI B, 0x20
     0x08bd: 20 [21 1C]  |   Undefined instruction
     0x08be: 21 [1C 27]  |   LXI H, 0x271C 
     0x08bf: 1C [27 3A]  |   INR E
     0x08c0: 27 [3A 67]  |   DAA
     0x08c1: 3A [67 20]  |   LDA 0x2067
     0x08c2: 67 [20 0F]  |   MOV H, A
     0x08c3: 20 [0F DA]  |   Undefined instruction
     0x08c4: 0F [DA CB]  |   RRC
     0x08c5: DA [CB 08]  |   JC 0x08CB
     0x08c6: CB [08 21]  |   Undefined instruction
     0x08c7: 08 [21 1C]  |   Undefined instruction
     0x08c8: 21 [1C 39]  |   LXI H, 0x391C 
     0x08c9: 1C [39 CD]  |   INR E
     0x08ca: 39 [CD CB]  |   DAD SP
     0x08cb: CD [CB 14]  |   CAL 0x14CB
     0x08cc: CB [14 C3]  |   Undefined instruction
     0x08cd: 14 [C3 A9]  |   INR D
     0x08ce: C3 [A9 08]  |   JMP 0x08A9
     0x08cf: A9 [08 DB]  |   XRA C
     0x08d0: 08 [DB 02]  |   Undefined instruction
     0x08d1: DB [02 E6]  |   IN 0x02
     0x08d2: 02 [E6 03]  |   STAX B
     0x08d3: E6 [03 C6]  |   ANI 0x03
     0x08d4: 03 [C6 03]  |   INX B
     0x08d5: C6 [03 C9]  |   ADI 0x03
     0x08d6: 03 [C9 3A]  |   INX B
     0x08d7: C9 [3A 82]  |   RET
     0x08d8: 3A [82 20]  |   LDA 0x2082
     0x08d9: 82 [20 FE]  |   ADD D
     0x08da: 20 [FE 09]  |   Undefined instruction
     0x08db: FE [09 D0]  |   CPI 0x09
     0x08dc: 09 [D0 3E]  |   DAD B
     0x08dd: D0 [3E FB]  |   RNC
     0x08de: 3E [FB 32]  |   MVI A, 0xFB
     0x08df: FB [32 7E]  |   EI
     0x08e0: 32 [7E 20]  |   STA 0x207E
     0x08e1: 7E [20 C9]  |   MOV A, M
     0x08e2: 20 [C9 3A]  |   Undefined instruction
     0x08e3: C9 [3A CE]  |   RET
     0x08e4: 3A [CE 20]  |   LDA 0x20CE
     0x08e5: CE [20 A7]  |   ACI 0x20
     0x08e6: 20 [A7 C0]  |   Undefined instruction
     0x08e7: A7 [C0 21]  |   ANA A
     0x08e8: C0 [21 1C]  |   RNZ
     0x08e9: 21 [1C 39]  |   LXI H, 0x391C 
     0x08ea: 1C [39 06]  |   INR E
     0x08eb: 39 [06 20]  |   DAD SP
     0x08ec: 06 [20 C3]  |   MVI B, 0x20
     0x08ed: 20 [C3 CB]  |   Undefined instruction
     0x08ee: C3 [CB 14]  |   JMP 0x14CB
     0x08ef: CB [14 0E]  |   Undefined instruction
     0x08f0: 14 [0E 03]  |   INR D
     0x08f1: 0E [03 1A]  |   MVI C, 0x03
     0x08f2: 03 [1A D5]  |   INX B
     0x08f3: 1A [D5 CD]  |   LDAX D
     0x08f4: D5 [CD FF]  |   PUSH D
     0x08f5: CD [FF 08]  |   CAL 0x08FF
     0x08f6: FF [08 D1]  |   RST 7
     0x08f7: 08 [D1 13]  |   Undefined instruction
     0x08f8: D1 [13 0D]  |   POP D
     0x08f9: 13 [0D C2]  |   INX D
     0x08fa: 0D [C2 F3]  |   DCR C
     0x08fb: C2 [F3 08]  |   JNZ 0x08F3
     0x08fc: F3 [08 C9]  |   DI
     0x08fd: 08 [C9 11]  |   Undefined instruction
     0x08fe: C9 [11 00]  |   RET
     0x08ff: 11 [00 1E]  |   LXI D, 0x1E00 
     0x0900: 00 [1E E5]  |   NOP
     0x0901: 1E [E5 26]  |   MVI E, 0xE5
     0x0902: E5 [26 00]  |   PUSH H
     0x0903: 26 [00 6F]  |   MVI H, 0x00
     0x0904: 00 [6F 29]  |   NOP
     0x0905: 6F [29 29]  |   MOV L, A
     0x0906: 29 [29 29]  |   DAD H
     0x0907: 29 [29 19]  |   DAD H
     0x0908: 29 [19 EB]  |   DAD H
     0x0909: 19 [EB E1]  |   DAD D
     0x090a: EB [E1 06]  |   XCHG
     0x090b: E1 [06 08]  |   POP H
     0x090c: 06 [08 D3]  |   MVI B, 0x08
     0x090d: 08 [D3 06]  |   Undefined instruction
     0x090e: D3 [06 C3]  |   OUT 0x06
     0x090f: 06 [C3 39]  |   MVI B, 0xC3
     0x0910: C3 [39 14]  |   JMP 0x1439
     0x0911: 39 [14 3A]  |   DAD SP
     0x0912: 14 [3A 09]  |   INR D
     0x0913: 3A [09 20]  |   LDA 0x2009
     0x0914: 09 [20 FE]  |   DAD B
     0x0915: 20 [FE 78]  |   Undefined instruction
     0x0916: FE [78 D0]  |   CPI 0x78
     0x0917: 78 [D0 2A]  |   MOV A, B
     0x0918: D0 [2A 91]  |   RNC
     0x0919: 2A [91 20]  |   LHLD 0x2091
     0x091a: 91 [20 7D]  |   SUB C
     0x091b: 20 [7D B4]  |   Undefined instruction
     0x091c: 7D [B4 C2]  |   MOV A, L
     0x091d: B4 [C2 29]  |   ORA H
     0x091e: C2 [29 09]  |   JNZ 0x0929
     0x091f: 29 [09 21]  |   DAD H
     0x0920: 09 [21 00]  |   DAD B
     0x0921: 21 [00 06]  |   LXI H, 0x0600 
     0x0922: 00 [06 3E]  |   NOP
     0x0923: 06 [3E 01]  |   MVI B, 0x3E
     0x0924: 3E [01 32]  |   MVI A, 0x01
     0x0925: 01 [32 83]  |   LXI B, 0x8332 
     0x0926: 32 [83 20]  |   STA 0x2083
     0x0927: 83 [20 2B]  |   ADD E
     0x0928: 20 [2B 22]  |   Undefined instruction
     0x0929: 2B [22 91]  |   DCX H
     0x092a: 22 [91 20]  |   SHLD 0x2091
     0x092b: 91 [20 C9]  |   SUB C
     0x092c: 20 [C9 CD]  |   Undefined instruction
     0x092d: C9 [CD 11]  |   RET
     0x092e: CD [11 16]  |   CAL 0x1611
     0x092f: 11 [16 2E]  |   LXI D, 0x2E16 
     0x0930: 16 [2E FF]  |   MVI D, 0x2E
     0x0931: 2E [FF 7E]  |   MVI L, 0xFF
     0x0932: FF [7E C9]  |   RST 7
     0x0933: 7E [C9 CD]  |   MOV A, M
     0x0934: C9 [CD 10]  |   RET
     0x0935: CD [10 19]  |   CAL 0x1910
     0x0936: 10 [19 2B]  |   Undefined instruction
     0x0937: 19 [2B 2B]  |   DAD D
     0x0938: 2B [2B 7E]  |   DCX H
     0x0939: 2B [7E A7]  |   DCX H
     0x093a: 7E [A7 C8]  |   MOV A, M
     0x093b: A7 [C8 06]  |   ANA A
     0x093c: C8 [06 15]  |   RZ
     0x093d: 06 [15 DB]  |   MVI B, 0x15
     0x093e: 15 [DB 02]  |   DCR D
     0x093f: DB [02 E6]  |   IN 0x02
     0x0940: 02 [E6 08]  |   STAX B
     0x0941: E6 [08 CA]  |   ANI 0x08
     0x0942: 08 [CA 48]  |   Undefined instruction
     0x0943: CA [48 09]  |   JZ 0x0948
     0x0944: 48 [09 06]  |   MOV C, B
     0x0945: 09 [06 10]  |   DAD B
     0x0946: 06 [10 CD]  |   MVI B, 0x10
     0x0947: 10 [CD CA]  |   Undefined instruction
     0x0948: CD [CA 09]  |   CAL 0x09CA
     0x0949: CA [09 23]  |   JZ 0x2309
     0x094a: 09 [23 7E]  |   DAD B
     0x094b: 23 [7E B8]  |   INX H
     0x094c: 7E [B8 D8]  |   MOV A, M
     0x094d: B8 [D8 CD]  |   CMP B
     0x094e: D8 [CD 2E]  |   RC
     0x094f: CD [2E 09]  |   CAL 0x092E
     0x0950: 2E [09 34]  |   MVI L, 0x09
     0x0951: 09 [34 7E]  |   DAD B
     0x0952: 34 [7E F5]  |   INR M
     0x0953: 7E [F5 21]  |   MOV A, M
     0x0954: F5 [21 01]  |   PUSH PSW
     0x0955: 21 [01 25]  |   LXI H, 0x2501 
     0x0956: 01 [25 24]  |   LXI B, 0x2425 
     0x0957: 25 [24 24]  |   DCR H
     0x0958: 24 [24 3D]  |   INR H
     0x0959: 24 [3D C2]  |   INR H
     0x095a: 3D [C2 58]  |   DCR A
     0x095b: C2 [58 09]  |   JNZ 0x0958
     0x095c: 58 [09 06]  |   MOV E, B
     0x095d: 09 [06 10]  |   DAD B
     0x095e: 06 [10 11]  |   MVI B, 0x10
     0x095f: 10 [11 60]  |   Undefined instruction
     0x0960: 11 [60 1C]  |   LXI D, 0x1C60 
     0x0961: 60 [1C CD]  |   MOV H, B
     0x0962: 1C [CD 39]  |   INR E
     0x0963: CD [39 14]  |   CAL 0x1439
     0x0964: 39 [14 F1]  |   DAD SP
     0x0965: 14 [F1 3C]  |   INR D
     0x0966: F1 [3C CD]  |   POP PSW
     0x0967: 3C [CD 8B]  |   INR A
     0x0968: CD [8B 1A]  |   CAL 0x1A8B
     0x0969: 8B [1A CD]  |   ADC E
     0x096a: 1A [CD 10]  |   LDAX D
     0x096b: CD [10 19]  |   CAL 0x1910
     0x096c: 10 [19 2B]  |   Undefined instruction
     0x096d: 19 [2B 2B]  |   DAD D
     0x096e: 2B [2B 36]  |   DCX H
     0x096f: 2B [36 00]  |   DCX H
     0x0970: 36 [00 3E]  |   MVI M, 0x00
     0x0971: 00 [3E FF]  |   NOP
     0x0972: 3E [FF 32]  |   MVI A, 0xFF
     0x0973: FF [32 99]  |   RST 7
     0x0974: 32 [99 20]  |   STA 0x2099
     0x0975: 99 [20 06]  |   SBB C
     0x0976: 20 [06 10]  |   Undefined instruction
     0x0977: 06 [10 C3]  |   MVI B, 0x10
     0x0978: 10 [C3 FA]  |   Undefined instruction
     0x0979: C3 [FA 18]  |   JMP 0x18FA
     0x097a: FA [18 21]  |   JM 0x2118
     0x097b: 18 [21 A0]  |   Undefined instruction
     0x097c: 21 [A0 1D]  |   LXI H, 0x1DA0 
     0x097d: A0 [1D FE]  |   ANA B
     0x097e: 1D [FE 02]  |   DCR E
     0x097f: FE [02 D8]  |   CPI 0x02
     0x0980: 02 [D8 23]  |   STAX B
     0x0981: D8 [23 FE]  |   RC
     0x0982: 23 [FE 04]  |   INX H
     0x0983: FE [04 D8]  |   CPI 0x04
     0x0984: 04 [D8 23]  |   INR B
     0x0985: D8 [23 C9]  |   RC
     0x0986: 23 [C9 CD]  |   INX H
     0x0987: C9 [CD CA]  |   RET
     0x0988: CD [CA 09]  |   CAL 0x09CA
     0x0989: CA [09 3A]  |   JZ 0x3A09
     0x098a: 09 [3A F1]  |   DAD B
     0x098b: 3A [F1 20]  |   LDA 0x20F1
     0x098c: F1 [20 A7]  |   POP PSW
     0x098d: 20 [A7 C8]  |   Undefined instruction
     0x098e: A7 [C8 AF]  |   ANA A
     0x098f: C8 [AF 32]  |   RZ
     0x0990: AF [32 F1]  |   XRA A
     0x0991: 32 [F1 20]  |   STA 0x20F1
     0x0992: F1 [20 E5]  |   POP PSW
     0x0993: 20 [E5 2A]  |   Undefined instruction
     0x0994: E5 [2A F2]  |   PUSH H
     0x0995: 2A [F2 20]  |   LHLD 0x20F2
     0x0996: F2 [20 EB]  |   JP 0xEB20
     0x0997: 20 [EB E1]  |   Undefined instruction
     0x0998: EB [E1 7E]  |   XCHG
     0x0999: E1 [7E 83]  |   POP H
     0x099a: 7E [83 27]  |   MOV A, M
     0x099b: 83 [27 77]  |   ADD E
     0x099c: 27 [77 5F]  |   DAA
     0x099d: 77 [5F 23]  |   MOV M, A
     0x099e: 5F [23 7E]  |   MOV E, A
     0x099f: 23 [7E 8A]  |   INX H
     0x09a0: 7E [8A 27]  |   MOV A, M
     0x09a1: 8A [27 77]  |   ADC D
     0x09a2: 27 [77 57]  |   DAA
     0x09a3: 77 [57 23]  |   MOV M, A
     0x09a4: 57 [23 7E]  |   MOV D, A
     0x09a5: 23 [7E 23]  |   INX H
     0x09a6: 7E [23 66]  |   MOV A, M
     0x09a7: 23 [66 6F]  |   INX H
     0x09a8: 66 [6F C3]  |   MOV H, M
     0x09a9: 6F [C3 AD]  |   MOV L, A
     0x09aa: C3 [AD 09]  |   JMP 0x09AD
     0x09ab: AD [09 7A]  |   XRA L
     0x09ac: 09 [7A CD]  |   DAD B
     0x09ad: 7A [CD B2]  |   MOV A, D
     0x09ae: CD [B2 09]  |   CAL 0x09B2
     0x09af: B2 [09 7B]  |   ORA D
     0x09b0: 09 [7B D5]  |   DAD B
     0x09b1: 7B [D5 F5]  |   MOV A, E
     0x09b2: D5 [F5 0F]  |   PUSH D
     0x09b3: F5 [0F 0F]  |   PUSH PSW
     0x09b4: 0F [0F 0F]  |   RRC
     0x09b5: 0F [0F 0F]  |   RRC
     0x09b6: 0F [0F E6]  |   RRC
     0x09b7: 0F [E6 0F]  |   RRC
     0x09b8: E6 [0F CD]  |   ANI 0x0F
     0x09b9: 0F [CD C5]  |   RRC
     0x09ba: CD [C5 09]  |   CAL 0x09C5
     0x09bb: C5 [09 F1]  |   PUSH B
     0x09bc: 09 [F1 E6]  |   DAD B
     0x09bd: F1 [E6 0F]  |   POP PSW
     0x09be: E6 [0F CD]  |   ANI 0x0F
     0x09bf: 0F [CD C5]  |   RRC
     0x09c0: CD [C5 09]  |   CAL 0x09C5
     0x09c1: C5 [09 D1]  |   PUSH B
     0x09c2: 09 [D1 C9]  |   DAD B
     0x09c3: D1 [C9 C6]  |   POP D
     0x09c4: C9 [C6 1A]  |   RET
     0x09c5: C6 [1A C3]  |   ADI 0x1A
     0x09c6: 1A [C3 FF]  |   LDAX D
     0x09c7: C3 [FF 08]  |   JMP 0x08FF
     0x09c8: FF [08 3A]  |   RST 7
     0x09c9: 08 [3A 67]  |   Undefined instruction
     0x09ca: 3A [67 20]  |   LDA 0x2067
     0x09cb: 67 [20 0F]  |   MOV H, A
     0x09cc: 20 [0F 21]  |   Undefined instruction
     0x09cd: 0F [21 F8]  |   RRC
     0x09ce: 21 [F8 20]  |   LXI H, 0x20F8 
     0x09cf: F8 [20 D8]  |   RM
     0x09d0: 20 [D8 21]  |   Undefined instruction
     0x09d1: D8 [21 FC]  |   RC
     0x09d2: 21 [FC 20]  |   LXI H, 0x20FC 
     0x09d3: FC [20 C9]  |   CM 0xC920
     0x09d4: 20 [C9 21]  |   Undefined instruction
     0x09d5: C9 [21 02]  |   RET
     0x09d6: 21 [02 24]  |   LXI H, 0x2402 
     0x09d7: 02 [24 36]  |   STAX B
     0x09d8: 24 [36 00]  |   INR H
     0x09d9: 36 [00 23]  |   MVI M, 0x00
     0x09da: 00 [23 7D]  |   NOP
     0x09db: 23 [7D E6]  |   INX H
     0x09dc: 7D [E6 1F]  |   MOV A, L
     0x09dd: E6 [1F FE]  |   ANI 0x1F
     0x09de: 1F [FE 1C]  |   RAR
     0x09df: FE [1C DA]  |   CPI 0x1C
     0x09e0: 1C [DA E8]  |   INR E
     0x09e1: DA [E8 09]  |   JC 0x09E8
     0x09e2: E8 [09 11]  |   RPE
     0x09e3: 09 [11 06]  |   DAD B
     0x09e4: 11 [06 00]  |   LXI D, 0x0006 
     0x09e5: 06 [00 19]  |   MVI B, 0x00
     0x09e6: 00 [19 7C]  |   NOP
     0x09e7: 19 [7C FE]  |   DAD D
     0x09e8: 7C [FE 40]  |   MOV A, H
     0x09e9: FE [40 DA]  |   CPI 0x40
     0x09ea: 40 [DA D9]  |   MOV B, B
     0x09eb: DA [D9 09]  |   JC 0x09D9
     0x09ec: D9 [09 C9]  |   Undefined instruction
     0x09ed: 09 [C9 CD]  |   DAD B
     0x09ee: C9 [CD 3C]  |   RET
     0x09ef: CD [3C 0A]  |   CAL 0x0A3C
     0x09f0: 3C [0A AF]  |   INR A
     0x09f1: 0A [AF 32]  |   LDAX B
     0x09f2: AF [32 E9]  |   XRA A
     0x09f3: 32 [E9 20]  |   STA 0x20E9
     0x09f4: E9 [20 CD]  |   PCHL
     0x09f5: 20 [CD D6]  |   Undefined instruction
     0x09f6: CD [D6 09]  |   CAL 0x09D6
     0x09f7: D6 [09 3A]  |   SUI 0x09
     0x09f8: 09 [3A 67]  |   DAD B
     0x09f9: 3A [67 20]  |   LDA 0x2067
     0x09fa: 67 [20 F5]  |   MOV H, A
     0x09fb: 20 [F5 CD]  |   Undefined instruction
     0x09fc: F5 [CD E4]  |   PUSH PSW
     0x09fd: CD [E4 01]  |   CAL 0x01E4
     0x09fe: E4 [01 F1]  |   CPO 0xF101
     0x09ff: 01 [F1 32]  |   LXI B, 0x32F1 
     0x0a00: F1 [32 67]  |   POP PSW
     0x0a01: 32 [67 20]  |   STA 0x2067
     0x0a02: 67 [20 3A]  |   MOV H, A
     0x0a03: 20 [3A 67]  |   Undefined instruction
     0x0a04: 3A [67 20]  |   LDA 0x2067
     0x0a05: 67 [20 67]  |   MOV H, A
     0x0a06: 20 [67 E5]  |   Undefined instruction
     0x0a07: 67 [E5 2E]  |   MOV H, A
     0x0a08: E5 [2E FE]  |   PUSH H
     0x0a09: 2E [FE 7E]  |   MVI L, 0xFE
     0x0a0a: FE [7E E6]  |   CPI 0x7E
     0x0a0b: 7E [E6 07]  |   MOV A, M
     0x0a0c: E6 [07 3C]  |   ANI 0x07
     0x0a0d: 07 [3C 77]  |   RLC
     0x0a0e: 3C [77 21]  |   INR A
     0x0a0f: 77 [21 A2]  |   MOV M, A
     0x0a10: 21 [A2 1D]  |   LXI H, 0x1DA2 
     0x0a11: A2 [1D 23]  |   ANA D
     0x0a12: 1D [23 3D]  |   DCR E
     0x0a13: 23 [3D C2]  |   INX H
     0x0a14: 3D [C2 13]  |   DCR A
     0x0a15: C2 [13 0A]  |   JNZ 0x0A13
     0x0a16: 13 [0A 7E]  |   INX D
     0x0a17: 0A [7E E1]  |   LDAX B
     0x0a18: 7E [E1 2E]  |   MOV A, M
     0x0a19: E1 [2E FC]  |   POP H
     0x0a1a: 2E [FC 77]  |   MVI L, 0xFC
     0x0a1b: FC [77 23]  |   CM 0x2377
     0x0a1c: 77 [23 36]  |   MOV M, A
     0x0a1d: 23 [36 38]  |   INX H
     0x0a1e: 36 [38 7C]  |   MVI M, 0x38
     0x0a1f: 38 [7C 0F]  |   Undefined instruction
     0x0a20: 7C [0F DA]  |   MOV A, H
     0x0a21: 0F [DA 33]  |   RRC
     0x0a22: DA [33 0A]  |   JC 0x0A33
     0x0a23: 33 [0A 3E]  |   INX SP
     0x0a24: 0A [3E 21]  |   LDAX B
     0x0a25: 3E [21 32]  |   MVI A, 0x21
     0x0a26: 21 [32 98]  |   LXI H, 0x9832 
     0x0a27: 32 [98 20]  |   STA 0x2098
     0x0a28: 98 [20 CD]  |   SBB B
     0x0a29: 20 [CD F5]  |   Undefined instruction
     0x0a2a: CD [F5 01]  |   CAL 0x01F5
     0x0a2b: F5 [01 CD]  |   PUSH PSW
     0x0a2c: 01 [CD 04]  |   LXI B, 0x04CD 
     0x0a2d: CD [04 19]  |   CAL 0x1904
     0x0a2e: 04 [19 C3]  |   INR B
     0x0a2f: 19 [C3 04]  |   DAD D
     0x0a30: C3 [04 08]  |   JMP 0x0804
     0x0a31: 04 [08 CD]  |   INR B
     0x0a32: 08 [CD EF]  |   Undefined instruction
     0x0a33: CD [EF 01]  |   CAL 0x01EF
     0x0a34: EF [01 CD]  |   RST 5
     0x0a35: 01 [CD C0]  |   LXI B, 0xC0CD 
     0x0a36: CD [C0 01]  |   CAL 0x01C0
     0x0a37: C0 [01 C3]  |   RNZ
     0x0a38: 01 [C3 04]  |   LXI B, 0x04C3 
     0x0a39: C3 [04 08]  |   JMP 0x0804
     0x0a3a: 04 [08 CD]  |   INR B
     0x0a3b: 08 [CD 59]  |   Undefined instruction
     0x0a3c: CD [59 0A]  |   CAL 0x0A59
     0x0a3d: 59 [0A C2]  |   MOV E, C
     0x0a3e: 0A [C2 52]  |   LDAX B
     0x0a3f: C2 [52 0A]  |   JNZ 0x0A52
     0x0a40: 52 [0A 3E]  |   MOV D, D
     0x0a41: 0A [3E 30]  |   LDAX B
     0x0a42: 3E [30 32]  |   MVI A, 0x30
     0x0a43: 30 [32 C0]  |   Undefined instruction
     0x0a44: 32 [C0 20]  |   STA 0x20C0
     0x0a45: C0 [20 3A]  |   RNZ
     0x0a46: 20 [3A C0]  |   Undefined instruction
     0x0a47: 3A [C0 20]  |   LDA 0x20C0
     0x0a48: C0 [20 A7]  |   RNZ
     0x0a49: 20 [A7 C8]  |   Undefined instruction
     0x0a4a: A7 [C8 CD]  |   ANA A
     0x0a4b: C8 [CD 59]  |   RZ
     0x0a4c: CD [59 0A]  |   CAL 0x0A59
     0x0a4d: 59 [0A CA]  |   MOV E, C
     0x0a4e: 0A [CA 47]  |   LDAX B
     0x0a4f: CA [47 0A]  |   JZ 0x0A47
     0x0a50: 47 [0A CD]  |   MOV B, A
     0x0a51: 0A [CD 59]  |   LDAX B
     0x0a52: CD [59 0A]  |   CAL 0x0A59
     0x0a53: 59 [0A C2]  |   MOV E, C
     0x0a54: 0A [C2 52]  |   LDAX B
     0x0a55: C2 [52 0A]  |   JNZ 0x0A52
     0x0a56: 52 [0A C9]  |   MOV D, D
     0x0a57: 0A [C9 3A]  |   LDAX B
     0x0a58: C9 [3A 15]  |   RET
     0x0a59: 3A [15 20]  |   LDA 0x2015
     0x0a5a: 15 [20 FE]  |   DCR D
     0x0a5b: 20 [FE FF]  |   Undefined instruction
     0x0a5c: FE [FF C9]  |   CPI 0xFF
     0x0a5d: FF [C9 3A]  |   RST 7
     0x0a5e: C9 [3A EF]  |   RET
     0x0a5f: 3A [EF 20]  |   LDA 0x20EF
     0x0a60: EF [20 A7]  |   RST 5
     0x0a61: 20 [A7 CA]  |   Undefined instruction
     0x0a62: A7 [CA 7C]  |   ANA A
     0x0a63: CA [7C 0A]  |   JZ 0x0A7C
     0x0a64: 7C [0A 48]  |   MOV A, H
     0x0a65: 0A [48 06]  |   LDAX B
     0x0a66: 48 [06 08]  |   MOV C, B
     0x0a67: 06 [08 CD]  |   MVI B, 0x08
     0x0a68: 08 [CD FA]  |   Undefined instruction
     0x0a69: CD [FA 18]  |   CAL 0x18FA
     0x0a6a: FA [18 41]  |   JM 0x4118
     0x0a6b: 18 [41 78]  |   Undefined instruction
     0x0a6c: 41 [78 CD]  |   MOV B, C
     0x0a6d: 78 [CD 7C]  |   MOV A, B
     0x0a6e: CD [7C 09]  |   CAL 0x097C
     0x0a6f: 7C [09 7E]  |   MOV A, H
     0x0a70: 09 [7E 21]  |   DAD B
     0x0a71: 7E [21 F3]  |   MOV A, M
     0x0a72: 21 [F3 20]  |   LXI H, 0x20F3 
     0x0a73: F3 [20 36]  |   DI
     0x0a74: 20 [36 00]  |   Undefined instruction
     0x0a75: 36 [00 2B]  |   MVI M, 0x00
     0x0a76: 00 [2B 77]  |   NOP
     0x0a77: 2B [77 2B]  |   DCX H
     0x0a78: 77 [2B 36]  |   MOV M, A
     0x0a79: 2B [36 01]  |   DCX H
     0x0a7a: 36 [01 21]  |   MVI M, 0x01
     0x0a7b: 01 [21 62]  |   LXI B, 0x6221 
     0x0a7c: 21 [62 20]  |   LXI H, 0x2062 
     0x0a7d: 62 [20 C9]  |   MOV H, D
     0x0a7e: 20 [C9 3E]  |   Undefined instruction
     0x0a7f: C9 [3E 02]  |   RET
     0x0a80: 3E [02 32]  |   MVI A, 0x02
     0x0a81: 02 [32 C1]  |   STAX B
     0x0a82: 32 [C1 20]  |   STA 0x20C1
     0x0a83: C1 [20 D3]  |   POP B
     0x0a84: 20 [D3 06]  |   Undefined instruction
     0x0a85: D3 [06 3A]  |   OUT 0x06
     0x0a86: 06 [3A CB]  |   MVI B, 0x3A
     0x0a87: 3A [CB 20]  |   LDA 0x20CB
     0x0a88: CB [20 A7]  |   Undefined instruction
     0x0a89: 20 [A7 CA]  |   Undefined instruction
     0x0a8a: A7 [CA 85]  |   ANA A
     0x0a8b: CA [85 0A]  |   JZ 0x0A85
     0x0a8c: 85 [0A AF]  |   ADD L
     0x0a8d: 0A [AF 32]  |   LDAX B
     0x0a8e: AF [32 C1]  |   XRA A
     0x0a8f: 32 [C1 20]  |   STA 0x20C1
     0x0a90: C1 [20 C9]  |   POP B
     0x0a91: 20 [C9 D5]  |   Undefined instruction
     0x0a92: C9 [D5 1A]  |   RET
     0x0a93: D5 [1A CD]  |   PUSH D
     0x0a94: 1A [CD FF]  |   LDAX D
     0x0a95: CD [FF 08]  |   CAL 0x08FF
     0x0a96: FF [08 D1]  |   RST 7
     0x0a97: 08 [D1 3E]  |   Undefined instruction
     0x0a98: D1 [3E 07]  |   POP D
     0x0a99: 3E [07 32]  |   MVI A, 0x07
     0x0a9a: 07 [32 C0]  |   RLC
     0x0a9b: 32 [C0 20]  |   STA 0x20C0
     0x0a9c: C0 [20 3A]  |   RNZ
     0x0a9d: 20 [3A C0]  |   Undefined instruction
     0x0a9e: 3A [C0 20]  |   LDA 0x20C0
     0x0a9f: C0 [20 3D]  |   RNZ
     0x0aa0: 20 [3D C2]  |   Undefined instruction
     0x0aa1: 3D [C2 9E]  |   DCR A
     0x0aa2: C2 [9E 0A]  |   JNZ 0x0A9E
     0x0aa3: 9E [0A 13]  |   SBB M
     0x0aa4: 0A [13 0D]  |   LDAX B
     0x0aa5: 13 [0D C2]  |   INX D
     0x0aa6: 0D [C2 93]  |   DCR C
     0x0aa7: C2 [93 0A]  |   JNZ 0x0A93
     0x0aa8: 93 [0A C9]  |   SUB E
     0x0aa9: 0A [C9 21]  |   LDAX B
     0x0aaa: C9 [21 50]  |   RET
     0x0aab: 21 [50 20]  |   LXI H, 0x2050 
     0x0aac: 50 [20 C3]  |   MOV D, B
     0x0aad: 20 [C3 4B]  |   Undefined instruction
     0x0aae: C3 [4B 02]  |   JMP 0x024B
     0x0aaf: 4B [02 3E]  |   MOV C, E
     0x0ab0: 02 [3E 40]  |   STAX B
     0x0ab1: 3E [40 C3]  |   MVI A, 0x40
     0x0ab2: 40 [C3 D7]  |   MOV B, B
     0x0ab3: C3 [D7 0A]  |   JMP 0x0AD7
     0x0ab4: D7 [0A 3E]  |   RST 2
     0x0ab5: 0A [3E 80]  |   LDAX B
     0x0ab6: 3E [80 C3]  |   MVI A, 0x80
     0x0ab7: 80 [C3 D7]  |   ADD B
     0x0ab8: C3 [D7 0A]  |   JMP 0x0AD7
     0x0ab9: D7 [0A E1]  |   RST 2
     0x0aba: 0A [E1 C3]  |   LDAX B
     0x0abb: E1 [C3 72]  |   POP H
     0x0abc: C3 [72 00]  |   JMP 0x0072
     0x0abd: 72 [00 3A]  |   MOV M, D
     0x0abe: 00 [3A C1]  |   NOP
     0x0abf: 3A [C1 20]  |   LDA 0x20C1
     0x0ac0: C1 [20 0F]  |   POP B
     0x0ac1: 20 [0F DA]  |   Undefined instruction
     0x0ac2: 0F [DA BB]  |   RRC
     0x0ac3: DA [BB 0A]  |   JC 0x0ABB
     0x0ac4: BB [0A 0F]  |   CMP E
     0x0ac5: 0A [0F DA]  |   LDAX B
     0x0ac6: 0F [DA 68]  |   RRC
     0x0ac7: DA [68 18]  |   JC 0x1868
     0x0ac8: 68 [18 0F]  |   MOV L, B
     0x0ac9: 18 [0F DA]  |   Undefined instruction
     0x0aca: 0F [DA AB]  |   RRC
     0x0acb: DA [AB 0A]  |   JC 0x0AAB
     0x0acc: AB [0A C9]  |   XRA E
     0x0acd: 0A [C9 21]  |   LDAX B
     0x0ace: C9 [21 14]  |   RET
     0x0acf: 21 [14 2B]  |   LXI H, 0x2B14 
     0x0ad0: 14 [2B 0E]  |   INR D
     0x0ad1: 2B [0E 0F]  |   DCX H
     0x0ad2: 0E [0F C3]  |   MVI C, 0x0F
     0x0ad3: 0F [C3 93]  |   RRC
     0x0ad4: C3 [93 0A]  |   JMP 0x0A93
     0x0ad5: 93 [0A 32]  |   SUB E
     0x0ad6: 0A [32 C0]  |   LDAX B
     0x0ad7: 32 [C0 20]  |   STA 0x20C0
     0x0ad8: C0 [20 3A]  |   RNZ
     0x0ad9: 20 [3A C0]  |   Undefined instruction
     0x0ada: 3A [C0 20]  |   LDA 0x20C0
     0x0adb: C0 [20 A7]  |   RNZ
     0x0adc: 20 [A7 C2]  |   Undefined instruction
     0x0add: A7 [C2 DA]  |   ANA A
     0x0ade: C2 [DA 0A]  |   JNZ 0x0ADA
     0x0adf: DA [0A C9]  |   JC 0xC90A
     0x0ae0: 0A [C9 21]  |   LDAX B
     0x0ae1: C9 [21 C2]  |   RET
     0x0ae2: 21 [C2 20]  |   LXI H, 0x20C2 
     0x0ae3: C2 [20 06]  |   JNZ 0x0620
     0x0ae4: 20 [06 0C]  |   Undefined instruction
     0x0ae5: 06 [0C C3]  |   MVI B, 0x0C
     0x0ae6: 0C [C3 32]  |   INR C
     0x0ae7: C3 [32 1A]  |   JMP 0x1A32
     0x0ae8: 32 [1A AF]  |   STA 0xAF1A
     0x0ae9: 1A [AF D3]  |   LDAX D
     0x0aea: AF [D3 03]  |   XRA A
     0x0aeb: D3 [03 D3]  |   OUT 0x03
     0x0aec: 03 [D3 05]  |   INX B
     0x0aed: D3 [05 CD]  |   OUT 0x05
     0x0aee: 05 [CD 82]  |   DCR B
     0x0aef: CD [82 19]  |   CAL 0x1982
     0x0af0: 82 [19 FB]  |   ADD D
     0x0af1: 19 [FB CD]  |   DAD D
     0x0af2: FB [CD B1]  |   EI
     0x0af3: CD [B1 0A]  |   CAL 0x0AB1
     0x0af4: B1 [0A 3A]  |   ORA C
     0x0af5: 0A [3A EC]  |   LDAX B
     0x0af6: 3A [EC 20]  |   LDA 0x20EC
     0x0af7: EC [20 A7]  |   CPE 0xA720
     0x0af8: 20 [A7 21]  |   Undefined instruction
     0x0af9: A7 [21 17]  |   ANA A
     0x0afa: 21 [17 30]  |   LXI H, 0x3017 
     0x0afb: 17 [30 0E]  |   RAL
     0x0afc: 30 [0E 04]  |   Undefined instruction
     0x0afd: 0E [04 C2]  |   MVI C, 0x04
     0x0afe: 04 [C2 E8]  |   INR B
     0x0aff: C2 [E8 0B]  |   JNZ 0x0BE8
     0x0b00: E8 [0B 11]  |   RPE
     0x0b01: 0B [11 FA]  |   DCX B
     0x0b02: 11 [FA 1C]  |   LXI D, 0x1CFA 
     0x0b03: FA [1C CD]  |   JM 0xCD1C
     0x0b04: 1C [CD 93]  |   INR E
     0x0b05: CD [93 0A]  |   CAL 0x0A93
     0x0b06: 93 [0A 11]  |   SUB E
     0x0b07: 0A [11 AF]  |   LDAX B
     0x0b08: 11 [AF 1D]  |   LXI D, 0x1DAF 
     0x0b09: AF [1D CD]  |   XRA A
     0x0b0a: 1D [CD CF]  |   DCR E
     0x0b0b: CD [CF 0A]  |   CAL 0x0ACF
     0x0b0c: CF [0A CD]  |   RST 1
     0x0b0d: 0A [CD B1]  |   LDAX B
     0x0b0e: CD [B1 0A]  |   CAL 0x0AB1
     0x0b0f: B1 [0A CD]  |   ORA C
     0x0b10: 0A [CD 15]  |   LDAX B
     0x0b11: CD [15 18]  |   CAL 0x1815
     0x0b12: 15 [18 CD]  |   DCR D
     0x0b13: 18 [CD B6]  |   Undefined instruction
     0x0b14: CD [B6 0A]  |   CAL 0x0AB6
     0x0b15: B6 [0A 3A]  |   ORA M
     0x0b16: 0A [3A EC]  |   LDAX B
     0x0b17: 3A [EC 20]  |   LDA 0x20EC
     0x0b18: EC [20 A7]  |   CPE 0xA720
     0x0b19: 20 [A7 C2]  |   Undefined instruction
     0x0b1a: A7 [C2 4A]  |   ANA A
     0x0b1b: C2 [4A 0B]  |   JNZ 0x0B4A
     0x0b1c: 4A [0B 11]  |   MOV C, D
     0x0b1d: 0B [11 95]  |   DCX B
     0x0b1e: 11 [95 1A]  |   LXI D, 0x1A95 
     0x0b1f: 95 [1A CD]  |   SUB L
     0x0b20: 1A [CD E2]  |   LDAX D
     0x0b21: CD [E2 0A]  |   CAL 0x0AE2
     0x0b22: E2 [0A CD]  |   JPO 0xCD0A
     0x0b23: 0A [CD 80]  |   LDAX B
     0x0b24: CD [80 0A]  |   CAL 0x0A80
     0x0b25: 80 [0A 11]  |   ADD B
     0x0b26: 0A [11 B0]  |   LDAX B
     0x0b27: 11 [B0 1B]  |   LXI D, 0x1BB0 
     0x0b28: B0 [1B CD]  |   ORA B
     0x0b29: 1B [CD E2]  |   DCX D
     0x0b2a: CD [E2 0A]  |   CAL 0x0AE2
     0x0b2b: E2 [0A CD]  |   JPO 0xCD0A
     0x0b2c: 0A [CD 80]  |   LDAX B
     0x0b2d: CD [80 0A]  |   CAL 0x0A80
     0x0b2e: 80 [0A CD]  |   ADD B
     0x0b2f: 0A [CD B1]  |   LDAX B
     0x0b30: CD [B1 0A]  |   CAL 0x0AB1
     0x0b31: B1 [0A 11]  |   ORA C
     0x0b32: 0A [11 C9]  |   LDAX B
     0x0b33: 11 [C9 1F]  |   LXI D, 0x1FC9 
     0x0b34: C9 [1F CD]  |   RET
     0x0b35: 1F [CD E2]  |   RAR
     0x0b36: CD [E2 0A]  |   CAL 0x0AE2
     0x0b37: E2 [0A CD]  |   JPO 0xCD0A
     0x0b38: 0A [CD 80]  |   LDAX B
     0x0b39: CD [80 0A]  |   CAL 0x0A80
     0x0b3a: 80 [0A CD]  |   ADD B
     0x0b3b: 0A [CD B1]  |   LDAX B
     0x0b3c: CD [B1 0A]  |   CAL 0x0AB1
     0x0b3d: B1 [0A 21]  |   ORA C
     0x0b3e: 0A [21 B7]  |   LDAX B
     0x0b3f: 21 [B7 33]  |   LXI H, 0x33B7 
     0x0b40: B7 [33 06]  |   ORA A
     0x0b41: 33 [06 0A]  |   INX SP
     0x0b42: 06 [0A CD]  |   MVI B, 0x0A
     0x0b43: 0A [CD CB]  |   LDAX B
     0x0b44: CD [CB 14]  |   CAL 0x14CB
     0x0b45: CB [14 CD]  |   Undefined instruction
     0x0b46: 14 [CD B6]  |   INR D
     0x0b47: CD [B6 0A]  |   CAL 0x0AB6
     0x0b48: B6 [0A CD]  |   ORA M
     0x0b49: 0A [CD D6]  |   LDAX B
     0x0b4a: CD [D6 09]  |   CAL 0x09D6
     0x0b4b: D6 [09 3A]  |   SUI 0x09
     0x0b4c: 09 [3A FF]  |   DAD B
     0x0b4d: 3A [FF 21]  |   LDA 0x21FF
     0x0b4e: FF [21 A7]  |   RST 7
     0x0b4f: 21 [A7 C2]  |   LXI H, 0xC2A7 
     0x0b50: A7 [C2 5D]  |   ANA A
     0x0b51: C2 [5D 0B]  |   JNZ 0x0B5D
     0x0b52: 5D [0B CD]  |   MOV E, L
     0x0b53: 0B [CD D1]  |   DCX B
     0x0b54: CD [D1 08]  |   CAL 0x08D1
     0x0b55: D1 [08 32]  |   POP D
     0x0b56: 08 [32 FF]  |   Undefined instruction
     0x0b57: 32 [FF 21]  |   STA 0x21FF
     0x0b58: FF [21 CD]  |   RST 7
     0x0b59: 21 [CD 7F]  |   LXI H, 0x7FCD 
     0x0b5a: CD [7F 1A]  |   CAL 0x1A7F
     0x0b5b: 7F [1A CD]  |   MOV A, A
     0x0b5c: 1A [CD E4]  |   LDAX D
     0x0b5d: CD [E4 01]  |   CAL 0x01E4
     0x0b5e: E4 [01 CD]  |   CPO 0xCD01
     0x0b5f: 01 [CD C0]  |   LXI B, 0xC0CD 
     0x0b60: CD [C0 01]  |   CAL 0x01C0
     0x0b61: C0 [01 CD]  |   RNZ
     0x0b62: 01 [CD EF]  |   LXI B, 0xEFCD 
     0x0b63: CD [EF 01]  |   CAL 0x01EF
     0x0b64: EF [01 CD]  |   RST 5
     0x0b65: 01 [CD 1A]  |   LXI B, 0x1ACD 
     0x0b66: CD [1A 02]  |   CAL 0x021A
     0x0b67: 1A [02 3E]  |   LDAX D
     0x0b68: 02 [3E 01]  |   STAX B
     0x0b69: 3E [01 32]  |   MVI A, 0x01
     0x0b6a: 01 [32 C1]  |   LXI B, 0xC132 
     0x0b6b: 32 [C1 20]  |   STA 0x20C1
     0x0b6c: C1 [20 CD]  |   POP B
     0x0b6d: 20 [CD CF]  |   Undefined instruction
     0x0b6e: CD [CF 01]  |   CAL 0x01CF
     0x0b6f: CF [01 CD]  |   RST 1
     0x0b70: 01 [CD 18]  |   LXI B, 0x18CD 
     0x0b71: CD [18 16]  |   CAL 0x1618
     0x0b72: 18 [16 CD]  |   Undefined instruction
     0x0b73: 16 [CD F1]  |   MVI D, 0xCD
     0x0b74: CD [F1 0B]  |   CAL 0x0BF1
     0x0b75: F1 [0B D3]  |   POP PSW
     0x0b76: 0B [D3 06]  |   DCX B
     0x0b77: D3 [06 CD]  |   OUT 0x06
     0x0b78: 06 [CD 59]  |   MVI B, 0xCD
     0x0b79: CD [59 0A]  |   CAL 0x0A59
     0x0b7a: 59 [0A CA]  |   MOV E, C
     0x0b7b: 0A [CA 71]  |   LDAX B
     0x0b7c: CA [71 0B]  |   JZ 0x0B71
     0x0b7d: 71 [0B AF]  |   MOV M, C
     0x0b7e: 0B [AF 32]  |   DCX B
     0x0b7f: AF [32 25]  |   XRA A
     0x0b80: 32 [25 20]  |   STA 0x2025
     0x0b81: 25 [20 CD]  |   DCR H
     0x0b82: 20 [CD 59]  |   Undefined instruction
     0x0b83: CD [59 0A]  |   CAL 0x0A59
     0x0b84: 59 [0A C2]  |   MOV E, C
     0x0b85: 0A [C2 83]  |   LDAX B
     0x0b86: C2 [83 0B]  |   JNZ 0x0B83
     0x0b87: 83 [0B AF]  |   ADD E
     0x0b88: 0B [AF 32]  |   DCX B
     0x0b89: AF [32 C1]  |   XRA A
     0x0b8a: 32 [C1 20]  |   STA 0x20C1
     0x0b8b: C1 [20 CD]  |   POP B
     0x0b8c: 20 [CD B1]  |   Undefined instruction
     0x0b8d: CD [B1 0A]  |   CAL 0x0AB1
     0x0b8e: B1 [0A CD]  |   ORA C
     0x0b8f: 0A [CD 88]  |   LDAX B
     0x0b90: CD [88 19]  |   CAL 0x1988
     0x0b91: 88 [19 0E]  |   ADC B
     0x0b92: 19 [0E 0C]  |   DAD D
     0x0b93: 0E [0C 21]  |   MVI C, 0x0C
     0x0b94: 0C [21 11]  |   INR C
     0x0b95: 21 [11 2C]  |   LXI H, 0x2C11 
     0x0b96: 11 [2C 11]  |   LXI D, 0x112C 
     0x0b97: 2C [11 90]  |   INR L
     0x0b98: 11 [90 1F]  |   LXI D, 0x1F90 
     0x0b99: 90 [1F CD]  |   SUB B
     0x0b9a: 1F [CD F3]  |   RAR
     0x0b9b: CD [F3 08]  |   CAL 0x08F3
     0x0b9c: F3 [08 3A]  |   DI
     0x0b9d: 08 [3A EC]  |   Undefined instruction
     0x0b9e: 3A [EC 20]  |   LDA 0x20EC
     0x0b9f: EC [20 FE]  |   CPE 0xFE20
     0x0ba0: 20 [FE 00]  |   Undefined instruction
     0x0ba1: FE [00 C2]  |   CPI 0x00
     0x0ba2: 00 [C2 AE]  |   NOP
     0x0ba3: C2 [AE 0B]  |   JNZ 0x0BAE
     0x0ba4: AE [0B 21]  |   XRA M
     0x0ba5: 0B [21 11]  |   DCX B
     0x0ba6: 21 [11 33]  |   LXI H, 0x3311 
     0x0ba7: 11 [33 3E]  |   LXI D, 0x3E33 
     0x0ba8: 33 [3E 02]  |   INX SP
     0x0ba9: 3E [02 CD]  |   MVI A, 0x02
     0x0baa: 02 [CD FF]  |   STAX B
     0x0bab: CD [FF 08]  |   CAL 0x08FF
     0x0bac: FF [08 01]  |   RST 7
     0x0bad: 08 [01 9C]  |   Undefined instruction
     0x0bae: 01 [9C 1F]  |   LXI B, 0x1F9C 
     0x0baf: 9C [1F CD]  |   SBB H
     0x0bb0: 1F [CD 56]  |   RAR
     0x0bb1: CD [56 18]  |   CAL 0x1856
     0x0bb2: 56 [18 CD]  |   MOV D, M
     0x0bb3: 18 [CD 4C]  |   Undefined instruction
     0x0bb4: CD [4C 18]  |   CAL 0x184C
     0x0bb5: 4C [18 DB]  |   MOV C, H
     0x0bb6: 18 [DB 02]  |   Undefined instruction
     0x0bb7: DB [02 07]  |   IN 0x02
     0x0bb8: 02 [07 DA]  |   STAX B
     0x0bb9: 07 [DA C3]  |   RLC
     0x0bba: DA [C3 0B]  |   JC 0x0BC3
     0x0bbb: C3 [0B 01]  |   JMP 0x010B
     0x0bbc: 0B [01 A0]  |   DCX B
     0x0bbd: 01 [A0 1F]  |   LXI B, 0x1FA0 
     0x0bbe: A0 [1F CD]  |   ANA B
     0x0bbf: 1F [CD 3A]  |   RAR
     0x0bc0: CD [3A 18]  |   CAL 0x183A
     0x0bc1: 3A [18 CD]  |   LDA 0xCD18
     0x0bc2: 18 [CD B6]  |   Undefined instruction
     0x0bc3: CD [B6 0A]  |   CAL 0x0AB6
     0x0bc4: B6 [0A 3A]  |   ORA M
     0x0bc5: 0A [3A EC]  |   LDAX B
     0x0bc6: 3A [EC 20]  |   LDA 0x20EC
     0x0bc7: EC [20 FE]  |   CPE 0xFE20
     0x0bc8: 20 [FE 00]  |   Undefined instruction
     0x0bc9: FE [00 C2]  |   CPI 0x00
     0x0bca: 00 [C2 DA]  |   NOP
     0x0bcb: C2 [DA 0B]  |   JNZ 0x0BDA
     0x0bcc: DA [0B 11]  |   JC 0x110B
     0x0bcd: 0B [11 D5]  |   DCX B
     0x0bce: 11 [D5 1F]  |   LXI D, 0x1FD5 
     0x0bcf: D5 [1F CD]  |   PUSH D
     0x0bd0: 1F [CD E2]  |   RAR
     0x0bd1: CD [E2 0A]  |   CAL 0x0AE2
     0x0bd2: E2 [0A CD]  |   JPO 0xCD0A
     0x0bd3: 0A [CD 80]  |   LDAX B
     0x0bd4: CD [80 0A]  |   CAL 0x0A80
     0x0bd5: 80 [0A CD]  |   ADD B
     0x0bd6: 0A [CD 9E]  |   LDAX B
     0x0bd7: CD [9E 18]  |   CAL 0x189E
     0x0bd8: 9E [18 21]  |   SBB M
     0x0bd9: 18 [21 EC]  |   Undefined instruction
     0x0bda: 21 [EC 20]  |   LXI H, 0x20EC 
     0x0bdb: EC [20 7E]  |   CPE 0x7E20
     0x0bdc: 20 [7E 3C]  |   Undefined instruction
     0x0bdd: 7E [3C E6]  |   MOV A, M
     0x0bde: 3C [E6 01]  |   INR A
     0x0bdf: E6 [01 77]  |   ANI 0x01
     0x0be0: 01 [77 CD]  |   LXI B, 0xCD77 
     0x0be1: 77 [CD D6]  |   MOV M, A
     0x0be2: CD [D6 09]  |   CAL 0x09D6
     0x0be3: D6 [09 C3]  |   SUI 0x09
     0x0be4: 09 [C3 DF]  |   DAD B
     0x0be5: C3 [DF 18]  |   JMP 0x18DF
     0x0be6: DF [18 11]  |   RST 3
     0x0be7: 18 [11 AB]  |   Undefined instruction
     0x0be8: 11 [AB 1D]  |   LXI D, 0x1DAB 
     0x0be9: AB [1D CD]  |   XRA E
     0x0bea: 1D [CD 93]  |   DCR E
     0x0beb: CD [93 0A]  |   CAL 0x0A93
     0x0bec: 93 [0A C3]  |   SUB E
     0x0bed: 0A [C3 0B]  |   LDAX B
     0x0bee: C3 [0B 0B]  |   JMP 0x0B0B
     0x0bef: 0B [0B CD]  |   DCX B
     0x0bf0: 0B [CD 0A]  |   DCX B
     0x0bf1: CD [0A 19]  |   CAL 0x190A
     0x0bf2: 0A [19 C3]  |   LDAX B
     0x0bf3: 19 [C3 9A]  |   DAD D
     0x0bf4: C3 [9A 19]  |   JMP 0x199A
     0x0bf5: 9A [19 13]  |   SBB D
     0x0bf6: 19 [13 00]  |   DAD D
     0x0bf7: 13 [00 08]  |   INX D
     0x0bf8: 00 [08 13]  |   NOP
     0x0bf9: 08 [13 0E]  |   Undefined instruction
     0x0bfa: 13 [0E 26]  |   INX D
     0x0bfb: 0E [26 02]  |   MVI C, 0x26
     0x0bfc: 26 [02 0E]  |   MVI H, 0x02
     0x0bfd: 02 [0E 0F]  |   STAX B
     0x0bfe: 0E [0F 00]  |   MVI C, 0x0F
     0x0bff: 0F [00 00]  |   RRC
     0x0c00: 00 [00 00]  |   NOP
     0x0c01: 00 [00 00]  |   NOP
     0x0c02: 00 [00 00]  |   NOP
     0x0c03: 00 [00 00]  |   NOP
     0x0c04: 00 [00 00]  |   NOP
     0x0c05: 00 [00 00]  |   NOP
     0x0c06: 00 [00 00]  |   NOP
     0x0c07: 00 [00 00]  |   NOP
     0x0c08: 00 [00 00]  |   NOP
     0x0c09: 00 [00 00]  |   NOP
     0x0c0a: 00 [00 00]  |   NOP
     0x0c0b: 00 [00 00]  |   NOP
     0x0c0c: 00 [00 00]  |   NOP
     0x0c0d: 00 [00 00]  |   NOP
     0x0c0e: 00 [00 00]  |   NOP
     0x0c0f: 00 [00 00]  |   NOP
     0x0c10: 00 [00 00]  |   NOP
     0x0c11: 00 [00 00]  |   NOP
     0x0c12: 00 [00 00]  |   NOP
     0x0c13: 00 [00 00]  |   NOP
     0x0c14: 00 [00 00]  |   NOP
     0x0c15: 00 [00 00]  |   NOP
     0x0c16: 00 [00 00]  |   NOP
     0x0c17: 00 [00 00]  |   NOP
     0x0c18: 00 [00 00]  |   NOP
     0x0c19: 00 [00 00]  |   NOP
     0x0c1a: 00 [00 00]  |   NOP
     0x0c1b: 00 [00 00]  |   NOP
     0x0c1c: 00 [00 00]  |   NOP
     0x0c1d: 00 [00 00]  |   NOP
     0x0c1e: 00 [00 00]  |   NOP
     0x0c1f: 00 [00 00]  |   NOP
     0x0c20: 00 [00 00]  |   NOP
     0x0c21: 00 [00 00]  |   NOP
     0x0c22: 00 [00 00]  |   NOP
     0x0c23: 00 [00 00]  |   NOP
     0x0c24: 00 [00 00]  |   NOP
     0x0c25: 00 [00 00]  |   NOP
     0x0c26: 00 [00 00]  |   NOP
     0x0c27: 00 [00 00]  |   NOP
     0x0c28: 00 [00 00]  |   NOP
     0x0c29: 00 [00 00]  |   NOP
     0x0c2a: 00 [00 00]  |   NOP
     0x0c2b: 00 [00 00]  |   NOP
     0x0c2c: 00 [00 00]  |   NOP
     0x0c2d: 00 [00 00]  |   NOP
     0x0c2e: 00 [00 00]  |   NOP
     0x0c2f: 00 [00 00]  |   NOP
     0x0c30: 00 [00 00]  |   NOP
     0x0c31: 00 [00 00]  |   NOP
     0x0c32: 00 [00 00]  |   NOP
     0x0c33: 00 [00 00]  |   NOP
     0x0c34: 00 [00 00]  |   NOP
     0x0c35: 00 [00 00]  |   NOP
     0x0c36: 00 [00 00]  |   NOP
     0x0c37: 00 [00 00]  |   NOP
     0x0c38: 00 [00 00]  |   NOP
     0x0c39: 00 [00 00]  |   NOP
     0x0c3a: 00 [00 00]  |   NOP
     0x0c3b: 00 [00 00]  |   NOP
     0x0c3c: 00 [00 00]  |   NOP
     0x0c3d: 00 [00 00]  |   NOP
     0x0c3e: 00 [00 00]  |   NOP
     0x0c3f: 00 [00 00]  |   NOP
     0x0c40: 00 [00 00]  |   NOP
     0x0c41: 00 [00 00]  |   NOP
     0x0c42: 00 [00 00]  |   NOP
     0x0c43: 00 [00 00]  |   NOP
     0x0c44: 00 [00 00]  |   NOP
     0x0c45: 00 [00 00]  |   NOP
     0x0c46: 00 [00 00]  |   NOP
     0x0c47: 00 [00 00]  |   NOP
     0x0c48: 00 [00 00]  |   NOP
     0x0c49: 00 [00 00]  |   NOP
     0x0c4a: 00 [00 00]  |   NOP
     0x0c4b: 00 [00 00]  |   NOP
     0x0c4c: 00 [00 00]  |   NOP
     0x0c4d: 00 [00 00]  |   NOP
     0x0c4e: 00 [00 00]  |   NOP
     0x0c4f: 00 [00 00]  |   NOP
     0x0c50: 00 [00 00]  |   NOP
     0x0c51: 00 [00 00]  |   NOP
     0x0c52: 00 [00 00]  |   NOP
     0x0c53: 00 [00 00]  |   NOP
     0x0c54: 00 [00 00]  |   NOP
     0x0c55: 00 [00 00]  |   NOP
     0x0c56: 00 [00 00]  |   NOP
     0x0c57: 00 [00 00]  |   NOP
     0x0c58: 00 [00 00]  |   NOP
     0x0c59: 00 [00 00]  |   NOP
     0x0c5a: 00 [00 00]  |   NOP
     0x0c5b: 00 [00 00]  |   NOP
     0x0c5c: 00 [00 00]  |   NOP
     0x0c5d: 00 [00 00]  |   NOP
     0x0c5e: 00 [00 00]  |   NOP
     0x0c5f: 00 [00 00]  |   NOP
     0x0c60: 00 [00 00]  |   NOP
     0x0c61: 00 [00 00]  |   NOP
     0x0c62: 00 [00 00]  |   NOP
     0x0c63: 00 [00 00]  |   NOP
     0x0c64: 00 [00 00]  |   NOP
     0x0c65: 00 [00 00]  |   NOP
     0x0c66: 00 [00 00]  |   NOP
     0x0c67: 00 [00 00]  |   NOP
     0x0c68: 00 [00 00]  |   NOP
     0x0c69: 00 [00 00]  |   NOP
     0x0c6a: 00 [00 00]  |   NOP
     0x0c6b: 00 [00 00]  |   NOP
     0x0c6c: 00 [00 00]  |   NOP
     0x0c6d: 00 [00 00]  |   NOP
     0x0c6e: 00 [00 00]  |   NOP
     0x0c6f: 00 [00 00]  |   NOP
     0x0c70: 00 [00 00]  |   NOP
     0x0c71: 00 [00 00]  |   NOP
     0x0c72: 00 [00 00]  |   NOP
     0x0c73: 00 [00 00]  |   NOP
     0x0c74: 00 [00 00]  |   NOP
     0x0c75: 00 [00 00]  |   NOP
     0x0c76: 00 [00 00]  |   NOP
     0x0c77: 00 [00 00]  |   NOP
     0x0c78: 00 [00 00]  |   NOP
     0x0c79: 00 [00 00]  |   NOP
     0x0c7a: 00 [00 00]  |   NOP
     0x0c7b: 00 [00 00]  |   NOP
     0x0c7c: 00 [00 00]  |   NOP
     0x0c7d: 00 [00 00]  |   NOP
     0x0c7e: 00 [00 00]  |   NOP
     0x0c7f: 00 [00 00]  |   NOP
     0x0c80: 00 [00 00]  |   NOP
     0x0c81: 00 [00 00]  |   NOP
     0x0c82: 00 [00 00]  |   NOP
     0x0c83: 00 [00 00]  |   NOP
     0x0c84: 00 [00 00]  |   NOP
     0x0c85: 00 [00 00]  |   NOP
     0x0c86: 00 [00 00]  |   NOP
     0x0c87: 00 [00 00]  |   NOP
     0x0c88: 00 [00 00]  |   NOP
     0x0c89: 00 [00 00]  |   NOP
     0x0c8a: 00 [00 00]  |   NOP
     0x0c8b: 00 [00 00]  |   NOP
     0x0c8c: 00 [00 00]  |   NOP
     0x0c8d: 00 [00 00]  |   NOP
     0x0c8e: 00 [00 00]  |   NOP
     0x0c8f: 00 [00 00]  |   NOP
     0x0c90: 00 [00 00]  |   NOP
     0x0c91: 00 [00 00]  |   NOP
     0x0c92: 00 [00 00]  |   NOP
     0x0c93: 00 [00 00]  |   NOP
     0x0c94: 00 [00 00]  |   NOP
     0x0c95: 00 [00 00]  |   NOP
     0x0c96: 00 [00 00]  |   NOP
     0x0c97: 00 [00 00]  |   NOP
     0x0c98: 00 [00 00]  |   NOP
     0x0c99: 00 [00 00]  |   NOP
     0x0c9a: 00 [00 00]  |   NOP
     0x0c9b: 00 [00 00]  |   NOP
     0x0c9c: 00 [00 00]  |   NOP
     0x0c9d: 00 [00 00]  |   NOP
     0x0c9e: 00 [00 00]  |   NOP
     0x0c9f: 00 [00 00]  |   NOP
     0x0ca0: 00 [00 00]  |   NOP
     0x0ca1: 00 [00 00]  |   NOP
     0x0ca2: 00 [00 00]  |   NOP
     0x0ca3: 00 [00 00]  |   NOP
     0x0ca4: 00 [00 00]  |   NOP
     0x0ca5: 00 [00 00]  |   NOP
     0x0ca6: 00 [00 00]  |   NOP
     0x0ca7: 00 [00 00]  |   NOP
     0x0ca8: 00 [00 00]  |   NOP
     0x0ca9: 00 [00 00]  |   NOP
     0x0caa: 00 [00 00]  |   NOP
     0x0cab: 00 [00 00]  |   NOP
     0x0cac: 00 [00 00]  |   NOP
     0x0cad: 00 [00 00]  |   NOP
     0x0cae: 00 [00 00]  |   NOP
     0x0caf: 00 [00 00]  |   NOP
     0x0cb0: 00 [00 00]  |   NOP
     0x0cb1: 00 [00 00]  |   NOP
     0x0cb2: 00 [00 00]  |   NOP
     0x0cb3: 00 [00 00]  |   NOP
     0x0cb4: 00 [00 00]  |   NOP
     0x0cb5: 00 [00 00]  |   NOP
     0x0cb6: 00 [00 00]  |   NOP
     0x0cb7: 00 [00 00]  |   NOP
     0x0cb8: 00 [00 00]  |   NOP
     0x0cb9: 00 [00 00]  |   NOP
     0x0cba: 00 [00 00]  |   NOP
     0x0cbb: 00 [00 00]  |   NOP
     0x0cbc: 00 [00 00]  |   NOP
     0x0cbd: 00 [00 00]  |   NOP
     0x0cbe: 00 [00 00]  |   NOP
     0x0cbf: 00 [00 00]  |   NOP
     0x0cc0: 00 [00 00]  |   NOP
     0x0cc1: 00 [00 00]  |   NOP
     0x0cc2: 00 [00 00]  |   NOP
     0x0cc3: 00 [00 00]  |   NOP
     0x0cc4: 00 [00 00]  |   NOP
     0x0cc5: 00 [00 00]  |   NOP
     0x0cc6: 00 [00 00]  |   NOP
     0x0cc7: 00 [00 00]  |   NOP
     0x0cc8: 00 [00 00]  |   NOP
     0x0cc9: 00 [00 00]  |   NOP
     0x0cca: 00 [00 00]  |   NOP
     0x0ccb: 00 [00 00]  |   NOP
     0x0ccc: 00 [00 00]  |   NOP
     0x0ccd: 00 [00 00]  |   NOP
     0x0cce: 00 [00 00]  |   NOP
     0x0ccf: 00 [00 00]  |   NOP
     0x0cd0: 00 [00 00]  |   NOP
     0x0cd1: 00 [00 00]  |   NOP
     0x0cd2: 00 [00 00]  |   NOP
     0x0cd3: 00 [00 00]  |   NOP
     0x0cd4: 00 [00 00]  |   NOP
     0x0cd5: 00 [00 00]  |   NOP
     0x0cd6: 00 [00 00]  |   NOP
     0x0cd7: 00 [00 00]  |   NOP
     0x0cd8: 00 [00 00]  |   NOP
     0x0cd9: 00 [00 00]  |   NOP
     0x0cda: 00 [00 00]  |   NOP
     0x0cdb: 00 [00 00]  |   NOP
     0x0cdc: 00 [00 00]  |   NOP
     0x0cdd: 00 [00 00]  |   NOP
     0x0cde: 00 [00 00]  |   NOP
     0x0cdf: 00 [00 00]  |   NOP
     0x0ce0: 00 [00 00]  |   NOP
     0x0ce1: 00 [00 00]  |   NOP
     0x0ce2: 00 [00 00]  |   NOP
     0x0ce3: 00 [00 00]  |   NOP
     0x0ce4: 00 [00 00]  |   NOP
     0x0ce5: 00 [00 00]  |   NOP
     0x0ce6: 00 [00 00]  |   NOP
     0x0ce7: 00 [00 00]  |   NOP
     0x0ce8: 00 [00 00]  |   NOP
     0x0ce9: 00 [00 00]  |   NOP
     0x0cea: 00 [00 00]  |   NOP
     0x0ceb: 00 [00 00]  |   NOP
     0x0cec: 00 [00 00]  |   NOP
     0x0ced: 00 [00 00]  |   NOP
     0x0cee: 00 [00 00]  |   NOP
     0x0cef: 00 [00 00]  |   NOP
     0x0cf0: 00 [00 00]  |   NOP
     0x0cf1: 00 [00 00]  |   NOP
     0x0cf2: 00 [00 00]  |   NOP
     0x0cf3: 00 [00 00]  |   NOP
     0x0cf4: 00 [00 00]  |   NOP
     0x0cf5: 00 [00 00]  |   NOP
     0x0cf6: 00 [00 00]  |   NOP
     0x0cf7: 00 [00 00]  |   NOP
     0x0cf8: 00 [00 00]  |   NOP
     0x0cf9: 00 [00 00]  |   NOP
     0x0cfa: 00 [00 00]  |   NOP
     0x0cfb: 00 [00 00]  |   NOP
     0x0cfc: 00 [00 00]  |   NOP
     0x0cfd: 00 [00 00]  |   NOP
     0x0cfe: 00 [00 00]  |   NOP
     0x0cff: 00 [00 00]  |   NOP
     0x0d00: 00 [00 00]  |   NOP
     0x0d01: 00 [00 00]  |   NOP
     0x0d02: 00 [00 00]  |   NOP
     0x0d03: 00 [00 00]  |   NOP
     0x0d04: 00 [00 00]  |   NOP
     0x0d05: 00 [00 00]  |   NOP
     0x0d06: 00 [00 00]  |   NOP
     0x0d07: 00 [00 00]  |   NOP
     0x0d08: 00 [00 00]  |   NOP
     0x0d09: 00 [00 00]  |   NOP
     0x0d0a: 00 [00 00]  |   NOP
     0x0d0b: 00 [00 00]  |   NOP
     0x0d0c: 00 [00 00]  |   NOP
     0x0d0d: 00 [00 00]  |   NOP
     0x0d0e: 00 [00 00]  |   NOP
     0x0d0f: 00 [00 00]  |   NOP
     0x0d10: 00 [00 00]  |   NOP
     0x0d11: 00 [00 00]  |   NOP
     0x0d12: 00 [00 00]  |   NOP
     0x0d13: 00 [00 00]  |   NOP
     0x0d14: 00 [00 00]  |   NOP
     0x0d15: 00 [00 00]  |   NOP
     0x0d16: 00 [00 00]  |   NOP
     0x0d17: 00 [00 00]  |   NOP
     0x0d18: 00 [00 00]  |   NOP
     0x0d19: 00 [00 00]  |   NOP
     0x0d1a: 00 [00 00]  |   NOP
     0x0d1b: 00 [00 00]  |   NOP
     0x0d1c: 00 [00 00]  |   NOP
     0x0d1d: 00 [00 00]  |   NOP
     0x0d1e: 00 [00 00]  |   NOP
     0x0d1f: 00 [00 00]  |   NOP
     0x0d20: 00 [00 00]  |   NOP
     0x0d21: 00 [00 00]  |   NOP
     0x0d22: 00 [00 00]  |   NOP
     0x0d23: 00 [00 00]  |   NOP
     0x0d24: 00 [00 00]  |   NOP
     0x0d25: 00 [00 00]  |   NOP
     0x0d26: 00 [00 00]  |   NOP
     0x0d27: 00 [00 00]  |   NOP
     0x0d28: 00 [00 00]  |   NOP
     0x0d29: 00 [00 00]  |   NOP
     0x0d2a: 00 [00 00]  |   NOP
     0x0d2b: 00 [00 00]  |   NOP
     0x0d2c: 00 [00 00]  |   NOP
     0x0d2d: 00 [00 00]  |   NOP
     0x0d2e: 00 [00 00]  |   NOP
     0x0d2f: 00 [00 00]  |   NOP
     0x0d30: 00 [00 00]  |   NOP
     0x0d31: 00 [00 00]  |   NOP
     0x0d32: 00 [00 00]  |   NOP
     0x0d33: 00 [00 00]  |   NOP
     0x0d34: 00 [00 00]  |   NOP
     0x0d35: 00 [00 00]  |   NOP
     0x0d36: 00 [00 00]  |   NOP
     0x0d37: 00 [00 00]  |   NOP
     0x0d38: 00 [00 00]  |   NOP
     0x0d39: 00 [00 00]  |   NOP
     0x0d3a: 00 [00 00]  |   NOP
     0x0d3b: 00 [00 00]  |   NOP
     0x0d3c: 00 [00 00]  |   NOP
     0x0d3d: 00 [00 00]  |   NOP
     0x0d3e: 00 [00 00]  |   NOP
     0x0d3f: 00 [00 00]  |   NOP
     0x0d40: 00 [00 00]  |   NOP
     0x0d41: 00 [00 00]  |   NOP
     0x0d42: 00 [00 00]  |   NOP
     0x0d43: 00 [00 00]  |   NOP
     0x0d44: 00 [00 00]  |   NOP
     0x0d45: 00 [00 00]  |   NOP
     0x0d46: 00 [00 00]  |   NOP
     0x0d47: 00 [00 00]  |   NOP
     0x0d48: 00 [00 00]  |   NOP
     0x0d49: 00 [00 00]  |   NOP
     0x0d4a: 00 [00 00]  |   NOP
     0x0d4b: 00 [00 00]  |   NOP
     0x0d4c: 00 [00 00]  |   NOP
     0x0d4d: 00 [00 00]  |   NOP
     0x0d4e: 00 [00 00]  |   NOP
     0x0d4f: 00 [00 00]  |   NOP
     0x0d50: 00 [00 00]  |   NOP
     0x0d51: 00 [00 00]  |   NOP
     0x0d52: 00 [00 00]  |   NOP
     0x0d53: 00 [00 00]  |   NOP
     0x0d54: 00 [00 00]  |   NOP
     0x0d55: 00 [00 00]  |   NOP
     0x0d56: 00 [00 00]  |   NOP
     0x0d57: 00 [00 00]  |   NOP
     0x0d58: 00 [00 00]  |   NOP
     0x0d59: 00 [00 00]  |   NOP
     0x0d5a: 00 [00 00]  |   NOP
     0x0d5b: 00 [00 00]  |   NOP
     0x0d5c: 00 [00 00]  |   NOP
     0x0d5d: 00 [00 00]  |   NOP
     0x0d5e: 00 [00 00]  |   NOP
     0x0d5f: 00 [00 00]  |   NOP
     0x0d60: 00 [00 00]  |   NOP
     0x0d61: 00 [00 00]  |   NOP
     0x0d62: 00 [00 00]  |   NOP
     0x0d63: 00 [00 00]  |   NOP
     0x0d64: 00 [00 00]  |   NOP
     0x0d65: 00 [00 00]  |   NOP
     0x0d66: 00 [00 00]  |   NOP
     0x0d67: 00 [00 00]  |   NOP
     0x0d68: 00 [00 00]  |   NOP
     0x0d69: 00 [00 00]  |   NOP
     0x0d6a: 00 [00 00]  |   NOP
     0x0d6b: 00 [00 00]  |   NOP
     0x0d6c: 00 [00 00]  |   NOP
     0x0d6d: 00 [00 00]  |   NOP
     0x0d6e: 00 [00 00]  |   NOP
     0x0d6f: 00 [00 00]  |   NOP
     0x0d70: 00 [00 00]  |   NOP
     0x0d71: 00 [00 00]  |   NOP
     0x0d72: 00 [00 00]  |   NOP
     0x0d73: 00 [00 00]  |   NOP
     0x0d74: 00 [00 00]  |   NOP
     0x0d75: 00 [00 00]  |   NOP
     0x0d76: 00 [00 00]  |   NOP
     0x0d77: 00 [00 00]  |   NOP
     0x0d78: 00 [00 00]  |   NOP
     0x0d79: 00 [00 00]  |   NOP
     0x0d7a: 00 [00 00]  |   NOP
     0x0d7b: 00 [00 00]  |   NOP
     0x0d7c: 00 [00 00]  |   NOP
     0x0d7d: 00 [00 00]  |   NOP
     0x0d7e: 00 [00 00]  |   NOP
     0x0d7f: 00 [00 00]  |   NOP
     0x0d80: 00 [00 00]  |   NOP
     0x0d81: 00 [00 00]  |   NOP
     0x0d82: 00 [00 00]  |   NOP
     0x0d83: 00 [00 00]  |   NOP
     0x0d84: 00 [00 00]  |   NOP
     0x0d85: 00 [00 00]  |   NOP
     0x0d86: 00 [00 00]  |   NOP
     0x0d87: 00 [00 00]  |   NOP
     0x0d88: 00 [00 00]  |   NOP
     0x0d89: 00 [00 00]  |   NOP
     0x0d8a: 00 [00 00]  |   NOP
     0x0d8b: 00 [00 00]  |   NOP
     0x0d8c: 00 [00 00]  |   NOP
     0x0d8d: 00 [00 00]  |   NOP
     0x0d8e: 00 [00 00]  |   NOP
     0x0d8f: 00 [00 00]  |   NOP
     0x0d90: 00 [00 00]  |   NOP
     0x0d91: 00 [00 00]  |   NOP
     0x0d92: 00 [00 00]  |   NOP
     0x0d93: 00 [00 00]  |   NOP
     0x0d94: 00 [00 00]  |   NOP
     0x0d95: 00 [00 00]  |   NOP
     0x0d96: 00 [00 00]  |   NOP
     0x0d97: 00 [00 00]  |   NOP
     0x0d98: 00 [00 00]  |   NOP
     0x0d99: 00 [00 00]  |   NOP
     0x0d9a: 00 [00 00]  |   NOP
     0x0d9b: 00 [00 00]  |   NOP
     0x0d9c: 00 [00 00]  |   NOP
     0x0d9d: 00 [00 00]  |   NOP
     0x0d9e: 00 [00 00]  |   NOP
     0x0d9f: 00 [00 00]  |   NOP
     0x0da0: 00 [00 00]  |   NOP
     0x0da1: 00 [00 00]  |   NOP
     0x0da2: 00 [00 00]  |   NOP
     0x0da3: 00 [00 00]  |   NOP
     0x0da4: 00 [00 00]  |   NOP
     0x0da5: 00 [00 00]  |   NOP
     0x0da6: 00 [00 00]  |   NOP
     0x0da7: 00 [00 00]  |   NOP
     0x0da8: 00 [00 00]  |   NOP
     0x0da9: 00 [00 00]  |   NOP
     0x0daa: 00 [00 00]  |   NOP
     0x0dab: 00 [00 00]  |   NOP
     0x0dac: 00 [00 00]  |   NOP
     0x0dad: 00 [00 00]  |   NOP
     0x0dae: 00 [00 00]  |   NOP
     0x0daf: 00 [00 00]  |   NOP
     0x0db0: 00 [00 00]  |   NOP
     0x0db1: 00 [00 00]  |   NOP
     0x0db2: 00 [00 00]  |   NOP
     0x0db3: 00 [00 00]  |   NOP
     0x0db4: 00 [00 00]  |   NOP
     0x0db5: 00 [00 00]  |   NOP
     0x0db6: 00 [00 00]  |   NOP
     0x0db7: 00 [00 00]  |   NOP
     0x0db8: 00 [00 00]  |   NOP
     0x0db9: 00 [00 00]  |   NOP
     0x0dba: 00 [00 00]  |   NOP
     0x0dbb: 00 [00 00]  |   NOP
     0x0dbc: 00 [00 00]  |   NOP
     0x0dbd: 00 [00 00]  |   NOP
     0x0dbe: 00 [00 00]  |   NOP
     0x0dbf: 00 [00 00]  |   NOP
     0x0dc0: 00 [00 00]  |   NOP
     0x0dc1: 00 [00 00]  |   NOP
     0x0dc2: 00 [00 00]  |   NOP
     0x0dc3: 00 [00 00]  |   NOP
     0x0dc4: 00 [00 00]  |   NOP
     0x0dc5: 00 [00 00]  |   NOP
     0x0dc6: 00 [00 00]  |   NOP
     0x0dc7: 00 [00 00]  |   NOP
     0x0dc8: 00 [00 00]  |   NOP
     0x0dc9: 00 [00 00]  |   NOP
     0x0dca: 00 [00 00]  |   NOP
     0x0dcb: 00 [00 00]  |   NOP
     0x0dcc: 00 [00 00]  |   NOP
     0x0dcd: 00 [00 00]  |   NOP
     0x0dce: 00 [00 00]  |   NOP
     0x0dcf: 00 [00 00]  |   NOP
     0x0dd0: 00 [00 00]  |   NOP
     0x0dd1: 00 [00 00]  |   NOP
     0x0dd2: 00 [00 00]  |   NOP
     0x0dd3: 00 [00 00]  |   NOP
     0x0dd4: 00 [00 00]  |   NOP
     0x0dd5: 00 [00 00]  |   NOP
     0x0dd6: 00 [00 00]  |   NOP
     0x0dd7: 00 [00 00]  |   NOP
     0x0dd8: 00 [00 00]  |   NOP
     0x0dd9: 00 [00 00]  |   NOP
     0x0dda: 00 [00 00]  |   NOP
     0x0ddb: 00 [00 00]  |   NOP
     0x0ddc: 00 [00 00]  |   NOP
     0x0ddd: 00 [00 00]  |   NOP
     0x0dde: 00 [00 00]  |   NOP
     0x0ddf: 00 [00 00]  |   NOP
     0x0de0: 00 [00 00]  |   NOP
     0x0de1: 00 [00 00]  |   NOP
     0x0de2: 00 [00 00]  |   NOP
     0x0de3: 00 [00 00]  |   NOP
     0x0de4: 00 [00 00]  |   NOP
     0x0de5: 00 [00 00]  |   NOP
     0x0de6: 00 [00 00]  |   NOP
     0x0de7: 00 [00 00]  |   NOP
     0x0de8: 00 [00 00]  |   NOP
     0x0de9: 00 [00 00]  |   NOP
     0x0dea: 00 [00 00]  |   NOP
     0x0deb: 00 [00 00]  |   NOP
     0x0dec: 00 [00 00]  |   NOP
     0x0ded: 00 [00 00]  |   NOP
     0x0dee: 00 [00 00]  |   NOP
     0x0def: 00 [00 00]  |   NOP
     0x0df0: 00 [00 00]  |   NOP
     0x0df1: 00 [00 00]  |   NOP
     0x0df2: 00 [00 00]  |   NOP
     0x0df3: 00 [00 00]  |   NOP
     0x0df4: 00 [00 00]  |   NOP
     0x0df5: 00 [00 00]  |   NOP
     0x0df6: 00 [00 00]  |   NOP
     0x0df7: 00 [00 00]  |   NOP
     0x0df8: 00 [00 00]  |   NOP
     0x0df9: 00 [00 00]  |   NOP
     0x0dfa: 00 [00 00]  |   NOP
     0x0dfb: 00 [00 00]  |   NOP
     0x0dfc: 00 [00 00]  |   NOP
     0x0dfd: 00 [00 00]  |   NOP
     0x0dfe: 00 [00 00]  |   NOP
     0x0dff: 00 [00 00]  |   NOP
     0x0e00: 00 [00 00]  |   NOP
     0x0e01: 00 [00 00]  |   NOP
     0x0e02: 00 [00 00]  |   NOP
     0x0e03: 00 [00 00]  |   NOP
     0x0e04: 00 [00 00]  |   NOP
     0x0e05: 00 [00 00]  |   NOP
     0x0e06: 00 [00 00]  |   NOP
     0x0e07: 00 [00 00]  |   NOP
     0x0e08: 00 [00 00]  |   NOP
     0x0e09: 00 [00 00]  |   NOP
     0x0e0a: 00 [00 00]  |   NOP
     0x0e0b: 00 [00 00]  |   NOP
     0x0e0c: 00 [00 00]  |   NOP
     0x0e0d: 00 [00 00]  |   NOP
     0x0e0e: 00 [00 00]  |   NOP
     0x0e0f: 00 [00 00]  |   NOP
     0x0e10: 00 [00 00]  |   NOP
     0x0e11: 00 [00 00]  |   NOP
     0x0e12: 00 [00 00]  |   NOP
     0x0e13: 00 [00 00]  |   NOP
     0x0e14: 00 [00 00]  |   NOP
     0x0e15: 00 [00 00]  |   NOP
     0x0e16: 00 [00 00]  |   NOP
     0x0e17: 00 [00 00]  |   NOP
     0x0e18: 00 [00 00]  |   NOP
     0x0e19: 00 [00 00]  |   NOP
     0x0e1a: 00 [00 00]  |   NOP
     0x0e1b: 00 [00 00]  |   NOP
     0x0e1c: 00 [00 00]  |   NOP
     0x0e1d: 00 [00 00]  |   NOP
     0x0e1e: 00 [00 00]  |   NOP
     0x0e1f: 00 [00 00]  |   NOP
     0x0e20: 00 [00 00]  |   NOP
     0x0e21: 00 [00 00]  |   NOP
     0x0e22: 00 [00 00]  |   NOP
     0x0e23: 00 [00 00]  |   NOP
     0x0e24: 00 [00 00]  |   NOP
     0x0e25: 00 [00 00]  |   NOP
     0x0e26: 00 [00 00]  |   NOP
     0x0e27: 00 [00 00]  |   NOP
     0x0e28: 00 [00 00]  |   NOP
     0x0e29: 00 [00 00]  |   NOP
     0x0e2a: 00 [00 00]  |   NOP
     0x0e2b: 00 [00 00]  |   NOP
     0x0e2c: 00 [00 00]  |   NOP
     0x0e2d: 00 [00 00]  |   NOP
     0x0e2e: 00 [00 00]  |   NOP
     0x0e2f: 00 [00 00]  |   NOP
     0x0e30: 00 [00 00]  |   NOP
     0x0e31: 00 [00 00]  |   NOP
     0x0e32: 00 [00 00]  |   NOP
     0x0e33: 00 [00 00]  |   NOP
     0x0e34: 00 [00 00]  |   NOP
     0x0e35: 00 [00 00]  |   NOP
     0x0e36: 00 [00 00]  |   NOP
     0x0e37: 00 [00 00]  |   NOP
     0x0e38: 00 [00 00]  |   NOP
     0x0e39: 00 [00 00]  |   NOP
     0x0e3a: 00 [00 00]  |   NOP
     0x0e3b: 00 [00 00]  |   NOP
     0x0e3c: 00 [00 00]  |   NOP
     0x0e3d: 00 [00 00]  |   NOP
     0x0e3e: 00 [00 00]  |   NOP
     0x0e3f: 00 [00 00]  |   NOP
     0x0e40: 00 [00 00]  |   NOP
     0x0e41: 00 [00 00]  |   NOP
     0x0e42: 00 [00 00]  |   NOP
     0x0e43: 00 [00 00]  |   NOP
     0x0e44: 00 [00 00]  |   NOP
     0x0e45: 00 [00 00]  |   NOP
     0x0e46: 00 [00 00]  |   NOP
     0x0e47: 00 [00 00]  |   NOP
     0x0e48: 00 [00 00]  |   NOP
     0x0e49: 00 [00 00]  |   NOP
     0x0e4a: 00 [00 00]  |   NOP
     0x0e4b: 00 [00 00]  |   NOP
     0x0e4c: 00 [00 00]  |   NOP
     0x0e4d: 00 [00 00]  |   NOP
     0x0e4e: 00 [00 00]  |   NOP
     0x0e4f: 00 [00 00]  |   NOP
     0x0e50: 00 [00 00]  |   NOP
     0x0e51: 00 [00 00]  |   NOP
     0x0e52: 00 [00 00]  |   NOP
     0x0e53: 00 [00 00]  |   NOP
     0x0e54: 00 [00 00]  |   NOP
     0x0e55: 00 [00 00]  |   NOP
     0x0e56: 00 [00 00]  |   NOP
     0x0e57: 00 [00 00]  |   NOP
     0x0e58: 00 [00 00]  |   NOP
     0x0e59: 00 [00 00]  |   NOP
     0x0e5a: 00 [00 00]  |   NOP
     0x0e5b: 00 [00 00]  |   NOP
     0x0e5c: 00 [00 00]  |   NOP
     0x0e5d: 00 [00 00]  |   NOP
     0x0e5e: 00 [00 00]  |   NOP
     0x0e5f: 00 [00 00]  |   NOP
     0x0e60: 00 [00 00]  |   NOP
     0x0e61: 00 [00 00]  |   NOP
     0x0e62: 00 [00 00]  |   NOP
     0x0e63: 00 [00 00]  |   NOP
     0x0e64: 00 [00 00]  |   NOP
     0x0e65: 00 [00 00]  |   NOP
     0x0e66: 00 [00 00]  |   NOP
     0x0e67: 00 [00 00]  |   NOP
     0x0e68: 00 [00 00]  |   NOP
     0x0e69: 00 [00 00]  |   NOP
     0x0e6a: 00 [00 00]  |   NOP
     0x0e6b: 00 [00 00]  |   NOP
     0x0e6c: 00 [00 00]  |   NOP
     0x0e6d: 00 [00 00]  |   NOP
     0x0e6e: 00 [00 00]  |   NOP
     0x0e6f: 00 [00 00]  |   NOP
     0x0e70: 00 [00 00]  |   NOP
     0x0e71: 00 [00 00]  |   NOP
     0x0e72: 00 [00 00]  |   NOP
     0x0e73: 00 [00 00]  |   NOP
     0x0e74: 00 [00 00]  |   NOP
     0x0e75: 00 [00 00]  |   NOP
     0x0e76: 00 [00 00]  |   NOP
     0x0e77: 00 [00 00]  |   NOP
     0x0e78: 00 [00 00]  |   NOP
     0x0e79: 00 [00 00]  |   NOP
     0x0e7a: 00 [00 00]  |   NOP
     0x0e7b: 00 [00 00]  |   NOP
     0x0e7c: 00 [00 00]  |   NOP
     0x0e7d: 00 [00 00]  |   NOP
     0x0e7e: 00 [00 00]  |   NOP
     0x0e7f: 00 [00 00]  |   NOP
     0x0e80: 00 [00 00]  |   NOP
     0x0e81: 00 [00 00]  |   NOP
     0x0e82: 00 [00 00]  |   NOP
     0x0e83: 00 [00 00]  |   NOP
     0x0e84: 00 [00 00]  |   NOP
     0x0e85: 00 [00 00]  |   NOP
     0x0e86: 00 [00 00]  |   NOP
     0x0e87: 00 [00 00]  |   NOP
     0x0e88: 00 [00 00]  |   NOP
     0x0e89: 00 [00 00]  |   NOP
     0x0e8a: 00 [00 00]  |   NOP
     0x0e8b: 00 [00 00]  |   NOP
     0x0e8c: 00 [00 00]  |   NOP
     0x0e8d: 00 [00 00]  |   NOP
     0x0e8e: 00 [00 00]  |   NOP
     0x0e8f: 00 [00 00]  |   NOP
     0x0e90: 00 [00 00]  |   NOP
     0x0e91: 00 [00 00]  |   NOP
     0x0e92: 00 [00 00]  |   NOP
     0x0e93: 00 [00 00]  |   NOP
     0x0e94: 00 [00 00]  |   NOP
     0x0e95: 00 [00 00]  |   NOP
     0x0e96: 00 [00 00]  |   NOP
     0x0e97: 00 [00 00]  |   NOP
     0x0e98: 00 [00 00]  |   NOP
     0x0e99: 00 [00 00]  |   NOP
     0x0e9a: 00 [00 00]  |   NOP
     0x0e9b: 00 [00 00]  |   NOP
     0x0e9c: 00 [00 00]  |   NOP
     0x0e9d: 00 [00 00]  |   NOP
     0x0e9e: 00 [00 00]  |   NOP
     0x0e9f: 00 [00 00]  |   NOP
     0x0ea0: 00 [00 00]  |   NOP
     0x0ea1: 00 [00 00]  |   NOP
     0x0ea2: 00 [00 00]  |   NOP
     0x0ea3: 00 [00 00]  |   NOP
     0x0ea4: 00 [00 00]  |   NOP
     0x0ea5: 00 [00 00]  |   NOP
     0x0ea6: 00 [00 00]  |   NOP
     0x0ea7: 00 [00 00]  |   NOP
     0x0ea8: 00 [00 00]  |   NOP
     0x0ea9: 00 [00 00]  |   NOP
     0x0eaa: 00 [00 00]  |   NOP
     0x0eab: 00 [00 00]  |   NOP
     0x0eac: 00 [00 00]  |   NOP
     0x0ead: 00 [00 00]  |   NOP
     0x0eae: 00 [00 00]  |   NOP
     0x0eaf: 00 [00 00]  |   NOP
     0x0eb0: 00 [00 00]  |   NOP
     0x0eb1: 00 [00 00]  |   NOP
     0x0eb2: 00 [00 00]  |   NOP
     0x0eb3: 00 [00 00]  |   NOP
     0x0eb4: 00 [00 00]  |   NOP
     0x0eb5: 00 [00 00]  |   NOP
     0x0eb6: 00 [00 00]  |   NOP
     0x0eb7: 00 [00 00]  |   NOP
     0x0eb8: 00 [00 00]  |   NOP
     0x0eb9: 00 [00 00]  |   NOP
     0x0eba: 00 [00 00]  |   NOP
     0x0ebb: 00 [00 00]  |   NOP
     0x0ebc: 00 [00 00]  |   NOP
     0x0ebd: 00 [00 00]  |   NOP
     0x0ebe: 00 [00 00]  |   NOP
     0x0ebf: 00 [00 00]  |   NOP
     0x0ec0: 00 [00 00]  |   NOP
     0x0ec1: 00 [00 00]  |   NOP
     0x0ec2: 00 [00 00]  |   NOP
     0x0ec3: 00 [00 00]  |   NOP
     0x0ec4: 00 [00 00]  |   NOP
     0x0ec5: 00 [00 00]  |   NOP
     0x0ec6: 00 [00 00]  |   NOP
     0x0ec7: 00 [00 00]  |   NOP
     0x0ec8: 00 [00 00]  |   NOP
     0x0ec9: 00 [00 00]  |   NOP
     0x0eca: 00 [00 00]  |   NOP
     0x0ecb: 00 [00 00]  |   NOP
     0x0ecc: 00 [00 00]  |   NOP
     0x0ecd: 00 [00 00]  |   NOP
     0x0ece: 00 [00 00]  |   NOP
     0x0ecf: 00 [00 00]  |   NOP
     0x0ed0: 00 [00 00]  |   NOP
     0x0ed1: 00 [00 00]  |   NOP
     0x0ed2: 00 [00 00]  |   NOP
     0x0ed3: 00 [00 00]  |   NOP
     0x0ed4: 00 [00 00]  |   NOP
     0x0ed5: 00 [00 00]  |   NOP
     0x0ed6: 00 [00 00]  |   NOP
     0x0ed7: 00 [00 00]  |   NOP
     0x0ed8: 00 [00 00]  |   NOP
     0x0ed9: 00 [00 00]  |   NOP
     0x0eda: 00 [00 00]  |   NOP
     0x0edb: 00 [00 00]  |   NOP
     0x0edc: 00 [00 00]  |   NOP
     0x0edd: 00 [00 00]  |   NOP
     0x0ede: 00 [00 00]  |   NOP
     0x0edf: 00 [00 00]  |   NOP
     0x0ee0: 00 [00 00]  |   NOP
     0x0ee1: 00 [00 00]  |   NOP
     0x0ee2: 00 [00 00]  |   NOP
     0x0ee3: 00 [00 00]  |   NOP
     0x0ee4: 00 [00 00]  |   NOP
     0x0ee5: 00 [00 00]  |   NOP
     0x0ee6: 00 [00 00]  |   NOP
     0x0ee7: 00 [00 00]  |   NOP
     0x0ee8: 00 [00 00]  |   NOP
     0x0ee9: 00 [00 00]  |   NOP
     0x0eea: 00 [00 00]  |   NOP
     0x0eeb: 00 [00 00]  |   NOP
     0x0eec: 00 [00 00]  |   NOP
     0x0eed: 00 [00 00]  |   NOP
     0x0eee: 00 [00 00]  |   NOP
     0x0eef: 00 [00 00]  |   NOP
     0x0ef0: 00 [00 00]  |   NOP
     0x0ef1: 00 [00 00]  |   NOP
     0x0ef2: 00 [00 00]  |   NOP
     0x0ef3: 00 [00 00]  |   NOP
     0x0ef4: 00 [00 00]  |   NOP
     0x0ef5: 00 [00 00]  |   NOP
     0x0ef6: 00 [00 00]  |   NOP
     0x0ef7: 00 [00 00]  |   NOP
     0x0ef8: 00 [00 00]  |   NOP
     0x0ef9: 00 [00 00]  |   NOP
     0x0efa: 00 [00 00]  |   NOP
     0x0efb: 00 [00 00]  |   NOP
     0x0efc: 00 [00 00]  |   NOP
     0x0efd: 00 [00 00]  |   NOP
     0x0efe: 00 [00 00]  |   NOP
     0x0eff: 00 [00 00]  |   NOP
     0x0f00: 00 [00 00]  |   NOP
     0x0f01: 00 [00 00]  |   NOP
     0x0f02: 00 [00 00]  |   NOP
     0x0f03: 00 [00 00]  |   NOP
     0x0f04: 00 [00 00]  |   NOP
     0x0f05: 00 [00 00]  |   NOP
     0x0f06: 00 [00 00]  |   NOP
     0x0f07: 00 [00 00]  |   NOP
     0x0f08: 00 [00 00]  |   NOP
     0x0f09: 00 [00 00]  |   NOP
     0x0f0a: 00 [00 00]  |   NOP
     0x0f0b: 00 [00 00]  |   NOP
     0x0f0c: 00 [00 00]  |   NOP
     0x0f0d: 00 [00 00]  |   NOP
     0x0f0e: 00 [00 00]  |   NOP
     0x0f0f: 00 [00 00]  |   NOP
     0x0f10: 00 [00 00]  |   NOP
     0x0f11: 00 [00 00]  |   NOP
     0x0f12: 00 [00 00]  |   NOP
     0x0f13: 00 [00 00]  |   NOP
     0x0f14: 00 [00 00]  |   NOP
     0x0f15: 00 [00 00]  |   NOP
     0x0f16: 00 [00 00]  |   NOP
     0x0f17: 00 [00 00]  |   NOP
     0x0f18: 00 [00 00]  |   NOP
     0x0f19: 00 [00 00]  |   NOP
     0x0f1a: 00 [00 00]  |   NOP
     0x0f1b: 00 [00 00]  |   NOP
     0x0f1c: 00 [00 00]  |   NOP
     0x0f1d: 00 [00 00]  |   NOP
     0x0f1e: 00 [00 00]  |   NOP
     0x0f1f: 00 [00 00]  |   NOP
     0x0f20: 00 [00 00]  |   NOP
     0x0f21: 00 [00 00]  |   NOP
     0x0f22: 00 [00 00]  |   NOP
     0x0f23: 00 [00 00]  |   NOP
     0x0f24: 00 [00 00]  |   NOP
     0x0f25: 00 [00 00]  |   NOP
     0x0f26: 00 [00 00]  |   NOP
     0x0f27: 00 [00 00]  |   NOP
     0x0f28: 00 [00 00]  |   NOP
     0x0f29: 00 [00 00]  |   NOP
     0x0f2a: 00 [00 00]  |   NOP
     0x0f2b: 00 [00 00]  |   NOP
     0x0f2c: 00 [00 00]  |   NOP
     0x0f2d: 00 [00 00]  |   NOP
     0x0f2e: 00 [00 00]  |   NOP
     0x0f2f: 00 [00 00]  |   NOP
     0x0f30: 00 [00 00]  |   NOP
     0x0f31: 00 [00 00]  |   NOP
     0x0f32: 00 [00 00]  |   NOP
     0x0f33: 00 [00 00]  |   NOP
     0x0f34: 00 [00 00]  |   NOP
     0x0f35: 00 [00 00]  |   NOP
     0x0f36: 00 [00 00]  |   NOP
     0x0f37: 00 [00 00]  |   NOP
     0x0f38: 00 [00 00]  |   NOP
     0x0f39: 00 [00 00]  |   NOP
     0x0f3a: 00 [00 00]  |   NOP
     0x0f3b: 00 [00 00]  |   NOP
     0x0f3c: 00 [00 00]  |   NOP
     0x0f3d: 00 [00 00]  |   NOP
     0x0f3e: 00 [00 00]  |   NOP
     0x0f3f: 00 [00 00]  |   NOP
     0x0f40: 00 [00 00]  |   NOP
     0x0f41: 00 [00 00]  |   NOP
     0x0f42: 00 [00 00]  |   NOP
     0x0f43: 00 [00 00]  |   NOP
     0x0f44: 00 [00 00]  |   NOP
     0x0f45: 00 [00 00]  |   NOP
     0x0f46: 00 [00 00]  |   NOP
     0x0f47: 00 [00 00]  |   NOP
     0x0f48: 00 [00 00]  |   NOP
     0x0f49: 00 [00 00]  |   NOP
     0x0f4a: 00 [00 00]  |   NOP
     0x0f4b: 00 [00 00]  |   NOP
     0x0f4c: 00 [00 00]  |   NOP
     0x0f4d: 00 [00 00]  |   NOP
     0x0f4e: 00 [00 00]  |   NOP
     0x0f4f: 00 [00 00]  |   NOP
     0x0f50: 00 [00 00]  |   NOP
     0x0f51: 00 [00 00]  |   NOP
     0x0f52: 00 [00 00]  |   NOP
     0x0f53: 00 [00 00]  |   NOP
     0x0f54: 00 [00 00]  |   NOP
     0x0f55: 00 [00 00]  |   NOP
     0x0f56: 00 [00 00]  |   NOP
     0x0f57: 00 [00 00]  |   NOP
     0x0f58: 00 [00 00]  |   NOP
     0x0f59: 00 [00 00]  |   NOP
     0x0f5a: 00 [00 00]  |   NOP
     0x0f5b: 00 [00 00]  |   NOP
     0x0f5c: 00 [00 00]  |   NOP
     0x0f5d: 00 [00 00]  |   NOP
     0x0f5e: 00 [00 00]  |   NOP
     0x0f5f: 00 [00 00]  |   NOP
     0x0f60: 00 [00 00]  |   NOP
     0x0f61: 00 [00 00]  |   NOP
     0x0f62: 00 [00 00]  |   NOP
     0x0f63: 00 [00 00]  |   NOP
     0x0f64: 00 [00 00]  |   NOP
     0x0f65: 00 [00 00]  |   NOP
     0x0f66: 00 [00 00]  |   NOP
     0x0f67: 00 [00 00]  |   NOP
     0x0f68: 00 [00 00]  |   NOP
     0x0f69: 00 [00 00]  |   NOP
     0x0f6a: 00 [00 00]  |   NOP
     0x0f6b: 00 [00 00]  |   NOP
     0x0f6c: 00 [00 00]  |   NOP
     0x0f6d: 00 [00 00]  |   NOP
     0x0f6e: 00 [00 00]  |   NOP
     0x0f6f: 00 [00 00]  |   NOP
     0x0f70: 00 [00 00]  |   NOP
     0x0f71: 00 [00 00]  |   NOP
     0x0f72: 00 [00 00]  |   NOP
     0x0f73: 00 [00 00]  |   NOP
     0x0f74: 00 [00 00]  |   NOP
     0x0f75: 00 [00 00]  |   NOP
     0x0f76: 00 [00 00]  |   NOP
     0x0f77: 00 [00 00]  |   NOP
     0x0f78: 00 [00 00]  |   NOP
     0x0f79: 00 [00 00]  |   NOP
     0x0f7a: 00 [00 00]  |   NOP
     0x0f7b: 00 [00 00]  |   NOP
     0x0f7c: 00 [00 00]  |   NOP
     0x0f7d: 00 [00 00]  |   NOP
     0x0f7e: 00 [00 00]  |   NOP
     0x0f7f: 00 [00 00]  |   NOP
     0x0f80: 00 [00 00]  |   NOP
     0x0f81: 00 [00 00]  |   NOP
     0x0f82: 00 [00 00]  |   NOP
     0x0f83: 00 [00 00]  |   NOP
     0x0f84: 00 [00 00]  |   NOP
     0x0f85: 00 [00 00]  |   NOP
     0x0f86: 00 [00 00]  |   NOP
     0x0f87: 00 [00 00]  |   NOP
     0x0f88: 00 [00 00]  |   NOP
     0x0f89: 00 [00 00]  |   NOP
     0x0f8a: 00 [00 00]  |   NOP
     0x0f8b: 00 [00 00]  |   NOP
     0x0f8c: 00 [00 00]  |   NOP
     0x0f8d: 00 [00 00]  |   NOP
     0x0f8e: 00 [00 00]  |   NOP
     0x0f8f: 00 [00 00]  |   NOP
     0x0f90: 00 [00 00]  |   NOP
     0x0f91: 00 [00 00]  |   NOP
     0x0f92: 00 [00 00]  |   NOP
     0x0f93: 00 [00 00]  |   NOP
     0x0f94: 00 [00 00]  |   NOP
     0x0f95: 00 [00 00]  |   NOP
     0x0f96: 00 [00 00]  |   NOP
     0x0f97: 00 [00 00]  |   NOP
     0x0f98: 00 [00 00]  |   NOP
     0x0f99: 00 [00 00]  |   NOP
     0x0f9a: 00 [00 00]  |   NOP
     0x0f9b: 00 [00 00]  |   NOP
     0x0f9c: 00 [00 00]  |   NOP
     0x0f9d: 00 [00 00]  |   NOP
     0x0f9e: 00 [00 00]  |   NOP
     0x0f9f: 00 [00 00]  |   NOP
     0x0fa0: 00 [00 00]  |   NOP
     0x0fa1: 00 [00 00]  |   NOP
     0x0fa2: 00 [00 00]  |   NOP
     0x0fa3: 00 [00 00]  |   NOP
     0x0fa4: 00 [00 00]  |   NOP
     0x0fa5: 00 [00 00]  |   NOP
     0x0fa6: 00 [00 00]  |   NOP
     0x0fa7: 00 [00 00]  |   NOP
     0x0fa8: 00 [00 00]  |   NOP
     0x0fa9: 00 [00 00]  |   NOP
     0x0faa: 00 [00 00]  |   NOP
     0x0fab: 00 [00 00]  |   NOP
     0x0fac: 00 [00 00]  |   NOP
     0x0fad: 00 [00 00]  |   NOP
     0x0fae: 00 [00 00]  |   NOP
     0x0faf: 00 [00 00]  |   NOP
     0x0fb0: 00 [00 00]  |   NOP
     0x0fb1: 00 [00 00]  |   NOP
     0x0fb2: 00 [00 00]  |   NOP
     0x0fb3: 00 [00 00]  |   NOP
     0x0fb4: 00 [00 00]  |   NOP
     0x0fb5: 00 [00 00]  |   NOP
     0x0fb6: 00 [00 00]  |   NOP
     0x0fb7: 00 [00 00]  |   NOP
     0x0fb8: 00 [00 00]  |   NOP
     0x0fb9: 00 [00 00]  |   NOP
     0x0fba: 00 [00 00]  |   NOP
     0x0fbb: 00 [00 00]  |   NOP
     0x0fbc: 00 [00 00]  |   NOP
     0x0fbd: 00 [00 00]  |   NOP
     0x0fbe: 00 [00 00]  |   NOP
     0x0fbf: 00 [00 00]  |   NOP
     0x0fc0: 00 [00 00]  |   NOP
     0x0fc1: 00 [00 00]  |   NOP
     0x0fc2: 00 [00 00]  |   NOP
     0x0fc3: 00 [00 00]  |   NOP
     0x0fc4: 00 [00 00]  |   NOP
     0x0fc5: 00 [00 00]  |   NOP
     0x0fc6: 00 [00 00]  |   NOP
     0x0fc7: 00 [00 00]  |   NOP
     0x0fc8: 00 [00 00]  |   NOP
     0x0fc9: 00 [00 00]  |   NOP
     0x0fca: 00 [00 00]  |   NOP
     0x0fcb: 00 [00 00]  |   NOP
     0x0fcc: 00 [00 00]  |   NOP
     0x0fcd: 00 [00 00]  |   NOP
     0x0fce: 00 [00 00]  |   NOP
     0x0fcf: 00 [00 00]  |   NOP
     0x0fd0: 00 [00 00]  |   NOP
     0x0fd1: 00 [00 00]  |   NOP
     0x0fd2: 00 [00 00]  |   NOP
     0x0fd3: 00 [00 00]  |   NOP
     0x0fd4: 00 [00 00]  |   NOP
     0x0fd5: 00 [00 00]  |   NOP
     0x0fd6: 00 [00 00]  |   NOP
     0x0fd7: 00 [00 00]  |   NOP
     0x0fd8: 00 [00 00]  |   NOP
     0x0fd9: 00 [00 00]  |   NOP
     0x0fda: 00 [00 00]  |   NOP
     0x0fdb: 00 [00 00]  |   NOP
     0x0fdc: 00 [00 00]  |   NOP
     0x0fdd: 00 [00 00]  |   NOP
     0x0fde: 00 [00 00]  |   NOP
     0x0fdf: 00 [00 00]  |   NOP
     0x0fe0: 00 [00 00]  |   NOP
     0x0fe1: 00 [00 00]  |   NOP
     0x0fe2: 00 [00 00]  |   NOP
     0x0fe3: 00 [00 00]  |   NOP
     0x0fe4: 00 [00 00]  |   NOP
     0x0fe5: 00 [00 00]  |   NOP
     0x0fe6: 00 [00 00]  |   NOP
     0x0fe7: 00 [00 00]  |   NOP
     0x0fe8: 00 [00 00]  |   NOP
     0x0fe9: 00 [00 00]  |   NOP
     0x0fea: 00 [00 00]  |   NOP
     0x0feb: 00 [00 00]  |   NOP
     0x0fec: 00 [00 00]  |   NOP
     0x0fed: 00 [00 00]  |   NOP
     0x0fee: 00 [00 00]  |   NOP
     0x0fef: 00 [00 00]  |   NOP
     0x0ff0: 00 [00 00]  |   NOP
     0x0ff1: 00 [00 00]  |   NOP
     0x0ff2: 00 [00 00]  |   NOP
     0x0ff3: 00 [00 00]  |   NOP
     0x0ff4: 00 [00 00]  |   NOP
     0x0ff5: 00 [00 00]  |   NOP
     0x0ff6: 00 [00 00]  |   NOP
     0x0ff7: 00 [00 00]  |   NOP
     0x0ff8: 00 [00 00]  |   NOP
     0x0ff9: 00 [00 00]  |   NOP
     0x0ffa: 00 [00 00]  |   NOP
     0x0ffb: 00 [00 00]  |   NOP
     0x0ffc: 00 [00 00]  |   NOP
     0x0ffd: 00 [00 00]  |   NOP
     0x0ffe: 00 [00 00]  |   NOP
     0x0fff: 00 [00 00]  |   NOP
     0x1000: 00 [00 00]  |   NOP
     0x1001: 00 [00 00]  |   NOP
     0x1002: 00 [00 00]  |   NOP
     0x1003: 00 [00 00]  |   NOP
     0x1004: 00 [00 00]  |   NOP
     0x1005: 00 [00 00]  |   NOP
     0x1006: 00 [00 00]  |   NOP
     0x1007: 00 [00 00]  |   NOP
     0x1008: 00 [00 00]  |   NOP
     0x1009: 00 [00 00]  |   NOP
     0x100a: 00 [00 00]  |   NOP
     0x100b: 00 [00 00]  |   NOP
     0x100c: 00 [00 00]  |   NOP
     0x100d: 00 [00 00]  |   NOP
     0x100e: 00 [00 00]  |   NOP
     0x100f: 00 [00 00]  |   NOP
     0x1010: 00 [00 00]  |   NOP
     0x1011: 00 [00 00]  |   NOP
     0x1012: 00 [00 00]  |   NOP
     0x1013: 00 [00 00]  |   NOP
     0x1014: 00 [00 00]  |   NOP
     0x1015: 00 [00 00]  |   NOP
     0x1016: 00 [00 00]  |   NOP
     0x1017: 00 [00 00]  |   NOP
     0x1018: 00 [00 00]  |   NOP
     0x1019: 00 [00 00]  |   NOP
     0x101a: 00 [00 00]  |   NOP
     0x101b: 00 [00 00]  |   NOP
     0x101c: 00 [00 00]  |   NOP
     0x101d: 00 [00 00]  |   NOP
     0x101e: 00 [00 00]  |   NOP
     0x101f: 00 [00 00]  |   NOP
     0x1020: 00 [00 00]  |   NOP
     0x1021: 00 [00 00]  |   NOP
     0x1022: 00 [00 00]  |   NOP
     0x1023: 00 [00 00]  |   NOP
     0x1024: 00 [00 00]  |   NOP
     0x1025: 00 [00 00]  |   NOP
     0x1026: 00 [00 00]  |   NOP
     0x1027: 00 [00 00]  |   NOP
     0x1028: 00 [00 00]  |   NOP
     0x1029: 00 [00 00]  |   NOP
     0x102a: 00 [00 00]  |   NOP
     0x102b: 00 [00 00]  |   NOP
     0x102c: 00 [00 00]  |   NOP
     0x102d: 00 [00 00]  |   NOP
     0x102e: 00 [00 00]  |   NOP
     0x102f: 00 [00 00]  |   NOP
     0x1030: 00 [00 00]  |   NOP
     0x1031: 00 [00 00]  |   NOP
     0x1032: 00 [00 00]  |   NOP
     0x1033: 00 [00 00]  |   NOP
     0x1034: 00 [00 00]  |   NOP
     0x1035: 00 [00 00]  |   NOP
     0x1036: 00 [00 00]  |   NOP
     0x1037: 00 [00 00]  |   NOP
     0x1038: 00 [00 00]  |   NOP
     0x1039: 00 [00 00]  |   NOP
     0x103a: 00 [00 00]  |   NOP
     0x103b: 00 [00 00]  |   NOP
     0x103c: 00 [00 00]  |   NOP
     0x103d: 00 [00 00]  |   NOP
     0x103e: 00 [00 00]  |   NOP
     0x103f: 00 [00 00]  |   NOP
     0x1040: 00 [00 00]  |   NOP
     0x1041: 00 [00 00]  |   NOP
     0x1042: 00 [00 00]  |   NOP
     0x1043: 00 [00 00]  |   NOP
     0x1044: 00 [00 00]  |   NOP
     0x1045: 00 [00 00]  |   NOP
     0x1046: 00 [00 00]  |   NOP
     0x1047: 00 [00 00]  |   NOP
     0x1048: 00 [00 00]  |   NOP
     0x1049: 00 [00 00]  |   NOP
     0x104a: 00 [00 00]  |   NOP
     0x104b: 00 [00 00]  |   NOP
     0x104c: 00 [00 00]  |   NOP
     0x104d: 00 [00 00]  |   NOP
     0x104e: 00 [00 00]  |   NOP
     0x104f: 00 [00 00]  |   NOP
     0x1050: 00 [00 00]  |   NOP
     0x1051: 00 [00 00]  |   NOP
     0x1052: 00 [00 00]  |   NOP
     0x1053: 00 [00 00]  |   NOP
     0x1054: 00 [00 00]  |   NOP
     0x1055: 00 [00 00]  |   NOP
     0x1056: 00 [00 00]  |   NOP
     0x1057: 00 [00 00]  |   NOP
     0x1058: 00 [00 00]  |   NOP
     0x1059: 00 [00 00]  |   NOP
     0x105a: 00 [00 00]  |   NOP
     0x105b: 00 [00 00]  |   NOP
     0x105c: 00 [00 00]  |   NOP
     0x105d: 00 [00 00]  |   NOP
     0x105e: 00 [00 00]  |   NOP
     0x105f: 00 [00 00]  |   NOP
     0x1060: 00 [00 00]  |   NOP
     0x1061: 00 [00 00]  |   NOP
     0x1062: 00 [00 00]  |   NOP
     0x1063: 00 [00 00]  |   NOP
     0x1064: 00 [00 00]  |   NOP
     0x1065: 00 [00 00]  |   NOP
     0x1066: 00 [00 00]  |   NOP
     0x1067: 00 [00 00]  |   NOP
     0x1068: 00 [00 00]  |   NOP
     0x1069: 00 [00 00]  |   NOP
     0x106a: 00 [00 00]  |   NOP
     0x106b: 00 [00 00]  |   NOP
     0x106c: 00 [00 00]  |   NOP
     0x106d: 00 [00 00]  |   NOP
     0x106e: 00 [00 00]  |   NOP
     0x106f: 00 [00 00]  |   NOP
     0x1070: 00 [00 00]  |   NOP
     0x1071: 00 [00 00]  |   NOP
     0x1072: 00 [00 00]  |   NOP
     0x1073: 00 [00 00]  |   NOP
     0x1074: 00 [00 00]  |   NOP
     0x1075: 00 [00 00]  |   NOP
     0x1076: 00 [00 00]  |   NOP
     0x1077: 00 [00 00]  |   NOP
     0x1078: 00 [00 00]  |   NOP
     0x1079: 00 [00 00]  |   NOP
     0x107a: 00 [00 00]  |   NOP
     0x107b: 00 [00 00]  |   NOP
     0x107c: 00 [00 00]  |   NOP
     0x107d: 00 [00 00]  |   NOP
     0x107e: 00 [00 00]  |   NOP
     0x107f: 00 [00 00]  |   NOP
     0x1080: 00 [00 00]  |   NOP
     0x1081: 00 [00 00]  |   NOP
     0x1082: 00 [00 00]  |   NOP
     0x1083: 00 [00 00]  |   NOP
     0x1084: 00 [00 00]  |   NOP
     0x1085: 00 [00 00]  |   NOP
     0x1086: 00 [00 00]  |   NOP
     0x1087: 00 [00 00]  |   NOP
     0x1088: 00 [00 00]  |   NOP
     0x1089: 00 [00 00]  |   NOP
     0x108a: 00 [00 00]  |   NOP
     0x108b: 00 [00 00]  |   NOP
     0x108c: 00 [00 00]  |   NOP
     0x108d: 00 [00 00]  |   NOP
     0x108e: 00 [00 00]  |   NOP
     0x108f: 00 [00 00]  |   NOP
     0x1090: 00 [00 00]  |   NOP
     0x1091: 00 [00 00]  |   NOP
     0x1092: 00 [00 00]  |   NOP
     0x1093: 00 [00 00]  |   NOP
     0x1094: 00 [00 00]  |   NOP
     0x1095: 00 [00 00]  |   NOP
     0x1096: 00 [00 00]  |   NOP
     0x1097: 00 [00 00]  |   NOP
     0x1098: 00 [00 00]  |   NOP
     0x1099: 00 [00 00]  |   NOP
     0x109a: 00 [00 00]  |   NOP
     0x109b: 00 [00 00]  |   NOP
     0x109c: 00 [00 00]  |   NOP
     0x109d: 00 [00 00]  |   NOP
     0x109e: 00 [00 00]  |   NOP
     0x109f: 00 [00 00]  |   NOP
     0x10a0: 00 [00 00]  |   NOP
     0x10a1: 00 [00 00]  |   NOP
     0x10a2: 00 [00 00]  |   NOP
     0x10a3: 00 [00 00]  |   NOP
     0x10a4: 00 [00 00]  |   NOP
     0x10a5: 00 [00 00]  |   NOP
     0x10a6: 00 [00 00]  |   NOP
     0x10a7: 00 [00 00]  |   NOP
     0x10a8: 00 [00 00]  |   NOP
     0x10a9: 00 [00 00]  |   NOP
     0x10aa: 00 [00 00]  |   NOP
     0x10ab: 00 [00 00]  |   NOP
     0x10ac: 00 [00 00]  |   NOP
     0x10ad: 00 [00 00]  |   NOP
     0x10ae: 00 [00 00]  |   NOP
     0x10af: 00 [00 00]  |   NOP
     0x10b0: 00 [00 00]  |   NOP
     0x10b1: 00 [00 00]  |   NOP
     0x10b2: 00 [00 00]  |   NOP
     0x10b3: 00 [00 00]  |   NOP
     0x10b4: 00 [00 00]  |   NOP
     0x10b5: 00 [00 00]  |   NOP
     0x10b6: 00 [00 00]  |   NOP
     0x10b7: 00 [00 00]  |   NOP
     0x10b8: 00 [00 00]  |   NOP
     0x10b9: 00 [00 00]  |   NOP
     0x10ba: 00 [00 00]  |   NOP
     0x10bb: 00 [00 00]  |   NOP
     0x10bc: 00 [00 00]  |   NOP
     0x10bd: 00 [00 00]  |   NOP
     0x10be: 00 [00 00]  |   NOP
     0x10bf: 00 [00 00]  |   NOP
     0x10c0: 00 [00 00]  |   NOP
     0x10c1: 00 [00 00]  |   NOP
     0x10c2: 00 [00 00]  |   NOP
     0x10c3: 00 [00 00]  |   NOP
     0x10c4: 00 [00 00]  |   NOP
     0x10c5: 00 [00 00]  |   NOP
     0x10c6: 00 [00 00]  |   NOP
     0x10c7: 00 [00 00]  |   NOP
     0x10c8: 00 [00 00]  |   NOP
     0x10c9: 00 [00 00]  |   NOP
     0x10ca: 00 [00 00]  |   NOP
     0x10cb: 00 [00 00]  |   NOP
     0x10cc: 00 [00 00]  |   NOP
     0x10cd: 00 [00 00]  |   NOP
     0x10ce: 00 [00 00]  |   NOP
     0x10cf: 00 [00 00]  |   NOP
     0x10d0: 00 [00 00]  |   NOP
     0x10d1: 00 [00 00]  |   NOP
     0x10d2: 00 [00 00]  |   NOP
     0x10d3: 00 [00 00]  |   NOP
     0x10d4: 00 [00 00]  |   NOP
     0x10d5: 00 [00 00]  |   NOP
     0x10d6: 00 [00 00]  |   NOP
     0x10d7: 00 [00 00]  |   NOP
     0x10d8: 00 [00 00]  |   NOP
     0x10d9: 00 [00 00]  |   NOP
     0x10da: 00 [00 00]  |   NOP
     0x10db: 00 [00 00]  |   NOP
     0x10dc: 00 [00 00]  |   NOP
     0x10dd: 00 [00 00]  |   NOP
     0x10de: 00 [00 00]  |   NOP
     0x10df: 00 [00 00]  |   NOP
     0x10e0: 00 [00 00]  |   NOP
     0x10e1: 00 [00 00]  |   NOP
     0x10e2: 00 [00 00]  |   NOP
     0x10e3: 00 [00 00]  |   NOP
     0x10e4: 00 [00 00]  |   NOP
     0x10e5: 00 [00 00]  |   NOP
     0x10e6: 00 [00 00]  |   NOP
     0x10e7: 00 [00 00]  |   NOP
     0x10e8: 00 [00 00]  |   NOP
     0x10e9: 00 [00 00]  |   NOP
     0x10ea: 00 [00 00]  |   NOP
     0x10eb: 00 [00 00]  |   NOP
     0x10ec: 00 [00 00]  |   NOP
     0x10ed: 00 [00 00]  |   NOP
     0x10ee: 00 [00 00]  |   NOP
     0x10ef: 00 [00 00]  |   NOP
     0x10f0: 00 [00 00]  |   NOP
     0x10f1: 00 [00 00]  |   NOP
     0x10f2: 00 [00 00]  |   NOP
     0x10f3: 00 [00 00]  |   NOP
     0x10f4: 00 [00 00]  |   NOP
     0x10f5: 00 [00 00]  |   NOP
     0x10f6: 00 [00 00]  |   NOP
     0x10f7: 00 [00 00]  |   NOP
     0x10f8: 00 [00 00]  |   NOP
     0x10f9: 00 [00 00]  |   NOP
     0x10fa: 00 [00 00]  |   NOP
     0x10fb: 00 [00 00]  |   NOP
     0x10fc: 00 [00 00]  |   NOP
     0x10fd: 00 [00 00]  |   NOP
     0x10fe: 00 [00 00]  |   NOP
     0x10ff: 00 [00 00]  |   NOP
     0x1100: 00 [00 00]  |   NOP
     0x1101: 00 [00 00]  |   NOP
     0x1102: 00 [00 00]  |   NOP
     0x1103: 00 [00 00]  |   NOP
     0x1104: 00 [00 00]  |   NOP
     0x1105: 00 [00 00]  |   NOP
     0x1106: 00 [00 00]  |   NOP
     0x1107: 00 [00 00]  |   NOP
     0x1108: 00 [00 00]  |   NOP
     0x1109: 00 [00 00]  |   NOP
     0x110a: 00 [00 00]  |   NOP
     0x110b: 00 [00 00]  |   NOP
     0x110c: 00 [00 00]  |   NOP
     0x110d: 00 [00 00]  |   NOP
     0x110e: 00 [00 00]  |   NOP
     0x110f: 00 [00 00]  |   NOP
     0x1110: 00 [00 00]  |   NOP
     0x1111: 00 [00 00]  |   NOP
     0x1112: 00 [00 00]  |   NOP
     0x1113: 00 [00 00]  |   NOP
     0x1114: 00 [00 00]  |   NOP
     0x1115: 00 [00 00]  |   NOP
     0x1116: 00 [00 00]  |   NOP
     0x1117: 00 [00 00]  |   NOP
     0x1118: 00 [00 00]  |   NOP
     0x1119: 00 [00 00]  |   NOP
     0x111a: 00 [00 00]  |   NOP
     0x111b: 00 [00 00]  |   NOP
     0x111c: 00 [00 00]  |   NOP
     0x111d: 00 [00 00]  |   NOP
     0x111e: 00 [00 00]  |   NOP
     0x111f: 00 [00 00]  |   NOP
     0x1120: 00 [00 00]  |   NOP
     0x1121: 00 [00 00]  |   NOP
     0x1122: 00 [00 00]  |   NOP
     0x1123: 00 [00 00]  |   NOP
     0x1124: 00 [00 00]  |   NOP
     0x1125: 00 [00 00]  |   NOP
     0x1126: 00 [00 00]  |   NOP
     0x1127: 00 [00 00]  |   NOP
     0x1128: 00 [00 00]  |   NOP
     0x1129: 00 [00 00]  |   NOP
     0x112a: 00 [00 00]  |   NOP
     0x112b: 00 [00 00]  |   NOP
     0x112c: 00 [00 00]  |   NOP
     0x112d: 00 [00 00]  |   NOP
     0x112e: 00 [00 00]  |   NOP
     0x112f: 00 [00 00]  |   NOP
     0x1130: 00 [00 00]  |   NOP
     0x1131: 00 [00 00]  |   NOP
     0x1132: 00 [00 00]  |   NOP
     0x1133: 00 [00 00]  |   NOP
     0x1134: 00 [00 00]  |   NOP
     0x1135: 00 [00 00]  |   NOP
     0x1136: 00 [00 00]  |   NOP
     0x1137: 00 [00 00]  |   NOP
     0x1138: 00 [00 00]  |   NOP
     0x1139: 00 [00 00]  |   NOP
     0x113a: 00 [00 00]  |   NOP
     0x113b: 00 [00 00]  |   NOP
     0x113c: 00 [00 00]  |   NOP
     0x113d: 00 [00 00]  |   NOP
     0x113e: 00 [00 00]  |   NOP
     0x113f: 00 [00 00]  |   NOP
     0x1140: 00 [00 00]  |   NOP
     0x1141: 00 [00 00]  |   NOP
     0x1142: 00 [00 00]  |   NOP
     0x1143: 00 [00 00]  |   NOP
     0x1144: 00 [00 00]  |   NOP
     0x1145: 00 [00 00]  |   NOP
     0x1146: 00 [00 00]  |   NOP
     0x1147: 00 [00 00]  |   NOP
     0x1148: 00 [00 00]  |   NOP
     0x1149: 00 [00 00]  |   NOP
     0x114a: 00 [00 00]  |   NOP
     0x114b: 00 [00 00]  |   NOP
     0x114c: 00 [00 00]  |   NOP
     0x114d: 00 [00 00]  |   NOP
     0x114e: 00 [00 00]  |   NOP
     0x114f: 00 [00 00]  |   NOP
     0x1150: 00 [00 00]  |   NOP
     0x1151: 00 [00 00]  |   NOP
     0x1152: 00 [00 00]  |   NOP
     0x1153: 00 [00 00]  |   NOP
     0x1154: 00 [00 00]  |   NOP
     0x1155: 00 [00 00]  |   NOP
     0x1156: 00 [00 00]  |   NOP
     0x1157: 00 [00 00]  |   NOP
     0x1158: 00 [00 00]  |   NOP
     0x1159: 00 [00 00]  |   NOP
     0x115a: 00 [00 00]  |   NOP
     0x115b: 00 [00 00]  |   NOP
     0x115c: 00 [00 00]  |   NOP
     0x115d: 00 [00 00]  |   NOP
     0x115e: 00 [00 00]  |   NOP
     0x115f: 00 [00 00]  |   NOP
     0x1160: 00 [00 00]  |   NOP
     0x1161: 00 [00 00]  |   NOP
     0x1162: 00 [00 00]  |   NOP
     0x1163: 00 [00 00]  |   NOP
     0x1164: 00 [00 00]  |   NOP
     0x1165: 00 [00 00]  |   NOP
     0x1166: 00 [00 00]  |   NOP
     0x1167: 00 [00 00]  |   NOP
     0x1168: 00 [00 00]  |   NOP
     0x1169: 00 [00 00]  |   NOP
     0x116a: 00 [00 00]  |   NOP
     0x116b: 00 [00 00]  |   NOP
     0x116c: 00 [00 00]  |   NOP
     0x116d: 00 [00 00]  |   NOP
     0x116e: 00 [00 00]  |   NOP
     0x116f: 00 [00 00]  |   NOP
     0x1170: 00 [00 00]  |   NOP
     0x1171: 00 [00 00]  |   NOP
     0x1172: 00 [00 00]  |   NOP
     0x1173: 00 [00 00]  |   NOP
     0x1174: 00 [00 00]  |   NOP
     0x1175: 00 [00 00]  |   NOP
     0x1176: 00 [00 00]  |   NOP
     0x1177: 00 [00 00]  |   NOP
     0x1178: 00 [00 00]  |   NOP
     0x1179: 00 [00 00]  |   NOP
     0x117a: 00 [00 00]  |   NOP
     0x117b: 00 [00 00]  |   NOP
     0x117c: 00 [00 00]  |   NOP
     0x117d: 00 [00 00]  |   NOP
     0x117e: 00 [00 00]  |   NOP
     0x117f: 00 [00 00]  |   NOP
     0x1180: 00 [00 00]  |   NOP
     0x1181: 00 [00 00]  |   NOP
     0x1182: 00 [00 00]  |   NOP
     0x1183: 00 [00 00]  |   NOP
     0x1184: 00 [00 00]  |   NOP
     0x1185: 00 [00 00]  |   NOP
     0x1186: 00 [00 00]  |   NOP
     0x1187: 00 [00 00]  |   NOP
     0x1188: 00 [00 00]  |   NOP
     0x1189: 00 [00 00]  |   NOP
     0x118a: 00 [00 00]  |   NOP
     0x118b: 00 [00 00]  |   NOP
     0x118c: 00 [00 00]  |   NOP
     0x118d: 00 [00 00]  |   NOP
     0x118e: 00 [00 00]  |   NOP
     0x118f: 00 [00 00]  |   NOP
     0x1190: 00 [00 00]  |   NOP
     0x1191: 00 [00 00]  |   NOP
     0x1192: 00 [00 00]  |   NOP
     0x1193: 00 [00 00]  |   NOP
     0x1194: 00 [00 00]  |   NOP
     0x1195: 00 [00 00]  |   NOP
     0x1196: 00 [00 00]  |   NOP
     0x1197: 00 [00 00]  |   NOP
     0x1198: 00 [00 00]  |   NOP
     0x1199: 00 [00 00]  |   NOP
     0x119a: 00 [00 00]  |   NOP
     0x119b: 00 [00 00]  |   NOP
     0x119c: 00 [00 00]  |   NOP
     0x119d: 00 [00 00]  |   NOP
     0x119e: 00 [00 00]  |   NOP
     0x119f: 00 [00 00]  |   NOP
     0x11a0: 00 [00 00]  |   NOP
     0x11a1: 00 [00 00]  |   NOP
     0x11a2: 00 [00 00]  |   NOP
     0x11a3: 00 [00 00]  |   NOP
     0x11a4: 00 [00 00]  |   NOP
     0x11a5: 00 [00 00]  |   NOP
     0x11a6: 00 [00 00]  |   NOP
     0x11a7: 00 [00 00]  |   NOP
     0x11a8: 00 [00 00]  |   NOP
     0x11a9: 00 [00 00]  |   NOP
     0x11aa: 00 [00 00]  |   NOP
     0x11ab: 00 [00 00]  |   NOP
     0x11ac: 00 [00 00]  |   NOP
     0x11ad: 00 [00 00]  |   NOP
     0x11ae: 00 [00 00]  |   NOP
     0x11af: 00 [00 00]  |   NOP
     0x11b0: 00 [00 00]  |   NOP
     0x11b1: 00 [00 00]  |   NOP
     0x11b2: 00 [00 00]  |   NOP
     0x11b3: 00 [00 00]  |   NOP
     0x11b4: 00 [00 00]  |   NOP
     0x11b5: 00 [00 00]  |   NOP
     0x11b6: 00 [00 00]  |   NOP
     0x11b7: 00 [00 00]  |   NOP
     0x11b8: 00 [00 00]  |   NOP
     0x11b9: 00 [00 00]  |   NOP
     0x11ba: 00 [00 00]  |   NOP
     0x11bb: 00 [00 00]  |   NOP
     0x11bc: 00 [00 00]  |   NOP
     0x11bd: 00 [00 00]  |   NOP
     0x11be: 00 [00 00]  |   NOP
     0x11bf: 00 [00 00]  |   NOP
     0x11c0: 00 [00 00]  |   NOP
     0x11c1: 00 [00 00]  |   NOP
     0x11c2: 00 [00 00]  |   NOP
     0x11c3: 00 [00 00]  |   NOP
     0x11c4: 00 [00 00]  |   NOP
     0x11c5: 00 [00 00]  |   NOP
     0x11c6: 00 [00 00]  |   NOP
     0x11c7: 00 [00 00]  |   NOP
     0x11c8: 00 [00 00]  |   NOP
     0x11c9: 00 [00 00]  |   NOP
     0x11ca: 00 [00 00]  |   NOP
     0x11cb: 00 [00 00]  |   NOP
     0x11cc: 00 [00 00]  |   NOP
     0x11cd: 00 [00 00]  |   NOP
     0x11ce: 00 [00 00]  |   NOP
     0x11cf: 00 [00 00]  |   NOP
     0x11d0: 00 [00 00]  |   NOP
     0x11d1: 00 [00 00]  |   NOP
     0x11d2: 00 [00 00]  |   NOP
     0x11d3: 00 [00 00]  |   NOP
     0x11d4: 00 [00 00]  |   NOP
     0x11d5: 00 [00 00]  |   NOP
     0x11d6: 00 [00 00]  |   NOP
     0x11d7: 00 [00 00]  |   NOP
     0x11d8: 00 [00 00]  |   NOP
     0x11d9: 00 [00 00]  |   NOP
     0x11da: 00 [00 00]  |   NOP
     0x11db: 00 [00 00]  |   NOP
     0x11dc: 00 [00 00]  |   NOP
     0x11dd: 00 [00 00]  |   NOP
     0x11de: 00 [00 00]  |   NOP
     0x11df: 00 [00 00]  |   NOP
     0x11e0: 00 [00 00]  |   NOP
     0x11e1: 00 [00 00]  |   NOP
     0x11e2: 00 [00 00]  |   NOP
     0x11e3: 00 [00 00]  |   NOP
     0x11e4: 00 [00 00]  |   NOP
     0x11e5: 00 [00 00]  |   NOP
     0x11e6: 00 [00 00]  |   NOP
     0x11e7: 00 [00 00]  |   NOP
     0x11e8: 00 [00 00]  |   NOP
     0x11e9: 00 [00 00]  |   NOP
     0x11ea: 00 [00 00]  |   NOP
     0x11eb: 00 [00 00]  |   NOP
     0x11ec: 00 [00 00]  |   NOP
     0x11ed: 00 [00 00]  |   NOP
     0x11ee: 00 [00 00]  |   NOP
     0x11ef: 00 [00 00]  |   NOP
     0x11f0: 00 [00 00]  |   NOP
     0x11f1: 00 [00 00]  |   NOP
     0x11f2: 00 [00 00]  |   NOP
     0x11f3: 00 [00 00]  |   NOP
     0x11f4: 00 [00 00]  |   NOP
     0x11f5: 00 [00 00]  |   NOP
     0x11f6: 00 [00 00]  |   NOP
     0x11f7: 00 [00 00]  |   NOP
     0x11f8: 00 [00 00]  |   NOP
     0x11f9: 00 [00 00]  |   NOP
     0x11fa: 00 [00 00]  |   NOP
     0x11fb: 00 [00 00]  |   NOP
     0x11fc: 00 [00 00]  |   NOP
     0x11fd: 00 [00 00]  |   NOP
     0x11fe: 00 [00 00]  |   NOP
     0x11ff: 00 [00 00]  |   NOP
     0x1200: 00 [00 00]  |   NOP
     0x1201: 00 [00 00]  |   NOP
     0x1202: 00 [00 00]  |   NOP
     0x1203: 00 [00 00]  |   NOP
     0x1204: 00 [00 00]  |   NOP
     0x1205: 00 [00 00]  |   NOP
     0x1206: 00 [00 00]  |   NOP
     0x1207: 00 [00 00]  |   NOP
     0x1208: 00 [00 00]  |   NOP
     0x1209: 00 [00 00]  |   NOP
     0x120a: 00 [00 00]  |   NOP
     0x120b: 00 [00 00]  |   NOP
     0x120c: 00 [00 00]  |   NOP
     0x120d: 00 [00 00]  |   NOP
     0x120e: 00 [00 00]  |   NOP
     0x120f: 00 [00 00]  |   NOP
     0x1210: 00 [00 00]  |   NOP
     0x1211: 00 [00 00]  |   NOP
     0x1212: 00 [00 00]  |   NOP
     0x1213: 00 [00 00]  |   NOP
     0x1214: 00 [00 00]  |   NOP
     0x1215: 00 [00 00]  |   NOP
     0x1216: 00 [00 00]  |   NOP
     0x1217: 00 [00 00]  |   NOP
     0x1218: 00 [00 00]  |   NOP
     0x1219: 00 [00 00]  |   NOP
     0x121a: 00 [00 00]  |   NOP
     0x121b: 00 [00 00]  |   NOP
     0x121c: 00 [00 00]  |   NOP
     0x121d: 00 [00 00]  |   NOP
     0x121e: 00 [00 00]  |   NOP
     0x121f: 00 [00 00]  |   NOP
     0x1220: 00 [00 00]  |   NOP
     0x1221: 00 [00 00]  |   NOP
     0x1222: 00 [00 00]  |   NOP
     0x1223: 00 [00 00]  |   NOP
     0x1224: 00 [00 00]  |   NOP
     0x1225: 00 [00 00]  |   NOP
     0x1226: 00 [00 00]  |   NOP
     0x1227: 00 [00 00]  |   NOP
     0x1228: 00 [00 00]  |   NOP
     0x1229: 00 [00 00]  |   NOP
     0x122a: 00 [00 00]  |   NOP
     0x122b: 00 [00 00]  |   NOP
     0x122c: 00 [00 00]  |   NOP
     0x122d: 00 [00 00]  |   NOP
     0x122e: 00 [00 00]  |   NOP
     0x122f: 00 [00 00]  |   NOP
     0x1230: 00 [00 00]  |   NOP
     0x1231: 00 [00 00]  |   NOP
     0x1232: 00 [00 00]  |   NOP
     0x1233: 00 [00 00]  |   NOP
     0x1234: 00 [00 00]  |   NOP
     0x1235: 00 [00 00]  |   NOP
     0x1236: 00 [00 00]  |   NOP
     0x1237: 00 [00 00]  |   NOP
     0x1238: 00 [00 00]  |   NOP
     0x1239: 00 [00 00]  |   NOP
     0x123a: 00 [00 00]  |   NOP
     0x123b: 00 [00 00]  |   NOP
     0x123c: 00 [00 00]  |   NOP
     0x123d: 00 [00 00]  |   NOP
     0x123e: 00 [00 00]  |   NOP
     0x123f: 00 [00 00]  |   NOP
     0x1240: 00 [00 00]  |   NOP
     0x1241: 00 [00 00]  |   NOP
     0x1242: 00 [00 00]  |   NOP
     0x1243: 00 [00 00]  |   NOP
     0x1244: 00 [00 00]  |   NOP
     0x1245: 00 [00 00]  |   NOP
     0x1246: 00 [00 00]  |   NOP
     0x1247: 00 [00 00]  |   NOP
     0x1248: 00 [00 00]  |   NOP
     0x1249: 00 [00 00]  |   NOP
     0x124a: 00 [00 00]  |   NOP
     0x124b: 00 [00 00]  |   NOP
     0x124c: 00 [00 00]  |   NOP
     0x124d: 00 [00 00]  |   NOP
     0x124e: 00 [00 00]  |   NOP
     0x124f: 00 [00 00]  |   NOP
     0x1250: 00 [00 00]  |   NOP
     0x1251: 00 [00 00]  |   NOP
     0x1252: 00 [00 00]  |   NOP
     0x1253: 00 [00 00]  |   NOP
     0x1254: 00 [00 00]  |   NOP
     0x1255: 00 [00 00]  |   NOP
     0x1256: 00 [00 00]  |   NOP
     0x1257: 00 [00 00]  |   NOP
     0x1258: 00 [00 00]  |   NOP
     0x1259: 00 [00 00]  |   NOP
     0x125a: 00 [00 00]  |   NOP
     0x125b: 00 [00 00]  |   NOP
     0x125c: 00 [00 00]  |   NOP
     0x125d: 00 [00 00]  |   NOP
     0x125e: 00 [00 00]  |   NOP
     0x125f: 00 [00 00]  |   NOP
     0x1260: 00 [00 00]  |   NOP
     0x1261: 00 [00 00]  |   NOP
     0x1262: 00 [00 00]  |   NOP
     0x1263: 00 [00 00]  |   NOP
     0x1264: 00 [00 00]  |   NOP
     0x1265: 00 [00 00]  |   NOP
     0x1266: 00 [00 00]  |   NOP
     0x1267: 00 [00 00]  |   NOP
     0x1268: 00 [00 00]  |   NOP
     0x1269: 00 [00 00]  |   NOP
     0x126a: 00 [00 00]  |   NOP
     0x126b: 00 [00 00]  |   NOP
     0x126c: 00 [00 00]  |   NOP
     0x126d: 00 [00 00]  |   NOP
     0x126e: 00 [00 00]  |   NOP
     0x126f: 00 [00 00]  |   NOP
     0x1270: 00 [00 00]  |   NOP
     0x1271: 00 [00 00]  |   NOP
     0x1272: 00 [00 00]  |   NOP
     0x1273: 00 [00 00]  |   NOP
     0x1274: 00 [00 00]  |   NOP
     0x1275: 00 [00 00]  |   NOP
     0x1276: 00 [00 00]  |   NOP
     0x1277: 00 [00 00]  |   NOP
     0x1278: 00 [00 00]  |   NOP
     0x1279: 00 [00 00]  |   NOP
     0x127a: 00 [00 00]  |   NOP
     0x127b: 00 [00 00]  |   NOP
     0x127c: 00 [00 00]  |   NOP
     0x127d: 00 [00 00]  |   NOP
     0x127e: 00 [00 00]  |   NOP
     0x127f: 00 [00 00]  |   NOP
     0x1280: 00 [00 00]  |   NOP
     0x1281: 00 [00 00]  |   NOP
     0x1282: 00 [00 00]  |   NOP
     0x1283: 00 [00 00]  |   NOP
     0x1284: 00 [00 00]  |   NOP
     0x1285: 00 [00 00]  |   NOP
     0x1286: 00 [00 00]  |   NOP
     0x1287: 00 [00 00]  |   NOP
     0x1288: 00 [00 00]  |   NOP
     0x1289: 00 [00 00]  |   NOP
     0x128a: 00 [00 00]  |   NOP
     0x128b: 00 [00 00]  |   NOP
     0x128c: 00 [00 00]  |   NOP
     0x128d: 00 [00 00]  |   NOP
     0x128e: 00 [00 00]  |   NOP
     0x128f: 00 [00 00]  |   NOP
     0x1290: 00 [00 00]  |   NOP
     0x1291: 00 [00 00]  |   NOP
     0x1292: 00 [00 00]  |   NOP
     0x1293: 00 [00 00]  |   NOP
     0x1294: 00 [00 00]  |   NOP
     0x1295: 00 [00 00]  |   NOP
     0x1296: 00 [00 00]  |   NOP
     0x1297: 00 [00 00]  |   NOP
     0x1298: 00 [00 00]  |   NOP
     0x1299: 00 [00 00]  |   NOP
     0x129a: 00 [00 00]  |   NOP
     0x129b: 00 [00 00]  |   NOP
     0x129c: 00 [00 00]  |   NOP
     0x129d: 00 [00 00]  |   NOP
     0x129e: 00 [00 00]  |   NOP
     0x129f: 00 [00 00]  |   NOP
     0x12a0: 00 [00 00]  |   NOP
     0x12a1: 00 [00 00]  |   NOP
     0x12a2: 00 [00 00]  |   NOP
     0x12a3: 00 [00 00]  |   NOP
     0x12a4: 00 [00 00]  |   NOP
     0x12a5: 00 [00 00]  |   NOP
     0x12a6: 00 [00 00]  |   NOP
     0x12a7: 00 [00 00]  |   NOP
     0x12a8: 00 [00 00]  |   NOP
     0x12a9: 00 [00 00]  |   NOP
     0x12aa: 00 [00 00]  |   NOP
     0x12ab: 00 [00 00]  |   NOP
     0x12ac: 00 [00 00]  |   NOP
     0x12ad: 00 [00 00]  |   NOP
     0x12ae: 00 [00 00]  |   NOP
     0x12af: 00 [00 00]  |   NOP
     0x12b0: 00 [00 00]  |   NOP
     0x12b1: 00 [00 00]  |   NOP
     0x12b2: 00 [00 00]  |   NOP
     0x12b3: 00 [00 00]  |   NOP
     0x12b4: 00 [00 00]  |   NOP
     0x12b5: 00 [00 00]  |   NOP
     0x12b6: 00 [00 00]  |   NOP
     0x12b7: 00 [00 00]  |   NOP
     0x12b8: 00 [00 00]  |   NOP
     0x12b9: 00 [00 00]  |   NOP
     0x12ba: 00 [00 00]  |   NOP
     0x12bb: 00 [00 00]  |   NOP
     0x12bc: 00 [00 00]  |   NOP
     0x12bd: 00 [00 00]  |   NOP
     0x12be: 00 [00 00]  |   NOP
     0x12bf: 00 [00 00]  |   NOP
     0x12c0: 00 [00 00]  |   NOP
     0x12c1: 00 [00 00]  |   NOP
     0x12c2: 00 [00 00]  |   NOP
     0x12c3: 00 [00 00]  |   NOP
     0x12c4: 00 [00 00]  |   NOP
     0x12c5: 00 [00 00]  |   NOP
     0x12c6: 00 [00 00]  |   NOP
     0x12c7: 00 [00 00]  |   NOP
     0x12c8: 00 [00 00]  |   NOP
     0x12c9: 00 [00 00]  |   NOP
     0x12ca: 00 [00 00]  |   NOP
     0x12cb: 00 [00 00]  |   NOP
     0x12cc: 00 [00 00]  |   NOP
     0x12cd: 00 [00 00]  |   NOP
     0x12ce: 00 [00 00]  |   NOP
     0x12cf: 00 [00 00]  |   NOP
     0x12d0: 00 [00 00]  |   NOP
     0x12d1: 00 [00 00]  |   NOP
     0x12d2: 00 [00 00]  |   NOP
     0x12d3: 00 [00 00]  |   NOP
     0x12d4: 00 [00 00]  |   NOP
     0x12d5: 00 [00 00]  |   NOP
     0x12d6: 00 [00 00]  |   NOP
     0x12d7: 00 [00 00]  |   NOP
     0x12d8: 00 [00 00]  |   NOP
     0x12d9: 00 [00 00]  |   NOP
     0x12da: 00 [00 00]  |   NOP
     0x12db: 00 [00 00]  |   NOP
     0x12dc: 00 [00 00]  |   NOP
     0x12dd: 00 [00 00]  |   NOP
     0x12de: 00 [00 00]  |   NOP
     0x12df: 00 [00 00]  |   NOP
     0x12e0: 00 [00 00]  |   NOP
     0x12e1: 00 [00 00]  |   NOP
     0x12e2: 00 [00 00]  |   NOP
     0x12e3: 00 [00 00]  |   NOP
     0x12e4: 00 [00 00]  |   NOP
     0x12e5: 00 [00 00]  |   NOP
     0x12e6: 00 [00 00]  |   NOP
     0x12e7: 00 [00 00]  |   NOP
     0x12e8: 00 [00 00]  |   NOP
     0x12e9: 00 [00 00]  |   NOP
     0x12ea: 00 [00 00]  |   NOP
     0x12eb: 00 [00 00]  |   NOP
     0x12ec: 00 [00 00]  |   NOP
     0x12ed: 00 [00 00]  |   NOP
     0x12ee: 00 [00 00]  |   NOP
     0x12ef: 00 [00 00]  |   NOP
     0x12f0: 00 [00 00]  |   NOP
     0x12f1: 00 [00 00]  |   NOP
     0x12f2: 00 [00 00]  |   NOP
     0x12f3: 00 [00 00]  |   NOP
     0x12f4: 00 [00 00]  |   NOP
     0x12f5: 00 [00 00]  |   NOP
     0x12f6: 00 [00 00]  |   NOP
     0x12f7: 00 [00 00]  |   NOP
     0x12f8: 00 [00 00]  |   NOP
     0x12f9: 00 [00 00]  |   NOP
     0x12fa: 00 [00 00]  |   NOP
     0x12fb: 00 [00 00]  |   NOP
     0x12fc: 00 [00 00]  |   NOP
     0x12fd: 00 [00 00]  |   NOP
     0x12fe: 00 [00 00]  |   NOP
     0x12ff: 00 [00 00]  |   NOP
     0x1300: 00 [00 00]  |   NOP
     0x1301: 00 [00 00]  |   NOP
     0x1302: 00 [00 00]  |   NOP
     0x1303: 00 [00 00]  |   NOP
     0x1304: 00 [00 00]  |   NOP
     0x1305: 00 [00 00]  |   NOP
     0x1306: 00 [00 00]  |   NOP
     0x1307: 00 [00 00]  |   NOP
     0x1308: 00 [00 00]  |   NOP
     0x1309: 00 [00 00]  |   NOP
     0x130a: 00 [00 00]  |   NOP
     0x130b: 00 [00 00]  |   NOP
     0x130c: 00 [00 00]  |   NOP
     0x130d: 00 [00 00]  |   NOP
     0x130e: 00 [00 00]  |   NOP
     0x130f: 00 [00 00]  |   NOP
     0x1310: 00 [00 00]  |   NOP
     0x1311: 00 [00 00]  |   NOP
     0x1312: 00 [00 00]  |   NOP
     0x1313: 00 [00 00]  |   NOP
     0x1314: 00 [00 00]  |   NOP
     0x1315: 00 [00 00]  |   NOP
     0x1316: 00 [00 00]  |   NOP
     0x1317: 00 [00 00]  |   NOP
     0x1318: 00 [00 00]  |   NOP
     0x1319: 00 [00 00]  |   NOP
     0x131a: 00 [00 00]  |   NOP
     0x131b: 00 [00 00]  |   NOP
     0x131c: 00 [00 00]  |   NOP
     0x131d: 00 [00 00]  |   NOP
     0x131e: 00 [00 00]  |   NOP
     0x131f: 00 [00 00]  |   NOP
     0x1320: 00 [00 00]  |   NOP
     0x1321: 00 [00 00]  |   NOP
     0x1322: 00 [00 00]  |   NOP
     0x1323: 00 [00 00]  |   NOP
     0x1324: 00 [00 00]  |   NOP
     0x1325: 00 [00 00]  |   NOP
     0x1326: 00 [00 00]  |   NOP
     0x1327: 00 [00 00]  |   NOP
     0x1328: 00 [00 00]  |   NOP
     0x1329: 00 [00 00]  |   NOP
     0x132a: 00 [00 00]  |   NOP
     0x132b: 00 [00 00]  |   NOP
     0x132c: 00 [00 00]  |   NOP
     0x132d: 00 [00 00]  |   NOP
     0x132e: 00 [00 00]  |   NOP
     0x132f: 00 [00 00]  |   NOP
     0x1330: 00 [00 00]  |   NOP
     0x1331: 00 [00 00]  |   NOP
     0x1332: 00 [00 00]  |   NOP
     0x1333: 00 [00 00]  |   NOP
     0x1334: 00 [00 00]  |   NOP
     0x1335: 00 [00 00]  |   NOP
     0x1336: 00 [00 00]  |   NOP
     0x1337: 00 [00 00]  |   NOP
     0x1338: 00 [00 00]  |   NOP
     0x1339: 00 [00 00]  |   NOP
     0x133a: 00 [00 00]  |   NOP
     0x133b: 00 [00 00]  |   NOP
     0x133c: 00 [00 00]  |   NOP
     0x133d: 00 [00 00]  |   NOP
     0x133e: 00 [00 00]  |   NOP
     0x133f: 00 [00 00]  |   NOP
     0x1340: 00 [00 00]  |   NOP
     0x1341: 00 [00 00]  |   NOP
     0x1342: 00 [00 00]  |   NOP
     0x1343: 00 [00 00]  |   NOP
     0x1344: 00 [00 00]  |   NOP
     0x1345: 00 [00 00]  |   NOP
     0x1346: 00 [00 00]  |   NOP
     0x1347: 00 [00 00]  |   NOP
     0x1348: 00 [00 00]  |   NOP
     0x1349: 00 [00 00]  |   NOP
     0x134a: 00 [00 00]  |   NOP
     0x134b: 00 [00 00]  |   NOP
     0x134c: 00 [00 00]  |   NOP
     0x134d: 00 [00 00]  |   NOP
     0x134e: 00 [00 00]  |   NOP
     0x134f: 00 [00 00]  |   NOP
     0x1350: 00 [00 00]  |   NOP
     0x1351: 00 [00 00]  |   NOP
     0x1352: 00 [00 00]  |   NOP
     0x1353: 00 [00 00]  |   NOP
     0x1354: 00 [00 00]  |   NOP
     0x1355: 00 [00 00]  |   NOP
     0x1356: 00 [00 00]  |   NOP
     0x1357: 00 [00 00]  |   NOP
     0x1358: 00 [00 00]  |   NOP
     0x1359: 00 [00 00]  |   NOP
     0x135a: 00 [00 00]  |   NOP
     0x135b: 00 [00 00]  |   NOP
     0x135c: 00 [00 00]  |   NOP
     0x135d: 00 [00 00]  |   NOP
     0x135e: 00 [00 00]  |   NOP
     0x135f: 00 [00 00]  |   NOP
     0x1360: 00 [00 00]  |   NOP
     0x1361: 00 [00 00]  |   NOP
     0x1362: 00 [00 00]  |   NOP
     0x1363: 00 [00 00]  |   NOP
     0x1364: 00 [00 00]  |   NOP
     0x1365: 00 [00 00]  |   NOP
     0x1366: 00 [00 00]  |   NOP
     0x1367: 00 [00 00]  |   NOP
     0x1368: 00 [00 00]  |   NOP
     0x1369: 00 [00 00]  |   NOP
     0x136a: 00 [00 00]  |   NOP
     0x136b: 00 [00 00]  |   NOP
     0x136c: 00 [00 00]  |   NOP
     0x136d: 00 [00 00]  |   NOP
     0x136e: 00 [00 00]  |   NOP
     0x136f: 00 [00 00]  |   NOP
     0x1370: 00 [00 00]  |   NOP
     0x1371: 00 [00 00]  |   NOP
     0x1372: 00 [00 00]  |   NOP
     0x1373: 00 [00 00]  |   NOP
     0x1374: 00 [00 00]  |   NOP
     0x1375: 00 [00 00]  |   NOP
     0x1376: 00 [00 00]  |   NOP
     0x1377: 00 [00 00]  |   NOP
     0x1378: 00 [00 00]  |   NOP
     0x1379: 00 [00 00]  |   NOP
     0x137a: 00 [00 00]  |   NOP
     0x137b: 00 [00 00]  |   NOP
     0x137c: 00 [00 00]  |   NOP
     0x137d: 00 [00 00]  |   NOP
     0x137e: 00 [00 00]  |   NOP
     0x137f: 00 [00 00]  |   NOP
     0x1380: 00 [00 00]  |   NOP
     0x1381: 00 [00 00]  |   NOP
     0x1382: 00 [00 00]  |   NOP
     0x1383: 00 [00 00]  |   NOP
     0x1384: 00 [00 00]  |   NOP
     0x1385: 00 [00 00]  |   NOP
     0x1386: 00 [00 00]  |   NOP
     0x1387: 00 [00 00]  |   NOP
     0x1388: 00 [00 00]  |   NOP
     0x1389: 00 [00 00]  |   NOP
     0x138a: 00 [00 00]  |   NOP
     0x138b: 00 [00 00]  |   NOP
     0x138c: 00 [00 00]  |   NOP
     0x138d: 00 [00 00]  |   NOP
     0x138e: 00 [00 00]  |   NOP
     0x138f: 00 [00 00]  |   NOP
     0x1390: 00 [00 00]  |   NOP
     0x1391: 00 [00 00]  |   NOP
     0x1392: 00 [00 00]  |   NOP
     0x1393: 00 [00 00]  |   NOP
     0x1394: 00 [00 00]  |   NOP
     0x1395: 00 [00 00]  |   NOP
     0x1396: 00 [00 00]  |   NOP
     0x1397: 00 [00 00]  |   NOP
     0x1398: 00 [00 00]  |   NOP
     0x1399: 00 [00 00]  |   NOP
     0x139a: 00 [00 00]  |   NOP
     0x139b: 00 [00 00]  |   NOP
     0x139c: 00 [00 00]  |   NOP
     0x139d: 00 [00 00]  |   NOP
     0x139e: 00 [00 00]  |   NOP
     0x139f: 00 [00 00]  |   NOP
     0x13a0: 00 [00 00]  |   NOP
     0x13a1: 00 [00 00]  |   NOP
     0x13a2: 00 [00 00]  |   NOP
     0x13a3: 00 [00 00]  |   NOP
     0x13a4: 00 [00 00]  |   NOP
     0x13a5: 00 [00 00]  |   NOP
     0x13a6: 00 [00 00]  |   NOP
     0x13a7: 00 [00 00]  |   NOP
     0x13a8: 00 [00 00]  |   NOP
     0x13a9: 00 [00 00]  |   NOP
     0x13aa: 00 [00 00]  |   NOP
     0x13ab: 00 [00 00]  |   NOP
     0x13ac: 00 [00 00]  |   NOP
     0x13ad: 00 [00 00]  |   NOP
     0x13ae: 00 [00 00]  |   NOP
     0x13af: 00 [00 00]  |   NOP
     0x13b0: 00 [00 00]  |   NOP
     0x13b1: 00 [00 00]  |   NOP
     0x13b2: 00 [00 00]  |   NOP
     0x13b3: 00 [00 00]  |   NOP
     0x13b4: 00 [00 00]  |   NOP
     0x13b5: 00 [00 00]  |   NOP
     0x13b6: 00 [00 00]  |   NOP
     0x13b7: 00 [00 00]  |   NOP
     0x13b8: 00 [00 00]  |   NOP
     0x13b9: 00 [00 00]  |   NOP
     0x13ba: 00 [00 00]  |   NOP
     0x13bb: 00 [00 00]  |   NOP
     0x13bc: 00 [00 00]  |   NOP
     0x13bd: 00 [00 00]  |   NOP
     0x13be: 00 [00 00]  |   NOP
     0x13bf: 00 [00 00]  |   NOP
     0x13c0: 00 [00 00]  |   NOP
     0x13c1: 00 [00 00]  |   NOP
     0x13c2: 00 [00 00]  |   NOP
     0x13c3: 00 [00 00]  |   NOP
     0x13c4: 00 [00 00]  |   NOP
     0x13c5: 00 [00 00]  |   NOP
     0x13c6: 00 [00 00]  |   NOP
     0x13c7: 00 [00 00]  |   NOP
     0x13c8: 00 [00 00]  |   NOP
     0x13c9: 00 [00 00]  |   NOP
     0x13ca: 00 [00 00]  |   NOP
     0x13cb: 00 [00 00]  |   NOP
     0x13cc: 00 [00 00]  |   NOP
     0x13cd: 00 [00 00]  |   NOP
     0x13ce: 00 [00 00]  |   NOP
     0x13cf: 00 [00 00]  |   NOP
     0x13d0: 00 [00 00]  |   NOP
     0x13d1: 00 [00 00]  |   NOP
     0x13d2: 00 [00 00]  |   NOP
     0x13d3: 00 [00 00]  |   NOP
     0x13d4: 00 [00 00]  |   NOP
     0x13d5: 00 [00 00]  |   NOP
     0x13d6: 00 [00 00]  |   NOP
     0x13d7: 00 [00 00]  |   NOP
     0x13d8: 00 [00 00]  |   NOP
     0x13d9: 00 [00 00]  |   NOP
     0x13da: 00 [00 00]  |   NOP
     0x13db: 00 [00 00]  |   NOP
     0x13dc: 00 [00 00]  |   NOP
     0x13dd: 00 [00 00]  |   NOP
     0x13de: 00 [00 00]  |   NOP
     0x13df: 00 [00 00]  |   NOP
     0x13e0: 00 [00 00]  |   NOP
     0x13e1: 00 [00 00]  |   NOP
     0x13e2: 00 [00 00]  |   NOP
     0x13e3: 00 [00 00]  |   NOP
     0x13e4: 00 [00 00]  |   NOP
     0x13e5: 00 [00 00]  |   NOP
     0x13e6: 00 [00 00]  |   NOP
     0x13e7: 00 [00 00]  |   NOP
     0x13e8: 00 [00 00]  |   NOP
     0x13e9: 00 [00 00]  |   NOP
     0x13ea: 00 [00 00]  |   NOP
     0x13eb: 00 [00 00]  |   NOP
     0x13ec: 00 [00 00]  |   NOP
     0x13ed: 00 [00 00]  |   NOP
     0x13ee: 00 [00 00]  |   NOP
     0x13ef: 00 [00 00]  |   NOP
     0x13f0: 00 [00 00]  |   NOP
     0x13f1: 00 [00 00]  |   NOP
     0x13f2: 00 [00 00]  |   NOP
     0x13f3: 00 [00 00]  |   NOP
     0x13f4: 00 [00 00]  |   NOP
     0x13f5: 00 [00 00]  |   NOP
     0x13f6: 00 [00 00]  |   NOP
     0x13f7: 00 [00 00]  |   NOP
     0x13f8: 00 [00 00]  |   NOP
     0x13f9: 00 [00 00]  |   NOP
     0x13fa: 00 [00 00]  |   NOP
     0x13fb: 00 [00 00]  |   NOP
     0x13fc: 00 [00 00]  |   NOP
     0x13fd: 00 [00 00]  |   NOP
     0x13fe: 00 [00 00]  |   NOP
     0x13ff: 00 [00 CD]  |   NOP
     0x1400: 00 [CD 74]  |   NOP
     0x1401: CD [74 14]  |   CAL 0x1474
     0x1402: 74 [14 00]  |   MOV M, H
     0x1403: 14 [00 C5]  |   INR D
     0x1404: 00 [C5 E5]  |   NOP
     0x1405: C5 [E5 1A]  |   PUSH B
     0x1406: E5 [1A D3]  |   PUSH H
     0x1407: 1A [D3 04]  |   LDAX D
     0x1408: D3 [04 DB]  |   OUT 0x04
     0x1409: 04 [DB 03]  |   INR B
     0x140a: DB [03 B6]  |   IN 0x03
     0x140b: 03 [B6 77]  |   INX B
     0x140c: B6 [77 23]  |   ORA M
     0x140d: 77 [23 13]  |   MOV M, A
     0x140e: 23 [13 AF]  |   INX H
     0x140f: 13 [AF D3]  |   INX D
     0x1410: AF [D3 04]  |   XRA A
     0x1411: D3 [04 DB]  |   OUT 0x04
     0x1412: 04 [DB 03]  |   INR B
     0x1413: DB [03 B6]  |   IN 0x03
     0x1414: 03 [B6 77]  |   INX B
     0x1415: B6 [77 E1]  |   ORA M
     0x1416: 77 [E1 01]  |   MOV M, A
     0x1417: E1 [01 20]  |   POP H
     0x1418: 01 [20 00]  |   LXI B, 0x0020 
     0x1419: 20 [00 09]  |   Undefined instruction
     0x141a: 00 [09 C1]  |   NOP
     0x141b: 09 [C1 05]  |   DAD B
     0x141c: C1 [05 C2]  |   POP B
     0x141d: 05 [C2 05]  |   DCR B
     0x141e: C2 [05 14]  |   JNZ 0x1405
     0x141f: 05 [14 C9]  |   DCR B
     0x1420: 14 [C9 00]  |   INR D
     0x1421: C9 [00 00]  |   RET
     0x1422: 00 [00 CD]  |   NOP
     0x1423: 00 [CD 74]  |   NOP
     0x1424: CD [74 14]  |   CAL 0x1474
     0x1425: 74 [14 C5]  |   MOV M, H
     0x1426: 14 [C5 E5]  |   INR D
     0x1427: C5 [E5 AF]  |   PUSH B
     0x1428: E5 [AF 77]  |   PUSH H
     0x1429: AF [77 23]  |   XRA A
     0x142a: 77 [23 77]  |   MOV M, A
     0x142b: 23 [77 23]  |   INX H
     0x142c: 77 [23 E1]  |   MOV M, A
     0x142d: 23 [E1 01]  |   INX H
     0x142e: E1 [01 20]  |   POP H
     0x142f: 01 [20 00]  |   LXI B, 0x0020 
     0x1430: 20 [00 09]  |   Undefined instruction
     0x1431: 00 [09 C1]  |   NOP
     0x1432: 09 [C1 05]  |   DAD B
     0x1433: C1 [05 C2]  |   POP B
     0x1434: 05 [C2 27]  |   DCR B
     0x1435: C2 [27 14]  |   JNZ 0x1427
     0x1436: 27 [14 C9]  |   DAA
     0x1437: 14 [C9 C5]  |   INR D
     0x1438: C9 [C5 1A]  |   RET
     0x1439: C5 [1A 77]  |   PUSH B
     0x143a: 1A [77 13]  |   LDAX D
     0x143b: 77 [13 01]  |   MOV M, A
     0x143c: 13 [01 20]  |   INX D
     0x143d: 01 [20 00]  |   LXI B, 0x0020 
     0x143e: 20 [00 09]  |   Undefined instruction
     0x143f: 00 [09 C1]  |   NOP
     0x1440: 09 [C1 05]  |   DAD B
     0x1441: C1 [05 C2]  |   POP B
     0x1442: 05 [C2 39]  |   DCR B
     0x1443: C2 [39 14]  |   JNZ 0x1439
     0x1444: 39 [14 C9]  |   DAD SP
     0x1445: 14 [C9 00]  |   INR D
     0x1446: C9 [00 00]  |   RET
     0x1447: 00 [00 00]  |   NOP
     0x1448: 00 [00 00]  |   NOP
     0x1449: 00 [00 00]  |   NOP
     0x144a: 00 [00 00]  |   NOP
     0x144b: 00 [00 00]  |   NOP
     0x144c: 00 [00 00]  |   NOP
     0x144d: 00 [00 00]  |   NOP
     0x144e: 00 [00 00]  |   NOP
     0x144f: 00 [00 00]  |   NOP
     0x1450: 00 [00 CD]  |   NOP
     0x1451: 00 [CD 74]  |   NOP
     0x1452: CD [74 14]  |   CAL 0x1474
     0x1453: 74 [14 C5]  |   MOV M, H
     0x1454: 14 [C5 E5]  |   INR D
     0x1455: C5 [E5 1A]  |   PUSH B
     0x1456: E5 [1A D3]  |   PUSH H
     0x1457: 1A [D3 04]  |   LDAX D
     0x1458: D3 [04 DB]  |   OUT 0x04
     0x1459: 04 [DB 03]  |   INR B
     0x145a: DB [03 2F]  |   IN 0x03
     0x145b: 03 [2F A6]  |   INX B
     0x145c: 2F [A6 77]  |   CMA
     0x145d: A6 [77 23]  |   ANA M
     0x145e: 77 [23 13]  |   MOV M, A
     0x145f: 23 [13 AF]  |   INX H
     0x1460: 13 [AF D3]  |   INX D
     0x1461: AF [D3 04]  |   XRA A
     0x1462: D3 [04 DB]  |   OUT 0x04
     0x1463: 04 [DB 03]  |   INR B
     0x1464: DB [03 2F]  |   IN 0x03
     0x1465: 03 [2F A6]  |   INX B
     0x1466: 2F [A6 77]  |   CMA
     0x1467: A6 [77 E1]  |   ANA M
     0x1468: 77 [E1 01]  |   MOV M, A
     0x1469: E1 [01 20]  |   POP H
     0x146a: 01 [20 00]  |   LXI B, 0x0020 
     0x146b: 20 [00 09]  |   Undefined instruction
     0x146c: 00 [09 C1]  |   NOP
     0x146d: 09 [C1 05]  |   DAD B
     0x146e: C1 [05 C2]  |   POP B
     0x146f: 05 [C2 55]  |   DCR B
     0x1470: C2 [55 14]  |   JNZ 0x1455
     0x1471: 55 [14 C9]  |   MOV D, L
     0x1472: 14 [C9 7D]  |   INR D
     0x1473: C9 [7D E6]  |   RET
     0x1474: 7D [E6 07]  |   MOV A, L
     0x1475: E6 [07 D3]  |   ANI 0x07
     0x1476: 07 [D3 02]  |   RLC
     0x1477: D3 [02 C3]  |   OUT 0x02
     0x1478: 02 [C3 47]  |   STAX B
     0x1479: C3 [47 1A]  |   JMP 0x1A47
     0x147a: 47 [1A C5]  |   MOV B, A
     0x147b: 1A [C5 E5]  |   LDAX D
     0x147c: C5 [E5 7E]  |   PUSH B
     0x147d: E5 [7E 12]  |   PUSH H
     0x147e: 7E [12 13]  |   MOV A, M
     0x147f: 12 [13 23]  |   STAX D
     0x1480: 13 [23 0D]  |   INX D
     0x1481: 23 [0D C2]  |   INX H
     0x1482: 0D [C2 7E]  |   DCR C
     0x1483: C2 [7E 14]  |   JNZ 0x147E
     0x1484: 7E [14 E1]  |   MOV A, M
     0x1485: 14 [E1 01]  |   INR D
     0x1486: E1 [01 20]  |   POP H
     0x1487: 01 [20 00]  |   LXI B, 0x0020 
     0x1488: 20 [00 09]  |   Undefined instruction
     0x1489: 00 [09 C1]  |   NOP
     0x148a: 09 [C1 05]  |   DAD B
     0x148b: C1 [05 C2]  |   POP B
     0x148c: 05 [C2 7C]  |   DCR B
     0x148d: C2 [7C 14]  |   JNZ 0x147C
     0x148e: 7C [14 C9]  |   MOV A, H
     0x148f: 14 [C9 CD]  |   INR D
     0x1490: C9 [CD 74]  |   RET
     0x1491: CD [74 14]  |   CAL 0x1474
     0x1492: 74 [14 AF]  |   MOV M, H
     0x1493: 14 [AF 32]  |   INR D
     0x1494: AF [32 61]  |   XRA A
     0x1495: 32 [61 20]  |   STA 0x2061
     0x1496: 61 [20 C5]  |   MOV H, C
     0x1497: 20 [C5 E5]  |   Undefined instruction
     0x1498: C5 [E5 1A]  |   PUSH B
     0x1499: E5 [1A D3]  |   PUSH H
     0x149a: 1A [D3 04]  |   LDAX D
     0x149b: D3 [04 DB]  |   OUT 0x04
     0x149c: 04 [DB 03]  |   INR B
     0x149d: DB [03 F5]  |   IN 0x03
     0x149e: 03 [F5 A6]  |   INX B
     0x149f: F5 [A6 CA]  |   PUSH PSW
     0x14a0: A6 [CA A9]  |   ANA M
     0x14a1: CA [A9 14]  |   JZ 0x14A9
     0x14a2: A9 [14 3E]  |   XRA C
     0x14a3: 14 [3E 01]  |   INR D
     0x14a4: 3E [01 32]  |   MVI A, 0x01
     0x14a5: 01 [32 61]  |   LXI B, 0x6132 
     0x14a6: 32 [61 20]  |   STA 0x2061
     0x14a7: 61 [20 F1]  |   MOV H, C
     0x14a8: 20 [F1 B6]  |   Undefined instruction
     0x14a9: F1 [B6 77]  |   POP PSW
     0x14aa: B6 [77 23]  |   ORA M
     0x14ab: 77 [23 13]  |   MOV M, A
     0x14ac: 23 [13 AF]  |   INX H
     0x14ad: 13 [AF D3]  |   INX D
     0x14ae: AF [D3 04]  |   XRA A
     0x14af: D3 [04 DB]  |   OUT 0x04
     0x14b0: 04 [DB 03]  |   INR B
     0x14b1: DB [03 F5]  |   IN 0x03
     0x14b2: 03 [F5 A6]  |   INX B
     0x14b3: F5 [A6 CA]  |   PUSH PSW
     0x14b4: A6 [CA BD]  |   ANA M
     0x14b5: CA [BD 14]  |   JZ 0x14BD
     0x14b6: BD [14 3E]  |   CMP L
     0x14b7: 14 [3E 01]  |   INR D
     0x14b8: 3E [01 32]  |   MVI A, 0x01
     0x14b9: 01 [32 61]  |   LXI B, 0x6132 
     0x14ba: 32 [61 20]  |   STA 0x2061
     0x14bb: 61 [20 F1]  |   MOV H, C
     0x14bc: 20 [F1 B6]  |   Undefined instruction
     0x14bd: F1 [B6 77]  |   POP PSW
     0x14be: B6 [77 E1]  |   ORA M
     0x14bf: 77 [E1 01]  |   MOV M, A
     0x14c0: E1 [01 20]  |   POP H
     0x14c1: 01 [20 00]  |   LXI B, 0x0020 
     0x14c2: 20 [00 09]  |   Undefined instruction
     0x14c3: 00 [09 C1]  |   NOP
     0x14c4: 09 [C1 05]  |   DAD B
     0x14c5: C1 [05 C2]  |   POP B
     0x14c6: 05 [C2 98]  |   DCR B
     0x14c7: C2 [98 14]  |   JNZ 0x1498
     0x14c8: 98 [14 C9]  |   SBB B
     0x14c9: 14 [C9 AF]  |   INR D
     0x14ca: C9 [AF C5]  |   RET
     0x14cb: AF [C5 77]  |   XRA A
     0x14cc: C5 [77 01]  |   PUSH B
     0x14cd: 77 [01 20]  |   MOV M, A
     0x14ce: 01 [20 00]  |   LXI B, 0x0020 
     0x14cf: 20 [00 09]  |   Undefined instruction
     0x14d0: 00 [09 C1]  |   NOP
     0x14d1: 09 [C1 05]  |   DAD B
     0x14d2: C1 [05 C2]  |   POP B
     0x14d3: 05 [C2 CC]  |   DCR B
     0x14d4: C2 [CC 14]  |   JNZ 0x14CC
     0x14d5: CC [14 C9]  |   CZ 0xC914
     0x14d6: 14 [C9 3A]  |   INR D
     0x14d7: C9 [3A 25]  |   RET
     0x14d8: 3A [25 20]  |   LDA 0x2025
     0x14d9: 25 [20 FE]  |   DCR H
     0x14da: 20 [FE 05]  |   Undefined instruction
     0x14db: FE [05 C8]  |   CPI 0x05
     0x14dc: 05 [C8 FE]  |   DCR B
     0x14dd: C8 [FE 02]  |   RZ
     0x14de: FE [02 C0]  |   CPI 0x02
     0x14df: 02 [C0 3A]  |   STAX B
     0x14e0: C0 [3A 29]  |   RNZ
     0x14e1: 3A [29 20]  |   LDA 0x2029
     0x14e2: 29 [20 FE]  |   DAD H
     0x14e3: 20 [FE D8]  |   Undefined instruction
     0x14e4: FE [D8 47]  |   CPI 0xD8
     0x14e5: D8 [47 D2]  |   RC
     0x14e6: 47 [D2 30]  |   MOV B, A
     0x14e7: D2 [30 15]  |   JNC 0x1530
     0x14e8: 30 [15 3A]  |   Undefined instruction
     0x14e9: 15 [3A 02]  |   DCR D
     0x14ea: 3A [02 20]  |   LDA 0x2002
     0x14eb: 02 [20 A7]  |   STAX B
     0x14ec: 20 [A7 C8]  |   Undefined instruction
     0x14ed: A7 [C8 78]  |   ANA A
     0x14ee: C8 [78 FE]  |   RZ
     0x14ef: 78 [FE CE]  |   MOV A, B
     0x14f0: FE [CE D2]  |   CPI 0xCE
     0x14f1: CE [D2 79]  |   ACI 0xD2
     0x14f2: D2 [79 15]  |   JNC 0x1579
     0x14f3: 79 [15 C6]  |   MOV A, C
     0x14f4: 15 [C6 06]  |   DCR D
     0x14f5: C6 [06 47]  |   ADI 0x06
     0x14f6: 06 [47 3A]  |   MVI B, 0x47
     0x14f7: 47 [3A 09]  |   MOV B, A
     0x14f8: 3A [09 20]  |   LDA 0x2009
     0x14f9: 09 [20 FE]  |   DAD B
     0x14fa: 20 [FE 90]  |   Undefined instruction
     0x14fb: FE [90 D2]  |   CPI 0x90
     0x14fc: 90 [D2 04]  |   SUB B
     0x14fd: D2 [04 15]  |   JNC 0x1504
     0x14fe: 04 [15 B8]  |   INR B
     0x14ff: 15 [B8 D2]  |   DCR D
     0x1500: B8 [D2 30]  |   CMP B
     0x1501: D2 [30 15]  |   JNC 0x1530
     0x1502: 30 [15 68]  |   Undefined instruction
     0x1503: 15 [68 CD]  |   DCR D
     0x1504: 68 [CD 62]  |   MOV L, B
     0x1505: CD [62 15]  |   CAL 0x1562
     0x1506: 62 [15 3A]  |   MOV H, D
     0x1507: 15 [3A 2A]  |   DCR D
     0x1508: 3A [2A 20]  |   LDA 0x202A
     0x1509: 2A [20 67]  |   LHLD 0x6720
     0x150a: 20 [67 CD]  |   Undefined instruction
     0x150b: 67 [CD 6F]  |   MOV H, A
     0x150c: CD [6F 15]  |   CAL 0x156F
     0x150d: 6F [15 22]  |   MOV L, A
     0x150e: 15 [22 64]  |   DCR D
     0x150f: 22 [64 20]  |   SHLD 0x2064
     0x1510: 64 [20 3E]  |   MOV H, H
     0x1511: 20 [3E 05]  |   Undefined instruction
     0x1512: 3E [05 32]  |   MVI A, 0x05
     0x1513: 05 [32 25]  |   DCR B
     0x1514: 32 [25 20]  |   STA 0x2025
     0x1515: 25 [20 CD]  |   DCR H
     0x1516: 20 [CD 81]  |   Undefined instruction
     0x1517: CD [81 15]  |   CAL 0x1581
     0x1518: 81 [15 7E]  |   ADD C
     0x1519: 15 [7E A7]  |   DCR D
     0x151a: 7E [A7 CA]  |   MOV A, M
     0x151b: A7 [CA 30]  |   ANA A
     0x151c: CA [30 15]  |   JZ 0x1530
     0x151d: 30 [15 36]  |   Undefined instruction
     0x151e: 15 [36 00]  |   DCR D
     0x151f: 36 [00 CD]  |   MVI M, 0x00
     0x1520: 00 [CD 5F]  |   NOP
     0x1521: CD [5F 0A]  |   CAL 0x0A5F
     0x1522: 5F [0A CD]  |   MOV E, A
     0x1523: 0A [CD 3B]  |   LDAX B
     0x1524: CD [3B 1A]  |   CAL 0x1A3B
     0x1525: 3B [1A CD]  |   DCX SP
     0x1526: 1A [CD D3]  |   LDAX D
     0x1527: CD [D3 15]  |   CAL 0x15D3
     0x1528: D3 [15 3E]  |   OUT 0x15
     0x1529: 15 [3E 10]  |   DCR D
     0x152a: 3E [10 32]  |   MVI A, 0x10
     0x152b: 10 [32 03]  |   Undefined instruction
     0x152c: 32 [03 20]  |   STA 0x2003
     0x152d: 03 [20 C9]  |   INX B
     0x152e: 20 [C9 3E]  |   Undefined instruction
     0x152f: C9 [3E 03]  |   RET
     0x1530: 3E [03 32]  |   MVI A, 0x03
     0x1531: 03 [32 25]  |   INX B
     0x1532: 32 [25 20]  |   STA 0x2025
     0x1533: 25 [20 C3]  |   DCR H
     0x1534: 20 [C3 4A]  |   Undefined instruction
     0x1535: C3 [4A 15]  |   JMP 0x154A
     0x1536: 4A [15 21]  |   MOV C, D
     0x1537: 15 [21 03]  |   DCR D
     0x1538: 21 [03 20]  |   LXI H, 0x2003 
     0x1539: 03 [20 35]  |   INX B
     0x153a: 20 [35 C0]  |   Undefined instruction
     0x153b: 35 [C0 2A]  |   DCR M
     0x153c: C0 [2A 64]  |   RNZ
     0x153d: 2A [64 20]  |   LHLD 0x2064
     0x153e: 64 [20 06]  |   MOV H, H
     0x153f: 20 [06 10]  |   Undefined instruction
     0x1540: 06 [10 CD]  |   MVI B, 0x10
     0x1541: 10 [CD 24]  |   Undefined instruction
     0x1542: CD [24 14]  |   CAL 0x1424
     0x1543: 24 [14 3E]  |   INR H
     0x1544: 14 [3E 04]  |   INR D
     0x1545: 3E [04 32]  |   MVI A, 0x04
     0x1546: 04 [32 25]  |   INR B
     0x1547: 32 [25 20]  |   STA 0x2025
     0x1548: 25 [20 AF]  |   DCR H
     0x1549: 20 [AF 32]  |   Undefined instruction
     0x154a: AF [32 02]  |   XRA A
     0x154b: 32 [02 20]  |   STA 0x2002
     0x154c: 02 [20 06]  |   STAX B
     0x154d: 20 [06 F7]  |   Undefined instruction
     0x154e: 06 [F7 C3]  |   MVI B, 0xF7
     0x154f: F7 [C3 DC]  |   RST 6
     0x1550: C3 [DC 19]  |   JMP 0x19DC
     0x1551: DC [19 00]  |   CC 0x0019
     0x1552: 19 [00 0E]  |   DAD D
     0x1553: 00 [0E 00]  |   NOP
     0x1554: 0E [00 BC]  |   MVI C, 0x00
     0x1555: 00 [BC D4]  |   NOP
     0x1556: BC [D4 90]  |   CMP H
     0x1557: D4 [90 15]  |   CNC 0x1590
     0x1558: 90 [15 BC]  |   SUB B
     0x1559: 15 [BC D0]  |   DCR D
     0x155a: BC [D0 C6]  |   CMP H
     0x155b: D0 [C6 10]  |   RNC
     0x155c: C6 [10 0C]  |   ADI 0x10
     0x155d: 10 [0C C3]  |   Undefined instruction
     0x155e: 0C [C3 5A]  |   INR C
     0x155f: C3 [5A 15]  |   JMP 0x155A
     0x1560: 5A [15 3A]  |   MOV E, D
     0x1561: 15 [3A 09]  |   DCR D
     0x1562: 3A [09 20]  |   LDA 0x2009
     0x1563: 09 [20 65]  |   DAD B
     0x1564: 20 [65 CD]  |   Undefined instruction
     0x1565: 65 [CD 54]  |   MOV H, L
     0x1566: CD [54 15]  |   CAL 0x1554
     0x1567: 54 [15 41]  |   MOV D, H
     0x1568: 15 [41 05]  |   DCR D
     0x1569: 41 [05 DE]  |   MOV B, C
     0x156a: 05 [DE 10]  |   DCR B
     0x156b: DE [10 6F]  |   SBI 0x10
     0x156c: 10 [6F C9]  |   Undefined instruction
     0x156d: 6F [C9 3A]  |   MOV L, A
     0x156e: C9 [3A 0A]  |   RET
     0x156f: 3A [0A 20]  |   LDA 0x200A
     0x1570: 0A [20 CD]  |   LDAX B
     0x1571: 20 [CD 54]  |   Undefined instruction
     0x1572: CD [54 15]  |   CAL 0x1554
     0x1573: 54 [15 DE]  |   MOV D, H
     0x1574: 15 [DE 10]  |   DCR D
     0x1575: DE [10 67]  |   SBI 0x10
     0x1576: 10 [67 C9]  |   Undefined instruction
     0x1577: 67 [C9 3E]  |   MOV H, A
     0x1578: C9 [3E 01]  |   RET
     0x1579: 3E [01 32]  |   MVI A, 0x01
     0x157a: 01 [32 85]  |   LXI B, 0x8532 
     0x157b: 32 [85 20]  |   STA 0x2085
     0x157c: 85 [20 C3]  |   ADD L
     0x157d: 20 [C3 45]  |   Undefined instruction
     0x157e: C3 [45 15]  |   JMP 0x1545
     0x157f: 45 [15 78]  |   MOV B, L
     0x1580: 15 [78 07]  |   DCR D
     0x1581: 78 [07 07]  |   MOV A, B
     0x1582: 07 [07 07]  |   RLC
     0x1583: 07 [07 80]  |   RLC
     0x1584: 07 [80 80]  |   RLC
     0x1585: 80 [80 80]  |   ADD B
     0x1586: 80 [80 81]  |   ADD B
     0x1587: 80 [81 3D]  |   ADD B
     0x1588: 81 [3D 6F]  |   ADD C
     0x1589: 3D [6F 3A]  |   DCR A
     0x158a: 6F [3A 67]  |   MOV L, A
     0x158b: 3A [67 20]  |   LDA 0x2067
     0x158c: 67 [20 67]  |   MOV H, A
     0x158d: 20 [67 C9]  |   Undefined instruction
     0x158e: 67 [C9 0C]  |   MOV H, A
     0x158f: C9 [0C C6]  |   RET
     0x1590: 0C [C6 10]  |   INR C
     0x1591: C6 [10 FA]  |   ADI 0x10
     0x1592: 10 [FA 90]  |   Undefined instruction
     0x1593: FA [90 15]  |   JM 0x1590
     0x1594: 90 [15 C9]  |   SUB B
     0x1595: 15 [C9 3A]  |   DCR D
     0x1596: C9 [3A 0D]  |   RET
     0x1597: 3A [0D 20]  |   LDA 0x200D
     0x1598: 0D [20 A7]  |   DCR C
     0x1599: 20 [A7 C2]  |   Undefined instruction
     0x159a: A7 [C2 B7]  |   ANA A
     0x159b: C2 [B7 15]  |   JNZ 0x15B7
     0x159c: B7 [15 21]  |   ORA A
     0x159d: 15 [21 A4]  |   DCR D
     0x159e: 21 [A4 3E]  |   LXI H, 0x3EA4 
     0x159f: A4 [3E CD]  |   ANA H
     0x15a0: 3E [CD C5]  |   MVI A, 0xCD
     0x15a1: CD [C5 15]  |   CAL 0x15C5
     0x15a2: C5 [15 D0]  |   PUSH B
     0x15a3: 15 [D0 06]  |   DCR D
     0x15a4: D0 [06 FE]  |   RNC
     0x15a5: 06 [FE 3E]  |   MVI B, 0xFE
     0x15a6: FE [3E 01]  |   CPI 0x3E
     0x15a7: 3E [01 32]  |   MVI A, 0x01
     0x15a8: 01 [32 0D]  |   LXI B, 0x0D32 
     0x15a9: 32 [0D 20]  |   STA 0x200D
     0x15aa: 0D [20 78]  |   DCR C
     0x15ab: 20 [78 32]  |   Undefined instruction
     0x15ac: 78 [32 08]  |   MOV A, B
     0x15ad: 32 [08 20]  |   STA 0x2008
     0x15ae: 08 [20 3A]  |   Undefined instruction
     0x15af: 20 [3A 0E]  |   Undefined instruction
     0x15b0: 3A [0E 20]  |   LDA 0x200E
     0x15b1: 0E [20 32]  |   MVI C, 0x20
     0x15b2: 20 [32 07]  |   Undefined instruction
     0x15b3: 32 [07 20]  |   STA 0x2007
     0x15b4: 07 [20 C9]  |   RLC
     0x15b5: 20 [C9 21]  |   Undefined instruction
     0x15b6: C9 [21 24]  |   RET
     0x15b7: 21 [24 25]  |   LXI H, 0x2524 
     0x15b8: 24 [25 CD]  |   INR H
     0x15b9: 25 [CD C5]  |   DCR H
     0x15ba: CD [C5 15]  |   CAL 0x15C5
     0x15bb: C5 [15 D0]  |   PUSH B
     0x15bc: 15 [D0 CD]  |   DCR D
     0x15bd: D0 [CD F1]  |   RNC
     0x15be: CD [F1 18]  |   CAL 0x18F1
     0x15bf: F1 [18 AF]  |   POP PSW
     0x15c0: 18 [AF C3]  |   Undefined instruction
     0x15c1: AF [C3 A9]  |   XRA A
     0x15c2: C3 [A9 15]  |   JMP 0x15A9
     0x15c3: A9 [15 06]  |   XRA C
     0x15c4: 15 [06 17]  |   DCR D
     0x15c5: 06 [17 7E]  |   MVI B, 0x17
     0x15c6: 17 [7E A7]  |   RAL
     0x15c7: 7E [A7 C2]  |   MOV A, M
     0x15c8: A7 [C2 6B]  |   ANA A
     0x15c9: C2 [6B 16]  |   JNZ 0x166B
     0x15ca: 6B [16 23]  |   MOV L, E
     0x15cb: 16 [23 05]  |   MVI D, 0x23
     0x15cc: 23 [05 C2]  |   INX H
     0x15cd: 05 [C2 C7]  |   DCR B
     0x15ce: C2 [C7 15]  |   JNZ 0x15C7
     0x15cf: C7 [15 C9]  |   RST 0
     0x15d0: 15 [C9 00]  |   DCR D
     0x15d1: C9 [00 CD]  |   RET
     0x15d2: 00 [CD 74]  |   NOP
     0x15d3: CD [74 14]  |   CAL 0x1474
     0x15d4: 74 [14 E5]  |   MOV M, H
     0x15d5: 14 [E5 C5]  |   INR D
     0x15d6: E5 [C5 E5]  |   PUSH H
     0x15d7: C5 [E5 1A]  |   PUSH B
     0x15d8: E5 [1A D3]  |   PUSH H
     0x15d9: 1A [D3 04]  |   LDAX D
     0x15da: D3 [04 DB]  |   OUT 0x04
     0x15db: 04 [DB 03]  |   INR B
     0x15dc: DB [03 77]  |   IN 0x03
     0x15dd: 03 [77 23]  |   INX B
     0x15de: 77 [23 13]  |   MOV M, A
     0x15df: 23 [13 AF]  |   INX H
     0x15e0: 13 [AF D3]  |   INX D
     0x15e1: AF [D3 04]  |   XRA A
     0x15e2: D3 [04 DB]  |   OUT 0x04
     0x15e3: 04 [DB 03]  |   INR B
     0x15e4: DB [03 77]  |   IN 0x03
     0x15e5: 03 [77 E1]  |   INX B
     0x15e6: 77 [E1 01]  |   MOV M, A
     0x15e7: E1 [01 20]  |   POP H
     0x15e8: 01 [20 00]  |   LXI B, 0x0020 
     0x15e9: 20 [00 09]  |   Undefined instruction
     0x15ea: 00 [09 C1]  |   NOP
     0x15eb: 09 [C1 05]  |   DAD B
     0x15ec: C1 [05 C2]  |   POP B
     0x15ed: 05 [C2 D7]  |   DCR B
     0x15ee: C2 [D7 15]  |   JNZ 0x15D7
     0x15ef: D7 [15 E1]  |   RST 2
     0x15f0: 15 [E1 C9]  |   DCR D
     0x15f1: E1 [C9 CD]  |   POP H
     0x15f2: C9 [CD 11]  |   RET
     0x15f3: CD [11 16]  |   CAL 0x1611
     0x15f4: 11 [16 01]  |   LXI D, 0x0116 
     0x15f5: 16 [01 00]  |   MVI D, 0x01
     0x15f6: 01 [00 37]  |   LXI B, 0x3700 
     0x15f7: 00 [37 7E]  |   NOP
     0x15f8: 37 [7E A7]  |   STC
     0x15f9: 7E [A7 CA]  |   MOV A, M
     0x15fa: A7 [CA FF]  |   ANA A
     0x15fb: CA [FF 15]  |   JZ 0x15FF
     0x15fc: FF [15 0C]  |   RST 7
     0x15fd: 15 [0C 23]  |   DCR D
     0x15fe: 0C [23 05]  |   INR C
     0x15ff: 23 [05 C2]  |   INX H
     0x1600: 05 [C2 F9]  |   DCR B
     0x1601: C2 [F9 15]  |   JNZ 0x15F9
     0x1602: F9 [15 79]  |   SPHL
     0x1603: 15 [79 32]  |   DCR D
     0x1604: 79 [32 82]  |   MOV A, C
     0x1605: 32 [82 20]  |   STA 0x2082
     0x1606: 82 [20 FE]  |   ADD D
     0x1607: 20 [FE 01]  |   Undefined instruction
     0x1608: FE [01 C0]  |   CPI 0x01
     0x1609: 01 [C0 21]  |   LXI B, 0x21C0 
     0x160a: C0 [21 6B]  |   RNZ
     0x160b: 21 [6B 20]  |   LXI H, 0x206B 
     0x160c: 6B [20 36]  |   MOV L, E
     0x160d: 20 [36 01]  |   Undefined instruction
     0x160e: 36 [01 C9]  |   MVI M, 0x01
     0x160f: 01 [C9 2E]  |   LXI B, 0x2EC9 
     0x1610: C9 [2E 00]  |   RET
     0x1611: 2E [00 3A]  |   MVI L, 0x00
     0x1612: 00 [3A 67]  |   NOP
     0x1613: 3A [67 20]  |   LDA 0x2067
     0x1614: 67 [20 67]  |   MOV H, A
     0x1615: 20 [67 C9]  |   Undefined instruction
     0x1616: 67 [C9 3A]  |   MOV H, A
     0x1617: C9 [3A 15]  |   RET
     0x1618: 3A [15 20]  |   LDA 0x2015
     0x1619: 15 [20 FE]  |   DCR D
     0x161a: 20 [FE FF]  |   Undefined instruction
     0x161b: FE [FF C0]  |   CPI 0xFF
     0x161c: FF [C0 21]  |   RST 7
     0x161d: C0 [21 10]  |   RNZ
     0x161e: 21 [10 20]  |   LXI H, 0x2010 
     0x161f: 10 [20 7E]  |   Undefined instruction
     0x1620: 20 [7E 23]  |   Undefined instruction
     0x1621: 7E [23 46]  |   MOV A, M
     0x1622: 23 [46 B0]  |   INX H
     0x1623: 46 [B0 C0]  |   MOV B, M
     0x1624: B0 [C0 3A]  |   ORA B
     0x1625: C0 [3A 25]  |   RNZ
     0x1626: 3A [25 20]  |   LDA 0x2025
     0x1627: 25 [20 A7]  |   DCR H
     0x1628: 20 [A7 C0]  |   Undefined instruction
     0x1629: A7 [C0 3A]  |   ANA A
     0x162a: C0 [3A EF]  |   RNZ
     0x162b: 3A [EF 20]  |   LDA 0x20EF
     0x162c: EF [20 A7]  |   RST 5
     0x162d: 20 [A7 CA]  |   Undefined instruction
     0x162e: A7 [CA 52]  |   ANA A
     0x162f: CA [52 16]  |   JZ 0x1652
     0x1630: 52 [16 3A]  |   MOV D, D
     0x1631: 16 [3A 2D]  |   MVI D, 0x3A
     0x1632: 3A [2D 20]  |   LDA 0x202D
     0x1633: 2D [20 A7]  |   DCR L
     0x1634: 20 [A7 C2]  |   Undefined instruction
     0x1635: A7 [C2 48]  |   ANA A
     0x1636: C2 [48 16]  |   JNZ 0x1648
     0x1637: 48 [16 CD]  |   MOV C, B
     0x1638: 16 [CD C0]  |   MVI D, 0xCD
     0x1639: CD [C0 17]  |   CAL 0x17C0
     0x163a: C0 [17 E6]  |   RNZ
     0x163b: 17 [E6 10]  |   RAL
     0x163c: E6 [10 C8]  |   ANI 0x10
     0x163d: 10 [C8 3E]  |   Undefined instruction
     0x163e: C8 [3E 01]  |   RZ
     0x163f: 3E [01 32]  |   MVI A, 0x01
     0x1640: 01 [32 25]  |   LXI B, 0x2532 
     0x1641: 32 [25 20]  |   STA 0x2025
     0x1642: 25 [20 32]  |   DCR H
     0x1643: 20 [32 2D]  |   Undefined instruction
     0x1644: 32 [2D 20]  |   STA 0x202D
     0x1645: 2D [20 C9]  |   DCR L
     0x1646: 20 [C9 CD]  |   Undefined instruction
     0x1647: C9 [CD C0]  |   RET
     0x1648: CD [C0 17]  |   CAL 0x17C0
     0x1649: C0 [17 E6]  |   RNZ
     0x164a: 17 [E6 10]  |   RAL
     0x164b: E6 [10 C0]  |   ANI 0x10
     0x164c: 10 [C0 32]  |   Undefined instruction
     0x164d: C0 [32 2D]  |   RNZ
     0x164e: 32 [2D 20]  |   STA 0x202D
     0x164f: 2D [20 C9]  |   DCR L
     0x1650: 20 [C9 21]  |   Undefined instruction
     0x1651: C9 [21 25]  |   RET
     0x1652: 21 [25 20]  |   LXI H, 0x2025 
     0x1653: 25 [20 36]  |   DCR H
     0x1654: 20 [36 01]  |   Undefined instruction
     0x1655: 36 [01 2A]  |   MVI M, 0x01
     0x1656: 01 [2A ED]  |   LXI B, 0xED2A 
     0x1657: 2A [ED 20]  |   LHLD 0x20ED
     0x1658: ED [20 23]  |   Undefined instruction
     0x1659: 20 [23 7D]  |   Undefined instruction
     0x165a: 23 [7D FE]  |   INX H
     0x165b: 7D [FE 7E]  |   MOV A, L
     0x165c: FE [7E DA]  |   CPI 0x7E
     0x165d: 7E [DA 63]  |   MOV A, M
     0x165e: DA [63 16]  |   JC 0x1663
     0x165f: 63 [16 2E]  |   MOV H, E
     0x1660: 16 [2E 74]  |   MVI D, 0x2E
     0x1661: 2E [74 22]  |   MVI L, 0x74
     0x1662: 74 [22 ED]  |   MOV M, H
     0x1663: 22 [ED 20]  |   SHLD 0x20ED
     0x1664: ED [20 7E]  |   Undefined instruction
     0x1665: 20 [7E 32]  |   Undefined instruction
     0x1666: 7E [32 1D]  |   MOV A, M
     0x1667: 32 [1D 20]  |   STA 0x201D
     0x1668: 1D [20 C9]  |   DCR E
     0x1669: 20 [C9 37]  |   Undefined instruction
     0x166a: C9 [37 C9]  |   RET
     0x166b: 37 [C9 AF]  |   STC
     0x166c: C9 [AF CD]  |   RET
     0x166d: AF [CD 8B]  |   XRA A
     0x166e: CD [8B 1A]  |   CAL 0x1A8B
     0x166f: 8B [1A CD]  |   ADC E
     0x1670: 1A [CD 10]  |   LDAX D
     0x1671: CD [10 19]  |   CAL 0x1910
     0x1672: 10 [19 36]  |   Undefined instruction
     0x1673: 19 [36 00]  |   DAD D
     0x1674: 36 [00 CD]  |   MVI M, 0x00
     0x1675: 00 [CD CA]  |   NOP
     0x1676: CD [CA 09]  |   CAL 0x09CA
     0x1677: CA [09 23]  |   JZ 0x2309
     0x1678: 09 [23 11]  |   DAD B
     0x1679: 23 [11 F5]  |   INX H
     0x167a: 11 [F5 20]  |   LXI D, 0x20F5 
     0x167b: F5 [20 1A]  |   PUSH PSW
     0x167c: 20 [1A BE]  |   Undefined instruction
     0x167d: 1A [BE 1B]  |   LDAX D
     0x167e: BE [1B 2B]  |   CMP M
     0x167f: 1B [2B 1A]  |   DCX D
     0x1680: 2B [1A CA]  |   DCX H
     0x1681: 1A [CA 8B]  |   LDAX D
     0x1682: CA [8B 16]  |   JZ 0x168B
     0x1683: 8B [16 D2]  |   ADC E
     0x1684: 16 [D2 98]  |   MVI D, 0xD2
     0x1685: D2 [98 16]  |   JNC 0x1698
     0x1686: 98 [16 C3]  |   SBB B
     0x1687: 16 [C3 8F]  |   MVI D, 0xC3
     0x1688: C3 [8F 16]  |   JMP 0x168F
     0x1689: 8F [16 BE]  |   ADC A
     0x168a: 16 [BE D2]  |   MVI D, 0xBE
     0x168b: BE [D2 98]  |   CMP M
     0x168c: D2 [98 16]  |   JNC 0x1698
     0x168d: 98 [16 7E]  |   SBB B
     0x168e: 16 [7E 12]  |   MVI D, 0x7E
     0x168f: 7E [12 13]  |   MOV A, M
     0x1690: 12 [13 23]  |   STAX D
     0x1691: 13 [23 7E]  |   INX D
     0x1692: 23 [7E 12]  |   INX H
     0x1693: 7E [12 CD]  |   MOV A, M
     0x1694: 12 [CD 50]  |   STAX D
     0x1695: CD [50 19]  |   CAL 0x1950
     0x1696: 50 [19 3A]  |   MOV D, B
     0x1697: 19 [3A CE]  |   DAD D
     0x1698: 3A [CE 20]  |   LDA 0x20CE
     0x1699: CE [20 A7]  |   ACI 0x20
     0x169a: 20 [A7 CA]  |   Undefined instruction
     0x169b: A7 [CA C9]  |   ANA A
     0x169c: CA [C9 16]  |   JZ 0x16C9
     0x169d: C9 [16 21]  |   RET
     0x169e: 16 [21 03]  |   MVI D, 0x21
     0x169f: 21 [03 28]  |   LXI H, 0x2803 
     0x16a0: 03 [28 11]  |   INX B
     0x16a1: 28 [11 A6]  |   Undefined instruction
     0x16a2: 11 [A6 1A]  |   LXI D, 0x1AA6 
     0x16a3: A6 [1A 0E]  |   ANA M
     0x16a4: 1A [0E 14]  |   LDAX D
     0x16a5: 0E [14 CD]  |   MVI C, 0x14
     0x16a6: 14 [CD 93]  |   INR D
     0x16a7: CD [93 0A]  |   CAL 0x0A93
     0x16a8: 93 [0A 25]  |   SUB E
     0x16a9: 0A [25 25]  |   LDAX B
     0x16aa: 25 [25 06]  |   DCR H
     0x16ab: 25 [06 1B]  |   DCR H
     0x16ac: 06 [1B 3A]  |   MVI B, 0x1B
     0x16ad: 1B [3A 67]  |   DCX D
     0x16ae: 3A [67 20]  |   LDA 0x2067
     0x16af: 67 [20 0F]  |   MOV H, A
     0x16b0: 20 [0F DA]  |   Undefined instruction
     0x16b1: 0F [DA B7]  |   RRC
     0x16b2: DA [B7 16]  |   JC 0x16B7
     0x16b3: B7 [16 06]  |   ORA A
     0x16b4: 16 [06 1C]  |   MVI D, 0x06
     0x16b5: 06 [1C 78]  |   MVI B, 0x1C
     0x16b6: 1C [78 CD]  |   INR E
     0x16b7: 78 [CD FF]  |   MOV A, B
     0x16b8: CD [FF 08]  |   CAL 0x08FF
     0x16b9: FF [08 CD]  |   RST 7
     0x16ba: 08 [CD B1]  |   Undefined instruction
     0x16bb: CD [B1 0A]  |   CAL 0x0AB1
     0x16bc: B1 [0A CD]  |   ORA C
     0x16bd: 0A [CD E7]  |   LDAX B
     0x16be: CD [E7 18]  |   CAL 0x18E7
     0x16bf: E7 [18 7E]  |   RST 4
     0x16c0: 18 [7E A7]  |   Undefined instruction
     0x16c1: 7E [A7 CA]  |   MOV A, M
     0x16c2: A7 [CA C9]  |   ANA A
     0x16c3: CA [C9 16]  |   JZ 0x16C9
     0x16c4: C9 [16 C3]  |   RET
     0x16c5: 16 [C3 ED]  |   MVI D, 0xC3
     0x16c6: C3 [ED 02]  |   JMP 0x02ED
     0x16c7: ED [02 21]  |   Undefined instruction
     0x16c8: 02 [21 18]  |   STAX B
     0x16c9: 21 [18 2D]  |   LXI H, 0x2D18 
     0x16ca: 18 [2D 11]  |   Undefined instruction
     0x16cb: 2D [11 A6]  |   DCR L
     0x16cc: 11 [A6 1A]  |   LXI D, 0x1AA6 
     0x16cd: A6 [1A 0E]  |   ANA M
     0x16ce: 1A [0E 0A]  |   LDAX D
     0x16cf: 0E [0A CD]  |   MVI C, 0x0A
     0x16d0: 0A [CD 93]  |   LDAX B
     0x16d1: CD [93 0A]  |   CAL 0x0A93
     0x16d2: 93 [0A CD]  |   SUB E
     0x16d3: 0A [CD B6]  |   LDAX B
     0x16d4: CD [B6 0A]  |   CAL 0x0AB6
     0x16d5: B6 [0A CD]  |   ORA M
     0x16d6: 0A [CD D6]  |   LDAX B
     0x16d7: CD [D6 09]  |   CAL 0x09D6
     0x16d8: D6 [09 AF]  |   SUI 0x09
     0x16d9: 09 [AF 32]  |   DAD B
     0x16da: AF [32 EF]  |   XRA A
     0x16db: 32 [EF 20]  |   STA 0x20EF
     0x16dc: EF [20 D3]  |   RST 5
     0x16dd: 20 [D3 05]  |   Undefined instruction
     0x16de: D3 [05 CD]  |   OUT 0x05
     0x16df: 05 [CD D1]  |   DCR B
     0x16e0: CD [D1 19]  |   CAL 0x19D1
     0x16e1: D1 [19 C3]  |   POP D
     0x16e2: 19 [C3 89]  |   DAD D
     0x16e3: C3 [89 0B]  |   JMP 0x0B89
     0x16e4: 89 [0B 31]  |   ADC C
     0x16e5: 0B [31 00]  |   DCX B
     0x16e6: 31 [00 24]  |   LXI SP, 0x2400 
     0x16e7: 00 [24 FB]  |   NOP
     0x16e8: 24 [FB AF]  |   INR H
     0x16e9: FB [AF 32]  |   EI
     0x16ea: AF [32 15]  |   XRA A
     0x16eb: 32 [15 20]  |   STA 0x2015
     0x16ec: 15 [20 CD]  |   DCR D
     0x16ed: 20 [CD D8]  |   Undefined instruction
     0x16ee: CD [D8 14]  |   CAL 0x14D8
     0x16ef: D8 [14 06]  |   RC
     0x16f0: 14 [06 04]  |   INR D
     0x16f1: 06 [04 CD]  |   MVI B, 0x04
     0x16f2: 04 [CD FA]  |   INR B
     0x16f3: CD [FA 18]  |   CAL 0x18FA
     0x16f4: FA [18 CD]  |   JM 0xCD18
     0x16f5: 18 [CD 59]  |   Undefined instruction
     0x16f6: CD [59 0A]  |   CAL 0x0A59
     0x16f7: 59 [0A C2]  |   MOV E, C
     0x16f8: 0A [C2 EE]  |   LDAX B
     0x16f9: C2 [EE 16]  |   JNZ 0x16EE
     0x16fa: EE [16 CD]  |   XRI 0x16
     0x16fb: 16 [CD D7]  |   MVI D, 0xCD
     0x16fc: CD [D7 19]  |   CAL 0x19D7
     0x16fd: D7 [19 21]  |   RST 2
     0x16fe: 19 [21 01]  |   DAD D
     0x16ff: 21 [01 27]  |   LXI H, 0x2701 
     0x1700: 01 [27 CD]  |   LXI B, 0xCD27 
     0x1701: 27 [CD FA]  |   DAA
     0x1702: CD [FA 19]  |   CAL 0x19FA
     0x1703: FA [19 AF]  |   JM 0xAF19
     0x1704: 19 [AF CD]  |   DAD D
     0x1705: AF [CD 8B]  |   XRA A
     0x1706: CD [8B 1A]  |   CAL 0x1A8B
     0x1707: 8B [1A 06]  |   ADC E
     0x1708: 1A [06 FB]  |   LDAX D
     0x1709: 06 [FB C3]  |   MVI B, 0xFB
     0x170a: FB [C3 6B]  |   EI
     0x170b: C3 [6B 19]  |   JMP 0x196B
     0x170c: 6B [19 CD]  |   MOV L, E
     0x170d: 19 [CD CA]  |   DAD D
     0x170e: CD [CA 09]  |   CAL 0x09CA
     0x170f: CA [09 23]  |   JZ 0x2309
     0x1710: 09 [23 7E]  |   DAD B
     0x1711: 23 [7E 11]  |   INX H
     0x1712: 7E [11 B8]  |   MOV A, M
     0x1713: 11 [B8 1C]  |   LXI D, 0x1CB8 
     0x1714: B8 [1C 21]  |   CMP B
     0x1715: 1C [21 A1]  |   INR E
     0x1716: 21 [A1 1A]  |   LXI H, 0x1AA1 
     0x1717: A1 [1A 0E]  |   ANA C
     0x1718: 1A [0E 04]  |   LDAX D
     0x1719: 0E [04 47]  |   MVI C, 0x04
     0x171a: 04 [47 1A]  |   INR B
     0x171b: 47 [1A B8]  |   MOV B, A
     0x171c: 1A [B8 D2]  |   LDAX D
     0x171d: B8 [D2 27]  |   CMP B
     0x171e: D2 [27 17]  |   JNC 0x1727
     0x171f: 27 [17 23]  |   DAA
     0x1720: 17 [23 13]  |   RAL
     0x1721: 23 [13 0D]  |   INX H
     0x1722: 13 [0D C2]  |   INX D
     0x1723: 0D [C2 1C]  |   DCR C
     0x1724: C2 [1C 17]  |   JNZ 0x171C
     0x1725: 1C [17 7E]  |   INR E
     0x1726: 17 [7E 32]  |   RAL
     0x1727: 7E [32 CF]  |   MOV A, M
     0x1728: 32 [CF 20]  |   STA 0x20CF
     0x1729: CF [20 C9]  |   RST 1
     0x172a: 20 [C9 3A]  |   Undefined instruction
     0x172b: C9 [3A 25]  |   RET
     0x172c: 3A [25 20]  |   LDA 0x2025
     0x172d: 25 [20 FE]  |   DCR H
     0x172e: 20 [FE 00]  |   Undefined instruction
     0x172f: FE [00 C2]  |   CPI 0x00
     0x1730: 00 [C2 39]  |   NOP
     0x1731: C2 [39 17]  |   JNZ 0x1739
     0x1732: 39 [17 06]  |   DAD SP
     0x1733: 17 [06 FD]  |   RAL
     0x1734: 06 [FD C3]  |   MVI B, 0xFD
     0x1735: FD [C3 DC]  |   Undefined instruction
     0x1736: C3 [DC 19]  |   JMP 0x19DC
     0x1737: DC [19 06]  |   CC 0x0619
     0x1738: 19 [06 02]  |   DAD D
     0x1739: 06 [02 C3]  |   MVI B, 0x02
     0x173a: 02 [C3 FA]  |   STAX B
     0x173b: C3 [FA 18]  |   JMP 0x18FA
     0x173c: FA [18 00]  |   JM 0x0018
     0x173d: 18 [00 00]  |   Undefined instruction
     0x173e: 00 [00 21]  |   NOP
     0x173f: 00 [21 9B]  |   NOP
     0x1740: 21 [9B 20]  |   LXI H, 0x209B 
     0x1741: 9B [20 35]  |   SBB E
     0x1742: 20 [35 CC]  |   Undefined instruction
     0x1743: 35 [CC 6D]  |   DCR M
     0x1744: CC [6D 17]  |   CZ 0x176D
     0x1745: 6D [17 3A]  |   MOV L, L
     0x1746: 17 [3A 68]  |   RAL
     0x1747: 3A [68 20]  |   LDA 0x2068
     0x1748: 68 [20 A7]  |   MOV L, B
     0x1749: 20 [A7 CA]  |   Undefined instruction
     0x174a: A7 [CA 6D]  |   ANA A
     0x174b: CA [6D 17]  |   JZ 0x176D
     0x174c: 6D [17 21]  |   MOV L, L
     0x174d: 17 [21 96]  |   RAL
     0x174e: 21 [96 20]  |   LXI H, 0x2096 
     0x174f: 96 [20 35]  |   SUB M
     0x1750: 20 [35 C0]  |   Undefined instruction
     0x1751: 35 [C0 21]  |   DCR M
     0x1752: C0 [21 98]  |   RNZ
     0x1753: 21 [98 20]  |   LXI H, 0x2098 
     0x1754: 98 [20 7E]  |   SBB B
     0x1755: 20 [7E D3]  |   Undefined instruction
     0x1756: 7E [D3 05]  |   MOV A, M
     0x1757: D3 [05 3A]  |   OUT 0x05
     0x1758: 05 [3A 82]  |   DCR B
     0x1759: 3A [82 20]  |   LDA 0x2082
     0x175a: 82 [20 A7]  |   ADD D
     0x175b: 20 [A7 CA]  |   Undefined instruction
     0x175c: A7 [CA 6D]  |   ANA A
     0x175d: CA [6D 17]  |   JZ 0x176D
     0x175e: 6D [17 2B]  |   MOV L, L
     0x175f: 17 [2B 7E]  |   RAL
     0x1760: 2B [7E 2B]  |   DCX H
     0x1761: 7E [2B 77]  |   MOV A, M
     0x1762: 2B [77 2B]  |   DCX H
     0x1763: 77 [2B 36]  |   MOV M, A
     0x1764: 2B [36 01]  |   DCX H
     0x1765: 36 [01 3E]  |   MVI M, 0x01
     0x1766: 01 [3E 04]  |   LXI B, 0x043E 
     0x1767: 3E [04 32]  |   MVI A, 0x04
     0x1768: 04 [32 9B]  |   INR B
     0x1769: 32 [9B 20]  |   STA 0x209B
     0x176a: 9B [20 C9]  |   SBB E
     0x176b: 20 [C9 3A]  |   Undefined instruction
     0x176c: C9 [3A 98]  |   RET
     0x176d: 3A [98 20]  |   LDA 0x2098
     0x176e: 98 [20 E6]  |   SBB B
     0x176f: 20 [E6 30]  |   Undefined instruction
     0x1770: E6 [30 D3]  |   ANI 0x30
     0x1771: 30 [D3 05]  |   Undefined instruction
     0x1772: D3 [05 C9]  |   OUT 0x05
     0x1773: 05 [C9 3A]  |   DCR B
     0x1774: C9 [3A 95]  |   RET
     0x1775: 3A [95 20]  |   LDA 0x2095
     0x1776: 95 [20 A7]  |   SUB L
     0x1777: 20 [A7 CA]  |   Undefined instruction
     0x1778: A7 [CA AA]  |   ANA A
     0x1779: CA [AA 17]  |   JZ 0x17AA
     0x177a: AA [17 21]  |   XRA D
     0x177b: 17 [21 11]  |   RAL
     0x177c: 21 [11 1A]  |   LXI H, 0x1A11 
     0x177d: 11 [1A 11]  |   LXI D, 0x111A 
     0x177e: 1A [11 21]  |   LDAX D
     0x177f: 11 [21 1A]  |   LXI D, 0x1A21 
     0x1780: 21 [1A 3A]  |   LXI H, 0x3A1A 
     0x1781: 1A [3A 82]  |   LDAX D
     0x1782: 3A [82 20]  |   LDA 0x2082
     0x1783: 82 [20 BE]  |   ADD D
     0x1784: 20 [BE D2]  |   Undefined instruction
     0x1785: BE [D2 8E]  |   CMP M
     0x1786: D2 [8E 17]  |   JNC 0x178E
     0x1787: 8E [17 23]  |   ADC M
     0x1788: 17 [23 13]  |   RAL
     0x1789: 23 [13 C3]  |   INX H
     0x178a: 13 [C3 85]  |   INX D
     0x178b: C3 [85 17]  |   JMP 0x1785
     0x178c: 85 [17 1A]  |   ADD L
     0x178d: 17 [1A 32]  |   RAL
     0x178e: 1A [32 97]  |   LDAX D
     0x178f: 32 [97 20]  |   STA 0x2097
     0x1790: 97 [20 21]  |   SUB A
     0x1791: 20 [21 98]  |   Undefined instruction
     0x1792: 21 [98 20]  |   LXI H, 0x2098 
     0x1793: 98 [20 7E]  |   SBB B
     0x1794: 20 [7E E6]  |   Undefined instruction
     0x1795: 7E [E6 30]  |   MOV A, M
     0x1796: E6 [30 47]  |   ANI 0x30
     0x1797: 30 [47 7E]  |   Undefined instruction
     0x1798: 47 [7E E6]  |   MOV B, A
     0x1799: 7E [E6 0F]  |   MOV A, M
     0x179a: E6 [0F 07]  |   ANI 0x0F
     0x179b: 0F [07 FE]  |   RRC
     0x179c: 07 [FE 10]  |   RLC
     0x179d: FE [10 C2]  |   CPI 0x10
     0x179e: 10 [C2 A4]  |   Undefined instruction
     0x179f: C2 [A4 17]  |   JNZ 0x17A4
     0x17a0: A4 [17 3E]  |   ANA H
     0x17a1: 17 [3E 01]  |   RAL
     0x17a2: 3E [01 B0]  |   MVI A, 0x01
     0x17a3: 01 [B0 77]  |   LXI B, 0x77B0 
     0x17a4: B0 [77 AF]  |   ORA B
     0x17a5: 77 [AF 32]  |   MOV M, A
     0x17a6: AF [32 95]  |   XRA A
     0x17a7: 32 [95 20]  |   STA 0x2095
     0x17a8: 95 [20 21]  |   SUB L
     0x17a9: 20 [21 99]  |   Undefined instruction
     0x17aa: 21 [99 20]  |   LXI H, 0x2099 
     0x17ab: 99 [20 35]  |   SBB C
     0x17ac: 20 [35 C0]  |   Undefined instruction
     0x17ad: 35 [C0 06]  |   DCR M
     0x17ae: C0 [06 EF]  |   RNZ
     0x17af: 06 [EF C3]  |   MVI B, 0xEF
     0x17b0: EF [C3 DC]  |   RST 5
     0x17b1: C3 [DC 19]  |   JMP 0x19DC
     0x17b2: DC [19 06]  |   CC 0x0619
     0x17b3: 19 [06 EF]  |   DAD D
     0x17b4: 06 [EF 21]  |   MVI B, 0xEF
     0x17b5: EF [21 98]  |   RST 5
     0x17b6: 21 [98 20]  |   LXI H, 0x2098 
     0x17b7: 98 [20 7E]  |   SBB B
     0x17b8: 20 [7E A0]  |   Undefined instruction
     0x17b9: 7E [A0 77]  |   MOV A, M
     0x17ba: A0 [77 D3]  |   ANA B
     0x17bb: 77 [D3 05]  |   MOV M, A
     0x17bc: D3 [05 C9]  |   OUT 0x05
     0x17bd: 05 [C9 00]  |   DCR B
     0x17be: C9 [00 3A]  |   RET
     0x17bf: 00 [3A 67]  |   NOP
     0x17c0: 3A [67 20]  |   LDA 0x2067
     0x17c1: 67 [20 0F]  |   MOV H, A
     0x17c2: 20 [0F D2]  |   Undefined instruction
     0x17c3: 0F [D2 CA]  |   RRC
     0x17c4: D2 [CA 17]  |   JNC 0x17CA
     0x17c5: CA [17 DB]  |   JZ 0xDB17
     0x17c6: 17 [DB 01]  |   RAL
     0x17c7: DB [01 C9]  |   IN 0x01
     0x17c8: 01 [C9 DB]  |   LXI B, 0xDBC9 
     0x17c9: C9 [DB 02]  |   RET
     0x17ca: DB [02 C9]  |   IN 0x02
     0x17cb: 02 [C9 DB]  |   STAX B
     0x17cc: C9 [DB 02]  |   RET
     0x17cd: DB [02 E6]  |   IN 0x02
     0x17ce: 02 [E6 04]  |   STAX B
     0x17cf: E6 [04 C8]  |   ANI 0x04
     0x17d0: 04 [C8 3A]  |   INR B
     0x17d1: C8 [3A 9A]  |   RZ
     0x17d2: 3A [9A 20]  |   LDA 0x209A
     0x17d3: 9A [20 A7]  |   SBB D
     0x17d4: 20 [A7 C0]  |   Undefined instruction
     0x17d5: A7 [C0 31]  |   ANA A
     0x17d6: C0 [31 00]  |   RNZ
     0x17d7: 31 [00 24]  |   LXI SP, 0x2400 
     0x17d8: 00 [24 06]  |   NOP
     0x17d9: 24 [06 04]  |   INR H
     0x17da: 06 [04 CD]  |   MVI B, 0x04
     0x17db: 04 [CD D6]  |   INR B
     0x17dc: CD [D6 09]  |   CAL 0x09D6
     0x17dd: D6 [09 05]  |   SUI 0x09
     0x17de: 09 [05 C2]  |   DAD B
     0x17df: 05 [C2 DC]  |   DCR B
     0x17e0: C2 [DC 17]  |   JNZ 0x17DC
     0x17e1: DC [17 3E]  |   CC 0x3E17
     0x17e2: 17 [3E 01]  |   RAL
     0x17e3: 3E [01 32]  |   MVI A, 0x01
     0x17e4: 01 [32 9A]  |   LXI B, 0x9A32 
     0x17e5: 32 [9A 20]  |   STA 0x209A
     0x17e6: 9A [20 CD]  |   SBB D
     0x17e7: 20 [CD D7]  |   Undefined instruction
     0x17e8: CD [D7 19]  |   CAL 0x19D7
     0x17e9: D7 [19 FB]  |   RST 2
     0x17ea: 19 [FB 11]  |   DAD D
     0x17eb: FB [11 BC]  |   EI
     0x17ec: 11 [BC 1C]  |   LXI D, 0x1CBC 
     0x17ed: BC [1C 21]  |   CMP H
     0x17ee: 1C [21 16]  |   INR E
     0x17ef: 21 [16 30]  |   LXI H, 0x3016 
     0x17f0: 16 [30 0E]  |   MVI D, 0x30
     0x17f1: 30 [0E 04]  |   Undefined instruction
     0x17f2: 0E [04 CD]  |   MVI C, 0x04
     0x17f3: 04 [CD 93]  |   INR B
     0x17f4: CD [93 0A]  |   CAL 0x0A93
     0x17f5: 93 [0A CD]  |   SUB E
     0x17f6: 0A [CD B1]  |   LDAX B
     0x17f7: CD [B1 0A]  |   CAL 0x0AB1
     0x17f8: B1 [0A AF]  |   ORA C
     0x17f9: 0A [AF 32]  |   LDAX B
     0x17fa: AF [32 9A]  |   XRA A
     0x17fb: 32 [9A 20]  |   STA 0x209A
     0x17fc: 9A [20 32]  |   SBB D
     0x17fd: 20 [32 93]  |   Undefined instruction
     0x17fe: 32 [93 20]  |   STA 0x2093
     0x17ff: 93 [20 C3]  |   SUB E
     0x1800: 20 [C3 C9]  |   Undefined instruction
     0x1801: C3 [C9 16]  |   JMP 0x16C9
     0x1802: C9 [16 21]  |   RET
     0x1803: 16 [21 84]  |   MVI D, 0x21
     0x1804: 21 [84 20]  |   LXI H, 0x2084 
     0x1805: 84 [20 7E]  |   ADD H
     0x1806: 20 [7E A7]  |   Undefined instruction
     0x1807: 7E [A7 CA]  |   MOV A, M
     0x1808: A7 [CA 07]  |   ANA A
     0x1809: CA [07 07]  |   JZ 0x0707
     0x180a: 07 [07 23]  |   RLC
     0x180b: 07 [23 7E]  |   RLC
     0x180c: 23 [7E A7]  |   INX H
     0x180d: 7E [A7 C0]  |   MOV A, M
     0x180e: A7 [C0 06]  |   ANA A
     0x180f: C0 [06 01]  |   RNZ
     0x1810: 06 [01 C3]  |   MVI B, 0x01
     0x1811: 01 [C3 FA]  |   LXI B, 0xFAC3 
     0x1812: C3 [FA 18]  |   JMP 0x18FA
     0x1813: FA [18 21]  |   JM 0x2118
     0x1814: 18 [21 10]  |   Undefined instruction
     0x1815: 21 [10 28]  |   LXI H, 0x2810 
     0x1816: 10 [28 11]  |   Undefined instruction
     0x1817: 28 [11 A3]  |   Undefined instruction
     0x1818: 11 [A3 1C]  |   LXI D, 0x1CA3 
     0x1819: A3 [1C 0E]  |   ANA E
     0x181a: 1C [0E 15]  |   INR E
     0x181b: 0E [15 CD]  |   MVI C, 0x15
     0x181c: 15 [CD F3]  |   DCR D
     0x181d: CD [F3 08]  |   CAL 0x08F3
     0x181e: F3 [08 3E]  |   DI
     0x181f: 08 [3E 0A]  |   Undefined instruction
     0x1820: 3E [0A 32]  |   MVI A, 0x0A
     0x1821: 0A [32 6C]  |   LDAX B
     0x1822: 32 [6C 20]  |   STA 0x206C
     0x1823: 6C [20 01]  |   MOV L, H
     0x1824: 20 [01 BE]  |   Undefined instruction
     0x1825: 01 [BE 1D]  |   LXI B, 0x1DBE 
     0x1826: BE [1D CD]  |   CMP M
     0x1827: 1D [CD 56]  |   DCR E
     0x1828: CD [56 18]  |   CAL 0x1856
     0x1829: 56 [18 DA]  |   MOV D, M
     0x182a: 18 [DA 37]  |   Undefined instruction
     0x182b: DA [37 18]  |   JC 0x1837
     0x182c: 37 [18 CD]  |   STC
     0x182d: 18 [CD 44]  |   Undefined instruction
     0x182e: CD [44 18]  |   CAL 0x1844
     0x182f: 44 [18 C3]  |   MOV B, H
     0x1830: 18 [C3 28]  |   Undefined instruction
     0x1831: C3 [28 18]  |   JMP 0x1828
     0x1832: 28 [18 CD]  |   Undefined instruction
     0x1833: 18 [CD B1]  |   Undefined instruction
     0x1834: CD [B1 0A]  |   CAL 0x0AB1
     0x1835: B1 [0A 01]  |   ORA C
     0x1836: 0A [01 CF]  |   LDAX B
     0x1837: 01 [CF 1D]  |   LXI B, 0x1DCF 
     0x1838: CF [1D CD]  |   RST 1
     0x1839: 1D [CD 56]  |   DCR E
     0x183a: CD [56 18]  |   CAL 0x1856
     0x183b: 56 [18 D8]  |   MOV D, M
     0x183c: 18 [D8 CD]  |   Undefined instruction
     0x183d: D8 [CD 4C]  |   RC
     0x183e: CD [4C 18]  |   CAL 0x184C
     0x183f: 4C [18 C3]  |   MOV C, H
     0x1840: 18 [C3 3A]  |   Undefined instruction
     0x1841: C3 [3A 18]  |   JMP 0x183A
     0x1842: 3A [18 C5]  |   LDA 0xC518
     0x1843: 18 [C5 06]  |   Undefined instruction
     0x1844: C5 [06 10]  |   PUSH B
     0x1845: 06 [10 CD]  |   MVI B, 0x10
     0x1846: 10 [CD 39]  |   Undefined instruction
     0x1847: CD [39 14]  |   CAL 0x1439
     0x1848: 39 [14 C1]  |   DAD SP
     0x1849: 14 [C1 C9]  |   INR D
     0x184a: C1 [C9 C5]  |   POP B
     0x184b: C9 [C5 3A]  |   RET
     0x184c: C5 [3A 6C]  |   PUSH B
     0x184d: 3A [6C 20]  |   LDA 0x206C
     0x184e: 6C [20 4F]  |   MOV L, H
     0x184f: 20 [4F CD]  |   Undefined instruction
     0x1850: 4F [CD 93]  |   MOV C, A
     0x1851: CD [93 0A]  |   CAL 0x0A93
     0x1852: 93 [0A C1]  |   SUB E
     0x1853: 0A [C1 C9]  |   LDAX B
     0x1854: C1 [C9 0A]  |   POP B
     0x1855: C9 [0A FE]  |   RET
     0x1856: 0A [FE FF]  |   LDAX B
     0x1857: FE [FF 37]  |   CPI 0xFF
     0x1858: FF [37 C8]  |   RST 7
     0x1859: 37 [C8 6F]  |   STC
     0x185a: C8 [6F 03]  |   RZ
     0x185b: 6F [03 0A]  |   MOV L, A
     0x185c: 03 [0A 67]  |   INX B
     0x185d: 0A [67 03]  |   LDAX B
     0x185e: 67 [03 0A]  |   MOV H, A
     0x185f: 03 [0A 5F]  |   INX B
     0x1860: 0A [5F 03]  |   LDAX B
     0x1861: 5F [03 0A]  |   MOV E, A
     0x1862: 03 [0A 57]  |   INX B
     0x1863: 0A [57 03]  |   LDAX B
     0x1864: 57 [03 A7]  |   MOV D, A
     0x1865: 03 [A7 C9]  |   INX B
     0x1866: A7 [C9 21]  |   ANA A
     0x1867: C9 [21 C2]  |   RET
     0x1868: 21 [C2 20]  |   LXI H, 0x20C2 
     0x1869: C2 [20 34]  |   JNZ 0x3420
     0x186a: 20 [34 23]  |   Undefined instruction
     0x186b: 34 [23 4E]  |   INR M
     0x186c: 23 [4E CD]  |   INX H
     0x186d: 4E [CD D9]  |   MOV C, M
     0x186e: CD [D9 01]  |   CAL 0x01D9
     0x186f: D9 [01 47]  |   Undefined instruction
     0x1870: 01 [47 3A]  |   LXI B, 0x3A47 
     0x1871: 47 [3A CA]  |   MOV B, A
     0x1872: 3A [CA 20]  |   LDA 0x20CA
     0x1873: CA [20 B8]  |   JZ 0xB820
     0x1874: 20 [B8 CA]  |   Undefined instruction
     0x1875: B8 [CA 98]  |   CMP B
     0x1876: CA [98 18]  |   JZ 0x1898
     0x1877: 98 [18 3A]  |   SBB B
     0x1878: 18 [3A C2]  |   Undefined instruction
     0x1879: 3A [C2 20]  |   LDA 0x20C2
     0x187a: C2 [20 E6]  |   JNZ 0xE620
     0x187b: 20 [E6 04]  |   Undefined instruction
     0x187c: E6 [04 2A]  |   ANI 0x04
     0x187d: 04 [2A CC]  |   INR B
     0x187e: 2A [CC 20]  |   LHLD 0x20CC
     0x187f: CC [20 C2]  |   CZ 0xC220
     0x1880: 20 [C2 88]  |   Undefined instruction
     0x1881: C2 [88 18]  |   JNZ 0x1888
     0x1882: 88 [18 11]  |   ADC B
     0x1883: 18 [11 30]  |   Undefined instruction
     0x1884: 11 [30 00]  |   LXI D, 0x0030 
     0x1885: 30 [00 19]  |   Undefined instruction
     0x1886: 00 [19 22]  |   NOP
     0x1887: 19 [22 C7]  |   DAD D
     0x1888: 22 [C7 20]  |   SHLD 0x20C7
     0x1889: C7 [20 21]  |   RST 0
     0x188a: 20 [21 C5]  |   Undefined instruction
     0x188b: 21 [C5 20]  |   LXI H, 0x20C5 
     0x188c: C5 [20 CD]  |   PUSH B
     0x188d: 20 [CD 3B]  |   Undefined instruction
     0x188e: CD [3B 1A]  |   CAL 0x1A3B
     0x188f: 3B [1A EB]  |   DCX SP
     0x1890: 1A [EB C3]  |   LDAX D
     0x1891: EB [C3 D3]  |   XCHG
     0x1892: C3 [D3 15]  |   JMP 0x15D3
     0x1893: D3 [15 00]  |   OUT 0x15
     0x1894: 15 [00 00]  |   DCR D
     0x1895: 00 [00 00]  |   NOP
     0x1896: 00 [00 3E]  |   NOP
     0x1897: 00 [3E 01]  |   NOP
     0x1898: 3E [01 32]  |   MVI A, 0x01
     0x1899: 01 [32 CB]  |   LXI B, 0xCB32 
     0x189a: 32 [CB 20]  |   STA 0x20CB
     0x189b: CB [20 C9]  |   Undefined instruction
     0x189c: 20 [C9 21]  |   Undefined instruction
     0x189d: C9 [21 50]  |   RET
     0x189e: 21 [50 20]  |   LXI H, 0x2050 
     0x189f: 50 [20 11]  |   MOV D, B
     0x18a0: 20 [11 C0]  |   Undefined instruction
     0x18a1: 11 [C0 1B]  |   LXI D, 0x1BC0 
     0x18a2: C0 [1B 06]  |   RNZ
     0x18a3: 1B [06 10]  |   DCX D
     0x18a4: 06 [10 CD]  |   MVI B, 0x10
     0x18a5: 10 [CD 32]  |   Undefined instruction
     0x18a6: CD [32 1A]  |   CAL 0x1A32
     0x18a7: 32 [1A 3E]  |   STA 0x3E1A
     0x18a8: 1A [3E 02]  |   LDAX D
     0x18a9: 3E [02 32]  |   MVI A, 0x02
     0x18aa: 02 [32 80]  |   STAX B
     0x18ab: 32 [80 20]  |   STA 0x2080
     0x18ac: 80 [20 3E]  |   ADD B
     0x18ad: 20 [3E FF]  |   Undefined instruction
     0x18ae: 3E [FF 32]  |   MVI A, 0xFF
     0x18af: FF [32 7E]  |   RST 7
     0x18b0: 32 [7E 20]  |   STA 0x207E
     0x18b1: 7E [20 3E]  |   MOV A, M
     0x18b2: 20 [3E 04]  |   Undefined instruction
     0x18b3: 3E [04 32]  |   MVI A, 0x04
     0x18b4: 04 [32 C1]  |   INR B
     0x18b5: 32 [C1 20]  |   STA 0x20C1
     0x18b6: C1 [20 3A]  |   POP B
     0x18b7: 20 [3A 55]  |   Undefined instruction
     0x18b8: 3A [55 20]  |   LDA 0x2055
     0x18b9: 55 [20 E6]  |   MOV D, L
     0x18ba: 20 [E6 01]  |   Undefined instruction
     0x18bb: E6 [01 CA]  |   ANI 0x01
     0x18bc: 01 [CA B8]  |   LXI B, 0xB8CA 
     0x18bd: CA [B8 18]  |   JZ 0x18B8
     0x18be: B8 [18 3A]  |   CMP B
     0x18bf: 18 [3A 55]  |   Undefined instruction
     0x18c0: 3A [55 20]  |   LDA 0x2055
     0x18c1: 55 [20 E6]  |   MOV D, L
     0x18c2: 20 [E6 01]  |   Undefined instruction
     0x18c3: E6 [01 C2]  |   ANI 0x01
     0x18c4: 01 [C2 C0]  |   LXI B, 0xC0C2 
     0x18c5: C2 [C0 18]  |   JNZ 0x18C0
     0x18c6: C0 [18 21]  |   RNZ
     0x18c7: 18 [21 11]  |   Undefined instruction
     0x18c8: 21 [11 33]  |   LXI H, 0x3311 
     0x18c9: 11 [33 3E]  |   LXI D, 0x3E33 
     0x18ca: 33 [3E 26]  |   INX SP
     0x18cb: 3E [26 00]  |   MVI A, 0x26
     0x18cc: 26 [00 CD]  |   MVI H, 0x00
     0x18cd: 00 [CD FF]  |   NOP
     0x18ce: CD [FF 08]  |   CAL 0x08FF
     0x18cf: FF [08 C3]  |   RST 7
     0x18d0: 08 [C3 B6]  |   Undefined instruction
     0x18d1: C3 [B6 0A]  |   JMP 0x0AB6
     0x18d2: B6 [0A 31]  |   ORA M
     0x18d3: 0A [31 00]  |   LDAX B
     0x18d4: 31 [00 24]  |   LXI SP, 0x2400 
     0x18d5: 00 [24 06]  |   NOP
     0x18d6: 24 [06 00]  |   INR H
     0x18d7: 06 [00 CD]  |   MVI B, 0x00
     0x18d8: 00 [CD E6]  |   NOP
     0x18d9: CD [E6 01]  |   CAL 0x01E6
     0x18da: E6 [01 CD]  |   ANI 0x01
     0x18db: 01 [CD 56]  |   LXI B, 0x56CD 
     0x18dc: CD [56 19]  |   CAL 0x1956
     0x18dd: 56 [19 3E]  |   MOV D, M
     0x18de: 19 [3E 08]  |   DAD D
     0x18df: 3E [08 32]  |   MVI A, 0x08
     0x18e0: 08 [32 CF]  |   Undefined instruction
     0x18e1: 32 [CF 20]  |   STA 0x20CF
     0x18e2: CF [20 C3]  |   RST 1
     0x18e3: 20 [C3 EA]  |   Undefined instruction
     0x18e4: C3 [EA 0A]  |   JMP 0x0AEA
     0x18e5: EA [0A 3A]  |   JPE 0x3A0A
     0x18e6: 0A [3A 67]  |   LDAX B
     0x18e7: 3A [67 20]  |   LDA 0x2067
     0x18e8: 67 [20 21]  |   MOV H, A
     0x18e9: 20 [21 E7]  |   Undefined instruction
     0x18ea: 21 [E7 20]  |   LXI H, 0x20E7 
     0x18eb: E7 [20 0F]  |   RST 4
     0x18ec: 20 [0F D0]  |   Undefined instruction
     0x18ed: 0F [D0 23]  |   RRC
     0x18ee: D0 [23 C9]  |   RNC
     0x18ef: 23 [C9 06]  |   INX H
     0x18f0: C9 [06 02]  |   RET
     0x18f1: 06 [02 3A]  |   MVI B, 0x02
     0x18f2: 02 [3A 82]  |   STAX B
     0x18f3: 3A [82 20]  |   LDA 0x2082
     0x18f4: 82 [20 3D]  |   ADD D
     0x18f5: 20 [3D C0]  |   Undefined instruction
     0x18f6: 3D [C0 04]  |   DCR A
     0x18f7: C0 [04 C9]  |   RNZ
     0x18f8: 04 [C9 3A]  |   INR B
     0x18f9: C9 [3A 94]  |   RET
     0x18fa: 3A [94 20]  |   LDA 0x2094
     0x18fb: 94 [20 B0]  |   SUB H
     0x18fc: 20 [B0 32]  |   Undefined instruction
     0x18fd: B0 [32 94]  |   ORA B
     0x18fe: 32 [94 20]  |   STA 0x2094
     0x18ff: 94 [20 D3]  |   SUB H
     0x1900: 20 [D3 03]  |   Undefined instruction
     0x1901: D3 [03 C9]  |   OUT 0x03
     0x1902: 03 [C9 21]  |   INX B
     0x1903: C9 [21 00]  |   RET
     0x1904: 21 [00 22]  |   LXI H, 0x2200 
     0x1905: 00 [22 C3]  |   NOP
     0x1906: 22 [C3 C3]  |   SHLD 0xC3C3
     0x1907: C3 [C3 01]  |   JMP 0x01C3
     0x1908: C3 [01 CD]  |   JMP 0xCD01
     0x1909: 01 [CD D8]  |   LXI B, 0xD8CD 
     0x190a: CD [D8 14]  |   CAL 0x14D8
     0x190b: D8 [14 C3]  |   RC
     0x190c: 14 [C3 97]  |   INR D
     0x190d: C3 [97 15]  |   JMP 0x1597
     0x190e: 97 [15 21]  |   SUB A
     0x190f: 15 [21 E7]  |   DCR D
     0x1910: 21 [E7 20]  |   LXI H, 0x20E7 
     0x1911: E7 [20 3A]  |   RST 4
     0x1912: 20 [3A 67]  |   Undefined instruction
     0x1913: 3A [67 20]  |   LDA 0x2067
     0x1914: 67 [20 0F]  |   MOV H, A
     0x1915: 20 [0F D8]  |   Undefined instruction
     0x1916: 0F [D8 23]  |   RRC
     0x1917: D8 [23 C9]  |   RC
     0x1918: 23 [C9 0E]  |   INX H
     0x1919: C9 [0E 1C]  |   RET
     0x191a: 0E [1C 21]  |   MVI C, 0x1C
     0x191b: 1C [21 1E]  |   INR E
     0x191c: 21 [1E 24]  |   LXI H, 0x241E 
     0x191d: 1E [24 11]  |   MVI E, 0x24
     0x191e: 24 [11 E4]  |   INR H
     0x191f: 11 [E4 1A]  |   LXI D, 0x1AE4 
     0x1920: E4 [1A C3]  |   CPO 0xC31A
     0x1921: 1A [C3 F3]  |   LDAX D
     0x1922: C3 [F3 08]  |   JMP 0x08F3
     0x1923: F3 [08 21]  |   DI
     0x1924: 08 [21 F8]  |   Undefined instruction
     0x1925: 21 [F8 20]  |   LXI H, 0x20F8 
     0x1926: F8 [20 C3]  |   RM
     0x1927: 20 [C3 31]  |   Undefined instruction
     0x1928: C3 [31 19]  |   JMP 0x1931
     0x1929: 31 [19 21]  |   LXI SP, 0x2119 
     0x192a: 19 [21 FC]  |   DAD D
     0x192b: 21 [FC 20]  |   LXI H, 0x20FC 
     0x192c: FC [20 C3]  |   CM 0xC320
     0x192d: 20 [C3 31]  |   Undefined instruction
     0x192e: C3 [31 19]  |   JMP 0x1931
     0x192f: 31 [19 5E]  |   LXI SP, 0x5E19 
     0x1930: 19 [5E 23]  |   DAD D
     0x1931: 5E [23 56]  |   MOV E, M
     0x1932: 23 [56 23]  |   INX H
     0x1933: 56 [23 7E]  |   MOV D, M
     0x1934: 23 [7E 23]  |   INX H
     0x1935: 7E [23 66]  |   MOV A, M
     0x1936: 23 [66 6F]  |   INX H
     0x1937: 66 [6F C3]  |   MOV H, M
     0x1938: 6F [C3 AD]  |   MOV L, A
     0x1939: C3 [AD 09]  |   JMP 0x09AD
     0x193a: AD [09 0E]  |   XRA L
     0x193b: 09 [0E 07]  |   DAD B
     0x193c: 0E [07 21]  |   MVI C, 0x07
     0x193d: 07 [21 01]  |   RLC
     0x193e: 21 [01 35]  |   LXI H, 0x3501 
     0x193f: 01 [35 11]  |   LXI B, 0x1135 
     0x1940: 35 [11 A9]  |   DCR M
     0x1941: 11 [A9 1F]  |   LXI D, 0x1FA9 
     0x1942: A9 [1F C3]  |   XRA C
     0x1943: 1F [C3 F3]  |   RAR
     0x1944: C3 [F3 08]  |   JMP 0x08F3
     0x1945: F3 [08 3A]  |   DI
     0x1946: 08 [3A EB]  |   Undefined instruction
     0x1947: 3A [EB 20]  |   LDA 0x20EB
     0x1948: EB [20 21]  |   XCHG
     0x1949: 20 [21 01]  |   Undefined instruction
     0x194a: 21 [01 3C]  |   LXI H, 0x3C01 
     0x194b: 01 [3C C3]  |   LXI B, 0xC33C 
     0x194c: 3C [C3 B2]  |   INR A
     0x194d: C3 [B2 09]  |   JMP 0x09B2
     0x194e: B2 [09 21]  |   ORA D
     0x194f: 09 [21 F4]  |   DAD B
     0x1950: 21 [F4 20]  |   LXI H, 0x20F4 
     0x1951: F4 [20 C3]  |   CP 0xC320
     0x1952: 20 [C3 31]  |   Undefined instruction
     0x1953: C3 [31 19]  |   JMP 0x1931
     0x1954: 31 [19 CD]  |   LXI SP, 0xCD19 
     0x1955: 19 [CD 5C]  |   DAD D
     0x1956: CD [5C 1A]  |   CAL 0x1A5C
     0x1957: 5C [1A CD]  |   MOV E, H
     0x1958: 1A [CD 1A]  |   LDAX D
     0x1959: CD [1A 19]  |   CAL 0x191A
     0x195a: 1A [19 CD]  |   LDAX D
     0x195b: 19 [CD 25]  |   DAD D
     0x195c: CD [25 19]  |   CAL 0x1925
     0x195d: 25 [19 CD]  |   DCR H
     0x195e: 19 [CD 2B]  |   DAD D
     0x195f: CD [2B 19]  |   CAL 0x192B
     0x1960: 2B [19 CD]  |   DCX H
     0x1961: 19 [CD 50]  |   DAD D
     0x1962: CD [50 19]  |   CAL 0x1950
     0x1963: 50 [19 CD]  |   MOV D, B
     0x1964: 19 [CD 3C]  |   DAD D
     0x1965: CD [3C 19]  |   CAL 0x193C
     0x1966: 3C [19 C3]  |   INR A
     0x1967: 19 [C3 47]  |   DAD D
     0x1968: C3 [47 19]  |   JMP 0x1947
     0x1969: 47 [19 CD]  |   MOV B, A
     0x196a: 19 [CD DC]  |   DAD D
     0x196b: CD [DC 19]  |   CAL 0x19DC
     0x196c: DC [19 C3]  |   CC 0xC319
     0x196d: 19 [C3 71]  |   DAD D
     0x196e: C3 [71 16]  |   JMP 0x1671
     0x196f: 71 [16 3E]  |   MOV M, C
     0x1970: 16 [3E 01]  |   MVI D, 0x3E
     0x1971: 3E [01 32]  |   MVI A, 0x01
     0x1972: 01 [32 6D]  |   LXI B, 0x6D32 
     0x1973: 32 [6D 20]  |   STA 0x206D
     0x1974: 6D [20 C3]  |   MOV L, L
     0x1975: 20 [C3 E6]  |   Undefined instruction
     0x1976: C3 [E6 16]  |   JMP 0x16E6
     0x1977: E6 [16 CD]  |   ANI 0x16
     0x1978: 16 [CD D7]  |   MVI D, 0xCD
     0x1979: CD [D7 19]  |   CAL 0x19D7
     0x197a: D7 [19 CD]  |   RST 2
     0x197b: 19 [CD 47]  |   DAD D
     0x197c: CD [47 19]  |   CAL 0x1947
     0x197d: 47 [19 C3]  |   MOV B, A
     0x197e: 19 [C3 3C]  |   DAD D
     0x197f: C3 [3C 19]  |   JMP 0x193C
     0x1980: 3C [19 32]  |   INR A
     0x1981: 19 [32 C1]  |   DAD D
     0x1982: 32 [C1 20]  |   STA 0x20C1
     0x1983: C1 [20 C9]  |   POP B
     0x1984: 20 [C9 8B]  |   Undefined instruction
     0x1985: C9 [8B 19]  |   RET
     0x1986: 8B [19 C3]  |   ADC E
     0x1987: 19 [C3 D6]  |   DAD D
     0x1988: C3 [D6 09]  |   JMP 0x09D6
     0x1989: D6 [09 21]  |   SUI 0x09
     0x198a: 09 [21 03]  |   DAD B
     0x198b: 21 [03 28]  |   LXI H, 0x2803 
     0x198c: 03 [28 11]  |   INX B
     0x198d: 28 [11 BE]  |   Undefined instruction
     0x198e: 11 [BE 19]  |   LXI D, 0x19BE 
     0x198f: BE [19 0E]  |   CMP M
     0x1990: 19 [0E 13]  |   DAD D
     0x1991: 0E [13 C3]  |   MVI C, 0x13
     0x1992: 13 [C3 F3]  |   INX D
     0x1993: C3 [F3 08]  |   JMP 0x08F3
     0x1994: F3 [08 00]  |   DI
     0x1995: 08 [00 00]  |   Undefined instruction
     0x1996: 00 [00 00]  |   NOP
     0x1997: 00 [00 00]  |   NOP
     0x1998: 00 [00 3A]  |   NOP
     0x1999: 00 [3A 1E]  |   NOP
     0x199a: 3A [1E 20]  |   LDA 0x201E
     0x199b: 1E [20 A7]  |   MVI E, 0x20
     0x199c: 20 [A7 C2]  |   Undefined instruction
     0x199d: A7 [C2 AC]  |   ANA A
     0x199e: C2 [AC 19]  |   JNZ 0x19AC
     0x199f: AC [19 DB]  |   XRA H
     0x19a0: 19 [DB 01]  |   DAD D
     0x19a1: DB [01 E6]  |   IN 0x01
     0x19a2: 01 [E6 76]  |   LXI B, 0x76E6 
     0x19a3: E6 [76 D6]  |   ANI 0x76
     0x19a4: 76 [D6 72]  |   HLT
     0x19a5: D6 [72 C0]  |   SUI 0x72
     0x19a6: 72 [C0 3C]  |   MOV M, D
     0x19a7: C0 [3C 32]  |   RNZ
     0x19a8: 3C [32 1E]  |   INR A
     0x19a9: 32 [1E 20]  |   STA 0x201E
     0x19aa: 1E [20 DB]  |   MVI E, 0x20
     0x19ab: 20 [DB 01]  |   Undefined instruction
     0x19ac: DB [01 E6]  |   IN 0x01
     0x19ad: 01 [E6 76]  |   LXI B, 0x76E6 
     0x19ae: E6 [76 FE]  |   ANI 0x76
     0x19af: 76 [FE 34]  |   HLT
     0x19b0: FE [34 C0]  |   CPI 0x34
     0x19b1: 34 [C0 21]  |   INR M
     0x19b2: C0 [21 1B]  |   RNZ
     0x19b3: 21 [1B 2E]  |   LXI H, 0x2E1B 
     0x19b4: 1B [2E 11]  |   DCX D
     0x19b5: 2E [11 F7]  |   MVI L, 0x11
     0x19b6: 11 [F7 0B]  |   LXI D, 0x0BF7 
     0x19b7: F7 [0B 0E]  |   RST 6
     0x19b8: 0B [0E 09]  |   DCX B
     0x19b9: 0E [09 C3]  |   MVI C, 0x09
     0x19ba: 09 [C3 F3]  |   DAD B
     0x19bb: C3 [F3 08]  |   JMP 0x08F3
     0x19bc: F3 [08 28]  |   DI
     0x19bd: 08 [28 13]  |   Undefined instruction
     0x19be: 28 [13 00]  |   Undefined instruction
     0x19bf: 13 [00 08]  |   INX D
     0x19c0: 00 [08 13]  |   NOP
     0x19c1: 08 [13 0E]  |   Undefined instruction
     0x19c2: 13 [0E 26]  |   INX D
     0x19c3: 0E [26 02]  |   MVI C, 0x26
     0x19c4: 26 [02 0E]  |   MVI H, 0x02
     0x19c5: 02 [0E 11]  |   STAX B
     0x19c6: 0E [11 0F]  |   MVI C, 0x11
     0x19c7: 11 [0F 0E]  |   LXI D, 0x0E0F 
     0x19c8: 0F [0E 11]  |   RRC
     0x19c9: 0E [11 00]  |   MVI C, 0x11
     0x19ca: 11 [00 13]  |   LXI D, 0x1300 
     0x19cb: 00 [13 08]  |   NOP
     0x19cc: 13 [08 0E]  |   INX D
     0x19cd: 08 [0E 0D]  |   Undefined instruction
     0x19ce: 0E [0D 28]  |   MVI C, 0x0D
     0x19cf: 0D [28 3E]  |   DCR C
     0x19d0: 28 [3E 01]  |   Undefined instruction
     0x19d1: 3E [01 32]  |   MVI A, 0x01
     0x19d2: 01 [32 E9]  |   LXI B, 0xE932 
     0x19d3: 32 [E9 20]  |   STA 0x20E9
     0x19d4: E9 [20 C9]  |   PCHL
     0x19d5: 20 [C9 AF]  |   Undefined instruction
     0x19d6: C9 [AF C3]  |   RET
     0x19d7: AF [C3 D3]  |   XRA A
     0x19d8: C3 [D3 19]  |   JMP 0x19D3
     0x19d9: D3 [19 00]  |   OUT 0x19
     0x19da: 19 [00 3A]  |   DAD D
     0x19db: 00 [3A 94]  |   NOP
     0x19dc: 3A [94 20]  |   LDA 0x2094
     0x19dd: 94 [20 A0]  |   SUB H
     0x19de: 20 [A0 32]  |   Undefined instruction
     0x19df: A0 [32 94]  |   ANA B
     0x19e0: 32 [94 20]  |   STA 0x2094
     0x19e1: 94 [20 D3]  |   SUB H
     0x19e2: 20 [D3 03]  |   Undefined instruction
     0x19e3: D3 [03 C9]  |   OUT 0x03
     0x19e4: 03 [C9 21]  |   INX B
     0x19e5: C9 [21 01]  |   RET
     0x19e6: 21 [01 27]  |   LXI H, 0x2701 
     0x19e7: 01 [27 CA]  |   LXI B, 0xCA27 
     0x19e8: 27 [CA FA]  |   DAA
     0x19e9: CA [FA 19]  |   JZ 0x19FA
     0x19ea: FA [19 11]  |   JM 0x1119
     0x19eb: 19 [11 60]  |   DAD D
     0x19ec: 11 [60 1C]  |   LXI D, 0x1C60 
     0x19ed: 60 [1C 06]  |   MOV H, B
     0x19ee: 1C [06 10]  |   INR E
     0x19ef: 06 [10 4F]  |   MVI B, 0x10
     0x19f0: 10 [4F CD]  |   Undefined instruction
     0x19f1: 4F [CD 39]  |   MOV C, A
     0x19f2: CD [39 14]  |   CAL 0x1439
     0x19f3: 39 [14 79]  |   DAD SP
     0x19f4: 14 [79 3D]  |   INR D
     0x19f5: 79 [3D C2]  |   MOV A, C
     0x19f6: 3D [C2 EC]  |   DCR A
     0x19f7: C2 [EC 19]  |   JNZ 0x19EC
     0x19f8: EC [19 06]  |   CPE 0x0619
     0x19f9: 19 [06 10]  |   DAD D
     0x19fa: 06 [10 CD]  |   MVI B, 0x10
     0x19fb: 10 [CD CB]  |   Undefined instruction
     0x19fc: CD [CB 14]  |   CAL 0x14CB
     0x19fd: CB [14 7C]  |   Undefined instruction
     0x19fe: 14 [7C FE]  |   INR D
     0x19ff: 7C [FE 35]  |   MOV A, H
     0x1a00: FE [35 C2]  |   CPI 0x35
     0x1a01: 35 [C2 FA]  |   DCR M
     0x1a02: C2 [FA 19]  |   JNZ 0x19FA
     0x1a03: FA [19 C9]  |   JM 0xC919
     0x1a04: 19 [C9 21]  |   DAD D
     0x1a05: C9 [21 72]  |   RET
     0x1a06: 21 [72 20]  |   LXI H, 0x2072 
     0x1a07: 72 [20 46]  |   MOV M, D
     0x1a08: 20 [46 1A]  |   Undefined instruction
     0x1a09: 46 [1A E6]  |   MOV B, M
     0x1a0a: 1A [E6 80]  |   LDAX D
     0x1a0b: E6 [80 A8]  |   ANI 0x80
     0x1a0c: 80 [A8 C0]  |   ADD B
     0x1a0d: A8 [C0 37]  |   XRA B
     0x1a0e: C0 [37 C9]  |   RNZ
     0x1a0f: 37 [C9 32]  |   STC
     0x1a10: C9 [32 2B]  |   RET
     0x1a11: 32 [2B 24]  |   STA 0x242B
     0x1a12: 2B [24 1C]  |   DCX H
     0x1a13: 24 [1C 16]  |   INR H
     0x1a14: 1C [16 11]  |   INR E
     0x1a15: 16 [11 0D]  |   MVI D, 0x11
     0x1a16: 11 [0D 0A]  |   LXI D, 0x0A0D 
     0x1a17: 0D [0A 08]  |   DCR C
     0x1a18: 0A [08 07]  |   LDAX B
     0x1a19: 08 [07 06]  |   Undefined instruction
     0x1a1a: 07 [06 05]  |   RLC
     0x1a1b: 06 [05 04]  |   MVI B, 0x05
     0x1a1c: 05 [04 03]  |   DCR B
     0x1a1d: 04 [03 02]  |   INR B
     0x1a1e: 03 [02 01]  |   INX B
     0x1a1f: 02 [01 34]  |   STAX B
     0x1a20: 01 [34 2E]  |   LXI B, 0x2E34 
     0x1a21: 34 [2E 27]  |   INR M
     0x1a22: 2E [27 22]  |   MVI L, 0x27
     0x1a23: 27 [22 1C]  |   DAA
     0x1a24: 22 [1C 18]  |   SHLD 0x181C
     0x1a25: 1C [18 15]  |   INR E
     0x1a26: 18 [15 13]  |   Undefined instruction
     0x1a27: 15 [13 10]  |   DCR D
     0x1a28: 13 [10 0E]  |   INX D
     0x1a29: 10 [0E 0D]  |   Undefined instruction
     0x1a2a: 0E [0D 0C]  |   MVI C, 0x0D
     0x1a2b: 0D [0C 0B]  |   DCR C
     0x1a2c: 0C [0B 09]  |   INR C
     0x1a2d: 0B [09 07]  |   DCX B
     0x1a2e: 09 [07 05]  |   DAD B
     0x1a2f: 07 [05 FF]  |   RLC
     0x1a30: 05 [FF 1A]  |   DCR B
     0x1a31: FF [1A 77]  |   RST 7
     0x1a32: 1A [77 23]  |   LDAX D
     0x1a33: 77 [23 13]  |   MOV M, A
     0x1a34: 23 [13 05]  |   INX H
     0x1a35: 13 [05 C2]  |   INX D
     0x1a36: 05 [C2 32]  |   DCR B
     0x1a37: C2 [32 1A]  |   JNZ 0x1A32
     0x1a38: 32 [1A C9]  |   STA 0xC91A
     0x1a39: 1A [C9 5E]  |   LDAX D
     0x1a3a: C9 [5E 23]  |   RET
     0x1a3b: 5E [23 56]  |   MOV E, M
     0x1a3c: 23 [56 23]  |   INX H
     0x1a3d: 56 [23 7E]  |   MOV D, M
     0x1a3e: 23 [7E 23]  |   INX H
     0x1a3f: 7E [23 4E]  |   MOV A, M
     0x1a40: 23 [4E 23]  |   INX H
     0x1a41: 4E [23 46]  |   MOV C, M
     0x1a42: 23 [46 61]  |   INX H
     0x1a43: 46 [61 6F]  |   MOV B, M
     0x1a44: 61 [6F C9]  |   MOV H, C
     0x1a45: 6F [C9 C5]  |   MOV L, A
     0x1a46: C9 [C5 06]  |   RET
     0x1a47: C5 [06 03]  |   PUSH B
     0x1a48: 06 [03 7C]  |   MVI B, 0x03
     0x1a49: 03 [7C 1F]  |   INX B
     0x1a4a: 7C [1F 67]  |   MOV A, H
     0x1a4b: 1F [67 7D]  |   RAR
     0x1a4c: 67 [7D 1F]  |   MOV H, A
     0x1a4d: 7D [1F 6F]  |   MOV A, L
     0x1a4e: 1F [6F 05]  |   RAR
     0x1a4f: 6F [05 C2]  |   MOV L, A
     0x1a50: 05 [C2 4A]  |   DCR B
     0x1a51: C2 [4A 1A]  |   JNZ 0x1A4A
     0x1a52: 4A [1A 7C]  |   MOV C, D
     0x1a53: 1A [7C E6]  |   LDAX D
     0x1a54: 7C [E6 3F]  |   MOV A, H
     0x1a55: E6 [3F F6]  |   ANI 0x3F
     0x1a56: 3F [F6 20]  |   CMC
     0x1a57: F6 [20 67]  |   ORI 0x20
     0x1a58: 20 [67 C1]  |   Undefined instruction
     0x1a59: 67 [C1 C9]  |   MOV H, A
     0x1a5a: C1 [C9 21]  |   POP B
     0x1a5b: C9 [21 00]  |   RET
     0x1a5c: 21 [00 24]  |   LXI H, 0x2400 
     0x1a5d: 00 [24 36]  |   NOP
     0x1a5e: 24 [36 00]  |   INR H
     0x1a5f: 36 [00 23]  |   MVI M, 0x00
     0x1a60: 00 [23 7C]  |   NOP
     0x1a61: 23 [7C FE]  |   INX H
     0x1a62: 7C [FE 40]  |   MOV A, H
     0x1a63: FE [40 C2]  |   CPI 0x40
     0x1a64: 40 [C2 5F]  |   MOV B, B
     0x1a65: C2 [5F 1A]  |   JNZ 0x1A5F
     0x1a66: 5F [1A C9]  |   MOV E, A
     0x1a67: 1A [C9 C5]  |   LDAX D
     0x1a68: C9 [C5 E5]  |   RET
     0x1a69: C5 [E5 1A]  |   PUSH B
     0x1a6a: E5 [1A B6]  |   PUSH H
     0x1a6b: 1A [B6 77]  |   LDAX D
     0x1a6c: B6 [77 13]  |   ORA M
     0x1a6d: 77 [13 23]  |   MOV M, A
     0x1a6e: 13 [23 0D]  |   INX D
     0x1a6f: 23 [0D C2]  |   INX H
     0x1a70: 0D [C2 6B]  |   DCR C
     0x1a71: C2 [6B 1A]  |   JNZ 0x1A6B
     0x1a72: 6B [1A E1]  |   MOV L, E
     0x1a73: 1A [E1 01]  |   LDAX D
     0x1a74: E1 [01 20]  |   POP H
     0x1a75: 01 [20 00]  |   LXI B, 0x0020 
     0x1a76: 20 [00 09]  |   Undefined instruction
     0x1a77: 00 [09 C1]  |   NOP
     0x1a78: 09 [C1 05]  |   DAD B
     0x1a79: C1 [05 C2]  |   POP B
     0x1a7a: 05 [C2 69]  |   DCR B
     0x1a7b: C2 [69 1A]  |   JNZ 0x1A69
     0x1a7c: 69 [1A C9]  |   MOV L, C
     0x1a7d: 1A [C9 CD]  |   LDAX D
     0x1a7e: C9 [CD 2E]  |   RET
     0x1a7f: CD [2E 09]  |   CAL 0x092E
     0x1a80: 2E [09 A7]  |   MVI L, 0x09
     0x1a81: 09 [A7 C8]  |   DAD B
     0x1a82: A7 [C8 F5]  |   ANA A
     0x1a83: C8 [F5 3D]  |   RZ
     0x1a84: F5 [3D 77]  |   PUSH PSW
     0x1a85: 3D [77 CD]  |   DCR A
     0x1a86: 77 [CD E6]  |   MOV M, A
     0x1a87: CD [E6 19]  |   CAL 0x19E6
     0x1a88: E6 [19 F1]  |   ANI 0x19
     0x1a89: 19 [F1 21]  |   DAD D
     0x1a8a: F1 [21 01]  |   POP PSW
     0x1a8b: 21 [01 25]  |   LXI H, 0x2501 
     0x1a8c: 01 [25 E6]  |   LXI B, 0xE625 
     0x1a8d: 25 [E6 0F]  |   DCR H
     0x1a8e: E6 [0F C3]  |   ANI 0x0F
     0x1a8f: 0F [C3 C5]  |   RRC
     0x1a90: C3 [C5 09]  |   JMP 0x09C5
     0x1a91: C5 [09 00]  |   PUSH B
     0x1a92: 09 [00 00]  |   DAD B
     0x1a93: 00 [00 00]  |   NOP
     0x1a94: 00 [00 00]  |   NOP
     0x1a95: 00 [00 FF]  |   NOP
     0x1a96: 00 [FF B8]  |   NOP
     0x1a97: FF [B8 FE]  |   RST 7
     0x1a98: B8 [FE 20]  |   CMP B
     0x1a99: FE [20 1C]  |   CPI 0x20
     0x1a9a: 20 [1C 10]  |   Undefined instruction
     0x1a9b: 1C [10 9E]  |   INR E
     0x1a9c: 10 [9E 00]  |   Undefined instruction
     0x1a9d: 9E [00 20]  |   SBB M
     0x1a9e: 00 [20 1C]  |   NOP
     0x1a9f: 20 [1C 30]  |   Undefined instruction
     0x1aa0: 1C [30 10]  |   INR E
     0x1aa1: 30 [10 0B]  |   Undefined instruction
     0x1aa2: 10 [0B 08]  |   Undefined instruction
     0x1aa3: 0B [08 07]  |   DCX B
     0x1aa4: 08 [07 06]  |   Undefined instruction
     0x1aa5: 07 [06 00]  |   RLC
     0x1aa6: 06 [00 0C]  |   MVI B, 0x00
     0x1aa7: 00 [0C 04]  |   NOP
     0x1aa8: 0C [04 26]  |   INR C
     0x1aa9: 04 [26 0E]  |   INR B
     0x1aaa: 26 [0E 15]  |   MVI H, 0x0E
     0x1aab: 0E [15 04]  |   MVI C, 0x15
     0x1aac: 15 [04 11]  |   DCR D
     0x1aad: 04 [11 26]  |   INR B
     0x1aae: 11 [26 26]  |   LXI D, 0x2626 
     0x1aaf: 26 [26 0F]  |   MVI H, 0x26
     0x1ab0: 26 [0F 0B]  |   MVI H, 0x0F
     0x1ab1: 0F [0B 00]  |   RRC
     0x1ab2: 0B [00 18]  |   DCX B
     0x1ab3: 00 [18 04]  |   NOP
     0x1ab4: 18 [04 11]  |   Undefined instruction
     0x1ab5: 04 [11 24]  |   INR B
     0x1ab6: 11 [24 26]  |   LXI D, 0x2624 
     0x1ab7: 24 [26 25]  |   INR H
     0x1ab8: 26 [25 1B]  |   MVI H, 0x25
     0x1ab9: 25 [1B 26]  |   DCR H
     0x1aba: 1B [26 0E]  |   DCX D
     0x1abb: 26 [0E 11]  |   MVI H, 0x0E
     0x1abc: 0E [11 26]  |   MVI C, 0x11
     0x1abd: 11 [26 1C]  |   LXI D, 0x1C26 
     0x1abe: 26 [1C 0F]  |   MVI H, 0x1C
     0x1abf: 1C [0F 0B]  |   INR E
     0x1ac0: 0F [0B 00]  |   RRC
     0x1ac1: 0B [00 18]  |   DCX B
     0x1ac2: 00 [18 04]  |   NOP
     0x1ac3: 18 [04 11]  |   Undefined instruction
     0x1ac4: 04 [11 12]  |   INR B
     0x1ac5: 11 [12 26]  |   LXI D, 0x2612 
     0x1ac6: 12 [26 01]  |   STAX D
     0x1ac7: 26 [01 14]  |   MVI H, 0x01
     0x1ac8: 01 [14 13]  |   LXI B, 0x1314 
     0x1ac9: 14 [13 13]  |   INR D
     0x1aca: 13 [13 0E]  |   INX D
     0x1acb: 13 [0E 0D]  |   INX D
     0x1acc: 0E [0D 26]  |   MVI C, 0x0D
     0x1acd: 0D [26 0E]  |   DCR C
     0x1ace: 26 [0E 0D]  |   MVI H, 0x0E
     0x1acf: 0E [0D 0B]  |   MVI C, 0x0D
     0x1ad0: 0D [0B 18]  |   DCR C
     0x1ad1: 0B [18 26]  |   DCX B
     0x1ad2: 18 [26 1B]  |   Undefined instruction
     0x1ad3: 26 [1B 0F]  |   MVI H, 0x1B
     0x1ad4: 1B [0F 0B]  |   DCX D
     0x1ad5: 0F [0B 00]  |   RRC
     0x1ad6: 0B [00 18]  |   DCX B
     0x1ad7: 00 [18 04]  |   NOP
     0x1ad8: 18 [04 11]  |   Undefined instruction
     0x1ad9: 04 [11 26]  |   INR B
     0x1ada: 11 [26 26]  |   LXI D, 0x2626 
     0x1adb: 26 [26 01]  |   MVI H, 0x26
     0x1adc: 26 [01 14]  |   MVI H, 0x01
     0x1add: 01 [14 13]  |   LXI B, 0x1314 
     0x1ade: 14 [13 13]  |   INR D
     0x1adf: 13 [13 0E]  |   INX D
     0x1ae0: 13 [0E 0D]  |   INX D
     0x1ae1: 0E [0D 26]  |   MVI C, 0x0D
     0x1ae2: 0D [26 26]  |   DCR C
     0x1ae3: 26 [26 12]  |   MVI H, 0x26
     0x1ae4: 26 [12 02]  |   MVI H, 0x12
     0x1ae5: 12 [02 0E]  |   STAX D
     0x1ae6: 02 [0E 11]  |   STAX B
     0x1ae7: 0E [11 04]  |   MVI C, 0x11
     0x1ae8: 11 [04 24]  |   LXI D, 0x2404 
     0x1ae9: 04 [24 1B]  |   INR B
     0x1aea: 24 [1B 25]  |   INR H
     0x1aeb: 1B [25 26]  |   DCX D
     0x1aec: 25 [26 07]  |   DCR H
     0x1aed: 26 [07 08]  |   MVI H, 0x07
     0x1aee: 07 [08 3F]  |   RLC
     0x1aef: 08 [3F 12]  |   Undefined instruction
     0x1af0: 3F [12 02]  |   CMC
     0x1af1: 12 [02 0E]  |   STAX D
     0x1af2: 02 [0E 11]  |   STAX B
     0x1af3: 0E [11 04]  |   MVI C, 0x11
     0x1af4: 11 [04 26]  |   LXI D, 0x2604 
     0x1af5: 04 [26 12]  |   INR B
     0x1af6: 26 [12 02]  |   MVI H, 0x12
     0x1af7: 12 [02 0E]  |   STAX D
     0x1af8: 02 [0E 11]  |   STAX B
     0x1af9: 0E [11 04]  |   MVI C, 0x11
     0x1afa: 11 [04 24]  |   LXI D, 0x2404 
     0x1afb: 04 [24 1C]  |   INR B
     0x1afc: 24 [1C 25]  |   INR H
     0x1afd: 1C [25 26]  |   INR E
     0x1afe: 25 [26 01]  |   DCR H
     0x1aff: 26 [01 00]  |   MVI H, 0x01
     0x1b00: 01 [00 00]  |   LXI B, 0x0000 
     0x1b01: 00 [00 10]  |   NOP
     0x1b02: 00 [10 00]  |   NOP
     0x1b03: 10 [00 00]  |   Undefined instruction
     0x1b04: 00 [00 00]  |   NOP
     0x1b05: 00 [00 00]  |   NOP
     0x1b06: 00 [00 02]  |   NOP
     0x1b07: 00 [02 78]  |   NOP
     0x1b08: 02 [78 38]  |   STAX B
     0x1b09: 78 [38 78]  |   MOV A, B
     0x1b0a: 38 [78 38]  |   Undefined instruction
     0x1b0b: 78 [38 00]  |   MOV A, B
     0x1b0c: 38 [00 F8]  |   Undefined instruction
     0x1b0d: 00 [F8 00]  |   NOP
     0x1b0e: F8 [00 00]  |   RM
     0x1b0f: 00 [00 80]  |   NOP
     0x1b10: 00 [80 00]  |   NOP
     0x1b11: 80 [00 8E]  |   ADD B
     0x1b12: 00 [8E 02]  |   NOP
     0x1b13: 8E [02 FF]  |   ADC M
     0x1b14: 02 [FF 05]  |   STAX B
     0x1b15: FF [05 0C]  |   RST 7
     0x1b16: 05 [0C 60]  |   DCR B
     0x1b17: 0C [60 1C]  |   INR C
     0x1b18: 60 [1C 20]  |   MOV H, B
     0x1b19: 1C [20 30]  |   INR E
     0x1b1a: 20 [30 10]  |   Undefined instruction
     0x1b1b: 30 [10 01]  |   Undefined instruction
     0x1b1c: 10 [01 00]  |   Undefined instruction
     0x1b1d: 01 [00 00]  |   LXI B, 0x0000 
     0x1b1e: 00 [00 00]  |   NOP
     0x1b1f: 00 [00 00]  |   NOP
     0x1b20: 00 [00 00]  |   NOP
     0x1b21: 00 [00 BB]  |   NOP
     0x1b22: 00 [BB 03]  |   NOP
     0x1b23: BB [03 00]  |   CMP E
     0x1b24: 03 [00 10]  |   INX B
     0x1b25: 00 [10 90]  |   NOP
     0x1b26: 10 [90 1C]  |   Undefined instruction
     0x1b27: 90 [1C 28]  |   SUB B
     0x1b28: 1C [28 30]  |   INR E
     0x1b29: 28 [30 01]  |   Undefined instruction
     0x1b2a: 30 [01 04]  |   Undefined instruction
     0x1b2b: 01 [04 00]  |   LXI B, 0x0004 
     0x1b2c: 04 [00 FF]  |   INR B
     0x1b2d: 00 [FF FF]  |   NOP
     0x1b2e: FF [FF 00]  |   RST 7
     0x1b2f: FF [00 00]  |   RST 7
     0x1b30: 00 [00 02]  |   NOP
     0x1b31: 00 [02 76]  |   NOP
     0x1b32: 02 [76 04]  |   STAX B
     0x1b33: 76 [04 00]  |   HLT
     0x1b34: 04 [00 00]  |   INR B
     0x1b35: 00 [00 00]  |   NOP
     0x1b36: 00 [00 00]  |   NOP
     0x1b37: 00 [00 00]  |   NOP
     0x1b38: 00 [00 04]  |   NOP
     0x1b39: 00 [04 EE]  |   NOP
     0x1b3a: 04 [EE 1C]  |   INR B
     0x1b3b: EE [1C 00]  |   XRI 0x1C
     0x1b3c: 1C [00 00]  |   INR E
     0x1b3d: 00 [00 03]  |   NOP
     0x1b3e: 00 [03 00]  |   NOP
     0x1b3f: 03 [00 00]  |   INX B
     0x1b40: 00 [00 00]  |   NOP
     0x1b41: 00 [00 B6]  |   NOP
     0x1b42: 00 [B6 04]  |   NOP
     0x1b43: B6 [04 00]  |   ORA M
     0x1b44: 04 [00 00]  |   INR B
     0x1b45: 00 [00 01]  |   NOP
     0x1b46: 00 [01 00]  |   NOP
     0x1b47: 01 [00 1D]  |   LXI B, 0x1D00 
     0x1b48: 00 [1D 04]  |   NOP
     0x1b49: 1D [04 E2]  |   DCR E
     0x1b4a: 04 [E2 1C]  |   INR B
     0x1b4b: E2 [1C 00]  |   JPO 0x001C
     0x1b4c: 1C [00 00]  |   INR E
     0x1b4d: 00 [00 03]  |   NOP
     0x1b4e: 00 [03 00]  |   NOP
     0x1b4f: 03 [00 00]  |   INX B
     0x1b50: 00 [00 00]  |   NOP
     0x1b51: 00 [00 82]  |   NOP
     0x1b52: 00 [82 06]  |   NOP
     0x1b53: 82 [06 00]  |   ADD D
     0x1b54: 06 [00 00]  |   MVI B, 0x00
     0x1b55: 00 [00 01]  |   NOP
     0x1b56: 00 [01 06]  |   NOP
     0x1b57: 01 [06 1D]  |   LXI B, 0x1D06 
     0x1b58: 06 [1D 04]  |   MVI B, 0x1D
     0x1b59: 1D [04 D0]  |   DCR E
     0x1b5a: 04 [D0 1C]  |   INR B
     0x1b5b: D0 [1C 00]  |   RNC
     0x1b5c: 1C [00 00]  |   INR E
     0x1b5d: 00 [00 03]  |   NOP
     0x1b5e: 00 [03 FF]  |   NOP
     0x1b5f: 03 [FF 00]  |   INX B
     0x1b60: FF [00 C0]  |   RST 7
     0x1b61: 00 [C0 1C]  |   NOP
     0x1b62: C0 [1C 00]  |   RNZ
     0x1b63: 1C [00 00]  |   INR E
     0x1b64: 00 [00 10]  |   NOP
     0x1b65: 00 [10 21]  |   NOP
     0x1b66: 10 [21 01]  |   Undefined instruction
     0x1b67: 21 [01 00]  |   LXI H, 0x0001 
     0x1b68: 01 [00 30]  |   LXI B, 0x3000 
     0x1b69: 00 [30 00]  |   NOP
     0x1b6a: 30 [00 12]  |   Undefined instruction
     0x1b6b: 00 [12 00]  |   NOP
     0x1b6c: 12 [00 00]  |   STAX D
     0x1b6d: 00 [00 00]  |   NOP
     0x1b6e: 00 [00 0F]  |   NOP
     0x1b6f: 00 [0F 0B]  |   NOP
     0x1b70: 0F [0B 00]  |   RRC
     0x1b71: 0B [00 18]  |   DCX B
     0x1b72: 00 [18 26]  |   NOP
     0x1b73: 18 [26 0F]  |   Undefined instruction
     0x1b74: 26 [0F 0B]  |   MVI H, 0x0F
     0x1b75: 0F [0B 00]  |   RRC
     0x1b76: 0B [00 18]  |   DCX B
     0x1b77: 00 [18 04]  |   NOP
     0x1b78: 18 [04 11]  |   Undefined instruction
     0x1b79: 04 [11 24]  |   INR B
     0x1b7a: 11 [24 1B]  |   LXI D, 0x1B24 
     0x1b7b: 24 [1B 25]  |   INR H
     0x1b7c: 1B [25 FC]  |   DCX D
     0x1b7d: 25 [FC 00]  |   DCR H
     0x1b7e: FC [00 01]  |   CM 0x0100
     0x1b7f: 00 [01 FF]  |   NOP
     0x1b80: 01 [FF FF]  |   LXI B, 0xFFFF 
     0x1b81: FF [FF 00]  |   RST 7
     0x1b82: FF [00 00]  |   RST 7
     0x1b83: 00 [00 00]  |   NOP
     0x1b84: 00 [00 20]  |   NOP
     0x1b85: 00 [20 64]  |   NOP
     0x1b86: 20 [64 1D]  |   Undefined instruction
     0x1b87: 64 [1D D0]  |   MOV H, H
     0x1b88: 1D [D0 29]  |   DCR E
     0x1b89: D0 [29 18]  |   RNC
     0x1b8a: 29 [18 02]  |   DAD H
     0x1b8b: 18 [02 54]  |   Undefined instruction
     0x1b8c: 02 [54 1D]  |   STAX B
     0x1b8d: 54 [1D 00]  |   MOV D, H
     0x1b8e: 1D [00 08]  |   DCR E
     0x1b8f: 00 [08 00]  |   NOP
     0x1b90: 08 [00 06]  |   Undefined instruction
     0x1b91: 00 [06 00]  |   NOP
     0x1b92: 06 [00 00]  |   MVI B, 0x00
     0x1b93: 00 [00 01]  |   NOP
     0x1b94: 00 [01 40]  |   NOP
     0x1b95: 01 [40 00]  |   LXI B, 0x0040 
     0x1b96: 40 [00 01]  |   MOV B, B
     0x1b97: 00 [01 00]  |   NOP
     0x1b98: 01 [00 00]  |   LXI B, 0x0000 
     0x1b99: 00 [00 10]  |   NOP
     0x1b9a: 00 [10 9E]  |   NOP
     0x1b9b: 10 [9E 00]  |   Undefined instruction
     0x1b9c: 9E [00 20]  |   SBB M
     0x1b9d: 00 [20 1C]  |   NOP
     0x1b9e: 20 [1C 00]  |   Undefined instruction
     0x1b9f: 1C [00 03]  |   INR E
     0x1ba0: 00 [03 04]  |   NOP
     0x1ba1: 03 [04 78]  |   INX B
     0x1ba2: 04 [78 14]  |   INR B
     0x1ba3: 78 [14 13]  |   MOV A, B
     0x1ba4: 14 [13 08]  |   INR D
     0x1ba5: 13 [08 1A]  |   INX D
     0x1ba6: 08 [1A 3D]  |   Undefined instruction
     0x1ba7: 1A [3D 68]  |   LDAX D
     0x1ba8: 3D [68 FC]  |   DCR A
     0x1ba9: 68 [FC FC]  |   MOV L, B
     0x1baa: FC [FC 68]  |   CM 0x68FC
     0x1bab: FC [68 3D]  |   CM 0x3D68
     0x1bac: 68 [3D 1A]  |   MOV L, B
     0x1bad: 3D [1A 00]  |   DCR A
     0x1bae: 1A [00 00]  |   LDAX D
     0x1baf: 00 [00 00]  |   NOP
     0x1bb0: 00 [00 01]  |   NOP
     0x1bb1: 00 [01 B8]  |   NOP
     0x1bb2: 01 [B8 98]  |   LXI B, 0x98B8 
     0x1bb3: B8 [98 A0]  |   CMP B
     0x1bb4: 98 [A0 1B]  |   SBB B
     0x1bb5: A0 [1B 10]  |   ANA B
     0x1bb6: 1B [10 FF]  |   DCX D
     0x1bb7: 10 [FF 00]  |   Undefined instruction
     0x1bb8: FF [00 A0]  |   RST 7
     0x1bb9: 00 [A0 1B]  |   NOP
     0x1bba: A0 [1B 00]  |   ANA B
     0x1bbb: 1B [00 00]  |   DCX D
     0x1bbc: 00 [00 00]  |   NOP
     0x1bbd: 00 [00 00]  |   NOP
     0x1bbe: 00 [00 00]  |   NOP
     0x1bbf: 00 [00 10]  |   NOP
     0x1bc0: 00 [10 00]  |   NOP
     0x1bc1: 10 [00 0E]  |   Undefined instruction
     0x1bc2: 00 [0E 05]  |   NOP
     0x1bc3: 0E [05 00]  |   MVI C, 0x05
     0x1bc4: 05 [00 00]  |   DCR B
     0x1bc5: 00 [00 00]  |   NOP
     0x1bc6: 00 [00 00]  |   NOP
     0x1bc7: 00 [00 00]  |   NOP
     0x1bc8: 00 [00 07]  |   NOP
     0x1bc9: 00 [07 D0]  |   NOP
     0x1bca: 07 [D0 1C]  |   RLC
     0x1bcb: D0 [1C C8]  |   RNC
     0x1bcc: 1C [C8 9B]  |   INR E
     0x1bcd: C8 [9B 03]  |   RZ
     0x1bce: 9B [03 00]  |   SBB E
     0x1bcf: 03 [00 00]  |   INX B
     0x1bd0: 00 [00 03]  |   NOP
     0x1bd1: 00 [03 04]  |   NOP
     0x1bd2: 03 [04 78]  |   INX B
     0x1bd3: 04 [78 14]  |   INR B
     0x1bd4: 78 [14 0B]  |   MOV A, B
     0x1bd5: 14 [0B 19]  |   INR D
     0x1bd6: 0B [19 3A]  |   DCX B
     0x1bd7: 19 [3A 6D]  |   DAD D
     0x1bd8: 3A [6D FA]  |   LDA 0xFA6D
     0x1bd9: 6D [FA FA]  |   MOV L, L
     0x1bda: FA [FA 6D]  |   JM 0x6DFA
     0x1bdb: FA [6D 3A]  |   JM 0x3A6D
     0x1bdc: 6D [3A 19]  |   MOV L, L
     0x1bdd: 3A [19 00]  |   LDA 0x0019
     0x1bde: 19 [00 00]  |   DAD D
     0x1bdf: 00 [00 00]  |   NOP
     0x1be0: 00 [00 00]  |   NOP
     0x1be1: 00 [00 00]  |   NOP
     0x1be2: 00 [00 00]  |   NOP
     0x1be3: 00 [00 00]  |   NOP
     0x1be4: 00 [00 00]  |   NOP
     0x1be5: 00 [00 00]  |   NOP
     0x1be6: 00 [00 00]  |   NOP
     0x1be7: 00 [00 01]  |   NOP
     0x1be8: 00 [01 00]  |   NOP
     0x1be9: 01 [00 00]  |   LXI B, 0x0000 
     0x1bea: 00 [00 01]  |   NOP
     0x1beb: 00 [01 74]  |   NOP
     0x1bec: 01 [74 1F]  |   LXI B, 0x1F74 
     0x1bed: 74 [1F 00]  |   MOV M, H
     0x1bee: 1F [00 80]  |   RAR
     0x1bef: 00 [80 00]  |   NOP
     0x1bf0: 80 [00 00]  |   ADD B
     0x1bf1: 00 [00 00]  |   NOP
     0x1bf2: 00 [00 00]  |   NOP
     0x1bf3: 00 [00 00]  |   NOP
     0x1bf4: 00 [00 1C]  |   NOP
     0x1bf5: 00 [1C 2F]  |   NOP
     0x1bf6: 1C [2F 00]  |   INR E
     0x1bf7: 2F [00 00]  |   CMA
     0x1bf8: 00 [00 1C]  |   NOP
     0x1bf9: 00 [1C 27]  |   NOP
     0x1bfa: 1C [27 00]  |   INR E
     0x1bfb: 27 [00 00]  |   DAA
     0x1bfc: 00 [00 1C]  |   NOP
     0x1bfd: 00 [1C 39]  |   NOP
     0x1bfe: 1C [39 00]  |   INR E
     0x1bff: 39 [00 00]  |   DAD SP
     0x1c00: 00 [00 39]  |   NOP
     0x1c01: 00 [39 79]  |   NOP
     0x1c02: 39 [79 7A]  |   DAD SP
     0x1c03: 79 [7A 6E]  |   MOV A, C
     0x1c04: 7A [6E EC]  |   MOV A, D
     0x1c05: 6E [EC FA]  |   MOV L, M
     0x1c06: EC [FA FA]  |   CPE 0xFAFA
     0x1c07: FA [FA EC]  |   JM 0xECFA
     0x1c08: FA [EC 6E]  |   JM 0x6EEC
     0x1c09: EC [6E 7A]  |   CPE 0x7A6E
     0x1c0a: 6E [7A 79]  |   MOV L, M
     0x1c0b: 7A [79 39]  |   MOV A, D
     0x1c0c: 79 [39 00]  |   MOV A, C
     0x1c0d: 39 [00 00]  |   DAD SP
     0x1c0e: 00 [00 00]  |   NOP
     0x1c0f: 00 [00 00]  |   NOP
     0x1c10: 00 [00 00]  |   NOP
     0x1c11: 00 [00 78]  |   NOP
     0x1c12: 00 [78 1D]  |   NOP
     0x1c13: 78 [1D BE]  |   MOV A, B
     0x1c14: 1D [BE 6C]  |   DCR E
     0x1c15: BE [6C 3C]  |   CMP M
     0x1c16: 6C [3C 3C]  |   MOV L, H
     0x1c17: 3C [3C 3C]  |   INR A
     0x1c18: 3C [3C 6C]  |   INR A
     0x1c19: 3C [6C BE]  |   INR A
     0x1c1a: 6C [BE 1D]  |   MOV L, H
     0x1c1b: BE [1D 78]  |   CMP M
     0x1c1c: 1D [78 00]  |   DCR E
     0x1c1d: 78 [00 00]  |   MOV A, B
     0x1c1e: 00 [00 00]  |   NOP
     0x1c1f: 00 [00 00]  |   NOP
     0x1c20: 00 [00 00]  |   NOP
     0x1c21: 00 [00 00]  |   NOP
     0x1c22: 00 [00 19]  |   NOP
     0x1c23: 00 [19 3A]  |   NOP
     0x1c24: 19 [3A 6D]  |   DAD D
     0x1c25: 3A [6D FA]  |   LDA 0xFA6D
     0x1c26: 6D [FA FA]  |   MOV L, L
     0x1c27: FA [FA 6D]  |   JM 0x6DFA
     0x1c28: FA [6D 3A]  |   JM 0x3A6D
     0x1c29: 6D [3A 19]  |   MOV L, L
     0x1c2a: 3A [19 00]  |   LDA 0x0019
     0x1c2b: 19 [00 00]  |   DAD D
     0x1c2c: 00 [00 00]  |   NOP
     0x1c2d: 00 [00 00]  |   NOP
     0x1c2e: 00 [00 00]  |   NOP
     0x1c2f: 00 [00 00]  |   NOP
     0x1c30: 00 [00 38]  |   NOP
     0x1c31: 00 [38 7A]  |   NOP
     0x1c32: 38 [7A 7F]  |   Undefined instruction
     0x1c33: 7A [7F 6D]  |   MOV A, D
     0x1c34: 7F [6D EC]  |   MOV A, A
     0x1c35: 6D [EC FA]  |   MOV L, L
     0x1c36: EC [FA FA]  |   CPE 0xFAFA
     0x1c37: FA [FA EC]  |   JM 0xECFA
     0x1c38: FA [EC 6D]  |   JM 0x6DEC
     0x1c39: EC [6D 7F]  |   CPE 0x7F6D
     0x1c3a: 6D [7F 7A]  |   MOV L, L
     0x1c3b: 7F [7A 38]  |   MOV A, A
     0x1c3c: 7A [38 00]  |   MOV A, D
     0x1c3d: 38 [00 00]  |   Undefined instruction
     0x1c3e: 00 [00 00]  |   NOP
     0x1c3f: 00 [00 00]  |   NOP
     0x1c40: 00 [00 00]  |   NOP
     0x1c41: 00 [00 0E]  |   NOP
     0x1c42: 00 [0E 18]  |   NOP
     0x1c43: 0E [18 BE]  |   MVI C, 0x18
     0x1c44: 18 [BE 6D]  |   Undefined instruction
     0x1c45: BE [6D 3D]  |   CMP M
     0x1c46: 6D [3D 3C]  |   MOV L, L
     0x1c47: 3D [3C 3D]  |   DCR A
     0x1c48: 3C [3D 6D]  |   INR A
     0x1c49: 3D [6D BE]  |   DCR A
     0x1c4a: 6D [BE 18]  |   MOV L, L
     0x1c4b: BE [18 0E]  |   CMP M
     0x1c4c: 18 [0E 00]  |   Undefined instruction
     0x1c4d: 0E [00 00]  |   MVI C, 0x00
     0x1c4e: 00 [00 00]  |   NOP
     0x1c4f: 00 [00 00]  |   NOP
     0x1c50: 00 [00 00]  |   NOP
     0x1c51: 00 [00 00]  |   NOP
     0x1c52: 00 [00 1A]  |   NOP
     0x1c53: 00 [1A 3D]  |   NOP
     0x1c54: 1A [3D 68]  |   LDAX D
     0x1c55: 3D [68 FC]  |   DCR A
     0x1c56: 68 [FC FC]  |   MOV L, B
     0x1c57: FC [FC 68]  |   CM 0x68FC
     0x1c58: FC [68 3D]  |   CM 0x3D68
     0x1c59: 68 [3D 1A]  |   MOV L, B
     0x1c5a: 3D [1A 00]  |   DCR A
     0x1c5b: 1A [00 00]  |   LDAX D
     0x1c5c: 00 [00 00]  |   NOP
     0x1c5d: 00 [00 00]  |   NOP
     0x1c5e: 00 [00 00]  |   NOP
     0x1c5f: 00 [00 00]  |   NOP
     0x1c60: 00 [00 0F]  |   NOP
     0x1c61: 00 [0F 1F]  |   NOP
     0x1c62: 0F [1F 1F]  |   RRC
     0x1c63: 1F [1F 1F]  |   RAR
     0x1c64: 1F [1F 1F]  |   RAR
     0x1c65: 1F [1F 7F]  |   RAR
     0x1c66: 1F [7F FF]  |   RAR
     0x1c67: 7F [FF 7F]  |   MOV A, A
     0x1c68: FF [7F 1F]  |   RST 7
     0x1c69: 7F [1F 1F]  |   MOV A, A
     0x1c6a: 1F [1F 1F]  |   RAR
     0x1c6b: 1F [1F 1F]  |   RAR
     0x1c6c: 1F [1F 0F]  |   RAR
     0x1c6d: 1F [0F 00]  |   RAR
     0x1c6e: 0F [00 00]  |   RRC
     0x1c6f: 00 [00 04]  |   NOP
     0x1c70: 00 [04 01]  |   NOP
     0x1c71: 04 [01 13]  |   INR B
     0x1c72: 01 [13 03]  |   LXI B, 0x0313 
     0x1c73: 13 [03 07]  |   INX D
     0x1c74: 03 [07 B3]  |   INX B
     0x1c75: 07 [B3 0F]  |   RLC
     0x1c76: B3 [0F 2F]  |   ORA E
     0x1c77: 0F [2F 03]  |   RRC
     0x1c78: 2F [03 2F]  |   CMA
     0x1c79: 03 [2F 49]  |   INX B
     0x1c7a: 2F [49 04]  |   CMA
     0x1c7b: 49 [04 03]  |   MOV C, C
     0x1c7c: 04 [03 00]  |   INR B
     0x1c7d: 03 [00 01]  |   INX B
     0x1c7e: 00 [01 40]  |   NOP
     0x1c7f: 01 [40 08]  |   LXI B, 0x0840 
     0x1c80: 40 [08 05]  |   MOV B, B
     0x1c81: 08 [05 A3]  |   Undefined instruction
     0x1c82: 05 [A3 0A]  |   DCR B
     0x1c83: A3 [0A 03]  |   ANA E
     0x1c84: 0A [03 5B]  |   LDAX B
     0x1c85: 03 [5B 0F]  |   INX B
     0x1c86: 5B [0F 27]  |   MOV E, E
     0x1c87: 0F [27 27]  |   RRC
     0x1c88: 27 [27 0B]  |   DAA
     0x1c89: 27 [0B 4B]  |   DAA
     0x1c8a: 0B [4B 40]  |   DCX B
     0x1c8b: 4B [40 84]  |   MOV C, E
     0x1c8c: 40 [84 11]  |   MOV B, B
     0x1c8d: 84 [11 48]  |   ADD H
     0x1c8e: 11 [48 0F]  |   LXI D, 0x0F48 
     0x1c8f: 48 [0F 99]  |   MOV C, B
     0x1c90: 0F [99 3C]  |   RRC
     0x1c91: 99 [3C 7E]  |   SBB C
     0x1c92: 3C [7E 3D]  |   INR A
     0x1c93: 7E [3D BC]  |   MOV A, M
     0x1c94: 3D [BC 3E]  |   DCR A
     0x1c95: BC [3E 7C]  |   CMP H
     0x1c96: 3E [7C 99]  |   MVI A, 0x7C
     0x1c97: 7C [99 27]  |   MOV A, H
     0x1c98: 99 [27 1B]  |   SBB C
     0x1c99: 27 [1B 1A]  |   DAA
     0x1c9a: 1B [1A 26]  |   DCX D
     0x1c9b: 1A [26 0F]  |   LDAX D
     0x1c9c: 26 [0F 0E]  |   MVI H, 0x0F
     0x1c9d: 0F [0E 08]  |   RRC
     0x1c9e: 0E [08 0D]  |   MVI C, 0x08
     0x1c9f: 08 [0D 13]  |   Undefined instruction
     0x1ca0: 0D [13 12]  |   DCR C
     0x1ca1: 13 [12 28]  |   INX D
     0x1ca2: 12 [28 12]  |   STAX D
     0x1ca3: 28 [12 02]  |   Undefined instruction
     0x1ca4: 12 [02 0E]  |   STAX D
     0x1ca5: 02 [0E 11]  |   STAX B
     0x1ca6: 0E [11 04]  |   MVI C, 0x11
     0x1ca7: 11 [04 26]  |   LXI D, 0x2604 
     0x1ca8: 04 [26 00]  |   INR B
     0x1ca9: 26 [00 03]  |   MVI H, 0x00
     0x1caa: 00 [03 15]  |   NOP
     0x1cab: 03 [15 00]  |   INX B
     0x1cac: 15 [00 0D]  |   DCR D
     0x1cad: 00 [0D 02]  |   NOP
     0x1cae: 0D [02 04]  |   DCR C
     0x1caf: 02 [04 26]  |   STAX B
     0x1cb0: 04 [26 13]  |   INR B
     0x1cb1: 26 [13 00]  |   MVI H, 0x13
     0x1cb2: 13 [00 01]  |   INX D
     0x1cb3: 00 [01 0B]  |   NOP
     0x1cb4: 01 [0B 04]  |   LXI B, 0x040B 
     0x1cb5: 0B [04 28]  |   DCX B
     0x1cb6: 04 [28 02]  |   INR B
     0x1cb7: 28 [02 10]  |   Undefined instruction
     0x1cb8: 02 [10 20]  |   STAX B
     0x1cb9: 10 [20 30]  |   Undefined instruction
     0x1cba: 20 [30 13]  |   Undefined instruction
     0x1cbb: 30 [13 08]  |   Undefined instruction
     0x1cbc: 13 [08 0B]  |   INX D
     0x1cbd: 08 [0B 13]  |   Undefined instruction
     0x1cbe: 0B [13 00]  |   DCX B
     0x1cbf: 13 [00 08]  |   INX D
     0x1cc0: 00 [08 49]  |   NOP
     0x1cc1: 08 [49 22]  |   Undefined instruction
     0x1cc2: 49 [22 14]  |   MOV C, C
     0x1cc3: 22 [14 81]  |   SHLD 0x8114
     0x1cc4: 14 [81 42]  |   INR D
     0x1cc5: 81 [42 00]  |   ADD C
     0x1cc6: 42 [00 42]  |   MOV B, D
     0x1cc7: 00 [42 81]  |   NOP
     0x1cc8: 42 [81 14]  |   MOV B, D
     0x1cc9: 81 [14 22]  |   ADD C
     0x1cca: 14 [22 49]  |   INR D
     0x1ccb: 22 [49 08]  |   SHLD 0x0849
     0x1ccc: 49 [08 00]  |   MOV C, C
     0x1ccd: 08 [00 00]  |   Undefined instruction
     0x1cce: 00 [00 44]  |   NOP
     0x1ccf: 00 [44 AA]  |   NOP
     0x1cd0: 44 [AA 10]  |   MOV B, H
     0x1cd1: AA [10 88]  |   XRA D
     0x1cd2: 10 [88 54]  |   Undefined instruction
     0x1cd3: 88 [54 22]  |   ADC B
     0x1cd4: 54 [22 10]  |   MOV D, H
     0x1cd5: 22 [10 AA]  |   SHLD 0xAA10
     0x1cd6: 10 [AA 44]  |   Undefined instruction
     0x1cd7: AA [44 22]  |   XRA D
     0x1cd8: 44 [22 54]  |   MOV B, H
     0x1cd9: 22 [54 88]  |   SHLD 0x8854
     0x1cda: 54 [88 4A]  |   MOV D, H
     0x1cdb: 88 [4A 15]  |   ADC B
     0x1cdc: 4A [15 BE]  |   MOV C, D
     0x1cdd: 15 [BE 3F]  |   DCR D
     0x1cde: BE [3F 5E]  |   CMP M
     0x1cdf: 3F [5E 25]  |   CMC
     0x1ce0: 5E [25 04]  |   MOV E, M
     0x1ce1: 25 [04 FC]  |   DCR H
     0x1ce2: 04 [FC 04]  |   INR B
     0x1ce3: FC [04 10]  |   CM 0x1004
     0x1ce4: 04 [10 FC]  |   INR B
     0x1ce5: 10 [FC 10]  |   Undefined instruction
     0x1ce6: FC [10 20]  |   CM 0x2010
     0x1ce7: 10 [20 FC]  |   Undefined instruction
     0x1ce8: 20 [FC 20]  |   Undefined instruction
     0x1ce9: FC [20 80]  |   CM 0x8020
     0x1cea: 20 [80 FC]  |   Undefined instruction
     0x1ceb: 80 [FC 80]  |   ADD B
     0x1cec: FC [80 00]  |   CM 0x0080
     0x1ced: 80 [00 FE]  |   ADD B
     0x1cee: 00 [FE 00]  |   NOP
     0x1cef: FE [00 24]  |   CPI 0x00
     0x1cf0: 00 [24 FE]  |   NOP
     0x1cf1: 24 [FE 12]  |   INR H
     0x1cf2: FE [12 00]  |   CPI 0x12
     0x1cf3: 12 [00 FE]  |   STAX D
     0x1cf4: 00 [FE 00]  |   NOP
     0x1cf5: FE [00 48]  |   CPI 0x00
     0x1cf6: 00 [48 FE]  |   NOP
     0x1cf7: 48 [FE 90]  |   MOV C, B
     0x1cf8: FE [90 0F]  |   CPI 0x90
     0x1cf9: 90 [0F 0B]  |   SUB B
     0x1cfa: 0F [0B 00]  |   RRC
     0x1cfb: 0B [00 29]  |   DCX B
     0x1cfc: 00 [29 00]  |   NOP
     0x1cfd: 29 [00 00]  |   DAD H
     0x1cfe: 00 [00 01]  |   NOP
     0x1cff: 00 [01 07]  |   NOP
     0x1d00: 01 [07 01]  |   LXI B, 0x0107 
     0x1d01: 07 [01 01]  |   RLC
     0x1d02: 01 [01 01]  |   LXI B, 0x0101 
     0x1d03: 01 [01 04]  |   LXI B, 0x0401 
     0x1d04: 01 [04 0B]  |   LXI B, 0x0B04 
     0x1d05: 04 [0B 01]  |   INR B
     0x1d06: 0B [01 06]  |   DCX B
     0x1d07: 01 [06 03]  |   LXI B, 0x0306 
     0x1d08: 06 [03 01]  |   MVI B, 0x03
     0x1d09: 03 [01 01]  |   INX B
     0x1d0a: 01 [01 0B]  |   LXI B, 0x0B01 
     0x1d0b: 01 [0B 09]  |   LXI B, 0x090B 
     0x1d0c: 0B [09 02]  |   DCX B
     0x1d0d: 09 [02 08]  |   DAD B
     0x1d0e: 02 [08 02]  |   STAX B
     0x1d0f: 08 [02 0B]  |   Undefined instruction
     0x1d10: 02 [0B 04]  |   STAX B
     0x1d11: 0B [04 07]  |   DCX B
     0x1d12: 04 [07 0A]  |   INR B
     0x1d13: 07 [0A 05]  |   RLC
     0x1d14: 0A [05 02]  |   LDAX B
     0x1d15: 05 [02 05]  |   DCR B
     0x1d16: 02 [05 04]  |   STAX B
     0x1d17: 05 [04 06]  |   DCR B
     0x1d18: 04 [06 07]  |   INR B
     0x1d19: 06 [07 08]  |   MVI B, 0x07
     0x1d1a: 07 [08 0A]  |   RLC
     0x1d1b: 08 [0A 06]  |   Undefined instruction
     0x1d1c: 0A [06 0A]  |   LDAX B
     0x1d1d: 06 [0A 03]  |   MVI B, 0x0A
     0x1d1e: 0A [03 FF]  |   LDAX B
     0x1d1f: 03 [FF 0F]  |   INX B
     0x1d20: FF [0F FF]  |   RST 7
     0x1d21: 0F [FF 1F]  |   RRC
     0x1d22: FF [1F FF]  |   RST 7
     0x1d23: 1F [FF 3F]  |   RAR
     0x1d24: FF [3F FF]  |   RST 7
     0x1d25: 3F [FF 7F]  |   CMC
     0x1d26: FF [7F FF]  |   RST 7
     0x1d27: 7F [FF FF]  |   MOV A, A
     0x1d28: FF [FF FC]  |   RST 7
     0x1d29: FF [FC FF]  |   RST 7
     0x1d2a: FC [FF F8]  |   CM 0xF8FF
     0x1d2b: FF [F8 FF]  |   RST 7
     0x1d2c: F8 [FF F0]  |   RM
     0x1d2d: FF [F0 FF]  |   RST 7
     0x1d2e: F0 [FF F0]  |   RP
     0x1d2f: FF [F0 FF]  |   RST 7
     0x1d30: F0 [FF F0]  |   RP
     0x1d31: FF [F0 FF]  |   RST 7
     0x1d32: F0 [FF F0]  |   RP
     0x1d33: FF [F0 FF]  |   RST 7
     0x1d34: F0 [FF F0]  |   RP
     0x1d35: FF [F0 FF]  |   RST 7
     0x1d36: F0 [FF F0]  |   RP
     0x1d37: FF [F0 FF]  |   RST 7
     0x1d38: F0 [FF F0]  |   RP
     0x1d39: FF [F0 FF]  |   RST 7
     0x1d3a: F0 [FF F8]  |   RP
     0x1d3b: FF [F8 FF]  |   RST 7
     0x1d3c: F8 [FF FC]  |   RM
     0x1d3d: FF [FC FF]  |   RST 7
     0x1d3e: FC [FF FF]  |   CM 0xFFFF
     0x1d3f: FF [FF FF]  |   RST 7
     0x1d40: FF [FF FF]  |   RST 7
     0x1d41: FF [FF FF]  |   RST 7
     0x1d42: FF [FF FF]  |   RST 7
     0x1d43: FF [FF 7F]  |   RST 7
     0x1d44: FF [7F FF]  |   RST 7
     0x1d45: 7F [FF 3F]  |   MOV A, A
     0x1d46: FF [3F FF]  |   RST 7
     0x1d47: 3F [FF 1F]  |   CMC
     0x1d48: FF [1F FF]  |   RST 7
     0x1d49: 1F [FF 0F]  |   RAR
     0x1d4a: FF [0F 05]  |   RST 7
     0x1d4b: 0F [05 10]  |   RRC
     0x1d4c: 05 [10 15]  |   DCR B
     0x1d4d: 10 [15 30]  |   Undefined instruction
     0x1d4e: 15 [30 94]  |   DCR D
     0x1d4f: 30 [94 97]  |   Undefined instruction
     0x1d50: 94 [97 9A]  |   SUB H
     0x1d51: 97 [9A 9D]  |   SUB A
     0x1d52: 9A [9D 10]  |   SBB D
     0x1d53: 9D [10 05]  |   SBB L
     0x1d54: 10 [05 05]  |   Undefined instruction
     0x1d55: 05 [05 10]  |   DCR B
     0x1d56: 05 [10 15]  |   DCR B
     0x1d57: 10 [15 10]  |   Undefined instruction
     0x1d58: 15 [10 10]  |   DCR D
     0x1d59: 10 [10 05]  |   Undefined instruction
     0x1d5a: 10 [05 30]  |   Undefined instruction
     0x1d5b: 05 [30 10]  |   DCR B
     0x1d5c: 30 [10 10]  |   Undefined instruction
     0x1d5d: 10 [10 10]  |   Undefined instruction
     0x1d5e: 10 [10 05]  |   Undefined instruction
     0x1d5f: 10 [05 15]  |   Undefined instruction
     0x1d60: 05 [15 10]  |   DCR B
     0x1d61: 15 [10 05]  |   DCR D
     0x1d62: 10 [05 00]  |   Undefined instruction
     0x1d63: 05 [00 00]  |   DCR B
     0x1d64: 00 [00 00]  |   NOP
     0x1d65: 00 [00 00]  |   NOP
     0x1d66: 00 [00 04]  |   NOP
     0x1d67: 00 [04 0C]  |   NOP
     0x1d68: 04 [0C 1E]  |   INR B
     0x1d69: 0C [1E 37]  |   INR C
     0x1d6a: 1E [37 3E]  |   MVI E, 0x37
     0x1d6b: 37 [3E 7C]  |   STC
     0x1d6c: 3E [7C 74]  |   MVI A, 0x7C
     0x1d6d: 7C [74 7E]  |   MOV A, H
     0x1d6e: 74 [7E 7E]  |   MOV M, H
     0x1d6f: 7E [7E 74]  |   MOV A, M
     0x1d70: 7E [74 7C]  |   MOV A, M
     0x1d71: 74 [7C 3E]  |   MOV M, H
     0x1d72: 7C [3E 37]  |   MOV A, H
     0x1d73: 3E [37 1E]  |   MVI A, 0x37
     0x1d74: 37 [1E 0C]  |   STC
     0x1d75: 1E [0C 04]  |   MVI E, 0x0C
     0x1d76: 0C [04 00]  |   INR C
     0x1d77: 04 [00 00]  |   INR B
     0x1d78: 00 [00 00]  |   NOP
     0x1d79: 00 [00 00]  |   NOP
     0x1d7a: 00 [00 00]  |   NOP
     0x1d7b: 00 [00 22]  |   NOP
     0x1d7c: 00 [22 00]  |   NOP
     0x1d7d: 22 [00 A5]  |   SHLD 0xA500
     0x1d7e: 00 [A5 40]  |   NOP
     0x1d7f: A5 [40 08]  |   ANA L
     0x1d80: 40 [08 98]  |   MOV B, B
     0x1d81: 08 [98 3D]  |   Undefined instruction
     0x1d82: 98 [3D B6]  |   SBB B
     0x1d83: 3D [B6 3C]  |   DCR A
     0x1d84: B6 [3C 36]  |   ORA M
     0x1d85: 3C [36 1D]  |   INR A
     0x1d86: 36 [1D 10]  |   MVI M, 0x1D
     0x1d87: 1D [10 48]  |   DCR E
     0x1d88: 10 [48 62]  |   Undefined instruction
     0x1d89: 48 [62 B6]  |   MOV C, B
     0x1d8a: 62 [B6 1D]  |   MOV H, D
     0x1d8b: B6 [1D 98]  |   ORA M
     0x1d8c: 1D [98 08]  |   DCR E
     0x1d8d: 98 [08 42]  |   SBB B
     0x1d8e: 08 [42 90]  |   Undefined instruction
     0x1d8f: 42 [90 08]  |   MOV B, D
     0x1d90: 90 [08 00]  |   SUB B
     0x1d91: 08 [00 00]  |   Undefined instruction
     0x1d92: 00 [00 26]  |   NOP
     0x1d93: 00 [26 1F]  |   NOP
     0x1d94: 26 [1F 1A]  |   MVI H, 0x1F
     0x1d95: 1F [1A 1B]  |   RAR
     0x1d96: 1A [1B 1A]  |   LDAX D
     0x1d97: 1B [1A 1A]  |   DCX D
     0x1d98: 1A [1A 1B]  |   LDAX D
     0x1d99: 1A [1B 1F]  |   LDAX D
     0x1d9a: 1B [1F 1A]  |   DCX D
     0x1d9b: 1F [1A 1D]  |   RAR
     0x1d9c: 1A [1D 1A]  |   LDAX D
     0x1d9d: 1D [1A 1A]  |   DCR E
     0x1d9e: 1A [1A 10]  |   LDAX D
     0x1d9f: 1A [10 20]  |   LDAX D
     0x1da0: 10 [20 30]  |   Undefined instruction
     0x1da1: 20 [30 60]  |   Undefined instruction
     0x1da2: 30 [60 50]  |   Undefined instruction
     0x1da3: 60 [50 48]  |   MOV H, B
     0x1da4: 50 [48 48]  |   MOV D, B
     0x1da5: 48 [48 48]  |   MOV C, B
     0x1da6: 48 [48 40]  |   MOV C, B
     0x1da7: 48 [40 40]  |   MOV C, B
     0x1da8: 40 [40 40]  |   MOV B, B
     0x1da9: 40 [40 0F]  |   MOV B, B
     0x1daa: 40 [0F 0B]  |   MOV B, B
     0x1dab: 0F [0B 00]  |   RRC
     0x1dac: 0B [00 18]  |   DCX B
     0x1dad: 00 [18 12]  |   NOP
     0x1dae: 18 [12 0F]  |   Undefined instruction
     0x1daf: 12 [0F 00]  |   STAX D
     0x1db0: 0F [00 02]  |   RRC
     0x1db1: 00 [02 04]  |   NOP
     0x1db2: 02 [04 26]  |   STAX B
     0x1db3: 04 [26 26]  |   INR B
     0x1db4: 26 [26 08]  |   MVI H, 0x26
     0x1db5: 26 [08 0D]  |   MVI H, 0x08
     0x1db6: 08 [0D 15]  |   Undefined instruction
     0x1db7: 0D [15 00]  |   DCR C
     0x1db8: 15 [00 03]  |   DCR D
     0x1db9: 00 [03 04]  |   NOP
     0x1dba: 03 [04 11]  |   INX B
     0x1dbb: 04 [11 12]  |   INR B
     0x1dbc: 11 [12 0E]  |   LXI D, 0x0E12 
     0x1dbd: 12 [0E 2C]  |   STAX D
     0x1dbe: 0E [2C 68]  |   MVI C, 0x2C
     0x1dbf: 2C [68 1D]  |   INR L
     0x1dc0: 68 [1D 0C]  |   MOV L, B
     0x1dc1: 1D [0C 2C]  |   DCR E
     0x1dc2: 0C [2C 20]  |   INR C
     0x1dc3: 2C [20 1C]  |   INR L
     0x1dc4: 20 [1C 0A]  |   Undefined instruction
     0x1dc5: 1C [0A 2C]  |   INR E
     0x1dc6: 0A [2C 40]  |   LDAX B
     0x1dc7: 2C [40 1C]  |   INR L
     0x1dc8: 40 [1C 08]  |   MOV B, B
     0x1dc9: 1C [08 2C]  |   INR E
     0x1dca: 08 [2C 00]  |   Undefined instruction
     0x1dcb: 2C [00 1C]  |   INR L
     0x1dcc: 00 [1C FF]  |   NOP
     0x1dcd: 1C [FF 0E]  |   INR E
     0x1dce: FF [0E 2E]  |   RST 7
     0x1dcf: 0E [2E E0]  |   MVI C, 0x2E
     0x1dd0: 2E [E0 1D]  |   MVI L, 0xE0
     0x1dd1: E0 [1D 0C]  |   RPO
     0x1dd2: 1D [0C 2E]  |   DCR E
     0x1dd3: 0C [2E EA]  |   INR C
     0x1dd4: 2E [EA 1D]  |   MVI L, 0xEA
     0x1dd5: EA [1D 0A]  |   JPE 0x0A1D
     0x1dd6: 1D [0A 2E]  |   DCR E
     0x1dd7: 0A [2E F4]  |   LDAX B
     0x1dd8: 2E [F4 1D]  |   MVI L, 0xF4
     0x1dd9: F4 [1D 08]  |   CP 0x081D
     0x1dda: 1D [08 2E]  |   DCR E
     0x1ddb: 08 [2E 99]  |   Undefined instruction
     0x1ddc: 2E [99 1C]  |   MVI L, 0x99
     0x1ddd: 99 [1C FF]  |   SBB C
     0x1dde: 1C [FF 27]  |   INR E
     0x1ddf: FF [27 38]  |   RST 7
     0x1de0: 27 [38 26]  |   DAA
     0x1de1: 38 [26 0C]  |   Undefined instruction
     0x1de2: 26 [0C 18]  |   MVI H, 0x0C
     0x1de3: 0C [18 12]  |   INR C
     0x1de4: 18 [12 13]  |   Undefined instruction
     0x1de5: 12 [13 04]  |   STAX D
     0x1de6: 13 [04 11]  |   INX D
     0x1de7: 04 [11 18]  |   INR B
     0x1de8: 11 [18 27]  |   LXI D, 0x2718 
     0x1de9: 18 [27 1D]  |   Undefined instruction
     0x1dea: 27 [1D 1A]  |   DAA
     0x1deb: 1D [1A 26]  |   DCR E
     0x1dec: 1A [26 0F]  |   LDAX D
     0x1ded: 26 [0F 0E]  |   MVI H, 0x0F
     0x1dee: 0F [0E 08]  |   RRC
     0x1def: 0E [08 0D]  |   MVI C, 0x08
     0x1df0: 08 [0D 13]  |   Undefined instruction
     0x1df1: 0D [13 12]  |   DCR C
     0x1df2: 13 [12 27]  |   INX D
     0x1df3: 12 [27 1C]  |   STAX D
     0x1df4: 27 [1C 1A]  |   DAA
     0x1df5: 1C [1A 26]  |   INR E
     0x1df6: 1A [26 0F]  |   LDAX D
     0x1df7: 26 [0F 0E]  |   MVI H, 0x0F
     0x1df8: 0F [0E 08]  |   RRC
     0x1df9: 0E [08 0D]  |   MVI C, 0x08
     0x1dfa: 08 [0D 13]  |   Undefined instruction
     0x1dfb: 0D [13 12]  |   DCR C
     0x1dfc: 13 [12 00]  |   INX D
     0x1dfd: 12 [00 00]  |   STAX D
     0x1dfe: 00 [00 00]  |   NOP
     0x1dff: 00 [00 1F]  |   NOP
     0x1e00: 00 [1F 24]  |   NOP
     0x1e01: 1F [24 44]  |   RAR
     0x1e02: 24 [44 24]  |   INR H
     0x1e03: 44 [24 1F]  |   MOV B, H
     0x1e04: 24 [1F 00]  |   INR H
     0x1e05: 1F [00 00]  |   RAR
     0x1e06: 00 [00 00]  |   NOP
     0x1e07: 00 [00 7F]  |   NOP
     0x1e08: 00 [7F 49]  |   NOP
     0x1e09: 7F [49 49]  |   MOV A, A
     0x1e0a: 49 [49 49]  |   MOV C, C
     0x1e0b: 49 [49 36]  |   MOV C, C
     0x1e0c: 49 [36 00]  |   MOV C, C
     0x1e0d: 36 [00 00]  |   MVI M, 0x00
     0x1e0e: 00 [00 00]  |   NOP
     0x1e0f: 00 [00 3E]  |   NOP
     0x1e10: 00 [3E 41]  |   NOP
     0x1e11: 3E [41 41]  |   MVI A, 0x41
     0x1e12: 41 [41 41]  |   MOV B, C
     0x1e13: 41 [41 22]  |   MOV B, C
     0x1e14: 41 [22 00]  |   MOV B, C
     0x1e15: 22 [00 00]  |   SHLD 0x0000
     0x1e16: 00 [00 00]  |   NOP
     0x1e17: 00 [00 7F]  |   NOP
     0x1e18: 00 [7F 41]  |   NOP
     0x1e19: 7F [41 41]  |   MOV A, A
     0x1e1a: 41 [41 41]  |   MOV B, C
     0x1e1b: 41 [41 3E]  |   MOV B, C
     0x1e1c: 41 [3E 00]  |   MOV B, C
     0x1e1d: 3E [00 00]  |   MVI A, 0x00
     0x1e1e: 00 [00 00]  |   NOP
     0x1e1f: 00 [00 7F]  |   NOP
     0x1e20: 00 [7F 49]  |   NOP
     0x1e21: 7F [49 49]  |   MOV A, A
     0x1e22: 49 [49 49]  |   MOV C, C
     0x1e23: 49 [49 41]  |   MOV C, C
     0x1e24: 49 [41 00]  |   MOV C, C
     0x1e25: 41 [00 00]  |   MOV B, C
     0x1e26: 00 [00 00]  |   NOP
     0x1e27: 00 [00 7F]  |   NOP
     0x1e28: 00 [7F 48]  |   NOP
     0x1e29: 7F [48 48]  |   MOV A, A
     0x1e2a: 48 [48 48]  |   MOV C, B
     0x1e2b: 48 [48 40]  |   MOV C, B
     0x1e2c: 48 [40 00]  |   MOV C, B
     0x1e2d: 40 [00 00]  |   MOV B, B
     0x1e2e: 00 [00 00]  |   NOP
     0x1e2f: 00 [00 3E]  |   NOP
     0x1e30: 00 [3E 41]  |   NOP
     0x1e31: 3E [41 41]  |   MVI A, 0x41
     0x1e32: 41 [41 45]  |   MOV B, C
     0x1e33: 41 [45 47]  |   MOV B, C
     0x1e34: 45 [47 00]  |   MOV B, L
     0x1e35: 47 [00 00]  |   MOV B, A
     0x1e36: 00 [00 00]  |   NOP
     0x1e37: 00 [00 7F]  |   NOP
     0x1e38: 00 [7F 08]  |   NOP
     0x1e39: 7F [08 08]  |   MOV A, A
     0x1e3a: 08 [08 08]  |   Undefined instruction
     0x1e3b: 08 [08 7F]  |   Undefined instruction
     0x1e3c: 08 [7F 00]  |   Undefined instruction
     0x1e3d: 7F [00 00]  |   MOV A, A
     0x1e3e: 00 [00 00]  |   NOP
     0x1e3f: 00 [00 00]  |   NOP
     0x1e40: 00 [00 41]  |   NOP
     0x1e41: 00 [41 7F]  |   NOP
     0x1e42: 41 [7F 41]  |   MOV B, C
     0x1e43: 7F [41 00]  |   MOV A, A
     0x1e44: 41 [00 00]  |   MOV B, C
     0x1e45: 00 [00 00]  |   NOP
     0x1e46: 00 [00 00]  |   NOP
     0x1e47: 00 [00 02]  |   NOP
     0x1e48: 00 [02 01]  |   NOP
     0x1e49: 02 [01 01]  |   STAX B
     0x1e4a: 01 [01 01]  |   LXI B, 0x0101 
     0x1e4b: 01 [01 7E]  |   LXI B, 0x7E01 
     0x1e4c: 01 [7E 00]  |   LXI B, 0x007E 
     0x1e4d: 7E [00 00]  |   MOV A, M
     0x1e4e: 00 [00 00]  |   NOP
     0x1e4f: 00 [00 7F]  |   NOP
     0x1e50: 00 [7F 08]  |   NOP
     0x1e51: 7F [08 14]  |   MOV A, A
     0x1e52: 08 [14 22]  |   Undefined instruction
     0x1e53: 14 [22 41]  |   INR D
     0x1e54: 22 [41 00]  |   SHLD 0x0041
     0x1e55: 41 [00 00]  |   MOV B, C
     0x1e56: 00 [00 00]  |   NOP
     0x1e57: 00 [00 7F]  |   NOP
     0x1e58: 00 [7F 01]  |   NOP
     0x1e59: 7F [01 01]  |   MOV A, A
     0x1e5a: 01 [01 01]  |   LXI B, 0x0101 
     0x1e5b: 01 [01 01]  |   LXI B, 0x0101 
     0x1e5c: 01 [01 00]  |   LXI B, 0x0001 
     0x1e5d: 01 [00 00]  |   LXI B, 0x0000 
     0x1e5e: 00 [00 00]  |   NOP
     0x1e5f: 00 [00 7F]  |   NOP
     0x1e60: 00 [7F 20]  |   NOP
     0x1e61: 7F [20 18]  |   MOV A, A
     0x1e62: 20 [18 20]  |   Undefined instruction
     0x1e63: 18 [20 7F]  |   Undefined instruction
     0x1e64: 20 [7F 00]  |   Undefined instruction
     0x1e65: 7F [00 00]  |   MOV A, A
     0x1e66: 00 [00 00]  |   NOP
     0x1e67: 00 [00 7F]  |   NOP
     0x1e68: 00 [7F 10]  |   NOP
     0x1e69: 7F [10 08]  |   MOV A, A
     0x1e6a: 10 [08 04]  |   Undefined instruction
     0x1e6b: 08 [04 7F]  |   Undefined instruction
     0x1e6c: 04 [7F 00]  |   INR B
     0x1e6d: 7F [00 00]  |   MOV A, A
     0x1e6e: 00 [00 00]  |   NOP
     0x1e6f: 00 [00 3E]  |   NOP
     0x1e70: 00 [3E 41]  |   NOP
     0x1e71: 3E [41 41]  |   MVI A, 0x41
     0x1e72: 41 [41 41]  |   MOV B, C
     0x1e73: 41 [41 3E]  |   MOV B, C
     0x1e74: 41 [3E 00]  |   MOV B, C
     0x1e75: 3E [00 00]  |   MVI A, 0x00
     0x1e76: 00 [00 00]  |   NOP
     0x1e77: 00 [00 7F]  |   NOP
     0x1e78: 00 [7F 48]  |   NOP
     0x1e79: 7F [48 48]  |   MOV A, A
     0x1e7a: 48 [48 48]  |   MOV C, B
     0x1e7b: 48 [48 30]  |   MOV C, B
     0x1e7c: 48 [30 00]  |   MOV C, B
     0x1e7d: 30 [00 00]  |   Undefined instruction
     0x1e7e: 00 [00 00]  |   NOP
     0x1e7f: 00 [00 3E]  |   NOP
     0x1e80: 00 [3E 41]  |   NOP
     0x1e81: 3E [41 45]  |   MVI A, 0x41
     0x1e82: 41 [45 42]  |   MOV B, C
     0x1e83: 45 [42 3D]  |   MOV B, L
     0x1e84: 42 [3D 00]  |   MOV B, D
     0x1e85: 3D [00 00]  |   DCR A
     0x1e86: 00 [00 00]  |   NOP
     0x1e87: 00 [00 7F]  |   NOP
     0x1e88: 00 [7F 48]  |   NOP
     0x1e89: 7F [48 4C]  |   MOV A, A
     0x1e8a: 48 [4C 4A]  |   MOV C, B
     0x1e8b: 4C [4A 31]  |   MOV C, H
     0x1e8c: 4A [31 00]  |   MOV C, D
     0x1e8d: 31 [00 00]  |   LXI SP, 0x0000 
     0x1e8e: 00 [00 00]  |   NOP
     0x1e8f: 00 [00 32]  |   NOP
     0x1e90: 00 [32 49]  |   NOP
     0x1e91: 32 [49 49]  |   STA 0x4949
     0x1e92: 49 [49 49]  |   MOV C, C
     0x1e93: 49 [49 26]  |   MOV C, C
     0x1e94: 49 [26 00]  |   MOV C, C
     0x1e95: 26 [00 00]  |   MVI H, 0x00
     0x1e96: 00 [00 00]  |   NOP
     0x1e97: 00 [00 40]  |   NOP
     0x1e98: 00 [40 40]  |   NOP
     0x1e99: 40 [40 7F]  |   MOV B, B
     0x1e9a: 40 [7F 40]  |   MOV B, B
     0x1e9b: 7F [40 40]  |   MOV A, A
     0x1e9c: 40 [40 00]  |   MOV B, B
     0x1e9d: 40 [00 00]  |   MOV B, B
     0x1e9e: 00 [00 00]  |   NOP
     0x1e9f: 00 [00 7E]  |   NOP
     0x1ea0: 00 [7E 01]  |   NOP
     0x1ea1: 7E [01 01]  |   MOV A, M
     0x1ea2: 01 [01 01]  |   LXI B, 0x0101 
     0x1ea3: 01 [01 7E]  |   LXI B, 0x7E01 
     0x1ea4: 01 [7E 00]  |   LXI B, 0x007E 
     0x1ea5: 7E [00 00]  |   MOV A, M
     0x1ea6: 00 [00 00]  |   NOP
     0x1ea7: 00 [00 7C]  |   NOP
     0x1ea8: 00 [7C 02]  |   NOP
     0x1ea9: 7C [02 01]  |   MOV A, H
     0x1eaa: 02 [01 02]  |   STAX B
     0x1eab: 01 [02 7C]  |   LXI B, 0x7C02 
     0x1eac: 02 [7C 00]  |   STAX B
     0x1ead: 7C [00 00]  |   MOV A, H
     0x1eae: 00 [00 00]  |   NOP
     0x1eaf: 00 [00 7F]  |   NOP
     0x1eb0: 00 [7F 02]  |   NOP
     0x1eb1: 7F [02 0C]  |   MOV A, A
     0x1eb2: 02 [0C 02]  |   STAX B
     0x1eb3: 0C [02 7F]  |   INR C
     0x1eb4: 02 [7F 00]  |   STAX B
     0x1eb5: 7F [00 00]  |   MOV A, A
     0x1eb6: 00 [00 00]  |   NOP
     0x1eb7: 00 [00 63]  |   NOP
     0x1eb8: 00 [63 14]  |   NOP
     0x1eb9: 63 [14 08]  |   MOV H, E
     0x1eba: 14 [08 14]  |   INR D
     0x1ebb: 08 [14 63]  |   Undefined instruction
     0x1ebc: 14 [63 00]  |   INR D
     0x1ebd: 63 [00 00]  |   MOV H, E
     0x1ebe: 00 [00 00]  |   NOP
     0x1ebf: 00 [00 60]  |   NOP
     0x1ec0: 00 [60 10]  |   NOP
     0x1ec1: 60 [10 0F]  |   MOV H, B
     0x1ec2: 10 [0F 10]  |   Undefined instruction
     0x1ec3: 0F [10 60]  |   RRC
     0x1ec4: 10 [60 00]  |   Undefined instruction
     0x1ec5: 60 [00 00]  |   MOV H, B
     0x1ec6: 00 [00 00]  |   NOP
     0x1ec7: 00 [00 43]  |   NOP
     0x1ec8: 00 [43 45]  |   NOP
     0x1ec9: 43 [45 49]  |   MOV B, E
     0x1eca: 45 [49 51]  |   MOV B, L
     0x1ecb: 49 [51 61]  |   MOV C, C
     0x1ecc: 51 [61 00]  |   MOV D, C
     0x1ecd: 61 [00 00]  |   MOV H, C
     0x1ece: 00 [00 00]  |   NOP
     0x1ecf: 00 [00 3E]  |   NOP
     0x1ed0: 00 [3E 45]  |   NOP
     0x1ed1: 3E [45 49]  |   MVI A, 0x45
     0x1ed2: 45 [49 51]  |   MOV B, L
     0x1ed3: 49 [51 3E]  |   MOV C, C
     0x1ed4: 51 [3E 00]  |   MOV D, C
     0x1ed5: 3E [00 00]  |   MVI A, 0x00
     0x1ed6: 00 [00 00]  |   NOP
     0x1ed7: 00 [00 00]  |   NOP
     0x1ed8: 00 [00 21]  |   NOP
     0x1ed9: 00 [21 7F]  |   NOP
     0x1eda: 21 [7F 01]  |   LXI H, 0x017F 
     0x1edb: 7F [01 00]  |   MOV A, A
     0x1edc: 01 [00 00]  |   LXI B, 0x0000 
     0x1edd: 00 [00 00]  |   NOP
     0x1ede: 00 [00 00]  |   NOP
     0x1edf: 00 [00 23]  |   NOP
     0x1ee0: 00 [23 45]  |   NOP
     0x1ee1: 23 [45 49]  |   INX H
     0x1ee2: 45 [49 49]  |   MOV B, L
     0x1ee3: 49 [49 31]  |   MOV C, C
     0x1ee4: 49 [31 00]  |   MOV C, C
     0x1ee5: 31 [00 00]  |   LXI SP, 0x0000 
     0x1ee6: 00 [00 00]  |   NOP
     0x1ee7: 00 [00 42]  |   NOP
     0x1ee8: 00 [42 41]  |   NOP
     0x1ee9: 42 [41 49]  |   MOV B, D
     0x1eea: 41 [49 59]  |   MOV B, C
     0x1eeb: 49 [59 66]  |   MOV C, C
     0x1eec: 59 [66 00]  |   MOV E, C
     0x1eed: 66 [00 00]  |   MOV H, M
     0x1eee: 00 [00 00]  |   NOP
     0x1eef: 00 [00 0C]  |   NOP
     0x1ef0: 00 [0C 14]  |   NOP
     0x1ef1: 0C [14 24]  |   INR C
     0x1ef2: 14 [24 7F]  |   INR D
     0x1ef3: 24 [7F 04]  |   INR H
     0x1ef4: 7F [04 00]  |   MOV A, A
     0x1ef5: 04 [00 00]  |   INR B
     0x1ef6: 00 [00 00]  |   NOP
     0x1ef7: 00 [00 72]  |   NOP
     0x1ef8: 00 [72 51]  |   NOP
     0x1ef9: 72 [51 51]  |   MOV M, D
     0x1efa: 51 [51 51]  |   MOV D, C
     0x1efb: 51 [51 4E]  |   MOV D, C
     0x1efc: 51 [4E 00]  |   MOV D, C
     0x1efd: 4E [00 00]  |   MOV C, M
     0x1efe: 00 [00 00]  |   NOP
     0x1eff: 00 [00 1E]  |   NOP
     0x1f00: 00 [1E 29]  |   NOP
     0x1f01: 1E [29 49]  |   MVI E, 0x29
     0x1f02: 29 [49 49]  |   DAD H
     0x1f03: 49 [49 46]  |   MOV C, C
     0x1f04: 49 [46 00]  |   MOV C, C
     0x1f05: 46 [00 00]  |   MOV B, M
     0x1f06: 00 [00 00]  |   NOP
     0x1f07: 00 [00 40]  |   NOP
     0x1f08: 00 [40 47]  |   NOP
     0x1f09: 40 [47 48]  |   MOV B, B
     0x1f0a: 47 [48 50]  |   MOV B, A
     0x1f0b: 48 [50 60]  |   MOV C, B
     0x1f0c: 50 [60 00]  |   MOV D, B
     0x1f0d: 60 [00 00]  |   MOV H, B
     0x1f0e: 00 [00 00]  |   NOP
     0x1f0f: 00 [00 36]  |   NOP
     0x1f10: 00 [36 49]  |   NOP
     0x1f11: 36 [49 49]  |   MVI M, 0x49
     0x1f12: 49 [49 49]  |   MOV C, C
     0x1f13: 49 [49 36]  |   MOV C, C
     0x1f14: 49 [36 00]  |   MOV C, C
     0x1f15: 36 [00 00]  |   MVI M, 0x00
     0x1f16: 00 [00 00]  |   NOP
     0x1f17: 00 [00 31]  |   NOP
     0x1f18: 00 [31 49]  |   NOP
     0x1f19: 31 [49 49]  |   LXI SP, 0x4949 
     0x1f1a: 49 [49 4A]  |   MOV C, C
     0x1f1b: 49 [4A 3C]  |   MOV C, C
     0x1f1c: 4A [3C 00]  |   MOV C, D
     0x1f1d: 3C [00 00]  |   INR A
     0x1f1e: 00 [00 00]  |   NOP
     0x1f1f: 00 [00 08]  |   NOP
     0x1f20: 00 [08 14]  |   NOP
     0x1f21: 08 [14 22]  |   Undefined instruction
     0x1f22: 14 [22 41]  |   INR D
     0x1f23: 22 [41 00]  |   SHLD 0x0041
     0x1f24: 41 [00 00]  |   MOV B, C
     0x1f25: 00 [00 00]  |   NOP
     0x1f26: 00 [00 00]  |   NOP
     0x1f27: 00 [00 00]  |   NOP
     0x1f28: 00 [00 41]  |   NOP
     0x1f29: 00 [41 22]  |   NOP
     0x1f2a: 41 [22 14]  |   MOV B, C
     0x1f2b: 22 [14 08]  |   SHLD 0x0814
     0x1f2c: 14 [08 00]  |   INR D
     0x1f2d: 08 [00 00]  |   Undefined instruction
     0x1f2e: 00 [00 00]  |   NOP
     0x1f2f: 00 [00 00]  |   NOP
     0x1f30: 00 [00 00]  |   NOP
     0x1f31: 00 [00 00]  |   NOP
     0x1f32: 00 [00 00]  |   NOP
     0x1f33: 00 [00 00]  |   NOP
     0x1f34: 00 [00 00]  |   NOP
     0x1f35: 00 [00 00]  |   NOP
     0x1f36: 00 [00 00]  |   NOP
     0x1f37: 00 [00 14]  |   NOP
     0x1f38: 00 [14 14]  |   NOP
     0x1f39: 14 [14 14]  |   INR D
     0x1f3a: 14 [14 14]  |   INR D
     0x1f3b: 14 [14 14]  |   INR D
     0x1f3c: 14 [14 00]  |   INR D
     0x1f3d: 14 [00 00]  |   INR D
     0x1f3e: 00 [00 00]  |   NOP
     0x1f3f: 00 [00 22]  |   NOP
     0x1f40: 00 [22 14]  |   NOP
     0x1f41: 22 [14 7F]  |   SHLD 0x7F14
     0x1f42: 14 [7F 14]  |   INR D
     0x1f43: 7F [14 22]  |   MOV A, A
     0x1f44: 14 [22 00]  |   INR D
     0x1f45: 22 [00 00]  |   SHLD 0x0000
     0x1f46: 00 [00 00]  |   NOP
     0x1f47: 00 [00 03]  |   NOP
     0x1f48: 00 [03 04]  |   NOP
     0x1f49: 03 [04 78]  |   INX B
     0x1f4a: 04 [78 04]  |   INR B
     0x1f4b: 78 [04 03]  |   MOV A, B
     0x1f4c: 04 [03 00]  |   INR B
     0x1f4d: 03 [00 00]  |   INX B
     0x1f4e: 00 [00 24]  |   NOP
     0x1f4f: 00 [24 1B]  |   NOP
     0x1f50: 24 [1B 26]  |   INR H
     0x1f51: 1B [26 0E]  |   DCX D
     0x1f52: 26 [0E 11]  |   MVI H, 0x0E
     0x1f53: 0E [11 26]  |   MVI C, 0x11
     0x1f54: 11 [26 1C]  |   LXI D, 0x1C26 
     0x1f55: 26 [1C 26]  |   MVI H, 0x1C
     0x1f56: 1C [26 0F]  |   INR E
     0x1f57: 26 [0F 0B]  |   MVI H, 0x0F
     0x1f58: 0F [0B 00]  |   RRC
     0x1f59: 0B [00 18]  |   DCX B
     0x1f5a: 00 [18 04]  |   NOP
     0x1f5b: 18 [04 11]  |   Undefined instruction
     0x1f5c: 04 [11 12]  |   INR B
     0x1f5d: 11 [12 25]  |   LXI D, 0x2512 
     0x1f5e: 12 [25 26]  |   STAX D
     0x1f5f: 25 [26 26]  |   DCR H
     0x1f60: 26 [26 28]  |   MVI H, 0x26
     0x1f61: 26 [28 1B]  |   MVI H, 0x28
     0x1f62: 28 [1B 26]  |   Undefined instruction
     0x1f63: 1B [26 0F]  |   DCX D
     0x1f64: 26 [0F 0B]  |   MVI H, 0x0F
     0x1f65: 0F [0B 00]  |   RRC
     0x1f66: 0B [00 18]  |   DCX B
     0x1f67: 00 [18 04]  |   NOP
     0x1f68: 18 [04 11]  |   Undefined instruction
     0x1f69: 04 [11 26]  |   INR B
     0x1f6a: 11 [26 26]  |   LXI D, 0x2626 
     0x1f6b: 26 [26 1B]  |   MVI H, 0x26
     0x1f6c: 26 [1B 26]  |   MVI H, 0x1B
     0x1f6d: 1B [26 02]  |   DCX D
     0x1f6e: 26 [02 0E]  |   MVI H, 0x02
     0x1f6f: 02 [0E 08]  |   STAX B
     0x1f70: 0E [08 0D]  |   MVI C, 0x08
     0x1f71: 08 [0D 26]  |   Undefined instruction
     0x1f72: 0D [26 01]  |   DCR C
     0x1f73: 26 [01 01]  |   MVI H, 0x01
     0x1f74: 01 [01 00]  |   LXI B, 0x0001 
     0x1f75: 01 [00 00]  |   LXI B, 0x0000 
     0x1f76: 00 [00 01]  |   NOP
     0x1f77: 00 [01 00]  |   NOP
     0x1f78: 01 [00 02]  |   LXI B, 0x0200 
     0x1f79: 00 [02 01]  |   NOP
     0x1f7a: 02 [01 00]  |   STAX B
     0x1f7b: 01 [00 02]  |   LXI B, 0x0200 
     0x1f7c: 00 [02 01]  |   NOP
     0x1f7d: 02 [01 00]  |   STAX B
     0x1f7e: 01 [00 60]  |   LXI B, 0x6000 
     0x1f7f: 00 [60 10]  |   NOP
     0x1f80: 60 [10 0F]  |   MOV H, B
     0x1f81: 10 [0F 10]  |   Undefined instruction
     0x1f82: 0F [10 60]  |   RRC
     0x1f83: 10 [60 30]  |   Undefined instruction
     0x1f84: 60 [30 18]  |   MOV H, B
     0x1f85: 30 [18 1A]  |   Undefined instruction
     0x1f86: 18 [1A 3D]  |   Undefined instruction
     0x1f87: 1A [3D 68]  |   LDAX D
     0x1f88: 3D [68 FC]  |   DCR A
     0x1f89: 68 [FC FC]  |   MOV L, B
     0x1f8a: FC [FC 68]  |   CM 0x68FC
     0x1f8b: FC [68 3D]  |   CM 0x3D68
     0x1f8c: 68 [3D 1A]  |   MOV L, B
     0x1f8d: 3D [1A 00]  |   DCR A
     0x1f8e: 1A [00 08]  |   LDAX D
     0x1f8f: 00 [08 0D]  |   NOP
     0x1f90: 08 [0D 12]  |   Undefined instruction
     0x1f91: 0D [12 04]  |   DCR C
     0x1f92: 12 [04 11]  |   STAX D
     0x1f93: 04 [11 13]  |   INR B
     0x1f94: 11 [13 26]  |   LXI D, 0x2613 
     0x1f95: 13 [26 26]  |   INX D
     0x1f96: 26 [26 02]  |   MVI H, 0x26
     0x1f97: 26 [02 0E]  |   MVI H, 0x02
     0x1f98: 02 [0E 08]  |   STAX B
     0x1f99: 0E [08 0D]  |   MVI C, 0x08
     0x1f9a: 08 [0D 0D]  |   Undefined instruction
     0x1f9b: 0D [0D 2A]  |   DCR C
     0x1f9c: 0D [2A 50]  |   DCR C
     0x1f9d: 2A [50 1F]  |   LHLD 0x1F50
     0x1f9e: 50 [1F 0A]  |   MOV D, B
     0x1f9f: 1F [0A 2A]  |   RAR
     0x1fa0: 0A [2A 62]  |   LDAX B
     0x1fa1: 2A [62 1F]  |   LHLD 0x1F62
     0x1fa2: 62 [1F 07]  |   MOV H, D
     0x1fa3: 1F [07 2A]  |   RAR
     0x1fa4: 07 [2A E1]  |   RLC
     0x1fa5: 2A [E1 1F]  |   LHLD 0x1FE1
     0x1fa6: E1 [1F FF]  |   POP H
     0x1fa7: 1F [FF 02]  |   RAR
     0x1fa8: FF [02 11]  |   RST 7
     0x1fa9: 02 [11 04]  |   STAX B
     0x1faa: 11 [04 03]  |   LXI D, 0x0304 
     0x1fab: 04 [03 08]  |   INR B
     0x1fac: 03 [08 13]  |   INX B
     0x1fad: 08 [13 26]  |   Undefined instruction
     0x1fae: 13 [26 00]  |   INX D
     0x1faf: 26 [00 60]  |   MVI H, 0x00
     0x1fb0: 00 [60 10]  |   NOP
     0x1fb1: 60 [10 0F]  |   MOV H, B
     0x1fb2: 10 [0F 10]  |   Undefined instruction
     0x1fb3: 0F [10 60]  |   RRC
     0x1fb4: 10 [60 38]  |   Undefined instruction
     0x1fb5: 60 [38 19]  |   MOV H, B
     0x1fb6: 38 [19 3A]  |   Undefined instruction
     0x1fb7: 19 [3A 6D]  |   DAD D
     0x1fb8: 3A [6D FA]  |   LDA 0xFA6D
     0x1fb9: 6D [FA FA]  |   MOV L, L
     0x1fba: FA [FA 6D]  |   JM 0x6DFA
     0x1fbb: FA [6D 3A]  |   JM 0x3A6D
     0x1fbc: 6D [3A 19]  |   MOV L, L
     0x1fbd: 3A [19 00]  |   LDA 0x0019
     0x1fbe: 19 [00 00]  |   DAD D
     0x1fbf: 00 [00 20]  |   NOP
     0x1fc0: 00 [20 40]  |   NOP
     0x1fc1: 20 [40 4D]  |   Undefined instruction
     0x1fc2: 40 [4D 50]  |   MOV B, B
     0x1fc3: 4D [50 20]  |   MOV C, L
     0x1fc4: 50 [20 00]  |   MOV D, B
     0x1fc5: 20 [00 00]  |   Undefined instruction
     0x1fc6: 00 [00 00]  |   NOP
     0x1fc7: 00 [00 00]  |   NOP
     0x1fc8: 00 [00 00]  |   NOP
     0x1fc9: 00 [00 FF]  |   NOP
     0x1fca: 00 [FF B8]  |   NOP
     0x1fcb: FF [B8 FF]  |   RST 7
     0x1fcc: B8 [FF 80]  |   CMP B
     0x1fcd: FF [80 1F]  |   RST 7
     0x1fce: 80 [1F 10]  |   ADD B
     0x1fcf: 1F [10 97]  |   RAR
     0x1fd0: 10 [97 00]  |   Undefined instruction
     0x1fd1: 97 [00 80]  |   SUB A
     0x1fd2: 00 [80 1F]  |   NOP
     0x1fd3: 80 [1F 00]  |   ADD B
     0x1fd4: 1F [00 00]  |   RAR
     0x1fd5: 00 [00 01]  |   NOP
     0x1fd6: 00 [01 D0]  |   NOP
     0x1fd7: 01 [D0 22]  |   LXI B, 0x22D0 
     0x1fd8: D0 [22 20]  |   RNC
     0x1fd9: 22 [20 1C]  |   SHLD 0x1C20
     0x1fda: 20 [1C 10]  |   Undefined instruction
     0x1fdb: 1C [10 94]  |   INR E
     0x1fdc: 10 [94 00]  |   Undefined instruction
     0x1fdd: 94 [00 20]  |   SUB H
     0x1fde: 00 [20 1C]  |   NOP
     0x1fdf: 20 [1C 28]  |   Undefined instruction
     0x1fe0: 1C [28 1C]  |   INR E
     0x1fe1: 28 [1C 26]  |   Undefined instruction
     0x1fe2: 1C [26 0F]  |   INR E
     0x1fe3: 26 [0F 0B]  |   MVI H, 0x0F
     0x1fe4: 0F [0B 00]  |   RRC
     0x1fe5: 0B [00 18]  |   DCX B
     0x1fe6: 00 [18 04]  |   NOP
     0x1fe7: 18 [04 11]  |   Undefined instruction
     0x1fe8: 04 [11 12]  |   INR B
     0x1fe9: 11 [12 26]  |   LXI D, 0x2612 
     0x1fea: 12 [26 1C]  |   STAX D
     0x1feb: 26 [1C 26]  |   MVI H, 0x1C
     0x1fec: 1C [26 02]  |   INR E
     0x1fed: 26 [02 0E]  |   MVI H, 0x02
     0x1fee: 02 [0E 08]  |   STAX B
     0x1fef: 0E [08 0D]  |   MVI C, 0x08
     0x1ff0: 08 [0D 12]  |   Undefined instruction
     0x1ff1: 0D [12 0F]  |   DCR C
     0x1ff2: 12 [0F 14]  |   STAX D
     0x1ff3: 0F [14 12]  |   RRC
     0x1ff4: 14 [12 07]  |   INR D
     0x1ff5: 12 [07 26]  |   STAX D
     0x1ff6: 07 [26 00]  |   RLC
     0x1ff7: 26 [00 08]  |   MVI H, 0x00
     0x1ff8: 00 [08 08]  |   NOP
     0x1ff9: 08 [08 08]  |   Undefined instruction
     0x1ffa: 08 [08 08]  |   Undefined instruction
     0x1ffb: 08 [08 08]  |   Undefined instruction
     0x1ffc: 08 [08 00]  |   Undefined instruction
     0x1ffd: 08 [00 00]  |   Undefined instruction
     0x1ffe: 00 [00 00]  |   NOP
     0x1fff: 00 [00 00]  |   NOP
     0x2000: 00 [00 00]  |   NOP
