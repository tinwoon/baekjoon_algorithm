#include <stdio.h>

//��ȭ���� �̿�
//dp������ ��κ��� ��ȭ���� �ִµ� �� �κ��� �����ϱⰡ ������ �������� �κ�
//dp���θ� �ϴ°��� ��ȭ���� �����ؾ��ϴ��� �𸣰���.

int main(void) {
	int num;
	int dp[101][10] = {};
	int sum = 0;
	scanf("%d", &num);
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= num; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				dp[i][0] = dp[i - 1][1] % 1000000000;
			else if (j == 9)
				dp[i][9] = dp[i - 1][8] % 1000000000;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}
	for (int i = 1; i < 10; i++)
		sum = (sum + dp[num][i]) % 1000000000;

	printf("%d\n", sum% 1000000000);
}




