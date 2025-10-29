// #pragma once
class Rational
{
private: 
	int numerator;
	int denominator;
	void Normalize();
public:
	Rational(int num = 0, int den = 1);
	Rational( const Rational &other);
	void setNumerator(int num);
	void setDenominator(int den);

	int getNumerator();
	int getDenominator();

	void print();

	bool equal(const Rational two);

	void makeEquals(Rational &two);

	void reduce();
	
	Rational add(const Rational two);

	Rational addOne();
};
