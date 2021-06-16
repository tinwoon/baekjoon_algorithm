#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string.h>

//팰린드롬 문제
//재귀 형식으로 진행한다.
//마찬가지로 dp를 진행하는 재귀 형식을 참조하는 것이 좋다. 

int N;
int map[5001];
int dp[5001][5001];

int calculate(int i, int j) {
	if (dp[i][j] != -1) return dp[i][j];
	if (map[i] == map[j]) dp[i][j] = calculate(i + 1, j - 1);
	else dp[i][j] = std::min(calculate(i + 1, j), calculate(i, j - 1)) + 1;
	return dp[i][j];
}

int main() {
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	for (int k = 0; k < N; k++) {
		scanf("%d", &map[k]);
	}
	for (int k = 0; k < N; k++) {
		dp[k][k] = 0;
		if(k != N-1) dp[k][k + 1] = map[k] == map[k + 1] ? 0 : 1; 
	}
	printf("%d", calculate(0, N - 1));
}
