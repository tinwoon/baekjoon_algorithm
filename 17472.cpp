#pragma warning(disable: 4996)
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <numeric>
#include <limits.h>

bool map[11][11];
//i,j��ǥ�� n�� ���� �ش��Ѵ�.
int map_island[11][11];
//i���� j�� ���� ���� n��ŭ ����Ǿ��ִ�.
int is_connected[7][7];
//i�� ���� j�� ����°�� ���� ���״�
bool visited[7][7];

int N, M;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
//sum_count���� ���� ���� ���� +1�� ����ִ�.
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

//i,j�� �󸶰��� �Ÿ��� ����Ǿ� �ִ��� => 0�̸� ���� �ȵǾ� �ִ°�
void bfs() {
    //���� ����Ǿ� �ִ����� Ȯ���ϰ� �󸶰��� �Ÿ��� �ִ��� ����
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
    //i,j�� ���� ���� ����Ǿ� �ִ��� Ȯ���ϴ� �ڵ�

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