#ifndef BIGREAL_H
#define BIGREAL_H

#include <iostream>

using namespace std;

class BigReal
{
private:
    bool isValidReal(string realNumber); // True if correct real
    char sign;
    string integer, fraction;

public:
    BigReal (double realNumber = 0.0); // Default constructor
    BigReal(string realNumber);         // Initialize from string
    ~BigReal(); // Destructor

    // setters.
    void setNum(string realNumber);
    void setSign(char sign);
    // Getters.
    string getNum();
    int getSize();
    char getSign();

    BigReal operator+ (BigReal& other);
    BigReal operator- (BigReal& other);

    bool operator<(BigReal anotherReal);
    bool operator>(BigReal anotherReal);
    bool operator==(BigReal anotherReal);

    friend ostream &operator<<(ostream &out, BigReal num);
};

#endif // BIGREAL_H
