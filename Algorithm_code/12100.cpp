#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

//12100 2048문제
//내용이 어려운건 하나도 없지만 구현 자체가 길어서 풀고싶지 않다.
//역량테스트에 나왔다는데 나오면 이건 안푼다. 

int N;
std::vector< std::vector<int> > map;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
std::vector<int> cmd(5, 0);
int ans = 0;


void move_L(std::vector< std::vector<int> >& c_map) {
    for (int i = 0; i < N; i++) {
        int index = -1;
        for (int j = 0; j < N; j++) {
            if (c_map[i][j] == 0) continue;
            int nx = i;
            int ny = j;
            while (1) {
                nx += dx[3];
                ny += dy[3];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;
                if (c_map[nx][ny]) break;
            }
            nx -= dx[3];
            ny -= dy[3];
            if (ny + dy[3] == index) {
                std::swap(c_map[i][j], c_map[nx][ny]);
            }
            else if (nx + dx[3] >= 0 && nx + dx[3] < N && ny + dy[3] >= 0 && ny + dy[3] < N) {
                if (c_map[nx + dx[3]][ny + dy[3]] == c_map[i][j]) {
                    index = ny + dy[3];
                    c_map[nx + dx[3]][ny + dy[3]] *= 2;
                    c_map[i][j] = 0;
                }
                else {
                    std::swap(c_map[i][j], c_map[nx][ny]);
                }
            }
        }
    }
}

void move_R(std::vector< std::vector<int> >& c_map) {
    for (int i = 0; i < N; i++) {
        int index = N;
        for (int j = N - 1; j >= 0; j--) {
            if (c_map[i][j] == 0) continue;
            int nx = i;
            int ny = j;
            while (1) {
                nx += dx[1];
                ny += dy[1];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;
                if (c_map[nx][ny]) break;
            }
            //nx,ny에는 넣을 곳이 들어가 있다.
            nx -= dx[1];
            ny -= dy[1];
            //넣을 곳 옆이 이미 합쳐져서 생긴 경우라면(즉, 번호가 같더라도 합칠 수 없으므로)
            if (ny + dy[1] == index) {
                std::swap(c_map[i][j], c_map[nx][ny]);
            }
            else if (nx + dx[1] >= 0 && nx + dx[1] < N && ny + dy[1] >= 0 && ny + dy[1] < N) {
                //넣을 곳 옆이 같다면
                if (c_map[nx + dx[1]][ny + dy[1]] == c_map[i][j]) {
                    index = ny + dy[1];
                    c_map[nx + dx[1]][ny + dy[1]] *= 2;
                    c_map[i][j] = 0;
                }
                else {
                    std::swap(c_map[i][j], c_map[nx][ny]);
                }
            }
        }
    }
}

void move_D(std::vector< std::vector<int> >& c_map) {
    for (int j = 0; j < N; j++) {
        int index = N;
        for (int i = N - 1; i >= 0; i--) {
            if (c_map[i][j] == 0) continue;
            int nx = i;
            int ny = j;
            while (1) {
                nx += dx[2];
                ny += dy[2];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;
                if (c_map[nx][ny]) break;
            }
            //nx,ny에는 넣을 곳이 들어가 있다.
            nx -= dx[2];
            ny -= dy[2];
            //넣을 곳 옆이 이미 합쳐져서 생긴 경우라면(즉, 번호가 같더라도 합칠 수 없으므로)
            if (nx + dx[2] == index) {
                std::swap(c_map[i][j], c_map[nx][ny]);
            }
            else if (nx + dx[2] >= 0 && nx + dx[2] < N && ny + dy[2] >= 0 && ny + dy[2] < N) {
                //넣을 곳 옆이 같다면
                if (c_map[nx + dx[2]][ny + dy[2]] == c_map[i][j]) {
                    index = nx + dx[2];
                    c_map[nx + dx[2]][ny + dy[2]] *= 2;
                    c_map[i][j] = 0;
                }
                else {
                    std::swap(c_map[i][j], c_map[nx][ny]);
                }
            }
        }
    }
}

void move_U(std::vector< std::vector<int> >& c_map) {
    for (int j = 0; j < N; j++) {
        int index = -1;
        for (int i = 0; i < N; i++) {
            if (c_map[i][j] == 0) continue;
            int nx = i;
            int ny = j;
            while (1) {
                nx += dx[0];
                ny += dy[0];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) break;
                if (c_map[nx][ny]) break;
            }
            //nx,ny에는 넣을 곳이 들어가 있다.
            nx -= dx[0];
            ny -= dy[0];
            //넣을 곳 옆이 이미 합쳐져서 생긴 경우라면(즉, 번호가 같더라도 합칠 수 없으므로)
            if (nx + dx[0] == index) {
                std::swap(c_map[i][j], c_map[nx][ny]);
            }
            else if (nx + dx[0] >= 0 && nx + dx[0] < N && ny + dy[0] >= 0 && ny + dy[0] < N) {
                //넣을 곳 옆이 같다면
                if (c_map[nx + dx[0]][ny + dy[0]] == c_map[i][j]) {
                    index = nx + dx[0];
                    c_map[nx + dx[0]][ny + dy[0]] *= 2;
                    c_map[i][j] = 0;
                }
                else {
                    std::swap(c_map[i][j], c_map[nx][ny]);
                }
            }
        }
    }
}

void calculate(int level) {
    if (level == 5) {
        auto c_map = map;

        if (cmd[0] == 3 && cmd[1] == 1 && cmd[2] == 3 && cmd[3] == 3 && cmd[4] == 3) {
            printf("");
        }

        for (int k = 0; k < 5; k++) {
            if (cmd[k] == 0) move_U(c_map);
            else if (cmd[k] == 1) move_R(c_map);
            else if (cmd[k] == 2) move_D(c_map);
            else if (cmd[k] == 3) move_L(c_map);
        }

        for (int k = 0; k < N; k++) {
            ans = std::max(ans, *std::max_element(c_map[k].begin(), c_map[k].end()));
        }
        return;
    }

    for (int k = 0; k < 4; k++) {
        cmd[level] = k;
        calculate(level + 1);
    }
}

int main() {
    scanf("%d", &N);
    map.assign(21, std::vector<int>(21, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    calculate(0);
    printf("%d", ans);
}
