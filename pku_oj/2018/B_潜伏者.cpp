#include <iostream>
#include <string>
#include <map>

using namespace std;




int main()
{
	string a;
	string b;
	string c;

	map <char, char> mcha;
	mcha.clear();

	cin >> a >> b >> c;

	int length = a.size();
	if (length != b.size())
	{
		cout << "Failed" << endl;
		return 0;
	}

	for (int i = 0; i < length; ++i)
	{
		map<char, char>::iterator mit = mcha.find(a[i]);
		if (mit == mcha.end())
		{
			mcha[a[i]] = b[i];
		}
		else
		{
			if (mit->second != b[i])
			{
				cout << "Failed" << endl;
				return 0;
			}

		}
	}

	if (mcha.size() != 26)
	{
		cout << "Failed" << endl;
		return 0;
	}

	length = c.size();
	for (int i = 0; i < length; ++i)
	{
		cout << mcha[c[i]];
	}


	return 0;
}