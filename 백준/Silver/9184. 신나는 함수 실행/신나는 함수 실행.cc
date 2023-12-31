#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>

int A, B, C;
int dp[51][51][51];

int w(int a, int b, int c) {

	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return dp[20][20][20] = w(20, 20, 20);

	if (dp[a][b][c]) return dp[a][b][c];

	if (a < b && b < c) return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);

	return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
	while (1) {
		scanf("%d %d %d", &A, &B, &C);

		if (A == -1 && B == -1 && C == -1) break;

		printf("w(%d, %d, %d) = %d\n", A, B, C, w(A, B, C));
	}
}