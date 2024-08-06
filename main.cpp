#include <stdlib.h>
#include <stdio.h>

using Byte = unsigned char;
using Word = unsigned short;

using u32 = unsigned int;

struct Mem {
    static constexpr u32 MAX_MEM = 1024 * 64;
    Byte Data[MAX_MEM];

    void Initialise() {
        for (u32 i = 0; i < MAX_MEM; i++) {
            Data[i] = 0;
        }
    }

    //read 1 byte
    Byte operator[] (u32 Address) const {
        //assert Address is < MAX_MEM
        return Data[Address];
    }
};


struct CPU {
    Word PC; //Program Counter
    Byte SP; //Stack pointer

    Byte A, X, Y; //register

    Byte C: 1; //status flag
    Byte Z: 1; //status flag
    Byte I: 1; //status flag
    Byte D: 1; //status flag
    Byte B: 1; //status flag
    Byte V: 1; //status flag
    Byte N: 1; //status flag

    void Reset(Mem &memory) {
        PC = 0xFFFC; //reset vector
        SP = 0x0100;
        C = Z = I = D = B = V = N = 0;
        A = X = Y = 0;
        memory.Initialise();
    }
    Byte FetchByte(u32& Cycles, Mem &memory) {
        Byte Data =  memory[PC];
        PC++;
        Cycles--;
        return Data;
    }

    void Execute(u32 Cycles, Mem &memory) {
        while (Cycles > 0) {
            Byte Ins = FetchByte(Cycles, memory);
        }
    }
};


int main() {
    Mem mem;
    CPU cpu;
    cpu.Reset(mem);
    cpu.Execute(2, mem); //2 is placeholder for amount of instructions to execute
    return 0;
}
