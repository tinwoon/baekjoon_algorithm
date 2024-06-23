#pragma warning (disable : 4996)
#include <iostream>

#define SK 1
#define CY 0

int N;
int dp[1001];

int main() {
    dp[1] = dp[3] = CY;
    dp[2] = dp[4] = SK;

    scanf("%d", &N);

    for (int k = 5; k <= N; k++) {
        dp[k] = (!dp[k - 1] || !dp[k - 4] || !dp[k - 3]) ? SK : CY;
    }
    printf("%s", dp[N] ? "SK" : "CY");
}