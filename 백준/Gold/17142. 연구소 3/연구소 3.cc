#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits.h>

int N, M, max_ans = INT_MIN;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
std::vector< std::vector<char> > map;
std::vector< std::pair<int, int> > virus;
int hv_t_visited;

//M개만큼의 virus 선택
std::priority_queue< std::tuple<int, int, int> > ret_virus_sel(std::vector<bool>& per, std::vector< std::vector<bool> >& visited) {
    std::priority_queue< std::tuple<int, int, int> > ret;

    for (int k = 0; k < per.size(); k++) {
        if (per[k]) {
            ret.emplace(std::make_tuple(0, virus[k].first, virus[k].second));
            visited[virus[k].first][virus[k].second] = true;
        }
    }
    return ret;
}

int calculate() {
    int ret = INT_MAX;
    std::vector<bool> per(virus.size(), false);
    std::fill(per.end() - M, per.end(), true);


    do {
        std::vector< std::vector<bool> > visited(N, std::vector<bool>(N, false));
        //x, y, time
        std::priority_queue< std::tuple<int, int, int> > pq = ret_virus_sel(per, visited);
        auto c_map = map;
        int ans = 0;
        int prev_time = -1;
        int visited_count = 0;

        while (!pq.empty()) {
            int x, y, time;
            std::tie(time, x, y) = pq.top();
            time *= -1;
            pq.pop();
            if (prev_time != time) {
                if (hv_t_visited <= visited_count) {
                    break;
                }
                else prev_time = time;
            }

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < N && ny >= 0 && ny < N && map[nx][ny] != '_') {
                    if (!visited[nx][ny]) {
                        pq.emplace(std::make_tuple(-1 * (time + 1), nx, ny));
                        ans = std::max(ans, time + 1);
                        visited[nx][ny] = true;
                        c_map[nx][ny] = '0' + time + 1;
                        if (map[nx][ny] == '0') visited_count++;
                    }
                }
            }

        }

        if (hv_t_visited <= visited_count) {
            ret = std::min(ret, ans);
        }

    } while (std::next_permutation(per.begin(), per.end()));

    return ret == INT_MAX ? -1 : ret;
}

int main() {
    scanf("%d %d", &N, &M);
    map.assign(N, std::vector<char>(N, '0'));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int v;
            scanf("%d", &v);
            if (v == 2) {
                virus.emplace_back(std::make_pair(i, j));
                map[i][j] = '*';
            }
            else if (v == 1) {
                map[i][j] = '_';
            }
            else {
                hv_t_visited++;
            }
        }
    }
    printf("%d", calculate());
}