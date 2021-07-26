#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

//두 용액 투포인터 문제
//딱히 어려운 부분 없.

std::vector<int> cmd;
int N;
std::pair<int, int> ans;
long long ans_value = LLONG_MAX;

void calculate(int a, int b) {
	while (a < b) {
		long long sum = (long long)cmd[a] + (long long)cmd[b];
		int n_a = a, n_b = b;
		if (sum < 0) n_a++;
		else n_b--;
		if (llabs(sum) < ans_value) {
			ans = std::make_pair(cmd[a], cmd[b]);
			ans_value = llabs(sum);
		}
		a = n_a;
		b = n_b;
	}
}

int main() {
	scanf("%d", &N);
	cmd.assign(N, 0);
	for (int k = 0; k < N; k++) {
		scanf("%d", &cmd[k]);
	}
	std::sort(cmd.begin(), cmd.end());
	calculate(0, N - 1);
	printf("%d %d", ans.first, ans.second);
}