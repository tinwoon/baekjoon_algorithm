#include <iostream>
#include <vector>
#include <algorithm>

std::vector< std::vector<int> >dp;

//카탈란 수 공부하기
// 4시간쯤 걸림
// i를 문자열의 길이라 하고 j를 닫히지 않은 수라 가정하면
// 길이가 i이고 닫히지 않은 수가 j인 값은 길이가 i-1이면서 닫힌 수가 j-1에 "("를 추가한 것에다가
// 길이가 i-1이면서 닫힌 수가 j+1인 수에 ")"를 추가한 것이랑 같다.

int calculate(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i < j) continue;
			if (i == j) {
				dp[i][j] = 1;
				continue;
			}
			if (i - 1 >= 1 && j + 1 <= n) {
				dp[i][j] += dp[i - 1][j + 1] % 1000000007;
			}
			if (i - 1 >= 1 && j - 1 >= 0) {
				dp[i][j] += dp[i - 1][j - 1] % 1000000007;
			}
		}
	}

	return dp[n][0];
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		dp.assign(n + 1, std::vector<int>(n + 1, 0));
		if (n % 2 == 1) printf("0\n");
		else printf("%d\n", calculate(n));
	}
}
