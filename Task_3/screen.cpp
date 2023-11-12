#include "machine.h"

Screen::Screen()
{
  screenBuffer = "--";
}

Screen::~Screen()
{
}

string Screen::getScreen()
{
  return screenBuffer;
}

void Screen::updateScreen(string data)
{
  this->screenBuffer = data;
}