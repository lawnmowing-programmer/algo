#include <stdio.h>

static int arr[100];

void insert_data(int i, int j, int k);
void put_arr(int n);

int main(void)
{
	int n, m;
	int i, j, k;
	int idx;

	scanf("%d %d", &n, &m);
	for (idx = 0; idx < m; idx++)
	{
		scanf("%d %d %d", &i, &j, &k);
		insert_data(i, j, k);
	}
	put_arr(n);
	return 0;
}

void insert_data(int i, int j, int k)
{
	int idx;

	for (idx = i - 1; idx < j; idx++)
	{
		arr[idx] = k;
	}
}

void put_arr(int n)
{
	int idx;

	for (idx = 0; idx < n - 1; idx++)
	{
		printf("%d ", arr[idx]);
	}
	printf("%d\n", arr[idx]);
}
