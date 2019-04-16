#include<iostream>
#include<string>

using namespace std;

#define BITS 10000//��������ֻȡ4λ
#define BIG_INTEGER_LENGTH 4
struct BigInteger {
	int digital[1000];
	int size;//��һ�����õ�

	friend BigInteger operator+(const BigInteger &b1, const BigInteger &b2);
	friend ostream &operator<<(ostream &bcout, const BigInteger &bi);
	friend BigInteger operator*(const BigInteger &b1, int integer);
};
ostream &operator<<(ostream &bcout, const BigInteger &bi)
{
	/*for (int i = bi.size - 1; i >= 0; --i)*/
		//bcout << bi.digital[i];---------------------------��һ�ε�ʱ��û�п��ǵ�0�����
		//printf("%04d", bi.digital[i]);--------------------�ڶ��ε�ʱ��û�п��ǵ�ǰ��0�Ĳ�Ҫ���

	printf("%d", bi.digital[bi.size - 1]);
	for (int i = bi.size - 2; i >= 0; --i)
		printf("%04d", bi.digital[i]);


	return bcout;
}

BigInteger operator+(const BigInteger &b1, const BigInteger &b2)
{
	BigInteger bi;
	int min_size = b1.size > b2.size ? b2.size : b1.size;
	int bonus = 0;//��λ
	for (int i = 0; i < min_size; ++i)
	{
		int total_digital = b1.digital[i] + b2.digital[i] + bonus;
		bi.digital[i] = total_digital % BITS;
		bonus = total_digital / BITS;
	}

	//min_size == b1.size - 1    //------------------------------------��һ������д����
	if (min_size == b1.size)//b2�Ƚϳ�
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
	else if (min_size == b2.size)//b1�Ƚϳ�
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
	else//һ����
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

BigInteger String2BigInteger(const string &input_str)
{
	BigInteger bi;
	string str = input_str;
	bi.size = 0;
	while (str.length() >= 4)
	{
		//string digtal(str.end() - 4, str.end() - 1);-----------------------��һ������д����
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
	int N;
	cin >> N;

	//---------------------------------------------------����������ʵ���ǿ���0��������������������Ҳ���ˡ�
	BigInteger bi = String2BigInteger(std::to_string(1));
	
	for (int i = 1; i <= N; ++i)
		bi = bi * i;
	cout << bi << endl;

	string str1;
	cin >> str1;
	return 0;
}