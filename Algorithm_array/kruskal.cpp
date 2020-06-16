#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int getParent_kruskal(int parent[], int x) {
	//printf("%d\n", x);
	if (parent[x] == x) return x;
	return getParent_kruskal(parent, parent[x]);
}

int unionParent_kruskal(int parent[], int a, int b) {
	a = getParent_kruskal(parent, a);
	b = getParent_kruskal(parent, b);
	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
	return 0;
}

int findParent_kruskal(int parent[], int a, int b) {
	a = getParent_kruskal(parent, a);
	b = getParent_kruskal(parent, b);
	//printf("%d\n", b);
	if (a == b) return 1;
	return 0;
}

class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	/*bool operator < (Edge &haha) {
		return this->distance < haha.distance;
	}*/
};

struct less_than_distance {
	/*inline bool operator() (const Edge& struct1, const Edge& struct2) {
		return (struct1.distance < struct2.distance);
	}*/
	bool operator() (const Edge& struct1, const Edge& struct2) {
		return (struct1.distance < struct2.distance);
	}
};

int main_kruskal(void) {
	const int n = 7;
	int m = 11;
	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));

	// 간선의 비용을 기준으로 오름차순 정렬
	sort(v.begin(), v.end(), less_than_distance());

	// 각 정점이 포함된 그래프가 어디인지 저장
	int parent[n];
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	int sum = 0;
	//printf("%d\n", v[0].node[1] - 1);
	for (int i = 0; i < v.size(); i++) {
		// 사이클이 발생하지 않는 경우 그래프에 포함
		if (!findParent_kruskal(parent, v[i].node[0] - 1, v[i].node[1] - 1)) {
			sum += v[i].distance;
			unionParent_kruskal(parent, v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}

	printf("%d\n", sum);
	return 0;
}