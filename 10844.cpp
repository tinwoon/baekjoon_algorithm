#include <stdio.h>

//점화식을 이용
//dp문제는 대부분이 점화식이 있는데 이 부분을 유추하기가 굉장히 수학적인 부분
//dp공부를 하는건지 점화식을 공부해야하는지 모르겠음.

int main(void) {
	int num;
	int dp[101][10] = {};
	int sum = 0;
	scanf("%d", &num);
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= num; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				dp[i][0] = dp[i - 1][1] % 1000000000;
			else if (j == 9)
				dp[i][9] = dp[i - 1][8] % 1000000000;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}
	for (int i = 1; i < 10; i++)
		sum = (sum + dp[num][i]) % 1000000000;

	printf("%d\n", sum% 1000000000);
}




