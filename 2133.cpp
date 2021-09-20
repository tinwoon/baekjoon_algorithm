#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <limits.h>
#include <numeric>
#include <math.h>

//3*N 타일 채우기 문제
//어렵지는 않았지만 점화식을 도출하는 과정이 흥미로웠던 문제이다.

int N;
std::vector<int> dp;
std::vector<int> prefix;

int sum(int a) {
	int rst = 0;
	for (int k = 0; k <= a; k++) {
		rst += dp[k];
	}
	return rst;
}

int calculate() {
	dp.assign(N + 1, 0);
	prefix.assign(N + 1, 0);
	dp[0] = 1;
	for (int k = 1; k <= N; k++) {
		if (k % 2 == 1) continue;
		if (k >= 4) dp[k] = sum(k - 4) * 2;
		dp[k] += dp[k - 2] * 3;
	}
	return dp[N];
}

int main() {
	scanf("%d", &N);
	printf("%d", calculate());
}