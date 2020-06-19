#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number_Dij_g = 6;
int INF_Dij_g = 10000000;

vector<pair<int, int> > a_Dij_g[7]; //  Cost information;
int d_Dij_g[7]; //  most Shortest cost


void dijkstra_g(int start) {
	d_Dij_g[start] = 0;
	priority_queue<pair<int, int> > pq; //This is heap structure.
	pq.push(make_pair(start, 0));
	// It will take care of in the nearest order.
	while (!pq.empty()) {
		int current = pq.top().first;
		printf("current = %d\n", current);
		// after converting numbers to negative ones, It will take care of in the shortest order.
		int distance = pq.top().second;
		//printf("distance = %d\n", distance);
		pq.pop();
		// If It's not shortest, we skip that.
		if (d_Dij_g[current] < distance) continue;
		for (int i = 0; i < a_Dij_g[current].size(); i++) {
			//  Selected near nodes
			int next = a_Dij_g[current][i].first;
			//printf("next = %d\n", next);
			//  The cost of going through the selected node to the adjacent node.
			int nextDistance = distance + a_Dij_g[current][i].second;
			//printf("nextDistance = %d\n", nextDistance);
			//	Replace if cheaper than the existing minimum cost.
			if (nextDistance < d_Dij_g[next]) {
				//printf("next = %d\n", next);
				//printf("nextDistance = %d\n", nextDistance);
				//printf("d_Dij_g = %d\n", d_Dij_g[next]);
				d_Dij_g[next] = nextDistance;
				pq.push(make_pair(next, nextDistance));
			}
		}
	}
}

int main_Dij_good(void) {
	//  By default, if not connected, the cost is infinite.
	for (int i = 1; i <= number_Dij_g; i++) {
		d_Dij_g[i] = INF_Dij_g;
	}



	a_Dij_g[1].push_back(make_pair(2, 2));
	a_Dij_g[1].push_back(make_pair(3, 5));
	a_Dij_g[1].push_back(make_pair(4, 1));

	a_Dij_g[2].push_back(make_pair(1, 2));
	a_Dij_g[2].push_back(make_pair(3, 3));
	a_Dij_g[2].push_back(make_pair(4, 2));

	a_Dij_g[3].push_back(make_pair(1, 5));
	a_Dij_g[3].push_back(make_pair(2, 3));
	a_Dij_g[3].push_back(make_pair(4, 3));
	a_Dij_g[3].push_back(make_pair(5, 1));
	a_Dij_g[3].push_back(make_pair(6, 5));

	a_Dij_g[4].push_back(make_pair(1, 1));
	a_Dij_g[4].push_back(make_pair(3, 2));
	a_Dij_g[4].push_back(make_pair(3, 3));
	a_Dij_g[4].push_back(make_pair(5, 1));

	a_Dij_g[5].push_back(make_pair(3, 1));
	a_Dij_g[5].push_back(make_pair(4, 1));
	a_Dij_g[5].push_back(make_pair(6, 2));

	a_Dij_g[6].push_back(make_pair(3, 5));
	a_Dij_g[6].push_back(make_pair(5, 2));

	dijkstra_g(1);

	//	print result.
	for (int i = 1; i <= number_Dij_g; i++) {
		printf("%d ", d_Dij_g[i]);
	}
	return 0;
}