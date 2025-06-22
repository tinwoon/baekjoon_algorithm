#pragma warning (disable : 4996)
#include <iostream>
#include <vector>

#define W 0
#define B 1

int N, M;
std::vector< std::vector<bool> > map;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

void calculate() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
					map[nx][ny] = !map[nx][ny];
				}
			}
		}
	}

	printf("1\n");

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d", map[i][j] + 2);
		}
		printf("\n");
	}
}

int main() {
	scanf("%d %d", &N, &M);
	map.assign(N, std::vector<bool>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c;
			scanf(" %1c", &c);

			if (c == 'B') map[i][j] = B;
		}
	}

	calculate();
}