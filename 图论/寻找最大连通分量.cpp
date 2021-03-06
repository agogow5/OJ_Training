#include <iostream>
#include <vector>

//关键：计算连通分量的数目。ans = 连通分量数目 - 1
//      求取最大连通分量，额外增加Sum数组来统计每个连通分量的结点数目。

using namespace std;
#define NODE_NUM 1000

int Tree[NODE_NUM];
int Sum[NODE_NUM];
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



int main()
{
	int N, M;
	cin >> N >> M;

	//初始化
	for (int i = 0; i < NODE_NUM; ++i)
	{
		Tree[i] = -1;
		Sum[i] = 1;
	}

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		int root_a = FindRoot(a);
		int root_b = FindRoot(b);
		if (root_a != root_b)
		{
			Tree[root_a] = root_b;//设置父结点，将两个联通分量连接起来
			Sum[root_b] += Sum[root_a];
		}
	}
	int ans = 0;

	//编号从1到N
	for (int i = 1; i <= N; ++i)
	{
		if (Tree[i] == -1)
		{
			if (ans < Sum[i])
				ans = Sum[i];
		}
	}

	cout << ans << endl;

	return 0;
}

