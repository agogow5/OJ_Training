#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;

int a[1001];
int b[1001];

bool check(int n)
{
	int top = 0, k = 1;

	for (int i = 1; i <= n; ++i)
	{
		b[++top] = i;
		while (top && b[top] == a[k])
		{
			k++;
			top--;
		}
	}

	if (top)
		return false;
	else
		return true;
}

int main()
{
	int i, n, t = 0;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
			break;
		if (t)
			printf("\n");
		t++;
		while (scanf("%d", &a[1]))
		{
			if (a[1] == 0)
				break;
			for (i = 2; i <= n; i++)
				scanf("%d", &a[i]);
			if (check(n))
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
}