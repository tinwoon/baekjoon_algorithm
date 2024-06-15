#pragma warning (disable : 4996)
#include <iostream>

#define SK 1
#define CY 0

int dp[1001];
int N;

int main() {
	dp[1] = dp[3] = dp[4] = SK;
	dp[2] = CY;

	scanf("%d", &N);

	for (int k = 5; k <= N; k++) {
		dp[k] = ((!dp[k - 1]) || (!dp[k - 3]) || (!dp[k - 4]));
	}
	printf("%s\n", dp[N] == SK ? "SK" : "CY");

	return 0;
}