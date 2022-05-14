#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <limits.h>

//4902 삼각형의 값
// 이전 dp 값을 저장 할 떄 i번 j번째 줄부터 i 번 k 번까지 구하고 싶다면
// 배열 값을 dp[i][j][k]로 선언해서 i번째 줄의 j~k 까지의 값으로 구하는게 아니라
// dp[i][j] - dp[i][k]로 확인한다. => i번째 0~j번까지의 합 - i번째 0~k번 까지의 합

#define NOT_INIT INT_MAX

int N;
int count = 0;
int forward;
std::vector< std::vector<int> > cmd;
//i층에서 0~j번 인덱스까지의 합
std::vector< std::vector<int> > sum_val;

int calculate() {
	int rst = INT_MIN;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * i + 1; j++) {
			int x = i;
			int y = N - (i + 1) + j;
			int prev = 0;
			int sign = (x + y) % 2 == forward ? 1 : -1;
			for (int k = 0; x + sign * k < N && x + sign * k >= 0; k++) {
				int pres;
				//y-k, y+k
				if (y - k < 0 || y + k >= 2 * N - 1) continue;
				if (sum_val[x + sign * k][y - k] != NOT_INIT && sum_val[x + sign * k][y + k] != NOT_INIT) {
					if (y - k == N - 1 - (x + sign * k)) pres = prev + sum_val[x + sign * k][y + k];
					else pres = prev + sum_val[x + sign * k][y + k] - sum_val[x + sign * k][y - k - 1];
					rst = std::max(rst, pres);
					prev = pres;
				}
				else prev = INT_MIN;
			}
		}
	}
	return rst;
}

int main() {
	while (1) {
		count++;
		scanf("%d", &N);
		if (N == 0) break;
		cmd.assign(N, std::vector<int>(2 * N - 1, NOT_INIT));
		sum_val.assign(N, std::vector<int>(2 * N - 1, NOT_INIT));
		//정방향 삼각형이 짝수인덱스인지 홀수 인덱스인지.
		//i,j가 짝수인지 홀수인지 아는 방법은 i+j의 값을 비교하면 된다.
		forward = (N - 1) % 2;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 2 * i + 1; j++) {
				scanf("%d", &cmd[i][N - (i + 1) + j]);
				if (j == 0) {
					sum_val[i][N - (i + 1) + j] = cmd[i][N - (i + 1) + j];
				}
				else sum_val[i][N - (i + 1) + j] = sum_val[i][N - (i + 1) + j - 1] + cmd[i][N - (i + 1) + j];
			}
		}
		printf("%d. %d\n", count, calculate());
	}
}