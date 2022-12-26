#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>

//12851 숨바꼭질 2
//기존 BFS와 다르게 visited 위치를 변경하여 풀이 완료
//어려운 부분은 없었다.

#define MAX_VAL 100000
int N, K;
int ans_t = -1, ans_n;

std::vector<bool> visited(MAX_VAL + 1, false);

void calculate() {
	std::queue< std::pair<int, int> > q;
	q.emplace(std::make_pair(N, 0));

	while (!q.empty()) {
		auto front = q.front();
		q.pop();

		int node = front.first;
		int num = front.second;
		visited[node] = true;

		if (ans_t != -1 && ans_t < num) continue;

		if (node == K) {
			ans_t = num;
			ans_n++;
			continue;
		}


		if (node + 1 <= MAX_VAL && !visited[node + 1]) {
			q.emplace(std::make_pair(node + 1, num + 1));
		}
		if (node * 2 <= MAX_VAL && !visited[node * 2]) {
			q.emplace(std::make_pair(node * 2, num + 1));
		}
		if (node - 1 >= 0 && !visited[node - 1]) {
			q.emplace(std::make_pair(node - 1, num + 1));
		}

	}

	return;
}

int main() {
	scanf("%d %d", &N, &K);
	calculate();
	printf("%d %d", ans_t, ans_n);
}