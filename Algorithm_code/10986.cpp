#include <iostream>
#include <vector>

//dp[n]의 의미는 0부터 K까지 더한 값을 sum이라 했을 때, 나머지가 n인 값의 총 개수이다.
//이 값을 알면 dp[i]*dp[i]-1/2를 하면 나머지가 i인 값들의 경우의 수를 구할 수 있다.
//왜 둘의 나머지가 같은 값의 경우의 수를 구하냐면 [i,j]구간의 합은 sum[j] - sum[i]이고,
//구간의 합이 M으로 떨어지는 (i,j)는 (sum[j]-sum[i])%M == 0이 되면 M으로 떨어지는 것이다.
//이 식을 모듈러 연산으로 해보면 sum[j]%M == sum[i]%M이 되는 것으로 sum의 나머지가 같은 값 끼리 두개씩 고르는 경우의 수를 고르면 된다.
//즉, dp[i]에는 나머지가 i인 sum의 개수가 들어 있으므로 그 개수에서 두개씩 고르는 조합의 공식은 dp[i] * (dp[i] - 1) / 2;이다.

//n까지 더한 값에서 m인 값의 개수
long long dp[1001];
int sum[1000001];
int N, M;

inline long long calculate() {
	long long rst = 0;
	for (int i = 0; i < M; i++) {
		if (dp[i] == 0) continue;
		rst += dp[i] * (dp[i] - 1) / 2;
	}
	return rst + dp[0];
}

int main() {
	scanf("%d %d", &N, &M);
	for (int k = 1; k <= N; k++) {
		int value;
		scanf("%d", &value);
		(sum[k] = sum[k - 1] + value) %= M;
		dp[sum[k]]++;

	}
	printf("%lli", calculate());
}