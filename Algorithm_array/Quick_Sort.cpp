#include <stdio.h>

int number_Quick = 10;
int array[10] = { 3, -2, -1, 4, 5, 9, 6, 10, 2, 1 };
//				{ 3, -2, -1, 1, 5, 9, 6, 10, 2, 4 }; check 1;
//				{ 3, -2, -1, 1, 2, 9, 6, 10, 5, 4 }; check 2;
//				{ 2, -2, -1, 1, 3, 9, 6, 10, 5, 4 }; check 3;
//				{ 1, -2, -1, 2, 3, 9, 6, 10, 5, 4 }; check 4;
//				{ -1, -2, 1, 2, 3, 9, 6, 10, 5, 4 }; check 5;
//				{ -2, -1, 1, 2, 3, 9, 6, 10, 5, 4 }; check 6;
int check = 0;
int check2 = 0;

void quickSort(int data[], int start, int end) {
	if (start >= end) { // 원소가 1개인 경우
		return;
	}

	int key = start; // 키는 첫번째 원소 
	int i = start + 1; // 왼쪽 출발 지점
	int j = end; // 오른쪽 출발 지점
	int temp;
	//printf("%d ", end);

	while (i <= j) { // 엇갈릴 때 까지 반복
		check++;
		printf("/// This is check (%d) ///\n", check);
		printf("// This is start (%d) \n", start);
		printf("// This is end (%d) \n", end);
		while (data[i] <= data[key] && i <= end) { // 키 값보다 큰 값을 만날 때까지
			printf("/ This is i (%d) \n", i);
			printf("/ This is data[i] (%d) \n", data[i]);
			i++;
		}
		while (data[j] >= data[key] && j > start) { // 키 값보다 작은 값을 만날 떄까지
			printf("/ This is j (%d) \n", j);
			printf("/ This is data[j] (%d) \n", data[j]);
			j--;
			
		}
		if (i > j) {	// 현재 엇갈린 상태면 키 값과 교체
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else {		// 엇갈리지 않았으니 두개의 값을 교체.
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}
		for (int i = 0; i < number_Quick; i++) {
			printf("%d ", array[i]);
		}
		printf("\n");
	}
	check2++;
	printf("///// This is check2 (%d) ///////\n", check2);
	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}

int main_quick_sort(void) {
	quickSort(array, 0, number_Quick - 1);
	for (int i = 0; i < number_Quick; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}