#pragma warning (disable : 4996)
#include <iostream>
#include <vector>

//2099 The game of death 문제
//전형적인 행렬 제곱의 최적화 알고리즘
//어려운 부분은 없었으므로, 생략 가능하다.


std::vector< std::vector<int> > connected;

int N, M, K;

std::vector< std::vector<int> > zegob(std::vector< std::vector<int> > a, std::vector< std::vector<int> > b) {

	std::vector< std::vector<int> > ret(N, std::vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				ret[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	return ret;
}

std::vector< std::vector<int> > calculate(int N) {
	std::vector< std::vector<int> > ret;

	if (N == 1) return ret = connected;
	ret = calculate(N / 2);
	ret = zegob(ret, ret);
	if (N % 2 == 1) return ret = zegob(ret, connected);
	return ret;
}

int main() {
	scanf("%d %d %d", &N, &M, &K);

	int a, b;
	connected.assign(N, std::vector<int>(N, 0));

	for (int k = 0; k < N; k++) {
		scanf("%d %d", &a, &b);
		connected[k][a - 1] = true;
		connected[k][b - 1] = true;
	}

	connected = calculate(M);

	while (K--) {
		scanf("%d %d", &a, &b);
		if (connected[a - 1][b - 1]) printf("death\n");
		else printf("life\n");
	}

}