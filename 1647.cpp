#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <tuple>

//1647 도시 분할 문제
//처음에 굉장히 난해할 수 있으나 MST를 통해 연결을 시킨 뒤 도시를 두개로 나눈다고 했으므로 하나의 간선을 빼면 된다.
// 하지만 각 마을마다 가장 작은 도로를 가져야하므로, 뺄 간선은 가장 높은 가중치의 선을 빼면된다.
//이는 MST를 모두 구하고 빼는 방법도 있지만, 애초에 마지막 간선이 가장 크므로 N-1개를 추가하는게 아닌 N-2개 까지만 추가하는 방법을 시도하면 된다.

int N, M;
std::vector<int> parent;
std::priority_queue< std::tuple<int, int, int>, std::vector< std::tuple<int, int, int> >, std::greater< std::tuple<int, int, int> > > pq;

int get_parent(int node) {
	if (parent[node] == node) return node;
	else return parent[node] = get_parent(parent[node]);
}

void union_n(int a, int b) {
	a = get_parent(a);
	b = get_parent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool find(int a, int b) {
	return get_parent(a) == get_parent(b) ? true : false;
}

int calculate() {
	int ans = 0;
	int path_include_size = 0;

	while (!pq.empty()) {
		int a, b, cost;
		std::tie(cost, a, b) = pq.top();
		pq.pop();

		if (!find(a, b)) {
			path_include_size++;
			ans += cost;
			union_n(a, b);
			if (path_include_size == N - 2) break;
		}
	}

	return ans;
}


int main() {
	scanf("%d %d", &N, &M);
	parent.assign(N + 1, 0);
	std::iota(parent.begin(), parent.end(), 0);
	for (int k = 0; k < M; k++) {
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		pq.emplace(std::make_tuple(cost, a, b));
	}

	printf("%d", calculate());
}