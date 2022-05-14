#include <iostream>
#include <vector>


std::vector< std::vector<long long> > dp;
std::vector<int> value;
int test_num;

//이전의 기타리스트랑 같은 문제

long long bfs() {
	//첫번째로 오는 수의 경우의 수는 1이다.
	dp[1][value[0]] = 1;
	for (int i = 1; i <= test_num - 2; i++) {
		for (int j = 0; j <= 20; j++) {
			if (dp[i][j] > 0) {
				if (j + value[i] >= 0 && j + value[i] <= 20) {
					dp[i + 1][j + value[i]] += dp[i][j];
				}
				if (j - value[i] >= 0 && j - value[i] <= 20) {
					dp[i + 1][j - value[i]] += dp[i][j];
				}
			}
		}
	}

	return dp[test_num-1][value[test_num-1]];
}


int main() {
	scanf("%d", &test_num);
	dp.assign(test_num + 1, std::vector<long long>(21,0));
	value.assign(test_num, 0);
	for (int i = 0; i < test_num; i++) {
		scanf("%d", &value[i]);
	}
	printf("%lli", bfs());
}
