#include <iostream>
#include <vector>
#include <algorithm>

//숫자카드 문제
//머 그냥 이분탐색은 사용 안하고 eqaul_range 사용했습니다.

int N, M;
std::vector<int> num;
std::vector<int> cmd;

int main() {
	scanf("%d", &N);
	num.assign(N, 0);
	for (int k = 0; k < N; k++) {
		scanf("%d", &num[k]);
	}
	std::sort(num.begin(), num.end());
	scanf("%d", &M);
	cmd.assign(M, 0);
	for (int k = 0; k < M; k++) {
		scanf("%d", &cmd[k]);
	}

	for (int k = 0; k < M; k++) {
		auto itr = std::equal_range(num.begin(), num.end(), cmd[k]);
		printf("%d ", itr.second - itr.first);
	}
}