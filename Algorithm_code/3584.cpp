#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

//3584 가장 가까운 공통조상 문제
//마찬가지로 LCA 그 자체니 패스한다

int T;
int N;
std::vector< std::vector<int> > connected;
std::vector<int> parent;
std::vector<bool> visited;
std::vector<int> depth;
std::vector<bool> is_root;
int root;

void dfs(int node) {
	visited[node] = true;

	for (int k = 0; k < connected[node].size(); k++) {
		int n_node = connected[node][k];
		if (!visited[n_node]) {
			depth[n_node] = depth[node] + 1;
			parent[n_node] = node;
			dfs(n_node);
		}
	}
}

int LCA(int u, int v) {
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
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		connected.assign(N + 1, std::vector<int>());
		parent.assign(N + 1, 0);
		visited.assign(N + 1, false);
		depth.assign(N + 1, 0);
		is_root.assign(N + 1, true);
		for (int k = 0; k < N - 1; k++) {
			int a, b;
			scanf("%d %d", &a, &b);
			connected[a].emplace_back(b);
			is_root[b] = false;
		}

		root = std::distance(is_root.begin(), std::find(is_root.begin() + 1, is_root.end(), true));
		depth[root] = 1;
		dfs(root);
		int u, v;
		scanf("%d %d", &u, &v);
		printf("%d\n", LCA(u, v));
	}
}