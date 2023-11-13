#include "BigReal.h"
#include <regex>
#include <ctype.h>

bool BigReal::isValidReal(string realNumber)
{
  // Here b is an object of regex (regular expression)
  regex reg1("([^ +-][0-9]*.?[0-9]+)"); //
  regex reg2("([^ +-][0-9]+.?[0-9]*)"); //
  regex reg3("(.*[a-zA-Z]+.*)");       //

  // regex_match function matches realNumber against regex reg
  // check if it contains any chars.
  if (regex_match(realNumber, reg3))
  {
    return 0;
  }
  // check if it is valid.
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

//BigReal::BigReal(const BigReal& other)
//{
//    sign = other.sign ;
//    integer = other.integer ;
//    fraction = other.fraction ;
//}

//BigReal &BigReal::operator=(BigReal &other)
//{
//    sign = other.sign;
//    integer = other.integer;
//    fraction = other.fraction;
//    return other;
//}

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
  int i ;
  BigReal result , second ;
  // two BigReal to save values
  result.sign = this ->sign;
  result.integer = this->integer;
  result.fraction = this->fraction;
  second.sign = other.sign ;
  second.integer = other.integer;
  second.fraction = other.fraction;
  // Check the sign of two numbers
  if (this->sign == other.sign)
  {
    // add zero or more to make fractions the same size
    if(result.fraction.size() > second.fraction.size())
    {
        while (result.fraction.size() != second.fraction.size())
        second.fraction += '0';
    }

    if(result.fraction.size() < second.fraction.size())
    {
        while (result.fraction.size() != second.fraction.size())
            result.fraction += '0';
    }

    // Loop from the right to left and add the two digits with carry
    for (i = result.fraction.size() - 1; i >= 0; i--)
    {
      result.fraction[i] = (result.fraction[i] + second.fraction[i] - '0');
      if (result.fraction[i] > '9')
      {
        result.fraction[i] -= 10;
        if(i == 0)
            result.integer[result.integer.size()-1] += 1;
        else
            result.fraction[i-1] += 1;
      }
      else
        continue ;
    }

    // Pad the integer that has less number of digits to the right by zeros
    if(result.integer.size() > second.integer.size())
    {
        while (result.integer.size() != second.integer.size())
            second.integer = '0' + second.integer;
    }

    if(result.integer.size() < second.integer.size())
    {
        while (result.integer.size() != second.integer.size())
            result.integer = '0' + result.integer;
    }

    // Loop from the right to left and add the two digits with carry
    for (i = result.integer.size() - 1; i >= 0; i--)
    {
      result.integer[i] = (result.integer[i] + second.integer[i] - '0');
      if (result.integer[i] > '9')
      {
        result.integer[i] -= 10;
        if(i == 0)
            result.integer = "1" + result.integer ;
        else
            result.integer[i-1] += 1;
      }
      else
        continue;
    }
    // return result
    return result;
  }
   else if(this->sign != other.sign){
    BigReal s1 , s2;
    if(this->sign == '-' && other.sign == '+'){
        s1 = other;
        s2.sign = '+';
        s2.integer = this->integer;
        s2.fraction = this->fraction;
        return s1-s2;
    }
    else if(this->sign == '+' && other.sign == '-'){
        s1.sign = this->sign;
        s1.integer = this->integer;
        s1.fraction = this->fraction;
        s2 = other;
        s2.sign = '+';
        return s1-s2;
    }
   }
}

