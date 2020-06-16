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
	if (start >= end) { // ���Ұ� 1���� ���
		return;
	}

	int key = start; // Ű�� ù��° ���� 
	int i = start + 1; // ���� ��� ����
	int j = end; // ������ ��� ����
	int temp;
	//printf("%d ", end);

	while (i <= j) { // ������ �� ���� �ݺ�
		check++;
		printf("/// This is check (%d) ///\n", check);
		printf("// This is start (%d) \n", start);
		printf("// This is end (%d) \n", end);
		while (data[i] <= data[key] && i <= end) { // Ű ������ ū ���� ���� ������
			printf("/ This is i (%d) \n", i);
			printf("/ This is data[i] (%d) \n", data[i]);
			i++;
		}
		while (data[j] >= data[key] && j > start) { // Ű ������ ���� ���� ���� ������
			printf("/ This is j (%d) \n", j);
			printf("/ This is data[j] (%d) \n", data[j]);
			j--;
			
		}
		if (i > j) {	// ���� ������ ���¸� Ű ���� ��ü
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else {		// �������� �ʾ����� �ΰ��� ���� ��ü.
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