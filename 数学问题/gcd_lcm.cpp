#include<iostream>

using namespace std;

//���ģ�����շת�����
//a,b�����Լ�����Ա�� b�� a%b�����Լ�����Ӷ����ϼ�С��ģ
int gcd(int a, int b)
{
	while (b != 0)
	{
		int tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << "gcd: " << gcd(a, b) << endl;
	cout << "lcm: " << lcm(a, b) << endl;

	return 0;
}