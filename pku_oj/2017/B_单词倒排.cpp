#include <iostream>
#include <string>

using namespace std;

//可以考虑使用 char 数组的方式
char *istr[101];



int main()
{
	string str;
	getline(cin, str);
	while (true)
	{
		int pos = str.find_last_of(" ");
		if (pos == string::npos)
		{
			cout << str;
			break;
		}
		else
		{
			cout << string(str.begin() + pos + 1, str.end());
			cout << " ";
			str = string(str.begin(), str.begin() + pos);
		}
	}


	return 0;
}