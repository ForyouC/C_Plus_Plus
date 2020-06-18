#include <stdio.h>

int number_Dij_e = 6;
int INF_e = 1000000000;

// All graph reset
int a_Dij_e[6][6] = {
	{ 0, 2, 5, 1, INF_e, INF_e },
	{ 2, 0, 3, 2, INF_e, INF_e },
	{ 5, 3, 0, 3, 1, 5 },
	{ 1, 2, 3, 0, 1, INF_e },
	{ INF_e, INF_e, 1, 1, 0, 2 },
	{ INF_e, INF_e, 5, INF_e, 2, 0}
};
bool v_dij_e[6]; // visited node
int d_Dij_e[6]; // most shortest distance

// Find node has the shortest distance
int getSmallIndex_e() {
	int min = INF_e;
	int index = 0;
	for (int i = 0; i < number_Dij_e; i++) {
		if (d_Dij_e[i] < min && !v_dij_e[i]) {
			min = d_Dij_e[i];
			index = i;
		}
	}
	//printf("%d ", index);
	return index;
}

// carry dijkstra_e out
void dijkstra_e(int start) {
	for (int i = 0; i < number_Dij_e; i++) {
		d_Dij_e[i] = a_Dij_e[start][i];
	}
	v_dij_e[start] = true;
	for (int i = 0; i < number_Dij_e - 2; i++) {
		int current = getSmallIndex_e();
		v_dij_e[current] = true;
		for (int j = 0; j < 6; j++) {
			if (!v_dij_e[j]) {
				if (d_Dij_e[current] + a_Dij_e[current][j] < d_Dij_e[j]) {
					d_Dij_e[j] = d_Dij_e[current] + a_Dij_e[current][j];
				}
			}
		}
	}
}

int main_Dij_easy_way(void) {
	dijkstra_e(0);
	for (int i = 0; i < number_Dij_e; i++) {
		printf("%d ", d_Dij_e[i]);
	}
	return 0;
}
