#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>

int N, M;
std::vector<int> indegree;
std::vector< std::vector< std::pair<int, int> > > connected;

void caculate() {
	int start = std::distance(std::find(indegree.begin(), indegree.end(), 0), indegree.end());
	std::queue<int> q;
	q.emplace(start);

	while (!q.empty()) {
		auto front = q.front();
		q.pop();

		for (int k = 0; k < connected[front].size(); k++) {
			int n_node = connected[front][k].first;
			indegree[n_node]--;

			//안에 들어가는 node가 0이라면
			if (indegree[n_node] == 0) {

			}
		}
	}

}

int main() {
	scanf("%d %d", &N, &M);
	indegree.assign(N, 0);
	for (int k = 0; k < M; k++) {
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		indegree[b - 1]++;
		connected[a - 1].emplace_back(std::make_pair(b - 1, cost));
	}
}