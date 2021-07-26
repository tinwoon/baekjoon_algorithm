#include <iostream>
#include <vector>
#include <algorithm>

//투포인터 문제인데 생각보다 어려웠다
//투포인터의 경우 맨 처음부터 같이 시작하는 경우와 서로 따로 시작하는 점이 있다는 것을 알아두어야 한다. 

std::vector<long long> cmd;
long long n, ans, match;

void calculate(long long a, long long b) {
	if (a == b) return;
	long long sum = cmd[a] + cmd[b];
	if (sum > match) {
		calculate(a, b - 1);
	}
	else {
		if (sum == match) ans++;
		calculate(a + 1, b);
	}
	return;
}

int main() {
	scanf("%d", &n);
	for (int k = 0; k < n; k++) {
		long long value;
		scanf("%lld", &value);
		cmd.emplace_back(value);
	}
	std::sort(cmd.begin(), cmd.end());
	scanf("%lld", &match);
	if (n == 1) printf("0");
	else {
		calculate(0, n - 1);
		printf("%lld", ans);
	}
}
