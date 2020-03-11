#include <iostream>
#include <string>
using namespace std;

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
	Date(int d, int m, int y)
	{
		if (TrueDate(d, m, y))
		{
			day = d;
			month = m;
			year = y;
		}
	}

	~Date()
	{

	}

	void print() const
	{
		cout << day << '.' << month << '.' << year << std::endl;
	}

    bool TrueDate(int d, int m, int y)
	{
		if ((d < 1 || d>31) || (m < 1 || m>12) )
		{
			cout << "Дата введена неправильно" << endl;
			return false;
		}
		else return true;
	}

    bool isLeapYear()
	{
	    if(year%4==0)
            return true;
        else
            return false;
	}

	int dayInMonth(int month)
	{
		int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		if (isLeapYear())days[1] = 29;
		return days[month - 1];
	}

    void AddDays(int g)
    {
        int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        if (isLeapYear())days[1] = 29;
        day+=g;
        while(day>days[month-1])
        {
            day-=days[month-1];
            month++;
            if(month > 12)
            {
                ++year;
                month=1;
            }
        }
    }
    void DecreaseDays(int g)
    {
        int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        if(isLeapYear()) days[1]=29;


    }
};

int main()
{
system("chcp 1251");
	char data[11];
	cout << "Введите дату в формате 'ДД.ММ.ГГГГ':\n";
	cin.getline(data, 11);
	int d = 0, m = 0, y = 0;
	string tmp = "";
	int k = 0;
	int g;
	for (int i = 0; i < 11; i++)
	{
		if (i == 10)
		{
			y = (atoi(tmp.c_str()));
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
				d = (atoi(tmp.c_str()));
				break;
			case 1:
				m = (atoi(tmp.c_str()));
				break;
			default:
				break;
			}
			k++;
			tmp = "";
		}
	}
	Date d1(d, m, y);
	if (d1.TrueDate(d, m, y))
		d1.print();
	else
		return 0;

    cout << "Введите кол-во дней для добавления: ";
    cin >> g;
    d1.AddDays(g);
    d1.print();
	return 0;
}
