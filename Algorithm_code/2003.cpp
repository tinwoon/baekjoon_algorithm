#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int* sum;
int N, M;

int ret_sum(int, int);
int calculate(void);

//전형적인 투포인터 문제이다.
//딱히 어려운 부분 전혀 없다. 

int main() {
	scanf("%d %d", &N, &M);
	sum = (int*)malloc(sizeof(int) * N);
	for (int k = 0; k < N; k++) {
		int t_sum;
		scanf("%d", &t_sum);
		sum[k] = k == 0 ? t_sum : sum[k - 1] + t_sum;
	}
	printf("%d", calculate());
}

int ret_sum(int left, int right) {
	return (left == 0 ? sum[right] : sum[right] - sum[left - 1]);
}

int calculate() {
	int ans = 0;
	int right = 0;
	int left = 0;
	while (right < N && left < N) {
		if (right < left) {
			right++;
			continue;
		}
		int ret_v = ret_sum(left, right);
		if (ret_v < M) right++;
		else if (ret_v > M) left++;
		else {
			ans++;
			right++;
		}
	}

	return ans;
}
