#pragma warning (disable : 4996)
#include <iostream>
#include <vector>

#define SK 1
#define CY 0

long long N;
std::vector<int> dp = { CY, SK, CY, SK, SK };

int main() {
    scanf("%lld", &N);

    printf("%s", dp[N%5] ? "SK" : "CY");
}