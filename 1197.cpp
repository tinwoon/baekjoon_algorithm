#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <tuple>

//최소 스패닝 트리 문제
// 최소 스패닝 트리는 마찬가지로 어렵지 않게 풀수 있다.
// 1. union_find를 구현한 뒤 pq를 통해 간선의 크기가 작을 수록 먼저 나오도록 tuple< cost, a, b> 형태로 넣는다.
// 2. find를 통해 해당 노드의 부모가 같은지를 확인한다.
// 3. find가 true라는 의미는 둘의 부모가 같다는 의미이며, 이 상태에서 union을 하면 싸이클이 형성되기 때문에 하면 안된다.
// 4. find가 false이면 union한 뒤

int V, E;
std::priority_queue< std::tuple<int, int, int>, std::vector<std::tuple<int, int, int> >, std::greater< std::tuple<int, int, int> > > pq;
std::vector<int> parent;

int get_parent(int node) {
	if (node == parent[node]) return node;
	else return parent[node] = get_parent(parent[node]);
}

void union_n(int a, int b) {
	a = get_parent(a);
	b = get_parent(b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

bool find(int a, int b) {
	if (get_parent(a) == get_parent(b)) return true;
	else return false;
}

int calculate() {
	int ans = 0;
	int make_V = 0;
	while (!pq.empty()) {
		int a, b, c;
		std::tie(c, a, b) = pq.top();
		pq.pop();

		if (!find(a, b)) {
			union_n(a, b);
			ans += c;
			make_V++;
		}

		if (make_V == E - 1) break;
	}
	return ans;
}

int main() {
	scanf("%d %d", &V, &E);
	parent.assign(V, 0);
	std::iota(parent.begin(), parent.end(), 0);

	for (int k = 0; k < E; k++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		pq.emplace(std::make_tuple(c, a - 1, b - 1));
	}

	printf("%d", calculate());
}