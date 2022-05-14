#include <iostream>
#include <vector>
#include <algorithm>


//설마 설마했는데 이 날 코딩이 답이다...

int main() {
	int M, N;
	scanf("%d  %d", &N, &M);
	std::vector< std::vector<int> >map(N,std::vector<int>(M,0));
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//1
			if (j + 3 < M) {
				sum = std::max(sum, map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3]);
			}
			//2
			if (i + 3 < N) {
				sum = std::max(sum, map[i][j] + map[i+1][j] + map[i+2][j] + map[i+3][j]);
			}
			//3
			if ( i+1<N && j+1<M ) {
				sum = std::max(sum, map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j]);
			}
			//4
			if (i + 2 < N && j + 1 < M) {
				sum = std::max(sum, map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1]);
			}
			//5
			if (i - 1 > -1 && j + 2 < M) {
				sum = std::max(sum, map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 2]);
			}
			//6
			if (i + 2 < N && j + 1 < M) {
				sum = std::max(sum, map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1]);
			}
			//7
			if (i + 1 < N && j + 2 < M) {
				sum = std::max(sum, map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j]);
			}
			//8
			if (i - 2 > -1 && j + 1 < M) {
				sum = std::max(sum, map[i][j] + map[i][j + 1] + map[i - 1][j + 1] + map[i - 2][j + 1]);
			}
			//9
			if (i + 1 < N && j + 2 < M) {
				sum = std::max(sum, map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 2]);
			}
			//10
			if (i + 2 < N && j + 1 < M) {
				sum = std::max(sum, map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 2][j]);
			}
			//11
			if (i + 1 < N && j + 2 < M) {
				sum = std::max(sum, map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2]);
			}
			//12
			if (i + 2 < N && j + 1 < M) {
				sum = std::max(sum, map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j]);
			}
			//13
			if (i - 1 > -1 && j + 2 < M) {
				sum = std::max(sum, map[i][j] + map[i][j + 1] + map[i - 1][j + 1] + map[i][j + 2]);
			}
			//14
			if (i + 2 < N && j - 1 > -1) {
				sum = std::max(sum, map[i][j] + map[i + 1][j] + map[i + 1][j - 1] + map[i + 2][j]);
			}
			//15
			if (i + 1 < N && j +2 < M) {
				sum = std::max(sum, map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1]);
			}
			//16
			if (i + 2 < N && j + 1 < M) {
				sum = std::max(sum, map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1]);
			}
			//17
			if (i - 1 > -1 && j + 2 < M) {
				sum = std::max(sum, map[i][j] + map[i][j + 1] + map[i - 1][j + 1] + map[i - 1][j + 2]);
			}
			//18
			if (i - 2 > -1 && j + 1 < M) {
				sum = std::max(sum, map[i][j] + map[i - 1][j] + map[i - 1][j + 1] + map[i - 2][j + 1]);
			}
			//19
			if (i + 1 < N && j + 2 < M) {
				sum = std::max(sum, map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2]);
			}
		}
	}
	printf("%d", sum);

}
