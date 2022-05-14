#include <iostream>
#include <vector>
#include <string.h>

int N, K;
bool dp[51][51][1226];
char rst[51];

bool calculate(int n, int a_num, int k) {
	
	
	if (n == N) {
		if (k == K)	return true;
		else return false;
	}
	if (dp[n][a_num][k]) return false;
	dp[n][a_num][k] = true;

	//A를 넣을 때
	rst[n] = 'A';
	if (calculate(n + 1, a_num + 1, k)) return true;

	//B를 넣을 때
	rst[n] = 'B';
	if (calculate(n + 1, a_num, k + a_num)) return true;
	
	return false;

}

int main() {
	scanf("%d %d", &N, &K);
	if (calculate(0, 0, 0)) std::cout << rst;
	else printf("-1");
}
