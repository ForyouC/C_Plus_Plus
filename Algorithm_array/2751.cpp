# include <stdio.h>

int number_2751, data[1000001];

void quickSort(int* data, int start, int end) {
	if (start >= end) {
		return;
	}
	int key = start;
	int i = start + 1, j = end, temp;
	while (i <= j) {
		while (data[i] <= data[key] && i <= end) {
			i++;
		}
		while (data[j] >= data[key] && j > start) {
			j--;
		}
		if (i > j) {
			temp = data[j];
			data[j] = data[key];
			data[key] = temp;
		}
		else {
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}

int main_2751(void) {
	scanf_s("%d", &number_2751);
	for (int i = 0; i < number_2751; i++) {
		scanf_s("%d", &data[i]);
	}
	quickSort(data, 0, number_2751 - 1);
	for (int i = 0; i < number_2751; i++) {
		printf("%d\n", data[i]);
	}
	return 0;
}