#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>
#include <set>

int N, M, ans;
std::vector< std::vector<int> > buckets;
//d,s의 모임
std::vector< std::pair<int, int> > c_move;
//구름들의 x,y
std::queue< std::pair<int, int> > clouds;

int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

void move_water_cloud(std::pair<int, int> c_move_unit) {
    int d = c_move_unit.first;
    int s = c_move_unit.second;

    std::set< std::pair<int, int> > disappear_clouds;
    std::queue< std::pair<int, int> > n_clouds;

    while (!clouds.empty()) {
        int x, y;
        auto front = clouds.front();
        clouds.pop();
        x = front.first;
        y = front.second;

        //2. 각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1증가한다.
        int nx = (x + N + (dx[d] * (s % N) )) % N;
        int ny = (y + N + (dy[d] * (s % N) )) % N;
        buckets[nx][ny]++;
        ans++;

        disappear_clouds.insert(std::make_pair(nx, ny));
    }

    for(auto itr = disappear_clouds.begin(); itr != disappear_clouds.end(); itr++) {

        int nx = itr->first;
        int ny = itr->second;

        //4. 2에서 물이 증가한 칸(r,c)에 물복사버그 마법을 시전한다.
        for (int k = 1; k < 8; k += 2) {
            int nnx = nx + dx[k];
            int nny = ny + dy[k];

            if (nnx >= 0 && nnx < N && nny >= 0 && nny < N) {
                if (buckets[nnx][nny]) {
                    buckets[nx][ny]++;
                    ans++;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (buckets[i][j] >= 2) {
                if (!disappear_clouds.count(std::make_pair(i, j))) {
                    buckets[i][j] -= 2;
                    ans -= 2;
                    n_clouds.emplace(std::make_pair(i, j));
                }
            }
        }
    }
    clouds = n_clouds;
}

int calculate() {
    for (int k = 0; k < M; k++) {
        move_water_cloud(c_move[k]);
    }
    return ans;
}

int main() {
    int d, s;
    scanf("%d %d", &N, &M);
    buckets.assign(N, std::vector<int>(N, 0));

    clouds.emplace(std::make_pair(N - 1, 0));
    clouds.emplace(std::make_pair(N - 1, 1));
    clouds.emplace(std::make_pair(N - 2, 0));
    clouds.emplace(std::make_pair(N - 2, 1));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &buckets[i][j]);
            ans += buckets[i][j];
        }
    }

    for (int k = 0; k < M; k++) {
        scanf("%d %d", &d, &s);
        c_move.emplace_back(std::make_pair(d - 1, s));
    }

    printf("%d", calculate());
}