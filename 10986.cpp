#include <iostream>
#include <vector>

//dp[n]�� �ǹ̴� 0���� K���� ���� ���� sum�̶� ���� ��, �������� n�� ���� �� �����̴�.
//�� ���� �˸� dp[i]*dp[i]-1/2�� �ϸ� �������� i�� ������ ����� ���� ���� �� �ִ�.
//�� ���� �������� ���� ���� ����� ���� ���ϳĸ� [i,j]������ ���� sum[j] - sum[i]�̰�,
//������ ���� M���� �������� (i,j)�� (sum[j]-sum[i])%M == 0�� �Ǹ� M���� �������� ���̴�.
//�� ���� ��ⷯ �������� �غ��� sum[j]%M == sum[i]%M�� �Ǵ� ������ sum�� �������� ���� �� ���� �ΰ��� ���� ����� ���� ���� �ȴ�.
//��, dp[i]���� �������� i�� sum�� ������ ��� �����Ƿ� �� �������� �ΰ��� ���� ������ ������ dp[i] * (dp[i] - 1) / 2;�̴�.

//n���� ���� ������ m�� ���� ����
long long dp[1001];
int sum[1000001];
int N, M;

inline long long calculate() {
	long long rst = 0;
	for (int i = 0; i < M; i++) {
		if (dp[i] == 0) continue;
		rst += dp[i] * (dp[i] - 1) / 2;
	}
	return rst + dp[0];
}

int main() {
	scanf("%d %d", &N, &M);
	for (int k = 1; k <= N; k++) {
		int value;
		scanf("%d", &value);
		(sum[k] = sum[k - 1] + value) %= M;
		dp[sum[k]]++;

	}
	printf("%lli", calculate());
}