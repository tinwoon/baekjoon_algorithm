#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


//틀린이유
//1. dp를 기준으로 갱신해야지 value를 기준으로 갱신하면 안됨
//2. dp는 마지막 값이 큰게 아니다. 

int N;
std::vector<int> value;
std::vector<int> dp;


void calculate() {
	std::priority_queue< std::pair<int, int> > q;
	if (N >= 1) {
		dp[1] = 1;
		q.push( std::pair<int, int>(dp[1],value[1]) );
		
	}
	for (int i = 2; i <= N; i++) {
		std::priority_queue< std::pair<int, int> > tmp = q;
		while (!tmp.empty()) {
			if (value[i] > tmp.top().second) {
				dp[i] = tmp.top().first + 1;
				break;
			}
			tmp.pop();
		}
		q.push(std::make_pair(dp[i], value[i]));
	}

	printf("%d\n", q.top().first);

	int stack = q.top().first;
	std::vector<int> data;
	for (int i = N; i >= 0; i--) {
		if (dp[i] == stack) {
			data.push_back(value[i]);
			stack--;
		}
	}
	std::reverse(data.begin(), data.end());
	for (int i = 0; i < data.size(); i++) {
		printf("%d ", data[i]);
	}

	return;
}


int main() {
	scanf("%d", &N);
	value.assign(N+1,0);
	dp.assign(N+1, 1);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &value[i]);
	}
	calculate();
}
