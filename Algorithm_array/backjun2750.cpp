# include <stdio.h>

int array_2750[1001];

int main_2750(void) {
	int number, i, j, min, index, temp;
	scanf_s("%d", &number);
	for (i = 0; i < number; i++) {
		scanf_s("%d", &array_2750[i]);
	}
	for (i = 0; i < number; i++) {
		min = 1001;
		for (j = i; j < number; j++) {
			if (min > array_2750[j]) {
				min = array_2750[j];
				index = j;
			}
		}
		printf("index = %d\n", index);
		printf("index °ª = %d\n", array_2750[index]);
		temp = array_2750[i];
		array_2750[i] = array_2750[index];
		array_2750[index] = temp;
		printf("temp = %d\n", i);
		printf("temp °ª = %d\n", temp);
	}
	for (i = 0; i < number; i++) {
		printf("%d\n", array_2750[i]);
	}
	return 0;
}