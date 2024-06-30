#include "Complex.hpp"
#include <string>

using namespace std;

// constructors
Complex::Complex(double r, double i) : real(r), imaginary(i) {}
Complex::Complex(double r) : real(r), imaginary(0) {}
Complex::Complex() : real(0), imaginary(0) {}

double Complex::get_real() const{return real;}

double Complex::get_imaginary() const{return imaginary;}

Complex &Complex::operator+=(const Complex &other){
    real += other.real;
    imaginary += other.imaginary;
    return *this;
}

Complex &Complex::operator-=(const Complex &other){
    real -= other.real;
    imaginary -= other.imaginary;
    return *this;
}

bool Complex::operator==(const Complex &other){
    return real == other.real && imaginary == other.imaginary;
}

bool Complex::operator!=(const Complex &other){
    return !(*this == other);
}

bool Complex::operator<(const Complex &other){
    return real < other.real || (real == other.real && imaginary < other.imaginary);
}

string Complex::to_string() const{
    return std::to_string(real) + " + " + std::to_string(imaginary) + "i";
}