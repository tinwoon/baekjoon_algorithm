#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <limits.h>

//10217 KCM Travel ���� 
//�ٽ� Ǫ�ϱ� �ٷ� ���صǴ� ����
//bfs�� dfs������ ��� �ش��� visited�� ������ ������ �ø��� ��κ� �ذ��� �ȴ�.
//KCM�� visited�� weight�̹Ƿ� weight�� node�� �ڿ� money�� �ٿ��� ����ߴ�.
//weight[node][money]�� node���� money�� ������ �� ���ִ� �ִ� ��θ� �ǹ��Ѵ�.
//�ش� ��θ� �״�� ���Ѵ���, N�� ��� �߿��� ������ �����ϴ� �ּҰ��� ã���� ���� �ȴ�. 

//v�� ������ 
std::vector< std::vector< std::tuple<int, int, int> > > connected;
//N�� ��带 ���� �ð����� �����ߴ°�
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

		//connected : ��������, money, cost
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
			//��߰���, ��������, money, cost
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
