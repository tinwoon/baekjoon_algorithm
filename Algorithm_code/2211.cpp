#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <limits.h>

//2211 네트워크 복구 문제
//딱히 머 이야기할 내용은 없다.
//그냥 다익스트라이다. 

int N, M;
std::vector<int> weight;
std::vector<int> from;
std::set< std::pair<int, int> > ans;
std::vector< std::vector< std::pair<int,int> > > connected;

void calculate() {
	from[1] = 1;
	weight[1] = 0;
	//cost, node;
	std::priority_queue< std::pair<int, int>, std::vector< std::pair<int, int> >, std::greater< std::pair<int, int> > > pq;
	pq.emplace(std::make_pair(0, 1));

	while (!pq.empty()) {
		auto front = pq.top();
		pq.pop();
		int cost = front.first;
		int node = front.second;

		if (weight[node] < cost) continue;

		for (int k = 0; k < connected[node].size(); k++) {
			int ncost = connected[node][k].second + cost;
			int nnode = connected[node][k].first;
			if (ncost < weight[nnode]) {
				from[nnode] = node;
				weight[nnode] = ncost;
				pq.emplace(std::make_pair(ncost, nnode));
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		int begin = i;
		int end = from[i];
		if (begin == end) continue;
		if (begin < end) ans.insert(std::make_pair(begin, end));
		else ans.insert(std::make_pair(end, begin));
	}

	printf("%d\n", ans.size());
	for (auto itr = ans.begin(); itr != ans.end(); itr++) {
		printf("%d %d\n", itr->first, itr->second);
	}
}

int main() {
	scanf("%d %d", &N, &M);
	weight.assign(N + 1, INT_MAX);
	from.assign(N + 1, INT_MAX);
	connected.assign(N + 1, std::vector< std::pair<int, int> >());
	for (int k = 0; k < M; k++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		connected[a].emplace_back(std::make_pair(b, c));
		connected[b].emplace_back(std::make_pair(a, c));
	}
	calculate();
}

