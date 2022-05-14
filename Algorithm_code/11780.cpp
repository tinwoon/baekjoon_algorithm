#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

//11780 플로이드 문제
//이름과 같이 플로이드 그 자체이다

int N, M;
std::vector < std::vector<int> >connected;
//경로를 저장
std::vector< std::vector< std::vector<int> > > road;

void calculate() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (connected[j][i] != INT_MAX && connected[i][k] != INT_MAX) {
					if (connected[j][k] > connected[j][i] + connected[i][k]) {
						connected[j][k] = connected[j][i] + connected[i][k];
						road[j][k].clear();
						for (int size = 0; size < road[j][i].size() - 1; size++) {
							road[j][k].emplace_back(road[j][i][size]);
						}
						road[j][k].emplace_back(i);
						for (int size = 1; size < road[i][k].size(); size++) {
							road[j][k].emplace_back(road[i][k][size]);
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", connected[i][j] == INT_MAX ? 0 : connected[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (road[i][j].size() > 1) printf("%d ", road[i][j].size());
			else {
				printf("0\n");
				continue;
			}
			for (int size = 0; size < road[i][j].size(); size++) {
				printf("%d ", road[i][j][size] + 1);
			}
			printf("\n");
		}
	}

}

int main() {
	scanf("%d %d", &N, &M);
	connected.assign(N, std::vector<int>(N, INT_MAX));
	road.assign(N, std::vector< std::vector<int> >(N, std::vector<int>()));

	for (int k = 0; k < N; k++) {
		connected[k][k] = 0;
		road[k][k].emplace_back(k);
	}

	for (int k = 0; k < M; k++) {
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		if (connected[a - 1][b - 1] > cost) {
			connected[a - 1][b - 1] = cost;
			road[a - 1][b - 1].clear();
			road[a - 1][b - 1].emplace_back(a - 1);
			road[a - 1][b - 1].emplace_back(b - 1);
		}
	}
	calculate();

}