#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX_VAL 1000001

//12026 BOJ 거리 문제
//DP의 전형적인 풀이로 해결 가능한 문제
//DP 풀 때 주의점은 브루트포스일 때 해당 값을 활용할 수 있으면 DP라는 것을 기억할 것

int N;
char data[1001];
int* DP;


int calculate() {
	for (int k = 1; k < N; k++) {
		char index = data[k];
		if (index == 'B') index = 'J';
		else if (index == 'O') index = 'B';
		else if (index == 'J') index = 'O';

		int node = k - 1;
		while (node >= 0) {
			if (data[node] == index) {
				int cal = DP[node] + (k - node) * (k - node);
				DP[k] = DP[k] > cal ? cal : DP[k];
			}
			node--;
		}
	}
	return DP[N - 1] != MAX_VAL ? DP[N - 1] : -1;
}

int main() {
	scanf("%d", &N);
	scanf("%s", data);
	DP = (int*)malloc(sizeof(int) * N);
	for (int k = 1; k < N; k++) {
		DP[k] = MAX_VAL;
	}
	printf("%d", calculate());
}