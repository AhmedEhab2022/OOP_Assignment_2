// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name: .......cpp
// Last Modification Date:	1/11/2023

// Author1 : Ahmed Ehab Shehata Ali
// ID : 20220012
// Section: S1
// email : am8122004@gmail.com

// Author2 : Ahmed Mohamed Amer Ahmed
// ID : 20220034
// Section: S1
// email : ahmedamer42214953@gmail.com

// Author3 : Mohanad Abdullrahem Abdullrahman
// ID : 20220348
// Section: S2
// email : mhndahmd031@gmail.com

// TA: Maya Ahmed Kamal

// Purpose: ........

#include "machine.cpp"
#include <iostream>
using namespace std;

/*
Designing a UML class diagram for a simulator of the "Vole machine" and 
its language is a complex task, and the diagram's exact structure can vary 
based on design decisions and specific requirements. However, I can provide 
a simplified representation of some key classes and their relationships to 
help you get started. Please keep in mind that a full implementation may 
require additional classes, methods, and details.

Here's a simplified UML class diagram for a "Vole machine" simulator:

1. **Machine**
  - Attributes: registers (an array of registers), PC (Program Counter), IR (Instruction Register), memory (Memory), screen (Screen)
  - Methods: loadProgram(file: File), executeProgram(), displayStatus()
2. **Memory**
  - Attributes: memoryData (an array to store memory contents)
  - Methods: readMemory(address: int), writeMemory(address: int, data: int)
3. **Register**
  - Attributes: value (to store the register's value)
4. **Instruction**
  - Attributes: opcode (e.g., load, add, etc.), operands (e.g., source register, destination register, memory location)
  - Methods: validate()
5. **Screen**
  - Attributes: screenBuffer (to store screen content)
  - Methods: updateScreen()
6. **ProgramStep**
  - Attributes: instruction (Instruction), valid (boolean to indicate whether the step is valid)
  
In this simplified diagram, we have a "Machine" class that represents 
the Vole machine itself. It contains attributes for registers, the 
program counter (PC), the instruction register (IR), memory, and the 
screen. The "Machine" class also has methods for loading a program, 
executing it, and displaying the status.

The "Memory" class is responsible for managing memory and provides 
methods for reading and writing memory locations.

The "Register" class represents a register and stores its value.

The "Instruction" class represents Vole machine instructions, with 
attributes for the opcode and operands. It includes a "validate" method 
to check if the instruction is valid.

The "Screen" class manages the screen's content and has a method to update it.

The "ProgramStep" class represents a single step in the execution of 
the program and includes an instruction and a boolean to indicate whether 
the step is valid.

Please note that this is a simplified representation, and a real 
implementation may involve more classes and detailed methods to handle 
the Vole machine's instruction set and program execution. The 
relationships between classes should also be further defined based 
on your specific design and requirements.
*/