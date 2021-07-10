#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#include <limits.h>

//4902 �ﰢ���� ��
// ���� dp ���� ���� �� �� i�� j��° �ٺ��� i �� k ������ ���ϰ� �ʹٸ�
// �迭 ���� dp[i][j][k]�� �����ؼ� i��° ���� j~k ������ ������ ���ϴ°� �ƴ϶�
// dp[i][j] - dp[i][k]�� Ȯ���Ѵ�. => i��° 0~j�������� �� - i��° 0~k�� ������ ��

#define NOT_INIT INT_MAX

int N;
int count = 0;
int forward;
std::vector< std::vector<int> > cmd;
//i������ 0~j�� �ε��������� ��
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
		//������ �ﰢ���� ¦���ε������� Ȧ�� �ε�������.
		//i,j�� ¦������ Ȧ������ �ƴ� ����� i+j�� ���� ���ϸ� �ȴ�.
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