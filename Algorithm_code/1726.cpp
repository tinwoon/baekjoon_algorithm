#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <string.h>

//전형적인 bfs 문제입니다

int N, M;
std::vector< std::vector<int> >map;
std::tuple<int, int, int> start, end;

int EWSN[4][3] = { {2,3,1}, {2,3,0}, {0,1,3}, {0,1,2} };

//i,j를 x방향으로
bool visited[101][101][4];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int calculate() {
    std::queue< std::tuple<int, int, int, int> > q;
    int a, b, c;
    std::tie(a, b, c) = start;
    //x,y, dir, 횟수
    q.emplace(std::make_tuple(a, b, c, 0));
    visited[a][b][c] = true;

    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        int x, y, dir, count;
        std::tie(x, y, dir, count) = front;

        if (x == std::get<0>(end) && y == std::get<1>(end) && dir == std::get<2>(end)) {
            return count;
        }

        for (int k = 1; k <= 3; k++) {
            int nx = x + dx[dir] * k;
            int ny = y + dy[dir] * k;

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                if (map[nx][ny] == 1) break;
                if (!visited[nx][ny][dir]) {
                    visited[nx][ny][dir] = true;
                    q.emplace(std::make_tuple(nx, ny, dir, count + 1));
                }
            }
        }

        for (int k = 0; k < 3; k++) {
            int n_dir = EWSN[dir][k];
            if (!visited[x][y][n_dir]) {
                visited[x][y][n_dir] = true;
                if (x == 0 && y == 3 && n_dir == 0) {
                    printf("");
                }
                if (k != 2) q.emplace(std::make_tuple(x, y, n_dir, count + 1));
                else q.emplace(std::make_tuple(x, y, n_dir, count + 2));
            }
        }

    }

    return -1;
}

int main() {
    scanf("%d %d", &N, &M);
    memset(visited, false, sizeof(visited));
    map.assign(N, std::vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    int start_t, end_t, dir_t;
    scanf("%d %d %d", &start_t, &end_t, &dir_t);
    start = std::make_tuple(start_t - 1, end_t - 1, dir_t - 1);
    scanf("%d %d %d", &start_t, &end_t, &dir_t);
    end = std::make_tuple(start_t - 1, end_t - 1, dir_t - 1);

    printf("%d", calculate());


}