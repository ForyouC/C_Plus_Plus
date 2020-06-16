#include <stdio.h>
#include <stdlib.h>

int number_Merge = 8;
int sorted[100];  //정렬 배열은 반드시 전역 변수
int count_Merge = 1;
int count_Merge2 = 1;
int count_Merge3 = 1;
int count_Merge4 = 1;


void merge(int* a, int left, int right)
{

	int mid = (left + right) / 2;

	int i = left;
	int j = mid + 1;
	printf("count_Merge의 값은 = %d \n", count_Merge++);
	printf("left의 값은 = %d \n", left);
	printf("mid의 값은 = %d \n", mid);
	printf("right의 값은 = %d \n", right);
	int k = left;
	while (i <= mid && j <= right)
	{
		if (a[i] <= a[j])
			sorted[k++] = a[i++];
		else
			sorted[k++] = a[j++];
	}

	if (i > mid) {
		for (int t = j; t <= right; t++) {
			sorted[k++] = a[t];
		}
	}
	else {
		for (int t = i; t <= right; t++) {
			sorted[k++] = a[t];
		}
	}

	for (int i = left; i <= right; i++) a[i] = sorted[i];
}

void mergeSort_2(int a[], int left, int right) {
	int middle;
	if (left < right) {
		middle = (left + right) / 2;
		printf("count_Merge2의 값은 = %d left 의 값은 = %d right 의 값은 = %d middle 의 값은 = %d\n", count_Merge2++, left, right, middle);
		mergeSort_2(a, left, middle);
		printf("count_Merge3의 값은 = %d left 의 값은 = %d right 의 값은 = %d middle 의 값은 = %d\n", count_Merge3++, left, right, middle);
		mergeSort_2(a, middle + 1, right);
		printf("count_Merge4의 값은 = %d left 의 값은 = %d right 의 값은 = %d middle 의 값은 = %d\n", count_Merge4++, left, right, middle);
		merge(a, left, right);
	}
}

void main_Merge_Sort(void) {
	int array_merge[] = { 300, -200, -100, 400, 500, 900, 600, 1000, 5, 50, 450, 925, 548, 211, 148, 26 };
	mergeSort_2(array_merge, 0, 15);
	for (int i = 0; i < 16; i++) {
		printf("%d ", array_merge[i]);
	}
}