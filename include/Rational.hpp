// COPYRIGHT (C) 2017 Larry Fritz (llf26) All rights reserved.
//
// rational.hpp: Definition of rational class and its variables.

#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <cstdlib>
#include <iosfwd>
#include <iostream>
#include <stdlib.h>


// Mathematical helper functions.
// NOTE: These are defined in rational.cpp.
int gcd(int, int);
int lcm(int, int);


// Represents a rational number. The rational numbers are the set of
// numbers that can be represented as the quotient of two integers.
class Rational
{
    int numerator;
    int denominator;


  public:
      // Returns the numerator.
      int num() const { return numerator; }

      // Returns the denominator
      int den() const { return denominator; }

      Rational();

      Rational(int n);

      Rational(int n, int d);

      //Reduce fractions by dividing top and bottom by GCD
      void reduce()
        {
        int tmp =  gcd(numerator, denominator);
        numerator /= tmp;
        denominator /= tmp;
        }




// TODO: Implement support for
// 1. Comparing two rational numbers for equality:
//    - r1 == t2
//    - r1 != r2
// 2. Ordering rational numbers
//    - r1 < r2
//    - r1 > r2
//    - r1 <= r2
//    - r1 >= r2
// 3. The standard arithmetic operators
//    - r1 + r2
//    - r1 - r2
//    - r1 * r2
//    - r1 / r2

// These are provided for you.
//
// NOTE: They are defined in rational.cpp.

bool operator==(Rational& obj)
  {
      //Compare both the numerator and denominator of each side

      Rational tmpObj1 = *this;
      Rational tmpObj2 = obj;
      tmpObj1.reduce();
      tmpObj2.reduce();
      if((tmpObj1.numerator == tmpObj2.numerator) && (tmpObj1.denominator == tmpObj2.denominator))
        return true;
      else
        return false;

  }

  bool operator==(int obj)
  {
      //Compare both the numerator and denominator of each side

      Rational tmpObj1 = *this;
      tmpObj1.reduce();
      if(tmpObj1.numerator == obj)
        return true;
      else
        return false;

  }

  bool operator!=(Rational& obj)
  {
      //Compare both the numerator and denominator of each side

      Rational tmpObj1 = *this;
      Rational tmpObj2 = obj;
      tmpObj1.reduce();
      tmpObj2.reduce();
      if((tmpObj1.numerator == tmpObj2.numerator) && (tmpObj1.denominator == tmpObj2.denominator))
        return false;
      else
        return true;

  }

  bool operator!=(int obj)
  {
      //Compare both the numerator and denominator of each side

      Rational tmpObj1 = *this;
      tmpObj1.reduce();
      if(tmpObj1.numerator != obj)
        return true;
      else
        return false;

  }

  bool operator<(Rational& obj)
  {
      //Reduce, then compare both the numerator and denominator of each side

      Rational tmpObj1 = *this;
      Rational tmpObj2 = obj;
      tmpObj1.reduce();
      tmpObj2.reduce();
      Rational commonTemp(tmpObj1.numerator, tmpObj1.denominator);
      tmpObj1.numerator *= tmpObj2.denominator;
      tmpObj1.denominator *= tmpObj2.denominator;
      tmpObj2.numerator *= commonTemp.denominator;
      tmpObj2.denominator *= commonTemp.denominator;

      if(tmpObj1.numerator < tmpObj2.numerator)
        return true;
      else return false;

  }

    bool operator<(int obj)
  {
      //Reduce, then compare both the numerator and denominator of each side

      Rational tmpObj1 = *this;

      tmpObj1.reduce();


      if(tmpObj1.numerator < obj)
        return true;
      else return false;

  }

    bool operator<=(Rational& obj)
  {
      //Reduce, then compare both the numerator and denominator of each side
      Rational tmpObj1 = *this;
      Rational tmpObj2 = obj;
      tmpObj1.reduce();
      tmpObj2.reduce();
      Rational commonTemp(tmpObj1.numerator, tmpObj1.denominator);
      tmpObj1.numerator *= tmpObj2.denominator;
      tmpObj1.denominator *= tmpObj2.denominator;
      tmpObj2.numerator *= commonTemp.denominator;
      tmpObj2.denominator *= commonTemp.denominator;

      if(tmpObj1.numerator <= tmpObj2.numerator)
        return true;
      else return false;

  }

      bool operator<=(int obj)
  {
      //Reduce, then compare both the numerator and denominator of each side

      Rational tmpObj1 = *this;

      tmpObj1.reduce();


      if(tmpObj1.numerator <= obj)
        return true;
      else return false;

  }



    bool operator>(Rational& obj)
  {
      //Reduce, then compare both the numerator and denominator of each side

      Rational tmpObj1 = *this;
      Rational tmpObj2 = obj;
      tmpObj1.reduce();
      tmpObj2.reduce();
      Rational commonTemp(tmpObj1.numerator, tmpObj1.denominator);
      tmpObj1.numerator *= tmpObj2.denominator;
      tmpObj1.denominator *= tmpObj2.denominator;
      tmpObj2.numerator *= commonTemp.denominator;
      tmpObj2.denominator *= commonTemp.denominator;

      if(tmpObj1.numerator > tmpObj2.numerator)
        return true;
      else return false;

  }

