#include <stdio.h>


//dp문제
//i 번까지 lis를 구했고 이제 i+1을 봤을때 i보다 큰 값을 가진다면 단순하게 i번째 까지 구한거에 수를 더하면됨
//예를들어 10 20 10 30이 있을때 3번째인 10까지 lis는 1 2 1이다. 즉 2를 가지는 20까지의 lis가 이제까지 제일 길기때문에
//20보다 큰 수를 찾으면 단순히 20에서 뒤에 큰수를 붙이는 형태이다 즉 30에서는 단순히 1을 더해 lis가 3이 된다.
//이 부분을 재귀적으로 dp로 찾게 된다.

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


