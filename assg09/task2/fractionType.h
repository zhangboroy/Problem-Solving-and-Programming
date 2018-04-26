#ifndef FRACTIONTYPE_H_INCLUDED
#define FRACTIONTYPE_H_INCLUDED

#include <iostream>
using namespace std;

//the class for fractions
class fractionType
{
    int numerator;
    int denominator;
public:
    //create a fraction=0/1
    fractionType();
    //create a fraction=a/b
    fractionType(int a, int b);
    //output fractionType(a,b) as a/b
    friend ostream& operator<<(ostream &cout, const fractionType &f);
    //input in the format "a/b" to the variable, then the variable will be fractionType(a,b)
    friend istream& operator>>(istream &cin, fractionType &f);
    // a/b + c/d = (ad + bc)/bd
    fractionType operator+(const fractionType &f) const;
    // a/b – c/d = (ad – bc)/bd
    fractionType operator-(const fractionType &f) const;
    // a/b * c/d = ac/bd
    fractionType operator*(const fractionType &f) const;
    // (a/b)/(c/d) = ad/bc, in which c/d !=0
    fractionType operator/(const fractionType &f) const;
    // (a/b<=c/d) = (ad<=bc)
    bool operator<=(const fractionType &f) const
    {
        return (numerator*f.denominator<=denominator*f.numerator);
    }
    // (a/b>=c/d) = (ad>=bc)
    bool operator>=(const fractionType &f) const
    {
        return (numerator*f.denominator>=denominator*f.numerator);
    }
    // (a/b==c/d) = (ad==bc)
    bool operator==(const fractionType &f) const
    {
        return (numerator*f.denominator==denominator*f.numerator);
    }
    // (a/b!=c/d) = (ad!=bc)
    bool operator!=(const fractionType &f) const
    {
        return (numerator*f.denominator!=denominator*f.numerator);
    }
    bool operator>(const fractionType &f) const
    {
        return !(*this<=f);
    }
    bool operator<(const fractionType &f) const
    {
        return !(*this>=f);
    }
};

#endif // FRACTIONTYPE_H_INCLUDED
