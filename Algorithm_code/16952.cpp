#pragma warning(disable: 4996)
#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <limits.h>
#include <tuple>

//ü���� ���� 2�� ����
//ü���� ���� 1�� ������ ���������� �ܼ��� pair ������ ��ȯ
//�׳� pair ������ ���� �ٲ� Ƚ���� �߰����ְ�, pair �ε�ȣ �����ڷ� ��

#define KNIGHT 0
#define LOOK   1
#define BISHOP 2

int N;
int map[11][11];
//x,y�� k�� ���� N�� ° �湮
//�湮���� ���� ��ȣ, �湮�ϸ鼭 �ٲ� Ƚ��
std::pair<int, int> dp[11][11][3][101];
std::pair<int, int> start;
int knight_dx[8] = { -2, -2, -1, -1, 1 ,2 ,1, 2 };
int knight_dy[8] = { -1, 1, -2, 2, -2, -1, 2, 1 };
int look_dx[4] = { -1, 0,1,0 };
int look_dy[4] = { 0,1,0,-1 };
int bishop_dx[4] = { -1, -1, 1, 1 };
int bishop_dy[4] = { -1, 1, -1, 1 };

std::pair<int, int> ans = std::make_pair(INT_MAX, INT_MAX);

void bfs() {
	std::queue < std::tuple<int, int, int, int> > q;
	for (int k = 0; k < 3; k++) {
		q.emplace(std::make_tuple(start.first, start.second, k, 1));
		dp[start.first][start.second][k][1].first = 0;
		dp[start.first][start.second][k][1].second = 0;
	}

	while (!q.empty()) {
		int x, y, pieces_kind, num;
		std::tie(x, y, pieces_kind, num) = q.front();
		q.pop();


		if (num == N * N) {
			ans = ans > dp[x][y][pieces_kind][num] ? dp[x][y][pieces_kind][num] : ans;
			continue;
		}

		if (pieces_kind == KNIGHT) {
			for (int k = 0; k < 8; k++) {
				int nx = x + knight_dx[k];
				int ny = y + knight_dy[k];
				if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
					auto np = std::make_pair(dp[x][y][pieces_kind][num].first + 1, dp[x][y][pieces_kind][num].second);
					if (map[nx][ny] == num + 1 && ((dp[nx][ny][KNIGHT][num + 1].first == -1) || (dp[nx][ny][KNIGHT][num + 1] > np))) {
						q.emplace(std::make_tuple(nx, ny, KNIGHT, num + 1));
						dp[nx][ny][KNIGHT][num + 1] = np;
					}
					else if ((dp[nx][ny][KNIGHT][num].first == -1) || (dp[nx][ny][KNIGHT][num] > np)) {
						q.emplace(std::make_tuple(nx, ny, KNIGHT, num));
						dp[nx][ny][KNIGHT][num] = np;
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
					auto np = std::make_pair(dp[x][y][pieces_kind][num].first + 1, dp[x][y][pieces_kind][num].second);
					if (map[nx][ny] == num + 1 && ((dp[nx][ny][LOOK][num + 1].first == -1) || (dp[nx][ny][LOOK][num + 1] > np))) {
						q.emplace(std::make_tuple(nx, ny, LOOK, num + 1));
						dp[nx][ny][LOOK][num + 1] = np;
					}
					else if ((dp[nx][ny][LOOK][num].first == -1) || (dp[nx][ny][LOOK][num] > np)) {
						q.emplace(std::make_tuple(nx, ny, LOOK, num));
						dp[nx][ny][LOOK][num] = np;
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
					auto np = std::make_pair(dp[x][y][pieces_kind][num].first + 1, dp[x][y][pieces_kind][num].second);
					if (map[nx][ny] == num + 1 && ((dp[nx][ny][BISHOP][num + 1].first == -1) || (dp[nx][ny][BISHOP][num + 1] > np))) {
						q.emplace(std::make_tuple(nx, ny, BISHOP, num + 1));
						dp[nx][ny][BISHOP][num + 1] = np;
					}
					else if ((dp[nx][ny][BISHOP][num].first == -1) || (dp[nx][ny][BISHOP][num] > np)) {
						q.emplace(std::make_tuple(nx, ny, BISHOP, num));
						dp[nx][ny][BISHOP][num] = np;
					}
				}
			}
		}

		for (int prs_kind = 0; prs_kind < 3; prs_kind++) {
			if (prs_kind == pieces_kind) continue;
			auto np = std::make_pair(dp[x][y][pieces_kind][num].first + 1, dp[x][y][pieces_kind][num].second + 1);
			if (dp[x][y][prs_kind][num].first == -1 || (dp[x][y][prs_kind][num] > np)) {
				q.emplace(std::make_tuple(x, y, prs_kind, num));
				dp[x][y][prs_kind][num] = np;
			}
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 101; l++) {
					dp[i][j][k][l] = std::make_pair(-1, -1);
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) start = std::make_pair(i, j);
		}
	}
	bfs();
	printf("%d %d", ans.first, ans.second);
}