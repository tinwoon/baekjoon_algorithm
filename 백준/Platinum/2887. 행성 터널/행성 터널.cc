#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <numeric>

#define LL (long long)

int N;
//node 별 x,y,z
std::vector< std::tuple<int, int, int> > data;
//x, y, z에 대한 sorting 값 (x, node), (y, node), (z, node)
std::vector< std::pair<int, int> > srt[3];
std::vector<int> parent;
//DIS, node1, node2
std::priority_queue< std::tuple<int, int, int> > pq;

int get_parent(int node) {
	if (parent[node] == node) return node;
	return parent[node] = get_parent(parent[node]);
}

bool find(int a, int b) {
	return (get_parent(a) == get_parent(b));
}

void union_n(int a, int b) { 
	a = get_parent(a);
	b = get_parent(b);

	if (a < b) parent[b] = a;
	else parent[a] = b;

	return;
}

long long calculate() {
	int make_n = 0;
	long long ans = 0;

	while (!pq.empty()) {
		auto front = pq.top();
		pq.pop();

		int dis, a, b;
		std::tie(dis, a, b) = front;
		dis *= -1;

		if (!find(a, b)) {
			union_n(a, b);
			make_n++;
			ans += LL dis;
		}

		if (make_n == N - 1) break;
	}

	return ans;
}

int main() {
	scanf("%d", &N);
	parent.assign(N, 0);
	std::iota(parent.begin(), parent.end(), 0);

	for (int k = 0; k < N; k++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		srt[0].emplace_back(std::make_pair(x, k));
		srt[1].emplace_back(std::make_pair(y, k));
		srt[2].emplace_back(std::make_pair(z, k));
	}
	std::sort(srt[0].begin(), srt[0].end());
	std::sort(srt[1].begin(), srt[1].end());
	std::sort(srt[2].begin(), srt[2].end());

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < N - 1; j++) {
			int a = srt[i][j].second;
			int b = srt[i][j + 1].second;
			if (a > b) std::swap(a, b);
			pq.emplace(std::make_tuple(-1*abs(srt[i][j].first - srt[i][j + 1].first), a, b));
		}
	}

	printf("%lld", calculate());
}