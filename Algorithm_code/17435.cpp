#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <queue>

#define MAX_VAL 1000000
int N, K;

std::vector<bool> visited;

void calculate() {
	std::queue< std::pair<int, int> > q;
	q.emplace(std::make_pair(N, 0));
	int ans = 0;

	while (!q.empty()) {
		auto front = q.front();
		q.pop();

		int node = front.first;
		int num = front.second;
		visited[node] = true;

		if (node == K) {

		}


		if (node + 1 < MAX_VAL && !visited[node + 1]) {
			q.emplace(std::make_pair(node + 1, num + 1));
		}
		if (node * 2< MAX_VAL && !visited[node]*2) {
			q.emplace(std::make_pair(node * 2, num + 1));
		}
		if (node - 1 >= 0 && !visited[node - 1]) {
			q.emplace(std::make_pair(node - 1, num + 1));
		}

	}
}

int main() {
	scanf("%d %d", &N, &K);
	
	visited.assign(N + 1, false);


}