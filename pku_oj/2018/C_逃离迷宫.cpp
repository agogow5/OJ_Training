#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct State {
	int x;
	int y;
	int t;
};

queue<State> qs;

char maze[10][10];
int mask[10][10];

int go[][2] = {
	1, 0,
	-1, 0,
	0, -1,
	0, 1
};
int m, t;

bool BFS()
{
	int x = -1, y = -1;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (maze[i][j] == 'S')
			{
				x = i;
				y = j;
				break;
			}
		}
		if (x != -1)
			break;
	}

	qs.push({ x, y, 0 });

	while (!qs.empty())
	{
		State sp = qs.front();
		qs.pop();

		int nx = sp.x;
		int ny = sp.y;

		if (sp.t == t)
			break;

		for (int i = 0; i < 4; ++i)
		{
			nx = sp.x + go[i][0];
			ny = sp.y + go[i][1];

			if (nx < 0 || nx >= m || ny < 0 || ny >= m)
				continue;
			if (mask[nx][ny] != 0 || maze[nx][ny] == '#')
				continue;

			if (maze[nx][ny] == '.')
			{
				qs.push({ nx, ny, sp.t + 1 });
				mask[nx][ny] = sp.t + 1;
			}
			else if (maze[nx][ny] == 'E')
				return true;
		}
	}

	return false;
}

int main()
{
	int k;
	cin >> k;
	for (int ii = 0; ii < k; ++ii)
	{

		cin >> m >> t;
		memset(maze, 0, sizeof(maze));
		memset(mask, 0, sizeof(mask));

		for (int i = 0; i < m; ++i)
			for (int j = 0; j < m; ++j)
				cin >> maze[i][j];

		if (BFS())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}


	return 0;
}