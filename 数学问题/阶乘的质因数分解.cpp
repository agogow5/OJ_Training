#include<iostream>

using namespace std;


//TODO: int 最大值

int prime[1000];//存储1000以内的素数
bool mask[1001];//用来标记 0 - 1000 是否为素数
int prime_size;//1001以内素数个数
int cnt[1001];//n!的质因数分解
int cnt2[1001];//a的质因数分解

void init()
{
	prime_size = 0;
	for (int i = 0; i <= 1000; ++i)
		mask[i] = false;

	//注意：这里从2开始。
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

	//先初始化，求出1000内的所有素数
	init();
	//设置为0
	for (int i = 0; i < 1001; ++i)
	{
		cnt[i] = 0;
		cnt2[i] = 0;
	}

	//求n!的质因数分解
	for (int i = 0; i < prime_size; ++i)
	{
		int tmp = n1;
		while (tmp)
		{
			cnt[i] += tmp / prime[i];
			tmp = tmp / prime[i];
		}
	}

	//因为要求最小值，这里的初始值为INT_MAX
	int ans = INT_MAX;
	//求a的质因数分解，同时求出最小的k
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

//	//挑出满足条件的最小情况
// -----------------------------编程的时候，这里出现错误。
//因为把cnt[1]与cnt[i]搞混了
//      cnt[2]  cnt2[i]
//	if (cnt[1] / cnt[2] < ans)
//		ans = cnt[1] / cnt[2];
//}