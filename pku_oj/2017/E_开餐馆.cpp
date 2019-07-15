#include <iostream>


using namespace std;

int dp[101];
int pl[101];
int prf[101];



int main()
{
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ++ii)
	{
		int n, k;
		cin >> n >> k;
		memset(dp, 0, sizeof(dp));
		memset(pl, 0, sizeof(pl));
		memset(prf, 0, sizeof(prf));

		for (int i = 1; i <= n; ++i)
			cin >> pl[i];
		for (int i = 1; i <= n; ++i)
			cin >> prf[i];

		dp[1] = prf[1];
		for (int i = 2; i <= n; ++i)
		{
			int maxprf = 0;

			for (int j = 1; j < i; ++j)
			{
				if (k > pl[i] - pl[j])
					break;

				if (maxprf < dp[j])
					maxprf = dp[j];
			}

			maxprf += prf[i];
			dp[i] = maxprf;
		}

		int max = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (dp[i] > max)
				max = dp[i];
		}
		cout << max << endl;

	}

	return 0;
}