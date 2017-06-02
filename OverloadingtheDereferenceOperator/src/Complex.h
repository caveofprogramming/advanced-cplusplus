/*
 * Complex.h
 *
 *  Created on: 17 Oct 2014
 *      Author: johnwpurcell
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <iostream>
using namespace std;

namespace caveofprogramming {

class Complex {
private:
	double real;
	double imaginary;

public:
	Complex();
	Complex(double real, double imaginary);
	Complex(const Complex &other);
	const Complex &operator=(const Complex &other);

	double getReal() const {
		return real;
	}
	double getImaginary() const {
		return imaginary;
	}

	bool operator==(const Complex &other) const;
	bool operator!=(const Complex &other) const;
	Complex operator*() const;
};

ostream &operator<<(ostream &out, const Complex &c);
Complex operator+(const Complex &c1, const Complex &c2);
Complex operator+(const Complex &c1, double d);
Complex operator+(double d, const Complex &c1);

} /* namespace caveofprogramming */

#endif /* COMPLEX_H_ */
