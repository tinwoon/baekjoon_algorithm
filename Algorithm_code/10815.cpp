#include <iostream>
#include <vector>
#include <algorithm>

//10815 숫자카드 문제
//그냥 이분탐색이라 써져있음

int N, M;
std::vector<int> card;
std::vector<int> card_test;
std::vector<int> ans;

int calculate(int value) {
	int begin = 0;
	int end = N - 1;


	while (begin <= end) {
		int mid = (begin + end) / 2;

		if (card[mid] == value) {
			return 1;
		}
		else if (card[mid] > value) {
			end = mid - 1;
		}
		else begin = mid + 1;
	}
	return 0;
}

int main() {
	scanf("%d", &N);
	card.assign(N, 0);
	for (int k = 0; k < N; k++) {
		scanf("%d", &card[k]);
	}
	std::sort(card.begin(), card.end());

	scanf("%d", &M);
	card_test.assign(M, 0);
	ans.assign(M, 0);
	for (int k = 0; k < M; k++) {
		scanf("%d", &card_test[k]);
	}

	for (int k = 0; k < M; k++) {
		ans[k] += calculate(card_test[k]);
	}

	for (int k = 0; k < M; k++) {
		printf("%d ", ans[k]);
	}
}