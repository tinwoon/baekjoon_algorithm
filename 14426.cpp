#pragma warning(disable: 4996)
#include <iostream>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <vector>
#include <string.h>

//수빈이의 위치 N, 동생의 위치 K
int N, K;
//n번 위치를 몇 번쩨에 방문했나.
//홀수일때 0 짝수일때 1
int node[500001][2];


int bfs() {
	//tuple에는 N번이 들어가야 한다.
	std::queue< std::pair<int, int> > q;
	q.emplace(std::make_pair(N, 0));
	node[N][0] = 0;

	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		int x = front.first;
		int num = front.second;

		for (int y : {x - 1, x + 1, 2 * x}) {
			if (y >= 0 && y <= 500000) {
				if (node[y][(num + 1) % 2] == -1) {
					node[y][(num + 1) % 2] = node[x][num] + 1;
					q.emplace(std::make_pair(y, (num + 1) % 2));
				}
			}
		}
	}
	int ans = -1;
	int k = K;
	for (int time = 0; ; time++) {
		k += time;
		if (k > 500000) break;
		if (node[k][time % 2] <= time) {
			ans = time;
			break;
		}
	}
	return ans;
}

int main() {
	memset(node, -1, sizeof(node));
	scanf("%d %d", &N, &K);
	printf("%d", bfs());
}