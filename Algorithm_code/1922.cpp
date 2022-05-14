#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <tuple>
#include <algorithm>

//1922 네트워크 연결
//MST 문제이다.
// 그 이상 그 이하도 아니니 생략한다.


int N, M;
std::vector<int> parent;
std::priority_queue < std::tuple<int, int, int>, std::vector< std::tuple<int, int, int> >, std::greater< std::tuple<int, int, int> > > q;


int get_parent(int node) {
	if (parent[node] == node) return node;
	return parent[node] = get_parent(parent[node]);
}

void union_n(int a, int b) {
	a = get_parent(a);
	b = get_parent(b);

	if (a < b) parent[b] = parent[a];
	else parent[a] = parent[b];
}

bool find(int a, int b) {
	if (get_parent(a) == get_parent(b)) return true;
	else return false;
}

int calculate() {
	int E = 0;
	int ans = 0;

	while (!q.empty()) {
		int cost, a, b;
		std::tie(cost, a, b) = q.top();
		q.pop();

		if (!find(a, b)) {
			union_n(a, b);
			E++;
			ans += cost;
		}

		if (E == N - 1) return ans;
	}

	return -1;
}

int main() {
	scanf("%d", &N);
	parent.assign(N, 0);
	std::iota(parent.begin(), parent.end(), 0);
	scanf("%d", &M);

	for (int k = 0; k < M; k++) {
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		q.emplace(std::make_tuple(cost, a - 1, b - 1));
	}
	printf("%d\n", calculate());
}