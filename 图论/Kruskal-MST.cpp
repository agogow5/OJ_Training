#include <iostream>
#include <vector>
#include <algorithm>

//关键：kruskal算法计算最小生成树
//注意：srot中的比较。 小于号，而不是小于等于

using namespace std;
#define NODE_NUM 1000

int Tree[NODE_NUM];
int FindRoot(int pos)
{
	if (Tree[pos] == -1)
		return pos;
	else
	{
		int tmp = FindRoot(Tree[pos]);
		Tree[pos] = tmp;//修改根结点，路径压缩
		return tmp;
	}
}

struct Edge {
	int src;
	int dst;
	int cost;
};

//!!!!!!!!这里只能用<， 如果使用<=会出错。可能是=的时候前后移动，无法确定最终的结果
bool cmp(const Edge &e1, const Edge &e2)
{
	return e1.cost < e2.cost;
}


int main()
{
	int N, M;
	cin >> N;
	M = N * (N - 1) / 2;
	vector<Edge> vedge;
	vedge.clear();
	//初始化
	for (int i = 0; i < N; ++i)
	{
		Tree[i] = -1;
	}

	for (int i = 0; i < M; ++i)
	{
		Edge tmp;
		cin >> tmp.src >> tmp.dst >> tmp.cost;
		vedge.push_back(tmp);

	}

	//排序，从小到大
	sort(vedge.begin(), vedge.end(), cmp);

	int ans = 0;
	for (vector<Edge>::iterator iter = vedge.begin(); iter != vedge.end(); ++iter)
	{
		int root_a = FindRoot(iter->src);
		int root_b = FindRoot(iter->dst);
		if (root_a != root_b)
		{
			Tree[root_a] = root_b;//设置父结点，将两个联通分量连接起来
			ans += iter->cost;//累计长度
		}
	}

	cout << ans << endl;

	return 0;
}

