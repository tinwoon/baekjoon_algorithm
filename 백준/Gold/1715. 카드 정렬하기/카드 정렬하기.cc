#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int N;
std::priority_queue<int> pq;

long long calculate() {
	long long ret = 0;
	if (pq.size() == 1) return ret;

	while (pq.size() != 1) {
		long long first, second;
		first = -1*pq.top();
		pq.pop();
		second = -1*pq.top();
		pq.pop();

		ret += (first + second);
		pq.emplace(-1 * first - 1 * second);
	}

	return ret;
}

int main() {
	scanf("%d", &N);

	for (int k = 0; k < N; k++) {
		int v;
		scanf("%d", &v);
		pq.emplace(-1*v);
	}
	printf("%lld", calculate());
}