#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <string>

using namespace std;

class Complex {
private:
    double real;
    double imaginary;
public:
    Complex(double r, double i);
    Complex(double r);
    Complex();
    double get_real() const;
    double get_imaginary() const;
    Complex& operator+=(const Complex& other);
    Complex& operator-=(const Complex& other);
    bool operator==(const Complex& other);
    bool operator!=(const Complex& other);
    bool operator<(const Complex& other);
    bool operator>(const Complex& other);
    string to_string() const;
};

#endif //COMPLEX_HPP