#include <stdio.h>

int d[100];		//This is very important if you didn't write this line your code take very long time.

int dp(int x) {
	if (x == 1) return 1;
	if (x == 2) return 1;
	if (d[x] != 0) return d[x];		//This is very important if you didn't write this line your code take very long time.
	return d[x] = dp(x - 1) + dp(x - 2);
}

int main_Dynamic(void) {
	printf("%d", dp(30));
	return 0;
}