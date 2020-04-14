#include <iostream>

struct Date {
	short day;
	short month;
	short year;
	bool isCorrect();
};

bool Date::isCorrect()
{
	bool result = false;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((day <= 31) && (day > 0))
			result = true;
		break;
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((day <= 30) && (day > 0))
			result = true;
		break;
	}

	case 2:
	{
		if (year % 4 != 0)
		{
			if ((day <= 28) && (day > 0))
				result = true;
		}
		else
			if (year % 400 == 0)
			{
				if ((day <= 29) && (day > 0))
					result = true;
			}
			else
				if ((year % 100 == 0) && (year % 400 != 0))
				{
					if ((day == 28) && (day > 0))
						result = true;
				}
				else
					if ((year % 4 == 0) && (year % 100 != 0))
						if ((day <= 29) && (day > 0))
							result = true;
		break;
	}

	default:
		result = false;
	}

	return result;
}

struct Student
{
	char name[56];
	char proizvod[32];
	Date delivery;
	short praice;
	short amount;
};

using namespace std;
int main()
{
	const int N = 2;
	Student group[N];

	for (int i = 0; i < N; i++)
	{
		cout << "\nInput Name : ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].name, 56);

		cout << "\nIinput Manufacturer : ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].proizvod, 32);


		do
		{
			cout << "\nInput Date of receipt at the werehouse: ";
			cin.ignore(std::cin.rdbuf()->in_avail());
			cin >> group[i].delivery.day >> group[i].delivery.month >> group[i].delivery.year;
		} while (!group[i].delivery.isCorrect());

		cout << "\nInput Price :";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> group[i].praice;

		cout << "\nInput Amount:";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> group[i].amount;

	}


	cin.clear();



	int best = 0;
	for (int i = 0; i < N; i++)
	{
		if (group[i].praice > group[best].praice)
			best = i;
	}

	cout << "\nName: " << group[best].name << endl;
	cout << "\nManufacturer: " << group[best].proizvod << endl;
	cout << "\nDate of receipt at the werehouse: " << group[best].delivery.day << "." << group[best].delivery.month << "." << group[best].delivery.year;
	cout << "\nPrice: " << group[best].praice << endl;
	cout << "\nAmount: " << group[best].amount << endl;
	return 0;
}
