#include <iostream>
#include <vector>

using namespace std;


//lis�� �̿�
//���� 10���� ������ �ϳ��� ������� �ϳ��� �������� ����
//�����ϴ� ���� ������ lis�� �������������� Ư���ε��� ������ ������ ������
//��������� lis���� i�ε����� ������ lis�� num-i+1�ε����� ���Ѱ��� i�ε����� �����ͳ� ������ �����̴�.
//�� ���̰� ����ū ���� ã�Ƽ� ��ȯ�Ѵ�.

int calculate(int num, vector<int> &value, vector<int> &dp) {
	int max = 0;


	for (int i = 1; i <= num; i++)
	{
		int min = 0;
		for (int j = 0; j < i; j++) {
			if (value[i] > value[j]) {
				if (min < dp[j])
					min = dp[j];
			}
		}
		dp[i] = min + 1;
		if (max < dp[i])
			max = dp[i];
	}
	return max;
}





int main(void) {
	int num = 0;
	int max = 0;
	vector<int> increase_dp;
	vector<int> decrease_dp;

	vector<int> increase_value;
	vector<int> decrease_value;
	increase_dp.resize(1001);
	increase_value.resize(1001);
	decrease_dp.resize(1001);
	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		int tmp;
		scanf("%d", &tmp);
		increase_value[i] = tmp;
		decrease_value.insert(decrease_value.begin(),tmp);
	}
	decrease_value.insert(decrease_value.begin(), 0);


	for (int i = 1; i <= num; i++) {
		
		if (( calculate(i, increase_value, increase_dp) + calculate(num - i+1, decrease_value, decrease_dp)) >max ) {
			max = calculate(i, increase_value, increase_dp) + calculate(num - i+1, decrease_value, decrease_dp);
		}
	}
		
	printf("%d\n", max-1);

}


