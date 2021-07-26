#include <iostream>
#include <vector>
#include <limits.h>

//�� �ܿ����� lis �˰���
//������ n^2������ lis ���� �ξ� ������
//�ڵ嵵 �����ϰ� �޸𸮵� ������ �� �ִ�.
//��, ���� �Ϻ��ϴ� �ܿ�� ���� ����. 
 

int N;
std::vector<int> dp;
std::vector<int> value;

int calculate() {
	value.emplace_back(INT_MIN);
	int count = 0;
	for (int k = 0; k < N; k++) {
		if (value.back() < dp[k]) {
			value.emplace_back(dp[k]);
			count++;
		}
		else {
			*std::lower_bound(value.begin(), value.end(), dp[k]) = dp[k];
		}
	}
	return count;
}

int main() {
	scanf("%d", &N);
	dp.assign(N, 0);
	for (int k = 0; k < N; k++) {
		scanf("%d", &dp[k]);
	}
	printf("%d", calculate());
}
