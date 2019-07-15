#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

long long int ans = 0;
int a[5000000];
void mergesort(int *arr, int le, int ri)
{
	if (le == ri)
		return;
	int mid = (le + ri) / 2;
	mergesort(arr, le, mid);
	mergesort(arr, mid + 1, ri);

	int i = le, j = mid + 1, k = 0, t = le;
	int *pt = new int[ri - le + 2];
	while (i <= mid && j <= ri)
	{
		if (arr[i] <= arr[j])
		{
			pt[k++] = arr[i++];
		}
		else
		{
			while (arr[t] <= 2 * arr[j] && t < mid) t++;
			if (arr[t] > 2 * arr[j])
				ans += mid - t + 1;

			pt[k++] = arr[j++];
		}
	}

	while (i <= mid)
	{
		pt[k++] = arr[i++];
	}


	while (j <= ri)
		pt[k++] = arr[j++];

	for (int p = 0; p <= ri - le; ++p)
		arr[le + p] = pt[p];

	delete[]pt;
}



int main()
{
	int n;
	scanf("%d", &n);
	for (int k = 1; k <= n; k++) scanf("%d", &a[k]);
	mergesort(a, 1, n);
	printf("%lld", ans);

	return 0;
}

