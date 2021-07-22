#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

//전형적인 플로이드 마샬 알고리즘이다.
//플로이드 마샬의 다익스트라, 벨만포드와 또 다른 특징이 있다면
//바로 현재 노드에서 다시 현재 노드로 오는 정점까지도 최단 경로를 구할 수 있다는 점이다.
//플로이드 마셜에서 dp[i][i]의 값을 0이 아닌 INT_MAX로 선언하면 최단 경로를 구할 수 있다. 

int V, E;
std::vector< std::vector<int> > connected;

int floyd() {
	int ans = INT_MAX;
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			for (int k = 1; k <= V; k++) {
				if (connected[j][i] != INT_MAX && connected[i][k] != INT_MAX) {
					connected[j][k] = std::min(connected[j][i] + connected[i][k], connected[j][k]);
				}
			}
		}
	}
	for (int k = 1; k <= V; k++) {
		ans = std::min(ans, connected[k][k]);
	}
	return ans != INT_MAX ? ans : -1;
}

int main() {
	scanf("%d %d", &V, &E);
	connected.assign(V + 1, std::vector<int>(V+1, INT_MAX));
	for (int k = 0; k < E; k++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		connected[a][b] = c;
	}
	printf("%d", floyd());
}
