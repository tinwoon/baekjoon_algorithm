#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

int N, M;
std::vector< std::vector<int> > map;
std::vector< std::vector<bool> > visited;
std::vector< std::pair<int, int> > biggest_blocks;
int biggest_blocks_rainbows_count = 0;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int rm_blocks() {
    for (int k = 0; k < biggest_blocks.size(); k++) {
        auto front = biggest_blocks[k];
        map[front.first][front.second] = INT_MIN;
    }

    return (((int)biggest_blocks.size()) * ((int)biggest_blocks.size()));
}

void bfs(int i, int j) {
    int block_id = map[i][j];
    std::vector< std::pair<int, int> > blocks;
    std::queue< std::pair<int, int> > q;
    std::vector< std::pair<int, int> > reversed_visited;

    q.emplace(std::make_pair(i, j));
    blocks.emplace_back(std::make_pair(i, j));
    visited[i][j] = true;

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = front.first + dx[k];
            int ny = front.second + dy[k];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if (!visited[nx][ny]) {
                    if (map[nx][ny] == block_id || map[nx][ny] == 0) {
                        blocks.emplace_back(std::make_pair(nx, ny));
                        q.emplace(std::make_pair(nx, ny));
                        visited[nx][ny] = true;
                        if (map[nx][ny] == 0) reversed_visited.emplace_back(std::make_pair(nx, ny));
                    }
                }
            }
        }
    }

    for (int k = 0; k < reversed_visited.size(); k++) {
        int x = reversed_visited[k].first;
        int y = reversed_visited[k].second;

        visited[x][y] = false;
    }

    if (blocks.size() >= 2) {
        if (blocks.size() > biggest_blocks.size()) {
            biggest_blocks = blocks;
            biggest_blocks_rainbows_count = reversed_visited.size();
        } else if (blocks.size() == biggest_blocks.size() && biggest_blocks_rainbows_count <= reversed_visited.size()) {
            biggest_blocks = blocks;
            biggest_blocks_rainbows_count = reversed_visited.size();
        }
    }

}

void find_block_group() {

    visited.assign(N, std::vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) continue;
            switch (map[i][j]) {
            case -1:
            case 0:
            case INT_MIN:
                continue;

            default:
                bfs(i, j);
            }
        }
    }
}

void gravity() {
    for (int j = 0; j < N; j++) {
        for (int i = N - 1; i >= 0; i--) {
            if (map[i][j] != INT_MIN && map[i][j] != -1) {
                int k;
                for (k = i; (k + 1 < N) && (map[k + 1][j] == INT_MIN); k++);
                std::swap(map[k][j], map[i][j]);
            }
        }
    }
}

void rotation() {
    // 매트릭스 전치
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++) {
            std::swap(map[i][j], map[j][i]);
        }
    }
    // 행 교환
    for (int i = 0; i < N / 2; i++)
    {
        for (int j = 0; j < N; j++) {
            std::swap(map[i][j], map[N - i - 1][j]);
        }
    }
}


int calculate() {

    int ans = 0;

    do {
        biggest_blocks.clear();

        //find block groups
        find_block_group();

        //rm_blocks()
        ans += rm_blocks();

        //gravity
        gravity();

        //rotation
        rotation();

        //gravity
        gravity();

    } while (!biggest_blocks.empty());

    return ans;
}



int main() {
    scanf("%d %d", &N, &M);
    map.assign(N, std::vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    printf("%d\n", calculate());
}