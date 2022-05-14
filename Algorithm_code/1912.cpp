#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//��ȭ���� �� 
//dp������ ������� �ݺ�
//������������ dp���� ������ value���� ���ѰŶ� �ܼ��� ������ value���� ���ؼ� ���� �� ū�� Ȯ����.

int main() {
	int num = 0;
	scanf("%d", &num);
	vector<int> data(num);
	vector<int> dp(num);
	int max=-1001;
	for (int i = 0; i < num; i++) {
		scanf("%d", &data[i]);
	}

	dp[0] = data[0];
	for (int i = 1; i < num; i++) {
		dp[i] = std::max(dp[i-1]+data[i],data[i]);
		max = std::max(dp[i], max);
	}

	printf("%d", std::max(max,dp[0]));

	return 0;
	
}
