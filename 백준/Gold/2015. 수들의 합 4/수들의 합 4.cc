#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <map>
#include <set>
#define ll (long long)

int N, M;
std::vector<int> sum;
//k의 값을 가지는 합의 개수
std::map<int, int> p;

int main() {
	int v;
	long long ans;
	scanf("%d %d", &N, &M);
	sum.assign(N, 0);

	scanf("%d", &sum[0]);
	ans = ll(sum[0] == M ? 1 : 0);
	p[sum[0]]++;
	for (int k = 1; k < N; k++) {
		scanf("%d", &v);
		sum[k] = sum[k - 1] + v;
		ans += (sum[k] == M ? 1 : 0);
		if (p.count(sum[k] - M) != 0) {
			ans += ll(p[sum[k] - M]);
		}
		p[sum[k]]++;
	}

	printf("%lld", ans);
}