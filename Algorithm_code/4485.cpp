#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

//4485번 녹색 옷 입은 애가 젤다지?
//전형적인 다익스트라에 노드 설정에 대한 알고리즘 활용 문제

std::vector< std::vector<int> > map;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

//0에서 n번까지 가는데 걸리는 비용
std::vector<int> weight;
//node, cost 순서임.
std::vector< std::vector< std::pair<int,int> > > connect;
int N;

int calculate() {
	std::priority_queue< std::pair<int, int>, std::vector< std::pair<int, int> >, std::greater< std::pair<int, int> > > pq;
	//초기 비용, 현재 노드
	pq.emplace(std::make_pair(map[0][0], 0));
	weight[0] = map[0][0];

	while (!pq.empty()) {
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		for (int k = 0; k < connect[node].size(); k++) {
			int n_cost = cost + connect[node][k].second;
			int n_node = connect[node][k].first;

			if (weight[n_node] > n_cost) {
				weight[n_node] = n_cost;
				pq.emplace(std::make_pair(n_cost, n_node));
			}
		}
	}

	return weight[N * N - 1];
}

int ret_idx(int x, int y) {
	return x * N + y;
}

int main() {
	int cnt = 0;
	while (1) {
		cnt++;
		scanf("%d", &N);
		if (N == 0) break;

		connect.assign(N * N, std::vector< std::pair<int, int> >());
		map.assign(N, std::vector<int>(N, 0));
		weight.assign(N * N, INT_MAX);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int idx = ret_idx(i, j);

				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
						connect[idx].emplace_back(std::make_pair(ret_idx(nx, ny), map[nx][ny]));
					}
				}
			}
		}
		printf("Problem %d: %d\n",cnt, calculate());
	}
	
}