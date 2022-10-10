#pragma warning (disable : 4996)
#include <iostream>
#include <vector>

//백준 1553 길의 개수
//시간초과의 이유를 알 수 없는 문제

int N, T, S, E;
std::vector< std::vector<long long> > connect;


void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			connect[i * 5 + j + 1][i * 5 + j] = 1;
		}
	}
}

std::vector< std::vector<long long> > zegob(std::vector< std::vector<long long> > a, std::vector< std::vector<long long> > b) {

	std::vector< std::vector<long long> > ret(5 * N, std::vector<long long>(5 * N, 0));

	for (int i = 0; i < 5 * N; i++) {
		for (int j = 0; j < 5 * N; j++) {
			for (int k = 0; k < 5 * N; k++) {
				ret[i][j] += a[i][k] * b[k][j];
				ret[i][j] %= 1000003;
			}
		}
	}
	return ret;
}

std::vector< std::vector<long long> > multiply(long long T) {
	if (T == 1) return connect;

	if (T & 1) {
		return zegob(multiply(1), multiply(T - 1));
	}
	return zegob(multiply(T / 2), multiply(T / 2));
}

int main() {
	scanf("%d %d %d %d", &N, &S, &E, &T);
	connect.assign(5 * N, std::vector<long long>(5 * N, 0));
	init();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			long long value;
			scanf(" %1lld", &value);
			if (value >= 1) {
				connect[i * 5][j * 5 + (value - 1)] = 1;
			}
		}
	}
	printf("%lld\n", multiply((long long)T)[(S - 1) * 5][(E - 1) * 5]);
}