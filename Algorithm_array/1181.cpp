#include <iostream>
#include <algorithm>

using namespace std;

string a[20000];
int n_1181;

bool compare(string a, string b) {
	// 길이가 짧은 순서 우선
	if (a.length() < b.length()) {
		return 1;
	}
	else if (a.length() > b.length()) {
		return 0;
	}
	//길이가 같은 경우라면
	else {
		return a < b; // 사전순으로 정렬
	}
}

int main_1181(void) {
	cin >> n_1181;
	for (int i = 0; i < n_1181; i++) {
		cin >> a[i];
	}
	sort(a, a + n_1181, compare);
	for (int i = 0; i < n_1181; i++) {
		if (i > 0 && a[i] == a[i - 1]) {
			continue;
		}
		else {
			cout << a[i] << '\n';
		}
	}
	return 0;
}