#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//점화식의 비교 
//dp문제로 재귀적인 반복
//이전값까지의 dp값과 지금의 value값을 더한거랑 단순히 지금의 value값을 비교해서 누가 더 큰지 확인함.

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
