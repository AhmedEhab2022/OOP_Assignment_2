#ifndef BIGREAL_H
#define BIGREAL_H

#include <iostream>
#include <string>
using namespace std;

class Machine
{
private:
  Memory memory;
  Regeisters reg;
  InstructionsRegester IR;
  Screen screen;
  static int pc;

public:
  Machine();
  ~Machine();

  int convertHexToDec(string hexNum) {}
  string convertDecToHex(int decNum) {}

  void loadProgram(string fileName, int address) {}
  void excuteProgram() {}
  void displayStatus() {} // to display the memory, regester, and screen to the user
  void displayMenu() {}   // to display menu options to the user
  string fetch(int address /*PC value*/) {}
};

class Regeisters
{
private:
  static string reg[16];

public:
  Regeisters();
  ~Regeisters();

  string getValue(int address) {}
  void storeValue(string data, int address) {}
};

class Memory
{
private:
  static string memo[256];

public:
  Memory();
  ~Memory();

  string readFromMemory(int address) {}           // return one byte
  string getInstruction(int address) {}           // return two bytes
  void writeToMemory(string data, int address) {} // store one byte
};

class Instructions
{
private:
  /* data */
public:
  Instructions();
  ~Instructions();

  // gonna have methods of all instruction
  // and the instructionsRegester will inherit from it
};

class InstructionsRegester : public Instructions
{
private:
  /* data */
public:
  InstructionsRegester();
  ~InstructionsRegester();

  bool validate(string instruction) {}          // to validate the instruction
  void excuteInstruction(string instruction) {} // depending on the istruction it will call the right method
};

class Screen
{
private:
  string screenBuffer;

public:
  Screen();
  ~Screen();

  void updateScreen(string data) {}
  string getScreen() {}
};

#endif