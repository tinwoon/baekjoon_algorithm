#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

//�÷��̵� ���� �˰����� ����ϸ� �ȴ�.
//������ ���ͽ�Ʈ�� ���ٵ� �����ϰ� �ִ� ��θ� ã�� �� �ְ�, ������ ����ġ ������ �ذ��� �� ������ 
//���� ���� ���ͽ�Ʈ�󺸴� ���� ������ �ִ�.
//i���� j������ �ִ� ��θ� dp[i][j]�� �Ѵٸ�
//dp[i][j] �� � k��θ� �߰� �������� �湮�Ѵ� ���� �� dp[i][j] = dp[i][k] + dp[j][k] �� dp[i][j] �� ���� ���� �����ϸ� ã���� �ȴ�. 

int n, m;
std::vector< std::vector<int> > dp;

void calculate() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (dp[j][i] != INT_MAX && dp[i][k] != INT_MAX) {
					dp[j][k] = std::min(dp[j][i] + dp[i][k], dp[j][k]);
				}
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	dp.assign(n + 1, std::vector<int>(n + 1, INT_MAX));
	
	for (int k = 0; k < m; k++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if(dp[a][b] > c) dp[a][b] = c;
	}
	calculate();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || dp[i][j] == INT_MAX)
				printf("0 ");
			else
				printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
}
