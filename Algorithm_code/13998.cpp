#include <iostream>
#include <vector>
#include <algorithm>


//Ʋ�� ���� N���� 1�� ���� �ݷʸ� ������� ����.

int N;
std::vector<int> dp;
std::vector<int> value;
std::vector<int> rst;

int result = -1001;

int calculate() {
	
	if (N >= 1) {//Ʋ�� ���� => if (N>=1)�� �ݷ�ó������ ���ؼ�
		dp[1] = value[1];
		rst[1] = value[1];
		result = std::max({ dp[1], rst[1], result });
	}

	for (int i = 2; i <= N; i++) {
		dp[i] = std::max(value[i], dp[i - 1] + value[i]);
		rst[i] = std::max(rst[i - 1] + value[i], dp[i - 1]);
		result = std::max({ dp[i], rst[i], result });
	}
	return result;
}


int main() {
	scanf("%d", &N);
	value.assign(N + 1, 0);
	dp.assign(N + 1, 0);
	rst.assign(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &value[i]);
	}
	
	printf("%d", calculate());
}
