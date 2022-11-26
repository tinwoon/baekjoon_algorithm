#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <map>

//1761�� �������� �Ÿ� ����
//a�� b ������ LCA(�ּ� ���� ����)�� ���� �� �ش� ������� a������ �Ÿ� + �ش� �������κ��� b������ �Ÿ��� ���ϴ� ������� ������.

int N, M;
//connected[a]�� ����� ������ first�̸�, a�� b ������ �Ÿ��� second
std::vector< std::map<int, int> > connected;
std::vector<bool> visited;
std::vector<int> depth;
std::vector<int> parent;
//root ���� ���� n�������� ������ ������ ���� �����صδ� �迭(���� ��ó�� ����� �� �ִ�)
std::vector<int> sum;

void bfs() {
	visited[1] = true;
	depth[1] = 0;
	parent[1] = 0;

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
			int value = itr->second;

			if (!visited[n_node]) {
				visited[n_node] = true;
				depth[n_node] = level + 1;
				parent[n_node] = node;
				sum[n_node] = sum[parent[n_node]] + connected[parent[n_node]][n_node];
				q.emplace(std::make_pair(n_node, depth[n_node]));
			}
		}
	}
}

int LCA(int a, int b) {

	int c_a = a;
	int c_b = b;

	if (depth[a] > depth[b]) std::swap(a, b);

	while (depth[a] != depth[b]) {
		b = parent[b];
	}

	while (a != b) {
		a = parent[a];
		b = parent[b];
	}

	return (sum[c_a] - sum[a]) + (sum[c_b] - sum[a]);
}

int main() {
	int a, b, c;
	scanf("%d", &N);

	connected.assign(N + 1, std::map<int, int>());
	visited.assign(N + 1, false);
	depth.assign(N + 1, 0);
	parent.assign(N + 1, 0);
	sum.assign(N + 1, 0);

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