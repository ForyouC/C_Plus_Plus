#pragma once

void main(void) {
	vector<pair< string, pair<int, int> > > v;
	v.push_back(pair< string, pair<int, int> >("�����", 100, 19980223));
	v.push_back(pair<int, string>(95, "������"));
	v.push_back(pair<int, string>(99, "������"));

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].fi << ' ';
	}
