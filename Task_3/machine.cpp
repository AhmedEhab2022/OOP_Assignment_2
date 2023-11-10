#include "machine.h"
#include <iostream>
#include <array>
using namespace std;

Machine::Machine()
{
  pc = 0;
}
Machine::~Machine()
{
}

InstructionsRegester::InstructionsRegester()
{
}

InstructionsRegester::~InstructionsRegester()
{
}

Regeisters::Regeisters()
{
  // reg[16] = {"00"};
  for (int i = 0; i < 16; i++)
  {
    reg[i] = "00";
  }
}

Regeisters::~Regeisters()
{
}

Memory::Memory()
{
  // memo = {"00"};
  for (int i = 0; i < 256; i++)
  {
    memo[i] = "00";
  }
}

Memory::~Memory()
{
}

Instructions::Instructions()
{
}

Instructions::~Instructions()
{
}

Screen::Screen()
{
  screenBuffer = "--";
}

Screen::~Screen()
{
}

array<string, 256> Memory::getMemory()
{
  return memo;
}

array<string, 16> Regeisters::getRegeister()
{
  return reg;
}

string Screen::getScreen()
{
  return screenBuffer;
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
  cout << pc;
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

  index = convertHexToDec(address);
  while (getline(instructionsFile, line))
  {
    // Store instructions to the memory line by line
    this->memory.writeToMemory(line.substr(2, 2), convertDecToHex(index));
    this->memory.writeToMemory(line.substr(7, 2), convertDecToHex(index + 1));
    index += 2;
  }
  instructionsFile.close();
}

string Regeisters::getValue(string address)
{
  int index;

  index = Machine::convertHexToDec(address);
  return this->reg[index];
}

void Regeisters::storeValue(string data, string address)
{
  int index;

  index = Machine::convertHexToDec(address);
  this->reg[index] = data;
}