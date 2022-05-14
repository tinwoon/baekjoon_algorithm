#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

//플로이드 마샬 알고리즘을 사용하면 된다.
//기존의 다익스트라 보다도 간편하게 최단 경로를 찾을 수 있고, 음수의 가중치 문제도 해결할 수 있지만 
//연산 값이 다익스트라보다 많은 문제가 있다.
//i부터 j까지의 최단 경로를 dp[i][j]라 한다면
//dp[i][j] 는 어떤 k경로를 중간 경유지로 방문한다 했을 때 dp[i][j] = dp[i][k] + dp[j][k] 와 dp[i][j] 중 작은 값을 갱신하며 찾으면 된다. 

int n, m;
std::vector< std::vector<int> > dp;

void calculate() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (dp[j][i] != INT_MAX && dp[i][k] != INT_MAX) {
					dp[j][k] = std::min(dp[j][i] + dp[i][k], dp[j][k]);
				}
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	dp.assign(n + 1, std::vector<int>(n + 1, INT_MAX));
	
	for (int k = 0; k < m; k++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(dp[a][b] > c) dp[a][b] = c;
	}
	calculate();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || dp[i][j] == INT_MAX)
				printf("0 ");
			else
				printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
}
