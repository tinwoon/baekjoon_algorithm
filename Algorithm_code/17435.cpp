#pragma warning (disable : 4996)
#include <iostream>
#include <vector>

//17435 백준 합성함수와 쿼리 문제
//전형적인 희소배열(Sparse Table 문제)
//다만 기존의 LCA2와 같이 lg 값을 구하는 것보다 최대치인 2^18까지 구하는게
//시간 복잡도 상 절야고딜 가능성이 높음.

int m, Q, n, x, max_n;
std::vector<int> f;
std::vector< std::vector<int> > F;

void init() {
	//2^0~18 까지만 있으면 됨.(2^18 = 524288)
	//F[a][b]의 b노드의 2^a번째 조상
	F.assign(19, std::vector<int>(m + 1, 0));

	for (int k = 1; k < m + 1; k++) {
		F[0][k] = f[k];
	}

	for (int i = 1; i <= 18; i++) {
		for (int j = 1; j <= m; j++) {
			F[i][j] = F[i - 1][F[i - 1][j]];
		}
	}
}

int calculate(int n, int x) {
	for (int k = 18; k >= 0; k--) {
		if ((1 << k) <= n) {
			x = F[k][x];
			n -= (1 << k);
		}
	}
	return x;
}

int main() {
	scanf("%d", &m);
	f.assign(m + 1, 0);

	for (int k = 1; k <= m; k++) {
		scanf("%d", &f[k]);
	}
	init();
	scanf("%d", &Q);
	for (int k = 0; k < Q; k++) {
		scanf("%d %d", &n, &x);
		printf("%d\n", calculate(n, x));
	}

}