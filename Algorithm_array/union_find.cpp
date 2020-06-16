#include <stdio.h>

int getParent(int parent[], int x) {
	printf("%d\n", x);
	if (parent[x] == x) return x;
	return getParent(parent, parent[x]);
}

int unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
	return 0;
}

int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	//printf("%d\n", b);
	if (a == b) return 1;
	return 0;
}

int main_union(void) {
	int parent[11];
	for (int i = 1; i <= 10; i++) {
		parent[i] = i;
	}
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	//unionParent(parent, 4, 5);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);
	//printf("1�� 5�� ����Ǿ� �ֳ���? %d\n", findParent(parent, 1, 5));
	printf("1�� 7�� �˾ƺ���.\n");
	printf("1�� 7�� ����Ǿ� �ֳ���? %d\n", findParent(parent, 1, 7));
	printf("1�� 5�� ��ġ��.\n");
	unionParent(parent, 1, 5);
	//printf("1�� 5�� ����Ǿ� �ֳ���? %d\n", findParent(parent, 1, 5));
	//printf("1�� 4�� ����Ǿ� �ֳ���? %d\n", findParent(parent, 1, 4));
	printf("2�� 7�� �˾ƺ���.\n");
	printf("2�� 7�� ����Ǿ� �ֳ���? %d\n", findParent(parent, 2, 7));
	return 0;
}