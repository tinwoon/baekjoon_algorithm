#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <limits.h>

std::vector< std::pair<int, int> > ans;

int N, M, lg;
std::vector< std::vector< std::pair<int, int> > > connected;
std::vector<int> depth;
//조상과 조상까지의 값
std::vector< std::pair<int, int> > parent;
std::vector<int> visited;
//a번째 노드의 2^b 번째 조상과, 해당 조상까지의 최대, 최소 값
//조상, 해당 조상까지의 최대값, 최소 값.
std::vector< std::vector< std::tuple<int, int, int> > > P;

void cal_log() {
	int m_depth = *std::max_element(depth.begin(), depth.end());
	for (lg = 0; (1 << lg) <= m_depth; lg++);
}

void bfs() {
	//node, depth
	std::queue< std::pair<int, int> > q;
	visited[1] = true;
	q.emplace(std::make_pair(1, 0));

	while (!q.empty()) {
		auto front = q.front();
		q.pop();

		int node = front.first;
		int dpth = front.second;

		for (int k = 0; k < connected[node].size(); k++) {
			int n_node = connected[node][k].first;
			int value = connected[node][k].second;
			if (!visited[n_node]) {
				visited[n_node] = true;
				depth[n_node] = dpth + 1;
				parent[n_node] = std::make_pair(node, value);
				q.emplace(std::make_pair(n_node, depth[n_node]));
			}
		}
	}
}

void init() {
	bfs();
	cal_log();
	P.assign(N + 1, std::vector< std::tuple<int, int, int> >(lg, std::tuple<int, int, int>()));

	for (int k = 0; k < N + 1; k++) {
		P[k][0] = std::make_tuple(parent[k].first, parent[k].second, parent[k].second);
	}

	for (int k = 1; k < lg; k++) {
		for (int i = 1; i <= N; i++) {
			auto mid = P[i][k - 1];
			auto end = P[std::get<0>(mid)][k - 1];

			int max_v = std::max(std::get<1>(mid), std::get<1>(end));
			int min_v = std::min(std::get<2>(mid), std::get<2>(end));

			P[i][k] = std::make_tuple(std::get<0>(end), max_v, min_v);
		}
	}
}

void calculate(int s, int e) {

	if (depth[s] > depth[e]) std::swap(s, e);

	int idx = lg;
	int i_min_v = INT_MAX, i_max_v = 0;
	int min_v = INT_MAX, max_v = 0;

	//같은 레벨까지만 올리고
	while ((depth[s] != depth[e]) && (idx >= 0)) {
		if (depth[e] - (1 << idx) >= depth[s]) {
			i_min_v = std::min(i_min_v, std::get<2>(P[e][idx]));
			i_max_v = std::max(i_max_v, std::get<1>(P[e][idx]));
			e = std::get<0>(P[e][idx]);
		}
		idx--;
	}

	if (s != e) {
		idx = lg;
		while (idx >= 0) {
			if (depth[e] - (1 << idx) >= 0) {
				int p_e = std::get<0>(P[e][idx]);
				int p_s = std::get<0>(P[s][idx]);
				if (p_e != p_s) {
					max_v = std::max({ std::get<1>(P[e][idx]), std::get<1>(P[s][idx]), max_v });
					min_v = std::min({ std::get<2>(P[e][idx]), std::get<2>(P[s][idx]), min_v });
					e = p_e;
					s = p_s;
				}
			}
			idx--;
		}

		max_v = std::max({ std::get<1>(P[e][0]), std::get<1>(P[s][0]), max_v });
		min_v = std::min({ std::get<2>(P[e][0]), std::get<2>(P[s][0]), min_v });
	}

	printf("%d %d\n", std::min(min_v, i_min_v), std::max(i_max_v, max_v));
}

int main() {
	int s, e, v;
	scanf("%d", &N);
	visited.assign(N + 1, 0);
	depth.assign(N + 1, 0);
	parent.assign(N + 1, std::pair<int, int>());
	connected.assign(N + 1, std::vector< std::pair<int, int> >());

	for (int k = 0; k < N - 1; k++) {
		scanf("%d %d %d", &s, &e, &v);
		connected[e].emplace_back(std::make_pair(s, v));
		connected[s].emplace_back(std::make_pair(e, v));
	}

	init();

	scanf("%d", &M);

	for (int k = 0; k < M; k++) {
		scanf("%d %d", &s, &e);
		calculate(s, e);
	}

}