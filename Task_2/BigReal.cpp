#include "BigReal.h"
#include <regex>
#include <ctype.h>

bool BigReal::isValidReal(string realNumber)
{
  // Here b is an object of regex (regular expression)
  regex reg1("([0-9]*.[0-9]+)"); //
  regex reg2("([0-9]+.[0-9]*)"); //

  // regex_match function matches realNumber against regex reg
  if (regex_match(realNumber, reg1) | regex_match(realNumber, reg2))
  {
    return 1;
  }

  return 0;
}

// BigReal::BigReal(double realNumber = 0.0)
// {

// }

BigReal::BigReal(string realNumber)
{
  BigReal::setNum(realNumber);
}

// BigReal::BigReal(const BigReal &other)
// {
// }

// BigReal &BigReal::operator=(BigReal &other)
// {
// }

void BigReal::setNum(string realNumber)
{
  this->sign = '+';
  if (realNumber[0] == '+' || realNumber[0] == '-')
  {
    if (BigReal::isValidReal(realNumber.substr(1)))
    {
      this->sign = realNumber[0];
      int i = 1;
      for (; isdigit(realNumber[i]); i++)
      {
        this->integer += realNumber[i];
      }
      i++;
      for (; i < realNumber.size(); i++)
      {
        this->fraction += realNumber[i];
      }
    }
    else
    {
      cout << "Error: not a valid real number.\n";
      this->integer = this->fraction = "0";
    }
  }
  else
  {
    if (BigReal::isValidReal(realNumber))
    {
      int i = 0;
      for (; isdigit(realNumber[i]); i++)
      {
        this->integer += realNumber[i];
      }
      i++;
      for (; i < realNumber.size(); i++)
      {
        this->fraction += realNumber[i];
      }
    }
    else
    {
      cout << "Error: not a valid real number \"" << realNumber << "\"\n";
      this->integer = this->fraction = "0";
    }
  }
}

string BigReal::getNum()
{
  return sign + integer + "." + fraction;
}

int BigReal::getSize()
{
  return integer.size() + fraction.size() + 1;
}

char BigReal::getSign()
{
  return sign;
}

// BigReal operator+(BigReal &other)
// {
// }

// BigReal operator-(BigReal &other)
// {
// }

bool BigReal::operator<(BigReal anotherReal)
{
  // check for the sign
  if (this->sign == '-' && anotherReal.sign == '+')
  {
    return true;
  }
  else if (this->sign == '+' && anotherReal.sign == '-')
  {
    return false;
  }
  // check for the integer part
  if (this->integer.size() < anotherReal.integer.size())
  {
    return true;
  }
  else if (this->integer.size() > anotherReal.integer.size())
  {
    return false;
  }
  else
  {
    for (int i = 0; i < this->integer.size(); i++)
    {
      if (this->integer[i] < anotherReal.integer[i])
      {
        return true;
      }
      else if (this->integer[i] > anotherReal.integer[i])
      {
        return false;
      }
    }
  }
  // check for the fraction part
  for (int i = 0; i < min(this->fraction.size(), anotherReal.fraction.size()); i++)
  {
    if (this->fraction[i] < anotherReal.fraction[i])
    {
      return true;
    }
    else if (this->fraction[i] > anotherReal.fraction[i])
    {
      return false;
    }
  }
  if (this->fraction.size() < anotherReal.fraction.size())
  {
    return true;
  }

  return false;
}

bool BigReal::operator>(BigReal anotherReal)
{
  // check for the sign
  if (this->sign == '-' && anotherReal.sign == '+')
  {
    return false;
  }
  else if (this->sign == '+' && anotherReal.sign == '-')
  {
    return true;
  }
  // check for the integer part
  if (this->integer.size() > anotherReal.integer.size())
  {
    return true;
  }
  else if (this->integer.size() < anotherReal.integer.size())
  {
    return false;
  }
  else
  {
    for (int i = 0; i < this->integer.size(); i++)
    {
      if (this->integer[i] > anotherReal.integer[i])
      {
        return true;
      }
      else if (this->integer[i] < anotherReal.integer[i])
      {
        return false;
      }
    }
  }
  // check for the fraction part
  for (int i = 0; i < min(this->fraction.size(), anotherReal.fraction.size()); i++)
  {
    if (this->fraction[i] > anotherReal.fraction[i])
    {
      return true;
    }
    else if (this->fraction[i] < anotherReal.fraction[i])
    {
      return false;
    }
  }
  if (this->fraction.size() > anotherReal.fraction.size())
  {
    return true;
  }

  return false;
}

bool BigReal::operator==(BigReal anotherReal)
{
  // check for the sign
  if (this->sign != anotherReal.sign)
  {
    return false;
  }
  // check for the integer part
  if (this->integer != anotherReal.integer)
  {
    return false;
  }
  // check for the fraction part
  if (this->fraction != anotherReal.fraction)
  {
    return false;
  }
  return true;
}

// ostream &operator<<(ostream &out, BigReal num)
// {
// }