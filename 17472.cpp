//���� ���� ���� �������� bridge ���� ������ ����ص���.

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
//i,j��ǥ�� n�� ���� �ش��Ѵ�.
int map_island[11][11];
//i���� j�� ���� ���� n��ŭ ����Ǿ��ִ�.
int is_connected[7][7];
//i�� ���� j�� ����°�� ���� ���״�
bool visited[7][7];
//���ᰡ���� ��� �ٸ��� ����� ��
std::vector< bridge > bridges;
//i���� j���� ���� ����Ǿ� �ִ�.
bool connect[7][7];
//���ΰ��� ����Ǿ� �ִ��� Ȯ���ߴ�.
bool check[7];

int N, M;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
//sum_count���� ���� ���� ���� +1�� ����ִ�.
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

//�ٸ����� ��, �Ǽ��� �ٸ��� ����, ���° bridges�� �����Ұ���
void go(int rst, int index, int loc) {

    if (index > sum_count - 1) return;
    if (ans != INT_MAX && ans < rst) return;
    if (index + ((int)bridges.size() - loc + 1) < sum_count - 2) return;

    //�ٸ��� ����Ǿ��ٸ�
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
    //�����Ұž�
    connect[bridges[loc].to][bridges[loc].from] = connect[bridges[loc].from][bridges[loc].to] = true;
    go(rst + is_connected[bridges[loc].from][bridges[loc].to], index + 1, loc + 1);
    connect[bridges[loc].to][bridges[loc].from] = connect[bridges[loc].from][bridges[loc].to] = false;
    go(rst, index, loc + 1);
}

//i,j�� �󸶰��� �Ÿ��� ����Ǿ� �ִ��� => 0�̸� ���� �ȵǾ� �ִ°�
void confirm() {
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
    //i,j�� ���� ���� ����Ǿ� �ִ��� Ȯ���ϴ� �ڵ�

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