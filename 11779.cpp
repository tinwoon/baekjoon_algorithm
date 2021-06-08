#pragma warning (disable: 4996)
#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <string.h>

//대표적인 다익스트라 문제

int N, M;
//i번 도시와 j번 도시의 간선의 가중치
int city[1001][1001];
//다익스트라 n번의 가중치
long long dijkstra_w[1001];
int from[1001];
bool visited[1001];
std::vector<int> ans;
int departure, destination;

void distance(int dest) {
    while (dest != departure) {
        ans.emplace_back(dest);
        dest = from[dest];
    }
    ans.emplace_back(dest);
}

void dijkstra(int node) {
    visited[node] = true;

    for (int k = 1; k <= N; k++) {
        if (city[node][k] != -1) {
            if (dijkstra_w[k] > (long long)dijkstra_w[node] + (long long)city[node][k]) {
                dijkstra_w[k] = (long long)dijkstra_w[node] + (long long)city[node][k];
                from[k] = node;
            }
        }
    }

    long long weight = LLONG_MAX;
    int n_node = -1;
    for (int k = 1; k <= N; k++) {
        if (!visited[k] && dijkstra_w[k] < weight) {
            weight = dijkstra_w[k];
            n_node = k;
        }
    }
    if (n_node == -1) return;
    else dijkstra(n_node);
}

int main() {
    memset(city, -1, sizeof(city));
    memset(dijkstra_w, -1, sizeof(dijkstra_w));
    memset(from, 0, sizeof(from));
    memset(visited, false, sizeof(visited));
    scanf("%d", &N);
    scanf("%d", &M);
    for (int k = 0; k < M; k++) {
        int start, end, value;
        scanf("%d %d %d", &start, &end, &value);
        if (city[start][end] == -1 || city[start][end] > value) {
            city[start][end] = value;
        }
    }
    for (int k = 1; k <= N; k++) dijkstra_w[k] = LLONG_MAX;
    scanf("%d %d", &departure, &destination);
    dijkstra_w[departure] = 0;
    dijkstra(departure);
    distance(destination);
    printf("%lli\n%d\n", dijkstra_w[destination], ans.size());
    for (auto ritr = ans.rbegin(); ritr != ans.rend(); ritr++) {
        printf("%d ", *ritr);
    }
}