#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

//기타레슨 문제
//까다로운 문제였습니다

long long N, M;
std::vector<long long> lesson;
long long begin = 0;
long long end;

long long calculate() {

	long long ans = LLONG_MAX;

	while (begin <= end) {

		//현재까지의 blueray_count
		long long blueray_count = 0;
		//현재까지의 blueray 길이
		long long blueray_length = 0;
		long long mid = (begin + end) / 2;


		for (int k = 0; k < N; k++) {
			blueray_length += lesson[k];
			if (k != N - 1) {
				if (blueray_length + lesson[k + 1] > mid) {
					blueray_count++;
					blueray_length = 0;
				}
			}
			else blueray_count++;
		}

		if (blueray_count <= M) {
			end = mid - 1;
			ans = std::min(ans, mid);
		}
		else {
			begin = mid + 1;
		}
	}

	return ans;
}

int main() {
	scanf("%lld %lld", &N, &M);
	lesson.assign(N, 0);
	for (int k = 0; k < N; k++) {
		scanf("%lld", &lesson[k]);
		end += lesson[k];
		begin = std::max(begin, lesson[k]);
	}
	printf("%lld", calculate());
}