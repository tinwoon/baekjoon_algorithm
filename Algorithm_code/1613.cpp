#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>

//1613 역사 문제
//그냥 단순히 플로이드인데 오히려 가중치가 없이 true, false로 접근해 푸는 문제이다.
//DAG 문제라 생각해 설계에 오래걸렸던 문제

int N, K, S;
std::vector< std::vector<bool> > weight;

void calculate() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= N; k++) {
				if (weight[j][i] && weight[i][k]) {
					weight[j][k] = true;
				}
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &K);
	weight.assign(N + 1, std::vector<bool>(N + 1, false));
	for (int k = 0; k < K; k++) {
		int a, b;
		scanf("%d %d", &a, &b);
		weight[a][b] = true;
	}
	calculate();
	scanf("%d", &S);
	for (int k = 0; k < S; k++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (weight[a][b]) printf("-1\n");
		else if (weight[b][a]) printf("1\n");
		else printf("0\n");
	}
}