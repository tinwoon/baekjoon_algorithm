#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

//벨만 포드 알고리즘 문제
//다익스트라의 경우 양수의 가중치만을 점검할 수 있지만
//벨만포드의 경우 음수의 가중치를 cycle을 통해 점검하여 최단 경로를 찾을 수 있다.
//전체 노드가 5개 있다면 가장 긴 그래프는 4개 일 것이다. 즉, 5번째 최단 경로를 갱신을 시도할때 5번 이상이 갱신된다는 말은 cycle이 형성됨을 의미한다.
//따라서 weight의 값을 기존의 다익스트라처럼 비교하며 방문하되 연결된 모든 노드를 비교한다(priority queue사용할 필요 없다)
//이때 N번째 cycle시에서도 기존 weigt가 갱신된다는건 cycle을 의미함으로 해당 간선은 무한히 작게 방문할 수 있기에 최단경로가 없는 노드이다. 

int N, M;
std::vector< std::vector< std::pair<int, int> >  > connected;
std::vector<long long> weight;

void calculate(int start) {
	weight[start] = 0;
	bool cycle = false;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < connected[j].size(); k++) {
				if (weight[j] != LLONG_MAX && weight[connected[j][k].first] > connected[j][k].second + weight[j]) {
					weight[connected[j][k].first] = connected[j][k].second + weight[j];
					if (i == N) cycle = true;
				}
			}
		}
	}

	if (cycle) printf("-1\n");
	else {
		for (int k = 2; k < weight.size(); k++) {
			if (weight[k] != LLONG_MAX) printf("%lld\n", weight[k]);
			else printf("-1\n");
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	connected.assign(N + 1, std::vector< std::pair<int, int> >(0, std::pair<int, int>(0, 0)));
	weight.assign(N + 1, LLONG_MAX);
	for (int k = 0; k < M; k++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		connected[a].emplace_back(std::make_pair(b, c));
	}
	calculate(1);
}
