#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

bool isALeapYear (int year)
{
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int numberOfDaysInMonth (int month, int year)
{
    switch (month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 2:
			if (isALeapYear(year))
            {
                return 29;
            }
            else
            {
                return 28;
            }
	}
}

bool dateIsValid (int year, int month, int day)
{
    if ((year < 1582) ||
        (year == 1582 && month < 10) ||
        (year == 1582 && month == 10 && day < 15) ||
        (month < 1 || month > 12) ||
        (day < 1 || day > numberOfDaysInMonth(month, year)))
		// Check to see if this is a valid date
		// The Gregorian calendar began On Oct 15, 1582. Earlier dates are invalid.
        // Months must be in the range 1..12
        // Days must be in the range 1..K where K is the number of days in that month.
    {
        return false;
    }
    else
    {
        return true;
    }
}

void dayOfTheYear (int year, int month, int day)
{
	int sum = 0;

    // Add up the number of days in all earlier months of this year
	for (int m = 1; m < month; ++m)
	{
		sum += numberOfDaysInMonth(m, year);
	}

	// Then add the day number to that sum
	int dayNum = sum + day;
	cout << setw(2) << setfill('0') << month
			 << "/" << setw(2) << setfill('0') << day << "/"
			 << setw(4) << year;
	cout << " is day #" << dayNum << " of that year." << endl;
}

void readDateFromFile(ifstream &inData)
{
    inData.open ("date-File.txt");
}

int main()
{
	int year, month, day;
	char c;
	ifstream inData;

    readDateFromFile(inData);
    inData >> year >> c >> month >> c >> day;
    inData.close();

	if (!inData)
	{
		cout << "Could not obtain valid input." << endl;
		return -1;
	}

    if (!dateIsValid(year, month, day))
	{
		cout << "Sorry, that is not a valid date" << endl;
	}
    else
    {
        cout<<"Date read: "<<year<<c<<month<<c<<day<<endl;
        dayOfTheYear (year, month, day);
    }
    return 0;
}

