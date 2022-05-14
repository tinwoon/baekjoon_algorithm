#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void calculate() {
	vector<int> dp;
	dp.resize(num);
	dp[0] = value[0];
	dp[1] = value[0] + value[1];
	dp[2] = max(dp[1],dp[0]+value)
}


int main() {
	int num = 0;
	scanf("%d", &num);
	vector <int> value;
	for (int i = 0; i < num; i++) {
		int tmp;
		scanf("%d", &tmp);
		value.push_back(tmp);
	}



	return 0;
	

}