#pragma warning (disable : 4996)
#include <vector>
#include <algorithm>
#include <limits.h>

//2157 ���� ����
//�������� DP ������ ���� ��ü�� ���� �б⸦ �Ǵ����� ���� �����ɷȴ� ����
//����� ������ ������.

int N, M, K;
std::vector< std::vector< std::pair<int, int> > > connected;
//n�� Ÿ���� pass�� ���ļ� �� �ִ밪
std::vector< std::vector<int> > dp;

//�������� �� ����, ������ ������ ����, ��������� �⳻��
int calculate() {

	for (int node = 0; node < connected[1].size(); node++) {
		dp[connected[1][node].first][2] = std::max(dp[connected[1][node].first][2], connected[1][node].second);
	}

	for (int m = 2; m < M; m++) {
		//���� ��� 
		for (int node = 1; node <= N; node++) {
			if (!dp[node][m]) continue;
			for (int idx = 0; idx < connected[node].size(); idx++) {
				int next = connected[node][idx].first;
				int weight = connected[node][idx].second;
				dp[next][m + 1] = std::max(dp[next][m + 1], dp[node][m] + weight);
			}
		}
	}

	return *std::max_element(dp[N].begin(), dp[N].end());
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	connected.assign(N + 1, std::vector< std::pair<int, int> >());
	dp.assign(N + 1, std::vector<int>(M + 1, 0));
	for (int k = 0; k < K; k++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a < b) connected[a].push_back(std::make_pair(b, c));
	}
	printf("%d\n", calculate());

}