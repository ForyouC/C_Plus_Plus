#include <iostream>

using namespace std;

int n_10989;
int a_10989[10001];

int main_10989(void) {
	scanf_s("%d", &n_10989);
	for (int i = 0; i < n_10989; i++) {
		int x;
		scanf_s("%d", &x);
		a_10989[x]++;
	}
	for (int i = 0; i < 10001; i++) {
		while (a_10989[i] != 0) {
			printf("%d\n", i);
			a_10989[i]--;
		}
	}
	return 0;
}