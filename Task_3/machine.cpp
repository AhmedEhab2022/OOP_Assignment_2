#include "machine.h"
#include <iostream>
#include <array>
#include <fstream>
#include <cmath>
using namespace std;

Machine::Machine()
{
  pc = "00";
}
Machine::~Machine()
{
}

void Machine::displayStatus()
{
  array<string, 256> tmp = this->memory.getMemory();
  cout << "Memory\n";
  for (int i = 0; i < 256; i++)
  {
    cout << hex << i << " : " << tmp[i] << '\n';
  }

  array<string, 16> tmp2 = this->reg.getRegeister();
  cout << "\nRegeisters\n";
  for (int i = 0; i < 16; i++)
  {
    cout << i << " : " << tmp2[i] << '\n';
  }

  cout << "\nScreen\n";
  cout << this->screen.getScreen();

  cout << "\n\nProgram Counter\n";
  cout << pc << "\n\n";
}

void Machine::displayMenu()
{
  // 1- enter file name and address to store the program
  // 2- store something in memory
  // 3- exit the simulator
  char cond;
  string tempPC;

  cout << "Welcome to the machine language simulator.\n";
  cout << "You can always close the simulator by clicking (ctrl+c)\n";
  cout << "Please enter the file name that contains the program:\n";
  cin >> programFileName;
  cout << "Please enter the address memory to store the program:\n";
  cin >> tempPC;
  // this->pc = tempPC;
  cout << "Thank you!\n";

  cout << "If you want to store something in the memory enter (s)\n";
  cout << "If you want to initiate the simulator enter (c)\n";
  cin >> cond;

  if (cond == 's')
  {
    string data;

    cout << "To store something in the memory enter the address followed by the data\n";
    cout << "for example: 5A01 (the address is 5A and the value is 01)\n";
    cout << "to exit the storing mood and start the simulator enter (e)\n";
    while (true)
    {
      cin >> data;
      if (data == "e")
      {
        return;
      }
      // store the data in memory
      // this->memory.writeToMemory(data.substr(2), data.substr(0, 2));
      cout << "Data saved successfully!\n";
      cout << "to exit the storing mood and initiate the simulator enter (e)\n";
      cout << "to store something else please enter it in the same format:\n";
    }
  }
  return;
}

int Machine::convertHexToDec(string hexNum)
{
  int decNum;

  decNum = stoi(hexNum, 0, 16);
  return decNum;
}

void Machine::loadProgram(string fileName, string address)
{
  ifstream instructionsFile(fileName);
  string line;
  int index;

  this->pc = address;
  index = convertHexToDec(address);
  while (getline(instructionsFile, line))
  {
    // Store instructions to the memory line by line
    // this->memory.writeToMemory(line.substr(2, 2), convertDecToHex(index));
    // this->memory.writeToMemory(line.substr(7, 2), convertDecToHex(index + 1));
    index += 2;
  }
  instructionsFile.close();
}

void Machine::excuteInstruction(string instruction)
{
  // this->validate(instruction); optional
  switch (instruction[0])
  {
  case '1':
    this->loadFromMemory(instruction);
    break;
  case '2':
    this->loadToRegester(instruction);
    break;
  case '3':
    this->store(instruction);
    break;
  case '4':
    this->move(instruction);
    break;
  case '5':
    this->addTwoComp(instruction);
    break;
  case '6':
    this->addFloat(instruction);
    break;
  case 'B':
    this->jump(instruction);
    break;
  case 'C':
    this->halt(instruction);
    break;
  }
}

// instruction 1
void Machine::loadFromMemory(string instruction)
{
  // Example: 14A3 would cause the contents of
  // the memory cell located at address A3 to be placed in register 4.

  string dataFromMem;

  // Retrieve the data from the memory
  dataFromMem = this->memory.readFromMemory(instruction.substr(2, 2));
  // Store the data in the regeister
  this->reg.storeValue(dataFromMem, instruction.substr(1, 1));
}

// instruction 2
void Machine::loadToRegester(string instruction) {}

// instruction 3
void Machine::store(string instruction)
{
  // Example: 35B1 would cause the contents of
  // register 5 to be placed in the memory cell
  // whose address is B1

  // Retrieve the data from the regeister
  string dataFromReg = this->reg.getValue(instruction.substr(1, 1));
  // Store the data in the memory cell
  this->memory.writeToMemory(dataFromReg, instruction.substr(2, 2));
}

