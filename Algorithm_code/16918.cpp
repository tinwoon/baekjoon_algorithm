#pragma warning (disable : 4996)
#include <iostream>
#include <vector>

std::vector< std::vector<int> > map;
int R, C, N;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

//16918 붐버맨 문제
//굉장히 까다로운 문제에 규칙이 0,1 번은 개별적이고 그 이후부터 반복된다는 점을 알아야한다. 

void calculate(int level) {

	if (level == N + 1) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] > 0) printf("O");
				else printf(".");
			}
			printf("\n");
		}
		return;
	}


	if (level == 1) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if(map[i][j] !=0) map[i][j]--;
			}
		}
	}
	else if (level % 2 == 1) {
		auto map_tmp = map;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] == 1) {
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
							map_tmp[nx][ny] = 0;
						}
					}
					map_tmp[i][j] = 0;
				}
				else if(map_tmp[i][j] !=0) map_tmp[i][j] = map[i][j] - 1;
			}
		}
		map = map_tmp;
	}
	else if (level%2 == 0) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] == 0) map[i][j] = 3;
				else map[i][j]--;
			}
		}
	}

	calculate(level + 1);


}

int main() {
	scanf("%d %d %d", &R, &C, &N);
	map.assign(R, std::vector<int>(C, 0));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			char value;
			scanf(" %1c", &value);
			if (value == 'O') map[i][j] = 3;
			else map[i][j] = 0;
		}
	}

	calculate(1);

}
