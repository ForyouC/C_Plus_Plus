#include <iostream>
#include <vector>

using namespace std;

int number_dfs = 7;
int c_dfs[8];
vector<int> d[15];

void dfs(int x) {
	if (c_dfs[x]) return;
	c_dfs[x] = true;
	cout << x << ' ';
	for (int i = 0; i < d[x].size(); i++) {
		int y = d[x][i];
		dfs(y);
	}
}

int main_Depth(void) {
	d[1].push_back(2);
	d[2].push_back(1);

	d[1].push_back(3);
	d[3].push_back(1);

	d[2].push_back(3);
	d[3].push_back(2);

	d[2].push_back(4);
	d[4].push_back(2);

	d[2].push_back(5);
	d[5].push_back(2);

	d[3].push_back(6);
	d[6].push_back(3);

	d[3].push_back(7);
	d[7].push_back(3);

	d[4].push_back(5);
	d[5].push_back(4);

	d[6].push_back(7);
	d[7].push_back(6);

	dfs(1);

	return 0;
}