#include <iostream>
#include <vector>

using namespace std;


//문제 표현 자체에 문제가 있다 생각함.(모든 2진 수열의 개수를 15746으로 나눈 것의 의미가 
//재귀적으로 들어갈 값 역시 15746으로 나눈 값을 활용하여 재귀적으로 가는가
//아니면 마지막 최종 값만 15746으로 나누는가)
//또한 이 문제가 점화식이라는 부분에 대한 상식을 알게 되는 부분부터 알고리즘 문제가 그냥 수학이라는 점에서 
//수학을 공부하는지 프로그래밍을 공부하는지 도움이 될지 잘 모르겠다.
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
