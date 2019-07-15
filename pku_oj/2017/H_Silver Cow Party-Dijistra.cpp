#include <iostream>


using namespace std;

int adj[1001][1001];
int dist1[1001], dist2[1001];

void dijstra(int dist[1001], int ad[1001][1001], int n, int x)
{
	bool mask[1001];
	memset(mask, false, sizeof(mask));
	memset(dist, -1, (n+1) * sizeof(int));
	dist[x] = 0;
	mask[x] = true;

	int newP = x;
	for (int ii = 1; ii < n; ++ii)
	{
		for (int i = 1; i <= n; ++i)
		{
			if (mask[i] == true || ad[newP][i] == -1)
				continue;

			if (dist[i] == -1 || dist[i] > ad[newP][i] + dist[newP])
				dist[i] = ad[newP][i] + dist[newP];
		}
		
		int min = INT32_MAX;
		int pos = -1;
		for (int i = 1; i <= n; ++i)
		{
			if (-1 != dist[i] && mask[i] == false && dist[i] < min)
			{
				min = dist[i];
				pos = i;
			}
		}
		newP = pos;
		mask[pos] = true;
	}

	

}


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

	dijstra(dist1, adj, n, x);



	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			int t = adj[i][j];
			adj[i][j] = adj[j][i];
			adj[j][i] = t;
		}
	}

	dijstra(dist2, adj, n, x);



	int max = 0;
	for (int i = 1; i <= n; ++i)
	{
		int dis = dist1[i] + dist2[i];
		if (max < dis)
			max = dis;
	}
	cout << max << endl;


	return 0;
}