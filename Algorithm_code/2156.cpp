#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//�������� dp����
//dp������ Ǯ ���� �ֵ� �˰����� �����ϰ� �ܿ�� ����� ���� ��
int calculate(int num, vector<int> &value) {
	vector<int> dp;
	dp.resize(num);
	dp[0] = value[0];
	dp[1] = value[0] + value[1];
	dp[2] = max({dp[1],dp[0]+value[2],value[1]+value[2]});
	for (int i = 3; i < num; i++) {
		dp[i] = max({ dp[i - 1], dp[i - 2] + value[i], dp[i-3] +value[i - 1] + value[i] });
	}

	return dp[num - 1];
}


int main() {
	int num = 0;
	scanf("%d", &num);
	vector <int> value;
	vector <int> dp;
	for (int i = 0; i < num; i++) {
		int tmp;
		scanf("%d", &tmp);
		value.push_back(tmp);
	}

	printf("%d", calculate(num, value));

	return 0;


}
