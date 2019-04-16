#include<iostream>


using namespace std;

int main()
{
	int n;
	char ch1, ch2;
	cin >> n >> ch1 >> ch2;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if ((i == 1 && j == 1) || (i == 1 && j == n) || (i == n && j == 1) || (i == n && j == n))
				cout << ' ' << ' ';
			else
			{
				int half = n / 2 + 1;

				int t_i = i > half ? 2 * half - i : i;
				int t_j = j > half ? 2 * half - j : j;
				

				int min = t_i > t_j ? t_j : t_i;
				if(min %2)
					cout << ch1 << ' ';
				else
					cout << ch2 << ' ';
			}
		}
		cout << endl;
	}
}