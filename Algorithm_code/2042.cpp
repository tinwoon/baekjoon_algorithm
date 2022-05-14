#pragma warning (disable:4996)
#include <iostream>
#include <vector>

//2042 구간합 문제
//전형적인 펜윅트리를 작성하는 문제
//개인적으로 굉장히 세상에 천재는 많다는 생각을 느끼게 해준 문제이다.
//정형화되어 있는 공식이 없지만 과정을 기억해야한다.

long long N, M, K;
std::vector<long long> data;
std::vector<long long> prefix;
std::vector<long long> tree;

//n번의 segment prefix를 구하는 함수
void set_tree() {

	for (long long index = 1; index <= N; index++) {
		long long sum_v = 0;
		for (long long k = index; k >= index - (index & -(1 * index)) + 1; k--) {
			sum_v += data[k];
		}
		prefix[index] = sum_v;
	}

}

void change_prefix(long long b, long long c) {
	long long index = (long long)b;
	while (index <= N) {
		prefix[index] = prefix[index] - data[b] + c;
		index += (index & (-1 * index));
	}
	data[b] = c;
}

void print_prefix(long long b, long long c) {
	long long index = (long long)b - 1;
	long long first = 0;
	long long second = 0;
	while (index >= 1) {
		first += prefix[index];
		index -= (index & (-1 * index));
	}
	index = c;
	while (index >= 1) {
		second += prefix[index];
		index -= (index & (-1 * index));
	}
	printf("%lld\n", second - first);
}

int main() {
	scanf("%lld %lld %lld", &N, &M, &K);
	prefix.assign(N + 1, 0);
	data.assign(N + 1, 0);
	for (long long k = 1; k <= N; k++) {
		scanf("%lld", &data[k]);
	}
	set_tree();
	for (long long k = 0; k < M + K; k++) {
		long long a, b, c;
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1) change_prefix(b, c);
		else print_prefix(b, c);
	}

}