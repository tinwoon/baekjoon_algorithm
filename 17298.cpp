#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

//17298번 오큰수 문제
//Stack을 기반으로 실행
//구현에 기반한 문제라 어렵다.

int N;
std::queue< std::pair<int, int> > data;
std::vector<int> ans;

void calculate() {
	std::stack< std::pair<int, int> > value;

	while (!data.empty()) {
		if (value.empty() || value.top().first >= data.front().first) {
			value.emplace(data.front());
			data.pop();
		}
		else {
			ans[value.top().second] = data.front().first;
			value.pop();
		}
	}

	while (!value.empty()) {
		ans[value.top().second] = -1;
		value.pop();
	}
}

int main() {
	scanf("%d", &N);
	for (int k = 0; k < N; k++) {
		int input;
		scanf("%d", &input);
		data.emplace(std::make_pair(input, k));
	}

	ans.assign(N, 0);
	calculate();

	for (int k = 0; k < N; k++) {
		printf("%d ", ans[k]);
	}
}