#pragma warning(disable: 4996)
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <numeric>
#include <limits.h>

bool map[11][11];
//i,j좌표는 n번 섬에 해당한다.
int map_island[11][11];
//i번과 j번 간의 섬은 n만큼 연결되어있다.
int is_connected[7][7];
//i번 섬과 j번 섬번째를 연결 시켰다
bool visited[7][7];

int N, M;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
//sum_count에는 현재 섬의 개수 +1이 들어있다.
int sum_count = 1;
int ans = INT_MAX;

void dfs(int first_node, int second_node, int count, int rst) {
    if (count == sum_count - 1) {
        ans = std::min(ans, rst);
        return;
    }

    visited[first_node][second_node] = visited[second_node][first_node] = true;

    for (int i = first_node; i < sum_count; i++) {
        for (int j = first_node + 1; j < sum_count; j++) {
            if (i == j || visited[i][j] || visited[j][i]) continue;
            if (is_connected[i][j]) {
                dfs(i, j, count + 1, rst + is_connected[i][j]);
                visited[i][j] = visited[j][i] = false;
            }
        }
    }


}

//i,j가 얼마간의 거리로 연결되어 있는지 => 0이면 연결 안되어 있는거
void bfs() {
    //서로 연결되어 있는지를 확인하고 얼마간의 거리가 있는지 정리
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map_island[i][j]) {
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    while (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                        if (map_island[nx][ny]) {
                            if (map_island[nx][ny] == map_island[i][j]) break;
                            int distance = abs(i - nx) + abs(j - ny) - 1;
                            is_connected[map_island[nx][ny]][map_island[i][j]] = is_connected[map_island[i][j]][map_island[nx][ny]] = distance < 2 ? 0 : distance;
                            break;
                        }
                        nx += dx[k];
                        ny += dy[k];
                    }
                }
            }
        }
    }
}

void calculate(int i, int j, int sum_count) {
    if (map_island[i][j] || i < 0 || i >= N || j < 0 || j >= M) return;

    map_island[i][j] = sum_count;

    for (int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (!map_island[nx][ny] && map[nx][ny]) {
            calculate(nx, ny, sum_count);
        }
    }
    return;
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    //i,j번 섬은 어디와 연결되어 있는지 확인하는 코드

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] && !map_island[i][j]) {
                calculate(i, j, sum_count++);
            }
        }
    }
    bfs();
    dfs(1, 1, 0, 0);
    printf("%d", ans == INT_MAX ? -1 : ans);
}