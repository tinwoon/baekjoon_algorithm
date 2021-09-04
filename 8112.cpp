#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

//0과1 2번째 문제
//배수의 문제는 보통 %연산자의 최적화를 유도하는 내용이다. 

int T;

void print_ans(std::vector<int> &from, int N) {
	int start = 0;
	std::vector<int> seq;
	seq.emplace_back(start);
	while (start != 1) {
		seq.emplace_back(from[start]);
		start = from[start];
	}
	std::reverse(seq.begin(), seq.end());

	printf("1");
	for (int k = 0; k < seq.size() - 1; k++) {
		if ((seq[k] * 10 + 1) % N == seq[k + 1]) printf("1");
		else printf("0");
	}
	printf("\n");
}

bool calculate(int N) {
	std::vector<int> from(N, -1);
	std::queue<int> q;
	std::vector<bool> visited(N, false);
	visited[1] = true;
	q.emplace(1);

	while (!q.empty()) {
		auto front = q.front();
		q.pop();

		if (front == 0) {
			print_ans(from, N);
			return true;
		}

		for (int k = 0; k < 2; k++) {
			int n_value = (front * 10 + k) % N;
			if (!visited[n_value]) {
				from[n_value] = front;
				visited[n_value] = true;
				q.emplace(n_value);
			}
		}
	}

	return false;
	
}

int main() {
	scanf("%d", &T);
	for (int k = 0; k < T; k++) {
		int N;
		scanf("%d", &N);
		if (N == 1) printf("1\n");
		else if (!calculate(N)) printf("BRAK\n");
	}
}
