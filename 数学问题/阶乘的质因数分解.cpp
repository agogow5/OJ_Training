#include<iostream>

using namespace std;


//TODO: int ���ֵ

int prime[1000];//�洢1000���ڵ�����
bool mask[1001];//������� 0 - 1000 �Ƿ�Ϊ����
int prime_size;//1001������������
int cnt[1001];//n!���������ֽ�
int cnt2[1001];//a���������ֽ�

void init()
{
	prime_size = 0;
	for (int i = 0; i <= 1000; ++i)
		mask[i] = false;

	//ע�⣺�����2��ʼ��
	for (int i = 2; i <= 1000; ++i)
	{
		if (mask[i])
			continue;

		prime[prime_size++] = i;

		for (int j = i * i; j <= 1000; j += i)
			mask[j] = true;
	}
}

int main()
{
	int n1, n2;
	cin >> n1 >> n2;

	//�ȳ�ʼ�������1000�ڵ���������
	init();
	//����Ϊ0
	for (int i = 0; i < 1001; ++i)
	{
		cnt[i] = 0;
		cnt2[i] = 0;
	}

	//��n!���������ֽ�
	for (int i = 0; i < prime_size; ++i)
	{
		int tmp = n1;
		while (tmp)
		{
			cnt[i] += tmp / prime[i];
			tmp = tmp / prime[i];
		}
	}

	//��ΪҪ����Сֵ������ĳ�ʼֵΪINT_MAX
	int ans = INT_MAX;
	//��a���������ֽ⣬ͬʱ�����С��k
	for (int i = 0; i < prime_size; ++i)
	{
		while (n2%prime[i] == 0)
		{
			cnt2[i]++;
			n2 /= prime[i];
		}

		if (cnt2[i] == 0)
			continue;

		if (cnt[i] / cnt2[i] < ans)
			ans = cnt[i] / cnt2[i];
		if (n2 == 1)
			break;

	}
	cout << ans << endl;


	return 0;
}
//if (n2 % prime[i] == 0)
//{
//	while (n2 / prime[i])
//	{
//		++cnt[i];
//		n2 = n2 / prime[i];
//	}

//	//����������������С���
// -----------------------------��̵�ʱ��������ִ���
//��Ϊ��cnt[1]��cnt[i]�����
//      cnt[2]  cnt2[i]
//	if (cnt[1] / cnt[2] < ans)
//		ans = cnt[1] / cnt[2];
//}