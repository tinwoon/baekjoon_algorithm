#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>

int n, m, t, s, g, h;
std::vector<int> destination;
std::vector< std::vector< std::pair<int, int> > > connected;
std::vector<int> weight;
std::priority_queue< std::pair<int, int>, std::vector< std::pair<int,int> >, std::greater< std::pair<int,int> > > q;

std::vector<int> w_every;
std::vector<int> g_to_end;
std::vector<int> h_to_end;
int g_to_h;
std::priority_queue<int> ans;

//총 세번의 다익스트라를 진행하면 된다.
//방법만 알면 간단하게 진행할 수 있으니 생략한다. 

void dijkstra(int start) {
    weight[start] = 0;
    q.emplace(std::make_pair(0, start));

    while (!q.empty()) {
        auto front = q.top();
        q.pop();

        int cost = front.first;
        int node = front.second;

        for (int k = 0; k < connected[node].size(); k++) {
            int ncost = connected[node][k].second;
            int nnode = connected[node][k].first;

            if (weight[nnode] > ncost + cost) {
                q.emplace(std::make_pair(ncost + cost, nnode));
                weight[nnode] = ncost + cost;
            }
        }
    }
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d %d %d", &n, &m, &t);
        scanf("%d %d %d", &s, &g, &h);
        connected.assign(n + 1, std::vector< std::pair<int, int> >(0, std::pair<int, int>(0, 0)));
        for (int k = 0; k < m; k++) {
            int a, b, d;
            scanf("%d %d %d", &a, &b, &d);
            connected[a].emplace_back(std::make_pair(b, d));
            connected[b].emplace_back(std::make_pair(a, d));
            if ((a == g && b == h) || (a == h && b == g) ) g_to_h = d;
        }
        destination.clear();
        for (int k = 0; k < t; k++) {
            int des;
            scanf("%d", &des);
            destination.emplace_back(des);
        }

        weight.assign(n + 1, INT_MAX);
        dijkstra(s);
        w_every = weight;        
        
        weight.assign(n + 1, INT_MAX);
        dijkstra(g);
        g_to_end = weight;

        weight.assign(n + 1, INT_MAX);
        dijkstra(h);
        h_to_end = weight;

        for (auto itr = destination.begin(); itr != destination.end(); itr++) {
            if (w_every[*itr] == w_every[g] + g_to_h + h_to_end[*itr]) ans.emplace(-1 * (*itr));
            else if (w_every[*itr] == w_every[h] + g_to_h + g_to_end[*itr]) ans.emplace(-1 * (*itr));
        }

        while (!ans.empty()) {
            printf("%d ", -1 * ans.top());
            ans.pop();
        }
        printf("\n");
    }
}
