#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <math.h>

//11958 텔레포트 문제
//굉장히 질이 안좋은 문제이다. 안푸는게 좋을 정도로
//N값이 1000이기 때문에 플로이드 와셜을 떠올렸지만 2초는 가뿐히 넘어 정말 오랫동안 고민
//하지만 답안은 플로이드 와셜인데 최적화를 활용한 코드도 없이 그냥 컴파일러 최적화에 의한 운으로 풀어야하는 문제이다.

int N, T, M;
//N번과 N번 간의 거리
std::vector< std::vector<int> > dp;
//N번 도시의 좌표
std::vector< std::pair<int, int> > city;
//현재 도시가 특별한 도시인가
std::vector<bool> is_special;

void calculate() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (dp[j][i] != INT_MAX && dp[i][k] != INT_MAX) {
					dp[j][k] = std::min(dp[j][i] + dp[i][k], dp[j][k]);
				}
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &T);
	dp.assign(N, std::vector<int>(N, INT_MAX));
	city.assign(N, std::pair<int, int>());
	is_special.assign(N, false);

	for (int k = 0; k < N; k++) {
		int Special, x, y;
		scanf("%d %d %d", &Special, &x, &y);
		city[k] = std::make_pair(x, y);
		is_special[k] = (bool)Special;
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (is_special[i] && is_special[j]) dp[j][i] = dp[i][j] = std::min(abs(city[i].first - city[j].first) + abs(city[i].second - city[j].second), T);
			else dp[j][i] = dp[i][j] = abs(city[i].first - city[j].first) + abs(city[i].second - city[j].second);
		}
	}

	calculate();

	scanf("%d", &M);
	for (int k = 0; k < M; k++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", dp[a - 1][b - 1]);
	}


}