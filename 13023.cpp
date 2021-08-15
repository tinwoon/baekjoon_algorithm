#pragma warning (disable : 4996)
#include <iostream>
#include <vector>

//13023 ABCDE 문제
//딱히 어려운 내용은 없으나 답을 찾으면 바로 return해야 답의 최적화를 이루어 낼 수 있다. 

int N, M;
std::vector< std::vector<int> > friends;
bool ans = false;
std::vector<bool> visited;

void calculate(int level, int node) {
	if (level == 4) {
		ans = true;
		return;
	}

	visited[node] = true;

	for (int k = 0; k < friends[node].size(); k++) {
		if (!visited[friends[node][k]] && !ans) {
			calculate(level + 1, friends[node][k]);
			visited[friends[node][k]] = false;
		}
	}


}

int main() {
	scanf("%d %d", &N, &M);
	friends.assign(N, std::vector<int>(0, 0));
	for (int k = 0; k < M; k++) {
		int a, b;
		scanf("%d %d", &a, &b);
		friends[a].emplace_back(b);
		friends[b].emplace_back(a);
	}

	for (int k = 0; k < N; k++) {
		visited.assign(N, false);
		calculate(0, k);
	}
	printf("%d", ans);
}
