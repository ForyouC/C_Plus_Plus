#include <stdio.h>

int number_Heap = 9;
int heap[9] = { 7,6,5,8,3,5,9,1,6 };
int check_Heap_cycle = 1; 
int main_Heap_Sort(void) {
	// 먼저 전체 트리 구조를 최대 힙 구조로 바꿉니다.
	for (int i = 1; i < number_Heap; i++) {
		int c = i;
		do {
			//printf("C의 값 = %d \n", c);
			int root = (c - 1) / 2;
			//printf("ROOT의 값 = %d \n", root);
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
	// 크기를 줄여가며 반복적으로 힙을 구성
	for (int i = number_Heap - 1; i >= 0; i--) { // 내 생각에는 코드 분석상 i >= 1; 로 해도 될듯
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
			printf("C의 값 = %d \n", c);
			printf("ROOT의 값 = %d \n", root);
			//자식 중에 더 큰 값을 찾기
			if (heap[c] < heap[c + 1] && c < i - 1) {
				printf("c++ 실행됨 \n");
				c++;
			}
			// 루트 보다 자식이 더 크다면 교환
			if (heap[root] < heap[c] && c < i) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			printf("i의 값 = %d \n", i);
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