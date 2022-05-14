#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>


//15810 풍선문제
//입국심사와 같은 문제입니다.

long long N, M;
std::vector<long long> time;
long long ans = LLONG_MAX;

long long calculate() {
	long long begin = 0;
	long long end = time[N - 1] * M;

	while (begin <= end) {
		long long mid = (begin + end) / 2;

		long long ballon = 0;

		for (int k = 0; k < N; k++) ballon += mid / time[k];

		if (ballon >= M) {
			end = mid - 1;
			ans = std::min(ans, mid);
		}
		else {
			begin = mid + 1;
		}
	}

	return ans;
}

int main() {
	scanf("%lld %lld", &N, &M);
	time.assign(N, 0);
	for (int k = 0; k < N; k++) {
		scanf("%lld", &time[k]);
	}
	std::sort(time.begin(), time.end());
	printf("%lld", calculate());
}