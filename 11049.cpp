#include <iostream>
#include <vector>
#include <string.h>
#include <limits.h>
#include <algorithm>

//��� ���� ���� ����
//������ ��� ���� dp�� ���Ѵ��� �ش� ���� ��İ��� �����ָ� �ȴ�.
//���� ��� (ABC)*(DE)�� ���ϴ� ���
//ABC�� �ּ� �� + DE�� �ּҰ� + ABC��BC ��� ���� ���� �����ָ� �ȴ�.

std::vector< std::pair<int, int> > data;
int N;
int dp[501][501];


int calculate(int i, int j) {
	if (i > j) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	int ans = INT_MAX;
	for (int x = i; x < j; x++) {
		ans = std::min(ans, calculate(i, x) + calculate(x + 1, j) + data[i].first * data[x].second * data[j].second);
	}
	return dp[i][j] = ans;
}

int main() {
	scanf("%d", &N);
	memset(dp, -1, sizeof(dp));
	for (int k = 0; k < N; k++) {
		int a, b;
		scanf("%d %d", &a, &b);
		data.emplace_back(std::make_pair(a, b));
		dp[k][k] = 0;
	}
	for (int k = 0; k < N - 1; k++) {
		dp[k][k + 1] = data[k].first * data[k].second * data[k + 1].second;
	}
	printf("%d", calculate(0, N - 1));
}