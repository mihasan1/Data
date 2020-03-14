#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

class Date
{
	int day;
	int month;
	int year;
public:
	Date()
	{
		day = 0;
		month = 0;
		year = 0;
	};
	Date(char(&data)[11])
	{
		SeperateSTR(data);
		if (!TrueDate())
			cout << "Дата введена неправильно!";
	}

	~Date()
	{

	}

	void SeperateSTR(char(&data)[11])
	{
		string tmp = "";
		int k = 0;
		for (int i = 0; i < 11; i++)
		{
			if (i == 10)
			{
				year = (atoi(tmp.c_str()));
			}
			if (data[i] != '.')
			{
				tmp += data[i];
			}
			else
			{
				switch (k)
				{
				case 0:
					day = (atoi(tmp.c_str()));
					break;
				case 1:
					month = (atoi(tmp.c_str()));
					break;
				default:
					break;
				}
				k++;
				tmp = "";
			}
		}
	}

	void print() const
	{
		cout << day << '.' << month << '.' << year << std::endl;
	}

	bool TrueDate()
	{
		if ((day < 1 || day>dayInMonth(month)) || (month < 1 || month>12))
		{
			cout << "Дата введена неправильно" << endl;
			return false;
		}
		else return true;
	}

	bool isLeapYear()
	{
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			return true;
		else
			return false;
	}

	int dayInMonth(int month)
	{
		if (isLeapYear())days[1] = 29;
		return days[month - 1];
	}

	void AddMonth(int g)
	{
		if (isLeapYear()) days[1] = 29;
		month += g;
		while (month > 12)
		{
			++year;
			month -= 12;
		}
		if (day > days[month - 1])
			*this = *this + (days[month - 1] - day);
	}
	void SubstractMonths(int g)
	{
		if (isLeapYear()) days[1] = 29;
		while (g > 0)
		{
			g--;
			month--;
			if (month < 1)
			{
				year--;
				month = 12;
			}
			if (day > days[month - 1])
				*this = *this + (days[month - 1] - day);
		}
	}
	void AddYears(int g)
	{
		year += g;
	}
	void SubstractYears(int g)
	{
		year -= g;
	}
	bool CompareDates(Date cmp)
	{
		if (day < cmp.day || month < cmp.month || year < cmp.year)
			return false;
		else
			return true;
	}
	int countDays(Date d2)
	{
		int count = 0;
		while (!(day == d2.day && month == d2.month && year == d2.year))
		{
			if (CompareDates(d2))
				*this = *this - 1;
			else if (!CompareDates(d2))
				*this = *this + 1;
			count++;
		}
		return count;
	}

	float countOfMonths(Date d2)
	{
		return (countDays(d2)/30);
	}

	Date operator+(int g)
	{
		if (isLeapYear())days[1] = 29;
		day += g;
		while (day > days[month - 1])
		{
			day -= days[month - 1];
			month++;
			if (month > 12)
			{
				++year;
				month = 1;
			}
		}
		return *this;
	}
	Date operator-(int g)
	{
		if (isLeapYear()) days[1] = 29;
		while (g > 0)
		{
			if (g > day)
			{
				g -= day;
				--month;
				if (month < 1)
				{
					--year;
					month = 12;
				}
				day = days[month - 1];
			}
			else if (day == g)
			{
				day -= g;
				g = 0;
				--month;
				if (month < 1)
				{
					--year;
					month = 12;
				}
				day = days[month - 1];
			}
			else
			{
				day -= g;
				g = 0;
			}
		}
		return *this;
	}
};


int main()
{
	system("chcp 1251");
	char data[11], data2[11];
	cout << "Введите дату в формате 'ДД.ММ.ГГГГ':\n";
	cin.getline(data, 11);
	int g;
	Date d1(data);
	d1.print();
	cout << "1 - Добавить к дате     2 - Отнять от даты (ДНИ)\n";
	cout << "3 - Добавить к дате     4 - Отнять от даты (МЕСЯЦЫ)\n";
	cout << "5 - Добавить к дате     6 - Отнять от даты (ГОДЫ)\n";
	cout << "7 - Сравнить две даты   8 - Кол-во дней между датами\n";
	cout << "9 - Кол-во месяцев между датами  0 - Выход\n";
	while (true)
	{
		int choice;
		cout << "Выберите действие: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Введите кол-во дней для добавления: ";
			cin >> g;
			d1 = d1 + g;
			d1.print();
			break;
		case 2:
			cout << "Введите кол-во дней для вычитания: ";
			cin >> g;
			d1 = d1 - g;
			d1.print();
			break;
		case 3:
			cout << "Введите кол-во месяцев для добавления: ";
			cin >> g;
			d1.AddMonth(g);
			d1.print();
			break;
		case 4:
			cout << "Введите кол-во месяцев для вычитания: ";
			cin >> g;
			d1.SubstractMonths(g);
			d1.print();
			break;
		case 5:
			cout << "Введите кол-во лет для добавления: ";
			cin >> g;
			d1.AddYears(g);
			d1.print();
			break;
		case 6:
			cout << "Введите кол-во лет для вычитания: ";
			cin >> g;
			d1.SubstractYears(g);
			d1.print();
			break;
		case 7:
		{
			cout << "Введите дату в формате 'ДД.ММ.ГГГГ':\n";
			cin.ignore();
			cin.getline(data2, 11);
			Date d2(data2);
			d2.print();
			d1.CompareDates(d2);
			if (d1.CompareDates(d2))
				cout << data << " > " << data2 << endl;
			else
				cout << data << " < " << data2 << endl;

			d2.~Date();
		}
		break;
		case 8:
		{
			cout << "Введите дату в формате 'ДД.ММ.ГГГГ':\n";
			cin.ignore();
			cin.getline(data2, 11);
			Date d2(data2);
			cout << "Между " << data << " и " << data2 << " " << abs(d1.countDays(d2)) << " дней\n";
			d2.~Date();
		}
		break;
		case 9:
		{
			cout << "Введите дату в формате 'ДД.ММ.ГГГГ':\n";
			cin.ignore();
			cin.getline(data2, 11);
			Date d2(data2);
			cout << "Между " << data << " и " << data2 << " " << abs(d1.countOfMonths(d2)) << " месяца(-ев)\n";
			d2.~Date();
		}
		break;
		case 0:
			return 0;
		default:
			cout << "Неправильно!";
			break;
		}
	}

	return 0;
}
