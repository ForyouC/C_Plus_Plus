# include <stdio.h>

int array_2752[3];

int main_2752(void) {
	int i, j, min, index, temp;
	for (i = 0; i < 3; i++) {
		scanf_s("%d", &array_2752[i]);
	}
	for (i = 0; i < 3; i++) {
		min = 100000001;
		for (j = i; j < 3; j++) {
			if (min > array_2752[j]) {
				min = array_2752[j];
				index = j;
			}
		}
		printf("index = %d\n", index);
		printf("index °ª = %d\n", array_2752[index]);
		temp = array_2752[i];
		array_2752[i] = array_2752[index];
		array_2752[index] = temp;
		printf("temp = %d\n", i);
		printf("temp °ª = %d\n", temp);
	}
	for (i = 0; i < 3; i++) {
		printf("%d ", array_2752[i]);
	}
	return 0;
}