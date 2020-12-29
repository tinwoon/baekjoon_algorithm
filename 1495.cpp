#include <iostream>
#include <vector>
#include <algorithm>

//dp라기보단 시뮬레이터에 가까웠던 문제
//dp의 방식을 따르지 않음

std::vector< std::vector<bool> > possible;
std::vector<int> volume;
int N, S, M;

int calculate() {
	possible[0][S] = true;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (possible[i-1][j]==true) {
				if (j + volume[i - 1] >= 0 && j + volume[i - 1] <= M) {
					possible[i][j + volume[i - 1]] = true;
				}
				if (j - volume[i - 1] >= 0 && j - volume[i - 1] <= M) {
					possible[i][j - volume[i - 1]] = true;
				}
			}
		}
	}

	for (int j = M; j >= 0; j--) {
		if (possible[N][j]) return j;
	}

	return -1;
}

int main() {
	scanf("%d %d %d", &N, &S, &M);
	volume.assign(N,0);
	possible.assign(N + 1, std::vector<bool>(M + 1, false));
	for (int i = 0; i < N; i++) {
		scanf("%d", &volume[i]);
	}
	printf("%d", calculate());
}
