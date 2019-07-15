#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Point {
	int x;
	int y;
	double dist;
};


//求平方、开方


bool cmp(const Point &p1, const Point &p2)
{
	if (p1.dist < p2.dist)
		return true;
	else if (p1.dist > p2.dist)
		return false;
	else
	{
		if (p1.x < p2.x)
			return true;
		else if (p1.x > p2.x)
			return false;
		else
		{
			if (p1.y <= p2.y)
				return true;
			else
				return false;
		}
	}
}

int main()
{
	int a, b, n;
	cin >> a >> b >> n;
	vector<Point> vp;

	for (int i = 0; i < n; ++i)
	{
		int x, y;
		double dis;
		cin >> x >> y;
		dis = sqrt((x - a)*(x - a) + (y - b) * (y - b));
		vp.push_back({ x, y, dis });
	}

	sort(vp.begin(), vp.end(), cmp);

	vector<Point>::iterator pit = vp.begin();
	for (; pit != vp.end(); ++pit)
	{
		if(pit != vp.begin())
			cout << ", ";
		cout << "(" << pit->x << "," << pit->y << ")";
	}


	return 0;
}