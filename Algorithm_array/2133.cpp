#include <stdio.h>

int d_2133[1001];

int dp_2133(int x) {
	if (x == 0) { return 1; }
	if (x == 1) return 0;
	if (x == 2) return 3;
	if (d_2133[x] != 0) return d_2133[x];
	int result = 3 * dp_2133(x - 2);
	for (int i = 3; i <= x; i++) {
		if (i % 2 == 0) {
			result += 2 * dp_2133(x - i);
		}
	}
	return d_2133[x] = result;
}

int main_2133(void) {
	int x;
	scanf_s("%d", &x);
	printf("%d", dp_2133(x));
	return 0;
}