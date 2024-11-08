#ifndef MACHINE_H
#define MACHINE_H

#include <iostream>
#include <algorithm>
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

  string getValue(string address);
  void storeValue(string data, string address);
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

  string readFromMemory(string address);           // return one byte
  string getInstruction(string address);           // return two bytes
  void writeToMemory(string data, string address); // store one byte
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
  Screen screen;
  string pc;
  string programFileName;

public:
  Machine();
  ~Machine();

  static int convertHexToDec(string hexNum);
  static string convertDecToHex(int decNum);

  float convertHexToFloat(string hexNum);
  string convertFloatToHex(float num);
  string HexToBin(string Hex);
  string addingBin(string bin1 , string bin2);
  string BinToHex(string Bin);

  void loadProgram(string fileName, string address);
  void executeProgram();
  void displayStatus(); // to display the memory, regester, and screen to the user
  void displayMenu();   // to display menu options to the user
  void increasePC(); // increase PC value

  void executeInstruction(string instruction); // depending on the instruction it will call the right method

  // instruction 1
  void loadFromMemory(string instruction);

  // instruction 2
  void loadToRegester(string instruction);

  // instruction 3
  void store(string instruction);

  // instruction 4
  void moveInstruction(string instruction);

  // instruction 5
  void addTwoComp(string instruction);

  // instruction 6
  void addFloat(string instruction);

  // instruction 7
  void jump(string instruction);

};

#endif
