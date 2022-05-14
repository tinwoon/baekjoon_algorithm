//질이 좋지 않은 문제지만 bridge 관련 내용은 기억해두자.

#pragma warning(disable: 4996)
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <numeric>
#include <limits.h>

struct bridge {
    int from, to, cost;
};

bool map[11][11];
//i,j좌표는 n번 섬에 해당한다.
int map_island[11][11];
//i번과 j번 간의 섬은 n만큼 연결되어있다.
int is_connected[7][7];
//i번 섬과 j번 섬번째를 연결 시켰다
bool visited[7][7];
//연결가능한 모든 다리의 경우의 수
std::vector< bridge > bridges;
//i번과 j번이 서로 연결되어 있다.
bool connect[7][7];
//서로간에 연결되어 있는지 확인했다.
bool check[7];

int N, M;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
//sum_count에는 현재 섬의 개수 +1이 들어있다.
int sum_count = 1;
int ans = INT_MAX;



void find(int first) {
    for (int second = 1; second <= sum_count - 1; second++) {
        if (connect[first][second] && !check[second]) {
            check[second] = true;
            find(second);
        }
    }
}

//다리들의 합, 건설한 다리의 개수, 몇번째 bridges를 연결할건지
void go(int rst, int index, int loc) {

    if (index > sum_count - 1) return;
    if (ans != INT_MAX && ans < rst) return;
    if (index + ((int)bridges.size() - loc + 1) < sum_count - 2) return;

    //다리가 연결되었다면
    if (loc == bridges.size()) {
        memset(check, false, sizeof(check));
        check[1] = true;
        find(1);
        for (int i = 1; i <= sum_count - 1; i++) {
            if (check[i] == false) return;
        }
        ans = std::min(rst, ans);
        return;
    }
    //연결할거야
    connect[bridges[loc].to][bridges[loc].from] = connect[bridges[loc].from][bridges[loc].to] = true;
    go(rst + is_connected[bridges[loc].from][bridges[loc].to], index + 1, loc + 1);
    connect[bridges[loc].to][bridges[loc].from] = connect[bridges[loc].from][bridges[loc].to] = false;
    go(rst, index, loc + 1);
}

//i,j가 얼마간의 거리로 연결되어 있는지 => 0이면 연결 안되어 있는거
void confirm() {
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
                            int distance = (abs(i - nx) + abs(j - ny) - 1) < 2 ? 0 : (abs(i - nx) + abs(j - ny) - 1);
                            if (distance == 0) break;
                            if (!is_connected[map_island[nx][ny]][map_island[i][j]] || !is_connected[map_island[i][j]][map_island[nx][ny]]) is_connected[map_island[nx][ny]][map_island[i][j]] = is_connected[map_island[i][j]][map_island[nx][ny]] = distance;
                            else is_connected[map_island[nx][ny]][map_island[i][j]] = is_connected[map_island[i][j]][map_island[nx][ny]] = std::min({ distance, is_connected[map_island[nx][ny]][map_island[i][j]], is_connected[map_island[i][j]][map_island[nx][ny]] });
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

void input_bridge() {
    for (int i = 1; i < sum_count; i++) {
        for (int j = i + 1; j < sum_count; j++) {
            if (is_connected[i][j]) {
                bridges.emplace_back(bridge{ i, j, is_connected[i][j] });
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
    confirm();
    input_bridge();
    go(0, 0, 0);
    printf("%d", ans == INT_MAX ? -1 : ans);
}