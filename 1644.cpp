#pragma warning (disable : 4996)
#include <iostream>
#include <math.h>
#include <vector>

//�Ҽ��� ���� �� ����
//�����佺�׳׽��� �Ҽ��� �������͸� Ȱ���ϸ� ������ �� �� �ִ�.
//����صα�!

int N;
std::vector<bool> is_prime;
std::vector<int> prime;

void eratos() {
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i <= sqrt(N); i++) {
		for (int j = i * i; j <= N; j += i) {
			is_prime[j] = false;
		}
	}

	for (int k = 1; k <= N; k++) {
		if (is_prime[k]) prime.emplace_back(k);
	}
}

int two_pointer(int a, int b) {
	int ans = 0;
	std::vector<int> sum(prime.size(), 0);
	for (int k = 0; k < prime.size(); k++) {
		if (k == 0) sum[k] = prime[k];
		else sum[k] = sum[k - 1] + prime[k];
	}

	while (a <= b && b < prime.size()) {
		int diff = (a == 0) ? sum[b] : sum[b] - sum[a - 1];
		if (diff < N) b++;
		else if (diff > N) a++;
		else {
			ans++;
			b++;
		}
	}
	return ans;
}

int main() {
	scanf("%d", &N);
	is_prime.assign(N + 1, true);
	eratos();
	printf("%d", two_pointer(0, 0));
}