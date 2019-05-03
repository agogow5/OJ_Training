#include <iostream>
#include <vector>
#include <algorithm>

//�ؼ���kruskal�㷨������С������
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
	int cost;
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
	vedge.clear();
	//��ʼ��
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

	//���򣬴�С����
	sort(vedge.begin(), vedge.end(), cmp);

	int ans = 0;
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

	cout << ans << endl;

	return 0;
}

