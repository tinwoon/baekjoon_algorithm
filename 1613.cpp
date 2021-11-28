#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>

//1613 ���� ����
//�׳� �ܼ��� �÷��̵��ε� ������ ����ġ�� ���� true, false�� ������ Ǫ�� �����̴�.
//DAG ������ ������ ���迡 �����ɷȴ� ����

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