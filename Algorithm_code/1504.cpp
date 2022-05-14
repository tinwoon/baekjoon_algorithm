#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <limits.h>

//특정한 최단 경로 문제
//다익스트라는 다음과 같은 형시에서 벗어나지 않는다. 즉 bfs랑 비슷하다.
//변형 문제도 다음과 같이 다익스트라를 일정 노드를 꼭 방문해야하는 방식으로 진행된다.
//즉, 몇번부터 몇번 노드까지 다익스트라 하고, 그 다음 몇번노드부터 몇번 노드까지 다익스트라해서 여러번 연산하는 방식으로 변형된다. 

int N, E;
int v1, v2;
std::priority_queue< std::pair<int, int>, std::vector< std::pair<int, int> >, std::greater< std::pair<int, int> > > q;
std::vector< std::vector< std::pair<int, int> > > connected;
std::vector<int> weight;

int ans = 0;
int first_v1, first_v2, v1_v2, v1_N, v2_N;
bool flag_1 = false, flag_2 = false;
int ans_1 = INT_MAX, ans_2 = INT_MAX;

void calculate(int node) {
	q.emplace(std::make_pair(0, node));
	weight[node] = 0;

	while (!q.empty()) {
		auto front = q.top();
		q.pop();

		int cost = front.first;
		int p_node = front.second;

		for (int k = 0; k < connected[p_node].size(); k++) {
			int ncost = connected[p_node][k].second;
			int n_node = connected[p_node][k].first;
			
			if (weight[n_node] > cost + ncost) {
				weight[n_node] = cost + ncost;
				q.emplace(std::make_pair(weight[n_node], n_node));
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &E);
	connected.assign(N + 1, std::vector< std::pair<int, int> >(0, std::pair<int, int>()));
	for (int k = 0; k < E; k++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		connected[a].emplace_back(std::make_pair(b, c));
		connected[b].emplace_back(std::make_pair(a, c));
	}
	scanf("%d %d", &v1, &v2);

	weight.assign(N + 1, INT_MAX);
	calculate(1);
	first_v1 = weight[v1];
	first_v2 = weight[v2];

	weight.assign(N + 1, INT_MAX);
	calculate(v1);
	v1_v2 = weight[v2];

	weight.assign(N + 1, INT_MAX);
	calculate(N);
	v1_N = weight[v1];
	v2_N = weight[v2];

	if (first_v1 == INT_MAX || v1_v2 == INT_MAX || v2_N == INT_MAX) flag_1 = true;
	else ans_1 = first_v1 + v1_v2 + v2_N;
	if (first_v2 == INT_MAX || v1_v2 == INT_MAX || v1_N == INT_MAX) flag_2 = true;
	else ans_2 = first_v2 + v1_v2 + v1_N;

	printf("%d", (flag_1 && flag_2) ? -1 : std::min(ans_1, ans_2));
}
