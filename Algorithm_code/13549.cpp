//bfs로 하자
//가중치 bfs를 푸는 문제로 반드시 통암기할것 
//그동안의 bfs는 모두 가중치가 같았지만 이건 다름 
//통으로 암기할것 이건 외우는게 편하다 

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

bool visited[100001];
int value[100001];
int N, K;
int stack = 0;

void bfs(int index) {

	std::queue<int> q;
	std::queue<int> next_q;
	q.push(index);
	visited[index] = true;
	value[index] = 0;


	while (!q.empty()) {
		int front = q.front();
		q.pop();

		if (front * 2 < 100001) {
			if (!visited[front * 2]) {
				q.push(front * 2);
				visited[front * 2] = true;
				value[front * 2] = value[front];
			}
		}
		if (front - 1 >= 0) {
			if (!visited[front - 1]) {
				next_q.push(front - 1);
				visited[front - 1] = true;
				value[front - 1] = value[front] + 1;
			}
		}
		if (front + 1 < 100001) {
			if (!visited[front + 1]) {
				next_q.push(front + 1);
				visited[front + 1] = true;
				value[front + 1] = value[front] + 1;
			}
		}
		if (q.empty()) {
			q = next_q;
			next_q = std::queue<int>();
		}


	}




}




int main() {
	scanf("%d %d", &N, &K);
	bfs(N);
	printf("%d\n", value[K]);
}
