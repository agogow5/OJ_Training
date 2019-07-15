#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>


using namespace std;
vector<int> edge[26];
int inDegree[26];

int vi[26];
int tp[26];
bool mask[26];

int n, m;
int toposort()
{
	memcpy(vi, inDegree, sizeof(inDegree));
	memset(tp, -1, sizeof(tp));
	memset(mask, false, sizeof(mask));

	int tps = 0;

	for (int i = 0; i < n; ++i)
	{
		int zcnt = 0;
		int pos = -1;
		for (int j = 0; j < n; ++j)
		{
			if (mask[j] == false && vi[j] == 0)
			{
				zcnt++;
				pos = j;
			}
		}

		if (zcnt == 0)
			return -1;

		if (zcnt > 1)
			tps = 1;

		mask[pos] = true;
		int vsize = edge[pos].size();
		for (int j = 0; j < vsize; ++j)
			vi[edge[pos][j]]--;
		tp[i] = pos;
	}
	return tps;
}

int main()
{
	string str;


	while (true)
	{
		cin >> n >> m;
		if (m == 0 && n == 0)
			break;

		for (int i = 0; i < 26; ++i)
			edge[i].clear();
		memset(inDegree, 0, sizeof(inDegree));

		int i = 0;
		for (; i < m; ++i)
		{
			cin >> str;
			edge[int(str[0] - 'A')].push_back(int(str[2] - 'A'));
			inDegree[int(str[2] - 'A')] ++;

			int res = toposort();
			if (res == 0)
			{
				cout << "Sorted sequence determined after " << i + 1 << " relations: ";
				for (int j = 0; j < n; ++j)
					cout << char('A' + tp[j]);
				cout << "." << endl;
				break;
			}
			else if (res == -1)
			{
				cout << "Inconsistency found after " << i + 1 << " relations." << endl;
				break;
			}

		}

		if(i == m)
			cout << "Sorted sequence cannot be determined." << endl;
		else
		{
			while (i + 1 < m)
			{
				cin >> str;
				++i;
			}
		}
	}

	return 0;
}