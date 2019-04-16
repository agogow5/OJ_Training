#include<iostream>

using namespace std;

//核心：把幂次B转成2进制。


//占用过多空间
//int main()
//{
//	int A, B;
//	cin >> A >> B;
//	//10000 < 2^15
//	int A_base[15];
//	//只取三位数
//	A_base[0] = A % 1000;
//	for (int i = 1; i < 15; ++i)
//		/*A_base[i] = (A_base[i - 1] * A) % 1000;*/// --------------------------- 这里出错！！！！！！！！！！ 不是与A相乘。
//		A_base[i] = (A_base[i - 1] * A_base[i - 1]) % 1000;
//
//	//把B转成2进制
//	int B_base[15];
//	int t = B;
//	for (int i = 0; i < 15; ++i)
//	{
//		if (t == 0)
//		{
//			B_base[i] = 0;
//			continue;
//		}
//		B_base[i] = t % 2;
//		t = t / 2;	
//	}
//	
//	int ans = 1;
//	for (int i = 0; i < 15; ++i)
//	{
//		if (B_base[i])
//			ans = (ans * A_base[i]) % 1000;
//	}
//	
//	
//	cout << ans << endl;
//
//	return 0;
//}

int main()
{
	int A, B;
	cin >> A >> B;

	int ans = 1;
	while (B)
	{
		if (B % 2)
		{
			ans = ans * A;
			ans = ans % 1000;
		}

		B = B / 2;
		A = (A * A) % 1000;
	}
	cout << ans << endl;

	return 0;
}