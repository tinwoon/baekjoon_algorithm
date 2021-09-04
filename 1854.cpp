#pragma warning (disable:4996)
#include <iostream>
#include <vector>
#include <queue>

//1854 k번째 최단경로 찾기 문제
//다익스트라를 완벽하게 이해했느냐는 것을 확인할 수 있는 문제
//auto front = pq.top()을 해서 나온 front.first의 node는 이미 최단 경로임을 알고있는냐가 중요하다
//다익스트라의 경우 한번 pop된 노드는 출발점부터 해당 node까지의 최단경로가 이미 확실시 되었음을 아는지를 묻는 문제이다.
//물론 pq에 의해 뒤에 나온도느가 최단경로는 아니지만 맨처음 나오게 된 노드는 확실하게 최단 경로임을 아는지 묻는 것이다.
//즉, 이제까지 n번 노드가 없었다가 pq.pop()에 의해 front.first에 n번노드가 처음으로 나왔다 => n번 노드의 최단경로는 이미 확실하게 front.second이다.
//그 후에 나오는 n번 노드는 최단 경로가 아니다. 
//정리하면 weight[n]이 무한인 상황에서 pq에서 n번 노드가 나왔다 => 해당 n의 cost값은 확실하게 최단경로이다. 

int N, M, K;
std::vector< std::vector< std::pair<int, int> > > connected;
std::vector< std::priority_queue<int> > weight;

void calculate() {
	//cost, node
	std::priority_queue< std::pair<int, int>, std::vector< std::pair<int, int> >, std::greater< std::pair<int, int> > > pq;
	pq.emplace(std::make_pair(0,1));
	weight[1].emplace(0);

	while (!pq.empty()) {
		auto front = pq.top();
		pq.pop();
		int cost = front.first;
		int node = front.second;

		for (int k = 0; k < connected[node].size(); k++) {
			int ncost = cost + connected[node][k].second;
			int nnode = connected[node][k].first;

			if (weight[nnode].size() == K && weight[nnode].top() > ncost) {
				weight[nnode].pop();
				weight[nnode].emplace(ncost);
				pq.emplace(std::make_pair(ncost, nnode));
			}
			else if(weight[nnode].size() < K){
				weight[nnode].emplace(ncost);
				pq.emplace(std::make_pair(ncost, nnode));
			}

		}
	}

	for (int k = 1; k <= N; k++) {
		if (weight[k].size() == K) printf("%d\n", weight[k].top());
		else printf("-1\n");
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	connected.assign(N + 1, std::vector< std::pair<int, int> >());
	weight.assign(N + 1, std::priority_queue<int>());

	for (int k = 0; k < M; k++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		connected[a].emplace_back(std::make_pair(b, c));
	}
	calculate();
}
