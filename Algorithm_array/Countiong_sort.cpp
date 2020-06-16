#include <stdio.h>

int main_counting(void) {
	int temp;
	int count[5];
	int array[30] = { 1,3,2,4,2,5,4,2,3,1,4,5,1,3,5,4,1,4,1,4,5,3,2,1,4,5,1,2,3,1 };

	for (int i = 0; i < 5; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < 30; i++) {
		count[array[i] - 1]++;
	}
	for (int i = 0; i < 5; i++) {
		if (count[i] != 0) {
			for (int j = 0; j < count[i]; j++) {
				printf("%d", i + 1);
			}
		}
	}
	return 0;
}