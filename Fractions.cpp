#include "Fractions.hpp"
#include <bits/stdc++.h>

template <typename T>

T gcd(T a, T b)
{
  return b ? gcd<T>(b, a % b) : a;
}

//===================== DO NOT TOUCH THE STUFF ABOVE ==========

// print() implementation:
// it should print the fraction in the following order in its lowest form
// 1/2
// terminated by a newline, no spaces or anything else

//=========== YOUR CODE HERE ==============

template <typename T>
Fraction<T>::Fraction(T numerator, T denominator)
{
  this->numerator = numerator;
  this->denominator = denominator;
}

template <typename T>
Fraction<T> Fraction<T>::reduce()
{
  T div = gcd<T>(numerator, denominator);
  numerator = numerator / div;
  denominator = denominator / div;
  if (numerator < 0 && denominator < 0)
  {
    numerator = numerator * (-1);
    denominator = denominator * (-1);
  }
  else if (denominator < 0)
  {
    denominator = denominator * (-1);
    numerator = numerator * (-1);
  }
  return *this;
}

template <typename T>
T Fraction<T>::get_numerator()
{
  this->reduce();
  return numerator;
}

template <typename T>
T Fraction<T>::get_denominator()
{
  this->reduce();
  return denominator;
}

template <typename T>
Fraction<T> Fraction<T>::operator+(Fraction &frac)
{
  // this->reduce();
  // frac.reduce();
  T num = frac.denominator * numerator + frac.numerator * denominator;
  T den = denominator * frac.denominator;
  return Fraction(num, den).reduce();
}

template <typename T>
Fraction<T> Fraction<T>::operator-(Fraction &frac)
{
  // this->reduce();
  // frac.reduce();
  T num = frac.denominator * numerator - frac.numerator * denominator;
  T den = denominator * frac.denominator;
  return Fraction(num, den).reduce();
}

template <typename T>
Fraction<T> Fraction<T>::operator*(Fraction &frac)
{
  // this->reduce();
  // frac.reduce();
  T num = frac.numerator * numerator;
  T den = frac.denominator * denominator;
  return Fraction(num, den).reduce();
}

template <typename T>
Fraction<T> Fraction<T>::operator/(Fraction &frac)
{
  // this->reduce();
  // frac.reduce();
  T num = frac.denominator * numerator;
  T den = frac.numerator * denominator;
  return Fraction(num, den).reduce();
}

template <typename T>
bool Fraction<T>::operator==(Fraction &frac)
{
  return ((numerator * frac.denominator) == (frac.numerator * denominator));
}

template <typename T>
bool Fraction<T>::operator!=(Fraction &frac)
{
  return !(*this == frac);
}

template <typename T>
bool Fraction<T>::operator<=(Fraction &frac)
{
  this->reduce();
  frac.reduce();
  T first = numerator * frac.denominator;
  T second = frac.numerator * denominator;
  return first <= second;
}

template <typename T>
bool Fraction<T>::operator<(Fraction &frac)
{
  this->reduce();
  frac.reduce();
  T first = numerator * frac.denominator;
  T second = frac.numerator * denominator;
  return first < second;
}

template <typename T>
bool Fraction<T>::operator>=(Fraction &frac)
{
  this->reduce();
  frac.reduce();
  T first = numerator * frac.denominator;
  T second = frac.numerator * denominator;
  return first >= second;
}

template <typename T>
bool Fraction<T>::operator>(Fraction &frac)
{
  this->reduce();
  frac.reduce();
  T first = numerator * frac.denominator;
  T second = frac.numerator * denominator;
  return first > second;
}

template <typename T>
void Fraction<T>::print()
{
  this->reduce();
  std::cout << numerator << "/" << denominator << std::endl;
}