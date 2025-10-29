#include "Rational.h"
#include <iostream>
#include <cmath>

Rational::Rational(int num, int den)
{
    
	numerator = num;
	denominator = den;
	if (denominator == 0)
	    denominator = 1;
// 	Normalize();

	if (denominator < 0)
	{
			denominator *= -1;
			numerator *= -1;
	}
	std::cout<< "print: in constructor\n";
}
Rational::Rational(const Rational &other)
{
	numerator = other.numerator;
	denominator = other.denominator;
	std::cout<< "print: in copy constructor\n" ;
}
void Rational::setNumerator(int num)
{
	numerator = num;
}

void Rational::setDenominator(int den)
{
	if (den == 0)
	{
		den = 1;
	}
	denominator = den;
	Normalize();
}
void Rational::Normalize()
{
	if (denominator < 0)
	{
			denominator *= -1;
			numerator *= -1;
	}
	
}
int Rational::getNumerator()
{
	return numerator;
}

int Rational::getDenominator()
{
	
	return denominator;
}

void Rational::print()
{
	std::cout << numerator << "/" << denominator << std::endl;
}


bool Rational::equal(const Rational two)
{
	if (numerator == two.numerator && denominator == two.denominator )
	{
		return true;
	}
	return false;
}

void Rational::makeEquals(Rational &two)
{
	two.setNumerator(numerator);
	two.setDenominator(denominator);
}

void Rational::reduce()
{
	int i = 2;
	while ( i <= abs(numerator))
	{
		if ( numerator % i == 0 && denominator % i == 0)
		{
			numerator /= i;
			denominator /= i;
		}
		else i++;
	}
	if(numerator == 0)
	{
	    denominator = 1;
	}
}

Rational Rational::add(const Rational two)
{
	int resNum = numerator * two.denominator + two.numerator * denominator;
	int resDem = denominator * two.denominator;
	Rational result = Rational(resNum, resDem);
	result.reduce();
    return result;
}


Rational Rational::addOne()
{
	Rational res = Rational(numerator + denominator, denominator);
	
	return res ;
}
