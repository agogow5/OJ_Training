#include <iostream>
#include <vector>
#include <algorithm>

//关键：kruskal算法计算最小生成树，需要自己根据点坐标构造边信息
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
	double cost;
};

struct Point {
	double x;
	double y;
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
	vector<Point> vpoint;

	//初始化
	for (int i = 0; i < N; ++i)
	{
		Tree[i] = -1;
	}

	//输入点坐标
	for (int i = 0; i < M; ++i)
	{
		Point tmp;
		cin >> tmp.x >> tmp.y;
		vpoint.push_back(tmp);

	}

	//构造边
	for (vector<Point>::iterator iter1 = vpoint.begin(); iter1 != vpoint.end(); ++iter1)
	{
		for (vector<Point>::iterator iter2 = iter1 + 1; iter2 != vpoint.end(); ++iter2)
		{
			double p_distance = (iter1->x - iter2->x) *(iter1->x - iter2->x) + (iter1->y - iter2->y) *(iter1->y - iter2->y);
			p_distance = sqrt(p_distance);
			vedge.push_back({ iter1 - vpoint.begin() + 1,iter2 - vpoint.begin() + 1,p_distance });

		}
	}


	//排序，从小到大
	sort(vedge.begin(), vedge.end(), cmp);

	double ans = 0;
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

	printf("%.2f", ans);


	return 0;
}

