#include<iostream>
#include <istream>
#include <algorithm>
#include <string>
using namespace std;

struct Student
{
	string name;
	int age;
	int score;
};

//true则 x在y之前
bool cmp(Student x, Student y)
{
	if (x.score != y.score)
		return x.score < y.score;

	//int tmp = x.name.compare(y.name);
	//if (tmp != 0)
	//	return tmp < 0;
	if (x.name != y.name)
		return x.name < y.name;
	
	
	return x.age > y.age;


	/*if (x.score > y.score)
		return true;
	else if (x.score < y.score)
		return false;
	else
	{
		if (x.name < y.name)
			return true;
		else if (x.name > y.name)
			return false;
		else {
			if (x.age < y.age)
				return true;
			else
				return false;
		}
	}*/
}


int main()
{
	int n;
	Student buf[100];
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> buf[i].name >> buf[i].age >> buf[i].score;

	sort(buf, buf + n, cmp);
	for (int i = 0; i < n; ++i)
		cout << buf[i].name << ' ' << buf[i].age << ' ' << buf[i].score << endl;


	return 0;
}