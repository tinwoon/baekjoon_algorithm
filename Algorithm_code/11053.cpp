#include <stdio.h>


//dp����
//i ������ lis�� ���߰� ���� i+1�� ������ i���� ū ���� �����ٸ� �ܼ��ϰ� i��° ���� ���Ѱſ� ���� ���ϸ��
//������� 10 20 10 30�� ������ 3��°�� 10���� lis�� 1 2 1�̴�. �� 2�� ������ 20������ lis�� �������� ���� ��⶧����
//20���� ū ���� ã���� �ܼ��� 20���� �ڿ� ū���� ���̴� �����̴� �� 30������ �ܼ��� 1�� ���� lis�� 3�� �ȴ�.
//�� �κ��� ��������� dp�� ã�� �ȴ�.

int calculate(int num, int value[1001], int dp[1001]) {
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
	int dp[1010] = {};
	int value[1010] = {};
	scanf("%d", &num);

	for (int i = 1; i <= num; i++)
		scanf("%d", &value[i]);

	

	printf("%d\n", calculate(num,value,dp));

}


