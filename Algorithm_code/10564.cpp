#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <algorithm>

//�ȱ������ ����
//dp ���� ����ϱ� 
//i�� ������ j�� �ȱ�����⿡�� �����Ѱ�
//dp ���� dfsó�� ������ ����ϱ� 
bool dp[5001][5001];
int N, M;
std::vector<int> score;

void calculate(int i, int j) {
	if (j > N) return;
	if (dp[i][j]) return;
	dp[i][j] = true;
	for (int k = 0; k < score.size(); k++) {
		calculate(i + score[k], i + j + score[k]);
	}
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int k = 0; k < tc; k++) {
		scanf("%d %d", &N, &M);
		score.assign(M, 0);
		memset(dp, false, sizeof(dp));
		for (int l = 0; l < M; l++) {
			scanf("%d", &score[l]);
		}
		calculate(0, 0);
		int ans = -1;
		for (int l = 0; l < 5001; l++) {
			if (dp[l][N]) ans = std::max(ans, l);
		}
		printf("%d\n", ans);
	}
}
