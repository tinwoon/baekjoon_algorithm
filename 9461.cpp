#include <iostream>
#include <vector>

using namespace std;


//오버플로우와 출력값의 형식지정자를 숙지하지 못해서 틀린 문제
void calculate(int num, vector<long long> &dp) {
	

	switch (num) {
		case 0: 
			dp[num] = 1;
			break;

		case 1:
			dp[num] = 1;
			break;

		case 2:
			dp[num] = 1;
			break;


		default:
			dp[num] = dp[num - 2] + dp[num - 3];
			break;

			
	}
	
}




int main() {
	int num = 0;
	scanf("%d", &num);
	vector<int> data;
	int max = 0;
	for (int i = 0; i < num; i++) {
		int tmp_data = 0;
		scanf("%d", &tmp_data);
		data.push_back(tmp_data);
		if (tmp_data > max) max = tmp_data;
	}


	vector<long long> dp(max,0);
	for (int i = 0; i < max; i++) {
		calculate(i, dp);
	}


	for (int i = 0; i < data.size(); i++) {
		printf("%lli\n", dp[data[i]-1]);

	}
}


