#include <iostream>
#include <vector>


//박스 안의 열쇠
// 점화식이긴 하지만 제 1의 스털링 수 라는 원순열 공식을 알아야 풀 수 있음
// 모르는 건 고민하지 말고 시간낭비 하지말고 바로 답안 보는 습관 들이기

int N, M;
//n개의 수중 m개의 싸이클을 가지는 경우
long long dp[21][21];

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long calculate(int n, int m) {
	if (n == 0) return 1;
	if (m == 0) return 0;

	if (dp[n][m] != 0) return dp[n][m];

	return dp[n][m] = calculate(n - 1, m - 1) + (n - 1) * calculate(n - 1, m);
}

int main() {
	scanf("%d %d", &N, &M);
	long long rst = calculate(N, M);
	long long rst_all = calculate(N, N);
	long long gcd_value = gcd(rst_all, rst);
	printf("%lli/%lli", rst/gcd_value, rst_all/gcd_value);
}
