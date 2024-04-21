#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

int N;
std::vector< std::vector<int> > connected;
std::vector<int> from;
std::vector< std::vector<int> > capacity, flow;

//모두 소문자로 converting할 예정
int convert_id(char c) {
    int ret;
    if (c >= 97) {
        return ret = c - 71;
    }
    return ret = c - 65;
}

int calculate(int start, int end) {
    int ans = 0;

    while (1) {
        std::queue<int> q;
        std::fill(from.begin(), from.end(), -1);
        q.emplace(start);
        int f = INT_MAX;

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            for (int k = 0; k < connected[node].size(); k++) {
                int n_node = connected[node][k];

                if ((capacity[node][n_node] - flow[node][n_node]) > 0 && from[n_node] == -1) {
                    q.emplace(n_node);
                    from[n_node] = node;
                    if (n_node == end) break;
                }
            }
        }

        if (from[end] == -1) break;

        for (int k = end; k != start; k = from[k]) {
            f = std::min(f, capacity[from[k]][k] - flow[from[k]][k]);
        }

        for (int k = end; k != start; k = from[k]) {
            flow[from[k]][k] += f;
            flow[k][from[k]] -= f;
        }

        ans += f;
    }

    return ans;
}


int main() {
    scanf("%d", &N);
    connected.assign('z' + 1, std::vector<int>());
    from.assign('z' + 1, -1);
    capacity.assign('z' + 1, std::vector<int>('z' + 1, 0));
    flow.assign('z' + 1, std::vector<int>('z' + 1, 0));

    for (int k = 0; k < N; k++) {
        char a, b;
        int c;
        scanf(" %1c %1c %d", &a, &b, &c);

        a = convert_id(a);
        b = convert_id(b);

        connected[a].emplace_back(b);
        connected[b].emplace_back(a);

        capacity[a][b] = (capacity[b][a] += c);
    }
    printf("%d\n", calculate('A' - 'A', 'Z' - 'A'));

}