#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare(pair<string, pair<int, int> > a,
	pair<string, pair<int, int> > b) {
	if (a.second.first == b.second.first) {
		return a.second.second > b.second.second;
	}
	else {
		return a.second.first > b.second.first;
	}
}


int main_STL_Sort_Pair(void) {
	vector<pair< string, pair<int, int> > > v;
	v.push_back(pair< string, pair<int, int> >("ÇãÀç¿ø", pair<int, int>(100, 19980223)));
	v.push_back(pair< string, pair<int, int> >("Á¦½ÅÈñ", pair<int, int>(95, 19990223)));
	v.push_back(pair< string, pair<int, int> >("³ªµ¿ºó", pair<int, int>(95, 19960223)));

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ';
	}
	return 0;
}
