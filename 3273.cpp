#include <iostream>
#include <vector>
#include <algorithm>

//3273�� �� ���� ��
//�������� �������� ������ ���ε� ����� ��Ű�� �ʰ� Ǯ��

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