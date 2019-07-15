#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m;
int dp[10010][510], v[10010];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + v[i]);
			if (i - j >= 0) dp[i][0] = max(dp[i][0], dp[i - j][j]);
		}
		dp[i][0] = max(dp[i][0], dp[i - 1][0]);
	}
	printf("%d", dp[n][0]);
	return 0;
}