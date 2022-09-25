#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

//백준 1389 케빈 베이컨의 6단계 법칙
//어려운 부분은 없었다.

int N, M;
std::vector< std::vector<int> > data;
std::vector<int> ans;

int calculate() {
	int cmp = INT_MAX;
	int ans = -1;
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (data[i][k] && data[k][j]) {
					if (i != k && k != j && i != j) {
						if (data[i][j]) data[i][j] = std::min(data[i][j], data[i][k] + data[k][j]);
						else data[i][j] = data[i][k] + data[k][j];
					}
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		int kevin = 0;
		for (int j = 0; j < N; j++) {
			if (i != j) kevin += data[i][j];
		}
		if (kevin < cmp) {
			cmp = kevin;
			ans = i;
		}
	}

	return ans + 1;
}

int main() {
	scanf("%d %d", &N, &M);
	data.assign(N, std::vector<int>(N, 0));
	ans.assign(N, 0);

	for (int k = 0; k < M; k++) {
		int a, b;
		scanf("%d %d", &a, &b);
		data[a - 1][b - 1] = 1;
		data[b - 1][a - 1] = 1;
	}

	printf("%d", calculate());
}