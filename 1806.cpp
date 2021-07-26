#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

//1806 �κ����� ������ �������͸� Ȱ���� �����̴�.
///�κ��հ� �������� ��� ������ �� ������ ��� ����ϴ°� ����.

std::vector<long long> sum;
int N, S;
long long length = LLONG_MAX;

//a=0 b=0�� ����
void calculate(int a, int b) {
	while (a <= b && b < N) {
		long long prefix_sum = a == 0 ? sum[b] : sum[b] - sum[a - 1];
		if (prefix_sum < S) {
			b++;
		}
		else {
			length = std::min((long long)b - (long long)a + (long long)1, length);
			a++;
		}
	}
}

int main() {
	scanf("%d %d", &N, &S);
	sum.assign(N, 0);
	for (int k = 0; k < N; k++) {
		long long value;
		scanf("%lld", &value);
		if (k == 0) sum[k] = value;
		else sum[k] = sum[k - 1] + value;
	}
	calculate(0, 0);
	printf("%lld", length == LLONG_MAX ? 0 : length);
}