#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>

//1948 LCA
//가장 가까운 공통조상 문제
//기본적인 LCA 문제이니 해당 개념을 숙지해야한다.

int N, M;
std::vector< std::vector<int> > connected;
std::vector<bool> visited;
std::vector<int> depth;
std::vector<int> parent;

void calculate() {
	std::queue<int> q;
	q.emplace(1);
	visited[1] = true;

	while (!q.empty()) {
		auto front = q.front();
		q.pop();

		for (int k = 0; k < connected[front].size(); k++) {
			int node = connected[front][k];
			if (!visited[node]) {
				visited[node] = true;
				q.emplace(node);
				depth[node] = depth[front] + 1;
				parent[node] = front;
			}
		}
	}
}

int LCA(int u, int v) {
	//u가 더 낮은 깊이여야 한다.
	if (depth[u] > depth[v]) std::swap(u, v);

	while (depth[u] != depth[v]) {
		v = parent[v];
	}

	while (u != v) {
		u = parent[u];
		v = parent[v];
	}

	return u;
}

int main() {
	scanf("%d", &N);
	connected.assign(N + 1, std::vector<int>());
	depth.assign(N + 1, 0);
	visited.assign(N + 1, false);
	parent.assign(N + 1, 0);
	for (int k = 0; k < N - 1; k++) {
		int a, b;
		scanf("%d %d", &a, &b);
		connected[a].emplace_back(b);
		connected[b].emplace_back(a);
	}
	scanf("%d", &M);
	calculate();
	for (int k = 0; k < M; k++) {
		int u, v;
		scanf("%d %d", &u, &v);
		printf("%d\n", LCA(u, v));
	}
}