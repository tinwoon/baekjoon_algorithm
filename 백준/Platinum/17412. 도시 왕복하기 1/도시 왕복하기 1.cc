#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>

int N, P;
std::vector< std::vector<int> > connected;
std::vector< std::vector<int> > flow;
std::vector< std::vector<int> > capacity;
std::vector<int> from;

int calculate(int start, int end) {
	int ret = 0;

	while (1) {
		std::queue<int> q;
		from.assign(N + 1, -1);
		q.emplace(start);
		
		while (!q.empty()) {
			auto front = q.front();
			q.pop();

			for (int k = 0; k < connected[front].size(); k++) {
				int n_node = connected[front][k];
				if (capacity[front][n_node] - flow[front][n_node] > 0 && from[n_node] == -1) {
					q.emplace(n_node);
					from[n_node] = front;
					if (n_node == end) break;
				}
			}
		}

		if (from[end] == -1) break;

		int flw = INT_MAX;
		for (int node = end; node != start; node = from[node]) {
			flw = std::min(flw, capacity[from[node]][node] - flow[from[node]][node]);
		}
		for (int node = end; node != start; node = from[node]) {
			flow[from[node]][node] += flw;
			flow[node][from[node]] -= flw;
		}

		ret += flw;
	}

	return ret;
}

int main() {
	scanf("%d %d", &N, &P);
	connected.assign(N + 1, std::vector<int>());
	flow.assign(N + 1, std::vector<int>(N + 1, 0));
	capacity.assign(N + 1, std::vector<int>(N + 1, 0));
	from.assign(N + 1, -1);


	for (int k = 0; k < P; k++) {
		int a, b;
		scanf("%d %d", &a, &b);
		connected[a].emplace_back(b);
		connected[b].emplace_back(a);
		capacity[a][b] = 1;
	}

	printf("%d", calculate(1, 2));
}