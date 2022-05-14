#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <limits.h>

//10217 KCM Travel 문제 
//다시 푸니까 바로 이해되는 문제
//bfs나 dfs문제의 모든 해답은 visited의 차원을 한차원 늘리면 대부분 해결이 된다.
//KCM의 visited는 weight이므로 weight의 node갑 뒤에 money를 붙여서 계산했다.
//weight[node][money]는 node까지 money를 가지고 갈 수있는 최단 경로를 의미한다.
//해당 경로를 그대로 구한다음, N번 노드 중에서 조건을 만족하는 최소값을 찾으면 답이 된다. 

//v번 공항의 
std::vector< std::vector< std::tuple<int, int, int> > > connected;
//N번 노드를 얼마의 시간으로 도착했는가
std::vector< std::vector<int> > weight;
int N, M, K;

void calculate() {
	std::priority_queue < std::tuple<int, int, int>, std::vector< std::tuple<int, int, int> >, std::greater < std::tuple<int, int, int> > > pq;
	//cost, money, node
	pq.emplace(std::make_tuple(0,0,1));
	weight[1][0] = 0;

	while (!pq.empty()) {
		int cost, money, node;
		std::tie(cost, money, node) = pq.top();
		pq.pop();

		if (weight[node][money] < cost) continue;

		//connected : 도착공항, money, cost
		for (int k = 0; k < connected[node].size(); k++) {
			int n_cost = cost + std::get<2>(connected[node][k]);
			int n_money = money + std::get<1>(connected[node][k]);
			int n_node = std::get<0>(connected[node][k]);

			if (n_money <= M) {
				if (weight[n_node][n_money] > n_cost) {
					pq.emplace(std::make_tuple(n_cost, n_money, n_node));
					weight[n_node][n_money] = n_cost;
				}
			}
		}
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d %d", &N, &M, &K);
		connected.assign(N + 1, std::vector< std::tuple<int, int, int> >());
		weight.assign(N + 1, std::vector<int>(M + 1, INT_MAX));
		for (int k = 0; k < K; k++) {
			//출발공항, 도착공항, money, cost
			int u, v, c, d;
			scanf("%d %d %d %d", &u, &v, &c, &d);
			connected[u].emplace_back(std::make_tuple(v, c, d));
		}
		calculate();
		int ans = INT_MAX;
		for (int k = 0; k <= M; k++) {
			ans = std::min(ans, weight[N][k]);
		}
		if (ans == INT_MAX) printf("Poor KCM\n");
		else printf("%d\n", ans);
	}
}
