#include "fractionType.h"

//create a fraction=0/1
fractionType::fractionType()
{
    numerator=0;
    denominator=1;
}

//create a fraction=a/b
fractionType::fractionType(int a, int b)
{
    if (b!=0)
    {
        numerator=a;
        denominator=b;
    }
    else
    {
        cout<<"The denominator can't be 0!"<<endl;
    }
}

//output fractionType(a,b) as a/b
ostream& operator<<(ostream &cout, const fractionType &f)
{
    cout<<f.numerator<<" / "<<f.denominator;
    return cout;
}

//input in the format "a/b" to the variable, then the variable will be fractionType(a,b)
istream& operator>>(istream &cin, fractionType &f)
{
    char temp;
    cin>>f.numerator>>temp>>f.denominator;
    return cin;
}

// a/b + c/d = (ad + bc)/bd
fractionType fractionType::operator+(const fractionType &f) const
{
    fractionType result;
    result.numerator=(numerator*f.denominator+f.numerator*denominator);
    result.denominator=denominator*f.denominator;
    return result;
}

// a/b – c/d = (ad – bc)/bd
fractionType fractionType::operator-(const fractionType &f) const
{
    fractionType result;
    result.numerator=(numerator*f.denominator-f.numerator*denominator);
    result.denominator=denominator*f.denominator;
    return result;
}

// a/b * c/d = ac/bd
fractionType fractionType::operator*(const fractionType &f) const
{
    fractionType result;
    result.numerator=(numerator*f.numerator);
    result.denominator=denominator*f.denominator;
    return result;
}

// (a/b)/(c/d) = ad/bc, in which c/d !=0
fractionType fractionType::operator/(const fractionType &f) const
{
    if (f.numerator!=0)
    {
        fractionType result;
        result.numerator=(numerator*f.denominator);
        result.denominator=denominator*f.numerator;
        return result;
    }
    else
    {
        cout<<"The divisor can't be 0!"<<endl;
    }
}