// instruction 4
void Machine::move(string instruction)
{
  // Example: 40A4 would cause the contents of
  // register A to be copied into register 4.

  string dataFromReg;

  // Retrieve the data from the regeister
  dataFromReg = this->reg.getValue(instruction.substr(2, 1));
  // Store the data in another cell in regeister
  this->reg.storeValue(dataFromReg, instruction.substr(3, 1));
}

// instruction 5
void Machine::addTwoComp(string instruction) {}

// instruction 6
void Machine::addFloat(string instruction)
{
  // Example: 634E would cause the values in
  // registers 4 and E to be added as floating-point
  // values and the result to be placed in register 3

  string firstNum = this->reg.getValue(instruction.substr(2, 1));
  string secondNum = this->reg.getValue(instruction.substr(3, 1));

  float floatFirstNum = this->convertHexToFloat(firstNum);
  float floatSecondNum = this->convertHexToFloat(secondNum);

  float result = floatFirstNum + floatSecondNum;

  string hexResult = this->convertFloatToHex(result);

  this->reg.storeValue(hexResult, instruction.substr(1, 1));
}

// instruction 7
void Machine::jump(string instruction)
{
  // Example: B43C would first compare the contents of register 4 with the
  // contents of register 0. If the two were equal, the pattern 3C would be placed
  // in the program counter so that the next instruction executed would be the one
  // located at that memory address. Otherwise, nothing would be done and program
  // execution would continue in its normal sequence.

  int decAddress;
  string hexAddress;

  // Check if the given regeister is equal to 0 regeister or not
  if (this->reg.getValue(instruction.substr(1, 1)) == this->reg.getValue("0"))
  {
    // Get the decimal address from the given hex address
    decAddress = this->convertHexToDec(instruction.substr(2, 2));
    decAddress -= 2;
    // Get the hex address that before 2 bytes from the given address 
    hexAddress = this->convertDecToHex(decAddress);
    // Store the hexAddress in program counter
    this->pc = hexAddress;
  }
}

// instruction 8
void Machine::halt(string instruction) {}

string Machine::convertFloatToHex(float num)
{
  string number = to_string(num);
  string result = "";

  if (number[0] == '-')
  {
    result += '1';
    number.erase(0, 1);
  }
  else
  {
    result += '0';
  }

  int intPart = static_cast<int>(num);

  string binIntNum = "";

  for (int i = 0; intPart != 0; i++)
  {
    if (intPart % 2 == 0)
    {
      binIntNum = "0" + binIntNum;
    }
    else
    {
      binIntNum = "1" + binIntNum;
    }
    intPart /= 2;
  }

  int exponent = binIntNum.size() + 4;

  string exponentPart = "";
  for (int i = 0; exponent != 0; i++)
  {
    if (exponent % 2 == 0)
    {
      exponentPart = "0" + exponentPart;
    }
    else
    {
      exponentPart = "1" + exponentPart;
    }
    exponent /= 2;
  }

  float fraction = abs(num - trunc(num));

  string fractionPart = "";

  for (int i = 0; i < 4; i++)
  {
    fraction *= 2;
    if (static_cast<int>(fraction) == 1)
    {
      fractionPart += "1";
    }
    else
    {
      fractionPart += "0";
    }
    fraction -= 1;
  }

  result += exponentPart + binIntNum + fractionPart;

  if (result.size() > 8)
  {
    result.erase(8);
  }

  int res = stoi(result, 0, 2);

  // result = this->convertDecToHex(res);

  return result;
}

float Machine::convertHexToFloat(string hexNum)
{
  string firstNum = hexNum;

  int decFirstNum = stoi(firstNum, 0, 16);

  string binFirstNum;
  binFirstNum = "";

  for (int i = 0; i < 8; i++)
  {
    if (decFirstNum % 2 == 0)
    {
      binFirstNum = "0" + binFirstNum;
    }
    else
    {
      binFirstNum = "1" + binFirstNum;
    }
    decFirstNum /= 2;
  }

  string floatFirstNum;
  floatFirstNum = "";

  if (binFirstNum[0] == '1')
  {
    floatFirstNum += "-";
  }
  else
  {
    floatFirstNum += "+";
  }

  int pointPos = stoi(binFirstNum.substr(1, 3), 0, 2) - 4;

  int intPart = stoi(binFirstNum.substr(4, pointPos), 0, 2);

  float fractionPart = 0.0;

  for (int i = 1; i < (4 - pointPos) + 1; i++)
  {
    if (binFirstNum[i + 3 + pointPos] == '1')
    {
      fractionPart += 1.0 / (pow(2, i));
    }
  }

  floatFirstNum += to_string(intPart) + to_string(fractionPart).erase(0, 1);

  float finalFirstNum = stof(floatFirstNum);

  return finalFirstNum;
}