#include<iostream>
#include<string>

using namespace std;

#define BITS 10000//假设这里只取4位
#define BIG_INTEGER_LENGTH 4
struct BigInteger {
	int digital[1000];
	int size;//下一个可用的
	BigInteger();//初始化
	friend BigInteger operator+(const BigInteger &b1, const BigInteger &b2);
	friend ostream &operator<<(ostream &bcout, const BigInteger &bi);
	friend BigInteger operator*(const BigInteger &b1, int integer);
	friend BigInteger operator/(const BigInteger &b1, int integer);
	friend int operator%(const BigInteger &b1, int integer);
};

BigInteger::BigInteger()
{
	for (int i = 0; i < 1000; ++i)
		digital[i] = 0;
	size = 0;
	return;
}
ostream &operator<<(ostream &bcout, const BigInteger &bi)
{
	/*for (int i = bi.size - 1; i >= 0; --i)*/
		//bcout << bi.digital[i];---------------------------第一次的时候没有考虑到0的输出
		//printf("%04d", bi.digital[i]);--------------------第二次的时候没有考虑到前导0的不要输出

	printf("%d", bi.digital[bi.size - 1]);
	for (int i = bi.size - 2; i >= 0; --i)
		printf("%04d", bi.digital[i]);


	return bcout;
}

BigInteger operator+(const BigInteger &b1, const BigInteger &b2)
{
	BigInteger bi;

	int bonus = 0;//进位

	for (int i = 0; i < b1.size || i < b2.size; ++i)
	{
		int total_digital = b1.digital[i] + b2.digital[i] + bonus;
		bi.digital[i] = total_digital % BITS;
		bonus = total_digital / BITS;
	}

	bi.size = b1.size > b2.size ? b1.size : b2.size;
	if (bonus)
	{
		bi.digital[bi.size] = bonus;
		bi.size += 1;
	}

	return bi;
}

BigInteger operator*(const BigInteger &b1, int integer)
{
	BigInteger bi;
	int bonus = 0;
	for (int i = 0; i < b1.size; ++i)
	{
		int total_digital = b1.digital[i] * integer + bonus;
		bi.digital[i] = total_digital % BITS;
		bonus = total_digital / BITS;
	}
	bi.size = b1.size;
	if (bonus)
	{
		bi.size += 1;
		bi.digital[b1.size] = bonus;
	}

	return bi;
}

BigInteger operator/(const BigInteger &b1, int integer)
{
	BigInteger bi;
	int remainder = 0;
	for (int i = b1.size - 1; i >= 0; --i)
	{
		bi.digital[i] = (remainder * BITS + b1.digital[i]) / integer;
		remainder = (remainder * BITS + b1.digital[i]) % integer;
	}
	for (int i = 0; i < 1000; ++i)
		if (bi.digital[i] != 0)
			bi.size = i + 1;

	return bi;
}

int operator%(const BigInteger &b1, int integer)
{
	int remainder = 0;
	for (int i = b1.size - 1; i >= 0; --i)
		remainder = (remainder * BITS + b1.digital[i]) % integer;
	
	return remainder;
}


BigInteger String2BigInteger(const string &input_str)
{
	BigInteger bi;
	string str = input_str;
	bi.size = 0;
	while (str.length() >= 4)
	{
		//string digtal(str.end() - 4, str.end() - 1);-----------------------第一次这里写错了
		string digtal(str.end() - 4, str.end());
		bi.digital[bi.size++] = std::stoi(digtal);
		str = string(str.begin(), str.end() - 4);
	}
	if (str.length() > 0)
		bi.digital[bi.size++] = std::stoi(str);

	return bi;
}

int main()
{
	int N, M;
	cin >> M >> N;
	BigInteger bi, a, b;
	b.digital[0] = 1;
	b.size = 1;

	//从M进制转10进制高精度数据
	string str;
	cin >> str;
	int temporal = 0;
	for (auto iter = str.rbegin(); iter != str.rend(); ++iter)
	{
		int t;
		if (*iter >= '0' && *iter <= '9')
			t = *iter - '0';
		else
			t = *iter - 'A' + 10;
		a = a + b * t;
		b = b * M;
	}

	cout << a << endl;
	int size = 0;
	char ans[1000];

	while (a.size != 0)
	{
		int t = a % N;
		ans[size++] = t >= 10 ? 'a' + t - 10 : '0' + t;
		a = a / N;
	}
	for (int i = size - 1; i >= 0; --i)
		cout << ans[i];

	return 0;
}
//25 17
//35BAJLA432ABCAC