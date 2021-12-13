#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <math.h>

//11958 �ڷ���Ʈ ����
//������ ���� ������ �����̴�. ��Ǫ�°� ���� ������
//N���� 1000�̱� ������ �÷��̵� �ͼ��� ���÷����� 2�ʴ� ������ �Ѿ� ���� �������� ���
//������ ����� �÷��̵� �ͼ��ε� ����ȭ�� Ȱ���� �ڵ嵵 ���� �׳� �����Ϸ� ����ȭ�� ���� ������ Ǯ����ϴ� �����̴�.

int N, T, M;
//N���� N�� ���� �Ÿ�
std::vector< std::vector<int> > dp;
//N�� ������ ��ǥ
std::vector< std::pair<int, int> > city;
//���� ���ð� Ư���� �����ΰ�
std::vector<bool> is_special;

void calculate() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (dp[j][i] != INT_MAX && dp[i][k] != INT_MAX) {
					dp[j][k] = std::min(dp[j][i] + dp[i][k], dp[j][k]);
				}
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &T);
	dp.assign(N, std::vector<int>(N, INT_MAX));
	city.assign(N, std::pair<int, int>());
	is_special.assign(N, false);

	for (int k = 0; k < N; k++) {
		int Special, x, y;
		scanf("%d %d %d", &Special, &x, &y);
		city[k] = std::make_pair(x, y);
		is_special[k] = (bool)Special;
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (is_special[i] && is_special[j]) dp[j][i] = dp[i][j] = std::min(abs(city[i].first - city[j].first) + abs(city[i].second - city[j].second), T);
			else dp[j][i] = dp[i][j] = abs(city[i].first - city[j].first) + abs(city[i].second - city[j].second);
		}
	}

	calculate();

	scanf("%d", &M);
	for (int k = 0; k < M; k++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", dp[a - 1][b - 1]);
	}


}