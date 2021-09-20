#pragma warning(disable:4996)
#include <iostream>
#include <algorithm>
#include <string.h>
#include <limits.h>
#include <vector>
#include <math.h>

//평범한 배낭 2 문제
//개인적으로 못 푼 문제

std::vector<int> bag;
int N, M, value, weight, things, thing;

int main() {
	scanf("%d %d", &N, &M);
	bag.assign(10001, 0);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d %d", &weight, &value, &things);
		thing = 1;
		while (things > 0) {
			for (int j = M; weight * thing <= j; j--)
				bag[j] = std::max(bag[j], bag[j - weight * thing] + value * thing);
			things = things - thing;
			thing = thing * 2;
			if (things < thing) thing = 1;
		}
	}
	printf("%d", bag[M]);
	return 0;
}