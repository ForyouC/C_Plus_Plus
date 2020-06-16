#pragma once

void main(void) {
	vector<pair< string, pair<int, int> > > v;
	v.push_back(pair< string, pair<int, int> >("허재원", 100, 19980223));
	v.push_back(pair<int, string>(95, "나동빈"));
	v.push_back(pair<int, string>(99, "제신희"));

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].fi << ' ';
	}
