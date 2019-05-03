#include <iostream>
#include <vector>
#include <algorithm>

//�ؼ���kruskal�㷨������С����������Ҫ�Լ����ݵ����깹�����Ϣ
//ע�⣺srot�еıȽϡ� С�ںţ�������С�ڵ���

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
		Tree[pos] = tmp;//�޸ĸ���㣬·��ѹ��
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

//!!!!!!!!����ֻ����<�� ���ʹ��<=�����������=��ʱ��ǰ���ƶ����޷�ȷ�����յĽ��
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

	//��ʼ��
	for (int i = 0; i < N; ++i)
	{
		Tree[i] = -1;
	}

	//���������
	for (int i = 0; i < M; ++i)
	{
		Point tmp;
		cin >> tmp.x >> tmp.y;
		vpoint.push_back(tmp);

	}

	//�����
	for (vector<Point>::iterator iter1 = vpoint.begin(); iter1 != vpoint.end(); ++iter1)
	{
		for (vector<Point>::iterator iter2 = iter1 + 1; iter2 != vpoint.end(); ++iter2)
		{
			double p_distance = (iter1->x - iter2->x) *(iter1->x - iter2->x) + (iter1->y - iter2->y) *(iter1->y - iter2->y);
			p_distance = sqrt(p_distance);
			vedge.push_back({ iter1 - vpoint.begin() + 1,iter2 - vpoint.begin() + 1,p_distance });

		}
	}


	//���򣬴�С����
	sort(vedge.begin(), vedge.end(), cmp);

	double ans = 0;
	for (vector<Edge>::iterator iter = vedge.begin(); iter != vedge.end(); ++iter)
	{
		int root_a = FindRoot(iter->src);
		int root_b = FindRoot(iter->dst);
		if (root_a != root_b)
		{
			Tree[root_a] = root_b;//���ø���㣬��������ͨ������������
			ans += iter->cost;//�ۼƳ���
		}
	}

	printf("%.2f", ans);


	return 0;
}

