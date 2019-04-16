#include<iostream>
#include<string>

using namespace std;

#define BITS 10000//假设这里只取4位
#define BIG_INTEGER_LENGTH 4
struct BigInteger {
	int digital[1000];
	int size;//下一个可用的

	friend BigInteger operator+(const BigInteger &b1, const BigInteger &b2);
	friend ostream &operator<<(ostream &bcout, const BigInteger &bi);
};
ostream &operator<<(ostream &bcout, const BigInteger &bi)
{
	/*for (int i = bi.size - 1; i >= 0; --i)*/
		//bcout << bi.digital[i];---------------------------第一次的时候没有考虑到0的输出
		//printf("%04d", bi.digital[i]);--------------------第二次的时候没有考虑到前导0的不要输出
		
	//------------------------------------------------------第三次的时候输出反了
	/*for (int i = bi.size - 1; i > 0; --i)
		printf("%04d", bi.digital[i]);
	printf("%d", bi.digital[0]);*/

	printf("%d", bi.digital[bi.size - 1]);
	for (int i = bi.size - 2; i >= 0; --i)
		printf("%04d", bi.digital[i]);
	
	
	
	return bcout;
}

BigInteger operator+(const BigInteger &b1, const BigInteger &b2)
{
	BigInteger bi;
	int min_size = b1.size > b2.size ? b2.size : b1.size;
	int bonus = 0;//进位
	for (int i = 0; i < min_size; ++i)
	{
		int total_digital = b1.digital[i] + b2.digital[i] + bonus;
		bi.digital[i] = total_digital % BITS;
		bonus = total_digital / BITS;
	}

	//min_size == b1.size - 1    //------------------------------------第一次这里写错了
	if (min_size == b1.size )//b2比较长
	{
		for (int i = b1.size; i < b2.size; ++i)
		{
			int total_digital = b2.digital[i] + bonus;
			bi.digital[i] = total_digital % BITS;
			bonus = total_digital / BITS;
		}
		bi.size = b2.size;
		if (bonus)
		{
			bi.size += 1;
			bi.digital[b2.size] = bonus;
		}
		
	}
	else if (min_size == b2.size )//b1比较长
	{
		for (int i = b2.size; i < b1.size; ++i)
		{
			int total_digital = b1.digital[i] + bonus;
			bi.digital[i] = total_digital % BITS;
			bonus = total_digital / BITS;
		}
		bi.size = b1.size;
		if (bonus)
		{
			bi.size += 1;
			bi.digital[b1.size] = bonus;
		}
	}
	else//一样长
	{
		bi.size = b2.size;
		if (bonus)
		{
			bi.size += 1;
			bi.digital[b2.size] = bonus;
		}
	}
	return bi;
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
	string str1, str2;
	cin >> str1 >> str2;
	BigInteger b1 = String2BigInteger(str1), b2 = String2BigInteger(str2), bi;
	bi = b1 + b2;
	cout << bi << endl;

	cin >> str1;
	return 0;
}