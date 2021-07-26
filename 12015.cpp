#include <iostream>
#include <vector>
#include <limits.h>

//꼭 외워야할 lis 알고리즘
//기존의 n^2형태의 lis 보다 훨씬 빠르며
//코드도 간편하고 메모리도 절약할 수 있다.
//즉, 모든게 완벽하니 외우는 것이 좋다. 
 

int N;
std::vector<int> dp;
std::vector<int> value;

int calculate() {
	value.emplace_back(INT_MIN);
	int count = 0;
	for (int k = 0; k < N; k++) {
		if (value.back() < dp[k]) {
			value.emplace_back(dp[k]);
			count++;
		}
		else {
			*std::lower_bound(value.begin(), value.end(), dp[k]) = dp[k];
		}
	}
	return count;
}

int main() {
	scanf("%d", &N);
	dp.assign(N, 0);
	for (int k = 0; k < N; k++) {
		scanf("%d", &dp[k]);
	}
	printf("%d", calculate());
}
