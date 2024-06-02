#pragma warning (disable : 4996)
#include <iostream>
#include <vector>

#define MOD 9901

int N, M;
//S번째 타일에서 bit형태로 놓았을 때의 값
std::vector< std::vector<int> > dp;

int calculate(int block_n, int bit) {

    if ((block_n == N * M) && (bit == 0)) {
        return 1;
    }

    if (block_n >= N * M) return 0;

    //이미 해당 케이스로 방문한 적이 있으면 종료
    if (dp[block_n][bit] != -1) return dp[block_n][bit];

    int ret = 0;

    if (bit & 1) {
        ret = calculate(block_n + 1, bit >> 1);
    }
    else {
        ret = calculate(block_n + 1, (bit >> 1) | (1 << (M - 1)));

        if ((!(bit & 2)) && ((block_n % M) != (M - 1))) {
            ret += calculate(block_n + 2, (bit >> 2));
        }
    }

    

    return dp[block_n][bit] = (ret % MOD);
}

int main() {
    scanf("%d %d", &N, &M);
    dp.assign(N * M, std::vector<int>(1 << M, -1));
    printf("%d", calculate(0, 0));
}