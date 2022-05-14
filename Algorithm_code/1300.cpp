#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

//1300 k번째 수 문제
//수학적인 부분이 굉장한 영감을 준다
//해당 알고리즘은 기억하자

long long N, C;
long long ans = LLONG_MAX;

long long calculate() {
	long long begin = 1;
	long long end = N * N;

	while (begin <= end) {
		long long mid = (begin + end) / 2;
		long long count = 0;
		for (int k = 1; k <= N; k++) {
			count += std::min(mid / (long long)k, N);
		}

		if (count < C) {
			begin = mid + 1;
		}
		else if (count >= C) {
			ans = std::min(ans, mid);
			end = mid - 1;
		}
	}
	return ans;
}

int main() {
	scanf("%lld", &N);
	scanf("%lld", &C);

	printf("%lld", calculate());
}