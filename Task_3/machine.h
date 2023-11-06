#ifndef BIGREAL_H
#define BIGREAL_H

#include <iostream>
#include <string>
using namespace std;

class Machine
{
private:
  static string memo[256];
  static string reg[16];
  static int cp;

public:
  Machine();
  ~Machine();

  int convertHexToDec(string hexNum) {}
  string convertDecToHex(int decNum) {}
};

class InstructionsRegester : public Machine
{
private:
  /* data */
public:
  InstructionsRegester();
  ~InstructionsRegester();
};

class Regeister : public Machine
{
private:
public:
  Regeister();
  ~Regeister();
};

class Memory : public Machine
{
private:
public:
  Memory();
  ~Memory();
};

class Instructions : public Machine
{
private:
  /* data */
public:
  Instructions();
  ~Instructions();
};

#endif