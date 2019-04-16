#include<iostream>

using namespace std;

//核心：利用辗转相除法
//a,b的最大公约数可以变成 b与 a%b的最大公约数，从而不断减小规模
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