#include <iostream>
#include <vector>

using namespace std;


//���� ǥ�� ��ü�� ������ �ִ� ������.(��� 2�� ������ ������ 15746���� ���� ���� �ǹ̰� 
//��������� �� �� ���� 15746���� ���� ���� Ȱ���Ͽ� ��������� ���°�
//�ƴϸ� ������ ���� ���� 15746���� �����°�)
//���� �� ������ ��ȭ���̶�� �κп� ���� ����� �˰� �Ǵ� �κк��� �˰��� ������ �׳� �����̶�� ������ 
//������ �����ϴ��� ���α׷����� �����ϴ��� ������ ���� �� �𸣰ڴ�.
void calculate(int num, vector<long> &dp) {
	if (num == 0) {
		dp[num] = 0;
		
	}
		
	else if (num == 1) {
		dp[num] = 1;
	}
	
	else if (num == 2) {
		dp[num] = 2;
	}

	else {
		dp[num] = dp[num - 1] + dp[num - 2];
		dp[num] = dp[num] % 15746;
	}
	
}




int main() {
	int num = 0;
	scanf("%d", &num);
	vector<long> dp(num+1,0);
	for (int i = 0; i < num+1; i++) {
		calculate(i, dp);
	}
	printf("%d", dp[num]);
}
