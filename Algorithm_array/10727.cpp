#include <stdio.h>

int d_10727[1001];

int dp_10727(int x) {
	if (x == 1) return 1;
	if (x == 2) return 3;
	if (d_10727[x] != 0) return d_10727[x];
	return d_10727[x] = dp_10727(x - 1) + 2 * dp_10727(x - 2) % 10007;
}

int main_10727(void) {
	int x;
	scanf_s("%d", &x);
	printf("%d", dp_10727(x));
	return 0;
}