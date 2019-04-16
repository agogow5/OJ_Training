#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Program {
	int begin_time;
	int end_time;
	bool operator<(const Program & p)
	{
		return this->end_time < p.end_time;
	}
};

int main()
{
	int n;
	vector<Program> programs;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		Program tmp;
		cin >> tmp.begin_time >> tmp.end_time;
		programs.push_back(tmp);
	}
	sort(programs.begin(), programs.end());
	int count = 0;
	int end = 0;
	//注：最早结束的节目要优先。按end_time的顺序来排列。
	for (vector<Program>::iterator iter = programs.begin(); iter != programs.end(); ++iter)
	{
		if (iter->begin_time >= end)
		{
			count++;
			end = iter->end_time;
		}
	}
	cout << count << endl;

	return 0;
}
