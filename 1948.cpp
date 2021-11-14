#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <set>

//1948 임계경로 문제
//아직도 정확히 이해하진 못한 문제
//indegree를 양쪽 모두로 수행해서 완료한 문제이다.

int n, m;
int start, end;
std::vector<int> indegree_a;
std::vector<int> indegree_b;
//n번 노드로 들어오는 indegree_node
std::vector< std::vector< std::pair<int, int> > > connected_a;
std::vector< std::vector< std::pair<int, int> > > connected_b;

std::vector<int> distance;

int calculate() {
	std::queue<int> q;

	for (int k = 0; k < indegree_a.size(); k++) {
		if (indegree_a[k] == 0) q.emplace(k);
	}

	while (!q.empty()) {
		auto front = q.front();
		q.pop();

		for (int k = 0; k < connected_a[front].size(); k++) {
			int n_node = connected_a[front][k].first;
			indegree_a[n_node]--;

			if (distance[n_node] < distance[front] + connected_a[front][k].second) {
				distance[n_node] = distance[front] + connected_a[front][k].second;
			}

			//안에 들어가는 node가 0이라면
			if (indegree_a[n_node] == 0) {
				q.emplace(n_node);
			}
		}
	}

	return distance[end];
}

int cal_road_size() {
	int ans = 0;
	std::vector<int> is_ok(n, 0);
	is_ok[end] = true;

	std::queue<int> q;
	for (int k = 0; k < indegree_a.size(); k++) {
		if (indegree_b[k] == 0) q.emplace(k);
	}

	while (!q.empty()) {
		auto front = q.front();
		q.pop();

		for (int k = 0; k < connected_b[front].size(); k++) {
			int n_node = connected_b[front][k].first;
			int cost = connected_b[front][k].second;
			if (is_ok[front] && (distance[front] - distance[n_node] == cost)) {
				ans++;
				is_ok[n_node] = true;
			}

			indegree_b[n_node]--;
			if (indegree_b[n_node] == 0) {
				q.emplace(n_node);
			}

		}
	}

	return ans;
}

int main() {
	scanf("%d %d", &n, &m);
	indegree_a.assign(n, 0);
	indegree_b.assign(n, 0);
	distance.assign(n, 0);
	connected_a.assign(n, std::vector< std::pair<int, int> >());
	connected_b.assign(n, std::vector< std::pair<int, int> >());

	for (int k = 0; k < m; k++) {
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		indegree_a[b - 1]++;
		indegree_b[a - 1]++;
		connected_a[a - 1].emplace_back(std::make_pair(b - 1, cost));
		connected_b[b - 1].emplace_back(std::make_pair(a - 1, cost));
	}
	scanf("%d %d", &start, &end);
	start--;
	end--;
	calculate();
	printf("%d\n", calculate());
	printf("%d\n", cal_road_size());
}
