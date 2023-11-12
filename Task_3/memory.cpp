#include "machine.h"

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

array<string, 256> Memory::getMemory()
{
  return memo;
}

void Memory::writeToMemory(string data, string address)
{
  int decAddress = Machine::convertHexToDec(address);
  this->memo[decAddress] = data;
}

string Memory::getInstruction(string address)
{
    // convert the string of address to integer to represent the index
    int decAddress = Machine::convertHexToDec(address);
    // return the address and the value of the address
    return this->memo[decAddress] + this->memo[decAddress+1];
}

string Memory::readFromMemory(string address)
{
    // convert the string of address to integer to represent the index
    int decAddress = Machine::convertHexToDec(address);
    // return the value of the address
    return this->memo[decAddress];
}
