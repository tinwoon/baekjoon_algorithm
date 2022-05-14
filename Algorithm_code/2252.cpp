#pragma warning(disable: 4996)
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

int N, M;
//i번은 j번으로 들어간다.
std::vector<std::vector<int> > indegree;
//i번으로 들어오는 노드의 개수
std::vector<int> indegree_value;

void calculate() {
	std::queue<int> q;
	for (int k = 1; k <= N; k++) {
		if (indegree_value[k] == 0) q.emplace(k);
	}
	while (!q.empty()) {
		auto front = q.front();
		printf("%d ", front);
		q.pop();

		for (int index = 0; index < indegree[front].size(); index++) {
			indegree_value[indegree[front][index]]--;
			if (indegree_value[indegree[front][index]] == 0) q.emplace(indegree[front][index]);
		}
	}
	return;
}

int main() {
	scanf("%d %d", &N, &M);
	indegree_value.assign(N + 1, 0);
	indegree.assign(N + 1, std::vector<int>(0, 0));
	int start, end;
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &start, &end);
		indegree[start].emplace_back(end);
		indegree_value[end]++;
	}
	calculate();

}