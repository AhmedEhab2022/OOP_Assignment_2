#include "machine.h"

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

array<string, 16> Regeisters::getRegeister()
{
  return reg;
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