#include <iostream>
#include <vector>
#include <algorithm>

std::vector< std::vector<int> >dp;

//īŻ�� �� �����ϱ�
// 4�ð��� �ɸ�
// i�� ���ڿ��� ���̶� �ϰ� j�� ������ ���� ���� �����ϸ�
// ���̰� i�̰� ������ ���� ���� j�� ���� ���̰� i-1�̸鼭 ���� ���� j-1�� "("�� �߰��� �Ϳ��ٰ�
// ���̰� i-1�̸鼭 ���� ���� j+1�� ���� ")"�� �߰��� ���̶� ����.

int calculate(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i < j) continue;
			if (i == j) {
				dp[i][j] = 1;
				continue;
			}
			if (i - 1 >= 1 && j + 1 <= n) {
				dp[i][j] += dp[i - 1][j + 1] % 1000000007;
			}
			if (i - 1 >= 1 && j - 1 >= 0) {
				dp[i][j] += dp[i - 1][j - 1] % 1000000007;
			}
		}
	}

	return dp[n][0];
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		dp.assign(n + 1, std::vector<int>(n + 1, 0));
		if (n % 2 == 1) printf("0\n");
		else printf("%d\n", calculate(n));
	}
}
