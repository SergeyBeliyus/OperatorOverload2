#include <iostream>
#include <string>
#include "windows.h"


class Fraction
{
private:
	int numerator_;
	int denominator_;

	int nod(int a, int b) {
		int c;
		while (b != 0) {
			c = abs(a) % abs(b);
			a = b;
			b = c;
		}
		return a;
	}

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	std::string getNumDen() {
		return (std::to_string(numerator_) + "/" + std::to_string(denominator_));
	}

	Fraction operator+ (Fraction fr) {
		int num;
		int den;
		int del;
		num = (numerator_ * fr.denominator_) + (fr.numerator_ * denominator_);
		den = denominator_ * fr.denominator_;
		del = nod(num, den);
		return Fraction((num/del), (den/del));
	}

	Fraction operator- (Fraction fr) {
		int num;
		int den;
		int del;
		num = (numerator_ * fr.denominator_) - (fr.numerator_ * denominator_);
		den = denominator_ * fr.denominator_;
		del = nod(num, den);
		return Fraction((num / del), (den / del));
	}

	Fraction operator* (Fraction fr) {
		int num;
		int den;
		int del;
		num = (numerator_ * fr.numerator_);
		den = denominator_ * fr.denominator_;
		del = nod(num, den);
		return Fraction((num / del), (den / del));
	}

	Fraction operator/ (Fraction fr) {
		int num;
		int den;
		int del;
		num = (numerator_ * fr.denominator_);
		den = denominator_ * fr.numerator_;
		del = nod(num, den);
		return Fraction((num / del), (den / del));
	}

	void operator++ () {
		int num;
		int den;

		num = numerator_ + denominator_;
		den = denominator_;

		numerator_ = num;
		denominator_ = den;
	}

	void operator++ (int) {
		int num;
		int den;

		num = numerator_ + denominator_;
		den = denominator_;

		numerator_ = num;
		denominator_ = den;
	}

	void operator-- () {
		int num;
		int den;

		num = denominator_ - numerator_;
		den = denominator_;

		numerator_ = num;
		denominator_ = den;
	}

	void operator-- (int) {
		int num;
		int den;

		num = numerator_ - denominator_;
		den = denominator_;

		numerator_ = num;
		denominator_ = den;
	}
};

int main()
{
	int num1, num2, den1, den2;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "Введите числитель дроби 1: ";
	std::cin >> num1;

	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> den1;

	std::cout << "Введите числитель дроби 2: ";
	std::cin >> num2;

	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> den2;

	Fraction f1(num1, den1);
	Fraction f2(num2, den2);

	std::cout << f1.getNumDen() << " + " << f2.getNumDen() << " = " << (f1 + f2).getNumDen() << std::endl;
	std::cout << f1.getNumDen() << " - " << f2.getNumDen() << " = " << (f1 - f2).getNumDen() << std::endl;
	std::cout << f1.getNumDen() << " * " << f2.getNumDen() << " = " << (f1 * f2).getNumDen() << std::endl;
	std::cout << f1.getNumDen() << " / " << f2.getNumDen() << " = " << (f1 / f2).getNumDen() << std::endl;
	std::cout << "++" << f1.getNumDen() << " * " << f2.getNumDen() << " = " << (f1 * f2).getNumDen() << std::endl;
	++f1;
	std::cout << "Значение дроби 1 = " << f1.getNumDen() << std::endl;
	std::cout <<  f1.getNumDen() << "--" << " * " << f2.getNumDen() << " = " << (f1 * f2).getNumDen() << std::endl;
	f1--;
	std::cout << "Значение дроби 1 = " << f1.getNumDen() << std::endl;
	return 0;
}