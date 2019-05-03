#include <iostream>
#include <vector>

//�ؼ���������ͨ��������Ŀ��ans = ��ͨ������Ŀ - 1
//      ��ȡ�����ͨ��������������Sum������ͳ��ÿ����ͨ�����Ľ����Ŀ��

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
		Tree[pos] = tmp;//�޸ĸ���㣬·��ѹ��
		return tmp;
	}
}



int main()
{
	int N, M;
	cin >> N >> M;

	//��ʼ��
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
			Tree[root_a] = root_b;//���ø���㣬��������ͨ������������
			Sum[root_b] += Sum[root_a];
		}
	}
	int ans = 0;

	//��Ŵ�1��N
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

