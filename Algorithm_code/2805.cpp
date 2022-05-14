#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

//나무 자르기 문제
//랜선 자르기랑 다를게 없다.

long long N, M;
std::vector<long long> tree;
long long begin = 0;
long long end = LLONG_MIN;
long long ans = 0;

long long calculate() {

	while (begin <= end) {
		long long mid = (begin + end) / 2;
		long long rst = 0;
		for (int k = 0; k < N; k++) {
			rst += (tree[k] - mid) >= 0 ? tree[k] - mid : 0;
		}
		if (rst >= M) {
			begin = mid + 1;
			ans = std::max(ans, mid);
		}
		else end = mid - 1;
	}
	return ans;
}

int main() {
	scanf("%d %d", &N, &M);
	tree.assign(N, 0);
	for (int k = 0; k < N; k++) {
		scanf("%d", &tree[k]);
		end = std::max(end, tree[k]);
	}
	printf("%lld", calculate());
}