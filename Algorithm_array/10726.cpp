#include <stdio.h>

int d_10726[1001];

int dp_10726(int x) {
	if (x == 1) return 1;
	if (x == 2) return 2;
	if (d_10726[x] != 0) return d_10726[x];
	return d_10726[x] = (dp_10726(x - 1) + dp_10726(x - 2)) % 10007;
}

int main_10726(void) {
	int x;
	scanf_s("%d", &x);
	printf("%d", dp_10726(x));
	return 0;
}