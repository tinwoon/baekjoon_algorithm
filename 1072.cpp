#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

//1072번
//게임 문제
//그냥 이분탐색이라 써있습니다.

long long X, Y, Z;

long long calculate() {
	long long begin = 0;
	long long end = X;
	long long ans = LLONG_MAX;
	while (begin <= end) {
		long long mid = (begin + end) / 2;

		long long value = (long long)(Y + mid) * 100 / (X + mid);

		if (value != Z) {
			ans = std::min(ans, mid);
			end = mid - 1;
		}
		else {
			begin = mid + 1;
		}

	}
	return ans == LLONG_MAX ? -1 : ans;
}

int main() {
	scanf("%lld %lld", &X, &Y);
	Z = Y * 100 / X;
	printf("%lld", calculate());
}