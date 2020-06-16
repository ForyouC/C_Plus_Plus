#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string a_1431[20000];
int n_1431;

int getSum_1431(string a) {
	int length = a.length(), sum = 0;
	for (int i = 0; i < length; i++) {
		//숫자인 경우에만 더합니다.
		if (a[i] - '0' <= 9 && a[i] - '0' >= 0) {
			sum += a[i] - '0';
		}
	}
	return sum;
}

bool compare_1431(string a, string b) {
	// 길이가 짧은 순서 우선
	if (a.length() < b.length()) {
		return 1;
	}
	else if (a.length() > b.length()) {
		return 0;
	}
	//길이가 같은 경우라면
	else {
		int aSum = getSum_1431(a);
		int bSum = getSum_1431(b);
		// 글자에 포합된 숫자의 합이 다르다면
		if (aSum != bSum) {
			return aSum < bSum;
		}
		else {
			return a < b;
		}
	}
}

int main_1431(void) {
	cin >> n_1431;
	for (int i = 0; i < n_1431; i++) {
		cin >> a_1431[i];
	}
	sort(a_1431, a_1431 + n_1431, compare_1431);
	for (int i = 0; i < n_1431; i++) {
		cout << a_1431[i] << '\n';
	}
	return 0;
}