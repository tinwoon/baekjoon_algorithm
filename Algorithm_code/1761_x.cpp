#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <map>

int N, M;
//connected[a]�� ����� ������ first�̸�, a�� b ������ �Ÿ��� second
std::vector< std::map<int, int> > connected;
std::vector<bool> visited;
std::vector<int> depth;
std::vector<int> parent;
//BFS �������� indexing �ϱ� ����(BFS���� ù��°�� �湮�� ���� 1��, �ι�°�� 4�� ���)
std::vector<int> index;
//root ��忡�� Ư�� �������� �κ����� �ֱ� ����.(6������ 5����� ���� �Ÿ��� 1 -> 6 �� 1 -> 5�� �Ÿ��� ���� �ȴ�.
std::vector<int> dp;

void bfs() {
	int idx = 1;
	visited[1] = true;
	depth[1] = 0;
	parent[1] = 0;
	index[1] = idx;
	dp[idx] = 0;

	//node, depth
	std::queue<std::pair<int, int> > q;
	q.emplace(std::make_pair(1, 1));

	while (!q.empty()) {
		auto front = q.front();
		q.pop();

		int node = front.first;
		int level = front.second;

		for (auto itr = connected[node].begin(); itr != connected[node].end(); itr++) {
			int n_node = itr->first;
			int node_to_n_node = itr->second;

			if (!visited[n_node]) {
				index[n_node] = ++idx;
				dp[idx] = dp[idx - 1] + node_to_n_node;
				visited[n_node] = true;
				depth[n_node] = level + 1;
				parent[n_node] = node;
				q.emplace(std::make_pair(n_node, depth[n_node]));
			}
		}
	}
}

int LCA(int a, int b) {
	int first_a = a;
	int first_b = b;

	if (depth[a] > depth[b]) std::swap(a, b);

	while (depth[a] != depth[b]) {
		b = parent[b];
	}

	while (a != b) {
		a = parent[a];
		b = parent[b];
	}

	return dp[first_a] + dp[first_b] - (2 * dp[a]);
}

int main() {
	int a, b, c;
	scanf("%d", &N);

	connected.assign(N + 1, std::map<int, int>());
	visited.assign(N + 1, false);
	depth.assign(N + 1, 0);
	parent.assign(N + 1, 0);
	index.assign(N + 1, 0);
	dp.assign(N + 1, 0);

	for (int k = 0; k < N - 1; k++) {
		scanf("%d %d %d", &a, &b, &c);
		connected[a].insert(std::make_pair(b, c));
		connected[b].insert(std::make_pair(a, c));
	}

	bfs();
	scanf("%d", &M);

	for (int k = 0; k < M; k++) {
		scanf("%d %d", &a, &b);
		printf("%d\n", LCA(a, b));
	}
}