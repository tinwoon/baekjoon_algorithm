#include <iostream>
#include <vector>
#include <algorithm>

std::vector< std::vector<int> > value;
int N, M;

//비트마스크 이용
//가로의 값은 1일때
//세로의 값은 0일때로 가정함
int calculate() {
	int max = 0;
	for (int s = 0; s < (1 << N * M); s++) {
		int sum = 0;

		//가로
		for (int i = 0; i < N; i++) {
			int cur = 0;
			for (int j = 0; j <M; j++) {
				if ( ( s & ( 1 << ( i * M + j ) ) ) == 0) {
					cur = cur*10 + value[i][j];
				}
				else {
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}

		//세로
		for (int i = 0; i < M; i++) {
			int cur = 0;
			for (int j = 0; j <N; j++) {
				if ( ( s & ( 1 << ( j * M + i ) ) ) != 0) {
					cur = cur * 10 + value[j][i];
				}
				else {
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}
		max = std::max(max, sum);
	}
	return max;
}



int main() {
	scanf("%d %d", &N, &M);
	value.assign(N, std::vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &value[i][j]);
		}
	}
	printf("%d", calculate());
}
