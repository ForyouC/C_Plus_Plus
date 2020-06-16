#include<iostream>

using namespace std;

int N, arr[1000001];
int* arr2;

void merge_sanf(int left, int right)
{
	int mid = (left + right) / 2;

	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			arr2[k++] = arr[i++];
		else
			arr2[k++] = arr[j++];
	}

	int tmp = i > mid ? j : i;

	while (k <= right) arr2[k++] = arr[tmp++];

	for (int i = left; i <= right; i++) arr[i] = arr2[i];
}

void partition_sanf(int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		partition_sanf(left, mid);
		partition_sanf(mid + 1, right);
		merge_sanf(left, right);
	}
}

int main_Merge_sort_sanf(void)
{
	scanf_s("%d", &N);
	arr2 = new int[N];
	for (int i = 0; i < N; i++) scanf_s("%d", &arr[i]);

	partition_sanf(0, N - 1);

	for (int i = 0; i < N; i++) printf("%d ", arr[i]);
	return 0;
}