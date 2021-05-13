#pragma warning(disable: 4996)
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

//수빈이의 위치 N, 동생의 위치 K
int N, K;
bool visited[500001];

int bfs() {
	std::queue< std::tuple<int, int, int> > q;
	q.emplace(std::make_tuple(N, K, 0));
	visited[N] = true;

	while (!q.empty()) {
		int x, y, num;
		std::tie(x, y, num) = q.front();
		q.pop();

		if (x == y) return num;


		if (x - 1 >= 0 && y + num + 1 <= 500000) {
			if (!visited[x - 1]) {
				q.emplace(std::make_tuple(x + 1, y + num + 1, num + 1));
				visited[x - 1] = true;
			}
		}
		if (x + 1 <= 500000 && y + num + 1 <= 500000) {
			if (!visited[x + 1]) {
				q.emplace(std::make_tuple(x - 1, y + num + 1, num + 1));
				visited[x + 1] = true;
			}
		}
		if (2 * x <= 500000 && y + num + 1 <= 500000) {
			if (!visited[2 * x]) {
				q.emplace(std::make_tuple(2 * x, y + num + 1, num + 1));
				visited[2 * x] = true;
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d %d", &N, &K);
	printf("%d", bfs());
}