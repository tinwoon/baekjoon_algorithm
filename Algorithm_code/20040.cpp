#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <numeric>

//위상 정렬 문제입니다.

int N, M;
std::vector<int> parent;

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
	if (get_parent(a) == get_parent(b)) return true;
	else return false;
}

int ans = 0;

int main() {
	scanf("%d %d", &N, &M);
	parent.assign(N, 0);
	std::iota(parent.begin(), parent.end(), 0);

	for (int k = 0; k < M; k++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (find(a, b)) {
			ans = k + 1;
			break;
		}
		else union_n(a, b);
	}

	printf("%d", ans);
}