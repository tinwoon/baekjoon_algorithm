#include <iostream>
#include <vector>

//dp문제니 다음과 같이 정의가 가능하다. 
// 그룹 x를 이미 추가한 노래로 가정하면 N-x는 그룹을 추가하지 않은 곡임을 알 수 있다.
// 즉 이제까지 x 개의 곡을 넣은 상태에서 넣지 않은 다른 곡을 넣는다면 넣을 수 있는 경우의 수는 N-j + 1이다.
//  만약 X에 들어있는 곡을 다시 넣는다면, X-M 중 아무 노래나 추가하면 된다. 

int N, M, P;
long long dp[101][101];

long long calculate() {
	dp[0][0] = 1;
	//i는 플레이리스트
	//j는 이제까지 몇 종류의 곡을 넣었는가
	for (int i = 1; i <= P; i++) {
		for (int j = 1; j <= N; j++) {
			//한번도 넣지 않은 곡을 넣을 때
			if (j > 0) (dp[i][j] += dp[i-1][j-1] * (N - j + 1)) %= 1000000007;
			//이미 넣은 곡을 넣을 때
			if (j > M) (dp[i][j] += dp[i - 1][j] * (j - M)) %= 1000000007;
		}
	}
	return dp[P][N];
}

int main() {
	scanf("%d %d %d", &N, &M, &P);
	printf("%lli", calculate());
}
