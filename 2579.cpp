#include <iostream>
#include <stdio.h>
using namespace std;



//dp�˰������� Ȯ��
//������ �ֵ� ������ ����� ��
//�迭�� �ΰ��� �ξ ��ĭ¥���� �ǳʼ� �ִ��� �� ���� dp�� �ι�° �ε��� ���� 1�� �߰��Ͽ�
//����� �ΰ����� �ǳ����� �˷���
//��ĭ�� �ǳ������� ��������
int max(int a, int b) {
	return a > b ? a : b;
}

void calculate(int data[300],int dp[300][2],int i) {
	if (i == 0) {
		dp[0][0] = data[0];
		
	}

	else if (i == 1) {
		dp[1][0] = data[1];
		dp[1][1]= data[0]+data[1];


	}


	else {
			dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + data[i];
			dp[i][1] = dp[i - 1][0] + data[i];
		}
		

}

 int main() {
	int num = 0;
	scanf("%d", &num);
	int data[300] = { 0, };
	int dp[300][2] = { { 0, }, };
	

	for (int i = 0; i < num; i++) {
		scanf("%d", &data[i]);
		calculate(data, dp, i);
	}

	printf("%d", max(dp[num - 1][0],dp[num-1][1]));


}
