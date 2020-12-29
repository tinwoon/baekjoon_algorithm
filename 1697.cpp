//bfs�� ����
//��Ÿ�� ������ ����
// 1. N,K�߿��� ���� ū ��*2 + 1������ �ε����� ����������
// �ε����� 100000�� ����� �޸� �ʰ�
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

std::vector<bool> visited;
std::vector<int> stack;
int N, K;


void bfs(int x) {

	std::queue<int> q;
	visited[x] = true;
	q.push(x);

	while (!q.empty()) {
		
		if (q.front() == K) {

			printf("%d", stack[K]);
			break;
		}

		x = q.front();
		q.pop();

		if (x - 1 >= 0) {
			if (!visited[x - 1]) {
				q.push(x - 1);
				visited[x - 1] = true;
				stack[x - 1] = stack[x] + 1;
			}
		}
		if (x + 1 <= 2 * (N > K ? N : K) ) {
			if (!visited[x + 1]) {
				q.push(x + 1);
				visited[x + 1] = true;
				stack[x + 1] = stack[x] + 1;
			}
		}
		if (2 * x <= 2 * (N > K ? N : K) ) {
			if (!visited[2 * x]) {
				q.push(2 * x);
				visited[2 * x] = true;
				stack[2 * x] = stack[x] + 1;
			}
		}
	}

}




int main() {
	scanf("%d %d", &N, &K);
	visited.assign(N > K ? 2*N + 1 : 2*K + 1, false);
	stack.assign(N > K ? 2*N + 1 : 2*K+1, 0);
	bfs(N);
}
