#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector< std::vector<int> >value;
std::vector< std::vector<int> >dp;

//오래 생각한 보람이 있었네!

int calculate(int n) {
	if(n>=1){
		dp[1][1] = value[1][1];
		dp[0][1] = value[0][1];
	}
	for (int j = 2; j <= n; j++) {
		for (int i = 0; i < 2; i++) {
			if (i == 0) {
				dp[i][j] = std::max({ dp[1][j - 1] + value[i][j], dp[1][j - 2] + value[i][j], dp[i][j - 2] + value[i][j] });
			}
			else {
				dp[i][j] = std::max({dp[0][j - 1] + value[i][j], dp[0][j - 2] + value[i][j], dp[i][j - 2] + value[i][j]});
			}
		}
	}
	return std::max(dp[1][n], dp[0][n]);
}

int main() {
	scanf("%d", &N);
	while (N--) {
		int n = 0;
		scanf("%d", &n);
		value.assign(2, std::vector<int>(n+1, 0));
		dp.assign(2, std::vector<int>(n+1, 0));

		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &value[i][j]);
			}
		}
		printf("%d\n", calculate(n));
	}
}
