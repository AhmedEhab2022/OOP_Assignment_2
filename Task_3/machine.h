#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include <string>
#include <array>
using namespace std;

class Regeisters
{
private:
  // static string reg[16];
  array<string, 16> reg;

public:
  Regeisters();
  ~Regeisters();

  array<string, 16> getRegeister();

  string getValue(int address);
  void storeValue(string data, int address);
};

class Memory
{
private:
  // static string memo[256];
  array<string, 256> memo;

public:
  Memory();
  ~Memory();

  array<string, 256> getMemory();

  string readFromMemory(int address);           // return one byte
  string getInstruction(int address);           // return two bytes
  void writeToMemory(string data, int address); // store one byte
};

class Instructions
{
private:
  /* data */
public:
  Instructions();
  ~Instructions();

  // instruction 1
  void loadFromMemory();

  // instruction 2
  void loadToRegester();

  // instruction 3
  void store();

  // instruction 4
  void move();

  // instruction 5
  void addTwoComp();

  // instruction 6
  void addFloat();

  // instruction 7
  void jump();

  // instruction 8
  void halt();
};

class InstructionsRegester : public Instructions
{
private:
  /* data */
public:
  InstructionsRegester();
  ~InstructionsRegester();

  bool validate(string instruction);          // to validate the instruction
  void excuteInstruction(string instruction); // depending on the istruction it will call the right method
};

class Screen
{
private:
  string screenBuffer;

public:
  Screen();
  ~Screen();

  void updateScreen(string data);
  string getScreen();
};

class Machine
{
private:
  Memory memory;
  Regeisters reg;
  InstructionsRegester IR;
  Screen screen;
  int pc;

public:
  Machine();
  ~Machine();

  int convertHexToDec(string hexNum);
  string convertDecToHex(int decNum);

  void loadProgram(string fileName, int address);
  void excuteProgram();
  void displayStatus(); // to display the memory, regester, and screen to the user
  void displayMenu();   // to display menu options to the user
  string fetch(int address /*PC value*/);
  void increasePC(); // increase PC value
};

#endif