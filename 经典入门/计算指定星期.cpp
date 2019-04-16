#include<iostream>
#include<string>
#include<map>
using namespace std;

#define ISLEAP(x) ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0 && x % 3200 != 0))? 1 : 0 
enum Weekday { Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday };
const char *week[] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
//char *Month[13] = [];
map<string, int> Month = { {"January", 1}, {"February", 2}, {"March", 3}, {"April", 4}, {"May", 5}, {"June", 6},
{"July", 7}, {"August", 8}, {"September", 9}, {"October", 10}, {"November", 11}, {"December", 12} };
int day_of_month[13][2] = {
	{0, 0},
	{31, 31},
	{28, 29},
	{31, 31},
	{30, 30},
	{31, 31},
	{30, 30},
	{31, 31},
	{31, 31},
	{30, 30},
	{31, 31},
	{30, 30},
	{31, 31} };

struct Date
{
	int day;
	int month;
	int year;
	void next_day();
	bool operator==(Date &);
};
void Date ::next_day() {
	day++;
	if (day > day_of_month[month][ISLEAP(year)])
	{
		day = 1;
		month++;
		if (month > 12)
		{
			month = 1;
			year++;
		}
	}

	return;
}

bool Date::operator==(Date &d)
{
	return (this->year == d.year && this->month == d.month && this->day == d.day);
}

int main()
{
	Date d1, today = { 12, 4, 2019 }, tmp = { 1, 1, 1000 }, final_day = { 31, 12, 3000 };
	int delta_today, delta_inputday;
	int count = 0;
	string str;
	cin >> d1.day >> str >> d1.year;
	d1.month = Month[str];
	while (!(tmp == final_day))
	{
		if (tmp == today)
			delta_today = count;
		if (tmp == d1)
			delta_inputday = count;
		count++;
		tmp.next_day();
	}
	//如果d1比today小，则是正确。否则就会错误。
	/*int delta = delta_day - delta_today;
	delta = delta % 7;
	if (delta < 0)
		delta += 7;
	int week_today = 4;
	int week_predict = (week_today + delta) % 7;
	cout << week[week_predict] << endl;*/

	int week_today = 4;
	int delta_day =  delta_inputday - delta_today;//这一行是关键！！！！！！！！！！！ 两者的顺序不能颠倒。
	int delta_weekday = week_today + delta_day;
	delta_weekday = delta_weekday % 7;
	if (delta_weekday < 0)
		delta_weekday += 7;
	cout << week[delta_weekday] << endl;
	
	return 0;
}