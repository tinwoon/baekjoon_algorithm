#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits.h>

//1916 최소비용 구하기
//다익스트라 문제인데 복습겸 그냥 풀어봤어용

int N, M;
std::vector< std::vector< std::pair<int, int> > > connected;
std::vector<int> weight;


int calculate(int start, int end) {
	weight[0] = 0;
	std::priority_queue< std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater< std::pair<int, int> > > pq;
	pq.emplace(std::make_pair(0, start));

	while (!pq.empty()) {
		auto front = pq.top();
		pq.pop();

		int cost = front.first;
		int node = front.second;

		if (cost > weight[node]) continue;

		for (int k = 0; k < connected[node].size(); k++) {
			int ncost = cost + connected[node][k].second;
			int nnode = connected[node][k].first;

			if (weight[nnode] > ncost) {
				weight[nnode] = ncost;
				pq.emplace(std::make_pair(ncost, nnode));
			}
		}
	}

	return weight[end];

}

int main() {
	scanf("%d %d", &N, &M);
	weight.assign(N, INT_MAX);
	connected.assign(N, std::vector<std::pair<int, int>>());

	for (int k = 0; k < M; k++) {
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		connected[a - 1].emplace_back(std::make_pair(b - 1, cost));
	}
	int start, end;
	scanf("%d %d", &start, &end);
	printf("%d", calculate(start - 1, end - 1));
}