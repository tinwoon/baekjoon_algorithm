#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <string.h>  

// 1. N번 행에 룩을 0개 넣는 경우의 수는 D[N-1][M][K]
// 2. N번 행에 룩을 1개 넣는 경우의 수는  D[N-1][M-1][K-1] * M
// 3. N번 행에 룩을 2개 넣는 경우의 수는  D[N-1][M-2][K-2] * M*(M-1)/2 가 된다. 
int N, M, K;
long long dp[101][101][101];

long long calculate(int n, int m, int k) {
    if (k == 0) {
        return 1;
    }
    if (n <= 0 || m <= 0 || k < 0) {
        return 0;
    }
    if (dp[n][m][k] != -1) {
        return dp[n][m][k];
    }
    dp[n][m][k] = calculate(n - 1, m, k) +
        calculate(n - 1, m - 1, k - 1) * m +
        calculate(n - 1, m - 2, k - 2) * m * (m - 1) / 2 +
        calculate(n - 2, m - 1, k - 2) * m * (n - 1);
    dp[n][m][k] %= 1000001;
    return dp[n][m][k];
}

int main() {
    memset(dp, -1, sizeof(dp));
	scanf("%d\n%d\n%d", &N, &M, &K);
    printf("%lli", calculate(N, M, K));
}
