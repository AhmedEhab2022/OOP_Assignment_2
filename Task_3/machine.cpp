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
  // convert from hex string to dec int and store it in pc
  // pc == this->convertHexToDec(tempPC);
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