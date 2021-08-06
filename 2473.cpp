#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <math.h>
#include <limits.h>

//세 용액 문제
//먼저 두개를 이중 포문을 통해 구하고
//마지막 한개를 이분 탐색을 통해 추출했다.

int N;
std::vector<long long> value;
std::vector<long long> ans(3, 0);
long long ans_val = LLONG_MAX;

void check_ans(long long two_sum, int three_index, int i, int j) {
	if (llabs(two_sum + value[three_index]) < ans_val) {
		ans[0] = value[i];
		ans[1] = value[j];
		ans[2] = value[three_index];
		ans_val = llabs(two_sum + value[three_index]);
	}
}

void calculate() {

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			long long two_sum = value[i] + value[j];
			//이거 앞뒤 전후에 최적 값이 들어가 있음.
			int three_index = std::distance(value.begin(), std::lower_bound(value.begin(), value.end(), two_sum * -1));
			if (three_index < N && i != three_index && j != three_index) {
				check_ans(two_sum, three_index, i, j);
			}
			if (three_index > 0 && i != three_index - 1 && j != three_index - 1) {
				check_ans(two_sum, three_index - 1, i, j);
			}
		}
	}
	std::sort(ans.begin(), ans.end());
	return;
}

int main() {
	scanf("%d", &N);
	value.assign(N, 0);
	for (int k = 0; k < N; k++) {
		scanf("%lld", &value[k]);
	}
	std::sort(value.begin(), value.end());

	calculate();
	printf("%lld %lld %lld", ans[0], ans[1], ans[2]);

}