BigReal BigReal :: operator- (BigReal& other)
{   // two BigReal to copy the values of variable
     BigReal result("0.0");
     BigReal second("0.0");
     bool bigger=true;
    // make sure that the strings of BigReal is not empty
     if(integer.size()==0){
        integer="0";
     }
      if(fraction.size()==0){
        fraction="0";
     }
     if(sign == '-' || sign == '+'){
     }
     else
        sign = '+';

    if(other.integer.size()==0){
        other.integer="0";
     }
      if(other.fraction.size()==0){
        other.fraction="0";
     }
     if(other.sign == '-' || other.sign == '+'){
     }
     else
        other.sign = '+';

    // check the sign to determine which operation will happen
    if(sign != other.sign){
        BigReal s1 , s2;
        if(sign == '+' && other.sign == '-')
            s2.sign='+';
        else if(sign == '-' && other.sign == '+')
            s2.sign='-';
        // call operator + after change the sign of second variable
        s1.sign=sign;
        s1.integer = integer;
        s1.fraction = fraction;
        s2.integer = other.integer;
        s2.fraction = other.fraction;
        return s1+s2;
    }
    else if(sign == other.sign){
        // if the integer of the first is bigger , the result sign will be first's sign
        if(integer.size() > other.integer.size()){
            result.sign = sign;
        }
        // if the integer of the seond is bigger , the result sign will be opposite of second's sign
        else if(integer.size() < other.integer.size()){
            if(sign == '+' && other.sign == '+')
                result.sign='-';
            else if(sign == '-' && other.sign == '-')
                result.sign='+';
            bigger =false;
        }
        // if the size is equal , loop over the integer
        else if(integer.size() == other.integer.size()){
            for(int i=0 ; i< integer.size(); i++){
                // subtract every index from another to determine which is bigger
                if(((integer[i]-'0') - (other.integer[i]-'0'))>0){
                    result.sign =sign;
                    break;
                }
                else if(((integer[i]-'0') - (other.integer[i]-'0'))<0){
                    if(sign == '+' && other.sign == '+')
                        result.sign='-';
                    else if(sign == '-' && other.sign == '-')
                        result.sign='+';
                    bigger =false;
                    break;
                }
                // if the integer part is the same in the two variable , we will compare the fraction part
                else if(((integer[i]-'0') - (other.integer[i]-'0')) == 0 && i ==integer.size()-1 ){
                    for(int i=0 ; i<min(fraction.size() , other.fraction.size()) ; i++){
                        if(fraction[i]>other.fraction[i]){
                            result.sign = sign;
                            break;
                        }
                        else if(other.fraction[i]>fraction[i]){
                              if(sign == '+' && other.sign == '+')
                                result.sign='-';
                            else if(sign == '-' && other.sign == '-')
                                result.sign='+';
                            bigger =false;
                            break;
                        }
                        else if(other.fraction[i] == fraction[i] && i==min(fraction.size() , other.fraction.size()) - 1 ){
                            if(fraction.size() > other.fraction.size())
                                result.sign = sign;
                            else if(fraction.size() < other.fraction.size()){
                                if(sign == '+' && other.sign == '+')
                                    result.sign='-';
                                else if(sign == '-' && other.sign == '-')
                                    result.sign='+';
                                bigger =false;
                            }
                        }
                    }
                }
            }
        }
    // make BigReal result the bigger value and the second is the another value
     if(bigger == true){
        result.integer=integer;
        result.fraction=fraction;

        second.fraction=other.fraction;
        second.integer=other.integer;
     }
     else if(bigger == false){
        result.integer=other.integer;
        result.fraction=other.fraction;

        second.fraction=fraction;
        second.integer=integer;
     }

        // fraction
        // calculate how many zeros to add to the left side of integer part to the lower value
        int zeros = 0;
        if(result.fraction.size()<second.fraction.size()){
        zeros =second.fraction.size()-result.fraction.size();
            for(int i=0 ; i< zeros ; i++){
                result.fraction +='0';
            }
        }
        else if(result.fraction.size()>second.fraction.size()){
            zeros =result.fraction.size()-second.fraction.size();
            for(int i=0 ; i< zeros ; i++){
                second.fraction +='0';
            }
        }
        // loop over the lower value from the right to left and subtract each index from the another variable
            for(int i=second.fraction.size() ; i>=0 ; i--){
                if(result.fraction[i]>= second.fraction[i]){
                    result.fraction[i]=result.fraction[i]-second.fraction[i]+'0';
                }
                // if the bigger variable's index value is less than the lower's index value we add 10
                // and subtract 1 from the next index
                else if(result.fraction[i]< second.fraction[i]){
                    result.fraction[i]=result.fraction[i]-second.fraction[i]+'0'+10;
                    if(i == 0){
                        result.integer[result.integer.size()-1] -= 1;
                    }
                    else{
                        // if the next value is '0' we make index = 9 and subtract from the next index
                        for(int j=i-1 ; j>=0 ; j--){
                            result.fraction[j]=result.fraction[j]-1;
                            if(fraction[j]>=48 && fraction[j]<=57){
                                break;
                            }
                            else{
                                // if the fraction part end and we need carry we subtract from integer part
                                result.fraction[j]='9';
                                if(j == 0 ){
                                    integer[integer.size()-1]-=1;
                                }
                            }
                        }
                    }
                }
            }


        // integer
        // we will do the same steps on integer part as fraction part
        if(result.integer.size()<second.integer.size()){
        zeros =second.integer.size()-result.integer.size();
        string temp;
            for(int i=0 ; i< zeros ; i++){
                temp +='0';
            }
            temp += result.integer;
            result.integer = temp;
        }
        else if(result.integer.size()>second.integer.size()){
            zeros =result.integer.size()-second.integer.size();
            string temp;
            for(int i=0 ; i< zeros ; i++){
                    temp +='0';
            }
            temp += second.integer;
            second.integer = temp;

        }
        for(int i=second.integer.size() ; i>=0 ; i--){
            if(result.integer[i]>= second.integer[i]){
                result.integer[i]=result.integer[i]-second.integer[i]+'0';
            }
            else if(result.integer[i]< second.integer[i]){
                result.integer[i]=result.integer[i]-second.integer[i]+'0'+10;
                for(int j=i-1 ; j>=0 ; j--){
                    result.integer[j]=result.integer[j]-1;
                    if(result.integer[j]>=48 && result.integer[j]<=57){
                        break;
                    }
                    else{
                        result.integer[j]='9';
                    }
                }
            }
        }
    // remove useless zeros from the right side of fraction part and left side of integer part
     string tmpint = result.integer;
     string tmpfrc = result.fraction;
     int idx = 0;
    for(int i=0 ; i<tmpint.size() ; i++){
        if(tmpint[i] == '0'){
            idx++;
        }
        else if(tmpint[i] != '0')
            break;
    }
    result.integer = tmpint.substr(idx , result.integer.size());
    idx = 0;
    for(int i=tmpfrc.size()-1 ; i>=0 ; i--){
        if(tmpfrc[i] == '0'){
            idx++;
        }
        else if(tmpfrc[i] != '0')
            break;
    }
    result.fraction = tmpfrc.substr(0 , result.fraction.size() - idx);

    if(result.integer.size()==0){
        result.integer="0";
     }
      if(result.fraction.size()==0){
        result.fraction="0";
     }
    return result ;
    }
}

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
  else if (this->sign == '-' && anotherReal.sign == '-')
  {
    this->setSign('+');
    anotherReal.setSign('+');
    bool ans = (this->operator>(anotherReal));
    this->setSign('-');
    anotherReal.setSign('-');
    return ans;
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
  else if (this->sign == '-' && anotherReal.sign == '-')
  {
    this->setSign('+');
    anotherReal.setSign('+');
    bool ans = (this->operator<(anotherReal));
    this->setSign('-');
    anotherReal.setSign('-');
    return ans;
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
  if(num.integer.size()==0)
    num.integer="0";
  if(num.fraction.size()==0)
    num.fraction = "0";

  if (num.sign == '-')
    out << num.sign;

  out << num.integer + '.' + num.fraction;
  return out;
}

BigReal::~BigReal()
{
}
