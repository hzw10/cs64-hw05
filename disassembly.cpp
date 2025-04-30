#include <iostream>     // for use of cin, cout, endl
#include <string>       // for use of strings
#include <cmath>        // for use of pow(x,y) function
// NO OTHER LIBRARIES ARE ALLOWED!

using namespace std;

// function: disassemble takes in a string representing
//          an assembled MIPS instruction as a string
//          and returns the instruction itself
//
//          Level 1 difficulty: assume the input is:
//          a) legitimate (an actual MIPS instruction)
//          b) is ONLY an I-type and ONLY one of: addi, addiu, andi, ori, slti
//          c) has only registers $t0 thru $t7 or $s0 thru $s7 in the instruction

// string decToBinary(unsigned int dec) {
//     string binary;
//     for (unsigned int i = 0; i < 32; i++) {
//         binary = to_string(dec % 2) + binary;
//         dec = dec/2;
//     }
//     return binary; 
// }

string getOperation(int i) {
    if (i == 8)
        return "addi";
    if (i == 9)
        return "addiu";
    if (i == 12) 
        return "andi";
    if (i == 13)
        return "ori";
    if (i == 10)
        return "slti";
    return "badOpCode";
}

string getRegister(int i){
    if ((8 <= i) && (i <= 15))
        return "$t" + to_string(i-8);
    if ((16 <= i) && (i <= 23))
        return "$s" + to_string(i - 16);
    return "badRegister";
}

string disassemble(string hex) {
    // You want to retrieve all the separate fields of an I-type instruction
    //      to help you figure out what the assembly instruction is.
    //
    // HINT: Use bitwise masking and bit-shifting to isolate the different parts of the hex instruction!
    //
    // YOUR CODE GOES HERE!!
    unsigned int dec = stoul(hex, nullptr, 16);
    int immediate = stoi(hex.substr(4), nullptr, 16) << 16 >> 16;
    string instruction = getOperation(dec >> 26) + " " + getRegister((dec << 11) >> 27) + " " + getRegister((dec << 6) >> 27) + " " + to_string(immediate);
    return instruction;
}

int main() {
// Don't change any code in main() function!!

    string hex, inst;
    
    cout << "Enter your assembled instruction as a hex number: 0x";
    cin >> hex;
    
    inst = disassemble( hex );
    cout << "Your instruction is:\n" << inst << endl;

    return 0;
}