      bool operator>(int obj)
  {
      //Reduce, then compare both the numerator and denominator of each side

      Rational tmpObj1 = *this;

      tmpObj1.reduce();


      if(tmpObj1.numerator > obj)
        return true;
      else return false;

  }

      bool operator>=(Rational& obj)
  {
      //Reduce, then compare both the numerator and denominator of each side

      Rational tmpObj1 = *this;
      Rational tmpObj2 = obj;
      tmpObj1.reduce();
      tmpObj2.reduce();
      Rational commonTemp(tmpObj1.numerator, tmpObj1.denominator);
      tmpObj1.numerator *= tmpObj2.denominator;
      tmpObj1.denominator *= tmpObj2.denominator;
      tmpObj2.numerator *= commonTemp.denominator;
      tmpObj2.denominator *= commonTemp.denominator;

      if(tmpObj1.numerator >= tmpObj2.numerator)
        return true;
      else return false;

  }

      bool operator>=(int obj)
  {
      //Reduce, then compare both the numerator and denominator of each side

      Rational tmpObj1 = *this;

      tmpObj1.reduce();


      if(tmpObj1.numerator >= obj)
        return true;
      else return false;

  }

    Rational operator+(const Rational& obj)
  {

      Rational tmpObj1 = *this;
      Rational tmpObj2 = obj;
      Rational commonTemp(tmpObj1.numerator, tmpObj1.denominator);

      //Get common denominator, then add
      tmpObj1.numerator *= tmpObj2.denominator;
      tmpObj1.denominator *= tmpObj2.denominator;
      tmpObj2.numerator *= commonTemp.denominator;
      tmpObj2.denominator *= commonTemp.denominator;

      int resultNum = tmpObj1.numerator + tmpObj2.numerator;
      int resultDen = tmpObj1.denominator;

      Rational result(resultNum, resultDen);

      result.reduce();
      return result;
  }

      Rational operator+(int obj)
  {

      Rational tmpObj1 = *this;
      Rational tmpObj2 (obj);
      Rational commonTemp(tmpObj1.numerator, tmpObj1.denominator);

      //Get common denominator, then add
      tmpObj1.numerator *= tmpObj2.denominator;
      tmpObj1.denominator *= tmpObj2.denominator;
      tmpObj2.numerator *= commonTemp.denominator;
      tmpObj2.denominator *= commonTemp.denominator;

      int resultNum = tmpObj1.numerator + tmpObj2.numerator;
      int resultDen = tmpObj1.denominator;

      Rational result(resultNum, resultDen);

      result.reduce();
      return result;
  }

      Rational operator-(const Rational& obj)
  {
     //Get common denominator, then subtract
      Rational tmpObj1 = *this;
      Rational tmpObj2 = obj;
      Rational commonTemp(tmpObj1.numerator, tmpObj1.denominator);
      tmpObj1.numerator *= tmpObj2.denominator;
      tmpObj1.denominator *= tmpObj2.denominator;
      tmpObj2.numerator *= commonTemp.denominator;
      tmpObj2.denominator *= commonTemp.denominator;

      int resultNum = tmpObj1.numerator - tmpObj2.numerator;
      int resultDen = tmpObj1.denominator;

      Rational result(resultNum, resultDen);

      result.reduce();
      return result;
  }

        Rational operator-(int obj)
  {
     //Get common denominator, then subtract
      Rational tmpObj1 = *this;
      Rational tmpObj2(obj);
      Rational commonTemp(tmpObj1.numerator, tmpObj1.denominator);
      tmpObj1.numerator *= tmpObj2.denominator;
      tmpObj1.denominator *= tmpObj2.denominator;
      tmpObj2.numerator *= commonTemp.denominator;
      tmpObj2.denominator *= commonTemp.denominator;

      int resultNum = tmpObj1.numerator - tmpObj2.numerator;
      int resultDen = tmpObj1.denominator;

      Rational result(resultNum, resultDen);

      result.reduce();
      return result;
  }

  Rational operator*(const Rational&obj)
  {
      //Multiply both numerator and denominator of each fraction

      Rational tmpObj = *this;
      int tempNum = tmpObj.numerator*obj.numerator;
      int tempDem = tmpObj.denominator*obj.denominator;
      Rational result(tempNum, tempDem);
      result.reduce();
      return result;
  }

    Rational operator*(int obj)
  {
      //Multiply numerator by given integer

      Rational tmpObj = *this;
      int tempNum = tmpObj.numerator*obj;
      Rational result(tempNum, tmpObj.denominator);
      result.reduce();
      return result;
  }

    Rational operator/(const Rational&obj)
  {
      //Multiply by reciprocal of right fraction

      Rational tmpObj = *this;
      int tempNum = tmpObj.numerator*obj.denominator;
      int tempDem = tmpObj.denominator*obj.numerator;
      Rational result(tempNum, tempDem);
      result.reduce();
      return result;
  }

      Rational operator/(int obj)
  {
      //Multiply left denominator by given integer

      Rational tmpObj = *this;
      int tempNum = tmpObj.numerator;
      int tempDem = tmpObj.denominator*obj;
      Rational result(tempNum, tempDem);
      result.reduce();
      return result;
  }

};


std::ostream& operator<<(std::ostream&, Rational);
std::istream& operator>>(std::istream&, Rational&);

#endif
