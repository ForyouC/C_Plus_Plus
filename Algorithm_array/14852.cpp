#include <stdio.h>

	// So long time taken
	/*int d_14852[1000001];

	int dp_14852(int x) {
		if (x == 0) return 1;
		if (x == 1) return 2;
		if (x == 2) return 7;
		if (d_14852[x] != 0) return d_14852[x];
		int result = 3 * dp_14852(x - 2) + 2 * dp_14852(x - 1);
		for (int i = 3; i <= x; i++) {
			result += (2 * dp_14852(x - i));
		}
		return d_14852[x] = result % 1000000007;
	}*/
	long long int d_14852[1000001][2];

	long long int dp_14852(int x) {
		d_14852[0][0] = 1;
		d_14852[1][0] = 2;
		d_14852[2][0] = 7;
		for (int i = 3; i <= x; i++) {
			d_14852[i][1] = (d_14852[i - 1][1] + d_14852[i - 3][0]) % 1000000007;
			d_14852[i][0] = (3 * d_14852[i - 2][0] + 2 * d_14852[i - 1][0] + 2 * d_14852[i][1]) % 1000000007;
		}
		return d_14852[x][0];
	}

int main_14852(void) {
	int x;
	scanf_s("%d", &x);
	printf("%lld", dp_14852(x));
	return 0;
}