#include <iostream>
#include <vector>
#include <string.h>


//올바른 괄호 문자열
//점화식 규칙을 결국 못찾아 답안을 확인함
//경우의 수로 생각하면 된다. 괄호를 하나 만들수 있으면 그 부분 내부의 괄호를 만들 수 있는 경우 * 그 외부의 괄호를 만들 수 있는 부분의 경우이다. 

int N;
std::string map;
long long mode = 100000;
std::string open = "[{(";
std::string close = "]})";
//i부터 j까지 만들 수 있는 문자열의 개수
long long dp[201][201];

long long calculate(int i, int j) {

	if (i > j) {
		return 1;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	dp[i][j] = 0;
	for (int k = i + 1; k <= j; k+=2) {
		for (int l = 0; l < 3; l++) {
			if (map[i] == open[l] || map[i] == '?') {
				if (map[k] == close[l] || map[k] == '?') {
					long long value = calculate(i + 1, k - 1) * calculate(k + 1, j);
					dp[i][j] += value;
					if (dp[i][j] >= mode) {
						dp[i][j] = mode + dp[i][j] % mode;
					}
				}
			}
		}
	}
	return dp[i][j];
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	std::cin >> map;
	long long ans = calculate(0, N - 1);
	if (ans >= mode) {
		printf("%05lld\n", ans % mode);
	}
	else {
		printf("%lld\n", ans);
	}
}
