#include <stdio.h>

int number_Heap = 9;
int heap[9] = { 7,6,5,8,3,5,9,1,6 };
int check_Heap_cycle = 1; 
int main_Heap_Sort(void) {
	// ���� ��ü Ʈ�� ������ �ִ� �� ������ �ٲߴϴ�.
	for (int i = 1; i < number_Heap; i++) {
		int c = i;
		do {
			//printf("C�� �� = %d \n", c);
			int root = (c - 1) / 2;
			//printf("ROOT�� �� = %d \n", root);
			if (heap[root] < heap[c]) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		}while(c != 0);
	}
	for (int i = 0; i < number_Heap; i++) {
		//printf("%d ", heap[i]);
		// { 9 7 8 6 3 5 5 1 6}
	}
	// ũ�⸦ �ٿ����� �ݺ������� ���� ����
	for (int i = number_Heap - 1; i >= 0; i--) { // �� �������� �ڵ� �м��� i >= 1; �� �ص� �ɵ�
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int c = 1;
		printf("//////////////check_Heap_cycle !!  %d \n", check_Heap_cycle);
		for (int i = 0; i < number_Heap; i++) {
			printf("%d ", heap[i]);
		}
		printf("\n ");
		do {
			c = 2 * root + 1;
			printf("C�� �� = %d \n", c);
			printf("ROOT�� �� = %d \n", root);
			//�ڽ� �߿� �� ū ���� ã��
			if (heap[c] < heap[c + 1] && c < i - 1) {
				printf("c++ ����� \n");
				c++;
			}
			// ��Ʈ ���� �ڽ��� �� ũ�ٸ� ��ȯ
			if (heap[root] < heap[c] && c < i) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			printf("i�� �� = %d \n", i);
			root = c;
		} while (c < i);
		for (int i = 0; i < number_Heap; i++) {
			printf("%d ", heap[i]);
		}
		printf("\n ");
		check_Heap_cycle++;
	}
	for (int i = 0; i < number_Heap; i++) {
		printf("%d ", heap[i]);
	}
	return 0;
}