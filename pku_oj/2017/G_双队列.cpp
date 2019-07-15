#include <iostream>
#include <map>

using namespace std;





int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	map<int, int> idmap;
	idmap.clear();

	int n, k, p;
	while (true)
	{
		cin >> n;

		if (0 == n)
			break;
		else if (1 == n)
		{
			cin >> k >> p;
			idmap[p] = k;
		}
		else if (3 == n)
		{
			if (idmap.empty())
				cout << 0 << endl;
			else
			{
				cout << idmap.begin()->second << endl;
				idmap.erase(idmap.begin());
			}
		}
		else // 2== n 
		{
			if (idmap.empty())
				cout << 0 << endl;
			else
			{
				map<int, int>::iterator idit = idmap.end();
				idit--;
				cout << idit->second << endl;
				idmap.erase(idit);
			}
		}
	}

	return 0;
}