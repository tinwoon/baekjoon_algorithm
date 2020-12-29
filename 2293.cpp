#include <iostream>
#include <vector>

//1,2,3 ���ϱ� 4 ������ ������
// �Ȱ��� �Ͻø� �˴ϴ�.

std::vector<int> coin;
std::vector<int> dp;
int n, value;

int calculate(int value) {
	dp[0] = 1;
	for (int i = 0; i < coin.size(); i++) {
		for (int j = 1; j <= value; j++) {
			if (j - coin[i] >= 0) {
				dp[j] += dp[j - coin[i]];
			}
		}
	}
	return dp[value];
}


int main() {
	scanf("%d %d", &n, &value);
	coin.assign(n,0);
	dp.assign(value + 1, 0);
	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
	}
	printf("%d",calculate(value));
}
