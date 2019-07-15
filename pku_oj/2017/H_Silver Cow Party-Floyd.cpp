#include <iostream>


using namespace std;

int adj[1001][1001];
//int dist[1001][1001];

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	memset(adj, -1, sizeof(adj));
	int n, m, x;
	cin >> n >> m >> x;

	for (int i = 1; i <= n; ++i)
		adj[i][i] = 0;

	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = c;
	}

	for (int k = 1; k <= n; ++k)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (-1 == adj[i][k] || -1 == adj[k][j])
					continue;
				if (-1 == adj[i][j] || ((adj[i][k] + adj[k][j]) < adj[i][j]))
					adj[i][j] = adj[i][k] + adj[k][j];
			}
		}
	}

	int max = 0;
	for (int i = 1; i <= n; ++i)
	{
		int dis = adj[i][x] + adj[x][i];
		if (max < dis)
			max = dis;
	}
	cout << max << endl;


	return 0;
}