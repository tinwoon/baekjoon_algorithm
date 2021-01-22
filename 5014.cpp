//https://www.acmicpc.net/problem/5014
//각도문제랑 굉장히 비슷한 알고리 

#include <iostream>
#include <queue>
#include <vector>

int F, S, G, U, D;
std::vector<bool> visited;

int calculate() {
	std::queue< std::pair<int, int> > q;
	visited[S] = true;
	q.emplace(std::make_pair(S, 0));

	while (!q.empty()) {
		auto front = q.front();
		q.pop();

		if (front.first == G) return front.second;

		int up = front.first + U;
		int down = front.first - D;

		if (up <= F) {
			if (!visited[up]) {
				visited[up] = true;
				q.emplace(std::make_pair(up, front.second + 1));
			}
		}
		if (down >= 1) {
			if (!visited[down]) {
				visited[down] = true;
				q.emplace(std::make_pair(down, front.second + 1));
			}
		}
	}

	return -1;

}


int main() {
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	visited.assign(F + 1, false);
	int rst = calculate();
	if (rst != -1) printf("%d", rst);
	else printf("use the stairs");
}
