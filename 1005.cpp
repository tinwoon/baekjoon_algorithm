#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

//위상 정렬 문제
//1. n번 노드로 들어가는 수를 저장하는 indegree를 저장
//2. a번 노드에서 b번 노드로 가는 vector를 저장

int T;
int N, K;
int W;

std::vector<int> time_v;
//n번의 indegree
std::vector<int> indegree;
//N번 노드부터 뻗어나가는 node
std::vector< std::vector<int> > connected;

std::vector<int> dp;


int calculate() {

    std::queue<int> q;
    int ans = 0;

    for (int node = 0; node < N; node++) {
        if (indegree[node] == 0) {
            q.emplace(node);
            dp[node] = time_v[node];
        }
    }

    while (!q.empty()) {
        auto node = q.front();
        q.pop();

        for (int index = 0; index < connected[node].size(); index++) {

            indegree[connected[node][index]]--;
            dp[connected[node][index]] = std::max(dp[connected[node][index]], dp[node] + time_v[connected[node][index]]);

            if (!indegree[connected[node][index]]) {
                q.emplace(connected[node][index]);
            }
        }
    }

    return dp[W];
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &N, &K);
        time_v.assign(N, 0);
        indegree.assign(N, 0);
        connected.assign(N, std::vector<int>());
        dp.assign(N, 0);

        for (int index = 0; index < N; index++) {
            int take_time;
            scanf("%d", &take_time);
            time_v[index] = take_time;
        }
        for (int index = 0; index < K; index++) {
            int from, to;
            scanf("%d %d", &from, &to);
            connected[from - 1].emplace_back(to - 1);
            indegree[to - 1]++;
        }
        scanf("%d", &W);
        W--;

        printf("%d\n", calculate());
    }
}