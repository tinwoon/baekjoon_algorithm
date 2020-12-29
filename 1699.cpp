#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

int N;
std::vector<int> dp;

int calculate() {
	int stack = 0;
	int zegob_count = 1;
	for (int i = 1; i <= N; i++) {
		if (i == pow(zegob_count, 2)) {
			dp[i] = 1;
			//stack = i;
			zegob_count++;
		}
		else {
			for (int j = zegob_count - 1 ; j >= 1; j--) {
				dp[i] = std::min(dp[i], dp[pow(j,2)] + dp[i - pow(j,2)]);
			}
			 
		}
	}

	return dp[N];
}



int main() {
	scanf("%d", &N);
	dp.assign(N + 1, 100001);
	printf("%d", calculate());
}
