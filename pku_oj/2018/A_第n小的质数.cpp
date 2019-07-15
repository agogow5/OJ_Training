#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(unsigned int num)
{
	unsigned int bound = (unsigned int)(sqrt(num) + 1);
	for (unsigned int i = 2; i <= bound; ++i)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}


int main()
{
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << 2 << endl;
		return 0;
	}

	int cnt = 1;
	for (unsigned int i = 3; i < 1000000000; ++i)
	{
		if (isPrime(i))
		{
			cnt++;
			if (cnt == n)
			{
				cout << i << endl;
				break;
			}
		}
	}

	return 0;
}