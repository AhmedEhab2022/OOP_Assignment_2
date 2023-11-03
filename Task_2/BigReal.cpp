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

BigReal::BigReal(double realNumber)
{
    // Convert the double real number to string to create a new BigReal number
   this->setNum(to_string(realNumber));
}

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
      cout << "Error: not a valid real number \"" << realNumber << "\"\n";
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

void BigReal::setSign(char sign)
{
  if (sign == '+' || sign == '-')
    this->sign = sign;
  else
    cout << "Invalid sign\n";
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

BigReal BigReal::operator+(BigReal &other)
{
  string result, integer1, integer2, frac1, frac2;
  int i, carry = 0;
  char temp;

  integer1 = this->integer;
  integer2 = other.integer;
  frac1 = this->fraction;
  frac2 = other.fraction;
  // Check the sign of two numbers
  if (this->sign == other.getSign())
  {
    // Store the remaining digits of the fraction that
    // has more number of digits in the result 
    if (frac1.size() > frac2.size())
      result = frac1.substr(frac2.size(), frac1.size());

    else if (frac1.size() < frac2.size())
      result = frac2.substr(frac2.size(), frac2.size());

    // Loop from the right to left and add the two digits with carry 
    for (i = min(frac1.size(), frac2.size()) - 1; i >= 0; i--)
    {
      temp = carry + (frac1[i] + frac2[i] - '0');
      if (temp > '9')
      {
        carry = 1;
        temp -= 10;
      }
      else
        carry = 0;

      result = temp + result;
    }
    result = '.' + result;
    // Pad the integer that has less number of digits to the right by zeros
    while (integer1.size() > integer2.size())
      integer2 = '0' + integer2;

    while (integer1.size() < integer2.size())
      integer1 = '0' + integer1;
    
    // Loop from the right to left and add the two digits with carry 
    for (i = integer1.size() - 1; i >= 0; i--)
    {
      temp = carry + (integer1[i] + integer2[i] - '0');
      if (temp > '9')
      {
        carry = 1;
        temp -= 10;
      }
      else
        carry = 0;

      result = temp + result;
    }
    // make a new big real object to return the result
    BigReal new_BigReal(result);
    new_BigReal.sign = this->sign;
    return new_BigReal;
  }
  // else
  //    call the '-' operator
  //    this->operator-(other);
}

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

ostream &operator<<(ostream &out, BigReal num)
{
  if (num.sign == '-')
    out << num.sign;

  out << num.integer + '.' + num.fraction;
  return out;
}

BigReal::~BigReal()
{

}
