//체스판 여행 1 문제
// 이전의 배달 문제와 마찬가지로 값을 visited(dp)의 방문 상태마다 3중 4중 배열로 선언하는 것이 핵심이다.

#pragma warning(disable: 4996)
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <tuple>

#define KNIGHT 0
#define LOOK   1
#define BISHOP 2

int N;
int map[11][11];
//x,y를 k번 말로 N번 째 방문
int dp[11][11][3][101];
std::pair<int, int> start;
int knight_dx[8] = { -2, -2, -1, -1, 1 ,2 ,1, 2 };
int knight_dy[8] = { -1, 1, -2, 2, -2, -1, 2, 1 };
int look_dx[4] = { -1, 0,1,0 };
int look_dy[4] = { 0,1,0,-1 };
int bishop_dx[4] = { -1, -1, 1, 1 };
int bishop_dy[4] = { -1, 1, -1, 1 };

int bfs() {
	std::queue < std::tuple<int, int, int, int> > q;
	for (int k = 0; k < 3; k++) {
		q.emplace(std::make_tuple(start.first, start.second, k, 1));
		dp[start.first][start.second][k][1] = 0;
	}

	while (!q.empty()) {
		int x, y, pieces_kind, num;
		std::tie(x, y, pieces_kind, num) = q.front();
		q.pop();

		if (num == N * N) return dp[x][y][pieces_kind][num];

		if (pieces_kind == KNIGHT) {
			for (int k = 0; k < 8; k++) {
				int nx = x + knight_dx[k];
				int ny = y + knight_dy[k];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
					if (map[nx][ny] == num + 1 && dp[nx][ny][KNIGHT][num + 1] == -1) {
						q.emplace(std::make_tuple(nx, ny, KNIGHT, num + 1));
						dp[nx][ny][KNIGHT][num + 1] = dp[x][y][pieces_kind][num] + 1;
					}
					else if (dp[nx][ny][KNIGHT][num] == -1) {
						q.emplace(std::make_tuple(nx, ny, KNIGHT, num));
						dp[nx][ny][KNIGHT][num] = dp[x][y][pieces_kind][num] + 1;
					}
				}
			}
		}
		else if (pieces_kind == LOOK) {
			for (int k = 0; k < 4; k++) {
				int nx = x, ny = y;
				while (1) {
					nx += look_dx[k];
					ny += look_dy[k];
					if (nx >= N || nx < 0 || ny >= N || ny < 0) break;
					if (map[nx][ny] == num + 1 && dp[nx][ny][LOOK][num + 1] == -1) {
						q.emplace(std::make_tuple(nx, ny, LOOK, num + 1));
						dp[nx][ny][LOOK][num + 1] = dp[x][y][pieces_kind][num] + 1;
					}
					else if (dp[nx][ny][LOOK][num] == -1) {
						q.emplace(std::make_tuple(nx, ny, LOOK, num));
						dp[nx][ny][LOOK][num] = dp[x][y][pieces_kind][num] + 1;
					}
				}
			}
		}
		else if (pieces_kind == BISHOP) {
			for (int k = 0; k < 4; k++) {
				int nx = x, ny = y;
				while (1) {
					nx += bishop_dx[k];
					ny += bishop_dy[k];
					if (nx >= N || nx < 0 || ny >= N || ny < 0) break;
					if (map[nx][ny] == num + 1 && dp[nx][ny][BISHOP][num + 1] == -1) {
						q.emplace(std::make_tuple(nx, ny, BISHOP, num + 1));
						dp[nx][ny][BISHOP][num + 1] = dp[x][y][pieces_kind][num] + 1;
					}
					else if (dp[nx][ny][BISHOP][num] == -1) {
						q.emplace(std::make_tuple(nx, ny, BISHOP, num));
						dp[nx][ny][BISHOP][num] = dp[x][y][pieces_kind][num] + 1;
					}
				}
			}
		}

		for (int prs_kind = 0; prs_kind < 3; prs_kind++) {
			if (prs_kind == pieces_kind) continue;
			if (dp[x][y][prs_kind][num] == -1) {
				q.emplace(std::make_tuple(x, y, prs_kind, num));
				dp[x][y][prs_kind][num] = dp[x][y][pieces_kind][num] + 1;
			}
		}
	}
}

int main() {
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) start = std::make_pair(i, j);
		}
	}
	printf("%d", bfs());
}