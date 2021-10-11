#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>

//DAG ���� ���� ���������� queue�� priority_queue�� ����Ͽ� Ǯ��� �����̴�.
//pq�� ����ϴ� �� �ܿ��� ����� �κ��� ����

int N, M;
std::vector<int> indegree;
//a�������� ���� Ǯ����ϴ� ������
std::vector< std::vector<int> > from_to;

void calculate() {
	std::priority_queue<int, std::vector<int>, std::greater<int> > q;
	for (int k = 1; k < indegree.size(); k++) {
		if (!indegree[k]) q.emplace(k);
	}

	while (!q.empty()) {
		auto front = q.top();
		q.pop();
		printf("%d ", front);

		for (int k = 0; k < from_to[front].size(); k++) {
			if (!(--indegree[from_to[front][k]])) {
				q.emplace(from_to[front][k]);
			}
		}
	}

	return;
}

int main() {
	scanf("%d %d", &N, &M);
	indegree.assign(N + 1, 0);
	from_to.assign(N + 1, std::vector<int>());

	for (int k = 0; k < M; k++) {
		int a, b;
		scanf("%d %d", &a, &b);
		from_to[a].emplace_back(b);
		indegree[b]++;
	}
	calculate();

}