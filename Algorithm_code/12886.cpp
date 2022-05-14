//https://www.acmicpc.net/problem/12886
// 기존의 물통 문제처럼 visited를 3차원이 아닌 2차원으로 할당이 가능하 

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

int A, B, C;

bool visited[1501][1501];

int calculate() {
	std::queue< std::tuple<int, int, int> > q;
	q.emplace(std::make_tuple(A, B, C));
	visited[A][B] = true;

	while (!q.empty()) {
		auto front = q.front();
		q.pop();

		std::vector<int> index(3, 0);
		std::tie(index[0], index[1], index[2]) = front;
		if (index[0] == index[1] && index[1] == index[2] && index[0] == index[2]) return 1;

		for (int i = 0; i < 3; i++) {
			for (int j = i + 1; j < 3; j++) {
				if (i == j) continue;
				auto tmp = index;
				int low_index = index[i] > index[j] ? j : i;
				int high_index = index[i] <= index[j] ? j : i;
				tmp[high_index] = index[high_index] - index[low_index];
				tmp[low_index] = index[low_index] * 2;
				if (!visited[tmp[0]][tmp[1]]) {
					visited[tmp[0]][tmp[1]] = true;
					q.emplace(std::make_tuple(tmp[0], tmp[1], tmp[2]));
				}
			}
		}
	}

	return 0;
	
}

int main() {
	scanf("%d %d %d", &A, &B, &C);
	printf("%d", calculate());
}
