#include <iostream>
#include <vector>


//�ڽ� ���� ����
// ��ȭ���̱� ������ �� 1�� ���и� �� ��� ������ ������ �˾ƾ� Ǯ �� ����
// �𸣴� �� ������� ���� �ð����� �������� �ٷ� ��� ���� ���� ���̱�

int N, M;
//n���� ���� m���� ����Ŭ�� ������ ���
long long dp[21][21];

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long calculate(int n, int m) {
	if (n == 0) return 1;
	if (m == 0) return 0;

	if (dp[n][m] != 0) return dp[n][m];

	return dp[n][m] = calculate(n - 1, m - 1) + (n - 1) * calculate(n - 1, m);
}

int main() {
	scanf("%d %d", &N, &M);
	long long rst = calculate(N, M);
	long long rst_all = calculate(N, N);
	long long gcd_value = gcd(rst_all, rst);
	printf("%lli/%lli", rst/gcd_value, rst_all/gcd_value);
}
