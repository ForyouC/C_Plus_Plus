#include <stdio.h>


	/*	This function will use you just find one prime number
	#include <math.h>

	bool isPrimeNumber(int x) {
		int end = (int) sqrt(x); // sqrt is inside math function.
		for (int i = 2; i < end; i++) {
			if (x % i == 0) return false;
		}
		return true;
	}

	int main(void) {
		printf("%d", isPrimeNumber(97));
		return 0;
	}
	*/

int number_Erato = 100000;
int a[100001];

void primeNumberSieve() {
	for (int i = 2; i <= number_Erato; i++) {
		a[i] = i;
	}
	for (int i = 2; i <= number_Erato; i++) {
		if (a[i] == 0) continue;
		for (int j = i + i; j <= number_Erato; j += i) {
			a[j] = 0;
		}
	}
	for (int i = 2; i <= number_Erato; i++) {
		if (a[i] != 0) printf("%d ", a[i]);
	}
}

int main_Eratosthenes(void) {
	primeNumberSieve();
	return 0;
}