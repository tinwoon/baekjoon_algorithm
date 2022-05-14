#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

//랜선 자르기 문제
//전형적인 이분탐색 파라메트릭 서치 문제

int N, K;
std::vector<int> lan;
long long rst = LLONG_MIN;

int calculate() {
	long long begin = 0;
	long long end = *std::max_element(lan.begin(), lan.end());
	while (begin <= end) {
		long long mid = (begin + end) / 2;
		if (mid == 0) mid = 1;
		long long ans = 0;
		for (int k = 0; k < K; k++) {
			ans += (long long)lan[k] / mid;
		}
		if (ans < (long long)N) end = mid - 1;
		else if (ans >= (long long)N) {
			rst = std::max(rst, mid);
			begin = mid + 1;
		}
	}
	return rst;
}

int main() {
	scanf("%d %d", &K, &N);
	lan.assign(K, 0);
	for (int k = 0; k < K; k++) {
		scanf("%d", &lan[k]);
	}
	printf("%d", calculate());
}
