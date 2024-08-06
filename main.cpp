#include <stdlib.h>

struct CPU {
    using Byte = unsigned char;
    using Word = unsigned short;

    Word PC; //Program Counter
    Byte SP; //Stack pointer

    Byte A, X, Y; //register

    Byte C : 1; //status flag
    Byte Z : 1; //status flag
    Byte I : 1; //status flag
    Byte D : 1; //status flag
    Byte B : 1; //status flag
    Byte V : 1; //status flag
    Byte N : 1; //status flag

    void Reset() {
        PC = 0xFFFC; //reset vector
        SP = 0x0100;
        C = Z = I = D = B = V = N = 0;
        A = X = Y = 0;
    }
};


int main() {
    CPU cpu;
    cpu.Reset();
    return 0;
}
