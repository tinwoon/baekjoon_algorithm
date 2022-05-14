#include <iostream>
#include <vector>

using namespace std;


//lis를 이용
//받은 10개의 값들을 하나는 순서대로 하나는 역순으로 삽입
//감소하는 수는 역순의 lis나 마찬가지임으로 특정인덱스 까지의 각각을 구한후
//순서대로의 lis간의 i인덱스와 역순의 lis의 num-i+1인덱스를 더한값이 i인덱스의 바이터널 수열의 길이이다.
//이 길이가 가장큰 값을 찾아서 반환한다.

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


