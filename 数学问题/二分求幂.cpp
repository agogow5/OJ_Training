#include<iostream>

using namespace std;

//���ģ����ݴ�Bת��2���ơ�


//ռ�ù���ռ�
//int main()
//{
//	int A, B;
//	cin >> A >> B;
//	//10000 < 2^15
//	int A_base[15];
//	//ֻȡ��λ��
//	A_base[0] = A % 1000;
//	for (int i = 1; i < 15; ++i)
//		/*A_base[i] = (A_base[i - 1] * A) % 1000;*/// --------------------------- ������������������������� ������A��ˡ�
//		A_base[i] = (A_base[i - 1] * A_base[i - 1]) % 1000;
//
//	//��Bת��2����
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