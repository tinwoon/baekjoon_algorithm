#include <iostream>
#include <vector>
#include <string.h>

//소코반 문제
//그냥 구현이다.

char map[15][15];
char dir[51];
std::pair<int, int> character;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };


int N, M;
int complete = 0;

void calculate(int count, int cmd_len) {
	int cmd_count = 0;
	while (cmd_count != cmd_len) {

		if (complete == 0) break;

		int k;
		if (dir[cmd_count] == 'U') k = 0;
		if (dir[cmd_count] == 'R') k = 1;
		if (dir[cmd_count] == 'D') k = 2;
		if (dir[cmd_count] == 'L') k = 3;
		cmd_count++;

		if (map[character.first + dx[k]][character.second + dy[k]] == '#') continue;

		else if (map[character.first + dx[k]][character.second + dy[k]] == '.') {
			if (map[character.first][character.second] == 'W') {
				map[character.first + dx[k]][character.second + dy[k]] = 'w';
				map[character.first][character.second] = '+';
			}
			else {
				map[character.first + dx[k]][character.second + dy[k]] = 'w';
				map[character.first][character.second] = '.';
			}
			character = std::make_pair(character.first + dx[k], character.second + dy[k]);
		}
		else if (map[character.first + dx[k]][character.second + dy[k]] == 'b' || map[character.first + dx[k]][character.second + dy[k]] == 'B') {
			if (map[character.first][character.second] == 'W' && (map[character.first + 2 * dx[k]][character.second + 2 * dy[k]] == '.' || map[character.first + 2 * dx[k]][character.second + 2 * dy[k]] == '+')) {
				if (map[character.first + 2 * dx[k]][character.second + 2 * dy[k]] == '.') map[character.first + 2 * dx[k]][character.second + 2 * dy[k]] = 'b';
				else {
					map[character.first + 2 * dx[k]][character.second + 2 * dy[k]] = 'B';
					complete--;
				}
				if (map[character.first + dx[k]][character.second + dy[k]] == 'B') {
					map[character.first + dx[k]][character.second + dy[k]] = 'W';
					complete++;
				}
				else map[character.first + dx[k]][character.second + dy[k]] = 'w';
				map[character.first][character.second] = '+';
			}
			else if (map[character.first][character.second] == 'w' && (map[character.first + 2 * dx[k]][character.second + 2 * dy[k]] == '.' || map[character.first + 2 * dx[k]][character.second + 2 * dy[k]] == '+')) {
				if (map[character.first + 2 * dx[k]][character.second + 2 * dy[k]] == '.') map[character.first + 2 * dx[k]][character.second + 2 * dy[k]] = 'b';
				else {
					map[character.first + 2 * dx[k]][character.second + 2 * dy[k]] = 'B';
					complete--;
				}
				if (map[character.first + dx[k]][character.second + dy[k]] == 'B') {
					map[character.first + dx[k]][character.second + dy[k]] = 'W';
					complete++;
				}
				else map[character.first + dx[k]][character.second + dy[k]] = 'w';
				map[character.first][character.second] = '.';
			}
			else continue;
			character = std::make_pair(character.first + dx[k], character.second + dy[k]);
		}
		else if (map[character.first + dx[k]][character.second + dy[k]] == '+') {
			if (map[character.first][character.second] == 'W') {
				map[character.first + dx[k]][character.second + dy[k]] = 'W';
				map[character.first][character.second] = '+';
			}
			else {
				map[character.first + dx[k]][character.second + dy[k]] = 'W';
				map[character.first][character.second] = '.';
			}
			character = std::make_pair(character.first + dx[k], character.second + dy[k]);
		}
	}

	printf("Game %d: ", count);
	if (complete == 0) printf("complete\n");
	else printf("incomplete\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int count = 0;
	while (1) {
		complete = 0;
		scanf("%d %d", &N, &M);
		if (N == 0 && M == 0) break;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf(" %1c", &map[i][j]);
				if (map[i][j] == 'w' || map[i][j] == 'W') character = std::make_pair(i, j);
				if (map[i][j] == '+' || map[i][j] == 'W') complete++;
			}
		}
		scanf("%s", dir);
		calculate(++count, strlen(dir));
	}
}