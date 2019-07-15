 #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
int dp1[50001], dp2[50001];
int vl[50001];


int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));
		memset(vl, 0, sizeof(vl));
		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n; ++i)
			scanf("%d", &vl[i]);

		dp1[1] = vl[1];
		for (int i = 2; i <= n; ++i)
			dp1[i] = max(dp1[i - 1] + vl[i], vl[i]);

		for (int i = 2; i <= n; ++i)
			dp1[i] = max(dp1[i - 1], dp1[i]);

		dp2[n] = vl[n];
		for (int i = n - 1; i >= 1; --i)
			dp2[i] = max(dp2[i + 1] + vl[i], vl[i]);

		for (int i = n - 1; i >= 1; --i)
			dp2[i] = max(dp2[i + 1], dp2[i]);

		int ans = -INT32_MAX;
		for (int i = 1; i < n; ++i)
		{
			int s = dp1[i] + dp2[i + 1];
			ans = max(ans, s);
		}

		printf("%d\n", ans);
	}

	return 0;
}