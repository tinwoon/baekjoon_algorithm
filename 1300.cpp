#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

//1300 k��° �� ����
//�������� �κ��� ������ ������ �ش�
//�ش� �˰����� �������

long long N, C;
long long ans = LLONG_MAX;

long long calculate() {
	long long begin = 1;
	long long end = N * N;

	while (begin <= end) {
		long long mid = (begin + end) / 2;
		long long count = 0;
		for (int k = 1; k <= N; k++) {
			count += std::min(mid / (long long)k, N);
		}

		if (count < C) {
			begin = mid + 1;
		}
		else if (count >= C) {
			ans = std::min(ans, mid);
			end = mid - 1;
		}
	}
	return ans;
}

int main() {
	scanf("%lld", &N);
	scanf("%lld", &C);

	printf("%lld", calculate());
}