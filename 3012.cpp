#include <iostream>
#include <vector>
#include <string.h>


//�ùٸ� ��ȣ ���ڿ�
//��ȭ�� ��Ģ�� �ᱹ ��ã�� ����� Ȯ����
//����� ���� �����ϸ� �ȴ�. ��ȣ�� �ϳ� ����� ������ �� �κ� ������ ��ȣ�� ���� �� �ִ� ��� * �� �ܺ��� ��ȣ�� ���� �� �ִ� �κ��� ����̴�. 

int N;
std::string map;
long long mode = 100000;
std::string open = "[{(";
std::string close = "]})";
//i���� j���� ���� �� �ִ� ���ڿ��� ����
long long dp[201][201];

long long calculate(int i, int j) {

	if (i > j) {
		return 1;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	dp[i][j] = 0;
	for (int k = i + 1; k <= j; k+=2) {
		for (int l = 0; l < 3; l++) {
			if (map[i] == open[l] || map[i] == '?') {
				if (map[k] == close[l] || map[k] == '?') {
					long long value = calculate(i + 1, k - 1) * calculate(k + 1, j);
					dp[i][j] += value;
					if (dp[i][j] >= mode) {
						dp[i][j] = mode + dp[i][j] % mode;
					}
				}
			}
		}
	}
	return dp[i][j];
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	std::cin >> map;
	long long ans = calculate(0, N - 1);
	if (ans >= mode) {
		printf("%05lld\n", ans % mode);
	}
	else {
		printf("%lld\n", ans);
	}
}
