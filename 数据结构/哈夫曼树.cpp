#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main()
{
	int weight = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}
	while (pq.size() >= 2)
	{
		int min_1 = pq.top();
		pq.pop();
		int min_2 = pq.top();
		pq.pop();
		int sum = min_1 + min_2;
		weight += sum;
		pq.push(sum);
	}
	cout << weight << endl;
	return 0;
}