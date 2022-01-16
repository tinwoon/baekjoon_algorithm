#pragma warning (disable : 4996)
#include <iostream>
#include <vector>

//그냥 DFS 입니다

int N, M;

std::vector< std::vector<int> > connected;
int ans;
std::vector<bool> visited;

void calculate(int node) {
	visited[node] = true;
	ans++;

	for (int k = 0; k < connected[node].size(); k++) {
		if (!visited[connected[node][k]]) calculate(connected[node][k]);
	}
}

int main() {
	scanf("%d %d", &N, &M);

	connected.assign(N, std::vector<int>());
	visited.assign(N, false);

	for (int k = 0; k < M; k++) {
		int a, b;
		scanf("%d %d", &a, &b);
		connected[a - 1].emplace_back(b - 1);
		connected[b - 1].emplace_back(a - 1);
	}
	calculate(0);
	printf("%d", ans - 1);
}