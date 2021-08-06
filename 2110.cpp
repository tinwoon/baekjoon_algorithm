#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

//공유기 설치 문제
//기타레슨과 비슷한 문제로 만약 파라메트릭 서치가 어렵게 출제된다면 이렇게 될 것이다.
//설치 개수를 임의로 파악하여 그 이상인지 아닌지로 이분탐색을 진행한다.

int N, C;
std::vector<int> ip;

int calculate() {
	int begin = 0;
	int end = ip[N - 1] - ip[0];
	int ans = INT_MIN;

	while (begin <= end) {
		int set_ip = 1;
		int p_node = 0;
		//공유기 설치하는데 떨어진 거리
		int mid = (begin + end) / 2;

		for (int k = 1; k < N; k++) {
			if (ip[k] - ip[p_node] >= mid) {
				set_ip++;
				p_node = k;
			}
		}

		if (set_ip >= C) {
			ans = std::max(ans, mid);
			begin = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return ans;
}

int main() {
	scanf("%d %d", &N, &C);
	ip.assign(N, 0);
	for (int k = 0; k < N; k++) {
		scanf("%d", &ip[k]);
	}
	std::sort(ip.begin(), ip.end());
	printf("%d", calculate());
}