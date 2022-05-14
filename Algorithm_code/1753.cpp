#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>

//다익스트라 알고리즘 

int V, E, K;
bool visited[20001];
std::vector< std::vector< std::pair<int, int> > > connected;
std::vector<int> weight(20001, INT_MAX);
int ans = 0;
std::priority_queue< std::pair<int, int>, std::vector< std::pair<int, int> >, std::greater< std::pair<int, int> > > q;

void calculate(int node) {
	visited[node] = true;
	for (int node_t = 0; node_t < connected[node].size(); node_t++) {
		weight[connected[node][node_t].first] = std::min(weight[node] + connected[node][node_t].second, weight[connected[node][node_t].first]);
		//가중치, node의 번호
		q.emplace(std::make_pair(weight[connected[node][node_t].first], connected[node][node_t].first));
	}
	while (!q.empty()) {
		auto front = q.top();
		q.pop();
		if (!visited[front.second]) calculate(front.second);
	}
}

int main() {
	scanf("%d %d", &V, &E);
	scanf("%d", &K);
	connected.assign(V + 1, std::vector< std::pair<int, int> >(0, std::pair<int, int>(0,0)));
	for (int e = 0; e < E; e++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		connected[u].emplace_back(std::make_pair(v, w));
	}
	weight[K] = 0;
	calculate(K);
	for (int node_t = 1; node_t <= V; node_t++) {
		if (weight[node_t] == INT_MAX) printf("INF\n");
		else printf("%d\n", weight[node_t]);
	}
}
