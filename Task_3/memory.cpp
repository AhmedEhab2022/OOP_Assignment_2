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