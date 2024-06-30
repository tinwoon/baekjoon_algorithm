#pragma warning (disable : 4996)
#include <iostream>

#define SK 1
#define CY 0

long long N;
int dp[7] = {CY, SK, CY, SK, SK, SK, SK};

int main() {
    scanf("%lld", &N);

    printf("%s", dp[N%7] ? "SK" : "CY");
}