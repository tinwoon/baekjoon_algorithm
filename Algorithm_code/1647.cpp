#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <tuple>

//1647 ���� ���� ����
//ó���� ������ ������ �� ������ MST�� ���� ������ ��Ų �� ���ø� �ΰ��� �����ٰ� �����Ƿ� �ϳ��� ������ ���� �ȴ�.
// ������ �� �������� ���� ���� ���θ� �������ϹǷ�, �� ������ ���� ���� ����ġ�� ���� ����ȴ�.
//�̴� MST�� ��� ���ϰ� ���� ����� ������, ���ʿ� ������ ������ ���� ũ�Ƿ� N-1���� �߰��ϴ°� �ƴ� N-2�� ������ �߰��ϴ� ����� �õ��ϸ� �ȴ�.

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