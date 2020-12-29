//dp[1][4] = dp[1][1] + dp[2][4] + (40 + 30 + 30 + 50)
//             = dp[1][1] + {dp[2][2] + dp[3][4] + (30 + 30 + 50)} + (40 + 30 + 30 + 50)
//              = 0           + 0            + 80         + (110) 
//              = 340
//이 알고리즘을 이해하는데 핵심 부분
//재귀적으로 최솟값을 찾는 방법이 핵심이다.
//위의 답은 답이 아니라 임의로 계산 로직을 구했을때임 (각각의 반복된 재귀가 모두 k=1일때) 

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
using namespace std;
 
int dp[501][501];
int cost[501];
int sum[501];
int t, k, i;
 
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &k);
        for (i = 1; i <= k; ++i) {
            scanf("%d", &cost[i]);
            sum[i] = sum[i - 1] + cost[i];
        }
 
        for (int d = 1; d < k; ++d) {
            for (int tx = 1; tx + d <= k; ++tx) {
                int ty = tx + d;
                dp[tx][ty] = INT_MAX;
 
                for (int mid = tx; mid < ty; ++mid)
                    dp[tx][ty] =
                        min(dp[tx][ty], 
                            dp[tx][mid] + dp[mid + 1][ty] + sum[ty] - sum[tx - 1]);
            }
        }
 
        printf("%d\n", dp[1][k]);
    }
    return 0;
}

