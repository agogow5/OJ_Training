#include <iostream>


using namespace std;

int a[102][102];
int b[102][102];



int main()
{
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
			cin >> a[i][j];
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			int cnt = a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1] + a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][j + 1] + a[i][j - 1] + a[i][j + 1];
			if (cnt < 2 || cnt > 3)
				b[i][j] = 0;
			else if (cnt == 3)
				b[i][j] = 1;
			else
				b[i][j] = a[i][j];

		}
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
			cout << b[i][j] << ' ';
		cout << endl;
	}

	return 0;
}